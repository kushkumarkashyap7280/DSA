# Day 111 - Binary Search Tree Problems

This directory contains enhanced C++ implementations of three important Binary Search Tree (BST) problems with comprehensive test cases and detailed complexity analysis.

## 📁 Files Overview

### 1. **Inorder_predecessor_and_successor.cpp**
- **Problem**: Find inorder predecessor and successor of a given key in BST
- **Source**: [GeeksforGeeks](https://www.geeksforgeeks.org/problems/predecessor-and-successor/1)
- **Algorithm**: Iterative search with predecessor/successor tracking
- **Time Complexity**: O(h) where h is height of BST
- **Space Complexity**: O(1)

### 2. **Leetcode_450.cpp**
- **Problem**: Delete Node in a BST
- **Source**: [LeetCode 450](https://leetcode.com/problems/delete-node-in-a-bst/description/)
- **Algorithm**: Recursive deletion with inorder successor replacement
- **Time Complexity**: O(h) where h is height of BST
- **Space Complexity**: O(h) due to recursion stack

### 3. **Leetcode_98.cpp**
- **Problem**: Validate Binary Search Tree
- **Source**: [LeetCode 98](https://leetcode.com/problems/validate-binary-search-tree/description/)
- **Algorithm**: Inorder traversal with previous node tracking
- **Time Complexity**: O(n) where n is number of nodes
- **Space Complexity**: O(h) due to recursion stack

## 🧪 Test Cases

Each file includes comprehensive test suites covering:

### **Inorder Predecessor and Successor (10 Test Cases)**
- ✅ Basic BST with existing key
- ✅ Key as leaf node
- ✅ Non-existent key
- ✅ Minimum key (no predecessor)
- ✅ Maximum key (no successor)
- ✅ Single node tree
- ✅ Key smaller than all nodes
- ✅ Key larger than all nodes
- ✅ Right skewed tree
- ✅ Left skewed tree

### **Delete Node in BST (10 Test Cases)**
- ✅ Delete leaf node
- ✅ Delete node with one child (left)
- ✅ Delete node with one child (right)
- ✅ Delete node with two children
- ✅ Delete root node
- ✅ Delete non-existent key
- ✅ Delete from single node tree
- ✅ Delete from empty tree
- ✅ Right skewed tree deletion
- ✅ Left skewed tree deletion

### **Validate BST (13 Test Cases)**
- ✅ Valid BST
- ✅ Invalid BST (right child smaller than root)
- ✅ Single node (always valid)
- ✅ Valid larger BST
- ✅ Invalid BST (duplicate values)
- ✅ Invalid BST (left subtree violation)
- ✅ Invalid BST (right subtree violation)
- ✅ Right skewed valid BST
- ✅ Left skewed valid BST
- ✅ BST with negative values
- ✅ Invalid BST with negative values
- ✅ Two nodes - valid
- ✅ Two nodes - invalid

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library support

### Compilation and Execution

```bash
# Compile any file
g++ -o program_name filename.cpp

# Run the program
./program_name  # Linux/Mac
program_name.exe  # Windows
```

### Example:
```bash
# For predecessor and successor
g++ -o pred_succ Inorder_predecessor_and_successor.cpp
./pred_succ

# For delete node
g++ -o delete_node Leetcode_450.cpp
./delete_node

# For validate BST
g++ -o validate_bst Leetcode_98.cpp
./validate_bst
```

## 📊 Complexity Analysis

| Problem | Time Complexity | Space Complexity | Notes |
|---------|----------------|------------------|-------|
| **Predecessor & Successor** | O(h) | O(1) | h = height of BST |
| **Delete Node** | O(h) | O(h) | Recursion stack depth |
| **Validate BST** | O(n) | O(h) | n = number of nodes |

### Complexity Breakdown:
- **Best Case (Balanced BST)**: h = O(log n)
- **Worst Case (Skewed BST)**: h = O(n)

## 🔍 Algorithm Details

### **Predecessor and Successor Algorithm**
1. Search for the key while maintaining potential predecessor and successor
2. If key found, find actual predecessor (rightmost in left subtree) and successor (leftmost in right subtree)
3. If key not found, the last nodes where we went right/left are predecessor/successor

### **Delete Node Algorithm**
1. Search for the node to delete
2. Handle three cases:
   - **No children**: Simply delete the node
   - **One child**: Replace node with its child
   - **Two children**: Replace with inorder successor (smallest in right subtree)

### **Validate BST Algorithm**
1. Perform inorder traversal of the BST
2. In a valid BST, inorder traversal gives nodes in strictly increasing order
3. Keep track of previous node and compare with current node
4. If current node value ≤ previous node value, it's not a valid BST

## 📈 Performance Characteristics

### **Space Optimization**
- Predecessor/Successor uses iterative approach for O(1) space
- Delete and Validate use recursion for cleaner code but O(h) space

### **Time Optimization**
- All algorithms achieve optimal time complexity for their respective problems
- BST properties are leveraged for efficient searching and validation

## 🛠️ Features Added

- **✅ Comprehensive Test Suites**: Each file includes 10-13 test cases
- **✅ Detailed Complexity Analysis**: Time and space complexity with explanations
- **✅ Helper Functions**: Tree creation and result display utilities
- **✅ Edge Case Coverage**: Empty trees, single nodes, boundary conditions
- **✅ Algorithm Documentation**: Step-by-step algorithm explanations
- **✅ Expected Output Comments**: Each test case includes expected results

## 📝 Notes

- All implementations follow standard BST properties
- Test cases cover both valid and invalid scenarios
- Memory management is handled appropriately
- Code is well-commented for educational purposes

## 🎯 Learning Objectives

After studying these implementations, you should understand:
1. BST traversal and search techniques
2. Node deletion strategies in BSTs
3. BST validation using inorder traversal
4. Time/space complexity analysis
5. Edge case handling in tree algorithms

---

**Author**: Enhanced with comprehensive test cases and complexity analysis  
**Date**: 2025-08-09  
**Purpose**: Educational and interview preparation
