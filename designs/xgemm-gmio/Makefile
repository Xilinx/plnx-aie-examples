###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

APP		:= aie-matrix-multiplication

AIEARCH		?= aie
TARGET		?= hw
OS		?= linux

ifeq ($(OS), baremetal)
all: platform compile hw sw cross-compile package print
else ifeq ($(SYSROOT),)
all: platform compile hw sw cross-compile xclbin copy-app-bins package print
else
all: platform compile hw cross-compile xclbin print
endif

.PHONY: platform compile hw sw cross-compile xclbin package print

platform:
	$(MAKE) all -C $(PFMS_DIR)

compile:
	$(MAKE) all -C aie AIEARCH=$(AIEARCH)

hw:
	mkdir -p export/$(OS)
	$(MAKE) all -C hw OS=$(OS)

sw:
	$(MAKE) all -C sw OS=$(OS)

xclbin:
	$(MAKE) xclbin -C ps/$(OS)

cross-compile:
	$(MAKE) cross-compile -C ps/$(OS) AIEARCH=$(AIEARCH)

copy-app-bins:
	$(MAKE) copy-exe -C ps/$(OS)
	$(MAKE) copy-xclbin -C ps/$(OS)

package:
	$(MAKE) package -C ps/$(OS)

print:
	@echo "[INFO] Build artifacts are created in $(PWD)/export/$(OS) directory"

clean:
	$(MAKE) clean -C $(PFMS_DIR)
	$(MAKE) clean -C aie
	$(MAKE) clean -C hw
	$(MAKE) clean -C sw OS=$(OS)
	$(MAKE) clean -C ps/$(OS)
	rm -rf export
