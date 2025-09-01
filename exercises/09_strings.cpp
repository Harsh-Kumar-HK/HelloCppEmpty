// Exercise 09: Strings
// This exercise demonstrates C-style strings (char arrays) and C++ string class,
// string operations, manipulation, and common string algorithms

#include <iostream>
#include <string>
#include <cstring>    // For C-style string functions
#include <cctype>     // For character classification functions
#include <algorithm>  // For string algorithms
#include <sstream>    // For string streams
#include <iomanip>

// Function prototypes
void demonstrate_cstring_functions();
void demonstrate_string_class();
void demonstrate_string_operations();
void demonstrate_string_algorithms();
std::string reverse_string(const std::string& str);
bool is_palindrome(const std::string& str);
int count_words(const std::string& str);
std::string to_title_case(const std::string& str);

int main() {
    std::cout << "=== C++ Strings ===" << std::endl << std::endl;
    
    // C-STYLE STRINGS (CHARACTER ARRAYS)
    std::cout << "--- C-Style Strings ---" << std::endl;
    
    // Declaration and initialization
    char greeting1[] = "Hello, World!";           // Array size determined automatically
    char greeting2[20] = "Hello";                 // Fixed size array
    char greeting3[20];                           // Uninitialized
    
    // Initialize using strcpy
    strcpy(greeting3, "Welcome!");
    
    std::cout << "greeting1: " << greeting1 << std::endl;
    std::cout << "greeting2: " << greeting2 << std::endl;
    std::cout << "greeting3: " << greeting3 << std::endl;
    
    // String length
    std::cout << "Length of greeting1: " << strlen(greeting1) << std::endl;
    std::cout << "Size of greeting1 array: " << sizeof(greeting1) << std::endl;
    
    demonstrate_cstring_functions();
    
    // C++ STRING CLASS
    std::cout << "\n--- C++ String Class ---" << std::endl;
    
    // Declaration and initialization
    std::string str1;                             // Empty string
    std::string str2 = "Hello";                   // Direct initialization
    std::string str3("World");                    // Constructor initialization
    std::string str4(str2);                       // Copy constructor
    std::string str5(5, 'A');                     // Fill constructor: "AAAAA"
    
    std::cout << "str1: '" << str1 << "' (empty)" << std::endl;
    std::cout << "str2: '" << str2 << "'" << std::endl;
    std::cout << "str3: '" << str3 << "'" << std::endl;
    std::cout << "str4: '" << str4 << "' (copy of str2)" << std::endl;
    std::cout << "str5: '" << str5 << "' (5 A's)" << std::endl;
    
    demonstrate_string_class();
    demonstrate_string_operations();
    demonstrate_string_algorithms();
    
    // PRACTICAL EXAMPLES
    std::cout << "\n--- Practical Examples ---" << std::endl;
    
    // User input processing
    std::cout << "Enter your full name: ";
    std::string full_name;
    std::getline(std::cin, full_name);
    
    std::cout << "You entered: '" << full_name << "'" << std::endl;
    std::cout << "Length: " << full_name.length() << " characters" << std::endl;
    std::cout << "Word count: " << count_words(full_name) << " words" << std::endl;
    std::cout << "Title case: '" << to_title_case(full_name) << "'" << std::endl;
    std::cout << "Reversed: '" << reverse_string(full_name) << "'" << std::endl;
    
    // Email validation (simple)
    std::cout << "\nEmail validation example:" << std::endl;
    std::string email;
    std::cout << "Enter an email address: ";
    std::cin >> email;
    
    bool has_at = email.find('@') != std::string::npos;
    bool has_dot = email.find('.') != std::string::npos;
    bool valid_length = email.length() >= 5;
    
    if (has_at && has_dot && valid_length) {
        std::cout << "Email appears to be valid." << std::endl;
    } else {
        std::cout << "Email appears to be invalid." << std::endl;
        if (!has_at) std::cout << "  Missing '@' symbol" << std::endl;
        if (!has_dot) std::cout << "  Missing '.' symbol" << std::endl;
        if (!valid_length) std::cout << "  Too short" << std::endl;
    }
    
    // Password strength checker
    std::cout << "\nPassword strength checker:" << std::endl;
    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;
    
    bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
    
    for (char c : password) {
        if (std::isupper(c)) has_upper = true;
        if (std::islower(c)) has_lower = true;
        if (std::isdigit(c)) has_digit = true;
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%') has_special = true;
    }
    
    int strength_score = 0;
    if (password.length() >= 8) strength_score++;
    if (has_upper) strength_score++;
    if (has_lower) strength_score++;
    if (has_digit) strength_score++;
    if (has_special) strength_score++;
    
    std::cout << "Password strength: ";
    if (strength_score >= 4) std::cout << "Strong";
    else if (strength_score >= 2) std::cout << "Medium";
    else std::cout << "Weak";
    std::cout << " (" << strength_score << "/5)" << std::endl;
    
    // Text statistics
    std::cout << "\nText statistics example:" << std::endl;
    std::string text = "The quick brown fox jumps over the lazy dog. This sentence contains every letter of the alphabet!";
    
    std::cout << "Text: " << text << std::endl;
    std::cout << "Length: " << text.length() << " characters" << std::endl;
    std::cout << "Words: " << count_words(text) << std::endl;
    
    // Count vowels and consonants
    int vowels = 0, consonants = 0;
    for (char c : text) {
        if (std::isalpha(c)) {
            char lower_c = std::tolower(c);
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || 
                lower_c == 'o' || lower_c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    std::cout << "Vowels: " << vowels << std::endl;
    std::cout << "Consonants: " << consonants << std::endl;
    
    // Check if palindrome
    std::string test_palindrome = "racecar";
    std::cout << "\nPalindrome test:" << std::endl;
    std::cout << "'" << test_palindrome << "' is " 
              << (is_palindrome(test_palindrome) ? "a palindrome" : "not a palindrome") << std::endl;
    
    return 0;
}

void demonstrate_cstring_functions() {
    std::cout << "\n--- C-Style String Functions ---" << std::endl;
    
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];
    
    // String copy
    strcpy(str3, str1);
    std::cout << "After strcpy(str3, str1): str3 = '" << str3 << "'" << std::endl;
    
    // String concatenation
    strcat(str1, ", ");
    strcat(str1, str2);
    strcat(str1, "!");
    std::cout << "After concatenation: str1 = '" << str1 << "'" << std::endl;
    
    // String comparison
    char test1[] = "Apple";
    char test2[] = "Banana";
    char test3[] = "Apple";
    
    std::cout << "strcmp(\"" << test1 << "\", \"" << test2 << "\") = " << strcmp(test1, test2) << std::endl;
    std::cout << "strcmp(\"" << test1 << "\", \"" << test3 << "\") = " << strcmp(test1, test3) << std::endl;
    
    // String search
    char sentence[] = "The quick brown fox";
    char* found = strstr(sentence, "quick");
    if (found) {
        std::cout << "Found 'quick' in: '" << sentence << "'" << std::endl;
    }
}

void demonstrate_string_class() {
    std::cout << "\n--- C++ String Class Operations ---" << std::endl;
    
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    // String concatenation
    std::string str3 = str1 + ", " + str2 + "!";
    std::cout << "Concatenation: " << str3 << std::endl;
    
    // String assignment
    std::string str4;
    str4 = str3;
    std::cout << "Assignment: str4 = " << str4 << std::endl;
    
    // String comparison
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 < str2: " << (str1 < str2) << std::endl;
    
    // String length and size
    std::cout << "str3.length(): " << str3.length() << std::endl;
    std::cout << "str3.size(): " << str3.size() << std::endl;
    std::cout << "str3.empty(): " << str3.empty() << std::endl;
    
    // Accessing characters
    std::cout << "str3[0]: '" << str3[0] << "'" << std::endl;
    std::cout << "str3.at(1): '" << str3.at(1) << "'" << std::endl;
    std::cout << "str3.front(): '" << str3.front() << "'" << std::endl;
    std::cout << "str3.back(): '" << str3.back() << "'" << std::endl;
}

void demonstrate_string_operations() {
    std::cout << "\n--- String Operations ---" << std::endl;
    
    std::string text = "The quick brown fox jumps over the lazy dog";
    std::cout << "Original: " << text << std::endl;
    
    // Substring
    std::string substring = text.substr(4, 5);  // Starting at index 4, length 5
    std::cout << "Substring (4, 5): '" << substring << "'" << std::endl;
    
    // Find
    size_t pos = text.find("fox");
    if (pos != std::string::npos) {
        std::cout << "Found 'fox' at position: " << pos << std::endl;
    }
    
    // Replace
    std::string modified = text;
    modified.replace(pos, 3, "cat");  // Replace "fox" with "cat"
    std::cout << "After replace: " << modified << std::endl;
    
    // Insert
    std::string inserted = text;
    inserted.insert(0, "Note: ");
    std::cout << "After insert: " << inserted << std::endl;
    
    // Erase
    std::string erased = text;
    erased.erase(0, 4);  // Remove first 4 characters
    std::cout << "After erase: " << erased << std::endl;
    
    // Append
    std::string appended = text;
    appended.append(" and cats");
    std::cout << "After append: " << appended << std::endl;
}

void demonstrate_string_algorithms() {
    std::cout << "\n--- String Algorithms ---" << std::endl;
    
    std::string text = "Hello World Programming";
    std::cout << "Original: " << text << std::endl;
    
    // Convert to uppercase
    std::string upper_text = text;
    std::transform(upper_text.begin(), upper_text.end(), upper_text.begin(), ::toupper);
    std::cout << "Uppercase: " << upper_text << std::endl;
    
    // Convert to lowercase
    std::string lower_text = text;
    std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
    std::cout << "Lowercase: " << lower_text << std::endl;
    
    // Reverse
    std::string reversed = text;
    std::reverse(reversed.begin(), reversed.end());
    std::cout << "Reversed: " << reversed << std::endl;
    
    // Count occurrences of a character
    int count_l = std::count(text.begin(), text.end(), 'l');
    std::cout << "Count of 'l': " << count_l << std::endl;
}

std::string reverse_string(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

bool is_palindrome(const std::string& str) {
    std::string clean_str;
    for (char c : str) {
        if (std::isalnum(c)) {
            clean_str += std::tolower(c);
        }
    }
    
    std::string reversed = clean_str;
    std::reverse(reversed.begin(), reversed.end());
    
    return clean_str == reversed;
}

int count_words(const std::string& str) {
    if (str.empty()) return 0;
    
    int word_count = 0;
    bool in_word = false;
    
    for (char c : str) {
        if (std::isspace(c)) {
            in_word = false;
        } else {
            if (!in_word) {
                word_count++;
                in_word = true;
            }
        }
    }
    
    return word_count;
}

std::string to_title_case(const std::string& str) {
    std::string result = str;
    bool capitalize_next = true;
    
    for (char& c : result) {
        if (std::isspace(c)) {
            capitalize_next = true;
        } else if (capitalize_next && std::isalpha(c)) {
            c = std::toupper(c);
            capitalize_next = false;
        } else {
            c = std::tolower(c);
        }
    }
    
    return result;
}

/*
Key Concepts Demonstrated:
1. C-style strings (character arrays) vs C++ string class
2. String declaration and initialization methods
3. C-style string functions (strcpy, strcat, strcmp, strlen, strstr)
4. C++ string class operations (concatenation, comparison, assignment)
5. String access methods ([], at(), front(), back())
6. String manipulation (substr, find, replace, insert, erase, append)
7. String algorithms using STL (transform, reverse, count)
8. Character classification functions (isalpha, isdigit, isspace, etc.)
9. Case conversion (toupper, tolower)
10. String streams and parsing
11. Practical applications (validation, text processing, algorithms)
12. Custom string functions (palindrome check, word count, etc.)
13. String searching and pattern matching
14. Text statistics and analysis
15. Input handling with getline for strings with spaces
*/
