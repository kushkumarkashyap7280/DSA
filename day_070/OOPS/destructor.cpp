// Destructor Example
#include <iostream>
using namespace std;

class Demo
{
public:
  Demo() { cout << "Constructor called!" << endl; }
  ~Demo() { cout << "Destructor called!" << endl; }
};

int main()
{
  cout << "Creating object d1..." << endl;
  Demo d1;
  {
    cout << "Entering inner scope..." << endl;
    Demo d2;
    cout << "Exiting inner scope..." << endl;
  } // d2 goes out of scope, destructor called
  cout << "Back in main, about to end program..." << endl;
  return 0; // d1 goes out of scope, destructor called
}
