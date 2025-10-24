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
BOARD_DTS	= versal2-vek385-reva
PROCESSOR	= cortexa78_0
LOP_DTS		= lop-a78-imux.dts

all: create sdt_lopper
else 
ifeq ($(AIEARCH), aieml)
BOARD_DTS	= versal-vek280-revb
PROCESSOR	= psv_cortexa72_0
LOP_DTS		= lop-a72-imux.dts

all: create sdt_lopper
else
ifeq ($(AIEARCH), aie)
ifeq ($(__BOARD__), vrk160)
BOARD_DTS      = versal-vrk160-reva
PROCESSOR      = psv_cortexa72_0
LOP_DTS                = lop-a72-imux.dts
else
ifeq ($(__BOARD__), vck190)
BOARD_DTS      = versal-vck190-rev1.1-x-ebm-01-reva
PROCESSOR      = psv_cortexa72_0
LOP_DTS                = lop-a72-imux.dts
endif
endif
all: create sdt_lopper
else
all: create
endif
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
	mkdir -p output
	@./sdt_lopper.sh $(TARGET).xsa $(BOARD_DTS) $(PROCESSOR) $(LOP_DTS)
	@-cp pl.dtsi pl.dtbo $(EXP_DIR)/$(OS)

clean_sdt:
	rm -rf sdt_output
	rm -rf pl.dtsi
	rm -rf pl.dtbo
	rm -rf sdtgen.tcl
	rm -rf output
	rm -rf sdt_lopper

clean: clean_sdt
	rm -rf _x
	rm -rf .Xil
	rm -rf .ipcache
	rm -rf *.pdi
	rm -rf *.link_summary
	rm -rf *.xsa
	rm -rf *.log
