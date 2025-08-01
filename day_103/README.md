# Day 103: Binary Tree Path Sum Problems

## Overview

Day 103 focuses on binary tree path sum problems covering various scenarios from simple root-to-leaf path sums to complex path sum III problems. The day includes problems involving path tracking, sum calculation, and advanced tree traversal techniques. Each problem demonstrates different approaches including DFS, recursion, and optimized solutions for complex tree scenarios.

## Problems Covered

### 1. Path Sum (Leetcode 112)

**File:** [Leetcode_112.cpp](./Leetcode_112.cpp)

**Problem Link:** [LeetCode 112 - Path Sum](https://leetcode.com/problems/path-sum/)

**Problem:** Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

**Key Points:**

- Path must start from root and end at a leaf node
- Return true if any such path exists, false otherwise
- A leaf is a node with no children

**Example:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
```

**Approach Implemented:**

```cpp
class Solution {
  bool isPossible(TreeNode* root, int &targetSum, int sum, bool &found) {
     if(!root) return false;
     if(found) return true;
     if(!root->left && !root->right){
             if((sum + root->val) == targetSum){
                 found = true;
                 return found;
             }
             return found;
     }
     bool left = isPossible(root->left, targetSum, sum + root->val, found);
     bool right = isPossible(root->right, targetSum, sum + root->val, found);

     return left || right;
 }
public:
 bool hasPathSum(TreeNode* root, int targetSum) {
     if(!root) return false;
     bool found = false;
    found = isPossible(root, targetSum, 0, found);
   return found;
 }
};
```

**Key Insight:** Track running sum and check at leaf nodes for target sum match.

**Time Complexity:** O(n) - visit each node once
**Space Complexity:** O(h) - recursion stack depth

---

### 2. Path Sum III (Leetcode 437)

**File:** [Leetcode_437.cpp](./Leetcode_437.cpp)

**Problem Link:** [LeetCode 437 - Path Sum III](https://leetcode.com/problems/path-sum-iii/)

**Problem:** Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum. The path does not need to start or end at the root or a leaf, but it must go downwards.

**Key Points:**

- Paths can start and end anywhere in the tree
- Must go downwards (parent to child)
- Count all such paths

**Example:**

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

**Approach Implemented:**

```cpp
class Solution {
  void solve(TreeNode* root, int &targetSum, int &count, vector<int> &path) {
      if(!root) return;
      path.push_back(root->val);
      solve(root->left, targetSum, count, path);
      solve(root->right, targetSum, count, path);

     long long sum = 0;
      for(int i = path.size()-1; i >= 0; i--) {
          sum += path[i];
          if(sum == targetSum) count++;
      }
       path.pop_back();
  }
public:
  int pathSum(TreeNode* root, int targetSum) {
      if(!root) return 0;
      vector<int> path;
      int count = 0;
      solve(root, targetSum, count, path);
      return count;
  }
};
```

**Key Insight:** Check all possible subpaths ending at each node.

**Time Complexity:** O(n²) - for each node, check all paths ending at it
**Space Complexity:** O(h) - recursion stack depth

---

### 3. Maximum Level Sum (Leetcode 1161)

**File:** [Leetcode_1161.cpp](./Leetcode_1161.cpp)

**Problem Link:** [LeetCode 1161 - Maximum Level Sum of Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-binary-tree/)

**Problem:** Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on. Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

**Key Points:**

- Find the level with maximum sum
- If multiple levels have same sum, return the smallest level
- Level numbering starts from 1

**Example:**

```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```

**Approach Implemented:**

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = INT_MIN;
        int maxLevel = 1;
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            int levelSum = 0;

            while (s--) {
                TreeNode* temp = q.front();
                q.pop();
                levelSum += temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};
```

**Key Insight:** Use BFS to track level sums and find the level with maximum sum.

**Time Complexity:** O(n) - visit each node once
**Space Complexity:** O(w) - where w is maximum width of tree

---

### 4. Sum of Nodes on the Longest Path

**File:** [Sum_of_nodes_on_the_longest_path.cpp](./Sum_of_nodes_on_the_longest_path.cpp)

**Problem Link:** [GeeksForGeeks - Sum of nodes on the longest path from root to leaf node](https://www.geeksforgeeks.org/problems/sum-of-nodes-on-the-longest-path-from-root-to-leaf-node/1)

**Problem:** Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that takes the root node of the binary tree as parameter and returns the sum of all nodes on the longest path from root to leaf node.

**Key Points:**

- Find the longest path from root to leaf
- If multiple paths have same length, return the one with maximum sum
- Return the sum of nodes on that path

**Example:**

```
Input:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
Output: 13
Explanation:
        4
       / \
      2   5
     / \ / \
    7  1 2  3
      /
     6
The highlighted path (4->2->1->6) gives the maximum sum as (4 + 2 + 1 + 6) = 13
```

**Approach Implemented:**

```cpp
class Solution {
public:
    void solve(Node* root, int sum, int len, int &maxLen, int &maxSum) {
        if (!root) return;

        sum += root->data;
        len++;

        if (!root->left && !root->right) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        solve(root->left, sum, len, maxLen, maxSum);
        solve(root->right, sum, len, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int maxLen = 0;
        int maxSum = 0;
        solve(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};
```

**Key Insight:** Track both length and sum of paths, update when longer path found or same length with higher sum.

**Time Complexity:** O(n) - visit each node once
**Space Complexity:** O(h) - recursion stack depth

---

### 5. Lowest Common Ancestor (Leetcode 236)

**File:** [Leetcode_236.cpp](./Leetcode_236.cpp)

**Problem Link:** [LeetCode 236 - Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

**Problem:** Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants.

**Key Points:**

- LCA is the lowest node that has both p and q as descendants
- A node can be a descendant of itself
- Both p and q exist in the tree

**Example:**

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself.
```

**Approach Implemented:**

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }
        if (left && !right) return left;
        if (right && !left) return right;

        return nullptr;
    }
};
```

**Key Insight:** If both nodes are found in different subtrees, current node is LCA.

**Time Complexity:** O(n) - visit each node once
**Space Complexity:** O(h) - recursion stack depth

---

## Key Concepts Covered

### 1. **Path Sum Variations**

- **Root-to-Leaf Path Sum:** Simple path from root to leaf with target sum
- **Path Sum III:** Any downward path with target sum
- **Longest Path Sum:** Path with maximum length and sum
- **Level Sum:** Sum of all nodes at a specific level

### 2. **Tree Traversal Techniques**

- **DFS with Sum Tracking:** Track running sum during traversal
- **BFS with Level Tracking:** Process nodes level by level
- **Recursive LCA Finding:** Use recursion to find common ancestor
- **Path Tracking:** Maintain path information during traversal

### 3. **Data Structure Usage**

- **Vector:** For storing paths and results
- **Queue:** For BFS and level order traversals
- **Recursion Stack:** For DFS implementations
- **Long Long:** For handling large sum calculations

### 4. **Algorithm Optimization**

- **Early Termination:** Stop when target found
- **Path Tracking:** Efficient path management
- **Level-based Processing:** BFS with level tracking
- **Recursive Solutions:** Elegant tree traversal

## Common Patterns

1. **Path Sum Patterns:**

   - **Simple Path Sum:** Track sum from root to leaf
   - **Path Sum III:** Check all subpaths ending at each node
   - **Longest Path:** Track both length and sum
   - **Level Sum:** Process nodes level by level

2. **LCA Patterns:**

   - Use recursion to find nodes in subtrees
   - Return LCA when both nodes found in different subtrees
   - Handle cases where one node is ancestor of other

3. **Tree Traversal Patterns:**
   - DFS for path problems
   - BFS for level problems
   - Recursion for LCA problems

## Time and Space Complexity Summary

| Problem                  | Time Complexity | Space Complexity | Approach                     |
| ------------------------ | --------------- | ---------------- | ---------------------------- |
| Path Sum (112)           | O(n)            | O(h)             | DFS with sum tracking        |
| Path Sum III (437)       | O(n²)           | O(h)             | DFS with path tracking       |
| Maximum Level Sum (1161) | O(n)            | O(w)             | BFS with level tracking      |
| Longest Path Sum         | O(n)            | O(h)             | DFS with length/sum tracking |
| Lowest Common Ancestor   | O(n)            | O(h)             | Recursive LCA finding        |

## Practice Problems

- [Leetcode 113 - Path Sum II](https://leetcode.com/problems/path-sum-ii/)
- [Leetcode 124 - Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
- [Leetcode 129 - Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)
- [Leetcode 257 - Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)
- [Leetcode 508 - Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

## Notes

- **Path Sum Variations:** Different requirements for path problems
- **Tree Traversal:** Foundation for all tree problems
- **Memory Management:** Consider space complexity for large trees
- **Edge Cases:** Handle null trees, single nodes, and skewed structures
- **Sum Calculations:** Use appropriate data types for large sums
- **Recursion:** Natural fit for tree problems
- **BFS vs DFS:** Choose based on problem requirements

## Sample Usage

### Running Path Sum:

```bash
g++ -o path_sum Leetcode_112.cpp
./path_sum
```

### Testing Path Sum III:

```bash
g++ -o path_sum_iii Leetcode_437.cpp
./path_sum_iii
```

### Testing Maximum Level Sum:

```bash
g++ -o max_level_sum Leetcode_1161.cpp
./max_level_sum
```

### Testing Longest Path Sum:

```bash
g++ -o longest_path_sum Sum_of_nodes_on_the_longest_path.cpp
./longest_path_sum
```

### Testing LCA:

```bash
g++ -o lca Leetcode_236.cpp
./lca
```

## Next Steps

- Explore more advanced tree problems (AVL, Red-Black trees)
- Practice tree serialization/deserialization
- Study tree-based algorithms (Segment trees, Fenwick trees)
- Implement tree balancing algorithms
- Explore tree-based dynamic programming problems
- Practice tree construction from different traversals
- Study tree optimization techniques (threaded trees, etc.)
- Explore graph algorithms on trees
- Practice tree-based interview problems
- Study advanced tree traversal techniques (Morris traversal, etc.)

## Key Takeaways

1. **Path Sum Variations:** Different approaches for different path requirements
2. **Tree Traversal:** Essential for all tree problems
3. **Data Structure Choice:** Vector for paths, Queue for BFS, Recursion for DFS
4. **Edge Case Handling:** Important for robust solutions
5. **Space-Time Trade-offs:** Consider both complexity aspects
6. **Pattern Recognition:** Similar problems often have similar solutions
7. **Optimization Techniques:** Early termination, efficient path tracking
8. **Implementation Details:** Careful attention to traversal order and data structures
