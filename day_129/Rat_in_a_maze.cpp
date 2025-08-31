// Rat in a Maze Problem - I
// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
Problem Description:
-----------------
Consider a rat placed at position (0, 0) in an n x n square matrix mat[][].
The rat's goal is to reach the destination at position (n-1, n-1).
The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:
- 0: A blocked cell through which the rat cannot travel.
- 1: A free cell that the rat can pass through.

Your task is to find all possible paths the rat can take to reach the destination,
starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat
cannot revisit any cell along the same path. Furthermore, the rat can only move to
adjacent cells that are within the bounds of the matrix and not blocked.

If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Example 1:
Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths -
DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

Example 2:
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.

Example 3:
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination:
1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.

Constraints:
- 2 ≤ mat.size() ≤ 5
- 0 ≤ mat[i][j] ≤ 1
*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  /**
   * Backtracking function to find all possible paths in the maze
   *
   * @param maze The maze matrix with 1 for open cells and 0 for blocked cells
   * @param s Current path string
   * @param ans Vector to store all valid paths
   * @param i Current row position
   * @param j Current column position
   * @param m Number of rows in maze
   * @param n Number of columns in maze
   */
  void backtrack(vector<vector<int>> &maze, string &s, vector<string> &ans,
                 int i, int j, int &m, int &n)
  {
    // Base case: If reached the destination
    if (i == m - 1 && j == n - 1)
    {
      ans.push_back(s);
      return;
    }

    // Mark current cell as visited by setting it to 0
    maze[i][j] = 0;

    // Try moving DOWN if possible
    if (i + 1 < m && maze[i + 1][j] == 1)
    {
      s.push_back('D');
      backtrack(maze, s, ans, i + 1, j, m, n);
      s.pop_back(); // Backtrack
    }

    // Try moving LEFT if possible
    if (j - 1 >= 0 && maze[i][j - 1] == 1)
    {
      s.push_back('L');
      backtrack(maze, s, ans, i, j - 1, m, n);
      s.pop_back(); // Backtrack
    }

    // Try moving RIGHT if possible
    if (j + 1 < n && maze[i][j + 1] == 1)
    {
      s.push_back('R');
      backtrack(maze, s, ans, i, j + 1, m, n);
      s.pop_back(); // Backtrack
    }

    // Try moving UP if possible
    if (i - 1 >= 0 && maze[i - 1][j] == 1)
    {
      s.push_back('U');
      backtrack(maze, s, ans, i - 1, j, m, n);
      s.pop_back(); // Backtrack
    }

    // Unmark the current cell (restore its value)
    maze[i][j] = 1;
  }

  /**
   * Main function to find all possible paths in the rat maze
   *
   * @param maze The maze matrix with 1 for open cells and 0 for blocked cells
   * @return Vector of all valid paths from (0,0) to (n-1,n-1)
   *
   * Time Complexity: O(4^(N²)), where N is the size of the maze
   * Space Complexity: O(N²) for recursion stack and visited cells
   */
  vector<string> ratInMaze(vector<vector<int>> &maze)
  {
    // If starting position is blocked, no path is possible
    if (maze[0][0] == 0)
      return {};

    int m = maze.size();
    int n = maze[0].size();

    string s;
    vector<string> ans;
    backtrack(maze, s, ans, 0, 0, m, n);
    return ans;
  }
};
