// Exercise 01: Hello World
// This is the traditional first program in any programming language
// It demonstrates the basic structure of a C++ program

#include <iostream>  // Include the input/output stream library

// The main function - every C++ program must have one
// int indicates that this function returns an integer value
int main() {
    // Output "Hello, World!" to the console
    // std::cout is the standard output stream
    // << is the stream insertion operator
    // std::endl adds a newline and flushes the output buffer
    std::cout << "Hello, World!" << std::endl;
    
    // You can also use \n for newline without flushing
    std::cout << "Welcome to C++ programming!\n";
    
    // Multiple outputs can be chained together
    std::cout << "This is " << "a concatenated " << "output." << std::endl;
    
    // return 0 indicates successful program execution
    // This is optional in main() - compiler will add it automatically
    return 0;
}

/*
Key Concepts Demonstrated:
1. #include directive - includes external libraries
2. main() function - entry point of the program
3. std::cout - standard output stream
4. << operator - stream insertion
5. std::endl vs \n - line endings
6. Comments - single line (//) and multi-line (/* */)
7. return statement - program exit status
*/
