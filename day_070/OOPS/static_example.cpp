// Static Data Members and Static Methods Example
#include <iostream>
using namespace std;

class Counter
{
public:
  static int count; // Static data member (shared by all objects)
  Counter() { count++; }
  static void showCount()
  { // Static method
    cout << "Count: " << count << endl;
  }
};

int Counter::count = 0; // Definition of static data member

int main()
{
  Counter c1;
  Counter c2;
  Counter::showCount(); // Access static method via class
  c1.showCount();       // Access static method via object (allowed, but not recommended)
  cout << "Static count via class: " << Counter::count << endl;
  cout << "Static count via object: " << c2.count << endl;
  return 0;
}
