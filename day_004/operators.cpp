#include <iostream>
using namespace std;

int main()
{
  int a = 10, b = 5;

  // 1. Arithmetic Operators
  cout << "=== Arithmetic Operators ===" << endl;
  cout << "Addition: " << a + b << endl;       // 15
  cout << "Subtraction: " << a - b << endl;    // 5
  cout << "Multiplication: " << a * b << endl; // 50
  cout << "Division: " << a / b << endl;       // 2
  cout << "Modulus: " << a % b << endl;        // 0

  // 2. Relational Operators
  cout << "\n=== Relational Operators ===" << endl;
  cout << "Equal to: " << (a == b) << endl;      // 0
  cout << "Not equal: " << (a != b) << endl;     // 1
  cout << "Greater than: " << (a > b) << endl;   // 1
  cout << "Less than: " << (a < b) << endl;      // 0
  cout << "Greater equal: " << (a >= b) << endl; // 1
  cout << "Less equal: " << (a <= b) << endl;    // 0

  // 3. Logical Operators
  bool x = true, y = false;
  cout << "\n=== Logical Operators ===" << endl;
  cout << "AND: " << (x && y) << endl; // 0
  cout << "OR: " << (x || y) << endl;  // 1
  cout << "NOT: " << (!x) << endl;     // 0

  // 4. Bitwise Operators
  cout << "\n=== Bitwise Operators ===" << endl;
  cout << "AND: " << (a & b) << endl;          // Bitwise AND
  cout << "OR: " << (a | b) << endl;           // Bitwise OR
  cout << "XOR: " << (a ^ b) << endl;          // Bitwise XOR
  cout << "Left shift: " << (a << 1) << endl;  // Multiply by 2
  cout << "Right shift: " << (a >> 1) << endl; // Divide by 2

  // 5. Assignment Operators
  int c = a; // Simple assignment
  c += a;    // c = c + a
  c -= a;    // c = c - a
  c *= a;    // c = c * a
  c /= a;    // c = c / a
  c %= a;    // c = c % a

  // 6. Increment/Decrement
  cout << "\n=== Increment/Decrement ===" << endl;
  cout << "Pre-increment: " << ++a << endl;
  cout << "Post-increment: " << a++ << endl;
  cout << "Pre-decrement: " << --b << endl;
  cout << "Post-decrement: " << b-- << endl;

  // 7. Conditional (Ternary) Operator
  cout << "\n=== Ternary Operator ===" << endl;
  int result = (a > b) ? a : b;
  cout << "Maximum is: " << result << endl;

  return 0;
}
