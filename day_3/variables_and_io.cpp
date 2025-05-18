#include <iostream>
using namespace std;

int main()
{
  // 1. DATA TYPES AND VARIABLES
  // Integer types
  int integer = 10;           // 4 bytes: -2^31 to 2^31-1
  short shortInt = 5;         // 2 bytes: -32,768 to 32,767
  long longInt = 1234567890L; // 8 bytes

  // Floating point types
  float floatNum = 3.14f;     // 4 bytes, 7 decimal digits
  double doubleNum = 3.14159; // 8 bytes, 15 decimal digits

  // Character type
  char character = 'A'; // 1 byte

  // Boolean type
  bool isTrue = true; // 1 byte

  // 2. TYPE MODIFIERS
  unsigned int positiveOnly = 10; // Only positive numbers
  signed int withSign = -10;      // Can be negative or positive

  // 3. CONSTANTS
  const int FIXED_VALUE = 100; // Cannot be changed

  // 4. INPUT/OUTPUT OPERATIONS
  // Basic output
  cout << "=== Basic Output ===" << endl;
  cout << "Integer: " << integer << endl;
  cout << "Float: " << floatNum << endl;
  cout << "Character: " << character << endl;

  // Formatted output
  cout << "\n=== Formatted Output ===" << endl;
  cout.precision(3); // Set decimal precision
  cout << "Pi: " << 3.14159 << endl;

  // Basic input
  cout << "\n=== Basic Input ===" << endl;
  int userAge;
  cout << "Enter your age: ";
  cin >> userAge; // Input integer

  // Input with spaces
  cout << "Enter your name: ";
  cin.ignore(); // Clear buffer
  string userName;
  getline(cin, userName); // Input string with spaces

  // Multiple inputs
  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2; // Multiple inputs

  // 5. TYPE CONVERSION
  // Implicit conversion
  int intNum = 10;
  double doubleFromInt = intNum; // Automatic conversion

  // Explicit conversion (casting)
  double pi = 3.14159;
  int intFromDouble = (int)pi;           // C-style cast
  int modernCast = static_cast<int>(pi); // Modern C++ cast

  // 6. SIZEOF OPERATOR
  cout << "\n=== Size of Data Types ===" << endl;
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of char: " << sizeof(char) << " byte" << endl;
  cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes" << endl;

  return 0;
}
