/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#ifndef XGEMM_START_H
#define XGEMM_START_H

#include <adf.h>

void OneInput(input_window<int32>* __restrict dataIn,
	      output_window<int32>* __restrict aOut,
	      output_window<int32>* __restrict result,
	      output_stream_acc48 *bOut);

void TwoInputs(input_window<int32>* __restrict aIn,
	       input_window<int32>* __restrict bypassResult,
	       input_stream_acc48 *bIn,
	       output_window<int32>* __restrict aOut,
	       output_window<int32>* __restrict result,
	       output_stream_acc48 *bOut);

void OneOutput(input_window<int32>* __restrict aIn,
	       input_window<int32>* __restrict bypassResult,
	       input_stream_acc48 *bIn,
	       output_window<int32>* __restrict result);
#endif
