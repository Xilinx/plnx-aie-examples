/******************************************************************************
# Copyright (C) 2024, Advanced Micro Devices, Inc.
# SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/
#include <unistd.h>
#include <fstream>
#include <cstring>
#include "kernels.h"
#include "kernels/config.h"
#include "xrt/xrt_aie.h"

int main(int argc, char ** argv)
{
	std::cout << "[INFO] AIE GMIO Matrix Multiplication" << std::endl;
	std::cout << "[INFO] Matrix size(int32): " <<  NUM_ROWS
		  << "x" <<  NUM_COLS << std::endl;

	std::string xclbinFilename;
	if(argc != 2)
		xclbinFilename = "/usr/bin/aie-matrix-multiplication.xclbin";
	else
		xclbinFilename = argv[1];

	// Open xclbin
	auto dhdl = xrt::aie::device{"0"};
	std::cout<<"Open device successfully"<<std::endl;
	auto xclbin_1 = xrt::xclbin(xclbinFilename);
	auto uuid = dhdl.load_xclbin(xclbin_1);
	std::cout<<"Load XCLBIN successfully"<<std::endl;

	auto ghdl = xrt::graph(dhdl, uuid, "my_graph");

	int ret = 0, pass = 0;
	int len = NUM_ELMNTS * sizeof(int) + NUM_ROWS * sizeof(int *);

	std::vector<xrt::aie::bo> input_a_BOs;
	std::vector<int*> input_a_mapped_BOs;
	for (int i = 0; i < NUM_HW_ROWS ; i++) {
		auto input_a = xrt::aie::bo(dhdl, MAT_A_CHUNK_SIZE, 0, 0);
		auto input_a_mapped = input_a.map<int*>();
		input_a_BOs.push_back(input_a);
		input_a_mapped_BOs.push_back(input_a_mapped);
	}

	auto input_b_0 = xrt::aie::bo(dhdl, len, 0, 0);
	auto input_b_mapped_0  =  input_b_0.map<int*>();

	std::vector<xrt::aie::bo> result_aie_BOs;
        std::vector<int*> result_aie_mapped_BOs;
        for (int i = 0; i < NUM_HW_ROWS ; i++) {
                auto result_aie = xrt::aie::bo(dhdl, MAT_A_CHUNK_SIZE, 0, 0);
                auto result_aie_mapped = result_aie.map<int*>();
                result_aie_BOs.push_back(result_aie);
                result_aie_mapped_BOs.push_back(result_aie_mapped);
        }
	std::cout<<"[INFO] Allocated BOs successfully"<<std::endl;
	for(int i = 0; i < NUM_HW_ROWS; i ++) {
		for (int j = 0; j < NUM_ELMNTS / NUM_HW_ROWS; j++) {
			input_a_mapped_BOs[i][j] = (i * NUM_COLS + j) % 10;;
			result_aie_mapped_BOs[i][j] = 0;
		}
	}

	for (int i = 0; i < NUM_ELMNTS; i++) {
        	input_b_mapped_0[i] = 1;
	}

	std::cout<<"[INFO] Starting graph execution"<<std::endl;
        //////////////////////////////////////////
        // graph execution for AIE
        //////////////////////////////////////////
        /* Enable AIE cores */

        ghdl.run(1);

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		std::string input_gmio_port = "my_graph.matrix_ab[" + std::to_string(i) + "]";
		input_a_BOs[i].async(input_gmio_port, XCL_BO_SYNC_BO_GMIO_TO_AIE, MAT_A_CHUNK_SIZE, 0);
		input_b_0.async(input_gmio_port, XCL_BO_SYNC_BO_GMIO_TO_AIE, NUM_ELMNTS  * sizeof(int), 0);
	}

	for (int i = 0; i < NUM_HW_ROWS; i++) {
                std::string output_gmio_port = "my_graph.result[" + std::to_string(i) + "]";
		result_aie_BOs[i].sync(output_gmio_port, XCL_BO_SYNC_BO_AIE_TO_GMIO, MAT_A_CHUNK_SIZE, 0);
        }

	ghdl.wait();

	std::cout << "[INFO] AIE cores are done executing" << std::endl;

	int **result_apu;
	result_apu = (int **) std::malloc(len);

	/* Allocate memory for sanity check */
	for (int i = 0; i < NUM_ROWS; i++) {
		result_apu[i] = (int *)(result_apu + NUM_ROWS) + i * NUM_COLS;
		if (!result_apu[i]) {
			std::cout << "[INFO] Failed to allocate GMIO memory";
			std::cout << std::endl;
			return EXIT_FAILURE;
		}
	}
	/* Init app input data */
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			result_apu[i][j] = 0;
		}
	}
	/* For sanity check compute the same on APU */
	std::cout << "[INFO] Running sanity check" << std::endl;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
        		result_apu[i][j] = 0;

			// Determine which partition of A this row belongs to
			int partition_A = i / (NUM_ROWS / NUM_HW_ROWS);
			int local_i = i % (NUM_ROWS / NUM_HW_ROWS);
			int* input_a_mapped = input_a_mapped_BOs[partition_A];

			for (int k = 0; k < NUM_COLS; k++) {
				int index_A = local_i * NUM_COLS + k;
				int index_B = k * NUM_COLS + j;
				result_apu[i][j] += input_a_mapped[index_A] * input_b_mapped_0[index_B];
			}
		}
	}
	std::cout << "[INFO] Running validation check" << std::endl;

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			// Determine which partition of result_aie_mapped_BOs this entry belongs to
			int partition = i / (NUM_ROWS / NUM_HW_ROWS);
			int local_i = i % (NUM_ROWS / NUM_HW_ROWS);

			int* result_aie_mapped = result_aie_mapped_BOs[partition];
			int index_result_aie = local_i * NUM_COLS + j;

			// Compare CPU result with AIE result
			if (result_apu[j][i] != result_aie_mapped[index_result_aie]) {
				printf("[MISMATCH] At (%d, %d): CPU = %d, AIE = %d\n",
					i, j, result_apu[i][j], result_aie_mapped[index_result_aie]);
				pass = -1;
				break;
			}
		}
	}

	ghdl.end();

	if(pass == -1) {
		std::cout << "[ERROR] XGeMM Failed!" << std::endl;
		ret = -1;
	} else {
		std::cout << "[INFO] XGeMM Success!" << std::endl;
	}

#if !defined(__AIESIM__) && !defined(__ADF_FRONTEND__) && !defined(__AIEBAREMETAL__)
	dhdl.reset_array();
#endif
	return ret;
}
