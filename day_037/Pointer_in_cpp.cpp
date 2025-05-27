// Pointers in C++: Pointers are variables that store the memory address of another variable. They are used for dynamic memory allocation, arrays, and functions.

#include <iostream>
using namespace std;

// Function to demonstrate function pointers
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Function that takes a function pointer as parameter
int operate(int x, int y, int (*operation)(int, int))
{
  return operation(x, y);
}

// Class to demonstrate this pointer and pointer to objects
class MyClass
{
private:
  int value;

public:
  MyClass(int v) : value(v) {}

  // Using 'this' pointer
  void compareWithThis(const MyClass *other)
  {
    if (this->value > other->value)
    {
      cout << "Current object is larger" << endl;
    }
    else
    {
      cout << "Other object is larger or equal" << endl;
    }
  }

  int getValue() const { return value; }
};

int main()
{
  cout << "\n=== Basic Pointer Declaration and Usage ===" << endl;

  // 1. Basic pointer declaration and initialization
  int number = 42;
  int *pointer; // Pointer declaration  it is just initialized, not pointing to anything yet , it can risk undefined behavior if dereferenced
  int *ptr = &number; // & operator gets the address
  cout << "Value of number: " << number << endl;
  cout << "Address of number: " << ptr << endl;
  cout << "Value through pointer: " << *ptr << endl; // * operator dereferences

  // 2. Null pointers
  cout << "\n=== Null Pointers ===" << endl;
  int *nullPtr = nullptr; // Modern C++ null pointer
  if (nullPtr == nullptr)
  {
    cout << "Pointer is null" << endl;
  }

  // 3. Pointer arithmetic
  cout << "\n=== Pointer Arithmetic ===" << endl;
  int arr[] = {1, 2, 3, 4, 5};
  int *arrPtr = arr;
  cout << "First element: " << *arrPtr << endl;
  arrPtr++; // Move to next element
  cout << "Second element: " << *arrPtr << endl;
  arrPtr += 2; // Skip two elements
  cout << "Fourth element: " << *arrPtr << endl;

  // 4. Dynamic memory allocation
  cout << "\n=== Dynamic Memory Allocation ===" << endl;

  // Single element
  int *dynamicInt = new int(100);
  cout << "Dynamically allocated int: " << *dynamicInt << endl;
  delete dynamicInt; // Free the memory

  // Array allocation
  int *dynamicArray = new int[5];
  for (int i = 0; i < 5; i++)
  {
    dynamicArray[i] = i * 10;
  }
  cout << "Dynamic array elements: ";
  for (int i = 0; i < 5; i++)
  {
    cout << dynamicArray[i] << " ";
  }
  cout << endl;
  delete[] dynamicArray; // Free the array

  // 5. Pointer to pointer (Double pointer)
  cout << "\n=== Double Pointers ===" << endl;
  int value = 100;
  int *singlePtr = &value;
  int **doublePtr = &singlePtr;
  cout << "Value through double pointer: " << **doublePtr << endl;

  // 6. Function pointers
  cout << "\n=== Function Pointers ===" << endl;
  int (*funcPtr)(int, int) = add; // Function pointer declaration
  cout << "Add through function pointer: " << funcPtr(5, 3) << endl;

  // Using function pointer as parameter
  cout << "Add using operate: " << operate(10, 5, add) << endl;
  cout << "Subtract using operate: " << operate(10, 5, subtract) << endl;

  // 7. Pointer to objects
  cout << "\n=== Pointers to Objects ===" << endl;
  MyClass obj1(50);
  MyClass obj2(30);
  MyClass *objPtr = &obj1;

  cout << "Value through object pointer: " << objPtr->getValue() << endl;
  objPtr->compareWithThis(&obj2);

  // 8. Const pointers
  cout << "\n=== Const Pointers ===" << endl;
  int x = 10, y = 20;

  // Pointer to constant value
  const int *ptr1 = &x;
  // *ptr1 = 20;  // Error: can't modify value
  ptr1 = &y; // OK: can change pointer

  // Constant pointer
  int *const ptr2 = &x;
  *ptr2 = 30; // OK: can modify value
  // ptr2 = &y;   // Error: can't change pointer

  // Constant pointer to constant value
  const int *const ptr3 = &x;
  // *ptr3 = 40;  // Error: can't modify value
  // ptr3 = &y;   // Error: can't change pointer

  cout << "Value of x after modifications: " << x << endl;

  // 9. Smart Pointers (Modern C++)
  cout << "\n=== Smart Pointers (Comment Example) ===" << endl;
  cout << "In modern C++, we have smart pointers:" << endl;
  cout << "- unique_ptr: Single owner of the pointer" << endl;
  cout << "- shared_ptr: Reference counted ownership" << endl;
  cout << "- weak_ptr: Non-owning reference to shared_ptr" << endl;

  return 0;
}