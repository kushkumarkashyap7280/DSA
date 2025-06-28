# Day 69: Rat in a Maze & Divide Two Integers

## 1. Rat in a Maze ([GFG Problem Link](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1))
- See: `Rat_in_a_maze.cpp`
- Approach: Backtracking to find all possible paths from (0,0) to (n-1,n-1) in a grid, moving only through open cells and not revisiting any cell in a path.
- Time Complexity: O(4^(n^2))
- Space Complexity: O(n^2) (maze + recursion stack)

## 2. Divide Two Integers ([LeetCode 29](https://leetcode.com/problems/divide-two-integers/))
- See: `leetcode_29.cpp`
- Approach: Bit manipulation to perform division without using *, /, or % operators. Handles overflow and sign.
- Time Complexity: O(log N) (where N is the absolute value of dividend)
- Space Complexity: O(1)

---

### Example Usage

#### Divide Two Integers
```cpp
int dividend = 10, divisor = 3;
cout << divide(dividend, divisor) << endl; // Output: 3
```

#### Rat in a Maze
- Input: `[[1,0,0,0],[1,1,0,1],[1,1,0,0],[0,1,1,1]]`
- Output: `["DDRDRR", "DRDDRR"]`

---

See code files for detailed implementation and comments.
