// Access Modifiers Example
#include <iostream>
using namespace std;

class Base
{
public:
  int pub; // Accessible everywhere
protected:
  int prot; // Accessible in Base and derived classes
private:
  int priv; // Accessible only in Base
};

class Derived : public Base
{
public:
  void test()
  {
    pub = 1;  // OK
    prot = 2; // OK
              // priv = 3; // ERROR: not accessible
  }
};

int main()
{
  Base b;
  b.pub = 10; // OK
  // b.prot = 20;  // ERROR: not accessible
  // b.priv = 30;  // ERROR: not accessible
  return 0;
}
