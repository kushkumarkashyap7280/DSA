#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Reverse first K of a Queue
//  link - https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

/*
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
*/

// Time Complexity: O(N), where N = q.size()
// Space Complexity: O(K) for the stack (worst case)
queue<int> reverseFirstK(queue<int> q, int k)
{
  if (q.empty() || k <= 0 || k > (int)q.size())
    return q;
  int size = q.size();
  stack<int> s;
  int i = 0;
  while (i < min(size, k))
  {
    s.push(q.front());
    q.pop();
    i++;
  }
  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }
  for (int j = 0; j < size - k; j++)
  {
    q.push(q.front());
    q.pop();
  }
  return q;
}

void printQueue(queue<int> q)
{
  cout << "[";
  while (!q.empty())
  {
    cout << q.front();
    q.pop();
    if (!q.empty())
      cout << ", ";
  }
  cout << "]" << endl;
}

queue<int> makeQueue(const vector<int> &v)
{
  queue<int> q;
  for (int x : v)
    q.push(x);
  return q;
}

int main()
{
  // Test case 1
  vector<int> v1 = {1, 2, 3, 4, 5};
  int k1 = 3;
  cout << "Test case 1: ";
  printQueue(reverseFirstK(makeQueue(v1), k1)); // Expected: [3, 2, 1, 4, 5]

  // Test case 2
  vector<int> v2 = {4, 3, 2, 1};
  int k2 = 4;
  cout << "Test case 2: ";
  printQueue(reverseFirstK(makeQueue(v2), k2)); // Expected: [1, 2, 3, 4]

  // Test case 3: k > size
  vector<int> v3 = {10, 20, 30};
  int k3 = 5;
  cout << "Test case 3: ";
  printQueue(reverseFirstK(makeQueue(v3), k3)); // Expected: [10, 20, 30]

  // Test case 4: k = 0
  vector<int> v4 = {7, 8, 9};
  int k4 = 0;
  cout << "Test case 4: ";
  printQueue(reverseFirstK(makeQueue(v4), k4)); // Expected: [7, 8, 9]

  // Test case 5: k = 1
  vector<int> v5 = {5, 6, 7, 8};
  int k5 = 1;
  cout << "Test case 5: ";
  printQueue(reverseFirstK(makeQueue(v5), k5)); // Expected: [5, 6, 7, 8]

  // Test case 6: all elements reversed
  vector<int> v6 = {1, 2, 3, 4, 5};
  int k6 = 5;
  cout << "Test case 6: ";
  printQueue(reverseFirstK(makeQueue(v6), k6)); // Expected: [5, 4, 3, 2, 1]

  return 0;
}