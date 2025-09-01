// Exercise 11: Classes and Objects
// This exercise demonstrates object-oriented programming in C++
// including class definition, constructors, destructors, member functions, and encapsulation

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// BASIC CLASS DEFINITION
class Rectangle {
private:
    double width;
    double height;
    
public:
    // Default constructor
    Rectangle() {
        width = 1.0;
        height = 1.0;
        std::cout << "Rectangle created with default constructor" << std::endl;
    }
    
    // Parameterized constructor
    Rectangle(double w, double h) {
        width = w;
        height = h;
        std::cout << "Rectangle created with parameters: " << w << " x " << h << std::endl;
    }
    
    // Copy constructor
    Rectangle(const Rectangle& other) {
        width = other.width;
        height = other.height;
        std::cout << "Rectangle copied" << std::endl;
    }
    
    // Destructor
    ~Rectangle() {
        std::cout << "Rectangle destroyed" << std::endl;
    }
    
    // Member functions (methods)
    double calculateArea() const {
        return width * height;
    }
    
    double calculatePerimeter() const {
        return 2 * (width + height);
    }
    
    // Getter methods
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    // Setter methods
    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            std::cout << "Width must be positive!" << std::endl;
        }
    }
    
    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            std::cout << "Height must be positive!" << std::endl;
        }
    }
    
    // Display method
    void display() const {
        std::cout << "Rectangle: " << width << " x " << height 
                  << " (Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << ")" << std::endl;
    }
    
    // Static member function
    static void showClassInfo() {
        std::cout << "This is the Rectangle class for geometric calculations" << std::endl;
    }
};

// STUDENT CLASS - More complex example
class Student {
private:
    std::string name;
    int student_id;
    std::vector<double> grades;
    static int total_students;  // Static member variable
    
public:
    // Constructor
    Student(const std::string& student_name, int id) : name(student_name), student_id(id) {
        total_students++;
        std::cout << "Student " << name << " (ID: " << student_id << ") created" << std::endl;
    }
    
    // Destructor
    ~Student() {
        total_students--;
        std::cout << "Student " << name << " destroyed" << std::endl;
    }
    
    // Add a grade
    void addGrade(double grade) {
        if (grade >= 0 && grade <= 100) {
            grades.push_back(grade);
            std::cout << "Grade " << grade << " added for " << name << std::endl;
        } else {
            std::cout << "Invalid grade! Must be between 0 and 100." << std::endl;
        }
    }
    
    // Calculate average grade
    double calculateAverage() const {
        if (grades.empty()) {
            return 0.0;
        }
        
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
    
    // Get letter grade based on average
    char getLetterGrade() const {
        double avg = calculateAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
    
    // Display student information
    void displayInfo() const {
        std::cout << "\n--- Student Information ---" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "ID: " << student_id << std::endl;
        std::cout << "Grades: ";
        for (size_t i = 0; i < grades.size(); i++) {
            std::cout << grades[i];
            if (i < grades.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Average: " << calculateAverage() << std::endl;
        std::cout << "Letter Grade: " << getLetterGrade() << std::endl;
    }
    
    // Getters
    std::string getName() const { return name; }
    int getStudentId() const { return student_id; }
    
    // Static member function
    static int getTotalStudents() {
        return total_students;
    }
};

// Initialize static member
int Student::total_students = 0;

// BANK ACCOUNT CLASS - Practical example
class BankAccount {
private:
    std::string account_holder;
    std::string account_number;
    double balance;
    std::vector<std::string> transaction_history;
    
    // Private helper method
    void addTransaction(const std::string& transaction) {
        transaction_history.push_back(transaction);
    }
    
public:
    // Constructor
    BankAccount(const std::string& holder, const std::string& account_num, double initial_balance = 0.0) {
        account_holder = holder;
        account_number = account_num;
        balance = initial_balance;
        addTransaction("Account opened with balance: $" + std::to_string(initial_balance));
        std::cout << "Bank account created for " << holder << std::endl;
    }
    
    // Destructor
    ~BankAccount() {
        std::cout << "Bank account for " << account_holder << " closed" << std::endl;
    }
    
    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposit: +$" + std::to_string(amount));
            std::cout << "Deposited $" << std::fixed << std::setprecision(2) << amount << std::endl;
        } else {
            std::cout << "Deposit amount must be positive!" << std::endl;
        }
    }
    
    // Withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction("Withdrawal: -$" + std::to_string(amount));
            std::cout << "Withdrew $" << std::fixed << std::setprecision(2) << amount << std::endl;
            return true;
        } else if (amount > balance) {
            std::cout << "Insufficient funds! Current balance: $" << balance << std::endl;
            return false;
        } else {
            std::cout << "Withdrawal amount must be positive!" << std::endl;
            return false;
        }
    }
    
    // Transfer money to another account
    bool transfer(BankAccount& target_account, double amount) {
        if (withdraw(amount)) {
            target_account.deposit(amount);
            addTransaction("Transfer to " + target_account.getAccountNumber() + ": -$" + std::to_string(amount));
            target_account.addTransaction("Transfer from " + account_number + ": +$" + std::to_string(amount));
            return true;
        }
        return false;
    }
    
    // Display account information
    void displayAccountInfo() const {
        std::cout << "\n--- Account Information ---" << std::endl;
        std::cout << "Account Holder: " << account_holder << std::endl;
        std::cout << "Account Number: " << account_number << std::endl;
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
    
    // Display transaction history
    void displayTransactionHistory() const {
        std::cout << "\n--- Transaction History ---" << std::endl;
        for (size_t i = 0; i < transaction_history.size(); i++) {
            std::cout << (i + 1) << ". " << transaction_history[i] << std::endl;
        }
    }
    
    // Getters
    double getBalance() const { return balance; }
    std::string getAccountHolder() const { return account_holder; }
    std::string getAccountNumber() const { return account_number; }
};

// CAR CLASS - Constructor overloading and member initialization
class Car {
private:
    std::string make;
    std::string model;
    int year;
    double mileage;
    double fuel_level;
    
public:
    // Constructor with member initialization list
    Car(const std::string& car_make, const std::string& car_model, int car_year) 
        : make(car_make), model(car_model), year(car_year), mileage(0.0), fuel_level(0.0) {
        std::cout << "Car created: " << year << " " << make << " " << model << std::endl;
    }
    
    // Constructor overloading
    Car(const std::string& car_make, const std::string& car_model, int car_year, double initial_mileage) 
        : make(car_make), model(car_model), year(car_year), mileage(initial_mileage), fuel_level(0.0) {
        std::cout << "Used car created: " << year << " " << make << " " << model 
                  << " with " << initial_mileage << " miles" << std::endl;
    }
    
    // Methods
    void addFuel(double gallons) {
        if (gallons > 0) {
            fuel_level += gallons;
            std::cout << "Added " << gallons << " gallons. Fuel level: " << fuel_level << std::endl;
        }
    }
    
    void drive(double miles) {
        if (miles > 0 && fuel_level > 0) {
            double fuel_consumption = miles / 25.0;  // Assume 25 MPG
            if (fuel_consumption <= fuel_level) {
                mileage += miles;
                fuel_level -= fuel_consumption;
                std::cout << "Drove " << miles << " miles. Total mileage: " << mileage << std::endl;
            } else {
                std::cout << "Not enough fuel to drive " << miles << " miles!" << std::endl;
            }
        }
    }
    
    void displayInfo() const {
        std::cout << "\n--- Car Information ---" << std::endl;
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Mileage: " << std::fixed << std::setprecision(1) << mileage << " miles" << std::endl;
        std::cout << "Fuel Level: " << fuel_level << " gallons" << std::endl;
    }
};

// Function prototypes
void demonstrate_basic_classes();
void demonstrate_student_class();
void demonstrate_bank_account();
void demonstrate_car_class();

int main() {
    std::cout << "=== C++ Classes and Objects ===" << std::endl << std::endl;
    
    demonstrate_basic_classes();
    demonstrate_student_class();
    demonstrate_bank_account();
    demonstrate_car_class();
    
    return 0;
}

void demonstrate_basic_classes() {
    std::cout << "--- Basic Class Demonstration ---" << std::endl;
    
    // Static member function call (no object needed)
    Rectangle::showClassInfo();
    
    // Creating objects with different constructors
    Rectangle rect1;                    // Default constructor
    Rectangle rect2(5.0, 3.0);         // Parameterized constructor
    Rectangle rect3 = rect2;            // Copy constructor
    
    std::cout << "\nRectangle objects created:" << std::endl;
    rect1.display();
    rect2.display();
    rect3.display();
    
    // Using member functions
    std::cout << "\nUsing member functions:" << std::endl;
    std::cout << "rect2 area: " << rect2.calculateArea() << std::endl;
    std::cout << "rect2 perimeter: " << rect2.calculatePerimeter() << std::endl;
    
    // Using setters and getters
    std::cout << "\nModifying rect1 using setters:" << std::endl;
    rect1.setWidth(4.0);
    rect1.setHeight(6.0);
    rect1.display();
    
    std::cout << "rect1 width: " << rect1.getWidth() << std::endl;
    std::cout << "rect1 height: " << rect1.getHeight() << std::endl;
    
    // Testing validation
    std::cout << "\nTesting validation:" << std::endl;
    rect1.setWidth(-2.0);  // Should show error message
    
    std::cout << std::endl;
}

void demonstrate_student_class() {
    std::cout << "--- Student Class Demonstration ---" << std::endl;
    
    // Creating student objects
    Student alice("Alice Johnson", 12345);
    Student bob("Bob Smith", 12346);
    
    std::cout << "\nTotal students created: " << Student::getTotalStudents() << std::endl;
    
    // Adding grades for Alice
    std::cout << "\nAdding grades for Alice:" << std::endl;
    alice.addGrade(95.0);
    alice.addGrade(87.5);
    alice.addGrade(92.0);
    alice.addGrade(88.5);
    
    // Adding grades for Bob
    std::cout << "\nAdding grades for Bob:" << std::endl;
    bob.addGrade(78.0);
    bob.addGrade(82.5);
    bob.addGrade(76.0);
    bob.addGrade(80.0);
    
    // Display student information
    alice.displayInfo();
    bob.displayInfo();
    
    // Testing invalid grade
    std::cout << "\nTesting invalid grade:" << std::endl;
    alice.addGrade(105.0);  // Should show error
    
    std::cout << "\nTotal students: " << Student::getTotalStudents() << std::endl;
    std::cout << std::endl;
}

void demonstrate_bank_account() {
    std::cout << "--- Bank Account Demonstration ---" << std::endl;
    
    // Creating bank accounts
    BankAccount checking("John Doe", "CHK-001", 1000.0);
    BankAccount savings("John Doe", "SAV-001", 5000.0);
    
    // Display initial account information
    checking.displayAccountInfo();
    savings.displayAccountInfo();
    
    // Perform some transactions
    std::cout << "\n--- Performing Transactions ---" << std::endl;
    
    checking.deposit(500.0);
    checking.withdraw(200.0);
    checking.withdraw(2000.0);  // Should fail - insufficient funds
    
    savings.deposit(1000.0);
    
    // Transfer money
    std::cout << "\nTransferring $300 from savings to checking:" << std::endl;
    savings.transfer(checking, 300.0);
    
    // Display final balances
    std::cout << "\n--- Final Account Status ---" << std::endl;
    checking.displayAccountInfo();
    savings.displayAccountInfo();
    
    // Show transaction history
    checking.displayTransactionHistory();
    savings.displayTransactionHistory();
    
    std::cout << std::endl;
}

void demonstrate_car_class() {
    std::cout << "--- Car Class Demonstration ---" << std::endl;
    
    // Creating car objects with different constructors
    Car new_car("Toyota", "Camry", 2023);
    Car used_car("Honda", "Civic", 2020, 15000.0);
    
    // Add fuel and drive
    std::cout << "\n--- Operating the new car ---" << std::endl;
    new_car.addFuel(12.0);
    new_car.drive(100.0);
    new_car.drive(200.0);
    new_car.displayInfo();
    
    std::cout << "\n--- Operating the used car ---" << std::endl;
    used_car.addFuel(15.0);
    used_car.drive(150.0);
    used_car.drive(500.0);  // Should fail - not enough fuel
    used_car.displayInfo();
    
    // Try to drive without enough fuel
    std::cout << "\nTrying to drive 400 miles with used car:" << std::endl;
    used_car.drive(400.0);
    
    std::cout << std::endl;
}

/*
Key Concepts Demonstrated:
1. Class definition with private and public members
2. Constructors (default, parameterized, copy)
3. Destructor for cleanup
4. Member functions (methods)
5. Encapsulation with getters and setters
6. Data validation in member functions
7. Static members (variables and functions)
8. Member initialization lists
9. Constructor overloading
10. Const member functions
11. Object creation and destruction
12. Practical class design patterns
13. Object interaction (transfer between accounts)
14. Vector usage within classes
15. String handling in classes
16. Method chaining concepts
17. Private helper methods
18. Class documentation and organization
*/
