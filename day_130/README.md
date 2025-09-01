# Day 130: Sudoku Problems

## Overview

Today, we tackled two Sudoku-related problems on LeetCode, focusing on validation and solving techniques. These problems are excellent examples of applying backtracking algorithms to constrained optimization problems.

## Problems Solved

### 1. [Valid Sudoku (LeetCode 36)](https://leetcode.com/problems/valid-sudoku/)

**Problem**: Determine if a 9x9 Sudoku board is valid according to the following rules:

- Each row must contain digits 1-9 without repetition
- Each column must contain digits 1-9 without repetition
- Each 3x3 sub-box must contain digits 1-9 without repetition

**Approach**:

- Check each filled cell against Sudoku rules
- For each filled cell, verify if it violates any row, column, or 3x3 sub-box constraints
- Time Complexity: O(1) - since the board size is fixed at 9x9
- Space Complexity: O(1) - using constant extra space

**Key Concepts**:

- Grid validation
- Array traversal
- Rule-based checking

### 2. [Sudoku Solver (LeetCode 37)](https://leetcode.com/problems/sudoku-solver/)

**Problem**: Write a program to solve a Sudoku puzzle by filling empty cells with digits 1-9 while satisfying all Sudoku rules.

**Approach**:

- Use backtracking to try all possible digit placements
- For each empty cell, try digits 1-9
- Validate each placement against Sudoku rules
- If valid, proceed to the next empty cell
- If no valid digit can be placed, backtrack to previous cells and try other digits
- Time Complexity: O(9^m) where m is the number of empty cells
- Space Complexity: O(m) for recursion stack and storing empty cell positions

**Key Concepts**:

- Backtracking algorithm
- Constraint satisfaction
- Recursion
- Systematic trial and error

## Key Takeaways

1. **Backtracking is Powerful**: Backtracking is an excellent approach for solving problems with constraints where we need to explore multiple possibilities.

2. **Optimization Techniques**:

   - Pre-compute empty cells to avoid repeatedly searching for them
   - Use early pruning (checking constraints as soon as possible) to reduce unnecessary exploration
   - Ordering the empty cells by the number of valid possibilities can improve efficiency (though not implemented in this solution)

3. **Problem Decomposition**:

   - Breaking down the problem into smaller sub-problems (checking rows, columns, and sub-boxes separately)
   - Reusing validation logic across problems

4. **Real-World Applications**:
   - These techniques apply to many scheduling, planning, and resource allocation problems
   - The core concepts of constraint satisfaction appear in numerous applications beyond puzzles

## Code Implementation

- [Valid Sudoku Solution](./Leetcode_36.cpp)
- [Sudoku Solver Solution](./Leetcode_37.cpp)

## Further Reading

- **Constraint Satisfaction Problems (CSPs)**: Sudoku is a classic example of a CSP
- **Heuristic Search**: Methods like minimum remaining values (MRV) and degree heuristic can further optimize backtracking solutions
- **Dancing Links Algorithm**: An efficient algorithm for exact cover problems, which can be applied to Sudoku
