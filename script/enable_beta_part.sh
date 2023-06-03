#!/bin/bash
filename="$HOME/.Xilinx/Vivado/Vivado_init.tcl"
searchPattern="enable_beta_device *"

# Check if the file exists
if [ ! -f "$filename" ]; then
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
