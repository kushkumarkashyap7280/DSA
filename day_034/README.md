# Day 34 Learning: Advanced Matrix Operations

## Problems Solved

### 1. Search a 2D Matrix II [LeetCode 240](https://leetcode.com/problems/search-a-2d-matrix-ii/)

#### Problem Description

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix where:

- Integers in each row are sorted in ascending from left to right
- Integers in each column are sorted in ascending from top to bottom

#### Example

```
Input: matrix = [
  [1,  4,  7,  11, 15],
  [2,  5,  8,  12, 19],
  [3,  6,  9,  16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
], target = 5

Output: true
```

#### Solution Approach

1. Start from top-right corner (or bottom-left)
2. If current element > target, move left
3. If current element < target, move down
4. Repeat until target found or out of bounds

#### Key Learning Points

- Matrix traversal optimization
- Using sorted properties of matrix
- Time Complexity: O(m + n)
- Space Complexity: O(1)

### 2. Spiral Matrix [LeetCode 54](https://leetcode.com/problems/spiral-matrix/)

#### Problem Description

Return all elements of the matrix in spiral order (clockwise, starting from the top left element).

#### Example

```
Input: matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
Output: [1,2,3,6,9,8,7,4,5]
```

#### Solution Approach

1. Define four boundaries: top, bottom, left, right
2. Traverse in order: right → down → left → up
3. After each traversal, update boundaries
4. Continue until all elements are visited

#### Key Learning Points

- Matrix traversal patterns
- Boundary condition handling
- Time Complexity: O(m\*n)
- Space Complexity: O(1) excluding output array

### 3. Rotate Image [LeetCode 48](https://leetcode.com/problems/rotate-image/)

#### Problem Description

Rotate the image by 90 degrees clockwise in-place.

#### Example

```
Input: matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
Output: [
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

#### Solution Approach

Two-step process:

1. Transpose the matrix (swap elements across main diagonal)
2. Reverse each row

OR Direct rotation:

1. For each layer from outer to inner:
   - Rotate four elements at a time
   - Move to next set of four elements
   - Continue until layer is complete

#### Key Learning Points

- Matrix manipulation techniques
- In-place rotation algorithms
- Understanding matrix symmetry
- Time Complexity: O(n²)
- Space Complexity: O(1)

## Key Concepts Covered

### Matrix Traversal Patterns

- Row-wise traversal
- Column-wise traversal
- Diagonal traversal
- Spiral traversal
- Layer-by-layer processing

### Space Optimization Techniques

- In-place operations
- Using matrix properties for optimization
- Avoiding extra space usage

### Matrix Properties

- Understanding sorted matrices
- Matrix symmetry
- Transpose operations
- Rotation properties

### Problem-Solving Strategies

- Starting from corners/edges
- Layer-by-layer processing
- Using matrix boundaries
- Pattern recognition in matrix problems

## Common Pitfalls to Avoid

- Boundary condition errors
- Index out of bounds
- Incorrect rotation direction
- Not handling edge cases (empty matrix, single element, etc.)
- Unnecessary space usage

## Interview Tips

- Always clarify matrix dimensions and constraints
- Discuss space-time trade-offs
- Consider edge cases early
- Explain the approach before coding
- Test the solution with example cases
