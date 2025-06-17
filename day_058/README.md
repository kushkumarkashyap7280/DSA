# Day 58 - LeetCode 20: Valid Parentheses

## Problem Description

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

[Problem Link](https://leetcode.com/problems/valid-parentheses/)

## Solution Approach

The solution uses a stack-based approach with the following strategy:

1. Create an empty stack to store opening brackets
2. Iterate through each character in the string:
   - If it's an opening bracket ('(', '{', '['), push it onto the stack
   - If it's a closing bracket:
     - If stack is empty, return false (no matching opening bracket)
     - If top of stack doesn't match current closing bracket, return false
     - Otherwise, pop the matching opening bracket from stack
3. After iteration, return true if stack is empty (all brackets matched)

### Time Complexity: O(n)

- Single pass through the string where n is the length of string

### Space Complexity: O(n)

- Stack can store up to n/2 opening brackets in worst case

## Example Test Cases

```cpp
Input: s = "()"
Output: true
Explanation: Simple matched pair

Input: s = "()[]{}"
Output: true
Explanation: Multiple matched pairs in sequence

Input: s = "(]"
Output: false
Explanation: Mismatched bracket types

Input: s = "([)]"
Output: false
Explanation: Incorrect nesting order

Input: s = "{[]}"
Output: true
Explanation: Properly nested brackets
```

## Key Points

1. Stack is perfect for matching pairs and maintaining order
2. Need to check both bracket type and order
3. Empty stack at end means all brackets were matched
4. Early return false for mismatched brackets
5. Handle empty string or odd length string cases

## Edge Cases

1. Empty string (length 0)
2. Single character (always invalid)
3. Odd length string (always invalid)
4. All opening brackets
5. All closing brackets
6. Mixed invalid sequences
