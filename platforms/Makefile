###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

PLATFORM_NAME    = base
PLATFORM_DIR 	 = $(PFMS_DIR)/.
all: create

create: $(BASE_PLATFORM)/export/base/base.xpfm

$(BASE_PLATFORM)/export/base/base.xpfm: $(BASE_XSA)
	cp -r $(BASE_XSA) base.xsa
	@echo "INFO: Creating Platform $(PLATFORM_NAME)"
	vitis -s generate_platform.py --platform_name $(PLATFORM_NAME) --xsa_path $(BASE_XSA) --platform_out $(PLATFORM_DIR)
.PHONY: clean
clean:
	rm -rf *.xsa
	rm -rf base
	rm -rf .Xil
	rm -rf _ide
	rm -rf .rigel_lopper
	rm -rf .gitignore
