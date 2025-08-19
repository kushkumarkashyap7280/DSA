# Day 118: Binary Search Tree Problems

## Problem 1: Largest BST in a Binary Tree

**Problem Statement:**  
Given a binary tree, find the size of the largest subtree that is a Binary Search Tree (BST).

### Problem Link
- [GeeksforGeeks: Largest BST](https://www.geeksforgeeks.org/problems/largest-bst/1)

### Solution Approach

#### Approach: Postorder Traversal with Info Aggregation
1. **Time Complexity:** O(n) — Each node is processed once.
2. **Space Complexity:** O(h) — Recursion stack where h is the tree height.

**Key Insights:**
- For every node, compute information from left and right subtrees: min, max, size, and isBST.
- A subtree is BST if: `left.max < root->data < right.min` and both left and right are BSTs.
- Track the maximum size of a valid BST encountered.

### How to Run
```bash
# Compile
g++ largest_bst.cpp -o largest_bst
# Run
./largest_bst
```

---

## Problem 2: Merge Two BSTs

**Problem Statement:**  
Given two BSTs, return all elements of the two BSTs in a sorted list.

### Problem Link
- [GeeksforGeeks: Merge two BSTs](http://geeksforgeeks.org/problems/merge-two-bst-s/1)

### Solution Approach

#### Approach: Morris Inorder to Flatten + Two-pointer Merge
1. **Time Complexity:** O(n + m) — Visit all nodes once.
2. **Space Complexity:** O(1) extra for traversal (ignoring output), overall O(n + m) for result.

**Key Insights:**
- Use Morris inorder traversal to convert each BST into an in-order threaded list using right pointers.
- Merge two sorted linked lists (via right pointers) using a two-pointer technique into a result vector.

### How to Run
```bash
# Compile
g++ merge_two_bst.cpp -o merge_two_bst
# Run
./merge_two_bst
```

---

### Key Concepts
- BST properties and inorder traversal producing sorted order.
- Morris traversal to achieve O(1) extra space inorder.
- Combining subtree information (min, max, size, isBST) to validate BSTs.
