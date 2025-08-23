#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

// Merge two binary Max heaps
//  Link: https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

/*
Problem Description:
Given two binary max heaps as arrays, merge them to form a new max heap.
The resulting heap should maintain the max-heap property: each parent node
should be greater than or equal to its children.

Time Complexity: O(N log N), where N = n + m
- Merging arrays: O(n + m)
- Building heap: O(N log N) where N = n + m
  * We perform heapify from n/2-1 to 0
  * Each heapify operation takes O(log N)

Space Complexity: O(1) excluding output
- Only constant extra space used
- Modifying input array a in-place
- No recursive stack space as heapify uses tail recursion

Example Test Cases:

1. Basic Case:
   Heap1: [10, 5, 6, 2]
          10
         /  \
        5    6
       /
      2

   Heap2: [12, 7, 9]
          12
         /  \
        7    9

   Result: [12, 10, 9, 2, 5, 7, 6]
          12
         /  \
        10   9
       / \  / \
      2   5 7  6

2. Equal Size Heaps:
   Input: a = [8, 4, 6], b = [9, 5, 7]
   Output: [9, 8, 7, 4, 5, 6]

3. Single Element Heaps:
   Input: a = [10], b = [15]
   Output: [15, 10]

4. One Empty Heap:
   Input: a = [20, 10, 15], b = []
   Output: [20, 10, 15]

5. All Equal Elements:
   Input: a = [5, 5], b = [5, 5]
   Output: [5, 5, 5, 5]

Approach:
1. Append second heap to first heap
2. Build max heap using bottom-up heapify
3. For bottom-up build:
   - Start from last non-leaf node (n/2-1)
   - Heapify each node going up to root
   - Each heapify ensures max-heap property for subtree
*/

// User function Template for C++

class Solution
{
  void heapify(vector<int> &a, int i, int n)
  {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    // Compare with left child
    if (left < n && a[left] > a[largest])
    {
      largest = left;
    }
    // Compare with right child
    if (right < n && a[right] > a[largest])
    {
      largest = right;
    }
    // If largest is not root
    if (largest != i)
    {
      swap(a[largest], a[i]);
      // Recursively heapify the affected sub-tree
      heapify(a, largest, n);
    }
  }

public:
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
  {
    // Step 1: Append second heap to first heap
    a.insert(a.end(), b.begin(), b.end());

    // Step 2: Build max heap using bottom-up heapify
    for (int i = (n + m) / 2 - 1; i >= 0; i--)
    {
      heapify(a, i, n + m);
    }

    return a;
  }
};

// Test function to print vector
void printVector(const vector<int> &v)
{
  for (int x : v)
  {
    cout << x << " ";
  }
  cout << endl;
}

// Function to verify max heap property
bool isMaxHeap(const vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n / 2; i++)
  {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[i] < arr[left])
      return false;
    if (right < n && arr[i] < arr[right])
      return false;
  }
  return true;
}

// Test cases
void runTests()
{
  Solution sol;

  // Test Case 1: Basic case from problem statement
  {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> result = sol.mergeHeaps(a, b, 4, 3);
    cout << "Test Case 1: ";
    printVector(result);
    cout << "Is Max Heap: " << (isMaxHeap(result) ? "Yes" : "No") << endl;
  }

  // Test Case 2: Equal size heaps
  {
    vector<int> a = {8, 4, 6};
    vector<int> b = {9, 5, 7};
    vector<int> result = sol.mergeHeaps(a, b, 3, 3);
    cout << "Test Case 2: ";
    printVector(result);
    cout << "Is Max Heap: " << (isMaxHeap(result) ? "Yes" : "No") << endl;
  }

  // Test Case 3: Single element heaps
  {
    vector<int> a = {10};
    vector<int> b = {15};
    vector<int> result = sol.mergeHeaps(a, b, 1, 1);
    cout << "Test Case 3: ";
    printVector(result);
    cout << "Is Max Heap: " << (isMaxHeap(result) ? "Yes" : "No") << endl;
  }

  // Test Case 4: One empty heap
  {
    vector<int> a = {20, 10, 15};
    vector<int> b = {};
    vector<int> result = sol.mergeHeaps(a, b, 3, 0);
    cout << "Test Case 4: ";
    printVector(result);
    cout << "Is Max Heap: " << (isMaxHeap(result) ? "Yes" : "No") << endl;
  }

  // Test Case 5: All equal elements
  {
    vector<int> a = {5, 5};
    vector<int> b = {5, 5};
    vector<int> result = sol.mergeHeaps(a, b, 2, 2);
    cout << "Test Case 5: ";
    printVector(result);
    cout << "Is Max Heap: " << (isMaxHeap(result) ? "Yes" : "No") << endl;
  }
}

// Main function to run tests
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  runTests();
  return 0;
}
