###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		:= aie-matrix-multiplication

PFM_XPFM	:= $(shell test -d $(PTLNX_BSP_DIR) && find $(PTLNX_BSP_DIR) -name *.xpfm)

all: platform compile aie_xclbin hw sw cross-compile package

platform:
	$(MAKE) all -C $(PFMS_DIR)

aie_app/libadf.a: $(PFM_XPFM)
	$(MAKE) all -C aie_app

compile: aie_app/libadf.a

ps_app_hw/linux/$(APP).xclbin: compile $(PFM_XPFM)
	$(MAKE) package -C ps_app_hw/linux

aie_xclbin: ps_app_hw/linux/$(APP).xclbin

hw/hw.xsa: aie_app/libadf.a
	$(MAKE) all -C hw

hw: hw/hw.xsa

sw/$(PTLNX_DIR)/images/linux/image.ub: hw
	$(MAKE) all -C sw PTLNX_DIR=$(PTLNX_DIR)

sw: sw/$(PTLNX_DIR)/images/linux/image.ub

aie_app/$(APP): aie_app/xgemm.cpp aie_app/Work/ps/c_rts/aie_control_xrt.cpp
	$(MAKE) cross-compile -C aie_app

cross-compile: aie_app/$(APP)

package: cross-compile aie_xclbin sw
	@cp -fv aie_app/$(APP) sw/$(PTLNX_DIR)/project-spec/meta-user/recipes-apps/aie-oob/files
	@cp -fv ps_app_hw/linux/$(APP).xclbin sw/$(PTLNX_DIR)/project-spec/meta-user/recipes-apps/aie-oob/files
	$(MAKE) build -C sw PTLNX_DIR=$(PTLNX_DIR)
	@echo "[INFO] Build artifacts are created in $(PWD)/sw/$(PTLNX_DIR)/images/linux directory"

.PHONY: export
export:
	$(MAKE) zip -C ps_app_hw/linux
	mkdir -p export
	@cp -fv ps_app_hw/linux/package.zip export/
	@cp -fv sw/$(PTLNX_DIR)/images/linux/BOOT.BIN export/
	@cp -fv sw/$(PTLNX_DIR)/images/linux/Image export/
	@cp -fv sw/$(PTLNX_DIR)/images/linux/rootfs.cpio.gz.u-boot export/
	@cp -fv sw/$(PTLNX_DIR)/images/linux/system.dtb export/

clean:
	$(MAKE) clean -C $(PFMS_DIR)
	$(MAKE) clean -C aie_app
	$(MAKE) clean -C hw
	$(MAKE) clean -C sw PTLNX_DIR=$(PTLNX_DIR)
	$(MAKE) clean -C ps_app_hw/linux
	rm -rf export
