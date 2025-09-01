// Main Menu - Interactive C++ Learning System
// This program provides a menu-driven interface to access all C++ exercises
// and allows users to compile and run individual exercises interactively

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>  // For system() calls
#include <limits>   // For input validation

// Structure to hold exercise information
struct Exercise {
    int number;
    std::string filename;
    std::string title;
    std::string description;
};

// Function prototypes
void display_welcome_message();
void display_main_menu();
void display_exercise_details(const Exercise& exercise);
bool compile_and_run_exercise(const Exercise& exercise);
void display_help();
void display_about();
void clear_screen();
void pause_execution();
int get_user_choice(int min_choice, int max_choice);
std::vector<Exercise> initialize_exercises();

int main() {
    // Initialize exercises
    std::vector<Exercise> exercises = initialize_exercises();
    
    clear_screen();
    display_welcome_message();
    
    int choice;
    bool continue_program = true;
    
    while (continue_program) {
        display_main_menu();
        choice = get_user_choice(0, static_cast<int>(exercises.size()) + 3);
        
        clear_screen();
        
        switch (choice) {
            case 0:
                std::cout << "Thank you for using the C++ Learning System!" << std::endl;
                std::cout << "Keep practicing and happy coding!" << std::endl;
                continue_program = false;
                break;
                
            default:
                if (choice >= 1 && choice <= static_cast<int>(exercises.size())) {
                    // Run specific exercise
                    Exercise& selected_exercise = exercises[choice - 1];
                    display_exercise_details(selected_exercise);
                    
                    char run_choice;
                    std::cout << "\nWould you like to compile and run this exercise? (y/n): ";
                    std::cin >> run_choice;
                    
                    if (run_choice == 'y' || run_choice == 'Y') {
                        std::cout << std::endl;
                        if (compile_and_run_exercise(selected_exercise)) {
                            std::cout << "\nExercise completed successfully!" << std::endl;
                        } else {
                            std::cout << "\nThere was an issue running the exercise." << std::endl;
                        }
                    }
                } else if (choice == static_cast<int>(exercises.size()) + 1) {
                    // Run all exercises
                    std::cout << "=== Running All Exercises ===" << std::endl << std::endl;
                    
                    char confirm;
                    std::cout << "This will compile and run all " << exercises.size() 
                              << " exercises sequentially." << std::endl;
                    std::cout << "Continue? (y/n): ";
                    std::cin >> confirm;
                    
                    if (confirm == 'y' || confirm == 'Y') {
                        for (size_t i = 0; i < exercises.size(); i++) {
                            std::cout << "\n" << std::string(50, '=') << std::endl;
                            std::cout << "Running Exercise " << (i + 1) << ": " 
                                      << exercises[i].title << std::endl;
                            std::cout << std::string(50, '=') << std::endl;
                            
                            if (!compile_and_run_exercise(exercises[i])) {
                                std::cout << "Failed to run exercise " << (i + 1) << std::endl;
                                std::cout << "Stopping execution..." << std::endl;
                                break;
                            }
                            
                            if (i < exercises.size() - 1) {
                                std::cout << "\nPress Enter to continue to the next exercise...";
                                std::cin.ignore();
                                std::cin.get();
                            }
                        }
                        std::cout << "\nAll exercises completed!" << std::endl;
                    }
                } else if (choice == static_cast<int>(exercises.size()) + 2) {
                    // Help
                    display_help();
                } else if (choice == static_cast<int>(exercises.size()) + 3) {
                    // About
                    display_about();
                }
                
                pause_execution();
        }
    }
    
    return 0;
}

std::vector<Exercise> initialize_exercises() {
    std::vector<Exercise> exercises = {
        {1, "exercises/01_hello_world.cpp", "Hello World", 
         "Basic program structure, include statements, main function, and simple output"},
        
        {2, "exercises/02_variables_datatypes.cpp", "Variables and Data Types", 
         "Integer, floating-point, character, boolean types, and variable declaration"},
        
        {3, "exercises/03_input_output.cpp", "Input and Output", 
         "Using cin/cout, stream manipulators, and basic formatting"},
        
        {4, "exercises/04_arithmetic_operators.cpp", "Arithmetic Operators", 
         "Basic arithmetic, assignment operators, increment/decrement, and precedence"},
        
        {5, "exercises/05_conditional_statements.cpp", "Conditional Statements", 
         "if/else statements, comparison operators, logical operators, and switch statements"},
        
        {6, "exercises/06_loops.cpp", "Loops", 
         "for loops, while loops, do-while loops, nested loops, and loop control"},
        
        {7, "exercises/07_functions.cpp", "Functions", 
         "Function declaration, parameters, return values, overloading, and scope"},
        
        {8, "exercises/08_arrays.cpp", "Arrays", 
         "Array declaration, initialization, multi-dimensional arrays, and operations"},
        
        {9, "exercises/09_strings.cpp", "Strings", 
         "C-style strings, C++ string class, string operations, and manipulation"},
        
        {10, "exercises/10_pointers_references.cpp", "Pointers and References", 
          "Pointer declaration, arithmetic, references, and dynamic memory allocation"},
        
        {11, "exercises/11_classes_objects.cpp", "Classes and Objects", 
          "Class definition, constructors, member functions, and encapsulation"},
        
        {12, "exercises/12_inheritance.cpp", "Inheritance", 
          "Base and derived classes, virtual functions, polymorphism, and access specifiers"}
    };
    
    return exercises;
}

void display_welcome_message() {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "            C++ LEARNING SYSTEM" << std::endl;
    std::cout << "        Progressive Syntax Exercises" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to the interactive C++ learning system!" << std::endl;
    std::cout << "This program will guide you through fundamental C++ concepts" << std::endl;
    std::cout << "with hands-on exercises progressing from basic to advanced topics." << std::endl;
    std::cout << std::endl;
    pause_execution();
}

void display_main_menu() {
    std::vector<Exercise> exercises = initialize_exercises();
    
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "                    MAIN MENU" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
    
    std::cout << "Available Exercises:" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    for (size_t i = 0; i < exercises.size(); i++) {
        std::cout << std::setw(2) << (i + 1) << ". " 
                  << std::left << std::setw(35) << exercises[i].title << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "Additional Options:" << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << std::setw(2) << (exercises.size() + 1) << ". Run All Exercises" << std::endl;
    std::cout << std::setw(2) << (exercises.size() + 2) << ". Help" << std::endl;
    std::cout << std::setw(2) << (exercises.size() + 3) << ". About" << std::endl;
    std::cout << std::setw(2) << "0" << ". Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
}

void display_exercise_details(const Exercise& exercise) {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Exercise " << exercise.number << ": " << exercise.title << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
    std::cout << "Description:" << std::endl;
    std::cout << exercise.description << std::endl;
    std::cout << std::endl;
    std::cout << "File: " << exercise.filename << std::endl;
}

bool compile_and_run_exercise(const Exercise& exercise) {
    std::string executable_name = "exercise_" + std::to_string(exercise.number);
    std::string compile_command = "g++ -std=c++11 -o " + executable_name + " " + exercise.filename;
    std::string run_command = "./" + executable_name;
    std::string cleanup_command = "rm -f " + executable_name;
    
    std::cout << "Compiling " << exercise.filename << "..." << std::endl;
    
    // Compile the exercise
    int compile_result = system(compile_command.c_str());
    
    if (compile_result != 0) {
        std::cout << "Compilation failed!" << std::endl;
        std::cout << "Command used: " << compile_command << std::endl;
        std::cout << "Please check the source file for errors." << std::endl;
        return false;
    }
    
    std::cout << "Compilation successful! Running exercise..." << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    // Run the exercise
    int run_result = system(run_command.c_str());
    
    std::cout << std::string(50, '-') << std::endl;
    
    // Cleanup executable
    system(cleanup_command.c_str());
    
    return run_result == 0;
}

void display_help() {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "                      HELP" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
    
    std::cout << "How to use this learning system:" << std::endl;
    std::cout << std::endl;
    
    std::cout << "1. INDIVIDUAL EXERCISES:" << std::endl;
    std::cout << "   - Select any exercise number (1-12) from the main menu" << std::endl;
    std::cout << "   - Read the exercise description" << std::endl;
    std::cout << "   - Choose to compile and run the exercise" << std::endl;
    std::cout << "   - Study the output and source code" << std::endl;
    std::cout << std::endl;
    
    std::cout << "2. RUN ALL EXERCISES:" << std::endl;
    std::cout << "   - Select option 13 to run all exercises sequentially" << std::endl;
    std::cout << "   - Great for a complete overview of C++ concepts" << std::endl;
    std::cout << "   - You can pause between exercises" << std::endl;
    std::cout << std::endl;
    
    std::cout << "3. LEARNING PROGRESSION:" << std::endl;
    std::cout << "   - Start with Exercise 1 (Hello World)" << std::endl;
    std::cout << "   - Work through exercises in order" << std::endl;
    std::cout << "   - Each exercise builds on previous concepts" << std::endl;
    std::cout << "   - Experiment with the code by modifying source files" << std::endl;
    std::cout << std::endl;
    
    std::cout << "4. COMPILATION REQUIREMENTS:" << std::endl;
    std::cout << "   - g++ compiler must be installed" << std::endl;
    std::cout << "   - C++11 standard is used" << std::endl;
    std::cout << "   - All source files must be in the 'exercises/' directory" << std::endl;
    std::cout << std::endl;
    
    std::cout << "5. TROUBLESHOOTING:" << std::endl;
    std::cout << "   - If compilation fails, check for missing files" << std::endl;
    std::cout << "   - Ensure you're in the correct directory" << std::endl;
    std::cout << "   - Verify g++ is installed: 'g++ --version'" << std::endl;
    std::cout << std::endl;
    
    std::cout << "6. STUDY TIPS:" << std::endl;
    std::cout << "   - Read the source code comments carefully" << std::endl;
    std::cout << "   - Try modifying values and see how output changes" << std::endl;
    std::cout << "   - Practice writing similar programs from scratch" << std::endl;
    std::cout << "   - Don't rush - understanding is more important than speed" << std::endl;
}

void display_about() {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "                     ABOUT" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::endl;
    
    std::cout << "C++ Learning System v1.0" << std::endl;
    std::cout << std::endl;
    
    std::cout << "OVERVIEW:" << std::endl;
    std::cout << "This interactive learning system is designed to teach C++" << std::endl;
    std::cout << "programming through progressive, hands-on exercises. Each" << std::endl;
    std::cout << "exercise focuses on specific concepts and builds upon" << std::endl;
    std::cout << "previous knowledge." << std::endl;
    std::cout << std::endl;
    
    std::cout << "LEARNING PATH:" << std::endl;
    std::cout << "1. Basic Syntax (Exercises 1-4)" << std::endl;
    std::cout << "   - Hello World, variables, I/O, operators" << std::endl;
    std::cout << std::endl;
    std::cout << "2. Control Structures (Exercises 5-6)" << std::endl;
    std::cout << "   - Conditions, loops, decision making" << std::endl;
    std::cout << std::endl;
    std::cout << "3. Functions and Data Structures (Exercises 7-10)" << std::endl;
    std::cout << "   - Functions, arrays, strings, pointers" << std::endl;
    std::cout << std::endl;
    std::cout << "4. Object-Oriented Programming (Exercises 11-12)" << std::endl;
    std::cout << "   - Classes, objects, inheritance, polymorphism" << std::endl;
    std::cout << std::endl;
    
    std::cout << "FEATURES:" << std::endl;
    std::cout << "- Interactive menu-driven interface" << std::endl;
    std::cout << "- Automatic compilation and execution" << std::endl;
    std::cout << "- Detailed comments and explanations" << std::endl;
    std::cout << "- Progressive difficulty levels" << std::endl;
    std::cout << "- Practical examples and applications" << std::endl;
    std::cout << "- Error handling and validation" << std::endl;
    std::cout << std::endl;
    
    std::cout << "SYSTEM REQUIREMENTS:" << std::endl;
    std::cout << "- Linux/Unix environment" << std::endl;
    std::cout << "- g++ compiler (C++11 support)" << std::endl;
    std::cout << "- Terminal/console access" << std::endl;
    std::cout << std::endl;
    
    std::cout << "EDUCATIONAL GOALS:" << std::endl;
    std::cout << "- Master fundamental C++ syntax" << std::endl;
    std::cout << "- Understand object-oriented programming" << std::endl;
    std::cout << "- Develop problem-solving skills" << std::endl;
    std::cout << "- Build confidence in C++ programming" << std::endl;
    std::cout << "- Prepare for advanced C++ topics" << std::endl;
}

void clear_screen() {
    // Clear screen using ANSI escape codes (works on most terminals)
    std::cout << "\033[2J\033[1;1H";
}

void pause_execution() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int get_user_choice(int min_choice, int max_choice) {
    int choice;
    
    while (true) {
        std::cin >> choice;
        
        if (std::cin.fail() || choice < min_choice || choice > max_choice) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number between " 
                      << min_choice << " and " << max_choice << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

/*
Key Features of the Menu System:
1. Interactive menu-driven interface
2. Exercise descriptions and details
3. Automatic compilation and execution
4. Error handling for compilation failures
5. Option to run all exercises sequentially
6. Help system with usage instructions
7. About section with learning path information
8. Input validation and error recovery
9. Clean screen management
10. User-friendly navigation
11. Detailed system information
12. Educational guidance and tips
13. Cross-platform compatibility considerations
14. Memory-efficient exercise management
15. Extensible design for adding new exercises
*/
