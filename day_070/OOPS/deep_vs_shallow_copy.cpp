// Deep Copy vs Shallow Copy Example
#include <iostream>
#include <cstring>
using namespace std;

class ShallowCopy
{
public:
  char *data;
  ShallowCopy(const char *str)
  {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
  }
  // Default copy constructor (shallow copy)
  ~ShallowCopy() { delete[] data; }
};

class DeepCopy
{
public:
  char *data;
  DeepCopy(const char *str)
  {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
  }
  // Custom copy constructor (deep copy)
  DeepCopy(const DeepCopy &other)
  {
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
  }
  ~DeepCopy() { delete[] data; }
};

int main()
{
  cout << "--- Shallow Copy Example ---\n";
  ShallowCopy s1("Hello");
  ShallowCopy s2 = s1; // Shallow copy (default)
  cout << "s1: " << s1.data << endl;
  cout << "s2: " << s2.data << endl;
  s1.data[0] = 'Y';
  cout << "After modifying s1.data[0]:\n";
  cout << "s1: " << s1.data << endl;
  cout << "s2: " << s2.data << " (also changed!)" << endl;
  // Both point to same memory, so both change

  cout << "\n--- Deep Copy Example ---\n";
  DeepCopy d1("World");
  DeepCopy d2 = d1; // Deep copy (custom)
  cout << "d1: " << d1.data << endl;
  cout << "d2: " << d2.data << endl;
  d1.data[0] = 'M';
  cout << "After modifying d1.data[0]:\n";
  cout << "d1: " << d1.data << endl;
  cout << "d2: " << d2.data << " (unchanged)" << endl;
  // Each has its own memory, so only d1 changes
  return 0;
}
