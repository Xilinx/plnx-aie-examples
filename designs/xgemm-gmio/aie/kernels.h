/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#ifndef XGEMM_START_H
#define XGEMM_START_H

#include <adf.h>
#include "kernels/config.h"

#if (__AIE_ARCH__ == AIE)
void OneInput(input_window<int32>* __restrict dataIn,
	      output_window<int32>* __restrict aOut,
	      output_window<int32>* __restrict result,
	      output_cascade<acc48> *bOut);

void TwoInputs(input_window<int32>* __restrict aIn,
	       input_window<int32>* __restrict bypassResult,
	       input_cascade<acc48> *bIn,
	       output_window<int32>* __restrict aOut,
	       output_window<int32>* __restrict result,
	       output_cascade<acc48> *bOut);

void OneOutput(input_window<int32>* __restrict aIn,
	       input_window<int32>* __restrict bypassResult,
	       input_cascade<acc48> *bIn,
	       output_window<int32>* __restrict result);
#else
void OneInput(input_window_uint32 * dataIn,
		output_window_uint32 * dataOut,
		output_window_uint32 * result);

void TwoInputs(input_window_uint32 * dataIn,
		input_window_uint32 * bypassResult,
		output_window_uint32 * dataOut,
		output_window_uint32 * result);


void OneOutput(input_window_uint32 * dataIn,
		input_window_uint32 * bypassResult,
		output_window_uint32 * result);
#endif

#endif
