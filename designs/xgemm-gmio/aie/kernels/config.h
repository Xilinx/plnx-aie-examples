/******************************************************************************
* Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#ifndef XGEMM_CONFIG_H
#define XGEMM_CONFIG_H

#define AIE			10
#define AIEML			20

#if (__AIE_ARCH__ == AIE)
#define NUM_HW_COLS		50
#define NUM_HW_ROWS		8
#define MAT_SIZE		1200
#define WIN_SIZE		600
#else
#define NUM_HW_COLS		38
#define NUM_HW_ROWS		8
#define MAT_SIZE		608
#define WIN_SIZE		608
#endif

#define NUM_COLS		MAT_SIZE
#define NUM_ROWS		MAT_SIZE
#define WIN_SIZE_BYTES		(WIN_SIZE * sizeof(int))

#define VECTOR_LENGTH		8

#define NUM_ROWS_PER_HW_ROW	(NUM_ROWS / NUM_HW_ROWS)
#define NUM_ROWS_PER_TILE	(NUM_ROWS_PER_HW_ROW / NUM_HW_COLS)

#define NUM_ELMNTS		(NUM_ROWS * NUM_COLS)
#define NUM_A_ELMNTS_PER_TILE	((NUM_ROWS_PER_HW_ROW * NUM_COLS) / NUM_HW_COLS)

#define MAT_A_CHUNK		(NUM_ROWS_PER_HW_ROW * NUM_COLS)
#define MAT_A_CHUNK_SIZE	(MAT_A_CHUNK * sizeof(int))

#endif
