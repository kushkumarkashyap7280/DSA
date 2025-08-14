# Day 116: Binary Search Tree Problems

## Problem 1: Recover Binary Search Tree

**Problem Statement:**  
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

### Problem Link
- [LeetCode 99](https://leetcode.com/problems/recover-binary-search-tree/)

### Solution Approach

#### Approach: Morris Inorder Traversal (Optimal)
1. **Time Complexity:** O(n) - Each node is visited once
2. **Space Complexity:** O(1) - Constant extra space is used (no recursion stack)

**Key Insights:**
- Inorder traversal of a BST should be sorted
- Find the two nodes where the order is violated
- Swap the values of these nodes to recover the BST

### Test Cases

```cpp
// Test Case 1: Example 1 from problem statement
Input: [1,3,null,null,2]
Output: [3,1,null,null,2]

// Test Case 2: Example 2 from problem statement
Input: [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]

// Test Case 3: Large tree with swapped nodes
Input: [10,5,15,2,8,12,20,1,3,6,9,11,13,18,25] (with 5 and 25 swapped)
Output: [10,25,15,2,8,12,20,1,3,6,9,11,13,18,5]
```

---

## Problem 2: Convert Sorted Array to Binary Search Tree

**Problem Statement:**  
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

### Problem Link
- [LeetCode 108](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

### Solution Approach

#### Approach: Recursive with Midpoint
1. **Time Complexity:** O(n) - Each element is processed once
2. **Space Complexity:** O(log n) - Recursion stack for balanced tree

**Key Insights:**
- The middle element of the array becomes the root
- Left half of the array forms the left subtree
- Right half of the array forms the right subtree
- Recursively apply this to create a height-balanced BST

### Test Cases

```cpp
// Test Case 1: Example 1 from problem statement
Input: [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]

// Test Case 2: Even number of elements
Input: [1,3]
Output: [3,1] or [1,null,3]

// Test Case 3: Large array
Input: [1,2,3,4,5,6,7,8,9,10]
Output: Multiple valid outputs, e.g., [6,3,9,2,5,8,10,1,null,4,null,7,null]
```

---

## Problem 3: Minimum Depth of Binary Tree

**Problem Statement:**  
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

### Problem Link
- [LeetCode 111](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

### Solution Approach

#### Approach: Depth-First Search (DFS)
1. **Time Complexity:** O(n) - Each node is visited once
2. **Space Complexity:** O(h) - Where h is the height of the tree (recursion stack)

**Key Insights:**
- A leaf node has no left or right children
- The minimum depth is the minimum of the depths of the left and right subtrees
- Handle edge cases like empty tree and single node tree

### Test Cases

```cpp
// Test Case 1: Example 1 from problem statement
Input: [3,9,20,null,null,15,7]
Output: 2

// Test Case 2: Skewed tree
Input: [2,null,3,null,4,null,5,null,6]
Output: 5

// Test Case 3: Perfect binary tree
Input: [1,2,3,4,5,6,7]
Output: 3
```

### How to Run
1. Compile the code using a C++ compiler:
   ```bash
   g++ Leetcode_99.cpp -o recover_bst
   g++ Leetcode_108.cpp -o sorted_to_bst
   g++ Leetcode_111.cpp -o min_depth
   ```
2. Run the executables:
   ```bash
   ./recover_bst
   ./sorted_to_bst
   ./min_depth
   ```
3. The programs will run all test cases and display the results.

### Key Concepts
- **Binary Search Tree (BST):** A binary tree where for each node, all left descendants have values less than the node's value, and all right descendants have values greater than the node's value.
- **Inorder Traversal:** Traversal order: Left -> Root -> Right (produces sorted order for BST)
- **Tree Traversal Algorithms:** DFS (Depth-First Search) and BFS (Breadth-First Search)
- **Recursive Tree Operations:** Building and traversing trees using recursion

### Additional Notes
- All solutions include proper memory management to prevent leaks.
- The test cases cover various scenarios including edge cases.
- The code is well-commented for better understanding.
