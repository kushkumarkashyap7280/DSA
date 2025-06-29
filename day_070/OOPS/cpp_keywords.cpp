// Important C++ Keywords Example
#include <iostream>
using namespace std;

class Base
{
public:
  virtual void foo() { cout << "Base foo" << endl; }
  virtual void bar() = 0; // pure virtual
};
class Derived final : public Base
{
public:
  void foo() override { cout << "Derived foo" << endl; }
  void bar() override { cout << "Derived bar" << endl; }
};

class Example
{
public:
  Example() = default;               // use compiler default constructor
  Example(const Example &) = delete; // disable copy constructor
  explicit Example(int x) {}         // prevent implicit conversion
};

class MyClass
{
private:
  int secret = 42;
  friend void reveal(const MyClass &); // grant access
};
void reveal(const MyClass &obj)
{
  cout << obj.secret << endl;
}

int main()
{
  Derived d;
  d.foo();
  d.bar();
  Example e1;
  Example e2(5);
  MyClass m;
  reveal(m);
  return 0;
}
