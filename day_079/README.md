# Day 79: Leetcode 2 - Add Two Numbers

## Problem Link

[Leetcode 2: Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)

## Coding Approaches

### Approach 1: In-place Addition

- Traverse both linked lists simultaneously.
- Add corresponding digits and carry, store result in the first list (`l1`).
- If one list is longer, continue adding carry to the remaining nodes.
- If carry remains at the end, add a new node.

**Pros:**

- Space efficient (O(1) extra space).

**Cons:**

- Modifies the input list.

### Approach 2: Using Dummy Node

- Use a dummy node to build a new result list.
- Traverse both lists, add digits and carry, append new nodes for each sum.
- Handles lists of different lengths and final carry easily.

**Pros:**

- Does not modify input lists.
- Clean and easy to implement.

**Cons:**

- Uses O(n) extra space for the new list.

---

See `Leetcode_2.cpp` for code implementations of both approaches.
