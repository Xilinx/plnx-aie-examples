###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		:= aie-matrix-multiplication

TARGET		:= hw

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

all: libadf.a

libadf.a: kernels/*
	v++ -c --mode aie --platform=$(PFM_XPFM) --aie.workdir=Work xgemm.cpp

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
