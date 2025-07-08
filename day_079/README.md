# Day 79: Linked List Advanced Problems

## Problem 1: Add Two Numbers

**LeetCode 2**: [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

### Problem Description

Given two non-empty linked lists representing two non-negative integers, where the digits are stored in reverse order, add the two numbers and return the sum as a linked list. Each node contains a single digit. The two numbers do not contain any leading zero, except the number 0 itself.

#### Example

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

### Approaches & Complexity

#### Approach 1: In-place Addition

- Traverse both lists, add corresponding digits and carry, and store the result in the first list (`l1`).
- If one list is longer, continue adding the carry to the remaining nodes.
- If a carry remains at the end, add a new node.
- **Time Complexity:** O(n) (where n is the length of the longer list)
- **Space Complexity:** O(1)
- **Code:** [Leetcode_2.cpp](Leetcode_2.cpp) (function: `addTwoNumbersInPlace`)

#### Approach 2: Using Dummy Node

- Use a dummy node to simplify result list construction.
- Traverse both lists, add corresponding digits and carry, and create new nodes for the result.
- Handles lists of different lengths and final carry naturally.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (for the new result list)
- **Code:** [Leetcode_2.cpp](Leetcode_2.cpp) (function: `addTwoNumbers`)

---

## Problem 2: Copy List with Random Pointer

**LeetCode 138**: [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

### Problem Description

Given a linked list where each node contains an additional random pointer (which could point to any node or null), construct a deep copy of the list. The deep copy should have new nodes with the same values and the same next/random pointer structure, but no pointers to the original nodes.

#### Example

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

### Approaches & Complexity

#### Approach 1: Brute Force (No Map)

- For each node in the original list, create a new node and set up the next pointers.
- For each node, find the corresponding random pointer by traversing the original and copied lists.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n) (for the new list)
- **Code:** [Leetcode_138.cpp](Leetcode_138.cpp) (function: `copyRandomList`)

#### Approach 2: Using Hash Map

- Use a hash map to store the mapping from original nodes to their copies.
- First pass: create all new nodes and store them in the map.
- Second pass: assign next and random pointers using the map.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (for the map and new list)
- **Code:** [Leetcode_138.cpp](Leetcode_138.cpp) (function: `copyRandomListUsingmap`)

#### Approach 3: Optimized (O(1) Space)

- Interleave copied nodes with original nodes in the list.
- Set up random pointers for the copied nodes using the interleaved structure.
- Separate the copied list from the original.
- **Time Complexity:** O(n)
- **Space Complexity:** O(1) (excluding the output list)
- **Code:** [Leetcode_138.cpp](Leetcode_138.cpp) (function: `copyRandomListOptimised`)

---

## Summary Table

| Problem                       | Solution File                        | Approaches                  | Time Complexity | Space Complexity |
| ----------------------------- | ------------------------------------ | --------------------------- | --------------- | ---------------- |
| Add Two Numbers               | [Leetcode_2.cpp](Leetcode_2.cpp)     | In-place, Dummy Node        | O(n)            | O(1)/O(n)        |
| Copy List with Random Pointer | [Leetcode_138.cpp](Leetcode_138.cpp) | Brute Force, Map, Optimized | O(n^2)/O(n)     | O(n)/O(1)        |

---

## How to Run

- Each `.cpp` file contains a `main()` with test cases and output for all approaches.
- Compile with any C++ compiler (e.g., `g++ Leetcode_2.cpp -o add2`), then run the executable.

---
