/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#include <adf.h>
#include "kernels.h"
#include "kernels/config.h"

using namespace adf;

class XGeMM : public adf::graph {
	private:
  		kernel krnl[NUM_HW_ROWS][NUM_HW_COLS];
	public:
		input_gmio matrix_ab[NUM_HW_ROWS];
		output_gmio result[NUM_HW_ROWS];

		XGeMM() {
			for (int r = 0; r < NUM_HW_ROWS; r++) {
				char str[10];

				sprintf(str, "gmioin%d", r);
				matrix_ab[r] = input_gmio::create(str, 64, 1);

				sprintf(str, "gmioout%d", r);
				result[r] = output_gmio::create(str, 64, 1);

				for (int c = 1; c < NUM_HW_COLS - 1; c++) {
					krnl[r][c] = kernel::create(TwoInputs);
					source(krnl[r][c]) = "kernels/two_inputs.cc";
					runtime<ratio>(krnl[r][c]) = 0.8;
					location<kernel>(krnl[r][c]) = tile(c, r);
				}
				
				if (r % 2 == 0){
					krnl[r][0] = kernel::create(OneInput);
					source(krnl[r][0]) = "kernels/one_input.cc";
					runtime<ratio>(krnl[r][0]) = 0.8;
					location<kernel>(krnl[r][0]) = tile(0, r);
		
					krnl[r][NUM_HW_COLS - 1] = kernel::create(OneOutput);
					source(krnl[r][NUM_HW_COLS - 1]) = "kernels/one_output.cc";
					runtime<ratio>(krnl[r][NUM_HW_COLS - 1]) = 0.8;
					location<kernel>(krnl[r][NUM_HW_COLS - 1]) = tile(NUM_HW_COLS - 1, r);

					connect<window<WIN_SIZE_BYTES>>(matrix_ab[r].out[0], async(krnl[r][0].in[0]));
					for (int c = 0; c < NUM_HW_COLS - 1; c++) {
						connect<window<WIN_SIZE_BYTES>>(async(krnl[r][c].out[0]), async(krnl[r][c + 1].in[0]));
						connect<window<WIN_SIZE_BYTES>>(async(krnl[r][c].out[1]), async(krnl[r][c + 1].in[1]));
						connect<cascade>(krnl[r][c].out[2], krnl[r][c+1].in[2]);
					}
					connect<window<WIN_SIZE_BYTES>>(async(krnl[r][NUM_HW_COLS - 1].out[0]), result[r].in[0]);
				} else {
					krnl[r][NUM_HW_COLS - 1] = kernel::create(OneInput);
					source(krnl[r][NUM_HW_COLS - 1]) = "kernels/one_input.cc";
					runtime<ratio>(krnl[r][NUM_HW_COLS - 1]) = 0.8;
					location<kernel>(krnl[r][NUM_HW_COLS - 1]) = tile(NUM_HW_COLS - 1, r);
		
					krnl[r][0] = kernel::create(OneOutput);
					source(krnl[r][0]) = "kernels/one_output.cc";
					runtime<ratio>(krnl[r][0]) = 0.8;
					location<kernel>(krnl[r][0]) = tile(0, r);

					connect<window<WIN_SIZE_BYTES>>(matrix_ab[r].out[0], async(krnl[r][NUM_HW_COLS - 1].in[0]));
					for (int c = NUM_HW_COLS - 1; c > 0; c--) {
						connect<window<WIN_SIZE_BYTES>>(async(krnl[r][c].out[0]), async(krnl[r][c - 1].in[0]));
						connect<window<WIN_SIZE_BYTES>>(async(krnl[r][c].out[1]), async(krnl[r][c - 1].in[1]));
						connect<cascade>(krnl[r][c].out[2], krnl[r][c-1].in[2]);
					}
					connect<window<WIN_SIZE_BYTES>>(async(krnl[r][0].out[0]), result[r].in[0]);
				}
			}
		}
};
