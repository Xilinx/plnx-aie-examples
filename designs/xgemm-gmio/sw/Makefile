###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

TARGET	= hw

all: copy_xsa create config build generate_sdk package

copy_xsa: ../$(TARGET)/$(TARGET).xsa
	@cp -fv ../$(TARGET)/$(TARGET).xsa ./

create:
	test -d $(PTLNX_DIR) || petalinux-create -t project -s $(PTLNX_BSP) -n $(PTLNX_DIR)
	@echo "CONFIG_YOCTO_BUILDTOOLS_EXTENDED=y" >>  $(PTLNX_DIR)/project-spec/configs/config
	@sed -i -E 's/.*CONFIG_SUBSYSTEM_INITRAMFS_IMAGE_NAME.+/CONFIG_SUBSYSTEM_INITRAMFS_IMAGE_NAME="petalinux-image-minimal"/' $(PTLNX_DIR)/project-spec/configs/config

update_yocto_config:
# Edit the config
# CONFIG_YOCTO_ENABLE_DEBUG_TWEAKS=y
	@sed -i -E 's/.*CONFIG_auto-login.+/CONFIG_auto-login=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config

update_rootfs_config:
# Edit the vck190_linux/project-spec/configs/rootfs_config
# CONFIG_libmetal=y
# CONFIG_libsysfs=y
# CONFIG_open-amp=y
# CONFIG_ai-engine-driver=y
	@sed -i -E 's/.*CONFIG_libmetal.+/CONFIG_libmetal=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config
	@sed -i -E 's/.*CONFIG_libsysfs.+/CONFIG_libsysfs=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config
	@sed -i -E 's/.*CONFIG_open-amp.+/CONFIG_open-amp=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config
	@sed -i -E 's/.*CONFIG_ai-engine-driver.+/CONFIG_ai-engine-driver=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config
	@sed -i -E 's/.*CONFIG_xrt.+/CONFIG_xrt=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config
	@sed -i -E 's/.*CONFIG_zocl.+/CONFIG_zocl=y/' $(PTLNX_DIR)/project-spec/configs/rootfs_config

update_kernel_config:
# Add vck190_linux/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg
# CONFIG_I2C_XILINX=y
# CONFIG_GPIO_XILINX=y
# CONFIG_FPGA=y
# CONFIG_FPGA_MGR_VERSAL_FPGA=y
# CONFIG_XILINX_INTC=y
	@echo "CONFIG_I2C_XILINX=y" >> $(PTLNX_DIR)/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg
	@echo "CONFIG_GPIO_XILINX=y" >> $(PTLNX_DIR)/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg
	@echo "CONFIG_XILINX_INTC=y" >> $(PTLNX_DIR)/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg
	@echo "CONFIG_FPGA=y" >> $(PTLNX_DIR)/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg
	@echo "CONFIG_FPGA_MGR_VERSAL_FPGA=y" >> $(PTLNX_DIR)/project-spec/meta-user/recipes-kernel/linux/linux-xlnx/bsp.cfg

config: $(TARGET).xsa
	petalinux-config -p $(PTLNX_DIR) --get-hw-description=$(TARGET).xsa --silentconfig
	$(MAKE) -f $(lastword $(MAKEFILE_LIST)) update_rootfs_config
	$(MAKE) -f $(lastword $(MAKEFILE_LIST)) update_yocto_config
	$(MAKE) -f $(lastword $(MAKEFILE_LIST)) update_kernel_config
	petalinux-config -p $(PTLNX_DIR) --silentconfig

build:
	petalinux-build -p $(PTLNX_DIR)

generate_sdk:
	petalinux-build -p $(PTLNX_DIR) --sdk

package_sysroot:
	cd $(PTLNX_DIR) && petalinux-package --sysroot

package: package_sysroot
	cd $(PTLNX_DIR) && petalinux-package --force --boot --u-boot --dtb pre-built/linux/images/system-default.dtb

.PHONY: clean
clean:
	rm -rf $(PTLNX_DIR)
	rm -rf *.xsa
