# Day 82: Stack Problems and Implementations

This folder contains various stack-related problems and implementations, including classic Leetcode problems and custom stack data structures using arrays and linked lists.

## Table of Contents
- [Leetcode_70.cpp](#leetcode_70cpp)
- [Leetcode_155.cpp](#leetcode_155cpp)
- [two_stacks_in_a_array.cpp](#two_stacks_in_a_arraycpp)
- [stack_using_array.cpp](#stack_using_arraycpp)
- [stack.cpp](#stackcpp)

---

## Leetcode_70.cpp
- **Problem:** [Leetcode 70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- **Description:**
  - Given `n` steps, you can climb 1 or 2 steps at a time. Find the number of distinct ways to reach the top.
- **Approach:**
  - Iterative dynamic programming using two variables to store the number of ways to reach the previous two steps.
  - Also includes a commented-out recursive solution for reference.
- **Time Complexity:** O(n) (iterative DP)
- **Space Complexity:** O(1) (only two variables used)

---

## Leetcode_155.cpp
- **Problem:** [Leetcode 155. Min Stack](https://leetcode.com/problems/min-stack/)
- **Description:**
  - Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
- **Approach:**
  - Custom stack implemented using a linked list. Each node stores its value and the minimum value up to that node.
  - On push, the new node’s min is the minimum of the new value and the previous min.
- **Time Complexity:** O(1) for all operations
- **Space Complexity:** O(n) for n elements in the stack

---

## two_stacks_in_a_array.cpp
- **Problem:** [Two Stacks in an Array (Coding Ninjas/Naukri)](https://www.naukri.com/code360/problems/two-stacks_983634)
- **Description:**
  - Implement two stacks using a single array.
- **Approach:**
  - Two pointers: one starts from the left (stack1), the other from the right (stack2). They grow towards each other.
  - Push and pop operations are implemented for both stacks, with overflow/underflow checks.
- **Time Complexity:** O(1) for all operations
- **Space Complexity:** O(n) (single array of size n)

---

## stack_using_array.cpp
- **Description:**
  - Implements a stack with basic operations using a dynamically allocated array.
- **Approach:**
  - Class `myStack` with methods for push, pop, peek, size, and traversal.
  - Handles overflow and underflow with exceptions. Interactive menu-driven main function for demonstration.
- **Time Complexity:** O(1) for push, pop, peek, size
- **Space Complexity:** O(n) for n elements (array)

---

## stack.cpp
- **Description:**
  - Implements a stack with basic operations using a singly linked list.
- **Approach:**
  - Class `myStack` with methods for push, pop, peek, isEmpty, size, and deep copy (clone).
  - Demonstrates both STL stack usage (commented) and custom implementation.
- **Time Complexity:** O(1) for push, pop, peek, isEmpty, size
- **Space Complexity:** O(n) for n elements (linked list nodes)

---

## References
- [Leetcode 70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [Leetcode 155. Min Stack](https://leetcode.com/problems/min-stack/)
- [Two Stacks in an Array (Coding Ninjas/Naukri)](https://www.naukri.com/code360/problems/two-stacks_983634) 