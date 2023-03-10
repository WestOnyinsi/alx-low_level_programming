#!/bin/bash

# Find all .c files in the current directory
c_files=$(find . -name "*.c")

# Compile the .c files into object files
for file in $c_files
do
    gcc -c $file
done

# Create the static library from the object files
ar rcs liball.a *.o

# Remove the object files
rm *.o
