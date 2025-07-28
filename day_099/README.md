# Day 099: Advanced Binary Tree Problems and Tree Properties

## Overview

Day 099 focuses on advanced binary tree problems, including tree properties, diameter calculations, balance checking, tree comparison, and specialized tree structures like sum trees. The day covers both fundamental tree concepts and advanced algorithmic techniques for solving complex tree-related problems.

## Problems Covered

### 1. Height of Binary Tree

**File:** [Height_of_binary_tree.cpp](./Height_of_binary_tree.cpp)

**Description:** Comprehensive implementation of binary tree height calculation with multiple approaches and tree construction methods.

**Features:**

- **Tree Construction:**
  - Recursive tree construction
  - Level order tree construction
  - Manual tree building for testing
- **Height Calculation Methods:**
  - Recursive height calculation
  - Iterative height calculation using level order traversal
  - Optimized height calculation
- **Tree Traversal Methods:**
  - Inorder, Preorder, Postorder traversals
  - Level order traversal
- **Utility Functions:**
  - Tree visualization
  - Node counting
  - Balance checking

**Key Concepts:**

- Tree height vs depth understanding
- Recursive vs iterative approaches
- Memory management in tree operations
- Time/Space complexity analysis

**Time Complexity:**

- Height calculation: O(n)
- Tree construction: O(n)
- Traversal: O(n)

**Space Complexity:**

- Recursive: O(h) where h is tree height
- Iterative: O(w) where w is maximum width

---

### 2. Diameter of Binary Tree (Leetcode 543)

**File:** [Leetcode_543.cpp](./Leetcode_543.cpp)

**Problem Link:** [Leetcode 543 - Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

**Problem:** Given the root of a binary tree, return the length of the diameter of the tree. The diameter is the length of the longest path between any two nodes in a tree.

**Example:**

```
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

**Approaches Implemented:**

1. **Brute Force Approach (O(N²)):**

   ```cpp
   class SolutionBruteForce {
       int height(TreeNode* node) {
           if(!node) return 0;
           return 1 + max(height(node->left), height(node->right));
       }
       int diameterOfBinaryTree(TreeNode* root) {
           if(!root) return 0;
           int l = diameterOfBinaryTree(root->left);
           int r = diameterOfBinaryTree(root->right);
           int c = height(root->left) + height(root->right);
           return max(c, max(l, r));
       }
   };
   ```

2. **Optimized Approach (O(N)):**

   ```cpp
   class SolutionOptimized {
       int dfs(TreeNode* root, int &diameter) {
           if (!root) return 0;
           int left = dfs(root->left, diameter);
           int right = dfs(root->right, diameter);
           diameter = max(diameter, left + right);
           return 1 + max(left, right);
       }
       int diameterOfBinaryTree(TreeNode* root) {
           int diameter = 0;
           dfs(root, diameter);
           return diameter;
       }
   };
   ```

**Key Insight:** The diameter of a tree is the maximum of:

- Diameter of left subtree
- Diameter of right subtree
- Height of left subtree + height of right subtree

**Time Complexity:**

- Brute Force: O(N²)
- Optimized: O(N)

**Space Complexity:** O(H) where H is the height of the tree

---

### 3. Balanced Binary Tree (Leetcode 110)

**File:** [Leetcode_110.cpp](./Leetcode_110.cpp)

**Problem Link:** [Leetcode 110 - Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

**Problem:** Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

**Approaches Implemented:**

1. **Brute Force Approach (O(N²)):**

   ```cpp
   class SolutionBruteForce {
       int height(TreeNode* root) {
           if(!root) return 0;
           return 1 + max(height(root->left), height(root->right));
       }
       bool isBalanced(TreeNode* root) {
           if(!root) return true;
           bool l = isBalanced(root->left);
           bool r = isBalanced(root->right);
           bool c = abs(height(root->left) - height(root->right)) <= 1;
           return (l && r && c);
       }
   };
   ```

2. **Optimized Approach (O(N)):**

   ```cpp
   class SolutionOptimised {
       pair<bool, int> isValid(TreeNode* root) {
           if(!root) return {true, 0};
           pair<bool, int> l = isValid(root->left);
           pair<bool, int> r = isValid(root->right);
           bool diff = abs(l.second - r.second) <= 1;
           bool balanced = l.first && r.first && diff;
           int height = 1 + max(l.second, r.second);
           return {balanced, height};
       }
       bool isBalanced(TreeNode* root) {
           if(!root) return true;
           return isValid(root).first;
       }
   };
   ```

**Key Insight:** Use a single traversal to calculate both balance status and height simultaneously.

**Time Complexity:**

- Brute Force: O(N²)
- Optimized: O(N)

**Space Complexity:** O(H) where H is the height of the tree

---

### 4. Same Tree (Leetcode 100)

**File:** [Leetcode_100.cpp](./Leetcode_100.cpp)

**Problem Link:** [Leetcode 100 - Same Tree](https://leetcode.com/problems/same-tree/)

**Problem:** Given the roots of two binary trees p and q, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

**Example:**

```
Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false
```

**Approach:**

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if ((p && !q) || (!p && q)) return false;
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        return ((p->val == q->val) && l && r);
    }
};
```

**Key Insight:** Recursively compare both structure and values simultaneously.

**Time Complexity:** O(min(N, M)) where N and M are the number of nodes in trees p and q
**Space Complexity:** O(min(H1, H2)) where H1 and H2 are the heights of trees p and q

---

### 5. Sum Tree

**File:** [Sum_tree.cpp](./Sum_tree.cpp)

**Problem Link:** [GFG - Sum Tree](https://www.geeksforgeeks.org/problems/sum-tree/1)

**Problem:** Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false. A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree.

**Example:**

```
Input:
    3
   / \
  1   2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node.

Input:
          10
        /    \
      20      30
    /   \
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
```

**Approach:**

```cpp
class Solution {
    pair<bool, int> isValid(Node* root) {
        if(!root) return {true, 0};
        if(!root->left && !root->right) return {true, root->data};

        pair<bool, int> l = isValid(root->left);
        pair<bool, int> r = isValid(root->right);

        bool isSumTree = (l.first && r.first) && (l.second + r.second == root->data);
        int totalSum = l.second + r.second + root->data;

        return {isSumTree, totalSum};
    }
public:
    bool isSumTree(Node* root) {
        if(!root) return true;
        return isValid(root).first;
    }
};
```

**Key Insight:** Use a single traversal to calculate both sum tree validity and subtree sums simultaneously.

**Time Complexity:** O(N) where N is the number of nodes in the tree
**Space Complexity:** O(H) where H is the height of the tree (recursion stack)

---

## Key Concepts Covered

### 1. **Tree Properties and Calculations**

- Tree height and depth understanding
- Diameter calculation techniques
- Balance checking algorithms
- Tree comparison methods
- Specialized tree structures (sum trees)

### 2. **Optimization Techniques**

- Single traversal solutions
- Pair return types for multiple values
- Recursive vs iterative approaches
- Memory-efficient implementations

### 3. **Algorithm Analysis**

- Time complexity analysis for tree operations
- Space complexity considerations
- Trade-offs between different approaches
- Problem-specific optimizations

### 4. **Advanced Tree Concepts**

- Diameter vs height understanding
- Balance factor calculations
- Tree isomorphism checking
- Specialized tree properties

## Common Patterns

1. **Tree Traversal Patterns:**

   - DFS (Depth-First Search) with recursion
   - Single traversal for multiple calculations
   - Pair return types for efficiency

2. **Optimization Patterns:**

   - Combine multiple calculations in one pass
   - Use reference parameters for efficiency
   - Leverage tree properties for optimization

3. **Problem-Specific Techniques:**
   - Diameter calculation using height
   - Balance checking with height calculation
   - Tree comparison with structure checking
   - Sum tree validation with subtree sums

## Practice Problems

- [Leetcode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Leetcode 111 - Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
- [Leetcode 226 - Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
- [Leetcode 101 - Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
- [Leetcode 112 - Path Sum](https://leetcode.com/problems/path-sum/)

## Notes

- **Diameter Calculation:** Always consider the path through the root
- **Balance Checking:** Use single traversal for efficiency
- **Tree Comparison:** Check both structure and values
- **Sum Trees:** Leaf nodes are always valid sum trees
- **Memory Management:** Be careful with memory allocation in tree operations
- **Problem Analysis:** Understand problem constraints before choosing approach

## Sample Usage

### Running Height of Binary Tree:

```bash
g++ -o height_tree Height_of_binary_tree.cpp
./height_tree
```

### Testing Diameter of Binary Tree:

```bash
g++ -o diameter Leetcode_543.cpp
./diameter
```

### Testing Balanced Binary Tree:

```bash
g++ -o balanced Leetcode_110.cpp
./balanced
```

### Testing Same Tree:

```bash
g++ -o same_tree Leetcode_100.cpp
./same_tree
```

### Testing Sum Tree:

```bash
g++ -o sum_tree Sum_tree.cpp
./sum_tree
```

## Next Steps

- Explore more advanced tree problems (AVL, Red-Black trees)
- Practice tree serialization/deserialization
- Study tree-based algorithms (Segment trees, Fenwick trees)
- Implement tree balancing algorithms
- Explore tree-based dynamic programming problems
