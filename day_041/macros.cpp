// here we going to learn marcos
#include <iostream>
using namespace std;

// 1. Object-like Macros (Simple Constants)
#define PI 3.14159
#define MAX_SIZE 100
#define NEWLINE '\n'

// 2. Function-like Macros
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// 3. Multi-line Macros
#define PRINT_INFO(x)                \
  cout << "Value: " << x << NEWLINE; \
  cout << "Square: " << SQUARE(x) << NEWLINE

// 4. Conditional Compilation Macros
#define DEBUG 1

#ifdef DEBUG
#define LOG(x) cout << "Debug: " << x << NEWLINE
#else
#define LOG(x)
#endif

// 5. Stringizing Operator (#)
#define STRINGIFY(x) #x
#define PRINT_VAR(var) cout << #var << " = " << var << NEWLINE

// 6. Token Pasting Operator (##)
#define CONCAT(a, b) a##b

// 7. Predefined Macros
void printPredefinedMacros()
{
  cout << "File: " << __FILE__ << NEWLINE;
  cout << "Line: " << __LINE__ << NEWLINE;
  cout << "Date: " << __DATE__ << NEWLINE;
  cout << "Time: " << __TIME__ << NEWLINE;
  cout << "ANSI: " << __STDC__ << NEWLINE;
}

int main()
{
  // 1. Object-like Macros
  cout << "=== Object-like Macros ===" << NEWLINE;
  cout << "PI: " << PI << NEWLINE;
  cout << "MAX_SIZE: " << MAX_SIZE << NEWLINE;

  // 2. Function-like Macros
  cout << "\n=== Function-like Macros ===" << NEWLINE;
  int a = 5, b = 7;
  cout << "Square of 5: " << SQUARE(5) << NEWLINE;
  cout << "Max of 5 and 7: " << MAX(a, b) << NEWLINE;
  cout << "Min of 5 and 7: " << MIN(a, b) << NEWLINE;

  // 3. Multi-line Macros
  cout << "\n=== Multi-line Macro ===" << NEWLINE;
  PRINT_INFO(10);

  // 4. Conditional Compilation
  cout << "\n=== Conditional Compilation ===" << NEWLINE;
  LOG("This is a debug message");

  // 5. Stringizing Operator
  cout << "\n=== Stringizing Operator ===" << NEWLINE;
  cout << STRINGIFY(Hello World) << NEWLINE;
  int x = 42;
  PRINT_VAR(x);

  // 6. Token Pasting
  cout << "\n=== Token Pasting ===" << NEWLINE;
  int value1 = 10;
  int CONCAT(val, ue2) = 20; // Creates variable 'value2'
  cout << "value1 = " << value1 << ", value2 = " << value2 << NEWLINE;

  // 7. Predefined Macros
  cout << "\n=== Predefined Macros ===" << NEWLINE;
  printPredefinedMacros();

  return 0;
}