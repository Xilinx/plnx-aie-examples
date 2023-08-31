/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#include <adf.h>
#include <aie_api/aie.hpp>
#include <aie_api/aie_adf.hpp>
#include <aie_api/utils.hpp>

#include "config.h"

void TwoInputs(input_window_int32 * dataIn, input_window_int32 * bypassResult,
	       output_window_int32 * dataOut, output_window_int32 * result)
{
	static int32 a[NUM_A_ELMNTS_PER_TILE];
	static int32 b[NUM_COLS];
	static int32 intrmdtResult[WIN_SIZE];
	static int32 count = 0;
	static int32 currentCol;

	currentCol = (get_coreid() & 0x7F0000) >> 16;

	for (unsigned i = 0; i < NUM_A_ELMNTS_PER_TILE / WIN_SIZE; i++) {
		window_acquire(dataIn);
		for (unsigned w = 0; w < WIN_SIZE / VECTOR_LENGTH; w++)
		chess_prepare_for_pipelining{
			aie::vector<int32, VECTOR_LENGTH> temp = window_readincr_v<VECTOR_LENGTH>(dataIn);
			aie::store_unaligned_v<VECTOR_LENGTH>(a + (i*WIN_SIZE) + (w*VECTOR_LENGTH), temp);
		}
		//a[i * WIN_SIZE + w] = window_readincr(dataIn);
		window_release(dataIn);
	}

	for (unsigned i = 0;
		      i < NUM_A_ELMNTS_PER_TILE *
		      		(NUM_HW_COLS - currentCol - 1) / WIN_SIZE;
		      i++)
	{
		window_acquire(dataOut);
		window_acquire(dataIn);
		for (unsigned w = 0; w < WIN_SIZE / VECTOR_LENGTH; w++)
		chess_prepare_for_pipelining{
			window_writeincr(dataOut, window_readincr_v<VECTOR_LENGTH>(dataIn));
		}
		window_release(dataIn);
		window_release(dataOut);
	}

	/*
	 * read one column of b, pass the same to the next core,
	 * compute matrix multiplication of 'a' rows x 'b' col and
	 * finally output the result
	 */
	for (unsigned i = 0; i < NUM_COLS; i++) {
		/* read 1 entire column of b */
		for (unsigned w = 0; w < (NUM_COLS / WIN_SIZE); w++) {
			window_acquire(dataOut);
			window_acquire(dataIn);
			for (unsigned x = 0; x < (WIN_SIZE/VECTOR_LENGTH); x++) 
			chess_prepare_for_pipelining{	
				aie::store_unaligned_v(b + (w* WIN_SIZE) + (x * VECTOR_LENGTH), window_readincr_v<VECTOR_LENGTH>(dataIn));
			}
			window_release(dataIn);
			window_release(dataOut);
		}

		for (unsigned k = 0; k < NUM_ROWS_PER_TILE; k++) {
			int32 add_result = 0;
			for (unsigned l = 0; l < NUM_COLS / VECTOR_LENGTH; l++)
			{
				aie::vector<int32, VECTOR_LENGTH> va = aie::load_v<VECTOR_LENGTH>(a + (k*NUM_COLS) + (l*VECTOR_LENGTH));
				aie::vector<int32, VECTOR_LENGTH> vb = aie::load_v<VECTOR_LENGTH>(b + (l*VECTOR_LENGTH));
				aie::accum<acc64, VECTOR_LENGTH> vm = aie::mul(va, vb);
				aie::vector<int32, VECTOR_LENGTH> result_vector = vm.to_vector<int32>(0);
				add_result += aie::reduce_add(result_vector);
			}
				intrmdtResult[count++] = add_result;
		}

		if (count == WIN_SIZE) { // dont worry, we will reach this as WIN_SIZE is the same as MAT_SIZE (NO OF COLS / ROWS) (WIN)SIZ is a multiple of no of elements
			/*
			 * copy the results from previous cores to the output
			 * window
			 */
			for (unsigned j = 0; j < currentCol; j++) {
				window_acquire(result);
				window_acquire(bypassResult);
				for (unsigned k = 0; k < WIN_SIZE/VECTOR_LENGTH; k++)
				chess_prepare_for_pipelining{
					window_writeincr(result,
							window_readincr_v<VECTOR_LENGTH>(bypassResult));
				}
				window_release(bypassResult);
				window_release(result);
			}

			window_acquire(result);
			for (unsigned z = 0; z < WIN_SIZE / VECTOR_LENGTH; z++) 
			
			{
				window_writeincr(result, aie::load_v<VECTOR_LENGTH>(intrmdtResult + (z*VECTOR_LENGTH)));	
				for (unsigned i = 0; i < VECTOR_LENGTH; ++i) 
					intrmdtResult[(z* VECTOR_LENGTH) + i] = 0;
			}
			window_release(result);
			count = 0;
		}
	}
}
