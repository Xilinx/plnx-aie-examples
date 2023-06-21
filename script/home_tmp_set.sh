#!/bin/bash

directory="/scratch/staff/$USER"
if [ ! -d "$directory" ]; then
    # Directory does not exist, create it
    mkdir -p "$directory"
		if [ $? -ne 0 ]; then
				echo "$directory creation failed!"
		else
				echo "Created directory: $directory"
		fi
fi

check_directory() {
    if [ -d "$1" ]; then
        echo "$1 exist"
				directory=$1	
    else
        echo "Directory $1 not exist"
        read -p "Please input another big space directory for HOME&TMP:" new_directory
        check_directory "$new_directory"
    fi
}

check_directory "$directory"

# Update TMP, TEMP, and HOME environment variables
export TMP="$directory"
export TEMP="$directory"
export HOME="$directory"

echo "TMP: $TMP"
echo "TEMP: $TEMP"
echo "HOME: $HOME"
