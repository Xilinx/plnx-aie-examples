###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

TARGET		?= hw
OS		?= linux

PTLNX_DIR	:= linux

LIB_DIR		:= baremetal/base/psv_cortexa72_0/standalone_domain/bsp/psv_cortexa72_0/lib
PLT_FLAGS	:= -domain ai_engine:aie_runtime -domain psv_cortexa72_0:standalone -out-dir $(OS)

ifeq ($(OS), linux)
all: copy_xsa create build gen_sdk package
else
all: copy_xsa gen_bsp
endif

copy_xsa: $(TARGET).xsa

$(TARGET).xsa: ../$(TARGET)/$(TARGET).xsa
	@cp -fv ../$(TARGET)/$(TARGET).xsa .

create: $(PTLNX_DIR)/pre-built/linux/images/BOOT.BIN

$(PTLNX_DIR)/pre-built/linux/images/BOOT.BIN:
	petalinux-create -t project -s $(PTLNX_BSP) -n $(PTLNX_DIR)
	petalinux-config -p $(PTLNX_DIR) --get-hw-description=$(TARGET).xsa --silentconfig

build:
	petalinux-build -p $(PTLNX_DIR)

gen_sdk: linux/images/linux/sdk.sh

linux/images/linux/sdk.sh:
	petalinux-build -p $(PTLNX_DIR) --sdk
	cd $(PTLNX_DIR) && petalinux-package --sysroot

package: linux/images/linux/BOOT.BIN

linux/images/linux/BOOT.BIN:
	cd $(PTLNX_DIR) && petalinux-package --force --boot --u-boot --dtb

gen_bsp: $(LIB_DIR)/libxil.a
	
$(LIB_DIR)/libxil.a: $(TARGET).xsa
	generate-platform.sh $(PLT_FLAGS) -name base -hw $<

.PHONY: clean
clean:
	rm -rf *.xsa
	rm -rf *.pdi
	rm -rf $(OS)
	rm -rf .Xil
