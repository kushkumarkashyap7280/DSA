# Leetcode 430: Flatten a Multilevel Doubly Linked List

This directory contains the solution for Leetcode Problem 430: Flatten a Multilevel Doubly Linked List.

## Problem Description

Given a multilevel doubly linked list where nodes may have a child pointer to another doubly linked list, flatten the list so that all nodes appear in a single-level, doubly linked list. All child pointers should be set to null in the result.

- [Leetcode Problem Link](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

## Solution Approaches

- **Iterative Approach:**
  - Traverse the list, and whenever a node with a child is found, insert the child list between the current node and its next node. Update all pointers accordingly.
  - Time Complexity: O(n)
  - Space Complexity: O(1)
- **Recursive Approach:**
  - Recursively flatten the child list and insert it between the current node and its next node.
  - Time Complexity: O(n)
  - Space Complexity: O(n) (due to recursion stack)

## How to Run

1. Open `Leetcode_430.cpp` in your C++ environment.
2. Compile and run the file. The main function constructs a sample multilevel doubly linked list, flattens it, and prints the result.

## Files

- `Leetcode_430.cpp`: Contains the implementation and a sample test case.

---

# Leetcode 148: Sort List

- [Leetcode Problem Link](https://leetcode.com/problems/sort-list/)

Given the head of a singly linked list, return the list after sorting it in ascending order.

## Approach

- **Merge Sort:**
  - Uses the merge sort algorithm to sort the linked list in O(n log n) time and O(log n) space (due to recursion stack).
  - Efficient for linked lists as it does not require random access.

## How to Run

1. Open `Leetcode_148.cpp` in your C++ environment.
2. Compile and run the file. The main function constructs sample linked lists, sorts them, and prints the results.

## Files

- `Leetcode_148.cpp`: Contains the implementation and sample test cases.
