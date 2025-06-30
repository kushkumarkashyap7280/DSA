// here we demostrate and know about polymorphism in C++

// definition :
// Polymorphism is a core concept in object-oriented programming that allows objects of different classes to be treated as objects of a common base class. It enables a single interface to represent different underlying forms (data types). In C++, polymorphism is typically achieved through function overloading, operator overloading, and virtual functions, allowing methods to be defined in a base class and overridden in derived classes, enabling dynamic binding at runtime.

// types of polymorphism in C++:

// 1. Compile-time Polymorphism (Static Binding):
//    - Function Overloading: Multiple functions with the same name but different parameters.
//    - Operator Overloading: Defining custom behavior for operators (e.g., +, -, *, etc.) for user-defined types.

// 2. Runtime Polymorphism (Dynamic Binding):
//    - Virtual Functions: Functions declared in a base class that can be overridden in derived classes
//    - Pure Virtual Functions: Functions that must be implemented by derived classes, making the base class abstract.

#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
  // Virtual function to make sound
  virtual void makeSound() const
  {
    cout << "Animal makes a sound." << endl;
  }

  // Virtual destructor
  virtual ~Animal()
  {
    cout << "Animal destroyed." << endl;
  }
};

// Derived class Dog
class Dog : public Animal
{
public:
  // Overriding the makeSound function
  void makeSound() const override
  {
    cout << "Dog barks." << endl;
  }

  // Destructor
  ~Dog()
  {
    cout << "Dog destroyed." << endl;
  }
};

// Derived class Cat
class Cat : public Animal
{
public:
  // Overriding the makeSound function
  void makeSound() const override
  {
    cout << "Cat meows." << endl;
  }

  // Destructor
  ~Cat()
  {
    cout << "Cat destroyed." << endl;
  }
};
// Function to demonstrate polymorphism
void demonstratePolymorphism(const Animal &animal)
{
  // Call the makeSound function, which will invoke the appropriate derived class method
  animal.makeSound();
}

// =========================
// Compile-time Polymorphism Example (Function Overloading)
// =========================
// Function overloading: same function name, different parameter lists
int add(int a, int b)
{
  return a + b;
}
double add(double a, double b)
{
  return a + b;
}

// =========================
// Runtime Polymorphism Example (Virtual Functions)
// =========================
// See the Animal, Dog, and Cat classes below for runtime polymorphism using virtual functions.
//
// When a base class pointer or reference refers to a derived class object, the overridden method in the derived class is called.
//
// Example usage in main():
//   Animal* animalPtr = new Dog();
//   animalPtr->makeSound(); // Calls Dog's makeSound() due to virtual function
//   delete animalPtr;
//

// =========================
// Operator Overloading in C++
// =========================
// Most operators in C++ can be overloaded, including:
// +  -  *  /  %  ^  &  |  ~  !  =  <  >  +=  -=  *=  /=  %=  ^=  &=  |=  <<  >>  >>=  <<=  ==  !=  <=  >=  ++  --  ->  []  ()  new  delete
//
// Some operators cannot be overloaded, such as: ::  .  .*  ?:  sizeof  typeid  static_cast  dynamic_cast  const_cast  reinterpret_cast
//
// Example: Overloading the + operator for a Point class
class Point
{
public:
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  // Overload + operator to add two Point objects
  Point operator+(const Point &other) const
  {
    return Point(x + other.x, y + other.y);
  }
};

int main()
{
  // Compile-time polymorphism demonstration
  cout << "Compile-time polymorphism (Function Overloading):\n";
  cout << "add(2, 3) = " << add(2, 3) << endl;
  cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << endl;

  // Runtime polymorphism demonstration
  cout << "\nRuntime polymorphism (Virtual Functions):\n";
  Animal *animalPtr;
  Dog dog;
  Cat cat;
  animalPtr = &dog;
  animalPtr->makeSound(); // Calls Dog's makeSound
  animalPtr = &cat;
  animalPtr->makeSound(); // Calls Cat's makeSound

  // Demonstrate polymorphism with reference
  cout << "\nDemonstrating polymorphism with reference parameter:\n";
  demonstratePolymorphism(dog); // Calls Dog's makeSound
  demonstratePolymorphism(cat); // Calls Cat's makeSound

  // Operator overloading demonstration
  Point p1(1, 2), p2(3, 4);
  Point p3 = p1 + p2;
  cout << "\nOperator overloading (+) demonstration:\n";
  cout << "p1: (" << p1.x << ", " << p1.y << ")\n";
  cout << "p2: (" << p2.x << ", " << p2.y << ")\n";
  cout << "p3 = p1 + p2: (" << p3.x << ", " << p3.y << ")\n";

  // Clean up
  return 0; // Destructors will be called automatically
}