#include <iostream>
#include <climits> // For integer limits
#include <cfloat>  // For floating-point limits
using namespace std;

int main()
{
  cout << "=== Integer Ranges ===" << endl;
  cout << "int: " << INT_MIN << " to " << INT_MAX << endl;
  cout << "unsigned int: 0 to " << UINT_MAX << endl;
  cout << "short: " << SHRT_MIN << " to " << SHRT_MAX << endl;
  cout << "long: " << LONG_MIN << " to " << LONG_MAX << endl;

  cout << "\n=== Floating Point Ranges ===" << endl;
  cout << "float: " << FLT_MIN << " to " << FLT_MAX << endl;
  cout << "double: " << DBL_MIN << " to " << DBL_MAX << endl;

  cout << "\n=== Precision ===" << endl;
  cout << "float precision: " << FLT_DIG << " digits" << endl;
  cout << "double precision: " << DBL_DIG << " digits" << endl;

  return 0;
}
