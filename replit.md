# Overview

This is a C++ learning project designed to teach fundamental programming concepts through progressive syntax exercises. The project provides a structured approach to learning C++, starting from basic "Hello World" programs and advancing through variables, input/output, operators, and eventually object-oriented programming concepts. It includes multiple ways to run exercises: individual compilation, batch execution via shell script, and an interactive menu system.

# User Preferences

Preferred communication style: Simple, everyday language.

# System Architecture

## Project Structure
The project follows a simple educational architecture with exercises organized in a linear progression:

- **Exercise Files**: Individual C++ source files (`exercises/01_hello_world.cpp`, `02_variables_datatypes.cpp`, etc.) containing focused lessons on specific concepts
- **Compilation Script**: Shell script (`compile_and_run.sh`) for batch compilation and execution of all exercises
- **Interactive Menu**: Menu system (`main_menu.cpp`) providing user-friendly navigation through exercises
- **Documentation**: README.md with comprehensive setup and usage instructions

## Learning Progression Design
The architecture implements a progressive learning approach where each exercise builds upon previous concepts:

1. **Foundation Layer**: Basic syntax, program structure, and simple I/O operations
2. **Core Concepts**: Variables, data types, operators, and control flow
3. **Advanced Topics**: Functions, arrays, and object-oriented programming principles

## Build System
The project uses a simple compilation approach suitable for educational purposes:

- **Individual Compilation**: Direct g++ compilation for single exercises
- **Batch Processing**: Shell script automation for running multiple exercises
- **Interactive Execution**: Menu-driven system for guided learning experience

This design prioritizes simplicity and accessibility over complex build systems, making it ideal for C++ beginners who need to focus on language concepts rather than toolchain complexity.

# External Dependencies

## Compiler Requirements
- **G++ Compiler**: Primary C++ compiler for compilation
- **Standard C++ Library**: Built-in library for basic I/O operations and data types

## Platform Dependencies
- **Linux/Unix Environment**: Primary target platform with native shell script support
- **Windows with MinGW**: Alternative platform requiring MinGW toolchain for compilation
- **Terminal/Command Line**: Required for script execution and program interaction

## Development Tools
- **Shell Environment**: Bash-compatible shell for running automation scripts
- **Text Editor**: Any editor capable of editing C++ source files

The project deliberately minimizes external dependencies to focus on core C++ learning without complex setup requirements.