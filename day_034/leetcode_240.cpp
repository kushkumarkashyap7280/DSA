// 240. Search a 2D Matrix II

// https://leetcode.com/problems/search-a-2d-matrix-ii/

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false


Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to search for target in a 2D matrix
// Time Complexity: O(m + n), where m is the number of rows and n is the number of columns
// Space Complexity: O(1), no extra space used
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  if (matrix.empty() || matrix[0].empty())
    return false;

  int rows = matrix.size();
  int cols = matrix[0].size();

  int row = 0;
  int col = cols - 1; // start from top-right

  while (row < rows && col >= 0)
  {
    int current = matrix[row][col];

    if (current == target)
    {
      return true;
    }
    else if (current > target)
    {
      col--; // move left
    }
    else
    {
      row++; // move down
    }
  }

  return false;
}
int main()
{
  // Example usage
  vector<vector<int>> matrix = {
      {1, 4, 7, 11, 15},
      {2, 5, 8, 12, 19},
      {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}};
  int target = 5;
  bool result = searchMatrix(matrix, target);
  if (result)
  {
    cout << "Target " << target << " found in the matrix." << endl;
  }
  else
  {
    cout << "Target " << target << " not found in the matrix." << endl;
  }
  return 0;
}