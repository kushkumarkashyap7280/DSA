// sort stack

// link - https://www.geeksforgeeks.org/problems/sort-a-stack/1

#include <iostream>
#include <stack>
using namespace std;

/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task:
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100
*/

// ✅ Time: 
// 𝑂(𝑛2)
//  )
// ✅ Space: 
// 𝑂(𝑛)

class SortedStack
{
public:
  stack<int> s;
  void sort();
};

// Helper function to insert an element in sorted order
void insertSorted(stack<int> &s, int toInsert)
{
  if (s.empty() || toInsert > s.top())
  {
    s.push(toInsert);
    return;
  }
  int temp = s.top();
  s.pop();
  insertSorted(s, toInsert);
  s.push(temp);
}

void SortedStack::sort()
{
  if (s.empty())
    return;
  int top = s.top();
  s.pop();
  sort();
  insertSorted(s, top);
}

// For local testing
int main()
{
  SortedStack ss;
  // Example: 11 2 32 3 41
  int arr[] = {11, 2, 32, 3, 41};
  for (int x : arr)
    ss.s.push(x);
  ss.sort();
  cout << "Sorted stack (top to bottom): ";
  while (!ss.s.empty())
  {
    cout << ss.s.top() << " ";
    ss.s.pop();
  }
  cout << endl;
  return 0;
}