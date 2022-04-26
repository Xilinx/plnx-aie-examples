###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		= aie-matrix-multiplication
VPP		= v++
TARGET		= hw

APP_DIR		= ../../aie_app
AIE_XCLBIN	= $(APP_DIR)/$(APP).xclbin

XRT_CFG		= xrt.ini

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

.PHONY: all clean
all: clean package

package: $(APP).xclbin
	
$(APP).xclbin: $(APP_DIR)/libadf.a $(XRT_CFG)
	$(VPP) -s -p -t $(TARGET) -f $(PFM_XPFM) --package.out_dir ./	\
	       --package.defer_aie_run --config $(XRT_CFG) -o $@ $<
zip:
	rm -rf package
	rm -rf package.zip
	mkdir package
	cp -r $(APP_DIR)/$(APP) ./package
	cp -r $(APP).xclbin ./package
	zip -r package.zip package

clean:
	rm -rf _x
	rm -rf package
	rm -rf .Xil
	rm -rf *.BIN
	rm -rf *.bif
	rm -rf *.bin
	rm -rf *.log
	rm -rf *.package_summary
	rm -rf *.xclbin
	rm -rf *.zip
