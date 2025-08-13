# Day 115: Binary Search Tree Construction from Preorder Traversal

## Problem: Construct Binary Search Tree from Preorder Traversal

**Problem Statement:**  
Given an array of integers preorder, which represents the preorder traversal of a BST, construct the tree and return its root. It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

### Problem Link
- [LeetCode 1008](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

### Solution Approach

#### Approach 1: Recursive with Bounds (Optimal)
1. **Time Complexity:** O(n) - Each node is processed exactly once
2. **Space Complexity:** O(n) - Recursion stack in worst case (for skewed trees)

**Key Insights:**
- The first element in preorder is always the root of the BST
- The next elements are first all left descendants, then right descendants
- We can use the BST property to set bounds on valid values for left and right subtrees

#### Approach 2: Insertion Method (Commented in Code)
1. **Time Complexity:** O(n²) in worst case (for skewed trees)
2. **Space Complexity:** O(n) - For the recursion stack

### Test Cases

```cpp
// Test Case 1: Example from problem statement
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

// Test Case 2: Simple two-node tree
Input: [1,3]
Output: [1,null,3]

// Test Case 3: Single node
Input: [5]
Output: [5]

// Test Case 4: Right-skewed tree
Input: [1,2,3,4,5]
Output: [1,null,2,null,3,null,4,null,5]

// Test Case 5: Left-skewed tree
Input: [5,4,3,2,1]
Output: [5,4,null,3,null,2,null,1]
```

### How to Run
1. Compile the code using a C++ compiler:
   ```bash
   g++ Leetcode_1008.cpp -o bst_from_preorder
   ```
2. Run the executable:
   ```bash
   ./bst_from_preorder
   ```
3. The program will run all test cases and display the results.

### Key Concepts
- **Binary Search Tree (BST):** A binary tree where for each node, all left descendants have values less than the node's value, and all right descendants have values greater than the node's value.
- **Preorder Traversal:** Traversal order: Root -> Left -> Right
- **Recursive Tree Construction:** Building the tree by recursively processing the preorder array while maintaining valid BST properties.

### Additional Notes
- The solution handles edge cases such as empty input and single-node trees.
- The implementation includes memory management to prevent leaks.
- The test cases cover various scenarios including balanced and skewed trees.
