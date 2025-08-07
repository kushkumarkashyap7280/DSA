# Day 109: Binary Search Tree Fundamentals and Operations

## Overview

Day 109 focuses on Binary Search Tree (BST) fundamentals and essential operations. The problems cover BST construction, searching, and insertion operations, providing a comprehensive understanding of BST data structure and its properties. These implementations demonstrate both iterative and recursive approaches to BST operations.

## Problems Covered

### 1. Binary Search Tree Implementation

**File:** [Binary_search_tree.cpp](./Binary_search_tree.cpp)

**Problem:** Complete implementation of Binary Search Tree with basic operations including insertion, traversal (inorder, preorder, postorder), and level-order printing. This serves as a foundation for understanding BST properties and operations.

### 2. Search in a Binary Search Tree (Leetcode 700)

**File:** [Leetcode_700.cpp](./Leetcode_700.cpp)

**Problem Link:** [LeetCode 700 - Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/)

**Problem:** Given the root of a binary search tree (BST) and an integer val, find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

### 3. Insert into a Binary Search Tree (Leetcode 701)

**File:** [Leetcode_701.cpp](./Leetcode_701.cpp)

**Problem Link:** [LeetCode 701 - Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

**Problem:** Given the root node of a binary search tree (BST) and a value to insert into the tree, return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

### 4. Construct Binary Search Tree from Preorder Traversal (Leetcode 1008)

**File:** [Leetcode_1008.cpp](./Leetcode_1008.cpp)

**Problem Link:** [LeetCode 1008 - Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

**Problem:** Given an array of integers preorder, which represents the preorder traversal of a BST, construct the tree and return its root. It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

## Problem Analysis

### Key Constraints

#### BST Implementation
- Maintains BST property: left subtree < root < right subtree
- Supports multiple traversal methods
- Dynamic insertion of elements
- Level-order traversal for visualization

#### LeetCode 700 (Search in BST)
- Number of nodes in range [1, 5000]
- Node values are unique
- -10^7 ≤ Node.val ≤ 10^7
- Root is guaranteed to be a valid BST

#### LeetCode 701 (Insert into BST)
- Number of nodes in range [0, 10^4]
- -10^8 ≤ Node.val ≤ 10^8
- All values are unique
- Multiple valid insertion positions possible

#### LeetCode 1008 (Construct from Preorder)
- 1 ≤ preorder.length ≤ 100
- 1 ≤ preorder[i] ≤ 1000
- Values in preorder are distinct
- Input guaranteed to represent valid BST preorder

## Algorithmic Approaches

### BST Search (LeetCode 700)

#### Iterative Approach
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    while(root){
        if(val == root->val) return root;
        if(val > root->val){
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return root;
}
```

**Time Complexity:** O(h) where h is height of tree
**Space Complexity:** O(1)

**Key Points:**
- Leverages BST property for efficient search
- Iterative approach saves stack space
- Returns subtree rooted at found node

### BST Insertion (LeetCode 701)

#### Recursive Approach
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}
```

**Time Complexity:** O(h) where h is height of tree
**Space Complexity:** O(h) for recursion stack

**Key Points:**
- Maintains BST property during insertion
- Creates new node when reaching null position
- Multiple valid insertion points possible

### BST Construction from Preorder (LeetCode 1008)

#### Insertion-based Approach
```cpp
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = nullptr;
    for(int val : preorder) {
        root = insert(root, val);
    }
    return root;
}
```

**Time Complexity:** O(n²) worst case, O(n log n) average
**Space Complexity:** O(h) for recursion

**Key Points:**
- Sequentially inserts elements from preorder array
- Relies on BST insertion to maintain structure
- First element becomes root

## Implementation Details

### Memory Management
- **Dynamic Allocation**: Uses `new TreeNode(val)` for node creation
- **Proper Cleanup**: Includes `deleteTree` function for memory deallocation
- **Memory Safety**: Prevents memory leaks in test cases

### Tree Traversals
- **Inorder**: Left → Root → Right (gives sorted order)
- **Preorder**: Root → Left → Right (useful for tree reconstruction)
- **Postorder**: Left → Right → Root (useful for deletion)
- **Level-order**: BFS traversal for visualization

### BST Properties
- **Search Efficiency**: O(log n) average case for balanced trees
- **Insertion Flexibility**: Multiple valid positions for new nodes
- **Ordering**: Inorder traversal yields sorted sequence

## Common Pitfalls

### Search Operations
- **Null Checks**: Always verify root is not null before operations
- **Value Comparison**: Ensure correct comparison operators for navigation
- **Return Values**: Return appropriate subtree or null as specified

### Insertion Operations
- **Base Case**: Handle empty tree insertion correctly
- **BST Property**: Maintain ordering during insertion
- **Memory Allocation**: Ensure proper node creation

### Tree Construction
- **Order Dependency**: Preorder sequence must represent valid BST
- **Recursive Structure**: Proper handling of subtree construction
- **Memory Management**: Avoid memory leaks during construction

## Key Learnings

- **BST Fundamentals**: Understanding of BST properties and operations
- **Search Efficiency**: Leveraging BST structure for O(log n) operations
- **Insertion Strategies**: Multiple approaches to maintain BST property
- **Tree Construction**: Building BST from traversal sequences
- **Memory Management**: Proper allocation and deallocation practices

These problems establish a solid foundation for more advanced BST operations and tree algorithms, demonstrating the efficiency and versatility of binary search trees.
