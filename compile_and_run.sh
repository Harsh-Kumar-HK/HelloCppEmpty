#!/bin/bash

# C++ Learning Project - Compile and Run Script
# This script compiles and runs all exercises in sequence

echo "==================================="
echo "C++ Learning Project - All Exercises"
echo "==================================="

# Function to compile and run a C++ file
compile_and_run() {
    local file=$1
    local name=$(basename "$file" .cpp)
    
    echo ""
    echo "--- Running: $name ---"
    echo "File: $file"
    echo ""
    
    # Compile
    if g++ -std=c++11 -o "$name" "$file"; then
        # Run if compilation successful
        ./"$name"
        # Clean up executable
        rm -f "$name"
    else
        echo "Compilation failed for $file"
    fi
    
    echo ""
    echo "Press Enter to continue to next exercise..."
    read
}

# Check if exercises directory exists
if [ ! -d "exercises" ]; then
    echo "Error: exercises directory not found!"
    echo "Make sure you're running this script from the project root directory."
    exit 1
fi

# Run all exercises in order
for exercise in exercises/*.cpp; do
    if [ -f "$exercise" ]; then
        compile_and_run "$exercise"
    fi
done

echo "All exercises completed!"
echo ""
echo "To run individual exercises:"
echo "g++ -std=c++11 -o exercise_name exercises/filename.cpp && ./exercise_name"
echo ""
echo "To run the interactive menu:"
echo "g++ -std=c++11 -o menu main_menu.cpp && ./menu"
