// Leetcode 36: Valid Sudoku
// Link: https://leetcode.com/problems/valid-sudoku/

/**
 * Problem Description:
 * -----------------
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * Note:
 * - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * - Only the filled cells need to be validated according to the mentioned rules.
 *
 * Example 1:
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8.
 * Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 *
 * Constraints:
 * - board.length == 9
 * - board[i].length == 9
 * - board[i][j] is a digit 1-9 or '.'.
 */

#include <vector>
using namespace std;

/**
 * Approach 1: Individual Cell Validation
 *
 * This approach validates each filled cell by checking its row, column, and 3x3 subgrid.
 * For each filled cell, we:
 * 1. Check if any other cell in the same row has the same value
 * 2. Check if any other cell in the same column has the same value
 * 3. Check if any other cell in the same 3x3 subgrid has the same value
 *
 * Time Complexity: O(9²) = O(1) - As the board size is fixed at 9x9
 * Space Complexity: O(1) - No extra space used beyond variables
 */
class Solution
{
private:
  /**
   * Checks if placing a value at the given position is valid according to Sudoku rules
   *
   * @param board The Sudoku board
   * @param row The row index to check
   * @param col The column index to check
   * @return true if the value at board[row][col] is valid, false otherwise
   */
  bool isSafe(vector<vector<char>> &board, int row, int col)
  {
    char c = board[row][col];

    // Check row
    for (int j = 0; j < 9; j++)
    {
      if (j != col && board[row][j] == c)
        return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
      if (i != row && board[i][col] == c)
        return false;
    }

    // Check 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        int r = startRow + i;
        int c2 = startCol + j;
        if ((r != row || c2 != col) && board[r][c2] == c)
          return false;
      }
    }

    return true;
  }

public:
  /**
   * Checks if the given Sudoku board is valid
   *
   * @param board The 9x9 Sudoku board to validate
   * @return true if the board is valid, false otherwise
   */
  bool isValidSudoku(vector<vector<char>> &board)
  {
    // Check each filled cell
    for (int i = 0; i < 81; i++)
    {
      int row = i / 9;
      int col = i % 9;
      if (board[row][col] != '.' && !isSafe(board, row, col))
        return false;
    }
    return true;
  }
};