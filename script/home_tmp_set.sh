#!/bin/bash

directory="/scratch/staff/$USER"
if [ ! -d "$directory" ]; then
    # Directory does not exist, create it
    mkdir -p "$directory"
    echo "Created directory: $directory"
fi

# Update TMP, TEMP, and HOME environment variables
export TMP="$directory"
export TEMP="$directory"
export HOME="$directory"

echo "TMP: $TMP"
echo "TEMP: $TEMP"
echo "HOME: $HOME"
