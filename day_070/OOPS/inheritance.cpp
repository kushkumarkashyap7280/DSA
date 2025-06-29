// Inheritance Example
#include <iostream>
using namespace std;

class Animal
{
public:
  void eat() { cout << "Eating..." << endl; }
};
class Dog : public Animal
{
public:
  void bark() { cout << "Barking..." << endl; }
};

int main()
{
  Dog d;
  d.eat();  // Output: Eating...
  d.bark(); // Output: Barking...
  return 0;
}
