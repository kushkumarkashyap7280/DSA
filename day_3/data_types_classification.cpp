#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

int main()
{
  cout << "=== PRIMITIVE DATA TYPES ===" << endl;
  // 1. Integer Types
  int a = 10;                 // Basic integer
  short b = 5;                // Short integer
  long c = 1000000L;          // Long integer
  long long d = 1000000000LL; // Long long integer

  // 2. Floating Point Types
  float e = 10.5f;       // Single precision
  double f = 10.5;       // Double precision
  long double g = 10.5L; // Extended precision

  // 3. Character Type
  char h = 'A'; // Single character

  // 4. Boolean Type
  bool i = true; // true or false

  cout << "\n=== NON-PRIMITIVE (DERIVED) DATA TYPES ===" << endl;

  // 1. Arrays (Fixed-size collection)
  int arr[5] = {1, 2, 3, 4, 5};
  cout << "Array example: " << arr[0] << endl;

  // 2. Strings (Character sequence)
  string str = "Hello";
  cout << "String example: " << str << endl;

  // 3. Pointers (Stores memory address)
  int *ptr = &a;
  cout << "Pointer example: " << *ptr << endl;

  // 4. References (Alias for variable)
  int &ref = a;
  cout << "Reference example: " << ref << endl;

  cout << "\n=== USER-DEFINED DATA TYPES ===" << endl;

  // 1. Structure
  struct Person
  {
    string name;
    int age;
  };
  Person person = {"John", 25};
  cout << "Structure example: " << person.name << endl;

  // 2. Class
  class Sample
  {
    int data; // Private by default
  public:
    void setData(int d) { data = d; }
    int getData() { return data; }
  };

  // 3. Enumeration
  enum Color
  {
    RED,
    GREEN,
    BLUE
  };
  Color color = RED;
  cout << "Enum example: " << color << endl;

  cout << "\n=== MEMORY SIZES ===" << endl;
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of char: " << sizeof(char) << " byte" << endl;
  cout << "Size of pointer: " << sizeof(int *) << " bytes" << endl;
  cout << "Size of structure: " << sizeof(Person) << " bytes" << endl;

  return 0;
}
