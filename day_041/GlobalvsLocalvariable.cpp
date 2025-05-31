#include <iostream>
using namespace std;

// Global variables (file scope)
int globalVar = 10;
const int MAX_VALUE = 100;

// Global variable with static duration
static int staticGlobal = 5;

// Function to demonstrate variable scope
void demoFunction()
{
  // Local variable
  int localVar = 20;

  // Static local variable (retains value between function calls)
  static int staticLocal = 0;
  staticLocal++;

  cout << "\n=== Inside demoFunction ===" << endl;
  cout << "Local variable: " << localVar << endl;
  cout << "Static local variable: " << staticLocal << endl;
  cout << "Global variable: " << globalVar << endl;

  // Block scope demonstration
  {
    int blockVar = 30;
    cout << "\nInside block:" << endl;
    cout << "Block variable: " << blockVar << endl;
    cout << "Can access local var: " << localVar << endl;
    cout << "Can access global var: " << globalVar << endl;
  }
  // blockVar is not accessible here
}

// Function showing parameter scope
void parameterScope(int paramVar)
{
  cout << "\n=== Parameter Scope ===" << endl;
  cout << "Parameter variable: " << paramVar << endl;
  cout << "Global variable: " << globalVar << endl;
}

int main()
{
  cout << "=== Initial Values ===" << endl;
  cout << "Global variable: " << globalVar << endl;
  cout << "Static global: " << staticGlobal << endl;

  // Local variable in main
  int mainLocal = 50;
  cout << "Main local variable: " << mainLocal << endl;

  // Call demoFunction multiple times to show static variable behavior
  for (int i = 0; i < 3; i++)
  {
    cout << "\nCall #" << (i + 1) << " to demoFunction:" << endl;
    demoFunction();
  }

  // Demonstrate parameter scope
  parameterScope(100);

  // Demonstrate variable shadowing
  int globalVar = 1000; // Local variable shadows global variable
  cout << "\n=== Variable Shadowing ===" << endl;
  cout << "Local globalVar (shadows global): " << globalVar << endl;
  cout << "Global globalVar (using ::): " << ::globalVar << endl;

  return 0;
}
