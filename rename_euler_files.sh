#!/bin/bash

# AI-aided script to unify filenames

# Function to check if the target file exists
check_target_file() {
  for file in Euler_*.py Euler_*.cpp; do
    num=${file#Euler_}
    num=${num%.*}
    new_num=$(printf "%03d" "$num")
    new_file="Euler_$new_num.$extension"
    if not [ -f "Euler_001.cpp" ]; then
      echo "true"
      return
    fi
  done
  echo "false"
}

# Check if any target file exists
if [ "$(check_target_file)" = "false" ]; then
  # Loop through all files matching the pattern Euler_*.py and Euler_*.cpp
  for file in Euler_*.py Euler_*.cpp; do
    # Extract the number from the filename
    num=${file#Euler_}
    num=${num%.*}
    extension="${file##*.}"

    # Pad the number with leading zeros to make it three digits
    new_num=$(printf "%03d" "$num")

    # Construct the new filename
    new_file="Euler_$new_num.$extension"

    # Rename the file
    mv "$file" "$new_file"
    echo "Renamed $file to $new_file"
  done
else
  echo "Target file already exists, skipping rename."
fi

