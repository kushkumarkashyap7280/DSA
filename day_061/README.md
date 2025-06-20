# Day 61 - LeetCode 168: Excel Sheet Column Title

## Problem Description

Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

For example:

- 1 -> A
- 2 -> B
- ...
- 26 -> Z
- 27 -> AA
- 28 -> AB

[Problem Link](https://leetcode.com/problems/excel-sheet-column-title/)

## Solution Approach

This problem is similar to converting a number to a base-26 numeral system, but with a twist: Excel columns are 1-indexed and use letters A-Z instead of digits 0-25. The approach is:

1. While `columnNumber` is greater than 0:
   - Decrement `columnNumber` by 1 to adjust for 0-based indexing.
   - Find the remainder when dividing by 26. This gives the current character (A-Z).
   - Prepend the corresponding character to the result string.
   - Divide `columnNumber` by 26 to move to the next digit.
2. Return the result string.

### Time Complexity

- O(log₍₂₆₎ n), where n is the column number (since we divide by 26 each step)

### Space Complexity

- O(1) (ignoring the output string)

## Example Test Cases

```cpp
Input: columnNumber = 1
Output: "A"

Input: columnNumber = 28
Output: "AB"

Input: columnNumber = 701
Output: "ZY"

Input: columnNumber = 2147483647
Output: "FXSHRXW"
```

## Key Points

- The algorithm is similar to base conversion, but with 1-based indexing and letters.
- Always decrement `columnNumber` before modulo to handle the offset.
- Prepend each character to build the result from least to most significant digit.

## Edge Cases

1. Minimum input (1) should return "A".
2. Large input (e.g., 2147483647) should not overflow.
3. Inputs that are exact multiples of 26 (e.g., 26, 52, 702) should be handled correctly.

# Recursion Problems: Array Sum, Linear Search, and Binary Search

This file demonstrates three classic array problems solved using recursion:

1. **Sum of Array Elements**
   - Recursively computes the sum of all elements in an array.
2. **Linear Search in Array**
   - Recursively finds the index of a given element in an array (returns -1 if not found).
3. **Binary Search in Array**
   - Recursively finds the index of a given element in a sorted array using binary search (returns -1 if not found).

## Solution Approaches

### 1. Sum of Array Elements

- **Base Cases:**
  - If size is 0, return 0.
  - If size is 1, return the only element.
- **Recursive Step:**
  - Add the first element to the sum of the rest of the array.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (due to recursion stack)

### 2. Linear Search in Array

- **Base Case:**
  - If size is 0, return -1 (not found).
- **Recursive Step:**
  - If the first element matches, return the current index.
  - Otherwise, search the rest of the array, incrementing the index.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

### 3. Binary Search in Array (Recursive)

- **Base Case:**
  - If left > right, return -1 (not found).
- **Recursive Step:**
  - Find the middle index. If it matches, return it.
  - If the target is greater, search the right half.
  - If the target is smaller, search the left half.
- **Time Complexity:** O(log n)
- **Space Complexity:** O(log n)

## Example Usage

```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = 5;

// Sum
cout << "Sum: " << Sum(arr, size) << endl;

// Linear Search
int idx = Index(arr, size, 3);
// Output: 2

// Binary Search (array must be sorted)
int binIdx = findIndex(arr, 0, size - 1, 3);
// Output: 2
```

## Edge Cases

- Empty array
- Element not present in array
- Array with one element
- Binary search on unsorted array (will not work correctly)
