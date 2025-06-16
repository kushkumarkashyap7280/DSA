# Day 57 - LeetCode 2016: Maximum Difference Between Increasing Elements

## Problem Description

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[j] and nums[i] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

[Problem Link](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)

## Solution Approach

The solution uses a single-pass approach with the following strategy:

1. Initialize `maxDiff` as -1 (default return value if no valid pair found)
2. Keep track of the minimum element seen so far (`minElement`)
3. For each element:
   - If current element is greater than `minElement`, calculate potential difference
   - Update `maxDiff` if the new difference is larger
   - If current element is smaller than `minElement`, update `minElement`

### Time Complexity: O(n)

- Single pass through the array

### Space Complexity: O(1)

- Only using constant extra space

## Example Test Cases

```cpp
Input: nums = [7,1,5,4]
Output: 4
Explanation: Maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4

Input: nums = [9,4,3,2]
Output: -1
Explanation: No valid pair exists where nums[i] < nums[j] and i < j

Input: nums = [1,5,2,10]
Output: 9
Explanation: Maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9
```

## Key Points

1. The order of elements matters (i must be less than j)
2. We need to find elements where nums[i] < nums[j]
3. If no valid pair exists, return -1
4. The solution must handle both increasing and non-increasing sequences correctly

## Edge Cases

1. Array with all decreasing elements
2. Array with all same elements
3. Minimum array size (n = 2)
4. Maximum array size (n = 1000)
5. Large element values (up to 10^9)
