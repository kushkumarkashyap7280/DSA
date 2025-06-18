# Day 59 - LeetCode 136: Single Number

## Problem Description

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

The solution must implement:

- Linear runtime complexity O(n)
- Constant extra space O(1)

[Problem Link](https://leetcode.com/problems/single-number/)

## Solution Approach

The solution uses the XOR (^) bitwise operator with the following properties:

1. XOR of a number with itself is 0: a ^ a = 0
2. XOR of a number with 0 is the number itself: a ^ 0 = a
3. XOR is associative and commutative: (a ^ b) ^ c = a ^ (b ^ c)

### Algorithm Steps:

1. Initialize result as 0
2. XOR all numbers in the array with result
3. The final value of result will be the single number

### Why this works:

- All numbers that appear twice will XOR to 0
- The single number will XOR with 0, giving itself
- Order doesn't matter due to XOR's commutative property

### Time Complexity: O(n)

- Single pass through the array

### Space Complexity: O(1)

- Only using one variable regardless of input size

## Example Test Cases

```cpp
Input: nums = [2,2,1]
Output: 1
Explanation:
- 0 ^ 2 = 2
- 2 ^ 2 = 0
- 0 ^ 1 = 1

Input: nums = [4,1,2,1,2]
Output: 4
Explanation:
- All pairs cancel out except 4

Input: nums = [1]
Output: 1
Explanation:
- Single element case
```

## Key Points

1. XOR operator properties are key to solution
2. No need for extra space (like hash table)
3. Works with negative numbers
4. Order of numbers doesn't matter
5. Handles all constraints efficiently

## Edge Cases

1. Array with single element
2. Array with negative numbers
3. Array with 0 as the single number
4. Maximum array length (3 \* 10^4)
5. Maximum/minimum element values (±3 \* 10^4)
