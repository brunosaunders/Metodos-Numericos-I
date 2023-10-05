#!/bin/bash

# Define the build directory
build_dir="build"

# Check if the build directory exists
if [ ! -d "$build_dir" ]; then
    echo "Creating the $build_dir directory..."
    mkdir "$build_dir"
fi

# Navigate to the build directory
cd "$build_dir"

# Run CMake to generate build files
cmake ..

# Build the project using make
make

# Run the executable
./metodos

cd ..