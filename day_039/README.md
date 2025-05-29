# Day 39: Binary Search & Matrix Problems

## Problem Sets

### 1. [Square Root (x) - LeetCode 69](https://leetcode.com/problems/sqrtx/)

- **Problem:** Find square root without using built-in functions
- **Approaches:**

  ```cpp
  // Brute Force: O(√n)
  while (i * i <= x) { i++; }

  // Binary Search: O(log n)
  while (left <= right) {
      mid = left + (right - left) / 2;
      if (mid * mid <= x) { left = mid + 1; }
      else { right = mid - 1; }
  }
  ```

- **Key Points:**
  - Integer overflow handling using `long long`
  - Binary search optimization
  - Edge case handling for x < 2

### 2. [Spiral Matrix II - LeetCode 59](https://leetcode.com/problems/spiral-matrix-ii/)

- Generate n x n matrix with elements in spiral order
- Pattern recognition and matrix traversal
- Direction control and boundary management

## Implementation Details

1. **Binary Search Implementation**

   - Time Complexity: O(log n)
   - Space Complexity: O(1)
   - Edge Cases: 0, 1, large numbers

2. **Matrix Traversal**
   - Direction vectors
   - Boundary conditions
   - Pattern simulation

## Common Patterns

1. **Binary Search Pattern**

   ```cpp
   int left = 0, right = x;
   while (left <= right) {
       mid = left + (right - left) / 2;
       // Update left or right based on condition
   }
   ```

2. **Matrix Spiral Pattern**
   ```cpp
   int direction = 0; // 0: right, 1: down, 2: left, 3: up
   while (elements_to_fill) {
       fill_current_direction();
       update_boundaries();
       direction = (direction + 1) % 4;
   }
   ```

## Interview Tips

1. **Square Root Problem**

   - Consider integer overflow
   - Think about optimization (binary search)
   - Handle edge cases (0, 1)

2. **Spiral Matrix**
   - Break down into smaller steps
   - Use direction arrays
   - Handle boundary updates

## Resources

- [LeetCode 69 - Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [LeetCode 59 - Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)
