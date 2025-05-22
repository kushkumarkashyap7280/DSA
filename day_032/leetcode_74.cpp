// 74. Search a 2D Matrix

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// approach 1: my solution( not optimal)
// time complexity: O(log(m)+log(n))
// space complexity: O(1)
// Function to find the row in which the target is present
// int findrow(vector<vector<int>> &matrix, int target, int r, int c)
// {

//   if (target < matrix[0][0] || target > matrix[r - 1][c - 1])
//     return -1;
//   int i = 0, j = r - 1;
//   while (i <= j)
//   {
//     int m = i + (j - i) / 2;
//     if (target >= matrix[m][0] && target <= matrix[m][c - 1])
//     {
//       return m;
//     }
//     else if (target < matrix[m][0])
//     {
//       j = m - 1;
//     }
//     else
//     {
//       i = m + 1;
//     }
//   }

//   return -1;
// }
// bool searchMatrix(vector<vector<int>> &matrix, int target)
// {
//   int r = matrix.size();
//   int c = matrix[0].size();
//   int result = findrow(matrix, target, r, c);
//   if (result == -1)
//     return false;
//   int i = 0, j = c - 1;
//   while (i <= j)
//   {
//     int m = i + (j - i) / 2;
//     if (target == matrix[result][m])
//     {
//       return true;
//     }
//     else if (target < matrix[result][m])
//     {
//       j = m - 1;
//     }
//     else
//     {
//       i = m + 1;
//     }
//   }
//   return false;
// }

// approach 2: optimal solution
// time complexity: O(log(m*n))
// space complexity: O(1)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int r = matrix.size();
  int c = matrix[0].size();

  if (target < matrix[0][0] || target > matrix[r - 1][c - 1])
    return false;
  int p = 0, q = r * c - 1;
  while (p <= q)
  {
    int m = p + (q - p) / 2;
    int row = m / c;
    int col = m % c;
    if (target == matrix[row][col])
    {
      return true;
    }
    else if (target < matrix[row][col])
    {
      q = m - 1;
    }
    else
    {
      p = m + 1;
    }
  }
  return false;
}
int main()
{
  vector<vector<int>> matrix = {
      {1, 3, 5, 7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}};
  int target = 3 ;
  if (searchMatrix(matrix, target))
  {
    cout << "Target found in the matrix." << endl;
  }
  else
  {
    cout << "Target not found in the matrix." << endl;
  }

  return 0;
}