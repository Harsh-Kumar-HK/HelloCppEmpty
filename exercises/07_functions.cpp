// Exercise 07: Functions
// This exercise demonstrates function declaration, definition, parameters,
// return values, function overloading, and scope concepts

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

// FUNCTION DECLARATIONS (prototypes)
// These tell the compiler about functions that will be defined later

void greet();                                    // Function with no parameters, no return
void greet_person(const std::string& name);     // Function with parameter, no return
int add(int a, int b);                          // Function with parameters and return value
double calculate_area(double radius);           // Function returning double
int factorial(int n);                          // Recursive function
void print_separator(char symbol = '-', int length = 30); // Function with default parameters

// Function overloading - same name, different parameters
int multiply(int a, int b);
double multiply(double a, double b);
int multiply(int a, int b, int c);

// Functions with different parameter types
void display_info(int age);
void display_info(const std::string& name);
void display_info(const std::string& name, int age);

// Pass by reference vs pass by value
void increment_by_value(int num);
void increment_by_reference(int& num);
void swap_values(int& a, int& b);

// Functions returning different types
bool is_even(int number);
std::string get_grade(int score);
double convert_to_celsius(double fahrenheit);

int main() {
    std::cout << "=== C++ Functions ===" << std::endl << std::endl;
    
    // BASIC FUNCTION CALLS
    std::cout << "--- Basic Function Calls ---" << std::endl;
    
    greet();
    greet_person("Alice");
    greet_person("Bob");
    
    print_separator();
    
    // FUNCTIONS WITH RETURN VALUES
    std::cout << "--- Functions with Return Values ---" << std::endl;
    
    int sum = add(15, 25);
    std::cout << "15 + 25 = " << sum << std::endl;
    
    double area = calculate_area(5.0);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area of circle with radius 5.0 = " << area << std::endl;
    
    int fact = factorial(5);
    std::cout << "Factorial of 5 = " << fact << std::endl;
    
    print_separator();
    
    // FUNCTION OVERLOADING
    std::cout << "--- Function Overloading ---" << std::endl;
    
    std::cout << "multiply(5, 3) = " << multiply(5, 3) << std::endl;
    std::cout << "multiply(2.5, 4.0) = " << multiply(2.5, 4.0) << std::endl;
    std::cout << "multiply(2, 3, 4) = " << multiply(2, 3, 4) << std::endl;
    
    display_info(25);
    display_info("Charlie");
    display_info("Diana", 30);
    
    print_separator();
    
    // PASS BY VALUE VS PASS BY REFERENCE
    std::cout << "--- Pass by Value vs Pass by Reference ---" << std::endl;
    
    int original_number = 10;
    std::cout << "Original number: " << original_number << std::endl;
    
    increment_by_value(original_number);
    std::cout << "After increment_by_value: " << original_number << std::endl;
    
    increment_by_reference(original_number);
    std::cout << "After increment_by_reference: " << original_number << std::endl;
    
    int x = 100, y = 200;
    std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
    swap_values(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    
    print_separator();
    
    // FUNCTIONS RETURNING DIFFERENT TYPES
    std::cout << "--- Functions Returning Different Types ---" << std::endl;
    
    for (int i = 1; i <= 6; i++) {
        std::cout << i << " is " << (is_even(i) ? "even" : "odd") << std::endl;
    }
    
    std::cout << std::endl;
    int scores[] = {95, 87, 76, 65, 54};
    for (int i = 0; i < 5; i++) {
        std::cout << "Score " << scores[i] << " = Grade " << get_grade(scores[i]) << std::endl;
    }
    
    std::cout << std::endl;
    double temp_f = 98.6;
    double temp_c = convert_to_celsius(temp_f);
    std::cout << temp_f << "°F = " << temp_c << "°C" << std::endl;
    
    print_separator();
    
    // DEFAULT PARAMETERS
    std::cout << "--- Default Parameters ---" << std::endl;
    
    print_separator();           // Uses defaults: '-' and 30
    print_separator('=');        // Uses '=' and default 30
    print_separator('*', 20);    // Uses '*' and 20
    
    print_separator();
    
    // PRACTICAL EXAMPLES
    std::cout << "--- Practical Examples ---" << std::endl;
    
    // Calculator functions
    std::cout << "Calculator operations:" << std::endl;
    std::cout << "10 + 5 = " << add(10, 5) << std::endl;
    std::cout << "10 * 5 = " << multiply(10, 5) << std::endl;
    
    // Temperature conversions
    std::cout << "\nTemperature conversions:" << std::endl;
    double fahrenheit_temps[] = {32.0, 68.0, 100.0, 212.0};
    for (int i = 0; i < 4; i++) {
        double celsius = convert_to_celsius(fahrenheit_temps[i]);
        std::cout << fahrenheit_temps[i] << "°F = " << celsius << "°C" << std::endl;
    }
    
    // Math operations
    std::cout << "\nMath operations:" << std::endl;
    for (int i = 1; i <= 6; i++) {
        std::cout << "Factorial of " << i << " = " << factorial(i) << std::endl;
    }
    
    return 0;
}

// FUNCTION DEFINITIONS

void greet() {
    std::cout << "Hello! Welcome to the function demonstration!" << std::endl;
}

void greet_person(const std::string& name) {
    std::cout << "Hello, " << name << "! Nice to meet you!" << std::endl;
}

int add(int a, int b) {
    return a + b;
}

double calculate_area(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

int factorial(int n) {
    // Recursive function - a function that calls itself
    if (n <= 1) {
        return 1;  // Base case
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

void print_separator(char symbol, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << symbol;
    }
    std::cout << std::endl;
}

// Function overloading definitions
int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

int multiply(int a, int b, int c) {
    return a * b * c;
}

// Overloaded display_info functions
void display_info(int age) {
    std::cout << "Age: " << age << " years old" << std::endl;
}

void display_info(const std::string& name) {
    std::cout << "Name: " << name << std::endl;
}

void display_info(const std::string& name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << " years old" << std::endl;
}

// Pass by value vs pass by reference
void increment_by_value(int num) {
    num++;  // This only changes the local copy
    std::cout << "Inside increment_by_value: " << num << std::endl;
}

void increment_by_reference(int& num) {
    num++;  // This changes the original variable
    std::cout << "Inside increment_by_reference: " << num << std::endl;
}

void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Functions returning different types
bool is_even(int number) {
    return (number % 2 == 0);
}

std::string get_grade(int score) {
    if (score >= 90) return "A";
    else if (score >= 80) return "B";
    else if (score >= 70) return "C";
    else if (score >= 60) return "D";
    else return "F";
}

double convert_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

/*
Key Concepts Demonstrated:
1. Function declaration (prototypes) and definition
2. Functions with no parameters and no return value
3. Functions with parameters
4. Functions with return values
5. Function overloading (same name, different parameters)
6. Default parameters
7. Pass by value vs pass by reference
8. Recursive functions
9. Local vs global scope
10. Function naming conventions
11. Const parameters for efficiency and safety
12. Practical applications of functions
13. Code organization and reusability
14. Different return types (void, int, double, bool, string)
*/
