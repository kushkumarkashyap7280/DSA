# Day 114 - Advanced BST Operations

This directory contains C++ implementations of advanced Binary Search Tree (BST) operations, focusing on balancing BST and flattening BST to a sorted list, with comprehensive test cases and detailed complexity analysis.

## 📁 Files Overview

### 1. **Leetcode_1382.cpp**
- **Problem**: Balance a Binary Search Tree
- **Source**: [LeetCode 1382](https://leetcode.com/problems/balance-a-binary-search-tree/)
- **Algorithm**: Morris Inorder Traversal + Construct Balanced BST
- **Time Complexity**: O(n) - Morris traversal is O(n) and building balanced BST is O(n)
- **Space Complexity**: O(n) - To store the inorder traversal

### 2. **Leetcode_114.cpp**
- **Problem**: Flatten BST to Sorted List
- **Source**: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1)
- **Algorithm**: Morris Traversal with In-order Processing
- **Time Complexity**: O(n) - Each node is visited exactly once
- **Space Complexity**: O(1) - Uses constant extra space (no recursion stack or queue)

## 🧪 Test Cases

### **Balance BST (3 Test Cases)**
- ✅ Standard case with unbalanced BST
- ✅ Already balanced BST
- ✅ Single node tree

### **Flatten BST (3 Test Cases)**
- ✅ Standard case with multiple nodes
- ✅ Single node tree
- ✅ Skewed tree (left or right)

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library support

### Compilation and Execution

```bash
# Compile any file
g++ -std=c++11 Leetcode_1382.cpp -o balance_bst
./balance_bst

# Or compile with optimizations
g++ -std=c++11 -O2 Leetcode_114.cpp -o flatten_bst
./flatten_bst

# For Windows
cl /EHsc Leetcode_1382.cpp
Leetcode_1382.exe
```

## 🧠 Key Concepts

1. **Morris Traversal**: Used for in-order traversal with O(1) space complexity
2. **BST Properties**: Leveraging the binary search tree property for efficient operations
3. **Balanced BST Construction**: Building a balanced BST from a sorted array
4. **Tree Manipulation**: Techniques for modifying tree structures in-place

## 📝 Notes

- All solutions include proper memory management
- Test cases cover edge cases and typical scenarios
- Code is well-commented for better understanding
- Time and space complexity analysis is provided for each solution
