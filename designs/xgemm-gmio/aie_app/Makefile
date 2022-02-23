###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		:= aie-matrix-multiplication

CXX		:= aarch64-linux-gnu-g++
CXXFLAGS	+= -D__PS_ENABLE_AIE__ -Wall

DIR_PFM		:= ../sw/vck190_linux
SYSROOT		?= $(DIR_PFM)/images/linux/sdk/sysroots/cortexa72-cortexa53-xilinx-linux/
AIE_LINKER      := $(SYSROOT)/lib
XRT_INCLUDE     := $(SYSROOT)/usr/include/xrt
INCDIRS		:= -I$(XILINX_VITIS)/aietools/include/ -I$(XRT_INCLUDE) -I./ -I./kernels
LDDIRS		:= --sysroot=$(SYSROOT) -L$(XILINX_VITIS)/aietools/lib/aarch64.o -L$(AIE_LINKER)
LDLIBS		:= -lxaiengine -ladf_api_xrt -lxrt_core -lxrt_coreutil
LDFLAGS		:= $(LDDIRS) $(LDLIBS)
PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

all: compile

compile: libadf.a

cross-compile: $(APP)

libadf.a: xgemm.cpp
	aiecompiler -v --target=hw --platform=$(PFM_XPFM) --dataflow $<

$(APP): xgemm.cpp Work/ps/c_rts/aie_control_xrt.cpp
	$(CXX) $(CXXFLAGS) $^ $(INCDIRS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf Work
	rm -rf .Xil
	rm -rf temp
	rm -rf *.a
	rm -rf *.log
	rm -rf *.dot
	rm -rf $(APP)
