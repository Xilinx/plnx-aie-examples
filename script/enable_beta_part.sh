# Copyright (C) 2024, Advanced Micro Devices, Inc.
# SPDX-License-Identifier: Apache-2.0

#!/bin/bash

xilfolder="$HOME/.Xilinx/Vivado/"
filename="$xilfolder/Vivado_init.tcl"
echo $filename
searchPattern="enable_beta_device *"

# Check if the file exists
if [ ! -f "$filename" ]; then
		mkdir -p $xilfolder
    # File does not exist, create it and add the pattern
    touch "$filename"
    echo "Created file: $filename"
fi

# Check if the pattern is already present
if ! grep -q "$searchPattern" "$filename"; then
    # Append the pattern to the file
    echo "$searchPattern" >> "$filename"
    echo "Added \"$searchPattern\" to the file."
else
    echo "The file already contains \"$searchPattern\"."
fi
