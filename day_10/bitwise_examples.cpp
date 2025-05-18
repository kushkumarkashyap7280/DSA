#include <iostream>
using namespace std;

int main()
{
  // Basic operations
  int a = 5, b = 3;
  cout << "AND: " << (a & b) << endl;
  cout << "OR: " << (a | b) << endl;
  cout << "XOR: " << (a ^ b) << endl;
  cout << "Left Shift: " << (a << 1) << endl;
  cout << "Right Shift: " << (a >> 1) << endl;
  cout << "NOT: " << (~a) << endl;

  // Common applications
  // Check if number is even
  cout << "Is 5 even? " << ((a & 1) == 0) << endl;

  // Multiply by 2
  cout << "5 * 2 = " << (a << 1) << endl;

  // Divide by 2
  cout << "5 / 2 = " << (a >> 1) << endl;

  // Swap numbers using XOR
  int x = 5, y = 10;
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  cout << "After swap: x = " << x << ", y = " << y << endl;

  return 0;
}
