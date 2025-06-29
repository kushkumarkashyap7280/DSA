// Dynamic Instance Creation Example
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
  string name;
  int roll;
  Student(string n, int r) : name(n), roll(r) {}
  void display() { cout << name << " (" << roll << ")" << endl; }
};

int main()
{
  // Dynamically create a Student instance using new
  Student *sPtr = new Student("Amit", 101);
  // Access members using pointer
  sPtr->display(); // Output: Amit (101)
  cout << "Name: " << sPtr->name << endl;
  cout << "Roll: " << sPtr->roll << endl;

  // Modify members
  sPtr->name = "Priya";
  sPtr->roll = 202;
  sPtr->display(); // Output: Priya (202)

  // Always delete dynamically allocated memory
  delete sPtr;
  return 0;
}
