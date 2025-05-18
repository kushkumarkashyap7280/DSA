#include <iostream>
using namespace std;

int main()
{
  // Basic pointer declaration and initialization
  int num = 10;
  int *ptr = &num;

  cout << "=== Basic Pointer Operations ===" << endl;
  cout << "Value of num: " << num << endl;
  cout << "Address of num: " << &num << endl;
  cout << "Value of ptr: " << ptr << endl;
  cout << "Value at ptr: " << *ptr << endl;

  // Pointer arithmetic
  int arr[] = {1, 2, 3, 4, 5};
  int *arrPtr = arr;

  cout << "\n=== Pointer Arithmetic ===" << endl;
  cout << "First element: " << *arrPtr << endl;
  cout << "Second element: " << *(arrPtr + 1) << endl;

  // Double pointer
  int **doublePtr = &ptr;
  cout << "\n=== Double Pointer ===" << endl;
  cout << "Value at double pointer: " << **doublePtr << endl;

  // Null pointer
  int *nullPtr = nullptr;
  cout << "\n=== Null Pointer ===" << endl;
  cout << "Null pointer value: " << nullPtr << endl;

  return 0;
}
