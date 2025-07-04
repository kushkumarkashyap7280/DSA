# Day 12: Matrix Diagonal Sum

## Problem: Matrix Diagonal Sum

**LeetCode 1572**: [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

### Problem Description

Given a square matrix `mat`, return the sum of the matrix diagonals. Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

#### Example 1:

```
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
```

#### Example 2:

```
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
```

#### Example 3:

```
Input: mat = [[5]]
Output: 5
```

### Approach

- Traverse the primary diagonal (top-left to bottom-right) and sum the elements.
- Traverse the secondary diagonal (top-right to bottom-left) and sum the elements, skipping the center if the matrix size is odd (to avoid double-counting).
- Time Complexity: O(n)
- Space Complexity: O(1)

### Solution File

- [leetcode_1572.cpp](leetcode_1572.cpp)
