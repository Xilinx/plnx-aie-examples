/******************************************************************************
* Copyright (C) 2019 - 2020 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#include <adf.h>
#include "kernels/config.h"
#include "xgemm.h"

using namespace adf;

PLIO plin[NUM_HW_ROWS] = {
	PLIO("plioin0", plio_64_bits),
	PLIO("plioin1", plio_64_bits),
	PLIO("plioin2", plio_64_bits),
	PLIO("plioin3", plio_64_bits),
	PLIO("plioin4", plio_64_bits),
	PLIO("plioin5", plio_64_bits),
	PLIO("plioin6", plio_64_bits),
	PLIO("plioin7", plio_64_bits),
};

PLIO plout[NUM_HW_ROWS] = {
	PLIO("plioout0", plio_64_bits),
	PLIO("plioout1", plio_64_bits),
	PLIO("plioout2", plio_64_bits),
	PLIO("plioout3", plio_64_bits),
	PLIO("plioout4", plio_64_bits),
	PLIO("plioout5", plio_64_bits),
	PLIO("plioout6", plio_64_bits),
	PLIO("plioout7", plio_64_bits),
};

simulation::platform<NUM_HW_ROWS, NUM_HW_ROWS> platform(&plin[0], &plin[1],
							&plin[2], &plin[3],
							&plin[4], &plin[5],
							&plin[6], &plin[7],
							&plout[0], &plout[1],
							&plout[2], &plout[3],
							&plout[4], &plout[5],
							&plout[6], &plout[7]);

XGeMM my_graph;

connect<> in0(platform.src[0], my_graph.matrix_ab[0]);
connect<> in1(platform.src[1], my_graph.matrix_ab[1]);
connect<> in2(platform.src[2], my_graph.matrix_ab[2]);
connect<> in3(platform.src[3], my_graph.matrix_ab[3]);
connect<> in4(platform.src[4], my_graph.matrix_ab[4]);
connect<> in5(platform.src[5], my_graph.matrix_ab[5]);
connect<> in6(platform.src[6], my_graph.matrix_ab[6]);
connect<> in7(platform.src[7], my_graph.matrix_ab[7]);

connect<> out0(my_graph.result[0], platform.sink[0]);
connect<> out1(my_graph.result[1], platform.sink[1]);
connect<> out2(my_graph.result[2], platform.sink[2]);
connect<> out3(my_graph.result[3], platform.sink[3]);
connect<> out4(my_graph.result[4], platform.sink[4]);
connect<> out5(my_graph.result[5], platform.sink[5]);
connect<> out6(my_graph.result[6], platform.sink[6]);
connect<> out7(my_graph.result[7], platform.sink[7]);

int main(void)
{
	/* Configure AIE */
	my_graph.init();

	/* Enable AIE cores */
	my_graph.run(1);

	/* Disable AIE cores */
	my_graph.end();

	return 0;
}
