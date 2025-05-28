// what is a reference variable in C++?
// A reference variable in C++ is an alias for another variable. It allows you to create a new name for an existing variable, enabling you to manipulate the original variable through the reference.
// Reference variables are created using the `&` operator in the variable declaration.
// They must be initialized when declared and cannot be changed to refer to another variable later.
// Reference variables are particularly useful for passing arguments to functions without copying the data, thus improving performance.
// Example of a reference variable in C++
#include <iostream>
using namespace std;
// here we demostrate the use of a reference variable in C++
// pass by reference and pass by value
int add(int b) {
    return b + 10; // Pass by value
}
int addRef(int &b) {
    b += 10; // Pass by reference
    return b;
}


int main() {
 int i = 10; // Original variable
 int &ref = i; // Reference variable
  cout << "Original variable i: " << i << endl; // Output: 10
  cout << "Reference variable ref: " << ref << endl; // Output: 10
  cout << "Address of original variable i: " << &i << endl; // Output: Address of i
  cout << "Address of reference variable ref: " << &ref << endl; // Output: Same address as i
  ref = 20; // Modifying the reference variable
  cout << "After modifying ref, original variable i: " << i << endl; // Output: 20
  cout << "After modifying ref, reference variable ref: " << ref << endl; // Output: 20

  int a = 5;
  int b = add(a); // Pass by value, a remains unchanged
  cout << "After add(a), a: " << a << ", b: " << b << endl; // Output: a: 5, b: 15
  int c = 5;
  int d = addRef(c); // Pass by reference, c is modified
  cout << "After addRef(c), c: " << c << ", d: " << d << endl; // Output: c: 15, d: 15
   
return 0;
}