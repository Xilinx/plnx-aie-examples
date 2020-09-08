#------------------------------------------------------------------------------
# Copyright (C) 2019 - 2020 Xilinx, Inc.  All rights reserved.
# SPDX-License-Identifier: MIT
#------------------------------------------------------------------------------

#!/bin/bash

DIR=$1

if [ -z "${DIR}" ]; then
	DIR=./Work
fi

files=$(find ${DIR} -type f)
rfiles=$(echo "${files}" | grep -v -E ".*_[0-9]$")
rfiles=$(echo "${rfiles}" | grep -v "aie_control.cpp")
rfiles=$(echo "${rfiles}" | grep -v -E "bin$")
echo "${rfiles}"
echo "${rfiles}" | xargs -I{} rm -r {}

find ${DIR} -type d -empty -delete
