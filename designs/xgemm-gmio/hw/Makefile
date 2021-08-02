###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

VPP			= v++
TARGET			= hw

LIBADF			:= ../aie_app/libadf.a
CONNECTIVITY_SPEC	:= system.cfg

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

VPP_FLAGS := -t $(TARGET) -f $(PFM_XPFM) --save-temps -g --vivado.param project.writeIntermediateCheckpoints=1 --advanced.param compiler.addOutputTypes="hw_export"

.PHONY: all
all: $(TARGET).xclbin

$(TARGET).xclbin: $(LIBADF) $(CONNECTIVITY_SPEC)
	$(VPP) -l $(VPP_FLAGS) $(LIBADF) --config $(CONNECTIVITY_SPEC) -o $@

clean:
	rm -rf _x
	rm -rf .Xil
	rm -rf .ipcache
	rm -rf *.ltx
	rm -rf *.xclbin
	rm -rf *_summary
	rm -rf *.xsa
	rm -rf *.log
	rm -rf *.jou
	rm -rf *.info
