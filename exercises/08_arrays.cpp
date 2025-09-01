// Exercise 08: Arrays
// This exercise demonstrates array declaration, initialization, access,
// multi-dimensional arrays, and common array operations

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>  // For sort, find, etc.

// Function prototypes for array operations
void print_array(int arr[], int size);
void print_array(double arr[], int size);
int find_maximum(int arr[], int size);
int find_minimum(int arr[], int size);
double calculate_average(int arr[], int size);
void bubble_sort(int arr[], int size);
void print_2d_array(int arr[][4], int rows, int cols);

int main() {
    std::cout << "=== C++ Arrays ===" << std::endl << std::endl;
    
    // ARRAY DECLARATION AND INITIALIZATION
    std::cout << "--- Array Declaration and Initialization ---" << std::endl;
    
    // Different ways to declare and initialize arrays
    int numbers1[5];                              // Uninitialized array
    int numbers2[5] = {10, 20, 30, 40, 50};      // Initialized with values
    int numbers3[] = {1, 2, 3, 4, 5, 6};         // Size determined by initializer
    int numbers4[10] = {1, 2, 3};                // Partially initialized (rest are 0)
    
    // Initialize all elements to same value
    int zeros[5] = {0};                           // All elements = 0
    int ones[5] = {1, 1, 1, 1, 1};               // All elements = 1
    
    std::cout << "numbers2 array: ";
    print_array(numbers2, 5);
    
    std::cout << "numbers3 array: ";
    print_array(numbers3, 6);
    
    std::cout << "numbers4 array (partially initialized): ";
    print_array(numbers4, 10);
    
    // ACCESSING ARRAY ELEMENTS
    std::cout << "\n--- Accessing Array Elements ---" << std::endl;
    
    int scores[5] = {85, 92, 78, 96, 88};
    
    std::cout << "Individual array elements:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "scores[" << i << "] = " << scores[i] << std::endl;
    }
    
    // Modifying array elements
    std::cout << "\nModifying array elements:" << std::endl;
    scores[0] = 90;  // Change first element
    scores[4] = 95;  // Change last element
    
    std::cout << "After modification: ";
    print_array(scores, 5);
    
    // ARRAY OPERATIONS
    std::cout << "\n--- Array Operations ---" << std::endl;
    
    int data[] = {45, 23, 67, 12, 89, 34, 56};
    int size = sizeof(data) / sizeof(data[0]);  // Calculate array size
    
    std::cout << "Original array: ";
    print_array(data, size);
    
    std::cout << "Array size: " << size << " elements" << std::endl;
    std::cout << "Maximum value: " << find_maximum(data, size) << std::endl;
    std::cout << "Minimum value: " << find_minimum(data, size) << std::endl;
    std::cout << "Average value: " << std::fixed << std::setprecision(2) 
              << calculate_average(data, size) << std::endl;
    
    // SORTING ARRAYS
    std::cout << "\n--- Sorting Arrays ---" << std::endl;
    
    int unsorted[] = {64, 34, 25, 12, 22, 11, 90};
    int sort_size = sizeof(unsorted) / sizeof(unsorted[0]);
    
    std::cout << "Before sorting: ";
    print_array(unsorted, sort_size);
    
    bubble_sort(unsorted, sort_size);
    std::cout << "After bubble sort: ";
    print_array(unsorted, sort_size);
    
    // Using STL sort
    int stl_array[] = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Before STL sort: ";
    print_array(stl_array, sort_size);
    
    std::sort(stl_array, stl_array + sort_size);
    std::cout << "After STL sort: ";
    print_array(stl_array, sort_size);
    
    // SEARCHING IN ARRAYS
    std::cout << "\n--- Searching in Arrays ---" << std::endl;
    
    int search_array[] = {10, 25, 30, 45, 60, 75, 90};
    int search_size = sizeof(search_array) / sizeof(search_array[0]);
    int target = 45;
    
    std::cout << "Array: ";
    print_array(search_array, search_size);
    
    // Linear search
    bool found = false;
    int position = -1;
    for (int i = 0; i < search_size; i++) {
        if (search_array[i] == target) {
            found = true;
            position = i;
            break;
        }
    }
    
    if (found) {
        std::cout << "Element " << target << " found at index " << position << std::endl;
    } else {
        std::cout << "Element " << target << " not found" << std::endl;
    }
    
    // MULTI-DIMENSIONAL ARRAYS
    std::cout << "\n--- Multi-Dimensional Arrays ---" << std::endl;
    
    // 2D array declaration and initialization
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    std::cout << "2D Array (3x4 matrix):" << std::endl;
    print_2d_array(matrix, 3, 4);
    
    // Accessing 2D array elements
    std::cout << "\nAccessing individual elements:" << std::endl;
    std::cout << "matrix[0][0] = " << matrix[0][0] << std::endl;
    std::cout << "matrix[1][2] = " << matrix[1][2] << std::endl;
    std::cout << "matrix[2][3] = " << matrix[2][3] << std::endl;
    
    // Sum of all elements in 2D array
    int sum = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            sum += matrix[row][col];
        }
    }
    std::cout << "Sum of all elements: " << sum << std::endl;
    
    // CHARACTER ARRAYS (C-style strings)
    std::cout << "\n--- Character Arrays ---" << std::endl;
    
    char greeting[] = "Hello, World!";
    char name[20] = "Alice";
    char message[100];
    
    std::cout << "Greeting: " << greeting << std::endl;
    std::cout << "Name: " << name << std::endl;
    
    // String operations with character arrays
    std::cout << "Length of greeting: " << strlen(greeting) << std::endl;
    
    strcpy(message, "Welcome, ");
    strcat(message, name);
    strcat(message, "!");
    std::cout << "Message: " << message << std::endl;
    
    // PRACTICAL EXAMPLES
    std::cout << "\n--- Practical Examples ---" << std::endl;
    
    // Grade book example
    std::cout << "Grade Book Example:" << std::endl;
    std::string student_names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    int student_grades[] = {85, 92, 78, 96, 88};
    int num_students = 5;
    
    std::cout << std::left << std::setw(12) << "Student" << std::setw(8) << "Grade" << std::endl;
    std::cout << std::setfill('-') << std::setw(20) << "" << std::setfill(' ') << std::endl;
    
    for (int i = 0; i < num_students; i++) {
        std::cout << std::setw(12) << student_names[i] << std::setw(8) << student_grades[i] << std::endl;
    }
    
    double class_average = calculate_average(student_grades, num_students);
    std::cout << "\nClass average: " << std::fixed << std::setprecision(1) << class_average << std::endl;
    
    // Temperature tracking example
    std::cout << "\nTemperature Tracking Example:" << std::endl;
    double daily_temps[7] = {72.5, 75.0, 73.8, 76.2, 74.5, 71.0, 69.8};
    std::string days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    
    std::cout << "Daily temperatures:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << days[i] << ": " << std::fixed << std::setprecision(1) 
                  << daily_temps[i] << "°F" << std::endl;
    }
    
    // Find hottest and coldest days
    int hottest_day = 0, coldest_day = 0;
    for (int i = 1; i < 7; i++) {
        if (daily_temps[i] > daily_temps[hottest_day]) {
            hottest_day = i;
        }
        if (daily_temps[i] < daily_temps[coldest_day]) {
            coldest_day = i;
        }
    }
    
    std::cout << "Hottest day: " << days[hottest_day] << " (" << daily_temps[hottest_day] << "°F)" << std::endl;
    std::cout << "Coldest day: " << days[coldest_day] << " (" << daily_temps[coldest_day] << "°F)" << std::endl;
    
    // Inventory system example
    std::cout << "\nInventory System Example:" << std::endl;
    std::string products[] = {"Laptop", "Mouse", "Keyboard", "Monitor", "Speakers"};
    int quantities[] = {15, 50, 30, 8, 25};
    double prices[] = {999.99, 29.99, 79.99, 249.99, 59.99};
    
    std::cout << std::left << std::setw(12) << "Product" << std::setw(10) << "Quantity" 
              << std::setw(10) << "Price" << std::setw(12) << "Total Value" << std::endl;
    std::cout << std::setfill('-') << std::setw(44) << "" << std::setfill(' ') << std::endl;
    
    double total_inventory_value = 0;
    for (int i = 0; i < 5; i++) {
        double item_value = quantities[i] * prices[i];
        total_inventory_value += item_value;
        
        std::cout << std::setw(12) << products[i] 
                  << std::setw(10) << quantities[i]
                  << "$" << std::setw(9) << std::fixed << std::setprecision(2) << prices[i]
                  << "$" << std::setw(11) << item_value << std::endl;
    }
    
    std::cout << "\nTotal inventory value: $" << total_inventory_value << std::endl;
    
    return 0;
}

// Function definitions for array operations

void print_array(int arr[], int size) {
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

void print_array(double arr[], int size) {
    std::cout << "{ ";
    for (int i = 0; i < size; i++) {
        std::cout << std::fixed << std::setprecision(1) << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

int find_maximum(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int find_minimum(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double calculate_average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_2d_array(int arr[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        std::cout << "[ ";
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(3) << arr[i][j];
            if (j < cols - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
}

/*
Key Concepts Demonstrated:
1. Array declaration and initialization
2. Accessing and modifying array elements
3. Calculating array size using sizeof
4. Array traversal with loops
5. Common array operations (find max/min, average)
6. Sorting algorithms (bubble sort)
7. Using STL algorithms with arrays
8. Searching in arrays (linear search)
9. Multi-dimensional arrays (2D arrays)
10. Character arrays (C-style strings)
11. Passing arrays to functions
12. Function overloading with arrays
13. Practical applications (gradebook, inventory, etc.)
14. String operations with character arrays
15. Array bounds and memory considerations
*/
