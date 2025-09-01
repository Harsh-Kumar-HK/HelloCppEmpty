// Exercise 10: Pointers and References
// This exercise demonstrates pointer declaration, usage, arithmetic,
// references, dynamic memory allocation, and pointer applications

#include <iostream>
#include <string>
#include <iomanip>

// Function prototypes
void demonstrate_basic_pointers();
void demonstrate_pointer_arithmetic();
void demonstrate_references();
void demonstrate_dynamic_memory();
void demonstrate_function_pointers();
void swap_by_pointers(int* a, int* b);
void swap_by_references(int& a, int& b);
int* find_maximum(int arr[], int size);
void print_array_with_pointers(int* arr, int size);

int main() {
    std::cout << "=== C++ Pointers and References ===" << std::endl << std::endl;
    
    demonstrate_basic_pointers();
    demonstrate_pointer_arithmetic();
    demonstrate_references();
    demonstrate_dynamic_memory();
    demonstrate_function_pointers();
    
    return 0;
}

void demonstrate_basic_pointers() {
    std::cout << "--- Basic Pointers ---" << std::endl;
    
    // Basic pointer declaration and usage
    int number = 42;
    int* ptr = &number;  // ptr points to the address of number
    
    std::cout << "Variable number: " << number << std::endl;
    std::cout << "Address of number: " << &number << std::endl;
    std::cout << "Pointer ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;
    std::cout << "Address of ptr itself: " << &ptr << std::endl;
    
    // Modifying value through pointer
    *ptr = 100;
    std::cout << "\nAfter *ptr = 100:" << std::endl;
    std::cout << "number = " << number << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    
    // Null pointers
    int* null_ptr = nullptr;  // C++11 way
    int* old_null_ptr = NULL; // C-style (still valid)
    
    std::cout << "\nNull pointers:" << std::endl;
    std::cout << "null_ptr: " << null_ptr << std::endl;
    std::cout << "old_null_ptr: " << old_null_ptr << std::endl;
    
    // Checking for null before dereferencing
    if (null_ptr != nullptr) {
        std::cout << "*null_ptr = " << *null_ptr << std::endl;
    } else {
        std::cout << "null_ptr is null, cannot dereference" << std::endl;
    }
    
    // Multiple pointers to same variable
    int value = 25;
    int* ptr1 = &value;
    int* ptr2 = &value;
    
    std::cout << "\nMultiple pointers to same variable:" << std::endl;
    std::cout << "value = " << value << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    
    *ptr1 = 50;
    std::cout << "After *ptr1 = 50:" << std::endl;
    std::cout << "value = " << value << std::endl;
    std::cout << "*ptr2 = " << *ptr2 << std::endl;
    
    // Pointer to pointer
    int original = 123;
    int* single_ptr = &original;
    int** double_ptr = &single_ptr;
    
    std::cout << "\nPointer to pointer:" << std::endl;
    std::cout << "original = " << original << std::endl;
    std::cout << "*single_ptr = " << *single_ptr << std::endl;
    std::cout << "**double_ptr = " << **double_ptr << std::endl;
    
    std::cout << std::endl;
}

void demonstrate_pointer_arithmetic() {
    std::cout << "--- Pointer Arithmetic ---" << std::endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // Points to first element
    
    std::cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nPointer arithmetic:" << std::endl;
    std::cout << "ptr points to: " << *ptr << std::endl;
    std::cout << "ptr + 1 points to: " << *(ptr + 1) << std::endl;
    std::cout << "ptr + 2 points to: " << *(ptr + 2) << std::endl;
    
    // Incrementing pointer
    std::cout << "\nIncrementing pointer:" << std::endl;
    ptr = numbers;  // Reset to beginning
    for (int i = 0; i < 5; i++) {
        std::cout << "Element " << i << ": " << *ptr << std::endl;
        ptr++;  // Move to next element
    }
    
    // Pointer subtraction
    int* start = numbers;
    int* end = numbers + 4;
    std::cout << "\nPointer subtraction:" << std::endl;
    std::cout << "Distance between start and end: " << (end - start) << std::endl;
    
    // Array name as pointer
    std::cout << "\nArray name as pointer:" << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "*numbers = " << *numbers << std::endl;
    std::cout << "numbers[2] = " << numbers[2] << std::endl;
    std::cout << "*(numbers + 2) = " << *(numbers + 2) << std::endl;
    
    // Using pointers to traverse array
    std::cout << "\nTraversing array with pointers:" << std::endl;
    print_array_with_pointers(numbers, 5);
    
    std::cout << std::endl;
}

void demonstrate_references() {
    std::cout << "--- References ---" << std::endl;
    
    // Basic reference usage
    int original = 100;
    int& ref = original;  // ref is an alias for original
    
    std::cout << "original = " << original << std::endl;
    std::cout << "ref = " << ref << std::endl;
    std::cout << "Address of original: " << &original << std::endl;
    std::cout << "Address of ref: " << &ref << std::endl;
    
    // Modifying through reference
    ref = 200;
    std::cout << "\nAfter ref = 200:" << std::endl;
    std::cout << "original = " << original << std::endl;
    std::cout << "ref = " << ref << std::endl;
    
    // References vs Pointers
    std::cout << "\n--- References vs Pointers ---" << std::endl;
    
    int a = 10, b = 20;
    
    // Using pointers for swapping
    std::cout << "Before swap (pointers): a = " << a << ", b = " << b << std::endl;
    swap_by_pointers(&a, &b);
    std::cout << "After swap (pointers): a = " << a << ", b = " << b << std::endl;
    
    // Using references for swapping
    std::cout << "Before swap (references): a = " << a << ", b = " << b << std::endl;
    swap_by_references(a, b);
    std::cout << "After swap (references): a = " << a << ", b = " << b << std::endl;
    
    // Const references
    const int constant_value = 500;
    const int& const_ref = constant_value;
    // const_ref = 600;  // This would cause a compilation error
    
    std::cout << "\nConst reference: " << const_ref << std::endl;
    
    // Reference to array elements
    int arr[] = {1, 2, 3, 4, 5};
    int& first_element = arr[0];
    int& last_element = arr[4];
    
    std::cout << "\nReference to array elements:" << std::endl;
    std::cout << "first_element = " << first_element << std::endl;
    std::cout << "last_element = " << last_element << std::endl;
    
    first_element = 100;
    last_element = 500;
    
    std::cout << "After modification through references:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    
    std::cout << std::endl;
}

void demonstrate_dynamic_memory() {
    std::cout << "--- Dynamic Memory Allocation ---" << std::endl;
    
    // Single variable allocation
    int* dynamic_int = new int(42);  // Allocate and initialize
    std::cout << "Dynamic integer: " << *dynamic_int << std::endl;
    delete dynamic_int;  // Free memory
    dynamic_int = nullptr;  // Good practice
    
    // Array allocation
    int size = 5;
    int* dynamic_array = new int[size];
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        dynamic_array[i] = (i + 1) * 10;
    }
    
    std::cout << "\nDynamic array: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamic_array[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] dynamic_array;  // Free array memory
    dynamic_array = nullptr;
    
    // Dynamic 2D array
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // Initialize matrix
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    std::cout << "\nDynamic 2D array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Free 2D array memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    
    // Memory leak demonstration (commented out to avoid actual leak)
    /*
    int* leak_pointer = new int(999);
    // Forgot to call delete - this would cause a memory leak!
    */
    
    std::cout << std::endl;
}

void demonstrate_function_pointers() {
    std::cout << "--- Function Pointers and Practical Examples ---" << std::endl;
    
    // Working with arrays using pointers
    int test_array[] = {45, 23, 67, 12, 89, 34, 56, 78, 91, 25};
    int array_size = sizeof(test_array) / sizeof(test_array[0]);
    
    std::cout << "Test array: ";
    print_array_with_pointers(test_array, array_size);
    
    // Find maximum using pointers
    int* max_ptr = find_maximum(test_array, array_size);
    std::cout << "Maximum value: " << *max_ptr << std::endl;
    std::cout << "Position of maximum: " << (max_ptr - test_array) << std::endl;
    
    // String manipulation with pointers
    char message[] = "Hello, World!";
    char* char_ptr = message;
    
    std::cout << "\nString manipulation with pointers:" << std::endl;
    std::cout << "Original string: " << message << std::endl;
    
    // Count characters using pointer
    int char_count = 0;
    while (*char_ptr != '\0') {
        char_count++;
        char_ptr++;
    }
    std::cout << "Character count: " << char_count << std::endl;
    
    // Convert to uppercase using pointer
    char_ptr = message;  // Reset pointer
    while (*char_ptr != '\0') {
        if (*char_ptr >= 'a' && *char_ptr <= 'z') {
            *char_ptr = *char_ptr - 32;  // Convert to uppercase
        }
        char_ptr++;
    }
    std::cout << "After uppercase conversion: " << message << std::endl;
    
    // Practical example: Dynamic student grades
    std::cout << "\n--- Practical Example: Dynamic Student Grades ---" << std::endl;
    
    int num_students;
    std::cout << "Enter number of students: ";
    std::cin >> num_students;
    
    // Dynamically allocate array for grades
    double* grades = new double[num_students];
    
    // Input grades
    for (int i = 0; i < num_students; i++) {
        std::cout << "Enter grade for student " << (i + 1) << ": ";
        std::cin >> grades[i];
    }
    
    // Calculate average using pointer arithmetic
    double sum = 0;
    double* grade_ptr = grades;
    for (int i = 0; i < num_students; i++) {
        sum += *grade_ptr;
        grade_ptr++;
    }
    double average = sum / num_students;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average grade: " << average << std::endl;
    
    // Find highest and lowest grades
    double* highest = grades;
    double* lowest = grades;
    
    for (int i = 1; i < num_students; i++) {
        if (grades[i] > *highest) {
            highest = &grades[i];
        }
        if (grades[i] < *lowest) {
            lowest = &grades[i];
        }
    }
    
    std::cout << "Highest grade: " << *highest << std::endl;
    std::cout << "Lowest grade: " << *lowest << std::endl;
    
    // Clean up memory
    delete[] grades;
    grades = nullptr;
    
    std::cout << std::endl;
}

// Helper function implementations

void swap_by_pointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_by_references(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int* find_maximum(int arr[], int size) {
    int* max_ptr = arr;  // Point to first element
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max_ptr) {
            max_ptr = &arr[i];
        }
    }
    
    return max_ptr;
}

void print_array_with_pointers(int* arr, int size) {
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i);
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

/*
Key Concepts Demonstrated:
1. Basic pointer declaration and usage
2. Address-of operator (&) and dereference operator (*)
3. Null pointers and nullptr (C++11)
4. Pointer arithmetic and array traversal
5. Pointers vs array names
6. References as aliases to variables
7. Pass by pointer vs pass by reference
8. Const pointers and const references
9. Dynamic memory allocation with new/delete
10. Memory management and avoiding memory leaks
11. 2D dynamic arrays
12. Pointer-to-pointer (double pointers)
13. String manipulation with char pointers
14. Practical applications of pointers
15. Function parameters using pointers and references
16. Array manipulation using pointer arithmetic
*/
