// quick sorting using recursion
// LeetCode: https://leetcode.com/problems/sort-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int> &arr, int l, int r)
{

  if (l >= r)
    return;
  int pivot = arr[l];

  int count = 0;

  for (int i = l + 1; i <= r; i++)
  {
    if (arr[i] < pivot)
      count++;
  }
  int pivotIndex = l + count;
  swap(arr[l], arr[pivotIndex]);

  int i = l, j = r;
  while (i < pivotIndex && j > pivotIndex)
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] >= pivot)
      j--;
    if (i < pivotIndex && j > pivotIndex)
    {
      swap(arr[i++], arr[j--]);
    }
  }

  quickSort(arr, l, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, r);
}
int main()
{
  vector<int> arr = {10, 7, 8, 9, 1, 5};
  int n = arr.size();

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}