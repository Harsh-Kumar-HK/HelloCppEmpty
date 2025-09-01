// Exercise 04: Arithmetic Operators
// This exercise demonstrates all arithmetic operators in C++
// including basic operations, assignment operators, and increment/decrement

#include <iostream>
#include <iomanip>
#include <cmath>  // For mathematical functions

int main() {
    std::cout << "=== C++ Arithmetic Operators ===" << std::endl << std::endl;
    
    // BASIC ARITHMETIC OPERATIONS
    std::cout << "--- Basic Arithmetic Operations ---" << std::endl;
    
    int a = 15, b = 4;
    
    std::cout << "Given: a = " << a << ", b = " << b << std::endl << std::endl;
    
    // Addition
    int sum = a + b;
    std::cout << "Addition: " << a << " + " << b << " = " << sum << std::endl;
    
    // Subtraction
    int difference = a - b;
    std::cout << "Subtraction: " << a << " - " << b << " = " << difference << std::endl;
    
    // Multiplication
    int product = a * b;
    std::cout << "Multiplication: " << a << " * " << b << " = " << product << std::endl;
    
    // Division (integer division)
    int quotient = a / b;
    std::cout << "Division (integer): " << a << " / " << b << " = " << quotient << std::endl;
    
    // Modulus (remainder)
    int remainder = a % b;
    std::cout << "Modulus: " << a << " % " << b << " = " << remainder << std::endl;
    
    // FLOATING-POINT DIVISION
    std::cout << "\n--- Floating-Point Division ---" << std::endl;
    
    double x = 15.0, y = 4.0;
    double float_result = x / y;
    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Floating division: " << x << " / " << y << " = " << float_result << std::endl;
    
    // Mixed operations
    double mixed_result = a / (double)b;  // Type casting
    std::cout << "Mixed division: " << a << " / (double)" << b << " = " << mixed_result << std::endl;
    
    // ASSIGNMENT OPERATORS
    std::cout << "\n--- Assignment Operators ---" << std::endl;
    
    int num = 10;
    std::cout << "Initial value: num = " << num << std::endl;
    
    // Compound assignment operators
    num += 5;   // Equivalent to: num = num + 5
    std::cout << "After num += 5: num = " << num << std::endl;
    
    num -= 3;   // Equivalent to: num = num - 3
    std::cout << "After num -= 3: num = " << num << std::endl;
    
    num *= 2;   // Equivalent to: num = num * 2
    std::cout << "After num *= 2: num = " << num << std::endl;
    
    num /= 4;   // Equivalent to: num = num / 4
    std::cout << "After num /= 4: num = " << num << std::endl;
    
    num %= 3;   // Equivalent to: num = num % 3
    std::cout << "After num %= 3: num = " << num << std::endl;
    
    // INCREMENT AND DECREMENT OPERATORS
    std::cout << "\n--- Increment and Decrement Operators ---" << std::endl;
    
    int counter = 5;
    std::cout << "Initial counter = " << counter << std::endl;
    
    // Pre-increment (increment first, then use value)
    std::cout << "Pre-increment ++counter = " << ++counter << std::endl;
    std::cout << "Counter is now: " << counter << std::endl;
    
    // Post-increment (use value first, then increment)
    std::cout << "Post-increment counter++ = " << counter++ << std::endl;
    std::cout << "Counter is now: " << counter << std::endl;
    
    // Pre-decrement
    std::cout << "Pre-decrement --counter = " << --counter << std::endl;
    std::cout << "Counter is now: " << counter << std::endl;
    
    // Post-decrement
    std::cout << "Post-decrement counter-- = " << counter-- << std::endl;
    std::cout << "Counter is now: " << counter << std::endl;
    
    // OPERATOR PRECEDENCE
    std::cout << "\n--- Operator Precedence ---" << std::endl;
    
    int result1 = 2 + 3 * 4;        // Multiplication first
    int result2 = (2 + 3) * 4;      // Parentheses first
    int result3 = 10 / 2 * 3;       // Left to right for same precedence
    int result4 = 10 / (2 * 3);     // Parentheses change order
    
    std::cout << "2 + 3 * 4 = " << result1 << " (multiplication first)" << std::endl;
    std::cout << "(2 + 3) * 4 = " << result2 << " (parentheses first)" << std::endl;
    std::cout << "10 / 2 * 3 = " << result3 << " (left to right)" << std::endl;
    std::cout << "10 / (2 * 3) = " << result4 << " (parentheses change order)" << std::endl;
    
    // MATHEMATICAL FUNCTIONS
    std::cout << "\n--- Mathematical Functions ---" << std::endl;
    
    double angle = 3.14159 / 4;  // 45 degrees in radians
    double base = 2.0;
    double exponent = 3.0;
    
    std::cout << std::setprecision(4);
    std::cout << "sqrt(16) = " << sqrt(16) << std::endl;
    std::cout << "pow(" << base << ", " << exponent << ") = " << pow(base, exponent) << std::endl;
    std::cout << "sin(π/4) = " << sin(angle) << std::endl;
    std::cout << "cos(π/4) = " << cos(angle) << std::endl;
    std::cout << "abs(-15) = " << abs(-15) << std::endl;
    std::cout << "ceil(4.3) = " << ceil(4.3) << std::endl;
    std::cout << "floor(4.7) = " << floor(4.7) << std::endl;
    
    // PRACTICAL EXAMPLES
    std::cout << "\n--- Practical Examples ---" << std::endl;
    
    // Temperature conversion
    double celsius = 25.0;
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    std::cout << std::setprecision(1);
    std::cout << "Temperature conversion: " << celsius << "°C = " << fahrenheit << "°F" << std::endl;
    
    // Compound interest calculation
    double principal = 1000.0;
    double rate = 0.05;  // 5% annual interest
    int years = 3;
    double amount = principal * pow(1 + rate, years);
    std::cout << std::setprecision(2);
    std::cout << "Compound interest: $" << principal << " at " << (rate * 100) << "% for " 
              << years << " years = $" << amount << std::endl;
    
    // Circle calculations
    double radius = 5.0;
    double area = 3.14159 * radius * radius;
    double circumference = 2 * 3.14159 * radius;
    std::cout << "Circle with radius " << radius << ":" << std::endl;
    std::cout << "  Area = " << area << std::endl;
    std::cout << "  Circumference = " << circumference << std::endl;
    
    // Average calculation
    int score1 = 85, score2 = 92, score3 = 78, score4 = 96;
    double average = (score1 + score2 + score3 + score4) / 4.0;
    std::cout << "Test scores: " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << std::endl;
    std::cout << "Average: " << std::setprecision(1) << average << std::endl;
    
    return 0;
}

/*
Key Concepts Demonstrated:
1. Basic arithmetic operators: +, -, *, /, %
2. Integer vs floating-point division
3. Type casting for mixed operations
4. Assignment operators: +=, -=, *=, /=, %=
5. Pre and post increment/decrement operators
6. Operator precedence and associativity
7. Mathematical functions from <cmath>
8. Practical applications of arithmetic operations
9. Formatting numeric output
10. Common mathematical calculations
*/
