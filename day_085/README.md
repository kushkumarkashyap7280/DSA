# Day 85 - 14 July, 2025

## Stack & Parentheses Problems

### 32. Longest Valid Parentheses

- [LeetCode Link](https://leetcode.com/problems/longest-valid-parentheses/)
- **Difficulty:** Hard
- **C++ Solution:** [leetcode_32.cpp](leetcode_32.cpp)

**Problem:**
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

**Example:**
Input: s = "(()"
Output: 2

**Constraints:**

- 0 <= s.length <= 3 \* 10^4
- s[i] is '(', or ')'.

**Approaches:**

- Stack: O(n) time, O(n) space
- Left/Right Counters: O(n) time, O(1) space

See code for detailed explanation and implementation.

## Stack Problems

### Next Smaller Element

- [Naukri Code360 Link](https://www.naukri.com/code360/problems/next-smaller-element_1112581)
- **Difficulty:** Medium
- **C++ Solution:** [next_smallest_element.cpp](next_smallest_element.cpp)

**Problem:**
Given an array of integers, for each element, find the next smaller element to its right. If none exists, output -1 for that element.

**Example:**
Input: [2, 3, 1]
Output: [1, 1, -1]

## Linked List Problems

### 1290. Convert Binary Number in a Linked List to Integer

- [LeetCode Link](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
- **Difficulty:** Easy
- **C++ Solution:** [leetcode_1290.cpp](leetcode_1290.cpp)

**Problem:**
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number. Return the decimal value of the number in the linked list.

**Example:**
Input: head = [1,0,1]
Output: 5

**Constraints:**

- The Linked List is not empty.
- Number of nodes will not exceed 30.
- Each node's value is either 0 or 1.
