// Leetcode 51: N-Queens
// Link: https://leetcode.com/problems/n-queens/

/*
Problem Description:
-----------------
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that
no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
- 1 <= n <= 9
*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
  /**
   * Checks if placing a queen at a given position is safe
   *
   * @param board The current state of the chessboard
   * @param row Current row being considered
   * @param col Current column being considered
   * @param n Size of the board
   * @return true if it's safe to place a queen, false otherwise
   */
  bool isSafe(vector<string> &board, int row, int col, int n)
  {
    // Check column (only need to check above the current row)
    for (int i = 0; i < row; i++)
    {
      if (board[i][col] == 'Q')
        return false;
    }

    // Check left diagonal (upper left)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    // Check right diagonal (upper right)
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
      if (board[i][j] == 'Q')
        return false;
    }

    return true;
  }

  /**
   * Recursive backtracking function to place queens on the board
   *
   * @param ans Vector to store all valid solutions
   * @param board Current state of the chessboard
   * @param row Current row being considered
   * @param n Size of the board
   */
  void solve(vector<vector<string>> &ans, vector<string> &board, int row, int n)
  {
    // Base case: If all queens are placed successfully
    if (row == n)
    {
      ans.push_back(board);
      return;
    }

    // Try placing queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
      if (isSafe(board, row, col, n))
      {
        // Place the queen
        board[row][col] = 'Q';

        // Recur for next row
        solve(ans, board, row + 1, n);

        // Backtrack: Remove the queen
        board[row][col] = '.';
      }
    }
  }

public:
  /**
   * Solves the N-Queens problem
   *
   * @param n Size of the chessboard
   * @return All distinct solutions to the n-queens puzzle
   *
   * Time Complexity: O(N!), where N is the board size
   * Space Complexity: O(N²) for storing the board
   */
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.')); // Initialize n x n board with empty spaces
    solve(ans, board, 0, n);
    return ans;
  }
};
