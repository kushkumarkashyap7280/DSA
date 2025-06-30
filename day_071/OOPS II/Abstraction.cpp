// Abstraction in C++
// ------------------
// Abstraction is an OOP concept that allows you to hide complex implementation details and show only the essential features of an object.
// It helps reduce programming complexity and effort by providing a clear separation between what an object does and how it does it.
//
// In C++, abstraction is achieved using abstract classes (classes with at least one pure virtual function) and interfaces.
//
// Key Points:
// - Abstract classes cannot be instantiated directly.
// - They can have regular methods and data members, but must have at least one pure virtual function.
// - Derived classes must implement all pure virtual functions to be instantiated.
//
// Example:
#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
  // Pure virtual function
  virtual double area() const = 0;
  // Regular function
  void info() const { cout << "This is a shape.\n"; }
};

// Derived class implements the pure virtual function
class Rectangle : public Shape
{
  double width, height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}
  double area() const override { return width * height; }
};

int main()
{
  // Shape s; // ERROR: cannot instantiate abstract class
  Rectangle rect(5, 3);
  rect.info();
  cout << "Area of rectangle: " << rect.area() << endl;
  return 0;
}

// Output:
// This is a shape.
// Area of rectangle: 15
//
// Abstraction allows you to define a common interface for all shapes, while hiding the details of how each shape calculates its area.
