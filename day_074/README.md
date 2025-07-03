# Day 74: Linked List Problems

## Problem 1: Middle of the Linked List

**LeetCode 876**: [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)

### Problem Description

Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

#### Approaches Discussed

1. **Using a Vector**: Store all nodes in a vector, then return the node at index `size/2`. (O(n) time, O(n) space)
2. **Counting Nodes**: First count the nodes, then traverse again to the middle. (O(n) time, O(1) space)
3. **Two Pointers**: Use a slow and a fast pointer; when the fast pointer reaches the end, the slow pointer is at the middle. (O(n) time, O(1) space)

- See: [leetcode_876.cpp](leetcode_876.cpp)

---

## Problem 2: Reverse Doubly Linked List

**geeks for geeks **: [reverse doubly linked list](http://geeksforgeeks.org/reverse-a-doubly-linked-list/)

### Problem Description

Given the head of a doubly linked list, reverse the list and return the new head.

#### Approach

- Traverse the list, swapping the `next` and `prev` pointers for each node.
- At the end, update the head to the last node processed.
- Time Complexity: O(n)
- Space Complexity: O(1)

- See: [reverse_doubly_linked_list.cpp](reverse_doubly_linked_list.cpp)
