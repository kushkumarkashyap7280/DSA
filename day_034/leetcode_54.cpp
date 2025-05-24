// 54. Spiral Matrix

// Problem Link: https://leetcode.com/problems/spiral-matrix/

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


#include <iostream>
#include <vector>
using namespace std;


// Function to return the spiral order of a matrix
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(m*n) for the result vector
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
   int top = 0, left =0;
   int right = n-1;
   int bottom = m-1;
   vector<int> result;
   while(result.size() < m*n ){
     // left to right
    for(int i = left ; i <=right && result.size() < m * n ; i++){
        result.push_back(matrix[top][i]);
    }
    top++;

    // top to bottom
     for(int i = top ; i <=bottom && result.size() < m * n ; i++){
        result.push_back(matrix[i][right]);
    }
    right--;

    // right to left
     for(int i = right; i >= left && result.size() < m * n ; i--){
        result.push_back(matrix[bottom][i]);
    }
    bottom--;

    // bottom to top
     for(int i = bottom ; i >= top && result.size() < m * n; i--){
        result.push_back(matrix[i][left]);
    }
     left++;      
    }

    return result;
   }
int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  vector<int> result = spiralOrder(matrix);
  cout << "Spiral Order: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  // Output: Spiral Order: 1 2 3 6 9 8 7 4 5;
  return 0;
}