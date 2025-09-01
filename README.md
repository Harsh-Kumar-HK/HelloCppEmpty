# C++ Learning Project - Progressive Syntax Exercises

This project contains a comprehensive set of C++ exercises designed to teach fundamental programming concepts progressively, starting from Hello World and advancing to object-oriented programming.

## Prerequisites

- C++ compiler (g++ recommended)
- Linux/Unix terminal or Windows with MinGW

## Quick Start

1. **Compile and run all exercises:**
   ```bash
   chmod +x compile_and_run.sh
   ./compile_and_run.sh
   ```

2. **Run individual exercises:**
   ```bash
   g++ -o hello exercises/01_hello_world.cpp && ./hello
   ```

3. **Interactive menu system:**
   ```bash
   g++ -o menu main_menu.cpp && ./menu
   ```

## Exercise Structure

### 01. Hello World (`01_hello_world.cpp`)
- Basic program structure
- Include statements
- Main function
- Simple output

### 02. Variables and Data Types (`02_variables_datatypes.cpp`)
- Integer types (int, long, short)
- Floating-point types (float, double)
- Character and boolean types
- Variable declaration and initialization

### 03. Input and Output (`03_input_output.cpp`)
- Using cin for input
- Using cout for output
- Stream manipulators
- Basic formatting

### 04. Arithmetic Operators (`04_arithmetic_operators.cpp`)
- Basic arithmetic operations
- Assignment operators
- Increment/decrement operators
- Operator precedence

### 05. Conditional Statements (`05_conditional_statements.cpp`)
- if, else if, else statements
- Comparison operators
- Logical operators
- Switch statements

### 06. Loops (`06_loops.cpp`)
- for loops
- while loops
- do-while loops
- Nested loops
- break and continue

### 07. Functions (`07_functions.cpp`)
- Function declaration and definition
- Parameters and return values
- Function overloading
- Scope and local variables

### 08. Arrays (`08_arrays.cpp`)
- Array declaration and initialization
- Accessing array elements
- Multi-dimensional arrays
- Array manipulation

### 09. Strings (`09_strings.cpp`)
- C-style strings
- C++ string class
- String operations
- String manipulation functions

### 10. Pointers and References (`10_pointers_references.cpp`)
- Pointer declaration and usage
- Memory addresses
- Reference variables
- Pointer arithmetic

### 11. Classes and Objects (`11_classes_objects.cpp`)
- Class definition
- Object creation
- Member variables and functions
- Constructors and destructors

### 12. Inheritance (`12_inheritance.cpp`)
- Base and derived classes
- Access specifiers
- Virtual functions
- Polymorphism basics

## Compilation Notes

- All exercises use standard C++11 features
- Compile with: `g++ -std=c++11 -o output_name source_file.cpp`
- For debugging: add `-g` flag
- For warnings: add `-Wall -Wextra` flags

## Learning Path

1. Start with exercise 01 and work through sequentially
2. Each exercise builds upon previous concepts
3. Try modifying the code to experiment with variations
4. Use the interactive menu for easy navigation between exercises

## Tips for Learning

- Read the comments in each file carefully
- Try running each exercise and observe the output
- Experiment by modifying values and seeing how output changes
- Practice writing similar programs from scratch
