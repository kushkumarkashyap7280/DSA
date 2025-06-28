// Rat in a Maze Problem - I

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1&selectedLang=python3

/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
Constraints:
2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// Function to find all paths from (0, 0) to (s-1, s-1) in the maze
// using backtracking
// Parameters:
// ans: vector to store all valid paths
// maze: 2D vector representing the maze
// s: size of the maze (n x n)
// str: current path string
// i, j: current position in the maze

//time complexity: O(4^(n^2)), where n is the size of the maze
//space complexity: O(n^2) for the maze and O(n) for the path
void addpath(vector<string> &ans, vector<vector<int>> &maze, int s, string &str, int i, int j)
{
  // If destination is reached
  if (i == s - 1 && j == s - 1)
  {
    ans.push_back(str);
    return;
  }

  // Mark current cell as visited
  maze[i][j] = 0;

  // D, L, R, U moves
  if (i + 1 < s && maze[i + 1][j] == 1)
  {
    str.push_back('D');
    addpath(ans, maze, s, str, i + 1, j);
    str.pop_back();
  }
  if (j - 1 >= 0 && maze[i][j - 1] == 1)
  {
    str.push_back('L');
    addpath(ans, maze, s, str, i, j - 1);
    str.pop_back();
  }
  if (j + 1 < s && maze[i][j + 1] == 1)
  {
    str.push_back('R');
    addpath(ans, maze, s, str, i, j + 1);
    str.pop_back();
  }
  if (i - 1 >= 0 && maze[i - 1][j] == 1)
  {
    str.push_back('U');
    addpath(ans, maze, s, str, i - 1, j);
    str.pop_back();
  }

  // Backtrack (unmark)
  maze[i][j] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
  int s = maze.size();
  vector<string> ans;
  if (maze[0][0] == 0 || maze[s - 1][s - 1] == 0)
    return ans;

  string path = "";
  addpath(ans, maze, s, path, 0, 0);

  // Optional: sort if multiple paths
  // sort(ans.begin(), ans.end());
  return ans;
}
int main()
{
  vector<vector<int>> maze = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};

  vector<string> paths = ratInMaze(maze);
  
  for (const string &path : paths)
    cout << path << " ";
  
  return 0;
}