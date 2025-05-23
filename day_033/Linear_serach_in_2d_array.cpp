// to demonstrate linear search in 2D array

// note :
// if we taking 2d array as args , it will become pointer of first element (0 ,0)
// it does not represent 2d array anymore so we need to explicitely pass the no. of rows and cols.
// also while taking 2d as args we need to metion no of cols in args without it will show error because array now decays to pointer which pointing to the first element
#include <iostream>
using namespace std;

// function to find coordinates of element if present
// time complexity is O(n*m) where n is the number of rows and m is the number of columns
// space complexity is O(1) as we are not using any extra space
pair<int, int> find_target(int arr[][3], int target ,int rows ,int cols)
{

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (arr[i][j] == target)
        return {i, j};
    }
  }
  return {-1, -1}; // return -1 if not found
}


int main()
{
  // example 2D array
  int arr[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
    
  // dimensions of the array
        int rows = sizeof(arr) / sizeof(arr[0]);
  int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

  int target;
  cout << "Enter the element to search: ";
  cin >> target;
  pair<int, int> result = find_target(arr, target, rows, cols);
  // check if the element is found
  if (result.first != -1)
  {
    cout << "Element found at coordinates: (" << result.first << ", " << result.second << ")\n";
  }
  else
  {
    cout << "Element not found in the array.\n";
  }
  return 0;
}