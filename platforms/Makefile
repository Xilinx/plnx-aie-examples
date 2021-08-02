###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

all: create

$(BASE_PLATFORM):
	cp -r $(BASE_XSA) base.xsa
	xsct platform_create.tcl

create: $(BASE_PLATFORM)

.PHONY: clean
clean:
	rm -rf *.xsa
	rm -rf base_vck190
	rm -rf .Xil
