###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		= aie-matrix-multiplication


AIEARCH		?= aie
TARGET		?= hw

ifeq ($(AIEARCH), aie)
AIEGEN		= 10
else ifeq ($(AIEARCH), aieml)
AIEGEN		= 20
else ifeq ($(AIEARCH), aie2ps)
AIEGEN	        = 22
else
$(if $(AIEARCH),$(error AIEARCH has invalid value: $(AIEARCH). Valid options are: aie, aieml, aie2ps),$(error AIEARCH is not set. Valid options are: aie, aieml, aie2ps))
endif

VPP		= v++
CXX		:= aarch64-linux-gnu-g++
CXX_FLAGS	+= -D__PS_ENABLE_AIE__ -D__AIE_ARCH__=$(AIEGEN) -D__BOARD__=$(__BOARD__) -Wall

AIE_DIR		:= ../../aie
SW_DIR		:= ../../sw
EXP_DIR		:= ../../export
PTLNX_DIR	:= $(SW_DIR)/linux
OOB_DIR		:= $(PTLNX_DIR)/project-spec/meta-user/recipes-apps/aie-oob/files

SYSROOT		?= $(PTLNX_DIR)/images/linux/sdk/sysroots/cortexa72-cortexa53-amd-linux/
AIE_LINKER      := $(SYSROOT)/lib
XRT_INC		:= $(SYSROOT)/usr/include/xrt
INCS		:= -I$(XILINX_VITIS)/aietools/include/ -I$(XRT_INC) -I./ -I./kernels
LD_DIRS		:= --sysroot=$(SYSROOT) -L$(XILINX_VITIS)/aietools/lib/aarch64.o -L$(AIE_LINKER)
LD_LIBS		:= -lgcc -lc -lxrt_coreutil -lpthread -lrt -ldl -lcrypt -lstdc++
LD_FLAGS	:= $(LD_DIRS) $(LD_LIBS)

PKG_CFG		= package_link.ini
PKG_OPTS	= --package.out_dir ./ --package.defer_aie_run --config $(PKG_CFG)
PFM_XPFM	:= $(shell test -d $(BASE_PLATFORM) && find $(BASE_PLATFORM) -name *.xpfm)

xclbin: $(APP).xclbin
	@cp $< $(EXP_DIR)/linux
	@-cp -fv $(APP).pdi $(EXP_DIR)/linux/vpl_gen_fixed_pld.pdi
	@-cp -fv $(APP).pdi $(EXP_DIR)/linux/vpl_gen_fixed.pdi

copy-xclbin:
	@cp -fv $(APP).xclbin $(OOB_DIR)

$(APP).xclbin: $(AIE_DIR)/libadf.a $(PKG_CFG)
	$(VPP) -s -p -t $(TARGET) -f $(EXP_DIR)/linux/hw.xsa $(PKG_OPTS) -o $@ $<

cross-compile: $(APP)
	@cp $< $(EXP_DIR)/linux

copy-exe:
	@cp -fv $(APP) $(OOB_DIR)

$(APP): $(AIE_DIR)/host.cpp
	$(CXX) $(CXX_FLAGS) $^ $(INCS) $(LD_FLAGS) -o $@

export:
	mkdir -p $(EXP_DIR)/linux
	@cp -fv $(PTLNX_DIR)/images/linux/BOOT.BIN $(EXP_DIR)/linux
	@cp -fv $(PTLNX_DIR)/images/linux/Image $(EXP_DIR)/linux
	@cp -fv $(PTLNX_DIR)/images/linux/rootfs.cpio.gz.u-boot $(EXP_DIR)/linux
	@cp -fv $(PTLNX_DIR)/images/linux/*.dtb $(EXP_DIR)/linux
	@cp -fv $(APP).pdi $(EXP_DIR)/linux/vpl_gen_fixed_pld.pdi
	@cp -fv $(APP).pdi $(EXP_DIR)/linux/vpl_gen_fixed.pdi

$(SW_DIR)/linux/images/linux/rootfs.cpio.gz.u-boot: $(APP) $(APP).xclbin
	$(MAKE) build -C $(SW_DIR)

rebuild: $(SW_DIR)/linux/images/linux/rootfs.cpio.gz.u-boot

package: rebuild export

.PHONY: clean
clean:
	rm -rf _x
	rm -rf .Xil
	rm -rf *.BIN
	rm -rf *.bif
	rm -rf *.bin
	rm -rf *.log
	rm -rf *.package_summary
	rm -rf *.xclbin
	rm -rf *.zip
	rm -rf $(APP)
