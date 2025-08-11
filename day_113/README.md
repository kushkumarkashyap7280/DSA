# Day 113 - BST Problems

This directory contains enhanced C++ implementations of Binary Search Tree (BST) problems, focusing on range sums, lowest common ancestors, and two-sum problems, with comprehensive test cases and detailed complexity analysis.

## 📁 Files Overview

### 1. **Leetcode_938.cpp**
- **Problem**: Range Sum of BST
- **Source**: [LeetCode 938](https://leetcode.com/problems/range-sum-of-bst/)
- **Algorithm**: Morris Traversal for in-order traversal with range checking
- **Time Complexity**: O(n) - Each node is visited exactly once
- **Space Complexity**: O(1) - Uses constant extra space (no recursion stack or queue)

### 2. **Leetcode_235.cpp**
- **Problem**: Lowest Common Ancestor of a Binary Search Tree
- **Source**: [LeetCode 235](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- **Algorithm**: Iterative BST traversal
- **Time Complexity**: O(h) where h is the height of the tree
- **Space Complexity**: O(1) - Uses constant extra space

### 3. **Leetcode_653.cpp**
- **Problem**: Two Sum IV - Input is a BST
- **Source**: [LeetCode 653](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
- **Algorithm**: Morris Inorder Traversal + Two Pointers
- **Time Complexity**: O(n) - Morris traversal + linear scan
- **Space Complexity**: O(n) - To store the inorder traversal

## 🧪 Test Cases

### **Range Sum of BST (3 Test Cases)**
- ✅ Standard case with multiple nodes in range
- ✅ Edge case with all nodes in range
- ✅ Single node tree

### **Lowest Common Ancestor (3 Test Cases)**
- ✅ Standard case with LCA in the middle
- ✅ Edge case where one node is ancestor of another
- ✅ Single node tree

### **Two Sum IV (4 Test Cases)**
- ✅ Standard case with valid pair
- ✅ Case with no valid pair
- ✅ Single node tree
- ✅ Two nodes that sum to target

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library support

### Compilation and Execution

```bash
# Compile any file
g++ -std=c++11 Leetcode_938.cpp -o range_sum
./range_sum

# Or compile with optimizations
g++ -std=c++11 -O2 Leetcode_235.cpp -o lca
./lca

# For Windows
cl /EHsc Leetcode_653.cpp
Leetcode_653.exe
```

## 🧠 Key Concepts

1. **Morris Traversal**: Used for in-order traversal with O(1) space complexity
2. **BST Property**: Leveraging the binary search tree property for efficient searching
3. **Two Pointers**: Efficiently finding pairs in a sorted array
4. **Tree Traversal**: Different approaches to traverse binary trees

## 📝 Notes

- All solutions include proper memory management
- Test cases cover edge cases and typical scenarios
- Code is well-commented for better understanding
- Time and space complexity analysis is provided for each solution
