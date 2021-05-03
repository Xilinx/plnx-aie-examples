#!/bin/bash

###############################################################################
# Copyright (C) 2019 - 2021 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

if [[ -z "$XILINX_VITIS" ]]; then
	echo "[ERROR]: Vitis needs to be setup"
	return
fi

if [[ -z "$PETALINUX" ]]; then
	echo "[ERROR]: Versal ACAP PetaLinux needs to be setup"
	return
fi

if [[ -z "$PTLNX_BSP" ]]; then
	echo "[ERROR]: Versal ACAP Petalinux BSP path must be set"
	return
fi

export PTLNX_DIR=vck190_linux
export PFMS_DIR=${PWD}/platforms
export PTLNX_BSP_DIR=${PFMS_DIR}/${PTLNX_DIR}
