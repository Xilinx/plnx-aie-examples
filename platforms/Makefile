###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

all: create

create: $(BASE_PLATFORM)/export/base/base.xpfm

$(BASE_PLATFORM)/export/base/base.xpfm: $(BASE_XSA)
	cp -r $(BASE_XSA) base.xsa
	xsct platform_create.tcl


.PHONY: clean
clean:
	rm -rf *.xsa
	rm -rf base
	rm -rf .Xil
