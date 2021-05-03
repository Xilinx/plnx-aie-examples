###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

all: create

$(PTLNX_BSP_DIR):
	petalinux-create --force -t project -s $(PTLNX_BSP) -n $(PTLNX_DIR)

create: $(PTLNX_BSP_DIR)

.PHONY: clean
clean:
	rm -rf $(PTLNX_BSP_DIR)
