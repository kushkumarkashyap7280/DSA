# Day 73: LeetCode Linked List Problems

Welcome to Day 73! This folder contains solutions to several important LeetCode linked list problems, each with a direct code link, problem link, and a detailed explanation of the approach, time complexity, and space complexity.

## 📂 Problem List

| Problem Name & Link                                                                                     | Solution File                          |
| ------------------------------------------------------------------------------------------------------- | -------------------------------------- |
| [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)                          | [leetcode_206.cpp](./leetcode_206.cpp) |
| [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [leetcode_19.cpp](./leetcode_19.cpp)   |
| [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)                    | [leetcode_234.cpp](./leetcode_234.cpp) |
| [707. Design Linked List](https://leetcode.com/problems/design-linked-list/)                            | [leetcode_707.cpp](./leetcode_707.cpp) |

---

## 📝 Problem Approaches

### 206. Reverse Linked List

**Approach:**

- Use two pointers (`prev` and `curr`) to reverse the links of the list one by one.
- Iterate through the list, at each step reverse the `next` pointer of the current node to point to the previous node.
- Continue until all nodes are reversed, then return the new head (`prev`).

**Time Complexity:** O(n), where n is the number of nodes (each node is visited once).

**Space Complexity:** O(1), in-place reversal with no extra data structures.

---

### 19. Remove Nth Node From End of List

**Approach:**

- Use two pointers (`fast` and `slow`). Move `fast` n steps ahead.
- Then move both pointers together until `fast` reaches the end. `slow` will be just before the node to remove.
- Adjust pointers to remove the nth node from the end.

**Time Complexity:** O(n)

**Space Complexity:** O(1)

---

### 234. Palindrome Linked List

**Approach:**

- Find the middle of the list using slow/fast pointers.
- Reverse the second half of the list.
- Compare the first and second halves node by node.
- Restore the list if needed.

**Time Complexity:** O(n)

**Space Complexity:** O(1)

---

### 707. Design Linked List

**Approach:**

- Implement a custom linked list class with methods for get, add at head/tail/index, and delete at index.
- Carefully handle edge cases for empty list, head/tail updates, and invalid indices.

**Time Complexity:** O(1) for add at head/tail, O(k) for get/add/delete at index.

**Space Complexity:** O(n), where n is the number of nodes.

---

Feel free to explore the code files for hands-on learning and reference. If you have any questions or want to practice more, check out the other days' folders!
