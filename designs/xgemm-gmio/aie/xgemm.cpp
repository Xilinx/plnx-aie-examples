/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#if !defined(__AIEBAREMETAL__)
#include <adf.h>
#include <fstream>

#include "kernels/config.h"
#endif
#include <unistd.h>

#if defined(__AIEBAREMETAL__)
#include "xil_cache.h"
#endif

#include "xgemm.h"

#if !defined(__AIESIM__) && !defined(__ADF_FRONTEND__) && !defined(__AIEBAREMETAL__)
	#include "adf/adf_api/XRTConfig.h"
#endif

#if !defined(__AIEBAREMETAL__)
using namespace adf;
#endif

XGeMM my_graph;

#if !defined(__AIESIM__) && !defined(__ADF_FRONTEND__) && !defined(__AIEBAREMETAL__)
static std::vector<char>
load_xclbin(xrtDeviceHandle device, const std::string& fnm)
{
	if (fnm.empty())
		throw std::runtime_error("No XCLBIN specified");

	/* Load bit stream */
	std::ifstream stream(fnm);
	stream.seekg(0,stream.end);
	size_t size = stream.tellg();
	stream.seekg(0,stream.beg);

	std::vector<char> header(size);
	stream.read(header.data(),size);

	auto top = reinterpret_cast<const axlf*>(header.data());
	if (xrtDeviceLoadXclbin(device, top))
		throw std::runtime_error("Bitstream download failed");

	return header;
}
#endif

int main(int argc, char ** argv)
{
	std::cout << "[INFO] AIE GMIO Matrix Multiplication" << std::endl;
	std::cout << "[INFO] Matrix size(int32): " <<  NUM_ROWS
		  << "x" <<  NUM_COLS << std::endl;

	/* Add delay print banner to stdout */
	sleep(1);

#if defined(__AIEBAREMETAL__)
	Xil_DCacheDisable();
#endif

#if !defined(__AIESIM__) && !defined(__ADF_FRONTEND__) && !defined(__AIEBAREMETAL__)
	std::string xclbinFilename;
	if(argc != 2)
		xclbinFilename = "/usr/bin/aie-matrix-multiplication.xclbin";
	else
		xclbinFilename = argv[1];

	auto dhdl = xrtDeviceOpen(0);
	if (!dhdl) {
		std::cout << "[ERROR] Device open error" << std::endl;
		return EXIT_FAILURE;
	}

	auto xclbin = load_xclbin(dhdl, xclbinFilename);
	if(!xclbin.size()) {
		std::cout << "[ERROR] XCLBIN load error" << std::endl;
		return EXIT_FAILURE;
	};

	auto top = reinterpret_cast<const axlf*>(xclbin.data());
	adf::registerXRT(dhdl, top->m_header.uuid);
	std::cout << "[INFO] XCLBIN download complete" << std::endl;
#endif

	/* Configure AIE */
	my_graph.init();

	int ret = 0, pass = 0;
	int **in_aie_a, **in_aie_bt, **out_aie_c;
	int **input_a, **input_b, **result_aie, **result_apu;
	int len = NUM_ELMNTS * sizeof(int) + NUM_ROWS * sizeof(int *);

	input_a = (int **) std::malloc(len);
	input_b = (int **) std::malloc(len);
	result_aie = (int **) std::malloc(len);
	result_apu = (int **) std::malloc(len);

	in_aie_bt = (int **) GMIO::malloc(len);
	in_aie_a = (int **) GMIO::malloc(NUM_HW_ROWS * sizeof(int *) + NUM_HW_ROWS * MAT_A_CHUNK_SIZE);
	out_aie_c = (int **) GMIO::malloc(NUM_HW_ROWS * sizeof(int *) + NUM_HW_ROWS * MAT_A_CHUNK_SIZE);

	/* Allocate memory for sanity check */
	for (int i = 0; i < NUM_ROWS; i++) {
		input_a[i] = (int *)(input_a + NUM_ROWS) + i * NUM_COLS;
		input_b[i] = (int *)(input_b + NUM_ROWS) + i * NUM_COLS;
		in_aie_bt[i] = (int *)(in_aie_bt + NUM_ROWS) + i * NUM_COLS;
		result_aie[i] = (int *)(result_aie + NUM_ROWS) + i * NUM_COLS;
		result_apu[i] = (int *)(result_apu + NUM_ROWS) + i * NUM_COLS;
		if (!input_a[i] || !input_b[i] || !result_aie[i] || !result_apu[i]) {
			std::cout << "[INFO] Failed to allocate GMIO memory";
			std::cout << std::endl;
			return EXIT_FAILURE;
		}
	}

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		in_aie_a[i] = (int *)((int **)in_aie_a + NUM_HW_ROWS) + i * MAT_A_CHUNK;
		out_aie_c[i] = (int *)((int **)out_aie_c + NUM_HW_ROWS) + i * MAT_A_CHUNK;
		if (!in_aie_a[i] || !out_aie_c[i]) {
			std::cout << "[INFO] Failed to allocate GMIO memory";
			std::cout << std::endl;
			return EXIT_FAILURE;
		}
	}

	/* Init app input data */
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			input_a[i][j] = (i * NUM_COLS + j) % 10;
			input_b[i][j] = 1;
			in_aie_bt[j][i] = input_b[i][j];
			result_aie[i][j] = 0;
			result_apu[i][j] = 0;
		}
	}

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		for (int j = 0; j < MAT_A_CHUNK; j++) {
			in_aie_a[i][j] = input_a[i * NUM_ROWS_PER_HW_ROW + j / NUM_COLS][j % NUM_COLS];
		}
	}

	/* Enable AIE cores */
	my_graph.run(1);

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		my_graph.matrix_ab[i].gm2aie_nb(in_aie_a[i], MAT_A_CHUNK_SIZE);
		my_graph.matrix_ab[i].gm2aie_nb(in_aie_bt[0], NUM_ELMNTS * sizeof(int));
	}

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		my_graph.result[i].aie2gm(out_aie_c[i], MAT_A_CHUNK_SIZE);
	}

	/*
	 * Assuming data from gmin are processed by the graph and output to
	 * gmout
	 */
	for (int i = 0; i < NUM_HW_ROWS; i++) {
		my_graph.result[i].wait();
	}
	std::cout << "[INFO] AIE cores are done executing" << std::endl;

	/* Z-ordering */
	for (int i = 0; i < NUM_COLS / (WIN_SIZE / NUM_ROWS_PER_TILE); i++) {
		for (int j = 0; j < NUM_HW_ROWS; j++) {
			for (int k = 0; k < NUM_HW_COLS; k++) {
				for (int m = 0; m < WIN_SIZE / NUM_ROWS_PER_TILE; m++) {
					for (int l = 0; l < NUM_ROWS_PER_TILE; l++) {
						result_aie[j * NUM_ROWS_PER_HW_ROW + k * NUM_ROWS_PER_TILE + l][i * (WIN_SIZE / NUM_ROWS_PER_TILE) + m]
							= ((int *)((int **)out_aie_c + NUM_HW_ROWS))[j * MAT_A_CHUNK + i * NUM_ROWS_PER_HW_ROW * (WIN_SIZE / NUM_ROWS_PER_TILE) + k * WIN_SIZE + m * NUM_ROWS_PER_TILE + l];
					}
				}
			}
		}
	}

	/* For sanity check compute the same on APU */
	std::cout << "[INFO] Running sanity check" << std::endl;
	for(int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			for (int k = 0; k < NUM_COLS; k++) {
				result_apu[i][j] += input_a[i][k] * input_b[k][j];
			}
		}
	}

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (result_aie[i][j] == result_apu[i][j])
				continue;

			std::cout << "[ERROR] Data mismatch: "
				  << "AIE[" << i << "][" << j << "] = "
				  << result_aie[i][j] << " APU[" << i
				  << "][" << j << "] =" << result_apu[i][j]
				  << std::endl;
			pass = -1;
		}
	}

	GMIO::free(in_aie_a);
	GMIO::free(out_aie_c);
	GMIO::free(in_aie_bt);

	std::free(input_a);
	std::free(input_b);
	std::free(result_aie);
	std::free(result_apu);

	/* Disable AIE cores */
	my_graph.end();

	if(pass == -1) {
		std::cout << "[ERROR] XGeMM Failed!" << std::endl;
		ret = -1;
	} else {
		std::cout << "[INFO] XGeMM Success!" << std::endl;
	}

#if !defined(__AIESIM__) && !defined(__ADF_FRONTEND__) && !defined(__AIEBAREMETAL__)
	xrtDeviceClose(dhdl);
#endif

	return ret;
}
