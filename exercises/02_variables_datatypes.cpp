// Exercise 02: Variables and Data Types
// This exercise demonstrates different data types available in C++
// and how to declare and initialize variables

#include <iostream>
#include <string>    // For std::string
#include <iomanip>   // For output formatting

int main() {
    std::cout << "=== C++ Data Types and Variables ===" << std::endl << std::endl;
    
    // INTEGER TYPES
    std::cout << "--- Integer Types ---" << std::endl;
    
    int age = 25;                    // Standard integer (usually 32 bits)
    short short_num = 100;           // Short integer (usually 16 bits)
    long long_num = 1000000L;        // Long integer (usually 64 bits)
    long long very_long = 9876543210LL; // Very long integer
    
    std::cout << "int age = " << age << std::endl;
    std::cout << "short short_num = " << short_num << std::endl;
    std::cout << "long long_num = " << long_num << std::endl;
    std::cout << "long long very_long = " << very_long << std::endl;
    
    // FLOATING-POINT TYPES
    std::cout << "\n--- Floating-Point Types ---" << std::endl;
    
    float temperature = 23.5f;       // Single precision (32 bits)
    double pi = 3.141592653589793;   // Double precision (64 bits)
    long double precise_pi = 3.141592653589793238L; // Extended precision
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "float temperature = " << temperature << std::endl;
    std::cout << "double pi = " << pi << std::endl;
    std::cout << "long double precise_pi = " << precise_pi << std::endl;
    
    // CHARACTER TYPES
    std::cout << "\n--- Character Types ---" << std::endl;
    
    char grade = 'A';                // Single character
    char digit = '9';                // Characters can represent digits
    
    std::cout << "char grade = '" << grade << "'" << std::endl;
    std::cout << "char digit = '" << digit << "'" << std::endl;
    
    // BOOLEAN TYPE
    std::cout << "\n--- Boolean Type ---" << std::endl;
    
    bool is_student = true;          // Boolean can be true or false
    bool is_working = false;
    
    std::cout << "bool is_student = " << std::boolalpha << is_student << std::endl;
    std::cout << "bool is_working = " << is_working << std::endl;
    
    // STRING TYPE (from std::string)
    std::cout << "\n--- String Type ---" << std::endl;
    
    std::string name = "Alice";      // C++ string class
    std::string greeting = "Hello, " + name + "!";
    
    std::cout << "std::string name = \"" << name << "\"" << std::endl;
    std::cout << "std::string greeting = \"" << greeting << "\"" << std::endl;
    
    // CONSTANT VARIABLES
    std::cout << "\n--- Constants ---" << std::endl;
    
    const int MAX_STUDENTS = 30;     // Constant - cannot be changed
    const double GRAVITY = 9.81;
    
    std::cout << "const int MAX_STUDENTS = " << MAX_STUDENTS << std::endl;
    std::cout << "const double GRAVITY = " << GRAVITY << std::endl;
    
    // VARIABLE INITIALIZATION METHODS
    std::cout << "\n--- Different Initialization Methods ---" << std::endl;
    
    int method1 = 10;                // Copy initialization
    int method2(20);                 // Direct initialization
    int method3{30};                 // Brace initialization (C++11)
    int method4 = {40};              // Copy-list initialization (C++11)
    
    std::cout << "Copy init: " << method1 << std::endl;
    std::cout << "Direct init: " << method2 << std::endl;
    std::cout << "Brace init: " << method3 << std::endl;
    std::cout << "Copy-list init: " << method4 << std::endl;
    
    // AUTO KEYWORD (C++11)
    std::cout << "\n--- Auto Keyword ---" << std::endl;
    
    auto auto_int = 42;              // Compiler deduces type as int
    auto auto_double = 3.14;         // Compiler deduces type as double
    auto auto_string = std::string("Hello");
    
    std::cout << "auto auto_int = " << auto_int << " (type deduced as int)" << std::endl;
    std::cout << "auto auto_double = " << auto_double << " (type deduced as double)" << std::endl;
    std::cout << "auto auto_string = \"" << auto_string << "\" (type deduced as string)" << std::endl;
    
    return 0;
}

/*
Key Concepts Demonstrated:
1. Integer types: int, short, long, long long
2. Floating-point types: float, double, long double
3. Character type: char
4. Boolean type: bool
5. String type: std::string
6. Constant variables with const keyword
7. Different initialization methods
8. Auto keyword for type deduction
9. Proper variable naming conventions
10. Output formatting with iomanip
*/
