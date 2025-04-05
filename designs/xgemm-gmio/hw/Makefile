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
ifeq ($(AIEARCH), aie2ps)
BOARD_DTS	= versal2-vek385-revA
all: create sdt_lopper
else 
ifeq ($(AIEARCH), aieml)
BOARD_DTS	= versal-vek280-revb
all: create sdt_lopper
else
all: create
endif
endif
	
create: $(TARGET).xsa
	@cp $< $(EXP_DIR)/$(OS)

$(TARGET).xsa: $(LIBADF) $(CONN_SPEC)
	$(VPP) -l $(VPP_FLAGS) $(LIBADF) --config $(CONN_SPEC) -o $@

sdt_lopper: pl.dtbo

pl.dtbo:
	@echo "Generating system.dtb and pl.dtbo"
	chmod +x sdt_lopper.sh
	@./sdt_lopper.sh $(TARGET).xsa $(BOARD_DTS)
	@-cp pl.dtsi pl.dtbo $(EXP_DIR)/$(OS)

clean_sdt:
	rm -rf SDT_OUTPUT
	rm -rf pl.dtsi
	rm -rf pl.dtbo
	rm -rf sdtgen.tcl

clean: clean_sdt
	rm -rf _x
	rm -rf .Xil
	rm -rf .ipcache
	rm -rf *.pdi
	rm -rf *.link_summary
	rm -rf *.xsa
	rm -rf *.log
