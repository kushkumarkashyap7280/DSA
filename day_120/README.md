# Heapify Algorithm

This file demonstrates the Heapify process, which is fundamental to heap operations and heap sort.

## What is Heapify?

Heapify is a process used to maintain the heap property:

- In a **max heap**, every parent node must be greater than or equal to its children.
- In a **min heap**, every parent node must be less than or equal to its children.

There are two types:

- **Heapify-up** (used during insertion): Compare the inserted node with its parent and swap if necessary.
- **Heapify-down** (used during deletion): Compare the root with its children and swap with the larger (or smaller, for min heap) child if needed.

## Example

Given an array: `[54, 53, 55, 52, 50]` (1-based index, with -1 as dummy at index 0)

After applying heapify, the array becomes a max heap: `[55, 53, 54, 52, 50]`

## Code

See [`heapify.cpp`](heapify.cpp) for the implementation and test cases.

## Test Output

The code includes a test suite that prints `[PASS]` for each successful test case, or `[FAIL]` with details if any test fails.

---

**Related Links:**

- [Build Min Heap (Coding Ninjas)](https://www.naukri.com/code360/problems/build-min-heap_1171167)

# Heap Sort

This file demonstrates the Heap Sort algorithm with a test suite, similar to the style used in Leetcode problems.

## Problem

Given an array `arr[]`, sort the array elements using Heap Sort.

**Examples:**

- Input: `[4, 1, 3, 9, 7]`  
  Output: `[1, 3, 4, 7, 9]`
- Input: `[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]`  
  Output: `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`
- Input: `[2, 1, 5]`  
  Output: `[1, 2, 5]`

## Approach

- Build a max heap from the array.
- Repeatedly extract the maximum element and move it to the end of the array.
- Heapify the reduced heap after each extraction.

## Code

See [`heap_sort.cpp`](heap_sort.cpp) for the implementation and test cases.

## Test Output

The code includes a test suite that prints `[PASS]` for each successful test case, or `[FAIL]` with details if any test fails.
