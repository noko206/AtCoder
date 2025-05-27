#!/bin/bash

# Check if a number is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $1 <number>"
    exit 1
fi

# Extract the number from the argument
NUMBER=$1

# Validate that NUMBER is a positive integer
if ! [[ "$NUMBER" =~ ^[1-9][0-9]*$ ]]; then
    echo "Error: The input must be a positive integer."
    exit 1
fi

# Define the target directory
RANGE_START=$(( (NUMBER - 1) / 50 * 50 + 1 ))
RANGE_END=$(( RANGE_START + 49 ))
TARGET_DIR="./morning/$NUMBER"

# Check if the target directory already exists
if [ -d "$TARGET_DIR" ]; then
    echo "Target directory $TARGET_DIR already exists. No further action will be taken."
    exit 0
fi

# Create the target directory
mkdir -p "$TARGET_DIR"

# Define the template file path
TEMPLATE_FILE="./cpp-library/template.cpp"

# Check if the template file exists
if [ ! -f "$TEMPLATE_FILE" ]; then
    echo "Template file $TEMPLATE_FILE not found."
    exit 1
fi

# Create the files a.cpp to g.cpp in the target directory
for FILE in {1..6}.cpp; do
    cp "$TEMPLATE_FILE" "$TARGET_DIR/$FILE"
done

echo "Files created successfully in $TARGET_DIR"
