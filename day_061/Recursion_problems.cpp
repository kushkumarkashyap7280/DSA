// some problems arrays using recursion

#include <iostream>
using namespace std;

// recusion approach

// sum of array elements
int Sum(int *arr, int size)
{
  if (size == 0)
    return 0;
  if (size == 1)
    return arr[0];

  int sum = 0;
  sum += arr[0] + Sum(arr + 1, size - 1);
  return sum;
}

// linear search in array
int Index(int *arr, int size, int a, int index = 0)
{
  if (size == 0)
    return -1;

  if (arr[0] == a)
  {
    return index;
  }
  else
  {
    index++;
    return Index(arr + 1, size - 1, a, index);
  }
}

// binary search in array (recursive)
int findIndex(int *arr, int left, int right, int a)
{
  if (left > right)
    return -1;
  int m = left + (right - left) / 2;
  if (arr[m] == a)
  {
    return m;
  }
  else if (arr[m] < a)
  {
    return findIndex(arr, m + 1, right, a);
  }
  else
  {
    return findIndex(arr, left, m - 1, a);
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Sum of array elements: " << Sum(arr, size) << endl;

  int searchElement = 3;
  int index = Index(arr, size, searchElement);

  if (index != -1)
  {
    cout << "Element " << searchElement << " found at index: " << index << " (Linear Search)" << endl;
  }
  else
  {
    cout << "Element " << searchElement << " not found in the array. (Linear Search)" << endl;
  }

  // Binary search usage (array must be sorted)
  int binIndex = findIndex(arr, 0, size - 1, searchElement);
  if (binIndex != -1)
  {
    cout << "Element " << searchElement << " found at index: " << binIndex << " (Binary Search)" << endl;
  }
  else
  {
    cout << "Element " << searchElement << " not found in the array. (Binary Search)" << endl;
  }
  return 0;
}