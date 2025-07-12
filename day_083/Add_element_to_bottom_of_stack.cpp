// Insert An Element At Its Bottom In A Given Stack
// link - https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

/*
Given a stack and an element x, insert x at the bottom of the stack.
*/

#include <iostream>
#include <stack>
using namespace std;

// Time: O(N), Space: O(N) (due to recursion stack)
stack<int> pushAtBottom(stack<int> myStack, int x)
{
  if (myStack.empty())
  {
    myStack.push(x);
    return myStack;
  }
  int top = myStack.top();
  myStack.pop();
  myStack = pushAtBottom(myStack, x);
  myStack.push(top);
  return myStack;
}

// Utility function to print stack from top to bottom
void printStack(stack<int> s)
{
  cout << "Stack (top to bottom): ";
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  cout << "Original stack: ";
  printStack(s);
  int x = 5;
  s = pushAtBottom(s, x);
  cout << "Stack after pushing " << x << " at bottom: ";
  printStack(s);
  return 0;
}