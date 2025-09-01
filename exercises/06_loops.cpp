// Exercise 06: Loops
// This exercise demonstrates for loops, while loops, do-while loops,
// nested loops, and loop control statements (break and continue)

#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::cout << "=== C++ Loops ===" << std::endl << std::endl;
    
    // FOR LOOPS
    std::cout << "--- For Loops ---" << std::endl;
    
    // Basic for loop
    std::cout << "Counting from 1 to 5:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // For loop with different increments
    std::cout << "Even numbers from 2 to 10:" << std::endl;
    for (int i = 2; i <= 10; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Countdown for loop
    std::cout << "Countdown from 5 to 1:" << std::endl;
    for (int i = 5; i >= 1; i--) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // WHILE LOOPS
    std::cout << "--- While Loops ---" << std::endl;
    
    // Basic while loop
    int count = 1;
    std::cout << "While loop counting to 5:" << std::endl;
    while (count <= 5) {
        std::cout << count << " ";
        count++;
    }
    std::cout << std::endl << std::endl;
    
    // While loop for input validation
    int user_number;
    std::cout << "Enter a number between 1 and 10: ";
    std::cin >> user_number;
    
    while (user_number < 1 || user_number > 10) {
        std::cout << "Invalid input! Please enter a number between 1 and 10: ";
        std::cin >> user_number;
    }
    std::cout << "Thank you! You entered: " << user_number << std::endl << std::endl;
    
    // DO-WHILE LOOPS
    std::cout << "--- Do-While Loops ---" << std::endl;
    
    // Basic do-while loop
    int num = 1;
    std::cout << "Do-while loop (executes at least once):" << std::endl;
    do {
        std::cout << num << " ";
        num++;
    } while (num <= 5);
    std::cout << std::endl << std::endl;
    
    // Menu system with do-while
    char choice;
    do {
        std::cout << "\n--- Simple Menu ---" << std::endl;
        std::cout << "A) Display greeting" << std::endl;
        std::cout << "B) Show current time info" << std::endl;
        std::cout << "C) Count to 3" << std::endl;
        std::cout << "Q) Quit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;
        
        switch (choice) {
            case 'A':
            case 'a':
                std::cout << "Hello! Welcome to the loop demonstration!" << std::endl;
                break;
            case 'B':
            case 'b':
                std::cout << "This is a demonstration running in a loop." << std::endl;
                break;
            case 'C':
            case 'c':
                std::cout << "Counting: ";
                for (int i = 1; i <= 3; i++) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
                break;
            case 'Q':
            case 'q':
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 'Q' && choice != 'q');
    
    // NESTED LOOPS
    std::cout << "\n--- Nested Loops ---" << std::endl;
    
    // Multiplication table
    std::cout << "Multiplication table (1-5):" << std::endl;
    std::cout << "   ";
    for (int i = 1; i <= 5; i++) {
        std::cout << std::setw(4) << i;
    }
    std::cout << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 1; j <= 5; j++) {
            std::cout << std::setw(4) << (i * j);
        }
        std::cout << std::endl;
    }
    
    // Pattern printing
    std::cout << "\nStar pattern:" << std::endl;
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    
    // BREAK AND CONTINUE STATEMENTS
    std::cout << "\n--- Break and Continue Statements ---" << std::endl;
    
    // Using break to exit loop early
    std::cout << "Numbers 1-10, but stop at 7:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        if (i == 7) {
            break;  // Exit the loop when i equals 7
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // Using continue to skip iterations
    std::cout << "Numbers 1-10, but skip multiples of 3:" << std::endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue;  // Skip the rest of this iteration
        }
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;
    
    // PRACTICAL EXAMPLES
    std::cout << "--- Practical Examples ---" << std::endl;
    
    // Finding prime numbers
    std::cout << "Prime numbers between 2 and 20:" << std::endl;
    for (int num = 2; num <= 20; num++) {
        bool is_prime = true;
        
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                is_prime = false;
                break;  // No need to check further
            }
        }
        
        if (is_prime) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
    
    // Sum of numbers
    int sum = 0;
    std::cout << "\nSum of numbers 1 to 100: ";
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;
    
    // Factorial calculation
    int factorial_num = 5;
    long long factorial = 1;
    for (int i = 1; i <= factorial_num; i++) {
        factorial *= i;
    }
    std::cout << "Factorial of " << factorial_num << " is: " << factorial << std::endl;
    
    // Fibonacci sequence
    std::cout << "\nFirst 10 Fibonacci numbers:" << std::endl;
    int first = 0, second = 1, next;
    std::cout << first << " " << second << " ";
    
    for (int i = 3; i <= 10; i++) {
        next = first + second;
        std::cout << next << " ";
        first = second;
        second = next;
    }
    std::cout << std::endl;
    
    // Password attempts with limited tries
    std::cout << "\n--- Password System (Demo) ---" << std::endl;
    std::string correct_password = "secret123";
    std::string entered_password;
    int max_attempts = 3;
    int attempts = 0;
    bool login_successful = false;
    
    while (attempts < max_attempts && !login_successful) {
        attempts++;
        std::cout << "Attempt " << attempts << "/" << max_attempts 
                  << " - Enter password: ";
        std::cin >> entered_password;
        
        if (entered_password == correct_password) {
            login_successful = true;
            std::cout << "Login successful!" << std::endl;
        } else {
            if (attempts < max_attempts) {
                std::cout << "Incorrect password. " 
                          << (max_attempts - attempts) << " attempts remaining." << std::endl;
            } else {
                std::cout << "Access denied. Too many failed attempts." << std::endl;
            }
        }
    }
    
    // Number guessing game
    std::cout << "\n--- Number Guessing Game (Demo) ---" << std::endl;
    int secret_number = 42;  // In a real game, this would be random
    int guess;
    int guess_count = 0;
    const int max_guesses = 5;
    
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;
    std::cout << "You have " << max_guesses << " guesses." << std::endl;
    
    do {
        guess_count++;
        std::cout << "Guess #" << guess_count << ": ";
        std::cin >> guess;
        
        if (guess == secret_number) {
            std::cout << "Congratulations! You guessed it in " 
                      << guess_count << " attempts!" << std::endl;
            break;
        } else if (guess < secret_number) {
            std::cout << "Too low! ";
        } else {
            std::cout << "Too high! ";
        }
        
        if (guess_count < max_guesses) {
            std::cout << (max_guesses - guess_count) << " guesses left." << std::endl;
        }
        
    } while (guess_count < max_guesses);
    
    if (guess != secret_number) {
        std::cout << "Sorry! The number was " << secret_number << std::endl;
    }
    
    return 0;
}

/*
Key Concepts Demonstrated:
1. For loops with various increments and conditions
2. While loops for conditional iteration
3. Do-while loops for guaranteed execution
4. Nested loops for multi-dimensional operations
5. Break statement to exit loops early
6. Continue statement to skip iterations
7. Loop control and flow
8. Practical applications: menus, validation, calculations
9. Pattern generation with nested loops
10. Mathematical computations using loops
11. Input validation techniques
12. Game logic implementation
*/
