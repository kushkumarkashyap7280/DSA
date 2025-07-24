#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// First negative in every window of size k
//  link - https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

/*
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
Note: If a window does not contain a negative integer, then return 0 for that window.
*/

// Time Complexity: O(N), where N = arr.size()
// Space Complexity: O(K) for the deque (worst case)
vector<int> firstNegInt(const vector<int> &arr, int k)
{
  int s = arr.size();
  vector<int> ans;
  deque<int> window;

  // Edge case: if window size is invalid
  if (s < k || k == 0)
    return ans;

  // First window
  for (int i = 0; i < k; i++)
  {
    if (arr[i] < 0)
      window.push_back(i);
  }

  // Add result for first window
  if (!window.empty())
  {
    ans.push_back(arr[window.front()]);
  }
  else
  {
    ans.push_back(0);
  }

  // Process remaining windows
  for (int i = k; i < s; i++)
  {
    // Remove out-of-window indices
    while (!window.empty() && window.front() < i - k + 1)
    {
      window.pop_front();
    }

    // Add current element if it's negative
    if (arr[i] < 0)
      window.push_back(i);

    // Add result for current window
    if (!window.empty())
    {
      ans.push_back(arr[window.front()]);
    }
    else
    {
      ans.push_back(0);
    }
  }

  return ans;
}

void printVector(const vector<int> &v)
{
  cout << "[";
  for (size_t i = 0; i < v.size(); ++i)
  {
    cout << v[i];
    if (i + 1 < v.size())
      cout << ", ";
  }
  cout << "]" << endl;
}

int main()
{
  // Test case 1
  vector<int> arr1 = {-8, 2, 3, -6, 10};
  int k1 = 2;
  cout << "Test case 1: ";
  printVector(firstNegInt(arr1, k1)); // Expected: [-8, 0, -6, -6]

  // Test case 2
  vector<int> arr2 = {12, -1, -7, 8, -15, 30, 16, 28};
  int k2 = 3;
  cout << "Test case 2: ";
  printVector(firstNegInt(arr2, k2)); // Expected: [-1, -1, -7, -15, -15, 0]

  // Test case 3
  vector<int> arr3 = {12, 1, 3, 5};
  int k3 = 3;
  cout << "Test case 3: ";
  printVector(firstNegInt(arr3, k3)); // Expected: [0, 0]

  // Additional test case: all negatives
  vector<int> arr4 = {-1, -2, -3, -4};
  int k4 = 2;
  cout << "Test case 4: ";
  printVector(firstNegInt(arr4, k4)); // Expected: [-1, -2, -3]

  // Additional test case: all positives
  vector<int> arr5 = {1, 2, 3, 4};
  int k5 = 2;
  cout << "Test case 5: ";
  printVector(firstNegInt(arr5, k5)); // Expected: [0, 0, 0]

  return 0;
}