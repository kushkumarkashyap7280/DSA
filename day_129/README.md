# Day 129: Backtracking Problems - N-Queens and Rat in a Maze

On day 129, I explored classic backtracking problems:

## Problems Solved

### 1. [LeetCode 51: N-Queens](https://leetcode.com/problems/n-queens/) (Hard)

- **Problem**: Place N queens on an N×N chessboard such that no two queens threaten each other.
- **Approach**: Used recursive backtracking with isSafe checks for column and diagonals.
- **Time Complexity**: O(N!), where N is the board size
- **Space Complexity**: O(N²) for the board representation

### 2. [Rat in a Maze](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1) (Medium)

- **Problem**: Find all possible paths for a rat to move from top-left to bottom-right of a maze.
- **Approach**: Used DFS with backtracking to explore all valid paths.
- **Time Complexity**: O(4^(N²)), where N is the size of the maze
- **Space Complexity**: O(N²) for recursion stack and visited cells

## Backtracking Pattern

Both problems demonstrate the classic backtracking pattern:

1. **Choose**: Make a choice (place a queen, move the rat)
2. **Explore**: Recursively solve the subproblem
3. **Unchoose**: Undo the choice if it doesn't lead to a solution (backtrack)

Backtracking is powerful for problems where we need to:

- Find all possible solutions
- Systematically explore all possibilities
- Prune invalid paths early

## Key Implementation Details

### N-Queens

- Used a 2D representation of the chessboard
- Validated queen placement by checking columns and diagonals
- Represented solutions as string arrays with 'Q' for queens and '.' for empty spaces

### Rat in a Maze

- Used DFS to explore all four directions (up, down, left, right)
- Marked visited cells to avoid cycles
- Collected paths using string to track directions (U, D, L, R)

## Key Learnings

- Backtracking is essential for combinatorial problems
- Early pruning of invalid paths is crucial for efficiency
- The choice-explore-unchoose pattern applies to many recursive problems
- State tracking and restoration are fundamental to backtracking
