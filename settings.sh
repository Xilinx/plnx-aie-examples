#!/bin/bash

###############################################################################
# Copyright (C) 2019 - 2022 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
###############################################################################

if [[ -z "$XILINX_VITIS" ]]; then
	echo "[ERROR]: Vitis needs to be setup"
	return
fi

if [[ -n "$PTLNX_BSP" &&  -z "$PETALINUX" ]]; then
	echo "[ERROR]: Versal ACAP PetaLinux needs to be setup"
	return
fi

if [ -z "$PTLNX_BSP" ]  && [ -z "$SYSROOT" ]; then
	echo "[ERROR]: Versal ACAP Petalinux BSP path must be set"
	return
fi

if [[ -z "$BASE_XSA" ]]; then
	echo "[ERROR]: Path to the base XSA must to be set"
	return
fi

export PFMS_DIR=${PWD}/platforms
export BASE_PLATFORM=${PFMS_DIR}/base
