# Day 64 - Recursion: Sorting and Power Problems

This folder contains classic recursion-based solutions for sorting and number theory problems:

## 1. Insertion Sort using Recursion ([LeetCode 912](https://leetcode.com/problems/sort-an-array/))

- **Approach:** Recursively sort the first n-1 elements, then insert the last element in its correct position.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n) (recursion stack)
- **Edge Cases:** Already sorted, reverse sorted, all elements equal, single element.

## 2. Selection Sort using Recursion ([LeetCode 912](https://leetcode.com/problems/sort-an-array/))

- **Approach:** Recursively select the minimum element and place it at the beginning, then sort the rest.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n) (recursion stack)
- **Edge Cases:** Already sorted, reverse sorted, all elements equal, single element.

## 3. Merge Sort using Recursion ([LeetCode 912](https://leetcode.com/problems/sort-an-array/))

- **Approach:** Recursively divide the array into halves, sort each half, then merge them.
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n) (for temporary arrays)
- **Edge Cases:** Already sorted, reverse sorted, all elements equal, single element.

## 4. Power of Four ([LeetCode 342](https://leetcode.com/problems/power-of-four/))

- **Approach:** Recursively divide the number by 4 and check if it reaches 1.
- **Time Complexity:** O(log₄ n)
- **Space Complexity:** O(log₄ n) (recursion stack)
- **Edge Cases:** n = 1, n = 0, negative numbers, non-powers of four.

---

Each file demonstrates a different recursive approach. See code comments for details and example usage.
