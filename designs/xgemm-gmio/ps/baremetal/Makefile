###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		= aie-matrix-multiplication

AIEARCH		?= aie
TARGET		?= hw

ifeq ($(AIEARCH), aie)
AIEGEN		= 10
else
AIEGEN		= 20
endif

VPP		= v++
CC		:= aarch64-none-elf-gcc
CC_FLAGS	:= -g -c -DPS_ENABLE_AIE -D__PS_BARE_METAL__ -D__AIEBAREMETAL__ -D__AIEARCH__=$(AIEGEN) -std=c++17

HW_DIR		= ../../hw
AIE_DIR		= ../../aie
EXP_DIR		:= ../../export

VPP_FLAGS	:= --package.out_dir ./ --package.domain aiengine		\
		   --package.defer_aie_run --package.boot_mode sd		\
		   --package.image_format=fat32 --package.ps_elf $(APP),a72-0
VPP_INPUT	:= $(AIE_DIR)/libadf.a $(HW_DIR)/$(TARGET).xsa

BSP_DIR		:= ../../sw/baremetal/base/export/base/sw/base/standalone_domain
BSP_LIBS	:= $(BSP_DIR)/bsplib/lib
BSP_INCS	:= $(BSP_DIR)/bspinclude/include
INCS		:= -I$(AIE_DIR) -I$(BSP_INCS) -I${XILINX_VITIS}/aietools/include -I${XILINX_VITIS}/include
LD_DIRS		:= -L$(BSP_LIBS) -L${XILINX_VITIS}/aietools/lib/aarchnone64.o
LD_LIBS		:= -ladf_api -Wl,--start-group,-lxil,-lgcc,-lc,-lstdc++,--end-group
LD_FLAGS	:= $(LD_DIRS) $(LD_LIBS) -g -mcpu=cortex-a72 -Wl,-T -Wl,./lscript.ld

PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

.PHONY: all clean
all: clean package

package: $(APP).xclbin
	@cp $< $(EXP_DIR)/baremetal

$(APP).xclbin: $(AIE_DIR)/libadf.a $(HW_DIR)/$(TARGET).xsa $(APP)
	$(VPP) -p -t $(TARGET) -f $(PFM_XPFM) $(VPP_INPUT) $(VPP_FLAGS) -o $(APP).xclbin
	@cp sd_card.img $(EXP_DIR)/baremetal
	@cp BOOT.BIN $(EXP_DIR)/baremetal

cross-compile: $(APP)
	mkdir -p $(EXP_DIR)/baremetal
	@cp $< $(EXP_DIR)/baremetal

$(APP): $(AIE_DIR)/xgemm.o $(AIE_DIR)/Work/ps/c_rts/aie_control.o
	$(CC) $^ $(LD_FLAGS) -o $@

%.o: %.cpp
	$(CC) $(INCS) $(CC_FLAGS) -o $@ $<

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
	rm -rf $(APP)
	rm -rf *.o
	rm -rf sd_card
	rm -rf *.img
