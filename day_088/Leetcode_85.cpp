// 85. Maximal Rectangle


// Time Complexity: O(rows * cols)
// Space Complexity: O(cols)
// Uses stack-based largest rectangle in histogram for each row
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream> // Added for main function
using std::max;
using std::stack;
using std::vector;

// link -https://leetcode.com/problems/maximal-rectangle/description/

/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1


Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;

    int maxArea = 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; ++i)
    {
      // Build histogram for current row
      for (int j = 0; j < cols; ++j)
      {
        if (matrix[i][j] == '1')
        {
          heights[j] += 1;
        }
        else
        {
          heights[j] = 0;
        }
      }
      maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
  }

  int largestRectangleArea(vector<int> &heights)
  {
    stack<int> s;
    heights.push_back(0); // Sentinel
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i)
    {
      while (!s.empty() && heights[i] < heights[s.top()])
      {
        int h = heights[s.top()];
        s.pop();
        int w = s.empty() ? i : (i - s.top() - 1);
        maxArea = max(maxArea, h * w);
      }
      s.push(i);
    }

    heights.pop_back(); // Remove sentinel
    return maxArea;
  }
};

int main()
{
  Solution sol;
  vector<vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  int result = sol.maximalRectangle(matrix);
  std::cout << "Maximal Rectangle Area: " << result << std::endl;
  return 0;
}
