# Kth Smallest Element in Array

This day covers the problem of finding the kth smallest element in an array, including both a general approach and a LeetCode-specific solution.

## Problems Covered

### 1. Kth Smallest Element in Array

- Find the kth smallest element in an unsorted array.
- Common approaches: sorting, min-heap/max-heap, quickselect.
- Efficient solutions use heaps or quickselect for better than O(n log n) time.
- See: [`kth_smallest_element_in_array.cpp`](kth_smallest_element_in_array.cpp)

### 2. [Leetcode 215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

- Given an integer array `nums` and an integer `k`, return the kth largest element in the array.
- Note: It is the kth largest element in sorted order, not the kth distinct element.
- See: [`Leetcode_215.cpp`](Leetcode_215.cpp)

## Example

- Input: `nums = [3,2,1,5,6,4], k = 2`
- Output: `5` (2nd largest is 5)

- Input: `nums = [3,2,3,1,2,4,5,5,6], k = 4`
- Output: `4` (4th largest is 4)

## Approaches

- **Heap (Priority Queue):**
  - Use a min-heap of size k to keep track of the k largest elements.
  - Time: O(n log k)
- **Quickselect:**
  - Partition-based selection algorithm, average O(n) time.

## Files

- `kth_smallest_element_in_array.cpp`: General kth smallest element solution(s).
- `Leetcode_215.cpp`: LeetCode 215 solution with test cases.

---

**Tip:** Both problems are classic interview questions and are often solved using heaps or quickselect for efficiency.
