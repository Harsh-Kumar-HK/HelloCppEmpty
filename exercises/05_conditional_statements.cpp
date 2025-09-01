// Exercise 05: Conditional Statements
// This exercise demonstrates if/else statements, comparison operators,
// logical operators, switch statements, and conditional expressions

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "=== C++ Conditional Statements ===" << std::endl << std::endl;
    
    // BASIC IF-ELSE STATEMENTS
    std::cout << "--- Basic If-Else Statements ---" << std::endl;
    
    int age = 18;
    std::cout << "Age: " << age << std::endl;
    
    if (age >= 18) {
        std::cout << "You are an adult." << std::endl;
    } else {
        std::cout << "You are a minor." << std::endl;
    }
    
    // IF-ELSE IF-ELSE CHAIN
    std::cout << "\n--- If-Else If-Else Chain ---" << std::endl;
    
    int score = 85;
    std::cout << "Test score: " << score << std::endl;
    
    if (score >= 90) {
        std::cout << "Grade: A (Excellent!)" << std::endl;
    } else if (score >= 80) {
        std::cout << "Grade: B (Good work!)" << std::endl;
    } else if (score >= 70) {
        std::cout << "Grade: C (Satisfactory)" << std::endl;
    } else if (score >= 60) {
        std::cout << "Grade: D (Needs improvement)" << std::endl;
    } else {
        std::cout << "Grade: F (Failed)" << std::endl;
    }
    
    // COMPARISON OPERATORS
    std::cout << "\n--- Comparison Operators ---" << std::endl;
    
    int x = 10, y = 20;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    
    std::cout << "x == y: " << (x == y) << " (equal to)" << std::endl;
    std::cout << "x != y: " << (x != y) << " (not equal to)" << std::endl;
    std::cout << "x < y:  " << (x < y) << " (less than)" << std::endl;
    std::cout << "x <= y: " << (x <= y) << " (less than or equal)" << std::endl;
    std::cout << "x > y:  " << (x > y) << " (greater than)" << std::endl;
    std::cout << "x >= y: " << (x >= y) << " (greater than or equal)" << std::endl;
    
    // LOGICAL OPERATORS
    std::cout << "\n--- Logical Operators ---" << std::endl;
    
    bool is_student = true;
    bool has_id = true;
    int account_balance = 500;
    
    std::cout << "is_student = " << std::boolalpha << is_student << std::endl;
    std::cout << "has_id = " << has_id << std::endl;
    std::cout << "account_balance = " << account_balance << std::endl << std::endl;
    
    // AND operator (&&)
    if (is_student && has_id) {
        std::cout << "Student discount applies!" << std::endl;
    }
    
    // OR operator (||)
    if (is_student || account_balance > 1000) {
        std::cout << "Eligible for special offers!" << std::endl;
    }
    
    // NOT operator (!)
    if (!is_student) {
        std::cout << "Regular pricing applies." << std::endl;
    } else {
        std::cout << "Student pricing available." << std::endl;
    }
    
    // COMPLEX CONDITIONS
    std::cout << "\n--- Complex Conditions ---" << std::endl;
    
    int temperature = 75;
    bool is_sunny = true;
    bool is_weekend = false;
    
    std::cout << "Temperature: " << temperature << "°F" << std::endl;
    std::cout << "Sunny: " << is_sunny << std::endl;
    std::cout << "Weekend: " << is_weekend << std::endl << std::endl;
    
    if ((temperature > 70 && temperature < 85) && is_sunny && is_weekend) {
        std::cout << "Perfect day for a picnic!" << std::endl;
    } else if (temperature > 85 || (!is_sunny && is_weekend)) {
        std::cout << "Maybe stay indoors today." << std::endl;
    } else if (is_sunny && !is_weekend) {
        std::cout << "Nice day, but it's a weekday." << std::endl;
    } else {
        std::cout << "Regular day." << std::endl;
    }
    
    // SWITCH STATEMENTS
    std::cout << "\n--- Switch Statements ---" << std::endl;
    
    char grade = 'B';
    std::cout << "Letter grade: " << grade << std::endl;
    
    switch (grade) {
        case 'A':
        case 'a':
            std::cout << "Excellent work! GPA: 4.0" << std::endl;
            break;
        case 'B':
        case 'b':
            std::cout << "Good job! GPA: 3.0" << std::endl;
            break;
        case 'C':
        case 'c':
            std::cout << "Satisfactory. GPA: 2.0" << std::endl;
            break;
        case 'D':
        case 'd':
            std::cout << "Needs improvement. GPA: 1.0" << std::endl;
            break;
        case 'F':
        case 'f':
            std::cout << "Failed. GPA: 0.0" << std::endl;
            break;
        default:
            std::cout << "Invalid grade!" << std::endl;
    }
    
    // SWITCH WITH INTEGERS
    std::cout << "\n--- Switch with Menu Selection ---" << std::endl;
    
    int menu_choice = 2;
    std::cout << "Menu choice: " << menu_choice << std::endl;
    
    switch (menu_choice) {
        case 1:
            std::cout << "You selected: New Game" << std::endl;
            break;
        case 2:
            std::cout << "You selected: Load Game" << std::endl;
            break;
        case 3:
            std::cout << "You selected: Settings" << std::endl;
            break;
        case 4:
            std::cout << "You selected: Exit" << std::endl;
            break;
        default:
            std::cout << "Invalid selection!" << std::endl;
    }
    
    // NESTED IF STATEMENTS
    std::cout << "\n--- Nested If Statements ---" << std::endl;
    
    int hour = 14;  // 2 PM in 24-hour format
    bool is_weekday = true;
    
    std::cout << "Hour: " << hour << " (24-hour format)" << std::endl;
    std::cout << "Weekday: " << is_weekday << std::endl << std::endl;
    
    if (is_weekday) {
        if (hour >= 9 && hour < 17) {
            std::cout << "Office hours - everyone should be working!" << std::endl;
        } else if (hour >= 17 && hour < 22) {
            std::cout << "Evening - time to relax!" << std::endl;
        } else {
            std::cout << "Late night or early morning - most people are sleeping." << std::endl;
        }
    } else {
        if (hour >= 8 && hour < 12) {
            std::cout << "Weekend morning - perfect for breakfast!" << std::endl;
        } else if (hour >= 12 && hour < 18) {
            std::cout << "Weekend afternoon - great for activities!" << std::endl;
        } else {
            std::cout << "Weekend evening/night - time for entertainment!" << std::endl;
        }
    }
    
    // CONDITIONAL (TERNARY) OPERATOR
    std::cout << "\n--- Conditional (Ternary) Operator ---" << std::endl;
    
    int number = 42;
    std::cout << "Number: " << number << std::endl;
    
    // Syntax: condition ? value_if_true : value_if_false
    std::string parity = (number % 2 == 0) ? "even" : "odd";
    std::cout << "The number is " << parity << std::endl;
    
    // Multiple ternary operators
    int value = 85;
    std::string category = (value >= 90) ? "High" : 
                          (value >= 70) ? "Medium" : "Low";
    std::cout << "Value " << value << " is in " << category << " category" << std::endl;
    
    // PRACTICAL EXAMPLES
    std::cout << "\n--- Practical Examples ---" << std::endl;
    
    // Password strength checker
    std::string password = "MyPass123!";
    bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
    
    for (char c : password) {
        if (c >= 'A' && c <= 'Z') has_upper = true;
        if (c >= 'a' && c <= 'z') has_lower = true;
        if (c >= '0' && c <= '9') has_digit = true;
        if (c == '!' || c == '@' || c == '#' || c == '$') has_special = true;
    }
    
    std::cout << "Password: " << password << std::endl;
    std::cout << "Password strength: ";
    
    if (password.length() >= 8 && has_upper && has_lower && has_digit && has_special) {
        std::cout << "Strong" << std::endl;
    } else if (password.length() >= 6 && has_upper && has_lower && has_digit) {
        std::cout << "Medium" << std::endl;
    } else {
        std::cout << "Weak" << std::endl;
    }
    
    // Shipping cost calculator
    double order_total = 75.50;
    double shipping_cost;
    
    if (order_total >= 100) {
        shipping_cost = 0.0;  // Free shipping
    } else if (order_total >= 50) {
        shipping_cost = 5.99;  // Reduced shipping
    } else {
        shipping_cost = 9.99;  // Standard shipping
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nOrder total: $" << order_total << std::endl;
    std::cout << "Shipping cost: $" << shipping_cost << std::endl;
    std::cout << "Final total: $" << (order_total + shipping_cost) << std::endl;
    
    return 0;
}

/*
Key Concepts Demonstrated:
1. Basic if-else statements
2. If-else if-else chains
3. Comparison operators: ==, !=, <, <=, >, >=
4. Logical operators: &&, ||, !
5. Complex boolean expressions
6. Switch statements with break and default
7. Nested if statements
8. Conditional (ternary) operator
9. Practical applications of conditionals
10. Boolean variables and expressions
11. Short-circuit evaluation
12. Case sensitivity in switch statements
*/
