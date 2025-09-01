// Exercise 03: Input and Output
// This exercise demonstrates various ways to handle input and output in C++
// including basic I/O, formatting, and string manipulation

#include <iostream>
#include <string>
#include <iomanip>   // For formatting
#include <sstream>   // For string streams

int main() {
    std::cout << "=== C++ Input and Output ===" << std::endl << std::endl;
    
    // BASIC INPUT WITH CIN
    std::cout << "--- Basic Input ---" << std::endl;
    
    std::string user_name;
    int user_age;
    
    std::cout << "Enter your name: ";
    std::cin >> user_name;  // Note: this stops at whitespace
    
    std::cout << "Enter your age: ";
    std::cin >> user_age;
    
    std::cout << "Hello, " << user_name << "! You are " << user_age << " years old." << std::endl;
    
    // HANDLING WHITESPACE IN INPUT
    std::cout << "\n--- Handling Whitespace in Input ---" << std::endl;
    
    std::cin.ignore(); // Clear the input buffer
    
    std::string full_name;
    std::cout << "Enter your full name (with spaces): ";
    std::getline(std::cin, full_name);  // Reads entire line including spaces
    
    std::cout << "Your full name is: " << full_name << std::endl;
    
    // MULTIPLE INPUTS ON ONE LINE
    std::cout << "\n--- Multiple Inputs ---" << std::endl;
    
    int num1, num2, num3;
    std::cout << "Enter three numbers separated by spaces: ";
    std::cin >> num1 >> num2 >> num3;
    
    std::cout << "You entered: " << num1 << ", " << num2 << ", " << num3 << std::endl;
    std::cout << "Sum: " << (num1 + num2 + num3) << std::endl;
    
    // OUTPUT FORMATTING
    std::cout << "\n--- Output Formatting ---" << std::endl;
    
    double price = 19.99;
    double tax_rate = 0.0825;
    double total = price * (1 + tax_rate);
    
    // Default output
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Tax rate: " << tax_rate << std::endl;
    std::cout << "Total: $" << total << std::endl;
    
    // Formatted output
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nFormatted output:" << std::endl;
    std::cout << "Price: $" << std::setw(8) << price << std::endl;
    std::cout << "Tax:   $" << std::setw(8) << (price * tax_rate) << std::endl;
    std::cout << "Total: $" << std::setw(8) << total << std::endl;
    
    // FIELD WIDTH AND ALIGNMENT
    std::cout << "\n--- Field Width and Alignment ---" << std::endl;
    
    std::cout << std::left;  // Left-align subsequent output
    std::cout << std::setw(15) << "Product" << std::setw(10) << "Price" << std::setw(10) << "Quantity" << std::endl;
    std::cout << std::setfill('-') << std::setw(35) << "" << std::setfill(' ') << std::endl;
    
    std::cout << std::setw(15) << "Laptop" << "$" << std::setw(9) << "999.99" << std::setw(10) << "2" << std::endl;
    std::cout << std::setw(15) << "Mouse" << "$" << std::setw(9) << "29.99" << std::setw(10) << "5" << std::endl;
    std::cout << std::setw(15) << "Keyboard" << "$" << std::setw(9) << "79.99" << std::setw(10) << "3" << std::endl;
    
    // DIFFERENT NUMBER BASES
    std::cout << "\n--- Number Base Output ---" << std::endl;
    
    int number = 255;
    std::cout << "Decimal: " << std::dec << number << std::endl;
    std::cout << "Hexadecimal: " << std::hex << number << std::endl;
    std::cout << "Octal: " << std::oct << number << std::endl;
    std::cout << std::dec; // Reset to decimal
    
    // BOOLEAN OUTPUT
    std::cout << "\n--- Boolean Output ---" << std::endl;
    
    bool condition1 = true;
    bool condition2 = false;
    
    std::cout << "Default boolean output: " << condition1 << " " << condition2 << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Text boolean output: " << condition1 << " " << condition2 << std::endl;
    std::cout << std::noboolalpha; // Reset to numeric
    
    // STRING STREAMS
    std::cout << "\n--- String Streams ---" << std::endl;
    
    std::ostringstream oss;
    oss << "The answer is " << 42 << " and pi is approximately " << std::setprecision(4) << 3.14159;
    std::string result = oss.str();
    std::cout << "String stream result: " << result << std::endl;
    
    // INTERACTIVE EXAMPLE
    std::cout << "\n--- Interactive Calculation ---" << std::endl;
    
    double first_number, second_number;
    char operation;
    
    std::cout << "Enter a simple calculation (e.g., 5 + 3): ";
    std::cin >> first_number >> operation >> second_number;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Result: " << first_number << " " << operation << " " << second_number << " = ";
    
    switch(operation) {
        case '+':
            std::cout << (first_number + second_number);
            break;
        case '-':
            std::cout << (first_number - second_number);
            break;
        case '*':
            std::cout << (first_number * second_number);
            break;
        case '/':
            if (second_number != 0) {
                std::cout << (first_number / second_number);
            } else {
                std::cout << "Error: Division by zero!";
            }
            break;
        default:
            std::cout << "Error: Unknown operation!";
    }
    std::cout << std::endl;
    
    return 0;
}

/*
Key Concepts Demonstrated:
1. Basic input with std::cin
2. Reading strings with spaces using std::getline
3. Multiple inputs on one line
4. Output formatting with iomanip
5. Field width and alignment
6. Number base output (decimal, hex, octal)
7. Boolean output formatting
8. String streams for formatted string creation
9. Input buffer management
10. Interactive user input processing
11. Precision and fixed-point notation
12. Fill characters and padding
*/
