// here we know about inheritance in C++

// definition :
// Inheritance is a fundamental concept in object-oriented programming that allows a class (derived class) to inherit properties and behaviors (attributes and methods) from another class (base class). This promotes code reuse, establishes a hierarchical relationship between classes, and enables polymorphism, allowing derived classes to override or extend the functionality of base classes.

// parent class  || child class   || final access modifier
// --------------||---------------||--------------------------
// private       || private       || private ,inaccessible outside the class
// private       || protected     || private ,inaccessible outside the class, but accessible to derived classes
// private       || public        || private ,inaccessible outside the class, but accessible to derived classes
// protected     || private       || private ,accessible to derived classes, but not outside the class
// protected     || protected     || protected ,accessible to derived classes
// protected     || public        || protected ,accessible to derived classes and outside the class
// public        || private       || private ,accessible outside the class, but not to derived classes
// public        || protected     || protected ,accessible outside the class, but not to derived classes
// public        || public        || public , accessible outside the class and to derived classes

// types of inheritance in C++:

// 1. Single Inheritance: A derived class inherits from a single base class.
// example: base class Animal and derived class Dog.
// class Animal (base class)
//    ||
// class Dog   (derived class)

// 2. Multiple Inheritance: A derived class inherits from multiple base classes.
// Example: A class that inherits from both Animal and Pet classes.

// class Animal (base class)     -----  class Pet (base class)
//                                 ||
//                              class Dog (derived class)

// // This can lead to ambiguity if not handled properly, especially with methods or attributes that have the same name in both base classes.

// 3. Multilevel Inheritance: A derived class inherits from another derived class.
// This creates a chain of inheritance where a class can inherit from another derived class, which in turn inherits from a base class.
// This allows for a more complex hierarchy of classes, where each level can add its own attributes.
// Example: A class Dog that inherits from Animal, and a class Puppy that inherits from Dog.
// class Animal (base class)
//    ||
// class Dog   (derived class)
//    ||
// class Puppy (derived class)

// This allows Puppy to inherit attributes from both Dog and Animal, creating a multi-level hierarchy.

// 4. Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
// example: A base class Animal with derived classes Dog and Cat.
// class Animal (base class)
//    ||
// class Dog   (derived class) && class Cat (derived class)

// 5. Hybrid Inheritance: A combination of two or more types of inheritance, often involving multiple and multilevel inheritance.
// This can create complex relationships between classes, allowing for a flexible design.
// Example: A class Dog that inherits from Animal, and a class Cat that also inherits from Animal, while both Dog and Cat inherit from a common base class Pet.
// class Animal (base class)
//    ||
// class Pet    (base class)
//    ||
// class Dog   (derived class) && class Cat (derived class)
// This allows for a hybrid structure where both Dog and Cat can share attributes from Animal and Pet, creating a more complex inheritance hierarchy.

// 6. Virtual Inheritance: A way to prevent multiple instances of a base class when using multiple inheritance, ensuring that only one instance of the base class is shared among derived classes.
// This is particularly useful in complex inheritance scenarios to avoid ambiguity and redundancy.

#include <iostream>
using namespace std;

// Base class
class Animal
{
  string name;
  string species;
  int weight;
  int height;
  string sound;

public:
  // Constructor to initialize the animal object
  Animal(string name, string species, int weight, int height)
      : name(name), species(species), weight(weight), height(height)
  {
    cout << "Animal created: " << name << ", Species: " << species
         << ", Weight: " << weight << ", Height: " << height << endl;
  }

  // virtual method to make sound
  // This method can be overridden in derived classes to provide specific sounds for different animals
  virtual void makeSount() const
  {
    cout << "Animal makes a sound." << endl;
  }
  // Method to display animal information
  void displayInfo() const
  {
    cout << "Name: " << name << ", Species: " << species
         << ", Weight: " << weight << ", Height: " << height << endl;
  }

  // Destructor
  virtual ~Animal()
  {
    cout << "Animal destroyed: " << name << endl;
  }
};

// Derived class example (not implemented here, but can be created)
class Dog : public Animal
{
  int age;      // Example of a specific attribute for Dog class
  string breed; // Example of another specific attribute for Dog class
public:
  // Dog-specific attributes and methods can be added here

  // constructor for Dog class
  Dog(string name, int age, int height)
      : Animal(name, "Dog", 20, height), age(age), breed("Unknown")
  {
    cout << "Dog created: " << name << ", Age: " << age << ", Height: " << height << endl;
  }

  // make sound method for Dog class
  void makeSount() const override
  {
    cout << "Dog barks." << endl;
  }

  ~Dog()
  {
    cout << "Dog destroyed." << endl;
  }
};

// base class Student
class Student
{
  string name;
  int age;
  int rollNo;

public:
  // construtor
  Student(string name, int age, int rollNo)
      : name(name), age(age), rollNo(rollNo) {}

  virtual void display()
  {
    cout << "name is :" << this->name << "and rollno is :" << this->rollNo << "having age :" << age;
  }
};

class BoyStudent : public Student
{
  int height;

public:
  // constructor
  BoyStudent(string name, int age, int rollNo, int height) : Student(name, age, rollNo), height(height) {};

  void display() override
  {
    // Note: name, rollNo, and age are private in Student, so this will not compile unless you make them protected or provide accessors.
    // For now, let's assume you want to call Student::display() and then add height.
    Student::display();
    cout << " with height :" << this->height << endl;
  }
};

// =========================
// Ambiguity in Multiple Inheritance
// =========================
// Ambiguity occurs in multiple inheritance when two or more base classes have a method with the same name, and the derived class does not override it.
// The compiler cannot decide which base class method to call, leading to an error.
//
// Example:
// class A {
// public:
//   void show() { cout << "A::show\n"; }
// };
// class B {
// public:
//   void show() { cout << "B::show\n"; }
// };
// class C : public A, public B {};
//
// int main() {
//   C obj;
//   obj.show(); // ERROR: ambiguous, as both A and B have show()
// }
//
// How to fix ambiguity:
// Use the scope resolution operator (::) to specify which base class's method you want to call.
//
// Example:
//   obj.A::show(); // Calls show() from class A
//   obj.B::show(); // Calls show() from class B
//
// This resolves the ambiguity by explicitly telling the compiler which method to use.
//
// In more complex cases (like the diamond problem), virtual inheritance is used to ensure only one instance of the base class exists in the inheritance hierarchy, preventing ambiguity.
// See the 'Virtual Inheritance' example above for details.
// =========================

// =========================
// CODE EXAMPLES FOR EACH INHERITANCE TYPE
// =========================

// 1. Single Inheritance Example
class SingleAnimal
{
public:
  void eat() { cout << "SingleAnimal eats.\n"; }
};
class SingleDog : public SingleAnimal
{
public:
  void bark() { cout << "SingleDog barks.\n"; }
};

// 2. Multiple Inheritance & Ambiguity Example
class A
{
public:
  void show() { cout << "A::show\n"; }
};
class B
{
public:
  void show() { cout << "B::show\n"; }
};
class C : public A, public B
{
};

// --- Ambiguity Explanation ---
// Ambiguity in inheritance occurs when a derived class inherits from two or more base classes that have members with the same name.
// The compiler cannot determine which member to use, resulting in an ambiguous error.
//
// Example:
//   C obj;
//   obj.show(); // ERROR: ambiguous, as both A and B have show()
//
// To fix ambiguity, use the scope resolution operator to specify which base class's method to call:
//   obj.A::show(); // Calls A's show()
//   obj.B::show(); // Calls B's show()
//
// This resolves the ambiguity by making it explicit which function you want to use.

void ambiguity_example()
{
  C obj;
  // obj.show(); // ERROR: ambiguous
  obj.A::show(); // OK
  obj.B::show(); // OK
}

// 3. Multilevel Inheritance Example
class Base
{
public:
  void baseFunc() { cout << "Base\n"; }
};
class Derived1 : public Base
{
public:
  void derived1Func() { cout << "Derived1\n"; }
};
class Derived2 : public Derived1
{
public:
  void derived2Func() { cout << "Derived2\n"; }
};

// 4. Hierarchical Inheritance Example
class Parent
{
public:
  void parentFunc() { cout << "Parent\n"; }
};
class Child1 : public Parent
{
};
class Child2 : public Parent
{
};

// 5. Hybrid Inheritance Example
class X
{
public:
  void fx() { cout << "X\n"; }
};
class Y : public X
{
public:
  void fy() { cout << "Y\n"; }
};
class Z
{
public:
  void fz() { cout << "Z\n"; }
};
class Hybrid : public Y, public Z
{
};

// 6. Virtual Inheritance (Diamond Problem) Example
class VA
{
public:
  void show() { cout << "VA\n"; }
};
class VB : virtual public VA
{
};
class VC : virtual public VA
{
};
class VD : public VB, public VC
{
};

int main()
{
  cout << "\n--- Single Inheritance ---\n";
  SingleDog sd;
  sd.eat();
  sd.bark();

  cout << "\n--- Multiple Inheritance & Ambiguity ---\n";
  ambiguity_example();

  cout << "\n--- Multilevel Inheritance ---\n";
  Derived2 m;
  m.baseFunc();
  m.derived1Func();
  m.derived2Func();

  cout << "\n--- Hierarchical Inheritance ---\n";
  Child1 c1;
  Child2 c2;
  c1.parentFunc();
  c2.parentFunc();

  cout << "\n--- Hybrid Inheritance ---\n";
  Hybrid h;
  h.fx();
  h.fy();
  h.fz();

  cout << "\n--- Virtual Inheritance (Diamond Problem) ---\n";
  VD vd;
  vd.show(); // Only one VA::show exists

  // Creating an instance of the Animal class
  Animal lion("Leo", "Lion", 190, 120);

  // Displaying the information of the animal
  lion.displayInfo();

  // Note: Inheritance can be demonstrated by creating derived classes that inherit from the Animal class.
  // For example, we could create a class Dog that inherits from Animal and adds specific attributes or methods.

  // Creating an instance of the Dog class
  Dog dog("Buddy", 5, 60);
  dog.displayInfo();

  // makeing student object
  BoyStudent boyStudent("John", 16, 101, 180);
  boyStudent.display();

  // making  boyStudent object dynamically
  Student *studentPtr = new BoyStudent("Mike", 17, 102, 175);
  studentPtr->display();
  // Clean up dynamically allocated memory
  delete studentPtr;
  return 0;
}