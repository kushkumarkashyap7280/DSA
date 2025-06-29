// Function Overriding Example
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void speak() { cout << "Animal sound" << endl; }
};
class Dog : public Animal
{
public:
  void speak() override { cout << "Woof!" << endl; }
};
class Cat : public Animal
{
public:
  void speak() override { cout << "Meow!" << endl; }
};

int main()
{
  Animal *a1 = new Dog();
  Animal *a2 = new Cat();
  a1->speak(); // Output: Woof!
  a2->speak(); // Output: Meow!
  delete a1;
  delete a2;
  return 0;
}
