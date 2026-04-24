#!/bin/bash
# Copyright (C) 2024, Advanced Micro Devices, Inc.
# SPDX-License-Identifier: Apache-2.0

# Usage: ./build_linux.sh <board> BASE_XSA=<path_to_xsa>
# Supported boards: vck190, vek280, vek385, vrk160

# Validate arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <board> BASE_XSA=<path_to_xsa>"
    echo "Supported boards: vck190, vek280, vek385, vrk160"
    exit 1
fi

BOARD=$1
BASE_XSA_ARG=$2

# Validate board parameter
if [[ ! "$BOARD" =~ ^(vck190|vek280|vek385|vrk160)$ ]]; then
    echo "Error: Invalid board '$BOARD'"
    echo "Supported boards: vck190, vek280, vek385, vrk160"
    exit 1
fi

# Parse BASE_XSA from command line argument
if [[ $BASE_XSA_ARG =~ ^BASE_XSA=(.+)$ ]]; then
    BASE_XSA_PATH="${BASH_REMATCH[1]}"
else
    echo "Error: BASE_XSA argument must be in format BASE_XSA=<path>"
    exit 1
fi

# Validate BASE_XSA path exists
if [ ! -f "$BASE_XSA_PATH" ]; then
    echo "Error: BASE_XSA file not found: $BASE_XSA_PATH"
    exit 1
fi

# Common environment setup
export XILINXD_LICENSE_FILE=2100@aiengine-eng
source /proj/xbuilds/2026.1_daily_latest/installs/lin64/2026.1/Vitis/settings64.sh
export BASE_XSA=$BASE_XSA_PATH

# Board-specific configurations
case $BOARD in
    vck190)
        AIEARCH=aie
        SYSROOT_PATH=/proj/yocto/edf/2026.1/stable/Yocto_edf_2026.1_verified_latest/artifacts/amd-cortexa72-common_meta-edf-app-sdk/sdk/sysroots/cortexa72-cortexa53-amd-linux/
        ;;
    vek280)
        AIEARCH=aieml
        SYSROOT_PATH=/proj/yocto/edf/2026.1/stable/Yocto_edf_2026.1_verified_latest/artifacts/amd-cortexa72-common_meta-edf-app-sdk/sdk/sysroots/cortexa72-cortexa53-amd-linux/
        ;;
    vrk160)
        AIEARCH=aie
        SYSROOT_PATH=/proj/yocto/edf/2026.1/stable/Yocto_edf_2026.1_verified_latest/artifacts/amd-cortexa72-common_meta-edf-app-sdk/sdk/sysroots/cortexa72-cortexa53-amd-linux/
        ;;
    vek385)
        AIEARCH=aie2ps
        SYSROOT_PATH=/proj/yocto/edf/2026.1/stable/Yocto_edf_2026.1_verified_latest/artifacts/amd-cortexa78-mali-common_meta-edf-app-sdk/sdk/sysroots/cortexa72-cortexa53-amd-linux/
        ;;
esac

# Set SYSROOT
unset SYSROOT
export SYSROOT=$SYSROOT_PATH

# Source settings
source settings.sh

# Build the application
cd designs/xgemm-gmio/
make clean
make BOARD=$BOARD AIEARCH=$AIEARCH OS=linux

echo "[INFO] Build completed for board: $BOARD"
