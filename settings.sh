###############################################################################
# Copyright (C) 2019 - 2020 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

#!/bin/bash

export VITIS_DIR=""
export AIETOOLS_ROOT=$VITIS_DIR/aietools
export XILINXD_LICENSE_FILE=""
export SYSROOT=""
export PFM_XPFM=""

if [[ -z "$VITIS_DIR" ]]; then
	echo "ERROR: Vitis directory path must be set"
	return
fi

if [[ -z "$XILINXD_LICENSE_FILE" ]]; then
	echo "ERROR: Xilinx license must be set"
	return
fi

if [[ -z "$SYSROOT" ]]; then
	echo "ERROR: SYSROOT path must be set"
	return
fi

if [[ -z "$PFM_XPFM" ]]; then
	echo "ERROR: Xilinx Platform definition file (*xpfm) path must be set"
	return
fi

# Update path with AIETOOLS_ROOT
export PATH=$AIETOOLS_ROOT/bin:$VITIS_DIR/bin:$PATH

# Source VITIS, and AIETOOLS
source $AIETOOLS_ROOT/scripts/aietools_env.sh
source $VITIS_DIR/settings64.sh
