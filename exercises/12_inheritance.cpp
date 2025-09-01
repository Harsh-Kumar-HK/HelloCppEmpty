// Exercise 12: Inheritance
// This exercise demonstrates inheritance, polymorphism, virtual functions,
// access specifiers, and advanced object-oriented programming concepts

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

// BASE CLASS - Shape
class Shape {
protected:
    std::string color;
    double x, y;  // Position coordinates
    
public:
    // Constructor
    Shape(const std::string& shape_color, double pos_x = 0, double pos_y = 0) 
        : color(shape_color), x(pos_x), y(pos_y) {
        std::cout << "Shape created at (" << x << ", " << y << ") with color " << color << std::endl;
    }
    
    // Virtual destructor (important for inheritance)
    virtual ~Shape() {
        std::cout << "Shape destroyed" << std::endl;
    }
    
    // Pure virtual functions (making Shape an abstract class)
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void display() const = 0;
    
    // Virtual function with default implementation
    virtual void move(double new_x, double new_y) {
        std::cout << "Moving shape from (" << x << ", " << y << ") to (" << new_x << ", " << new_y << ")" << std::endl;
        x = new_x;
        y = new_y;
    }
    
    // Non-virtual functions
    std::string getColor() const { return color; }
    void setColor(const std::string& new_color) { color = new_color; }
    double getX() const { return x; }
    double getY() const { return y; }
    
    // Static function
    static void printShapeInfo() {
        std::cout << "This is the base Shape class for geometric objects" << std::endl;
    }
};

// DERIVED CLASS - Circle
class Circle : public Shape {
private:
    double radius;
    
public:
    // Constructor with base class initialization
    Circle(const std::string& color, double r, double pos_x = 0, double pos_y = 0) 
        : Shape(color, pos_x, pos_y), radius(r) {
        std::cout << "Circle created with radius " << radius << std::endl;
    }
    
    // Destructor
    ~Circle() override {
        std::cout << "Circle destroyed" << std::endl;
    }
    
    // Override pure virtual functions
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double calculatePerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void display() const override {
        std::cout << "Circle: radius=" << radius << ", color=" << color 
                  << ", position=(" << x << ", " << y << ")" 
                  << ", area=" << std::fixed << std::setprecision(2) << calculateArea() << std::endl;
    }
    
    // Override virtual function
    void move(double new_x, double new_y) override {
        std::cout << "Rolling circle from (" << x << ", " << y << ") to (" << new_x << ", " << new_y << ")" << std::endl;
        x = new_x;
        y = new_y;
    }
    
    // Circle-specific methods
    double getRadius() const { return radius; }
    void setRadius(double r) { 
        if (r > 0) radius = r; 
        else std::cout << "Radius must be positive!" << std::endl;
    }
    
    double getDiameter() const { return 2 * radius; }
};

// DERIVED CLASS - Rectangle
class Rectangle : public Shape {
private:
    double width, height;
    
public:
    // Constructor
    Rectangle(const std::string& color, double w, double h, double pos_x = 0, double pos_y = 0) 
        : Shape(color, pos_x, pos_y), width(w), height(h) {
        std::cout << "Rectangle created: " << width << " x " << height << std::endl;
    }
    
    // Destructor
    ~Rectangle() override {
        std::cout << "Rectangle destroyed" << std::endl;
    }
    
    // Override pure virtual functions
    double calculateArea() const override {
        return width * height;
    }
    
    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
    
    void display() const override {
        std::cout << "Rectangle: " << width << "x" << height << ", color=" << color 
                  << ", position=(" << x << ", " << y << ")" 
                  << ", area=" << std::fixed << std::setprecision(2) << calculateArea() << std::endl;
    }
    
    // Override virtual function
    void move(double new_x, double new_y) override {
        std::cout << "Sliding rectangle from (" << x << ", " << y << ") to (" << new_x << ", " << new_y << ")" << std::endl;
        x = new_x;
        y = new_y;
    }
    
    // Rectangle-specific methods
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    void setDimensions(double w, double h) {
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        } else {
            std::cout << "Dimensions must be positive!" << std::endl;
        }
    }
    
    bool isSquare() const { return width == height; }
};

// DERIVED CLASS - Triangle
class Triangle : public Shape {
private:
    double side1, side2, side3;
    
public:
    // Constructor
    Triangle(const std::string& color, double s1, double s2, double s3, double pos_x = 0, double pos_y = 0) 
        : Shape(color, pos_x, pos_y), side1(s1), side2(s2), side3(s3) {
        if (isValidTriangle()) {
            std::cout << "Triangle created with sides: " << side1 << ", " << side2 << ", " << side3 << std::endl;
        } else {
            std::cout << "Warning: Invalid triangle dimensions!" << std::endl;
        }
    }
    
    // Destructor
    ~Triangle() override {
        std::cout << "Triangle destroyed" << std::endl;
    }
    
    // Override pure virtual functions
    double calculateArea() const override {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;  // Semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
    
    void display() const override {
        std::cout << "Triangle: sides(" << side1 << ", " << side2 << ", " << side3 
                  << "), color=" << color << ", position=(" << x << ", " << y << ")" 
                  << ", area=" << std::fixed << std::setprecision(2) << calculateArea() << std::endl;
    }
    
    // Triangle-specific methods
    bool isValidTriangle() const {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
    
    bool isEquilateral() const {
        return (side1 == side2) && (side2 == side3);
    }
    
    bool isIsosceles() const {
        return (side1 == side2) || (side2 == side3) || (side1 == side3);
    }
    
    bool isRightTriangle() const {
        double a = side1, b = side2, c = side3;
        // Sort sides to find hypotenuse
        if (a > b) std::swap(a, b);
        if (b > c) std::swap(b, c);
        if (a > b) std::swap(a, b);
        
        // Check Pythagorean theorem (with small tolerance for floating point)
        return abs((a*a + b*b) - c*c) < 0.001;
    }
};

// INHERITANCE WITH ACCESS SPECIFIERS
class Animal {
protected:
    std::string name;
    int age;
    
public:
    Animal(const std::string& animal_name, int animal_age) : name(animal_name), age(animal_age) {
        std::cout << "Animal " << name << " created" << std::endl;
    }
    
    virtual ~Animal() {
        std::cout << "Animal " << name << " destroyed" << std::endl;
    }
    
    virtual void makeSound() const = 0;  // Pure virtual
    virtual void eat() const {
        std::cout << name << " is eating" << std::endl;
    }
    
    virtual void sleep() const {
        std::cout << name << " is sleeping" << std::endl;
    }
    
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

// Public inheritance
class Dog : public Animal {
private:
    std::string breed;
    
public:
    Dog(const std::string& name, int age, const std::string& dog_breed) 
        : Animal(name, age), breed(dog_breed) {
        std::cout << "Dog of breed " << breed << " created" << std::endl;
    }
    
    ~Dog() override {
        std::cout << "Dog destroyed" << std::endl;
    }
    
    void makeSound() const override {
        std::cout << name << " says: Woof! Woof!" << std::endl;
    }
    
    void eat() const override {
        std::cout << name << " is eating dog food" << std::endl;
    }
    
    // Dog-specific method
    void fetch() const {
        std::cout << name << " is fetching the ball!" << std::endl;
    }
    
    std::string getBreed() const { return breed; }
};

class Cat : public Animal {
private:
    bool is_indoor;
    
public:
    Cat(const std::string& name, int age, bool indoor = true) 
        : Animal(name, age), is_indoor(indoor) {
        std::cout << "Cat created (" << (is_indoor ? "indoor" : "outdoor") << ")" << std::endl;
    }
    
    ~Cat() override {
        std::cout << "Cat destroyed" << std::endl;
    }
    
    void makeSound() const override {
        std::cout << name << " says: Meow! Meow!" << std::endl;
    }
    
    void eat() const override {
        std::cout << name << " is eating cat food" << std::endl;
    }
    
    // Cat-specific methods
    void purr() const {
        std::cout << name << " is purring contentedly" << std::endl;
    }
    
    void climb() const {
        std::cout << name << " is climbing the cat tree" << std::endl;
    }
    
    bool isIndoor() const { return is_indoor; }
};

// MULTIPLE LEVELS OF INHERITANCE
class Vehicle {
protected:
    std::string make, model;
    int year;
    
public:
    Vehicle(const std::string& vehicle_make, const std::string& vehicle_model, int vehicle_year) 
        : make(vehicle_make), model(vehicle_model), year(vehicle_year) {
        std::cout << "Vehicle created: " << year << " " << make << " " << model << std::endl;
    }
    
    virtual ~Vehicle() {
        std::cout << "Vehicle destroyed" << std::endl;
    }
    
    virtual void start() const = 0;
    virtual void stop() const = 0;
    virtual void displayInfo() const {
        std::cout << year << " " << make << " " << model;
    }
    
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
};

class MotorVehicle : public Vehicle {
protected:
    double engine_size;
    std::string fuel_type;
    
public:
    MotorVehicle(const std::string& make, const std::string& model, int year, 
                double engine, const std::string& fuel) 
        : Vehicle(make, model, year), engine_size(engine), fuel_type(fuel) {
        std::cout << "Motor vehicle with " << engine_size << "L " << fuel_type << " engine" << std::endl;
    }
    
    virtual ~MotorVehicle() {
        std::cout << "Motor vehicle destroyed" << std::endl;
    }
    
    void displayInfo() const override {
        Vehicle::displayInfo();  // Call base class method
        std::cout << " (" << engine_size << "L " << fuel_type << " engine)";
    }
    
    double getEngineSize() const { return engine_size; }
    std::string getFuelType() const { return fuel_type; }
};

class Car : public MotorVehicle {
private:
    int num_doors;
    
public:
    Car(const std::string& make, const std::string& model, int year, 
        double engine, const std::string& fuel, int doors) 
        : MotorVehicle(make, model, year, engine, fuel), num_doors(doors) {
        std::cout << "Car with " << num_doors << " doors created" << std::endl;
    }
    
    ~Car() override {
        std::cout << "Car destroyed" << std::endl;
    }
    
    void start() const override {
        std::cout << "Car engine started with key" << std::endl;
    }
    
    void stop() const override {
        std::cout << "Car engine stopped" << std::endl;
    }
    
    void displayInfo() const override {
        MotorVehicle::displayInfo();
        std::cout << " - " << num_doors << " door car" << std::endl;
    }
    
    int getNumDoors() const { return num_doors; }
};

class Motorcycle : public MotorVehicle {
private:
    bool has_sidecar;
    
public:
    Motorcycle(const std::string& make, const std::string& model, int year, 
               double engine, const std::string& fuel, bool sidecar = false) 
        : MotorVehicle(make, model, year, engine, fuel), has_sidecar(sidecar) {
        std::cout << "Motorcycle" << (has_sidecar ? " with sidecar" : "") << " created" << std::endl;
    }
    
    ~Motorcycle() override {
        std::cout << "Motorcycle destroyed" << std::endl;
    }
    
    void start() const override {
        std::cout << "Motorcycle started with electric start" << std::endl;
    }
    
    void stop() const override {
        std::cout << "Motorcycle engine stopped" << std::endl;
    }
    
    void displayInfo() const override {
        MotorVehicle::displayInfo();
        std::cout << " - Motorcycle" << (has_sidecar ? " with sidecar" : "") << std::endl;
    }
    
    bool hasSidecar() const { return has_sidecar; }
};

// Function prototypes
void demonstrate_basic_inheritance();
void demonstrate_polymorphism();
void demonstrate_animal_hierarchy();
void demonstrate_vehicle_hierarchy();
void demonstrate_virtual_functions();

int main() {
    std::cout << "=== C++ Inheritance and Polymorphism ===" << std::endl << std::endl;
    
    demonstrate_basic_inheritance();
    demonstrate_polymorphism();
    demonstrate_animal_hierarchy();
    demonstrate_vehicle_hierarchy();
    demonstrate_virtual_functions();
    
    return 0;
}

void demonstrate_basic_inheritance() {
    std::cout << "--- Basic Inheritance ---" << std::endl;
    
    // Cannot create Shape object (abstract class)
    // Shape shape("red");  // This would cause compilation error
    
    // Create derived objects
    Circle circle("red", 5.0, 10.0, 20.0);
    Rectangle rectangle("blue", 4.0, 6.0, 0.0, 0.0);
    Triangle triangle("green", 3.0, 4.0, 5.0, 5.0, 5.0);
    
    std::cout << "\n--- Displaying Shape Information ---" << std::endl;
    circle.display();
    rectangle.display();
    triangle.display();
    
    std::cout << "\n--- Testing Shape Movement ---" << std::endl;
    circle.move(15.0, 25.0);
    rectangle.move(10.0, 10.0);
    
    std::cout << "\n--- Testing Derived Class Specific Methods ---" << std::endl;
    std::cout << "Circle diameter: " << circle.getDiameter() << std::endl;
    std::cout << "Rectangle is square: " << (rectangle.isSquare() ? "Yes" : "No") << std::endl;
    std::cout << "Triangle is right triangle: " << (triangle.isRightTriangle() ? "Yes" : "No") << std::endl;
    std::cout << "Triangle is equilateral: " << (triangle.isEquilateral() ? "Yes" : "No") << std::endl;
    
    std::cout << std::endl;
}

void demonstrate_polymorphism() {
    std::cout << "--- Polymorphism Demonstration ---" << std::endl;
    
    // Create vector of base class pointers
    std::vector<std::unique_ptr<Shape>> shapes;
    
    // Add different derived objects
    shapes.push_back(std::make_unique<Circle>("red", 3.0));
    shapes.push_back(std::make_unique<Rectangle>("blue", 4.0, 5.0));
    shapes.push_back(std::make_unique<Triangle>("green", 6.0, 8.0, 10.0));
    shapes.push_back(std::make_unique<Circle>("yellow", 2.5));
    
    std::cout << "\n--- Polymorphic Function Calls ---" << std::endl;
    double total_area = 0.0;
    double total_perimeter = 0.0;
    
    for (const auto& shape : shapes) {
        shape->display();  // Polymorphic call
        total_area += shape->calculateArea();
        total_perimeter += shape->calculatePerimeter();
        shape->move(1.0, 1.0);  // Polymorphic call
        std::cout << std::endl;
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total area of all shapes: " << total_area << std::endl;
    std::cout << "Total perimeter of all shapes: " << total_perimeter << std::endl;
    
    std::cout << std::endl;
}

void demonstrate_animal_hierarchy() {
    std::cout << "--- Animal Hierarchy ---" << std::endl;
    
    // Create animals
    Dog dog("Buddy", 3, "Golden Retriever");
    Cat cat("Whiskers", 2, true);
    
    std::cout << "\n--- Animal Behaviors ---" << std::endl;
    
    // Polymorphic calls through base class pointers
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Rex", 5, "German Shepherd"));
    animals.push_back(std::make_unique<Cat>("Mittens", 1, false));
    
    for (const auto& animal : animals) {
        std::cout << "\n" << animal->getName() << " (age " << animal->getAge() << "):" << std::endl;
        animal->makeSound();  // Polymorphic
        animal->eat();        // Polymorphic
        animal->sleep();
    }
    
    std::cout << "\n--- Specific Animal Behaviors ---" << std::endl;
    dog.fetch();  // Dog-specific method
    cat.purr();   // Cat-specific method
    cat.climb();  // Cat-specific method
    
    std::cout << std::endl;
}

void demonstrate_vehicle_hierarchy() {
    std::cout << "--- Vehicle Hierarchy ---" << std::endl;
    
    // Create vehicles
    Car sedan("Toyota", "Camry", 2023, 2.5, "Gasoline", 4);
    Motorcycle bike("Harley-Davidson", "Street 750", 2022, 0.75, "Gasoline", false);
    
    std::cout << "\n--- Vehicle Operations ---" << std::endl;
    
    // Store in base class pointers
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("Honda", "Civic", 2022, 1.5, "Gasoline", 4));
    vehicles.push_back(std::make_unique<Motorcycle>("Yamaha", "R3", 2023, 0.32, "Gasoline", false));
    
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo();
        vehicle->start();   // Polymorphic
        vehicle->stop();    // Polymorphic
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

void demonstrate_virtual_functions() {
    std::cout << "--- Virtual Function Behavior ---" << std::endl;
    
    // Demonstrate virtual vs non-virtual behavior
    Circle circle("purple", 4.0);
    Shape* shape_ptr = &circle;
    
    std::cout << "\nCalling through base pointer:" << std::endl;
    shape_ptr->display();           // Virtual - calls Circle::display()
    shape_ptr->move(100, 200);      // Virtual - calls Circle::move()
    std::cout << "Color: " << shape_ptr->getColor() << std::endl;  // Non-virtual
    
    std::cout << "\nDemonstrating virtual destructor importance:" << std::endl;
    Shape* dynamic_shape = new Rectangle("orange", 3.0, 7.0);
    dynamic_shape->display();
    delete dynamic_shape;  // Virtual destructor ensures proper cleanup
    
    std::cout << std::endl;
}

/*
Key Concepts Demonstrated:
1. Basic inheritance with public access
2. Virtual functions and pure virtual functions
3. Abstract base classes
4. Function overriding in derived classes
5. Polymorphism with base class pointers
6. Virtual destructors for proper cleanup
7. Protected members accessible in derived classes
8. Multiple levels of inheritance
9. Constructor and destructor call order
10. Base class method calling with scope resolution
11. Runtime polymorphism vs compile-time binding
12. Abstract interfaces with pure virtual functions
13. Inheritance access specifiers (public, protected, private)
14. Virtual function tables (vtable) concepts
15. Dynamic memory management with inheritance
16. Smart pointers with inheritance hierarchies
17. Method overriding vs method overloading
18. IS-A relationships in inheritance
*/
