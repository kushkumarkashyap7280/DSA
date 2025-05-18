#include <iostream>
using namespace std;

// Pass by value
void passByValue(int x)
{
  x = x + 10; // Changes only local copy
}

// Pass by reference using reference variable
void passByReference(int &x)
{
  x = x + 10; // Changes original value
}

// Pass by reference using pointer
void passByPointer(int *x)
{
  *x = *x + 10; // Changes original value
}

// Function overloading
int add(int a, int b)
{
  return a + b;
}

double add(double a, double b)
{
  return a + b;
}

// Default arguments
void printNumber(int num = 10)
{
  cout << "Number: " << num << endl;
}

int main()
{
  int num = 5;

  cout << "Original value: " << num << endl;

  passByValue(num);
  cout << "After pass by value: " << num << endl;

  passByReference(num);
  cout << "After pass by reference: " << num << endl;

  passByPointer(&num);
  cout << "After pass by pointer: " << num << endl;

  // Function overloading
  cout << "Integer addition: " << add(5, 3) << endl;
  cout << "Double addition: " << add(3.14, 2.86) << endl;

  // Default arguments
  printNumber();   // Uses default value
  printNumber(20); // Uses provided value

  return 0;
}
