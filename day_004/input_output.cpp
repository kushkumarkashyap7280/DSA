#include <iostream>
#include <string>
using namespace std;

int main()
{
  // 1. Basic Input/Output
  int age;
  cout << "Enter your age: ";
  cin >> age;
  cout << "Your age is: " << age << endl;

  // 2. Multiple inputs
  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;
  cout << "Sum: " << num1 + num2 << endl;

  // 3. Character input
  char ch;
  cout << "Enter a character: ";
  cin >> ch;
  cout << "ASCII value of " << ch << " is: " << (int)ch << endl;

  // 4. String input (single word)
  string name;
  cout << "Enter your name (single word): ";
  cin >> name;
  cout << "Hello, " << name << endl;

  // 5. String input with spaces
  cin.ignore(); // Clear buffer
  string fullName;
  cout << "Enter your full name: ";
  getline(cin, fullName);
  cout << "Hello, " << fullName << endl;

  // 6. Type-safe input
  cout << "Enter a number: ";
  if (cin >> num1)
  {
    cout << "Valid input: " << num1 << endl;
  }
  else
  {
    cout << "Invalid input!" << endl;
    cin.clear();             // Clear error flag
    cin.ignore(10000, '\n'); // Clear buffer
  }

  return 0;
}
