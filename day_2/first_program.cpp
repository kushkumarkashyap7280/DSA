// Single line comment
/*
   Multi-line comment
   Explains multiple lines of code
*/

// Header file that contains input/output functionality
#include <iostream> // iostream = input/output stream

// Using namespace std to avoid writing std:: before cout, cin, endl
// Not recommended in large projects but okay for learning
using namespace std;

// Main function - program execution starts here
// int - return type of the function
// main - special name recognized by compiler as starting point
// () - can contain parameters (empty in this case)
int main()
{
  // cout - Console output
  // << - Insertion operator (puts data into cout stream)
  // endl - Ends current line and flushes output buffer
  cout << "Hello World!" << endl;

  // Example of different ways to print
  cout << "Multiple " << "strings " << "can be " << "concatenated" << endl;

  // \n is another way to create new line
  cout << "First line\nSecond line\n";

  // return 0 indicates successful program execution
  // required because main() return type is int
  return 0;
}

/*
Program Structure Explanation:
1. Preprocessor directives (#include) - Tells compiler to include header files
2. Namespace declaration - Specifies scope for identifiers
3. Main function - Entry point of program
4. Function body - Contains actual program code
5. Return statement - Indicates program completion status

Compilation Process:
1. Preprocessing - Expands #include and macros
2. Compilation - Converts C++ to object code
3. Linking - Combines object code with libraries
4. Loading - Creates executable file
*/
