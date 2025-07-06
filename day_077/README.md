# Day 77: Linked List - Remove Duplicates & Loops

## Problem 1: Remove Duplicates from Sorted List

**LeetCode 83**: [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

### Problem Description

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

#### Approach & Visualization

- Traverse the list, compare each node with the next, and skip duplicates by adjusting pointers.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Solution File:** [Leetcode_83.cpp](Leetcode_83.cpp)

---

## Problem 2: Remove Duplicates from Sorted List II

**LeetCode 82**: [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

### Problem Description

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

#### Approach & Visualization

- Use a dummy node and two pointers to skip all nodes with duplicate values.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Solution File:** [Leetcode_82.cpp](Leetcode_82.cpp)

---

## Problem 3: Remove Loop in Linked List

**GFG:** [Remove loop in Linked List](https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)

### Problem Description

Given a linked list, remove the loop if present.

#### Approach & Visualization

- Use Floyd’s Cycle Detection to find the loop, then fix the last node's next pointer to null.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

**Solution File:** [remove_loop_from_linkedLIst_gfg.cpp](remove_loop_from_linkedLIst_gfg.cpp)
