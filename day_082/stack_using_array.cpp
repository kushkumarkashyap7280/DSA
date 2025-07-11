// here we implement stack using array;
// here we implement stack using array

#include <iostream>
using namespace std;

// Stack class using array
class myStack
{
  int index;    // Points to the top element in the stack (-1 means empty)
  int size_;    // Maximum size of the stack
  int *arr;     // Pointer to the array holding stack elements

public:
  // Constructor: initializes stack with given size
  myStack(int size) : index(-1), size_(size), arr(new int[size]) {};

  // Destructor: releases allocated memory
  ~myStack()
  {
    delete[] arr;
  }

  // Checks if the stack is empty
  bool isEmpty()
  {
    return index == -1;
  }

  // Pushes a value onto the stack
  void push(int val)
  {
    if (index >= size_ - 1)
      throw runtime_error("stack is already full"); // Overflow check
    index++;
    arr[index] = val;
  }

  // Pops the top value from the stack
  void pop()
  {
    if (isEmpty())
      throw runtime_error("stack is already empty"); // Underflow check
    arr[index] = 0; // Optional: clear the value (not necessary for stack logic)
    index--;
  }

  // Returns the top value of the stack without removing it
  int peak()
  {
    if (isEmpty())
      throw runtime_error("stack is empty");
    return arr[index];
  }

  // Returns the current number of elements in the stack
  int size()
  {
    return index + 1;
  }

  // Prints the stack from top to bottom
  void transverse()
  {
    if (isEmpty())
    {
      cout << "Stack is empty.\n";
      return;
    }

    cout << "Stack from top to bottom:\n";
    for (int i = index; i >= 0; i--)
    {
      cout << arr[i];
      if (i > 0)
      {
        cout << "\n ^ \n | \n"; // Visual separator
      }
    }
    cout << endl;
  }
};

int main()
{
  int stackSize;
  cout << "Enter stack size: ";
  cin >> stackSize;

  myStack s(stackSize); // Create stack object

  while (true)
  {
    // Menu for stack operations
    cout << "\nChoose an operation:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Size\n";
    cout << "5. iterate\n";
    cout << "6. Exit\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    try
    {
      if (choice == 1)
      {
        int val;
        cout << "Enter value to push: ";
        cin >> val;
        s.push(val);
        cout << "Pushed " << val << ".\n";
      }
      else if (choice == 2)
      {
        int topVal = s.peak(); // Get value before popping
        s.pop();
        cout << "Popped " << topVal << ".\n";
      }
      else if (choice == 3)
      {
        cout << "Top of stack: " << s.peak() << endl;
      }
      else if (choice == 4)
      {
        cout << "Current size: " << s.size() << endl;
      }
      else if (choice == 5)
      {
        s.transverse();
      }
      else if (choice == 6)
      {
        cout << "Exiting.\n";
        break;
      }
      else
      {
        cout << "Invalid choice.\n";
      }
    }
    catch (const exception &e)
    {
      cout << "Error: " << e.what() << endl; // Handle stack errors
    }
  }

  return 0;
}
#include <iostream>
using namespace std;

class myStack
{
  int index;
  int size_;
  int *arr;

public:
  myStack(int size) : index(-1), size_(size), arr(new int[size]) {};

  ~myStack()
  {
    delete[] arr;
  }

  bool isEmpty()
  {
    return index == -1;
  }

  void push(int val)
  {
    if (index >= size_ - 1)
      throw runtime_error("stack is already full");
    index++;
    arr[index] = val;
  }
  void pop()
  {

    if (isEmpty())
      throw runtime_error("stack is already empty");
    arr[index] = 0;
    index--;
  }
  int peak()
  {
    if (isEmpty())
      throw runtime_error("stack is empty");
    return arr[index];
  }
  int size()
  {
    return index + 1;
  }

  void transverse()
  {
    if (isEmpty())
    {
      cout << "Stack is empty.\n";
      return;
    }

    cout << "Stack from top to bottom:\n";
    for (int i = index; i >= 0; i--)
    {
      cout << arr[i];
      if (i > 0)
      {
        cout << "\n ^ \n | \n";
      }
    }
    cout << endl;
  }
};
int main()
{
  int stackSize;
  cout << "Enter stack size: ";
  cin >> stackSize;

  myStack s(stackSize);

  while (true)
  {
    cout << "\nChoose an operation:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Size\n";
    cout << "5. iterate\n";
    cout << "6. Exit\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    try
    {
      if (choice == 1)
      {
        int val;
        cout << "Enter value to push: ";
        cin >> val;
        s.push(val);
        cout << "Pushed " << val << ".\n";
      }
      else if (choice == 2)
      {
        int topVal = s.peak();
        s.pop();
        cout << "Popped " << topVal << ".\n";
      }
      else if (choice == 3)
      {
        cout << "Top of stack: " << s.peak() << endl;
      }
      else if (choice == 4)
      {
        cout << "Current size: " << s.size() << endl;
      }
      else if (choice == 5)
      {
        s.transverse();
      }
      else if (choice == 6)
      {
        cout << "Exiting.\n";
        break;
      }
      else
      {
        cout << "Invalid choice.\n";
      }
    }
    catch (const exception &e)
    {
      cout << "Error: " << e.what() << endl;
    }
  }

  return 0;
}
