# Day 72: Linked Lists & LeetCode Practice

Welcome to Day 72! This folder contains:

- A comprehensive LinkedList folder with all major types of linked list implementations in C++.
- Today's solved LeetCode problem, with approach and code.

## 📂 LinkedList Folder Overview

The `LinkedList` folder includes beginner-friendly, best-practice C++ implementations for:

| Linked List Type            | File Name                                                                 |
| --------------------------- | ------------------------------------------------------------------------- |
| Singly Linked List          | [singlyLinkedList.cpp](./LinkedList/singlyLinkedList.cpp)                 |
| Doubly Linked List          | [doublyLinkedList.cpp](./LinkedList/doublyLinkedList.cpp)                 |
| Circular Singly Linked List | [circularSinglyLinkedList.cpp](./LinkedList/circularSinglyLinkedList.cpp) |
| Circular Doubly Linked List | [circularDoublyLinkedList.cpp](./LinkedList/circularDoublyLinkedList.cpp) |

Each file contains:

- Clean class structure
- Add, insert, delete, and print methods
- Rail-style output for easy visualization
- Robust memory management

## 🔗 Quick Links

- [Singly Linked List](./LinkedList/singlyLinkedList.cpp)
- [Doubly Linked List](./LinkedList/doublyLinkedList.cpp)
- [Circular Singly Linked List](./LinkedList/circularSinglyLinkedList.cpp)
- [Circular Doubly Linked List](./LinkedList/circularDoublyLinkedList.cpp)

## 📝 LeetCode Problem Solved Today

### [LeetCode 3330. Find the Original Typed String I](https://leetcode.com/problems/find-the-original-typed-string-i/)

**Approach:**

- Traverse the string and count consecutive groups of the same character.
- For each group of length > 1, Alice could have intended to type that character fewer times (at most once per group), so add all possible reductions for that group.
- Sum all possibilities for each group and return the total.

**Time Complexity:** O(n), where n is the length of the input string (each character is visited once).

**Space Complexity:** O(1), since only a constant amount of extra space is used.

> _You can find the code for this problem in:_  
> [leetcode_3330.cpp](./leetcode_3330.cpp)

---

Feel free to explore the code files for hands-on learning and reference. If you have any questions or want to practice more, check out the other days' folders!
