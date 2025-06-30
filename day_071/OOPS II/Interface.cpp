// Interface in C++
// ---------------
// C++ does not have a keyword 'interface' like Java or C#. However, interfaces can be implemented using abstract classes that have only pure virtual functions (and no data members or implemented methods).
//
// An interface defines a contract: any class that inherits from the interface must implement all its pure virtual functions.
//
// Key Points:
// - An interface in C++ is an abstract class with only pure virtual functions.
// - No data members or implemented methods (except possibly a virtual destructor).
// - Used to achieve full abstraction and multiple inheritance of behavior.
//
// Example:
#include <iostream>
using namespace std;

// Interface (abstract class with only pure virtual functions)
class IPrintable
{
public:
  virtual void print() const = 0; // Pure virtual function
  virtual ~IPrintable() {}        // Virtual destructor (optional but recommended)
};

// Class implementing the interface
class Document : public IPrintable
{
public:
  void print() const override
  {
    cout << "Printing document..." << endl;
  }
};

class Image : public IPrintable
{
public:
  void print() const override
  {
    cout << "Printing image..." << endl;
  }
};

int main()
{
  Document doc;
  Image img;
  IPrintable *ptr;
  ptr = &doc;
  ptr->print(); // Output: Printing document...
  ptr = &img;
  ptr->print(); // Output: Printing image...
  return 0;
}

// Output:
// Printing document...
// Printing image...
//
// This demonstrates how interfaces in C++ allow you to define a common contract for unrelated classes, enabling polymorphic behavior.
