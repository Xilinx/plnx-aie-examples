###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		:= aie-matrix-multiplication

AIEARCH		?= aie
TARGET		:= hw

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

all: libadf.a

libadf.a: kernels/*
	aiecompiler -v --target=$(TARGET) --platform=$(PFM_XPFM) --aiearch=$(AIEARCH) --dataflow xgemm.cpp

.PHONY: clean
clean:
	rm -rf Work
	rm -rf .Xil
	rm -rf *.a
	rm -rf *.o
	rm -rf *.log
	rm -rf *.csv
	rm -rf *.jou
	rm -rf *.db
