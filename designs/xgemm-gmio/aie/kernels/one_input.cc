/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#include <adf.h>
#include <aie_api/aie.hpp>
#include <aie_api/aie_adf.hpp>
#include <aie_api/utils.hpp>
#include "config.h"

void OneInput(input_window_int32 * dataIn, output_window_int32 * dataOut,
	      output_window_int32 * result)
{
	static int32 a[NUM_A_ELMNTS_PER_TILE];
	static int32 b[NUM_COLS];
	static int32 intrmdtResult[WIN_SIZE];
	static int32 count = 0;
	static int32 currentCol;

	currentCol = (get_coreid() & 0x7F0000) >> 16;

int time1=get_cycles();
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
int time2=get_cycles();
 
int time = time2 - time1;
dataTransfercc += time;
printf("one_input::[V]Reading from dataIn into matrix A took %d \n", time);

time1=get_cycles();
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
			//window_writeincr(dataOut, window_readincr(dataIn));
		window_release(dataIn);
		window_release(dataOut);
	}

time2=get_cycles();
time = time2 - time1;
dataTransfercc += time;
printf("one_input::[V]Reading from dataIn into dataOut took %d \n", time);

	/*
	 * read one column of b, pass the same to the next core,
	 * compute matrix multiplication of 'a' rows x 'b' col and
	 * finally output the result
	 */
	for (unsigned i = 0; i < NUM_COLS; i++) {
		/* read 1 entire column of b */
		time1=get_cycles();
		for (unsigned w = 0; w < (NUM_COLS/WIN_SIZE); w++) {
			window_acquire(dataOut);
			window_acquire(dataIn);
			for (unsigned x = 0; x < WIN_SIZE / VECTOR_LENGTH; x++) 
			chess_prepare_for_pipelining{
				aie::vector<int32, VECTOR_LENGTH> temp = window_readincr_v<VECTOR_LENGTH>(dataIn);
				aie::store_unaligned_v<VECTOR_LENGTH>(b + (w*WIN_SIZE) + (x*VECTOR_LENGTH), temp);
				window_writeincr(dataOut, aie::load_v<VECTOR_LENGTH>(b + (w*WIN_SIZE) + (x*VECTOR_LENGTH)));
				//b[w * WIN_SIZE + x] = window_readincr(dataIn);
				//window_writeincr(dataOut, b[w * WIN_SIZE + x]);
			}
			window_release(dataIn);
			window_release(dataOut);
		}
		time2=get_cycles();
		time = time2 - time1;
		dataTransfercc += time;
		printf("one_input::[V]Reading from dataIn into b; b into dataOut took %d \n", time);

		time1=get_cycles();
		
		//at this point we have a full column of B ready to be hammered by our rows
		for (unsigned k = 0; k < NUM_ROWS_PER_TILE; k++)
		{
			int32 add_result = 0;
			//each row has "NUM_COLS" number of elements
			for (unsigned l = 0; l < NUM_COLS / VECTOR_LENGTH; l++) chess_prepare_for_pipelining{
				aie::vector<int32, VECTOR_LENGTH> va = aie::load_v<VECTOR_LENGTH>(a + (k*NUM_COLS) + (l* VECTOR_LENGTH));
				aie::vector<int32, VECTOR_LENGTH> vb = aie::load_v<VECTOR_LENGTH>(b + (l*VECTOR_LENGTH)); // cuz we just be dealin with one column of b at a time 
				aie::accum<acc64, VECTOR_LENGTH> vres = aie::mul(va, vb);
				aie::vector<int32, VECTOR_LENGTH> result_vector = vres.to_vector<int32>(0);
				add_result = add_result + aie::reduce_add(result_vector);
			}
			intrmdtResult[count++] = add_result;
		}
		time2=get_cycles();
		time = time2 - time1;
		computecc += time;
		printf("one_input::[V]aie::mul Compute took %d \n", time);
		// for (unsigned k = 0; k < NUM_ROWS_PER_TILE; k++) {
		// 	for (unsigned l = 0; l < NUM_COLS; l++)
		// 		intrmdtResult[count] += a[k * NUM_COLS + l] * b[l];
		// 	count++;
		// }

		if (count == WIN_SIZE) {
time1=get_cycles();
			window_acquire(result);
			for (unsigned z = 0; z < WIN_SIZE/VECTOR_LENGTH; z++) chess_prepare_for_pipelining{
				window_writeincr(result, aie::load_v<VECTOR_LENGTH>(intrmdtResult + (z * VECTOR_LENGTH)));
				//reset 
				for (unsigned i = 0; i < VECTOR_LENGTH; ++i)
				{
					intrmdtResult[(z * VECTOR_LENGTH) + i] = 0;
				}
			}
			window_release(result);
			count = 0;
		
time2=get_cycles();
time = time2 - time1;
dataTransfercc += time;
printf("one_input::[V]Resykt write took %d \n", time);
		}
	}
}
