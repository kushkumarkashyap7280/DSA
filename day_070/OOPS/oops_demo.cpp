// OOPs Concepts Demonstration in C++
#include <iostream>
#include <string>
#include "animal.h" // Include the Animal class from another file
using namespace std;

// 2. Inheritance
class Dog : public Animal
{
public:
  Dog(string n) : Animal(n) {}
  void speak() override
  {
    cout << name << " barks." << endl;
  }
};

// 3. Polymorphism (Function Overriding)
void animalSound(Animal *a)
{
  a->speak();
}

// 4. Encapsulation
class BankAccount
{
private:
  double balance;

public:
  BankAccount(double b) : balance(b) {}
  void deposit(double amt) { balance += amt; }
  void withdraw(double amt)
  {
    if (amt <= balance)
      balance -= amt;
  }
  double getBalance() const { return balance; }
};

// 5. Abstraction (via interface)
class Shape
{
public:
  virtual double area() const = 0;
};
class Circle : public Shape
{
  double r;

public:
  Circle(double radius) : r(radius) {}
  double area() const override { return 3.14159 * r * r; }
};

int main()
{
  // Class & Object (from another file)
  Animal a("Generic Animal");
  a.speak();

  // Inheritance & Polymorphism
  Dog d("Tommy");
  animalSound(&a);
  animalSound(&d);

  // Encapsulation
  BankAccount acc(1000);
  acc.deposit(500);
  acc.withdraw(200);
  cout << "Account Balance: " << acc.getBalance() << endl;

  // Abstraction
  Circle c(5);
  cout << "Area of Circle: " << c.area() << endl;

  return 0;
}
