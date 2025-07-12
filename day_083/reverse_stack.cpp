// reverse stack
// link - https://www.geeksforgeeks.org/problems/reverse-a-stack/1

/*
You are given a stack St. You have to reverse the stack using recursion or iteration.
*/

#include <iostream>
#include <stack>
using namespace std;

// Recursive approach
// Time: O(N^2), Space: O(N) (due to recursion stack)
void insertAtBottom(stack<int> &s, int x)
{
  if (s.empty())
  {
    s.push(x);
    return;
  }
  int top = s.top();
  s.pop();
  insertAtBottom(s, x);
  s.push(top);
}

void ReverseRecursive(stack<int> &s)
{
  if (s.empty())
    return;
  int top = s.top();
  s.pop();
  ReverseRecursive(s);
  insertAtBottom(s, top);
}

// Iterative approach
// Time: O(N), Space: O(N)
void Reverse(stack<int> &St)
{
  stack<int> temp;
  while (!St.empty())
  {
    temp.push(St.top());
    St.pop();
  }
  St = temp;
  return;
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
  s.push(3);
  s.push(2);
  s.push(1);
  s.push(7);
  s.push(6);
  cout << "Original stack: ";
  printStack(s);

  // Iterative approach
  Reverse(s);
  cout << "Reversed stack (iterative): ";
  printStack(s);

  // Reverse again using recursive approach to restore original order
  ReverseRecursive(s);
  cout << "Reversed stack (recursive): ";
  printStack(s);

  return 0;
}