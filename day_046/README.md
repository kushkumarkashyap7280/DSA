# Day 46: LeetCode 35 - Search Insert Position

## Problem Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

The algorithm must run in O(log n) time complexity.

## Examples

1. Input: nums = [1,3,5,6], target = 5
   Output: 2
   Explanation: Target 5 found at index 2

2. Input: nums = [1,3,5,6], target = 2
   Output: 1
   Explanation: Target 2 would be inserted at index 1

3. Input: nums = [1,3,5,6], target = 7
   Output: 4
   Explanation: Target 7 would be inserted at the end (index 4)

## Approach

### Binary Search Implementation

The solution uses binary search algorithm because:

1. The array is sorted
2. We need O(log n) time complexity
3. We need to find a specific position for insertion

Key points in the implementation:

1. Initialize pointers:

   - left = 0 (start of array)
   - right = array length - 1 (end of array)

2. While left ≤ right:

   - Calculate mid = left + (right - left)/2
   - If nums[mid] == target: return mid
   - If nums[mid] < target: search in right half
   - If nums[mid] > target: search in left half

3. Return Position:
   - When loop ends, left pointer will be at the insertion position
   - Return left for the correct insert position

### Time and Space Complexity

- Time Complexity: O(log n)

  - Binary search reduces search space by half in each iteration
  - Takes logarithmic time to find position

- Space Complexity: O(1)
  - Only uses a constant amount of extra space
  - Variables are independent of input size

## Code Structure

The solution consists of two main parts:

1. searchInsert function: Implements binary search logic
2. main function: Contains test cases and output formatting

## Common Pitfalls

1. Integer Overflow:

   - Use left + (right - left)/2 instead of (left + right)/2
   - Prevents potential overflow in large arrays

2. Loop Condition:

   - Use left <= right to handle edge cases
   - Ensures all elements are checked

3. Return Value:
   - Return left after loop ends
   - Gives correct insertion position for non-found targets

## Notes

- The array must be sorted for binary search to work
- All elements in array must be distinct
- The solution handles both finding existing elements and determining insert positions
- The approach maintains the required O(log n) time complexity
