// heap sort

// link - https://www.geeksforgeeks.org/problems/heap-sort/1

/*
Given an array arr[]. The task is to sort the array elements by Heap Sort.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
Input: arr[] = [2, 1, 5]
Output: [1, 2, 5]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/

// Standard includes
#include <bits/stdc++.h>
using namespace std;

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution
{
public:
  void heapify(vector<int> &arr, int n, int i)
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
      largest = l;
    if (r < n && arr[r] > arr[largest])
      largest = r;
    if (largest != i)
    {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }

  void heapSort(vector<int> &arr)
  {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }
};

// ---------------------
// Test Infrastructure
// ---------------------
static void expectEq(const vector<int> &got, const vector<int> &want, const string &testName)
{
  if (got != want)
  {
    cerr << "[FAIL] " << testName << ": expected [";
    for (size_t i = 0; i < want.size(); ++i)
      cerr << want[i] << (i + 1 < want.size() ? ", " : "");
    cerr << "], got [";
    for (size_t i = 0; i < got.size(); ++i)
      cerr << got[i] << (i + 1 < got.size() ? ", " : "");
    cerr << "]\n";
    exit(1);
  }
  else
  {
    cout << "[PASS] " << testName << "\n";
  }
}

static void runTests()
{
  Solution sol;
  {
    vector<int> arr{4, 1, 3, 9, 7};
    vector<int> want{1, 3, 4, 7, 9};
    sol.heapSort(arr);
    expectEq(arr, want, "Example 1");
  }
  {
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> want{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sol.heapSort(arr);
    expectEq(arr, want, "Example 2");
  }
  {
    vector<int> arr{2, 1, 5};
    vector<int> want{1, 2, 5};
    sol.heapSort(arr);
    expectEq(arr, want, "Example 3");
  }
  {
    vector<int> arr{5};
    vector<int> want{5};
    sol.heapSort(arr);
    expectEq(arr, want, "Single element");
  }
  {
    vector<int> arr{};
    vector<int> want{};
    sol.heapSort(arr);
    expectEq(arr, want, "Empty array");
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  runTests();
  return 0;
}