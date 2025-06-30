// Important C++ Keywords Explained
// -------------------------------
// This file explains several important C++ keywords with examples and why they are necessary.

#include <iostream>
using namespace std;

// 1. const
// ---------
// Used to declare constants or prevent modification of variables, pointers, or member functions.
void constExample()
{
  const int x = 10;
  // x = 20; // ERROR: cannot modify a const variable
  cout << "const int x = " << x << endl;
}

// 2. new
// -------
// Used to dynamically allocate memory on the heap.
void newExample()
{
  int *ptr = new int(5); // Allocates an int with value 5
  cout << "Value allocated with new: " << *ptr << endl;
  delete ptr; // Always free memory allocated with new
}

// 3. virtual
// -----------
// Used to enable runtime polymorphism. Declares a function as virtual so it can be overridden in derived classes.
class Base
{
public:
  virtual void show() { cout << "Base::show()\n"; }
};
class Derived : public Base
{
public:
  void show() override { cout << "Derived::show()\n"; }
};

// 4. static
// ----------
// Used for static variables (shared among all instances), static member functions, or static local variables.
class StaticExample
{
public:
  static int count;
  StaticExample() { ++count; }
  static void printCount() { cout << "Static count: " << count << endl; }
};
int StaticExample::count = 0;

// 5. override
// ------------
// Used to indicate that a virtual function is intended to override a base class function. Helps catch errors at compile time.
// See Derived::show() above.

// 6. this
// --------
// Pointer to the current object instance. Used to access members from within the class.
class ThisExample
{
  int x;

public:
  ThisExample(int x) { this->x = x; }
  void print() { cout << "this->x = " << this->x << endl; }
};

// 7. friend
// ----------
// Allows a function or another class to access private/protected members of a class.
class FriendExample
{
  int secret;

public:
  FriendExample(int s) : secret(s) {}
  friend void revealSecret(const FriendExample &);
};
void revealSecret(const FriendExample &obj)
{
  cout << "Friend can access secret: " << obj.secret << endl;
}

// 8. mutable
// -----------
// Allows a member of an object to be modified even if the object is const.
class MutableExample
{
public:
  mutable int counter;
  MutableExample() : counter(0) {}
  void increment() const { ++counter; }
};

// 9. constexpr
// -------------
// Used to declare that it is possible to evaluate the value of a function or variable at compile time.
constexpr int square(int x) { return x * x; }

// 10. typedef / using
// -------------------
// Used to create type aliases.
typedef unsigned long ulong;
using uint = unsigned int;

int main()
{
  cout << "1. const example:\n";
  constExample();

  cout << "\n2. new example:\n";
  newExample();

  cout << "\n3. virtual, override example:\n";
  Base *b = new Derived();
  b->show(); // Calls Derived::show() due to virtual/override
  delete b;

  cout << "\n4. static example:\n";
  StaticExample s1, s2;
  StaticExample::printCount();

  cout << "\n5. this example:\n";
  ThisExample t(42);
  t.print();

  cout << "\n6. friend example:\n";
  FriendExample f(99);
  revealSecret(f);

  cout << "\n7. mutable example:\n";
  const MutableExample m;
  m.increment();
  cout << "Mutable counter: " << m.counter << endl;

  cout << "\n8. constexpr example:\n";
  constexpr int val = square(5);
  cout << "constexpr square(5): " << val << endl;

  cout << "\n9. typedef/using example:\n";
  ulong big = 1000000;
  uint small = 42;
  cout << "ulong: " << big << ", uint: " << small << endl;

  return 0;
}

// Each keyword is essential for writing robust, efficient, and maintainable C++ code. They provide control over memory, object lifetime, access, type safety, and program structure.
