// Leetcode 37: Sudoku Solver
// Link: https://leetcode.com/problems/sudoku-solver/

/**
 * Problem Description:
 * -----------------
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 * 1. Each of the digits 1-9 must occur exactly once in each row.
 * 2. Each of the digits 1-9 must occur exactly once in each column.
 * 3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 *
 * The '.' character indicates empty cells.
 *
 * Example:
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
 *
 * Output:
 * [["5","3","4","6","7","8","9","1","2"]
 * ,["6","7","2","1","9","5","3","4","8"]
 * ,["1","9","8","3","4","2","5","6","7"]
 * ,["8","5","9","7","6","1","4","2","3"]
 * ,["4","2","6","8","5","3","7","9","1"]
 * ,["7","1","3","9","2","4","8","5","6"]
 * ,["9","6","1","5","3","7","2","8","4"]
 * ,["2","8","7","4","1","9","6","3","5"]
 * ,["3","4","5","2","8","6","1","7","9"]]
 *
 * Constraints:
 * - board.length == 9
 * - board[i].length == 9
 * - board[i][j] is a digit or '.'.
 * - It is guaranteed that the input board has only one solution.
 */

#include <vector>
#include <utility>
using namespace std;

/**
 * Approach: Backtracking
 *
 * This approach uses backtracking to solve the Sudoku puzzle:
 * 1. Find all empty cells (cells with '.')
 * 2. For each empty cell, try placing digits 1-9
 * 3. For each digit, check if it's valid according to Sudoku rules
 * 4. If valid, place the digit and recursively try to solve the rest of the puzzle
 * 5. If at any point we can't place a valid digit, backtrack by removing the last placed digit
 *    and try another digit
 * 6. Continue until all empty cells are filled
 *
 * Time Complexity: O(9^m) where m is the number of empty cells
 * Space Complexity: O(m) for the recursion stack and the empty cells vector
 */
class Solution
{
private:
  /**
   * Checks if placing a digit at the given position is valid according to Sudoku rules
   *
   * @param board The Sudoku board
   * @param row The row index
   * @param col The column index
   * @param val The digit value (1-9) to check
   * @return true if placing the digit is valid, false otherwise
   */
  bool isSafe(vector<vector<char>> &board, int row, int col, int val)
  {
    char c = '0' + val;

    // Check row
    for (int j = 0; j < 9; j++)
    {
      if (board[row][j] == c)
        return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
      if (board[i][col] == c)
        return false;
    }

    // Check 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[startRow + i][startCol + j] == c)
          return false;
      }
    }

    return true;
  }

  /**
   * Recursive function to solve the Sudoku puzzle using backtracking
   *
   * @param board The Sudoku board
   * @param empty Vector of coordinates (row, col) of empty cells
   * @param i Current index in the empty cells vector
   * @return true if the puzzle is solved, false otherwise
   */
  bool solve(vector<vector<char>> &board, vector<pair<int, int>> &empty, int i)
  {
    // Base case: all empty cells are filled
    if (i >= empty.size())
      return true;

    int row = empty[i].first;
    int col = empty[i].second;

    // Try digits 1-9
    for (int val = 1; val <= 9; val++)
    {
      if (isSafe(board, row, col, val))
      {
        // Place the digit
        board[row][col] = '0' + val;

        // Recursively solve for the next empty cell
        if (solve(board, empty, i + 1))
          return true;

        // Backtrack if the current placement doesn't lead to a solution
        board[row][col] = '.';
      }
    }

    return false;
  }

public:
  /**
   * Solves the Sudoku puzzle by filling the empty cells
   *
   * @param board The 9x9 Sudoku board to solve
   */
  void solveSudoku(vector<vector<char>> &board)
  {
    // Find all empty cells
    vector<pair<int, int>> empty;

    for (int i = 0; i < 81; i++)
    {
      if (board[i / 9][i % 9] == '.')
      {
        empty.push_back({i / 9, i % 9});
      }
    }

    // Solve the puzzle
    solve(board, empty, 0);
  }
};