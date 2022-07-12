/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#ifndef XGEMM_START_H
#define XGEMM_START_H

#include <adf.h>

void OneInput(input_window<int32>* __restrict dataIn,
		output_window<int32>* __restrict dataOut,
		output_window<int32>* __restrict result);

void TwoInputs(input_window<int32>* __restrict dataIn,
		input_window<int32>* __restrict bypassResult,
		output_window<int32>* __restrict dataOut,
		output_window<int32>* __restrict result);

void OneOutput(input_window<int32>* __restrict dataIn,
		input_window<int32>* __restrict bypassResult,
		output_window<int32>* __restrict result);
			
#endif
