// 867. Transpose Matrix

// https://leetcode.com/problems/transpose-matrix/

// Given a 2D integer array matrix, return the transpose of matrix.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 105
// -109 <= matrix[i][j] <= 109
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 487K
// Submissions
// 656.8K
// Acceptance Rate
// 74.2%

#include <iostream>
#include <vector>
using namespace std;

// Function to transpose a matrix (my own implementation)
// Time complexity: O(m*n)
// Space complexity: O(m*n)
// where m is the number of rows and n is the number of columns in the matrix
// The function takes a 2D vector (matrix) as input and returns its transpose
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<vector<int>> ans(cols, vector<int>(rows, 0));
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      ans[j][i] = matrix[i][j];
    }
  }
  return ans;
}
int main()
{
  // Example usage
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  vector<vector<int>> transposedMatrix = transpose(matrix);
  cout << "Transposed Matrix:" << endl;
  for (const auto &row : transposedMatrix)
  {
    for (const auto &elem : row)
    {
      cout << elem << " ";
    }
    cout << endl;
  }
  return 0;
}