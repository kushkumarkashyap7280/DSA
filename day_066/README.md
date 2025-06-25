# Day 66 - LeetCode 268: Missing Number

## Problem Description

Given an array `nums` containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

[LeetCode 268: Missing Number](https://leetcode.com/problems/missing-number/)

## Solution Approach

This solution uses the XOR approach:

- XOR all numbers from 0 to n (inclusive).
- XOR all elements in the array.
- The result is the missing number, since all other numbers cancel out.

### Time Complexity

- O(n)

### Space Complexity

- O(1)

## Example Usage

```cpp
vector<int> nums = {3, 0, 1};
cout << "The missing number is: " << missingNumber(nums) << endl; // Output: 2
```

## Edge Cases

- Array with only one element (e.g., [0] or [1])
- Array with missing number at the start or end of the range
- Large n (up to 10^4)

## Key Points

- XOR is used for O(1) space and O(n) time.
- No extra data structures are needed.
- Handles all constraints efficiently.
