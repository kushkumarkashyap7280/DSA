// Class and Object Example
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
  string name;
  int roll;
  void display() { cout << name << " (" << roll << ")" << endl; }
};

int main()
{
  Student s;
  s.name = "Amit";
  s.roll = 101;
  s.display(); // Output: Amit (101)
  return 0;
}
