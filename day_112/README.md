# Day 112 - Kth Element in BST Problems

This directory contains enhanced C++ implementations of two important Binary Search Tree (BST) problems focusing on finding the kth element, with comprehensive test cases and detailed complexity analysis.

## 📁 Files Overview

### 1. **Kth_largest_node_In_bst.cpp**
- **Problem**: Find the kth largest element in a BST
- **Source**: [GeeksforGeeks](https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/)
- **Algorithm**: Reverse inorder traversal with early termination
- **Time Complexity**: O(n) worst case, O(k) average case
- **Space Complexity**: O(h) where h is height of tree (recursion stack)

### 2. **Leetcode_230.cpp**
- **Problem**: Kth Smallest Element in a BST
- **Source**: [LeetCode 230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- **Algorithm**: Inorder traversal with early termination
- **Time Complexity**: O(n) worst case, O(k) average case
- **Space Complexity**: O(h) where h is height of tree (recursion stack)

## 🧪 Test Cases

### **Kth Largest Element in BST (7 Test Cases)**
- ✅ Small BST with k=2 (middle element)
- ✅ Right skewed tree (k=1)
- ✅ Left skewed tree (k=3)
- ✅ Larger balanced BST (k=3)
- ✅ Single node tree (k=1)
- ✅ k = number of nodes (smallest element)
- ✅ k = 1 (largest element)

### **Kth Smallest Element in BST (7 Test Cases)**
- ✅ Simple BST with k=1
- ✅ Larger BST with k=3
- ✅ Right skewed tree (k=2)
- ✅ Left skewed tree (k=3)
- ✅ Single node (k=1)
- ✅ k = number of nodes (largest element)
- ✅ k = 1 (smallest element)

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
# For kth largest element
g++ -o kth_largest Kth_largest_node_In_bst.cpp
./kth_largest

# For kth smallest element
g++ -o kth_smallest Leetcode_230.cpp
./kth_smallest
```

## 📝 Notes

### Key Observations:
1. **Kth Largest**:
   - Uses reverse inorder traversal (right-root-left)
   - Decrements counter after right subtree is processed
   - Returns immediately when k reaches 0

2. **Kth Smallest**:
   - Uses standard inorder traversal (left-root-right)
   - Decrements counter after left subtree is processed
   - Returns immediately when k reaches 0

### Optimizations:
- Early termination when kth element is found
- No need to process remaining nodes after finding the result
- Space efficient due to tail recursion optimization

### Edge Cases Handled:
- Empty tree
- Single node tree
- Skewed trees (left and right)
- k = 1 (smallest/largest element)
- k = number of nodes (largest/smallest element)
- k out of bounds (handled by returning -1 in some implementations)

## 🛠️ Implementation Details

### Kth Largest Element:
```cpp
int findKthLargest(Node* root, int& k) {
    if (!root) return -1;
    int right = findKthLargest(root->right, k);
    if (right != -1) return right;
    k--;
    if (k == 0) return root->data;
    return findKthLargest(root->left, k);
}
```

### Kth Smallest Element:
```cpp
int findKthSmallest(TreeNode* root, int& k) {
    if (!root) return -1;
    int left = findKthSmallest(root->left, k);
    if (left != -1) return left;
    k--;
    if (k == 0) return root->val;
    return findKthSmallest(root->right, k);
}
```

## 📈 Performance Analysis

### Time Complexity:
- **Best Case**: O(k) when k is small
- **Worst Case**: O(n) when k = n or tree is skewed
- **Average Case**: O(k) for balanced trees

### Space Complexity:
- **Worst Case**: O(h) where h is height of tree
- **Best Case**: O(log n) for balanced trees
- **Average Case**: O(log n) for random BSTs

## 🤔 Follow-up Questions

1. How would you modify the solution if the BST can be modified (insert/delete operations are frequent)?
2. Can you solve it using O(1) extra space (Morris Traversal)?
3. How would you handle duplicate values in the BST?
4. What if you need to find kth largest/smallest frequently on a static BST?
