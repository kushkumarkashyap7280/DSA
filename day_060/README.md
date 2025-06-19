# Day 60 - LeetCode 169: Majority Element

## Problem Description

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

[Problem Link](https://leetcode.com/problems/majority-element/)

## Solution Approach

The solution uses the Boyer-Moore Voting Algorithm:

1. Initialize variables:

   - count = 0 (counter for current candidate)
   - candidate = any value (stores potential majority element)

2. Iterate through array:

   - If count is 0, set current element as candidate
   - If current element equals candidate, increment count
   - If current element differs from candidate, decrement count

3. Return the final candidate

### Why This Works:

- If an element is majority (>n/2 occurrences), it will always be more frequent than all other elements combined
- Non-majority elements will eventually cancel out with other elements
- The last surviving candidate must be the majority element

### Time Complexity: O(n)

- Single pass through the array

### Space Complexity: O(1)

- Only using two variables regardless of input size

## Example Test Cases

```cpp
Input: nums = [3,2,3]
Output: 3
Explanation:
3 appears 2 times which is more than ⌊3/2⌋ = 1 time

Input: nums = [2,2,1,1,1,2,2]
Output: 2
Explanation:
2 appears 4 times which is more than ⌊7/2⌋ = 3 times

Input: nums = [1]
Output: 1
Explanation:
Single element is always majority
```

## Key Points

1. Boyer-Moore algorithm is optimal for this problem
2. No need for sorting or hash map
3. Works because majority element always exists
4. Handles positive and negative numbers
5. Count resets when reaching zero

## Edge Cases

1. Array of size 1
2. All elements same
3. Exactly n/2 + 1 occurrences
4. Maximum array length (5 \* 10^4)
5. Maximum/minimum element values (±10^9)
6. Mixed positive and negative numbers
