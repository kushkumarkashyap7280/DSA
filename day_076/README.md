# Day 76: Find Lucky Integer in an Array

## Problem: Find Lucky Integer in an Array

**LeetCode 1394**: [Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array/)

### Problem Description

Given an array of integers `arr`, a lucky integer is an integer that has a frequency in the array equal to its value. Return the largest lucky integer in the array. If there is no lucky integer, return -1.

#### Example 1:

- Input: `[2,2,3,4]`
- Output: `2`
- Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

#### Example 2:

- Input: `[1,2,2,3,3,3]`
- Output: `3`
- Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

#### Example 3:

- Input: `[2,2,2,3,3]`
- Output: `-1`
- Explanation: There are no lucky numbers in the array.

---

## Approaches & Visualization

### 1. Map-Based Frequency Count (My Approach)

- Use a map to count the frequency of each integer in the array.
- Iterate through the map to find the largest integer whose frequency equals its value.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

**Visualization:**

- For `[2,2,3,4]`, map: `{2:2, 3:1, 4:1}` → Only 2 is lucky (freq=2).

### 2. Optimized Counting Array

- Use a fixed-size array (since 1 ≤ arr[i] ≤ 500) to count frequencies.
- Iterate from 1 to 500, check if count[i] == i, and track the largest.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Visualization:**

- For `[1,2,2,3,3,3]`, count array: `count[1]=1, count[2]=2, count[3]=3` → All are lucky, largest is 3.

---

## Solution Files

- [leetcode_1394.cpp](leetcode_1394.cpp)

## Visual Resources

- [LeetCode 1394 - Find Lucky Integer (YouTube)](https://www.youtube.com/watch?v=QvQw1q6Qb6w)
