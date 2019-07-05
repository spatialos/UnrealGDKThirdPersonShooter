#!/bin/bash

if [ "$#" -ne "2" ]; then
  echo "Incorrect number of args. Make sure to include the input file and destination directory."
  echo "usage: $(basename "$0") <input_file> <destination_directory>"
  exit 1
fi

INPUT_FILE=$1
DEST_DIR=$2

# Copies a file and removes <CR> characters (ensures UNIX line endings).
cp_unix_ending() {
  src="$1"
  dest="$2"
  sed 's/$//' $src >$dest
}

cp_unix_ending $INPUT_FILE $DEST_DIR/run_test_linux.sh