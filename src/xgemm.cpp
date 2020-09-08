/******************************************************************************
* Copyright (C) 2019 - 2020 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

#include <adf.h>
#include <sys/time.h>
#include <unistd.h>
#include "xgemm.h"
#include "kernels.h"
#include "kernels/config.h"

#include "experimental/xrt_bo.h"
#include "experimental/xrt_device.h"

extern "C"
{
	#include <fcntl.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/mman.h>
	#include <time.h>
}

#define ENABLE			1
#define DISABLE			0

#define DEBUG			0
#define ENABLE_PROFILING	0

#if ENABLE_PROFILING
#define CAL_THROUGHPUT		1
#define CAL_BANDWIDTH		0
#define CAL_GLATENCY		0
#endif

#define raw_printf(format, ...)	printf(format, ##__VA_ARGS__)
#define LPRINTF(format, ...)	raw_printf("PLIO MCDMA> " format, ##__VA_ARGS__)
#if DEBUG
#define LPDEBUG(format, ...)	raw_printf("PLIO MCDMA> " format, ##__VA_ARGS__)
#else
#define LPDEBUG(...)
#endif
#define raw_perror(format, ...)	fprintf(stderr, format, ##__VA_ARGS__)
#define LPERROR(format, ...)	raw_perror("ERROR: PLIO MCDMA> " format, ##__VA_ARGS__)

#define MM2S_BUF_LEN		(WIN_SIZE_BYTES)
#define S2MM_BUF_LEN		(WIN_SIZE_BYTES)

#define DMA_BD_SIZE		0x40UL
#define MM2S_BD_CHAIN_SIZE	(DMA_BD_SIZE * ((NUM_ROWS_PER_HW_ROW * NUM_COLS + NUM_ELMNTS) / WIN_SIZE) * sizeof(int))
#define S2MM_BD_CHAIN_SIZE	(DMA_BD_SIZE * ((NUM_ROWS_PER_HW_ROW * NUM_COLS) / WIN_SIZE) * sizeof(int))

#define MM2S_DATA_SIZE		((NUM_ROWS_PER_HW_ROW * NUM_COLS + NUM_ELMNTS) * sizeof(int))
#define S2MM_DATA_SIZE		(NUM_ROWS_PER_HW_ROW * NUM_COLS * sizeof(int))
#define MAT_A_CHUNK_SIZE	(NUM_ROWS_PER_HW_ROW * NUM_COLS * sizeof(int))

#define INOUT_BUF_SIZE		(NUM_ELMNTS * sizeof(int) * 6)
#define DMA_BD_BUF_SIZE		(MM2S_BD_CHAIN_SIZE * NUM_HW_ROWS + S2MM_BD_CHAIN_SIZE * NUM_HW_ROWS)
#define BUFFER_SIZE		(INOUT_BUF_SIZE + DMA_BD_BUF_SIZE)

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

typedef struct {
	uint32_t dma_pa;
	unsigned char *dma_va;
	uint32_t send_buf_size;
	uint32_t recv_buf_size;
	uint64_t send_tail_bd_pa[16];
	uint64_t recv_tail_bd_pa[16];
	uint64_t send_bd_pa[16];
	uint64_t recv_bd_pa[16];
	uint64_t send_bd_total_size;
	uint64_t recv_bd_total_size;
	uint64_t send_bd_va[16];
	uint64_t recv_bd_va[16];
} xaxidma_t;

typedef struct {
	PLIO *pl_port;
	int event_handle;
	long long cycle_count;
} profile_plio_t;

typedef struct {
	xaxidma_t *dma;
	uint32_t chan_id;
	profile_plio_t *profile;
	uint8_t enable_profile;
} xaxidma_send_chan_t, xaxidma_recv_chan_t;

static xaxidma_t xdmas[] = {
	{.dma_pa = 0xa4000000,},
	{.dma_pa = 0xa4010000,},
	{.dma_pa = 0xa4020000,},
	{.dma_pa = 0xa4030000,},
	{.dma_pa = 0xa4040000,},
	{.dma_pa = 0xa4050000,},
	{.dma_pa = 0xa4060000,},
	{.dma_pa = 0xa4070000,}
};

static profile_plio_t profile_in[] = {
	{.pl_port = &plin[0],},
	{.pl_port = &plin[1],},
	{.pl_port = &plin[2],},
	{.pl_port = &plin[3],},
	{.pl_port = &plin[4],},
	{.pl_port = &plin[5],},
	{.pl_port = &plin[6],},
	{.pl_port = &plin[7],}
};
static profile_plio_t profile_out[] = {
	{.pl_port = &plout[0],},
        {.pl_port = &plout[1],},
        {.pl_port = &plout[2],},
        {.pl_port = &plout[3],},
        {.pl_port = &plout[4],},
        {.pl_port = &plout[5],},
        {.pl_port = &plout[6],},
        {.pl_port = &plout[7],}
};

static xaxidma_send_chan_t xdma_send_chans[] = {
	{.dma = &xdmas[0], .chan_id = 1, .profile = &profile_in[0],},
	{.dma = &xdmas[1], .chan_id = 1, .profile = &profile_in[1],},
	{.dma = &xdmas[2], .chan_id = 1, .profile = &profile_in[2],},
	{.dma = &xdmas[3], .chan_id = 1, .profile = &profile_in[3],},
	{.dma = &xdmas[4], .chan_id = 1, .profile = &profile_in[4],},
	{.dma = &xdmas[5], .chan_id = 1, .profile = &profile_in[5],},
	{.dma = &xdmas[6], .chan_id = 1, .profile = &profile_in[6],},
	{.dma = &xdmas[7], .chan_id = 1, .profile = &profile_in[7],}
};

static xaxidma_recv_chan_t xdma_recv_chans[] = {
	{.dma = &xdmas[7], .chan_id = 3, .profile = &profile_out[0],},
	{.dma = &xdmas[6], .chan_id = 6, .profile = &profile_out[1],},
	{.dma = &xdmas[5], .chan_id = 6, .profile = &profile_out[2],},
	{.dma = &xdmas[4], .chan_id = 6, .profile = &profile_out[3],},
	{.dma = &xdmas[3], .chan_id = 6, .profile = &profile_out[4],},
	{.dma = &xdmas[2], .chan_id = 6, .profile = &profile_out[5],},
	{.dma = &xdmas[1], .chan_id = 6, .profile = &profile_out[6],},
	{.dma = &xdmas[0], .chan_id = 6, .profile = &profile_out[7],}
};

void start_throughput_profile(profile_plio_t *profile, uint32_t data_size)
{
	PLIO *port  = profile->pl_port;
	int handle;

	/* Calculate throughtput */
	handle = event::start_profiling(*port,
					event::io_stream_start_to_bytes_transferred_cycles,
					data_size);

	profile->event_handle = handle;
}

void start_bandwidth_profile(profile_plio_t *profile)
{
	PLIO *port  = profile->pl_port;
	int handle;

	/* Calculate bandwidth */
	handle = event::start_profiling(*port,
					event::io_total_stream_running_to_idle_cycles);

	profile->event_handle = handle;
}

void start_latency_profile(profile_plio_t *profile_in, profile_plio_t *profile_out)
{
	PLIO *port_in  = profile_in->pl_port;
	PLIO *port_out = profile_out->pl_port;
	int handle;

	/* Calculate graph latency */
	handle = event::start_profiling(*port_in, *port_out,
					event::io_stream_start_difference_cycles);

	profile_out->event_handle = handle;
}

void stop_plio_profile(profile_plio_t *profile)
{
	long long cycle_count;
	int handle = profile->event_handle;

	cycle_count = event::read_profiling(handle);
	profile->cycle_count = cycle_count;

	LPDEBUG("%s: event handle id = 0x%llx count = 0x0x%lx\n", __func__,
							handle, cycle_count);

	event::stop_profiling(handle);
}

void reset_dma(xaxidma_t *dma)
{
	unsigned char *xaxidma_va = (unsigned char *)(dma->dma_va);

	/* Soft reset enable */
	*((volatile uint32_t *)(xaxidma_va + 0x0)) = 0x4;
	*((volatile uint32_t *)(xaxidma_va + 0x500)) = 0x4;

	sleep(1);

	/* Soft reset disable */
	*((volatile uint32_t *)(xaxidma_va + 0x0)) = 0;
	*((volatile uint32_t *)(xaxidma_va + 0x500)) = 0;
}

int init_dmas(int devmem_fd, uint64_t *mm2s_bd_chain_va,
	      uint64_t *mm2s_bd_chain_pa, uint64_t *s2mm_bd_chain_va,
	      uint64_t *s2mm_bd_chain_pa)
{
	unsigned int page_addr, page_offset;
	unsigned int page_size = sysconf(_SC_PAGESIZE);
	void *mm_ptr;

	for (unsigned int i = 0; i < sizeof(xdmas) / sizeof(xdmas[0]); i++) {
		LPRINTF("%s: 0x%x, page size: 0x%x\n", __func__,
						xdmas[i].dma_pa, page_size);

		page_addr = (xdmas[i].dma_pa & ~(page_size - 1));
		page_offset = (unsigned int)xdmas[i].dma_pa - page_addr;
		mm_ptr = mmap(NULL, page_size, PROT_READ|PROT_WRITE, MAP_SHARED,
							devmem_fd, page_addr);
		if (mm_ptr == NULL) {
			LPERROR("Failed to mmap axi dma address, 0x%x\r\n",
							xdmas[i].dma_pa);
			return -EINVAL;
		}

		xdmas[i].dma_va = (unsigned char *)mm_ptr + page_offset;
		xdmas[i].send_buf_size = MM2S_BUF_LEN;
		xdmas[i].recv_buf_size = S2MM_BUF_LEN;
		xdmas[i].send_bd_total_size = MM2S_BD_CHAIN_SIZE;
		xdmas[i].recv_bd_total_size = S2MM_BD_CHAIN_SIZE;

		reset_dma(&xdmas[i]);
	}

	for (unsigned int i = 0;
			i < sizeof(xdma_send_chans) / sizeof(xdma_send_chans[0]);
			i++)
	{
		xaxidma_t *dma = xdma_send_chans[i].dma;
		dma->send_bd_va[xdma_send_chans[i].chan_id - 1] = mm2s_bd_chain_va[i];
		dma->send_bd_pa[xdma_send_chans[i].chan_id - 1] = mm2s_bd_chain_pa[i];
	}

	for (unsigned int i = 0;
			i < sizeof(xdma_recv_chans) / sizeof(xdma_recv_chans[0]);
			i++)
	{
		xaxidma_t *dma = xdma_recv_chans[i].dma;
		dma->recv_bd_va[xdma_recv_chans[i].chan_id - 1] = s2mm_bd_chain_va[i];
		dma->recv_bd_pa[xdma_recv_chans[i].chan_id - 1] = s2mm_bd_chain_pa[i];
	}

	return 0;
}

uint32_t chain_mm2s_bds(xaxidma_send_chan_t *dma_send_chan,
			uint64_t mem_mat_a_pa, uint64_t mem_mat_bt_pa)
{
	xaxidma_t *dma = dma_send_chan->dma;
	uint64_t curr_bd_va = dma->send_bd_va[dma_send_chan->chan_id - 1];
	uint64_t curr_bd_pa = dma->send_bd_pa[dma_send_chan->chan_id - 1];
	uint64_t next_bd_pa = curr_bd_pa + DMA_BD_SIZE;
	uint32_t bd_trans_size = dma->send_buf_size;
	uint32_t total_bds;
	uint32_t control_value;
	uint32_t mm2s_data_queued = 0;

	/* Init with the pysical address of chunk of matrix A */
	uint64_t mm2s_buf_addr = mem_mat_a_pa;

	/* Init with the size of chunk of matrix A */
	uint32_t rem_size = MAT_A_CHUNK_SIZE;

	/* Total BDs in BD chain */
	total_bds = MM2S_DATA_SIZE / bd_trans_size;
	if ((MM2S_DATA_SIZE % bd_trans_size) != 0) {
		total_bds += 1;
	}

	LPDEBUG("%s: DMA physical address = 0x%lx\r\n", __func__, dma->dma_pa);
	LPDEBUG("%s: matrix A physical address: 0x%lx\r\n", __func__, mem_mat_a_pa);
	LPDEBUG("%s: transaction size = 0x%x\r\n", __func__, MM2S_DATA_SIZE);
	LPDEBUG("%s: single BD transaction length = 0x%x\r\n", __func__, bd_trans_size);
	LPDEBUG("%s: BD chain physical address = 0x%lx\r\n", __func__, curr_bd_pa);
	LPDEBUG("%s: total number of BDs in the chain = 0x%lx\r\n", __func__, total_bds);

	/* Reset BD configs */
	memset((void *)curr_bd_va, 0, MM2S_BD_CHAIN_SIZE);

	/* Chain BDs to send chunk of matrix A */
	while (mm2s_data_queued < MM2S_DATA_SIZE) {
		/* Higher 32-bits of next descriptor */
		*((volatile uint32_t *)(curr_bd_va + 0x4)) = next_bd_pa >> 32;

		/* Lower 32-bits of 16-word aligned next descriptor */
		*((volatile uint32_t *)(curr_bd_va + 0x0)) = next_bd_pa & 0xFFFFFFC0;

		/* Higher 32-bits of buffer addr */
		*((volatile uint32_t *)(curr_bd_va + 0xc)) = mm2s_buf_addr >> 32;

		/* Lower 32-bits of buffer addr */
		*((volatile uint32_t *)(curr_bd_va + 0x8)) = mm2s_buf_addr & 0xFFFFFFFF;

		/* Buffer length */
		control_value = bd_trans_size & 0x3FFFFFF;

		/* End 0f frame */
		control_value |= 0x40000000;

		/* Start of frame */
		control_value |= 0x80000000;

		/* Start of frame | End of frame | Buffer length */
		*((volatile uint32_t *)(curr_bd_va + 0x14)) = control_value;

		/* Update the counters */
		rem_size -= bd_trans_size;
		mm2s_data_queued += bd_trans_size;
		curr_bd_va += DMA_BD_SIZE;

		/* Last window size of matrix B to be queued */
		if (rem_size == bd_trans_size &&
			mm2s_data_queued == (MM2S_DATA_SIZE - bd_trans_size)) {
			LPDEBUG("%s: Chaining last BD in the chain. Data queued = 0x%x\n",
					__func__, mm2s_data_queued);

			/* Record the physical address of tail BD */
			dma->send_tail_bd_pa[dma_send_chan->chan_id - 1] = next_bd_pa;

			mm2s_buf_addr += bd_trans_size;
		}
		/* After chaining BDs for matrix A chain BDs for matrix B */
		else if (rem_size == 0 && (mm2s_data_queued < MM2S_DATA_SIZE)) {
			LPDEBUG("%s: Chaining BDs for matrix A compelete. Data queued = 0x%x\n",
					__func__, mm2s_data_queued);
			next_bd_pa += DMA_BD_SIZE;
			mm2s_buf_addr = mem_mat_bt_pa;
			rem_size = NUM_ELMNTS * sizeof(int);
		} else {
			next_bd_pa += DMA_BD_SIZE;
			mm2s_buf_addr += bd_trans_size;
		}
	}

	return mm2s_data_queued;
}

uint32_t chain_s2mm_bds(xaxidma_recv_chan_t *dma_recv_chan, uint64_t mem_mat_c_pa)
{
	xaxidma_t *dma = dma_recv_chan->dma;
	uint64_t curr_bd_va = dma->recv_bd_va[dma_recv_chan->chan_id - 1];
	uint64_t curr_bd_pa = dma->recv_bd_pa[dma_recv_chan->chan_id - 1];
	uint64_t next_bd_pa = curr_bd_pa + DMA_BD_SIZE;
	uint32_t bd_trans_size = dma->recv_buf_size;
	uint32_t total_bds;
	uint32_t control_value;
	uint32_t s2mm_data_queued = 0;

	/* Init with the pysical address of chunk of matrix C */
	uint64_t s2mm_buf_addr = mem_mat_c_pa;

	/* Set up the descriptor and mm2s */
	total_bds = S2MM_DATA_SIZE / bd_trans_size;
	if ((S2MM_DATA_SIZE % bd_trans_size) != 0) {
		total_bds += 1;
	}

	LPDEBUG("%s: DMA physical address = 0x%lx\r\n", __func__, dma->dma_pa);
	LPDEBUG("%s: matrix C physical address: 0x%lx\r\n", __func__, mem_mat_c_pa);
	LPDEBUG("%s: transaction size = 0x%x\r\n", __func__, S2MM_DATA_SIZE);
	LPDEBUG("%s: single BD transaction length = 0x%x\r\n", __func__, bd_trans_size);
	LPDEBUG("%s: BD chain physical address = 0x%lx\r\n", __func__, curr_bd_pa);
	LPDEBUG("%s: total number of BDs in the chain = 0x%lx\r\n", __func__, total_bds);

	/* Reset BD configs */
	memset((void *)curr_bd_va, 0, S2MM_BD_CHAIN_SIZE);

	/* Chain BDs to receive chunk of matrix C */
	while (s2mm_data_queued < S2MM_DATA_SIZE) {
		/* Higher 32-bits of next descriptor */
		*((volatile uint32_t *)(curr_bd_va + 0x4)) = next_bd_pa >> 32;

		/* Lower 32-bits of 16-word aligned next descriptor */
		*((volatile uint32_t *)(curr_bd_va + 0x0)) = next_bd_pa & 0xFFFFFFC0;

		/* Higher 32-bits of buffer addr */
		*((volatile uint32_t *)(curr_bd_va + 0xc)) = s2mm_buf_addr >> 32;

		/* Lower 32-bits of buffer addr */
		*((volatile uint32_t *)(curr_bd_va + 0x8)) = s2mm_buf_addr & 0xFFFFFFFF;

		/* Buffer length */
		control_value = bd_trans_size & 0x3FFFFFF;

		/* Assert end of frame signal in the last BD */
		if (s2mm_data_queued == S2MM_DATA_SIZE - bd_trans_size)
			control_value |= 0x40000000;

		/* Assert start of frame in the first BD */
		if (s2mm_data_queued == 0)
			control_value |= 0x80000000;

		/* Start of frame | End of frame | Buffer length */
		*((volatile uint32_t *)(curr_bd_va + 0x14)) = control_value;

		/* Update the counter */
		s2mm_data_queued += bd_trans_size;
		s2mm_buf_addr += bd_trans_size;
		curr_bd_va += DMA_BD_SIZE;

		/* Last window size of matrix C to be queued */
		if (s2mm_data_queued == S2MM_DATA_SIZE - bd_trans_size) {
			LPDEBUG("%s: Chaining last BD in the chain. Data queued = 0x%x\n",
						__func__, s2mm_data_queued);

			/* Record the physical address of tail BD */
			dma->recv_tail_bd_pa[dma_recv_chan->chan_id - 1] = next_bd_pa;
		} else {
			next_bd_pa += DMA_BD_SIZE;
		}
	}

	return s2mm_data_queued;
}

void enable_s2mm_channel(xaxidma_recv_chan_t *dma_recv_chan, uint8_t profile_port)
{
	xaxidma_t *dma = dma_recv_chan->dma;
	uint32_t chan_id = dma_recv_chan->chan_id - 1;
	uint32_t chan_offset = DMA_BD_SIZE * (chan_id + 1);
	uint64_t curr_bd_pa = dma->recv_bd_pa[chan_id];
	uint64_t tail_bd_pa = dma->recv_tail_bd_pa[chan_id];
	unsigned char *xaxidma_va = (unsigned char *)(dma->dma_va);

	LPDEBUG("%s: DMA physical address = 0x%lx. Channel ID = 0x%x\n",
						__func__, dma->dma_pa, chan_id);

#if ENABLE_PROFILING
	if (profile_port == ENABLE) {
#if CAL_THROUGHPUT
		/* Start shim performance counters to count clock cycles */
		start_throughput_profile(dma_recv_chan->profile, S2MM_DATA_SIZE);
		dma_recv_chan->enable_profile = ENABLE;
#elif CAL_BANDWIDTH
		/* Start shim performance counters to count clock cycles */
		start_bandwidth_profile(dma_recv_chan->profile);
		dma_recv_chan->enable_profile = ENABLE;
#endif
	} else {
#if !CAL_GLATENCY
		dma_recv_chan->enable_profile = DISABLE;
#endif
	}
#endif

	/* Enable S2MM channel */
	*((volatile uint32_t *)(xaxidma_va + 0x500 + 0x8)) = (0x1 << chan_id);

	/* Program current descriptor */
	LPDEBUG("%s: Channel ID = 0x%x. Start BD physical address = 0x%lx\n",
						__func__, chan_id, curr_bd_pa);

	/* Lower 32-bits of 16-word aligned first descriptor in the BD chain */
	*((volatile uint32_t *)(xaxidma_va + 0x500 + chan_offset + 0x8)) = curr_bd_pa & 0xFFFFFFC0;
	/* Higher 32-bits of first descriptor in the BD chain */
	*((volatile uint32_t *)(xaxidma_va + 0x500 + chan_offset + 0xc)) = curr_bd_pa >> 32;

	/* Enable Fetch bit in the channel control register */
	*((volatile uint32_t *)(xaxidma_va + 0x500 + chan_offset + 0x0)) = 0x1;

	/* Run the device */
	*((volatile uint32_t *)(xaxidma_va + 0x500 + 0x0)) = 0x1;

	/* Program tail descriptor */
	LPDEBUG("%s: Channel ID = 0x%x. Tail BD physical address = 0x%lx\n\n",
						__func__, chan_id, tail_bd_pa);
	*((volatile uint32_t *)(xaxidma_va + 0x500 + chan_offset + 0x10)) = tail_bd_pa & 0xFFFFFFC0;
	*((volatile uint32_t *)(xaxidma_va + 0x500 + chan_offset + 0x14)) = tail_bd_pa >> 32;

	return;
}

void enable_mm2s_channel(xaxidma_send_chan_t *dma_send_chan,
			 xaxidma_recv_chan_t *dma_recv_chan, uint8_t profile_port)
{
	xaxidma_t *dma = dma_send_chan->dma;
	uint32_t chan_id = dma_send_chan->chan_id - 1;
	uint32_t chan_offset = DMA_BD_SIZE * (chan_id + 1);
	uint64_t curr_bd_pa = dma->send_bd_pa[chan_id];
	uint64_t tail_bd_pa = dma->send_tail_bd_pa[chan_id];
	unsigned char *xaxidma_va = (unsigned char *)(dma->dma_va);

	LPDEBUG("%s: DMA physical address = 0x%lx. Channel ID = 0x%x\n",
						__func__, dma->dma_pa, chan_id);

#if ENABLE_PROFILING
	if (profile_port ==  ENABLE) {
#if CAL_THROUGHPUT
		/* Start shim performance counters to count clock cycles */
		start_throughput_profile(dma_send_chan->profile, MM2S_DATA_SIZE);
#elif CAL_BANDWIDTH
		/* Start shim performance counters to count clock cycles */
		start_bandwidth_profile(dma_send_chan->profile);
#elif CAL_GLATENCY
		/* Start shim performance counters to count clock cycles */
		start_latency_profile(dma_send_chan->profile, dma_recv_chan->profile);
		dma_recv_chan->enable_profile = ENABLE;
#endif
		dma_send_chan->enable_profile = ENABLE;
	} else {
#if CAL_GLATENCY
		dma_recv_chan->enable_profile = DISABLE;
#endif
		dma_send_chan->enable_profile = DISABLE;
	}
#endif

	/* Disable all the active channels */
	*((volatile uint32_t *)(xaxidma_va + 0x8)) = 0x0;

	/* Program current descriptor */
	LPDEBUG("%s: Channel ID = 0x%x. Start BD physical address = 0x%lx\n",
						__func__, chan_id, curr_bd_pa);

	/* Lower 32-bits of 16-word aligned first descriptor in the BD chain */
	*((volatile uint32_t *)(xaxidma_va + chan_offset + 0x8)) = curr_bd_pa & 0xFFFFFFC0;
	/* Higher 32-bits of first descriptor in the BD chain */
	*((volatile uint32_t *)(xaxidma_va + chan_offset + 0xc)) = curr_bd_pa >> 32;

	/* Enable Fetch bit in the channel control register */
	*((volatile uint32_t *)(xaxidma_va + chan_offset + 0x0)) = 0x1;

	/* Run the device */
	*((volatile uint32_t *)(xaxidma_va + 0x0)) = 0x1;

	/* Program tail descriptor */
	LPDEBUG("%s: Channel ID = 0x%x. Tail BD physical address = 0x%lx\n\n",
						__func__, chan_id, tail_bd_pa);
	*((volatile uint32_t *)(xaxidma_va + chan_offset + 0x10)) = tail_bd_pa & 0xFFFFFFC0;
	*((volatile uint32_t *)(xaxidma_va + chan_offset + 0x14)) = tail_bd_pa >> 32;

	/* Enable MM2S channel */
	*((volatile uint32_t *)(xaxidma_va + 0x8)) = 0x1 << chan_id;

	return;
}

void wait_s2mm_channel(xaxidma_recv_chan_t *dma_recv_chan)
{
	xaxidma_t *dma = dma_recv_chan->dma;
	unsigned char *xaxidma_va = (unsigned char *)(dma->dma_va);
	uint32_t s2mm_status;

	s2mm_status = *((volatile uint32_t *)(xaxidma_va + 0x504));
	while ((s2mm_status & 0x2) == 0)
		s2mm_status = *((volatile uint32_t *)(xaxidma_va + 0x504));

	LPDEBUG("%s: DMA physical address = 0x%lx. S2MM status = 0x%x\n",
					__func__, dma->dma_pa, s2mm_status);
#if ENABLE_PROFILING
	if (dma_recv_chan->enable_profile == ENABLE) {
		/* Stop shim performance counters */
		stop_plio_profile(dma_recv_chan->profile);
	}
#endif
}

void wait_mm2s_channel(xaxidma_send_chan_t *dma_send_chan)
{
	xaxidma_t *dma = dma_send_chan->dma;
	unsigned char *xaxidma_va = (unsigned char *)(dma->dma_va);
	uint32_t mm2s_status;

	mm2s_status = *((volatile uint32_t *)(xaxidma_va + 0x4));
	while ((mm2s_status & 0x2) == 0)
		mm2s_status = *((volatile uint32_t *)(xaxidma_va + 0x4));

	LPDEBUG("%s: DMA physical address = 0x%lx. MM2S status = 0x%x\n",
					__func__, dma->dma_pa, mm2s_status);
#if ENABLE_PROFILING
#if !CAL_GLATENCY
	if (dma_send_chan->enable_profile == ENABLE) {
		/* Stop shim performance counters */
		stop_plio_profile(dma_send_chan->profile);
	}
#endif
#endif
}

int main(void)
{
	struct timespec startAPU, endAPU, gInit, gRun, ChainBDs,
			reorderResult, transCompute;

	int devmem_fd = 0;
	int ret;
	char const *dev_file = "/dev/mem";

	uint64_t mem_mat_a_va;
	uint64_t mem_mat_b_va;
	uint64_t mem_mat_bt_va;
	uint64_t mem_mat_c_va;
	uint64_t mem_result_AIE_va;
	uint64_t mem_result_APU_va;
	uint64_t mem_mm2s_bd_chain_va[NUM_HW_ROWS];
	uint64_t mem_s2mm_bd_chain_va[NUM_HW_ROWS];

	uint64_t mem_mat_a_pa;
	uint64_t mem_mat_b_pa;
	uint64_t mem_mat_bt_pa;
	uint64_t mem_mat_c_pa;
	uint64_t mem_result_AIE_pa;
	uint64_t mem_result_APU_pa;
	uint64_t mem_mm2s_bd_chain_pa[NUM_HW_ROWS];
	uint64_t mem_s2mm_bd_chain_pa[NUM_HW_ROWS];

	int *input_a[NUM_ROWS], *input_b[NUM_ROWS], *input_bt[NUM_ROWS],
	    *resultAIE[NUM_ROWS], *resultAPU[NUM_ROWS];

	printf("Matrix size(int32): %dx%d\n", NUM_ROWS, NUM_COLS);

	/* Allocate input and output data buffers in DDR */
	auto xrtDevHandle = xrtDeviceOpen(0);
	xrtBufferHandle xrtBuf = xrtBOAlloc(xrtDevHandle, BUFFER_SIZE, 0, 0);
	if (!xrtBuf) {
		LPERROR("failed to allocate xrt buffer of size %ldMB.\n",
						(BUFFER_SIZE/1024/1024));
		return -1;
	}

	/* Get the virtual address of the allocated memory instance */
	mem_mat_a_va = (uint64_t)(uintptr_t)xrtBOMap(xrtBuf);
	mem_mat_b_va = mem_mat_a_va + NUM_ELMNTS * sizeof(int);
	mem_mat_bt_va = mem_mat_b_va + NUM_ELMNTS * sizeof(int);
	mem_mat_c_va = mem_mat_bt_va + NUM_ELMNTS * sizeof(int);
	mem_result_AIE_va = mem_mat_c_va + NUM_ELMNTS * sizeof(int);
	mem_result_APU_va = mem_result_AIE_va + NUM_ELMNTS * sizeof(int);
	mem_mm2s_bd_chain_va[0] = mem_result_APU_va + NUM_ELMNTS * sizeof(int);
	for (int i = 1; i < NUM_HW_ROWS; i++)
		mem_mm2s_bd_chain_va[i] = mem_mm2s_bd_chain_va[0] +
							i * MM2S_BD_CHAIN_SIZE;

	mem_s2mm_bd_chain_va[0] = mem_mm2s_bd_chain_va[NUM_HW_ROWS - 1] +
							MM2S_BD_CHAIN_SIZE;;
	for (int i = 1; i < NUM_HW_ROWS; i++)
		mem_s2mm_bd_chain_va[i] = mem_s2mm_bd_chain_va[0] +
							i * S2MM_BD_CHAIN_SIZE;

	/* Get the physical address of the allocated memory instance */
	mem_mat_a_pa = xrtBOAddress(xrtBuf);
	mem_mat_b_pa = mem_mat_a_pa + NUM_ELMNTS * sizeof(int);
	mem_mat_bt_pa = mem_mat_b_pa + NUM_ELMNTS * sizeof(int);
	mem_mat_c_pa = mem_mat_bt_pa + NUM_ELMNTS * sizeof(int);
	mem_result_AIE_pa = mem_mat_c_pa + NUM_ELMNTS * sizeof(int);
	mem_result_APU_pa = mem_result_AIE_pa + NUM_ELMNTS * sizeof(int);
	mem_mm2s_bd_chain_pa[0] = mem_result_APU_pa + NUM_ELMNTS * sizeof(int);
	for (int i = 1; i < NUM_HW_ROWS; i++)
		mem_mm2s_bd_chain_pa[i] = mem_mm2s_bd_chain_pa[0] +
							i * MM2S_BD_CHAIN_SIZE;

	mem_s2mm_bd_chain_pa[0] = mem_mm2s_bd_chain_pa[NUM_HW_ROWS - 1] +
							MM2S_BD_CHAIN_SIZE;
	for (int i = 1; i < NUM_HW_ROWS; i++)
		mem_s2mm_bd_chain_pa[i] = mem_s2mm_bd_chain_pa[0] +
							i * S2MM_BD_CHAIN_SIZE;

	LPRINTF("allocated matrix A at 0x%lx (phy addr: 0x%lx)\r\n",
						mem_mat_a_va, mem_mat_a_pa);
	LPRINTF("allocated matrix B at 0x%lx (phy addr: 0x%lx)\r\n",
						mem_mat_b_va, mem_mat_b_pa);
	LPRINTF("allocated matrix B transpose at 0x%lx (phy addr: 0x%lx)\r\n",
						mem_mat_bt_va, mem_mat_bt_pa);
	LPRINTF("allocated matrix C at 0x%lx (phy addr: 0x%lx)\r\n",
						mem_mat_c_va, mem_mat_c_pa);
	LPRINTF("allocated AIE result at 0x%lx (phy addr: 0x%lx)\r\n",
					mem_result_AIE_va, mem_result_AIE_pa);
	LPRINTF("allocated APU result at 0x%lx (phy addr: 0x%lx)\r\n",
					mem_result_APU_va, mem_result_APU_pa);

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		LPRINTF("allocated MM2S BD chain #%d at 0x%lx (phy addr: 0x%lx)\r\n",
				i, mem_mm2s_bd_chain_va[i], mem_mm2s_bd_chain_pa[i]);
		LPRINTF("allocated S2MM BD chain #%d at 0x%lx (phy addr: 0x%lx)\r\n",
				i, mem_s2mm_bd_chain_va[i], mem_s2mm_bd_chain_pa[i]);
	}

	/* Enable access to allocated buffer as a 2-D array */
	for (int i = 0; i < NUM_ROWS; i++) {
		input_a[i] = (int *)mem_mat_a_va + i * NUM_COLS;
		input_b[i] = (int *)mem_mat_b_va + i * NUM_COLS;
		input_bt[i] = (int *)mem_mat_bt_va + i * NUM_COLS;
		resultAIE[i] = (int *)mem_result_AIE_va + i * NUM_COLS;
		resultAPU[i] = (int *)mem_result_APU_va + i * NUM_COLS;
	}

	/* Clean output data buffer */
	memset((void *)mem_mat_c_va, 0, NUM_ELMNTS * sizeof(int));

	/* Init app input data */
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			input_a[i][j] = rand() % 10;
			input_b[i][j] = rand() % 10;
		}
	}

	/* transpose matrix B */
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			input_bt[j][i] = input_b[i][j];

	/* mmap AXI DMA */
	devmem_fd = open(dev_file, O_RDWR);
	if (devmem_fd < 1) {
		LPERROR("Failed to open %s, %s.\r\n", dev_file, strerror(errno));
		return -EINVAL;
	}

	/* mmap AXI DMA */
	ret = init_dmas(devmem_fd, mem_mm2s_bd_chain_va, mem_mm2s_bd_chain_pa,
				mem_s2mm_bd_chain_va, mem_s2mm_bd_chain_pa);
	if (ret != 0) {
		LPERROR("Failed to initialize DMAs.\n");
		close(devmem_fd);
		return -EINVAL;
	}

	/* Reset AIE */
	/* record timestamps for performance measurement */
	clock_gettime(CLOCK_MONOTONIC, &gInit);

	/* Configure AIE */
#if 0
	if (xrtDeviceLoadXclbinFile(xrtDevHandle,
					"aie-matrix-multiplication.xclbin")) {
		LPERROR("Failed to load xclbin.\n");
		return -1;
	}
#else
	my_graph.init();
#endif
	clock_gettime(CLOCK_MONOTONIC, &gRun);

	/* Enable AIE cores */
	my_graph.run(1);

	clock_gettime(CLOCK_MONOTONIC, &ChainBDs);

	/* Chain BDS and enable S2MM channel */
	for (int i = 0; i < NUM_HW_ROWS; i++) {
		int *mem_mat_c_chunk_pa;
		uint32_t offset;
		uint32_t retsize;

		/*
		 * Create a pointer next chunk of matrix C in the physical
		 * memory.
		 */
		offset = i * (NUM_ROWS_PER_HW_ROW * NUM_COLS);
		mem_mat_c_chunk_pa = (int *)mem_mat_c_pa + offset;

		retsize = chain_s2mm_bds(&xdma_recv_chans[i],
						(uint64_t)mem_mat_c_chunk_pa);
		LPDEBUG("%s: setup to receive 0x%x\n", __func__, retsize);

		enable_s2mm_channel(&xdma_recv_chans[i], 1);
	}

	/* Chain BDs and enable MM2S channel */
	for (int i = 0; i < NUM_HW_ROWS; i++) {
		int *mem_mat_a_chunk_pa;
		uint32_t offset;
		uint32_t retsize;

		/*
		 * Create a pointer next chunk of matrix A in the physical
		 * memory.
		 */
		offset = i * (NUM_ROWS_PER_HW_ROW * NUM_COLS);
		mem_mat_a_chunk_pa = (int *)mem_mat_a_pa + offset;

		retsize = chain_mm2s_bds(&xdma_send_chans[i],
				(uint64_t)mem_mat_a_chunk_pa, mem_mat_bt_pa);
		LPDEBUG("%s: setup to send 0x%x\n", __func__, retsize);

		/*
		 * Throughput profiling utilizes 2 performance counters in a
		 * single column. Skip enabling profiling for the first column,
		 * as it has already been requested by S2MM port.
		 */
#if !CAL_THROUGHPUT
		if (i >= 0)
			enable_mm2s_channel(&xdma_send_chans[i],
						&xdma_recv_chans[i], ENABLE);
#else
		if (i > 0)
			enable_mm2s_channel(&xdma_send_chans[i],
						&xdma_recv_chans[i], ENABLE);
#endif
		else
			enable_mm2s_channel(&xdma_send_chans[i],
						&xdma_recv_chans[i], DISABLE);
	}

	clock_gettime(CLOCK_MONOTONIC, &transCompute);

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		/* Poll MM2S status bit */
		wait_mm2s_channel(&xdma_send_chans[i]);

		/* Poll S2MM status bit */
		wait_s2mm_channel(&xdma_recv_chans[i]);
	}

	/* Disable AIE cores */
	my_graph.end();

	clock_gettime(CLOCK_MONOTONIC, &reorderResult);

	/* Z-ordering */
	for (int i = 0; i < NUM_COLS / (WIN_SIZE / NUM_ROWS_PER_TILE); i++)
		for (int j = 0; j < NUM_HW_ROWS; j++)
			for (int k = 0; k < NUM_HW_COLS; k++)
				for (int m = 0; m < WIN_SIZE / NUM_ROWS_PER_TILE; m++)
					for (int l = 0; l < NUM_ROWS_PER_TILE; l++)
						resultAIE[j * NUM_ROWS_PER_HW_ROW + k * NUM_ROWS_PER_TILE + l][i * (WIN_SIZE / NUM_ROWS_PER_TILE) + m]
							= ((int *)mem_mat_c_va)[j * NUM_ROWS_PER_HW_ROW * NUM_COLS + i * NUM_ROWS_PER_HW_ROW * (WIN_SIZE / NUM_ROWS_PER_TILE) + k * WIN_SIZE + m * NUM_ROWS_PER_TILE + l];

	clock_gettime(CLOCK_MONOTONIC, &startAPU);

	/* For sanity check compute the same on APU */
	for(int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			for (int k = 0; k < NUM_COLS; k++)
				resultAPU[i][j] += input_a[i][k] * input_bt[j][k];

	clock_gettime(CLOCK_MONOTONIC, &endAPU);

	int pass = 0;
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			if (resultAIE[i][j] != resultAPU[i][j]) {
				printf("AIE[%d][%d] = %d APU[%d][%d] = %d\n", i,
					j, resultAIE[i][j], i, j, resultAPU[i][j]);
				pass = -1;
				break;
			}

	if(pass == -1) {
		printf("ERROR: XGeMM Failed!\n");
		return -1;
	} else {
		printf("Success!\n");
	}

	xrtBOFree(xrtBuf);

#if ENABLE_PROFILING
	double graphInit, graphRun, ChainingBDs, transferCompute,
	       reorderingResult, timeAIE, timeAPU, speed, computeSpeed;

	graphInit = (gRun.tv_sec - gInit.tv_sec) * 1e+9 +
				gRun.tv_nsec - gInit.tv_nsec;
	graphRun = (ChainBDs.tv_sec - gRun.tv_sec) * 1e+9 +
				ChainBDs.tv_nsec - gRun.tv_nsec;
	ChainingBDs = (transCompute.tv_sec - ChainBDs.tv_sec) * 1e+9 +
				transCompute.tv_nsec - ChainBDs.tv_nsec;
	transferCompute = (reorderResult.tv_sec - transCompute.tv_sec) * 1e+9 +
				reorderResult.tv_nsec - transCompute.tv_nsec;
	reorderingResult = (startAPU.tv_sec - reorderResult.tv_sec) * 1e+9 +
				startAPU.tv_nsec - reorderResult.tv_nsec;

	timeAPU = (endAPU.tv_sec - startAPU.tv_sec) * 1e+9 +
				endAPU.tv_nsec - startAPU.tv_nsec;
	timeAIE = graphInit + graphRun + ChainingBDs + transferCompute +
				reorderingResult;

	speed = timeAPU / (timeAIE - graphInit);
	computeSpeed = timeAPU / transferCompute;

	double count_out[NUM_HW_ROWS], count_in[NUM_HW_ROWS];

	for (int i = 0; i < NUM_HW_ROWS; i++) {
		xaxidma_send_chan_t *dma_send_chan = &xdma_send_chans[i];
		xaxidma_recv_chan_t *dma_recv_chan = &xdma_recv_chans[i];

#if !CAL_GLATENCY
		if (dma_send_chan->enable_profile) {
			profile_plio_t *profile = dma_send_chan->profile;
			count_in[i] = (double)MM2S_DATA_SIZE / (profile->cycle_count * 1e-9);
		}
#endif

#if CAL_GLATENCY
		if (dma_recv_chan->enable_profile) {
			profile_plio_t *profile = dma_recv_chan->profile;
			count_out[i] = (double)profile->cycle_count * 1e-6;
		}
#else
		if (dma_recv_chan->enable_profile) {
			profile_plio_t *profile = dma_recv_chan->profile;
			count_out[i] = (double)S2MM_DATA_SIZE / (profile->cycle_count * 1e-9);
		}
#endif
	}

	printf("\n<<============================== XGEMM STATS ===============================>>\n\n");

	printf("Graph init took %.4f ms or %.4f%% of total AIE time\n",
		graphInit / 1e+6, (graphInit * 100 / timeAIE));
	printf("Graph run took %.4f ms or %.4f%% of total AIE time\n",
		graphRun / 1e+6, (graphRun * 100 / timeAIE));
	printf("Chaining BDs took %.4f ms or %.4f%% of total AIE time\n",
		ChainingBDs / 1e+6, (ChainingBDs * 100 / timeAIE));
	printf("Data transfer and compute took %.4f ms or %.4f%% of total AIE time\n",
		transferCompute / 1e+6, (transferCompute * 100 / timeAIE));
	printf("Re-ordering result on APU took %.4f ms or %.4f%% of total AIE time\n",
		reorderingResult / 1e+6, (reorderingResult * 100 / timeAIE));

	printf("\nTotal Compute time on APU = %.4f ms\n", timeAPU / 1e+6);
	printf("Total Compute time on AIE = %.4f ms\n", timeAIE / 1e+6);

	printf("\nSpeedup (excluding graph init)  = %.3fx\n", speed);
	printf("Speedup (just compute) = %.3fx\n\n", computeSpeed);

#if CAL_THROUGHPUT
	for (int i = 1; i < NUM_HW_ROWS; i++)
		printf("PL input port #%d throughput = %.4f MB/s\n", i,
						count_in[i] / (1024 * 1024));


	printf("\n");

	for (int i = 0; i < NUM_HW_ROWS; i++)
		printf("PL output port #%d throughput = %.4f MB/s\n", i,
						count_out[i] / (1024 * 1024));

#elif CAL_BANDWIDTH
	for (int i = 0; i < NUM_HW_ROWS; i++)
		printf("PL input port #%d bandwidth = %.4f MB/s\n", i,
						count_in[i] / (1024 * 1024));


	printf("\n");

	for (int i = 0; i < NUM_HW_ROWS; i++)
		printf("PL output port #%d bandwidth = %.4f MB/s\n", i,
						count_out[i] / (1024 * 1024));

#elif CAL_GLATENCY
	for (int i = 0; i < NUM_HW_ROWS; i++)
		printf("Graph latency for row #%d = %.4f ms\n", i + 1,
								count_out[i]);
#endif
	printf("\n<<==========================================================================>>\n");
#endif

	return 0;
}
