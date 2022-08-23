###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

VPP		= v++
TARGET		= hw
OS		?= linux

EXP_DIR		:= ../export

LIBADF		:= ../aie/libadf.a
CONN_SPEC	:= system.cfg

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

VPP_FLAGS 	:= -t $(TARGET) -f $(PFM_XPFM) --save-temps -g

.PHONY: all
all: create
	
create: $(TARGET).xsa
	@cp $< $(EXP_DIR)/$(OS)

$(TARGET).xsa: $(LIBADF) $(CONN_SPEC)
	$(VPP) -l $(VPP_FLAGS) $(LIBADF) --config $(CONN_SPEC) -o $@

clean:
	rm -rf _x
	rm -rf .Xil
	rm -rf .ipcache
	rm -rf *.pdi
	rm -rf *.link_summary
	rm -rf *.xsa
	rm -rf *.log
