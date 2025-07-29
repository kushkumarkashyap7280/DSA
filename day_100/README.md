# Day 100: Binary Tree Traversal and Tree Properties

## Overview

Day 100 focuses on fundamental binary tree problems covering various traversal techniques, tree properties, and advanced tree algorithms. The day includes symmetric tree checking, level order traversals (normal, zigzag, and bottom-up), and maximum depth calculations. Each problem demonstrates different approaches including recursive, iterative, and optimized solutions.

## Problems Covered

### 1. Symmetric Tree (Leetcode 101)

**File:** [Leetcode_101.cpp](./Leetcode_101.cpp)

**Problem Link:** [Leetcode 101 - Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

**Problem:** Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

**Example:**

```
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false
```

**Approaches Implemented:**

1. **Recursive Solution (O(N)):**

   ```cpp
   class SolutionRecursive {
   public:
       bool isMirror(TreeNode *l, TreeNode *r) {
           if (!l && !r) return true;
           if (!l || !r) return false;
           return (l->val == r->val) &&
                  (isMirror(l->left, r->right)) &&
                  (isMirror(l->right, r->left));
       }
       bool isSymmetric(TreeNode *root) {
           if (!root) return true;
           return isMirror(root->left, root->right);
       }
   };
   ```

2. **Iterative Solution using Queue (O(N)):**

   ```cpp
   class SolutionIterative {
   public:
       bool isSymmetric(TreeNode* root) {
           if(!root) return true;
           queue<TreeNode*> q1, q2;
           q1.push(root->left);
           q2.push(root->right);
           while(!q1.empty() && !q2.empty()) {
               TreeNode* temp1 = q1.front(); q1.pop();
               TreeNode* temp2 = q2.front(); q2.pop();
               if(!temp1 && !temp2) continue;
               if((!temp1 || !temp2) || (temp1->val != temp2->val))
                   return false;
               q1.push(temp1->left); q2.push(temp2->right);
               q1.push(temp1->right); q2.push(temp2->left);
           }
           return true;
       }
   };
   ```

3. **Alternative Iterative Solution using Stack (O(N)):**
   ```cpp
   class SolutionIterativeStack {
   public:
       bool isSymmetric(TreeNode* root) {
           if (!root) return true;
           stack<TreeNode*> s1, s2;
           s1.push(root->left);
           s2.push(root->right);
           while (!s1.empty() && !s2.empty()) {
               TreeNode* left = s1.top(); s1.pop();
               TreeNode* right = s2.top(); s2.pop();
               if (!left && !right) continue;
               if (!left || !right || left->val != right->val)
                   return false;
               s1.push(left->left); s1.push(left->right);
               s2.push(right->right); s2.push(right->left);
           }
           return s1.empty() && s2.empty();
       }
   };
   ```

**Key Insight:** Compare left subtree with right subtree mirror-wise.

**Time Complexity:** O(N) - visits each node once
**Space Complexity:**

- Recursive: O(H) where H is tree height
- Iterative: O(W) where W is maximum width

---

### 2. Binary Tree Level Order Traversal (Leetcode 102)

**File:** [Leetcode_102.cpp](./Leetcode_102.cpp)

**Problem Link:** [Leetcode 102 - Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

**Problem:** Given the root of a binary tree, return the level order traversal of its nodes' values (i.e., from left to right, level by level).

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Approaches Implemented:**

1. **Queue with nullptr as Level Separator:**

   ```cpp
   class Solution {
   public:
       vector<vector<int>> levelOrder(TreeNode* root) {
           vector<vector<int>> ans;
           if(!root) return ans;
           queue<TreeNode*> q;
           vector<int> v;
           q.push(root);
           q.push(nullptr);
           while(!q.empty()) {
               TreeNode* temp = q.front();
               q.pop();
               if(temp) {
                   v.push_back(temp->val);
                   if (temp->left) q.push(temp->left);
                   if (temp->right) q.push(temp->right);
               } else {
                   ans.push_back(v);
                   v.clear();
                   if(!q.empty()) q.push(nullptr);
               }
           }
           return ans;
       }
   };
   ```

2. **Queue with Size Tracking:**
   ```cpp
   class SolutionAlternative {
   public:
       vector<vector<int>> levelOrder(TreeNode* root) {
           vector<vector<int>> ans;
           if(!root) return ans;
           queue<TreeNode*> q;
           q.push(root);
           while(!q.empty()) {
               int levelSize = q.size();
               vector<int> currentLevel;
               for(int i = 0; i < levelSize; i++) {
                   TreeNode* node = q.front(); q.pop();
                   currentLevel.push_back(node->val);
                   if(node->left) q.push(node->left);
                   if(node->right) q.push(node->right);
               }
               ans.push_back(currentLevel);
           }
           return ans;
       }
   };
   ```

**Key Insight:** Use queue for BFS traversal and track level boundaries.

**Time Complexity:** O(N)
**Space Complexity:** O(W) where W is maximum width

---

### 3. Binary Tree Zigzag Level Order Traversal (Leetcode 103)

**File:** [Leetcode_103.cpp](./Leetcode_103.cpp)

**Problem Link:** [Leetcode 103 - Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

**Problem:** Given the root of a binary tree, return the zigzag level order traversal of its nodes' values (i.e., from left to right, then right to left for the next level and alternate between).

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

**Approaches Implemented:**

1. **Queue with Reverse Operation:**

   ```cpp
   class Solution {
   public:
       vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           vector<vector<int>> ans;
           if(!root) return ans;
           bool ltr = true;
           queue<TreeNode*> q;
           q.push(root);
           while(!q.empty()) {
               vector<int> v;
               int s = q.size();
               for(int i = 0; i < s; i++) {
                   TreeNode* temp = q.front(); q.pop();
                   v.push_back(temp->val);
                   if(temp->left) q.push(temp->left);
                   if(temp->right) q.push(temp->right);
               }
               if(!ltr) reverse(v.begin(), v.end());
               ans.push_back(v);
               ltr = !ltr;
           }
           return ans;
       }
   };
   ```

2. **Deque-based Solution:**
   ```cpp
   class SolutionAlternative {
   public:
       vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
           vector<vector<int>> ans;
           if(!root) return ans;
           deque<TreeNode*> dq;
           dq.push_back(root);
           bool ltr = true;
           while(!dq.empty()) {
               int levelSize = dq.size();
               vector<int> currentLevel;
               for(int i = 0; i < levelSize; i++) {
                   TreeNode* node;
                   if(ltr) {
                       node = dq.front(); dq.pop_front();
                       if(node->left) dq.push_back(node->left);
                       if(node->right) dq.push_back(node->right);
                   } else {
                       node = dq.back(); dq.pop_back();
                       if(node->right) dq.push_front(node->right);
                       if(node->left) dq.push_front(node->left);
                   }
                   currentLevel.push_back(node->val);
               }
               ans.push_back(currentLevel);
               ltr = !ltr;
           }
           return ans;
       }
   };
   ```

**Key Insight:** Use a flag to alternate direction and reverse/use deque accordingly.

**Time Complexity:** O(N)
**Space Complexity:** O(W) where W is maximum width

---

### 4. Maximum Depth of Binary Tree (Leetcode 104)

**File:** [Leetcode_104.cpp](./Leetcode_104.cpp)

**Problem Link:** [Leetcode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

**Problem:** Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Approaches Implemented:**

1. **Recursive Solution (O(N)):**

   ```cpp
   class SolutionRecursive {
   public:
       int maxDepth(TreeNode* root) {
           if(!root) return 0;
           return 1 + max(maxDepth(root->left), maxDepth(root->right));
       }
   };
   ```

2. **Iterative BFS Solution (O(N)):**

   ```cpp
   class Solution {
   public:
       int maxDepth(TreeNode* root) {
           if(!root) return 0;
           queue<TreeNode*> q;
           q.push(root);
           int depth = 0;
           while(!q.empty()) {
               int s = q.size();
               while(s) {
                   TreeNode* temp = q.front(); q.pop();
                   if(temp->left) q.push(temp->left);
                   if(temp->right) q.push(temp->right);
                   s--;
               }
               depth++;
           }
           return depth;
       }
   };
   ```

3. **Iterative DFS Solution (O(N)):**
   ```cpp
   class SolutionDFS {
   public:
       int maxDepth(TreeNode* root) {
           if(!root) return 0;
           stack<pair<TreeNode*, int>> st;
           st.push({root, 1});
           int maxDepth = 0;
           while(!st.empty()) {
               TreeNode* node = st.top().first;
               int depth = st.top().second;
               st.pop();
               maxDepth = max(maxDepth, depth);
               if(node->right) st.push({node->right, depth + 1});
               if(node->left) st.push({node->left, depth + 1});
           }
           return maxDepth;
       }
   };
   ```

**Key Insight:** Height of tree equals maximum depth.

**Time Complexity:** O(N)
**Space Complexity:**

- Recursive: O(H) where H is tree height
- BFS: O(W) where W is maximum width
- DFS: O(H) where H is tree height

---

### 5. Binary Tree Level Order Traversal II (Leetcode 107)

**File:** [Leetcode_107.cpp](./Leetcode_107.cpp)

**Problem Link:** [Leetcode 107 - Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

**Problem:** Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values (i.e., from left to right, level by level from leaf to root).

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

**Approaches Implemented:**

1. **Queue with Reverse (O(N)):**

   ```cpp
   class Solution {
   public:
       vector<vector<int>> levelOrderBottom(TreeNode* root) {
           vector<vector<int>> ans;
           if (!root) return ans;
           queue<TreeNode *> q;
           vector<int> v;
           q.push(root);
           q.push(nullptr);
           while (!q.empty()) {
               TreeNode *temp = q.front(); q.pop();
               if (temp) {
                   v.push_back(temp->val);
                   if (temp->left) q.push(temp->left);
                   if (temp->right) q.push(temp->right);
               } else {
                   ans.push_back(v);
                   v.clear();
                   if (!q.empty()) q.push(nullptr);
               }
           }
           reverse(ans.begin(), ans.end());
           return ans;
       }
   };
   ```

2. **Stack-based Solution (O(N)):**
   ```cpp
   class SolutionAlternative {
   public:
       vector<vector<int>> levelOrderBottom(TreeNode* root) {
           vector<vector<int>> ans;
           if(!root) return ans;
           queue<TreeNode*> q;
           stack<vector<int>> st;
           q.push(root);
           while(!q.empty()) {
               int levelSize = q.size();
               vector<int> currentLevel;
               for(int i = 0; i < levelSize; i++) {
                   TreeNode* node = q.front(); q.pop();
                   currentLevel.push_back(node->val);
                   if(node->left) q.push(node->left);
                   if(node->right) q.push(node->right);
               }
               st.push(currentLevel);
           }
           while(!st.empty()) {
               ans.push_back(st.top());
               st.pop();
           }
           return ans;
       }
   };
   ```

**Key Insight:** Perform normal level order traversal and reverse the result.

**Time Complexity:** O(N)
**Space Complexity:** O(W) where W is maximum width

---

### 6. Binary Tree Inorder Traversal (Leetcode 94)

**File:** [Leetcode_94.cpp](./Leetcode_94.cpp)

**Problem Link:** [Leetcode 94 - Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

**Problem:** Given the root of a binary tree, return the inorder traversal of its nodes' values.

**Example:**

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**Approaches Implemented:**

1. **Recursive Solution (O(N)):**

   ```cpp
   class SolutionRecursive {
   public:
       void inorder(TreeNode* root, vector<int>& result) {
           if(!root) return;
           inorder(root->left, result);
           result.push_back(root->val);
           inorder(root->right, result);
       }
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int> result;
           inorder(root, result);
           return result;
       }
   };
   ```

2. **Iterative Solution using Stack (O(N)):**

   ```cpp
   class SolutionIterative {
   public:
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int> result;
           stack<TreeNode*> st;
           TreeNode* current = root;
           while(current || !st.empty()) {
               while(current) {
                   st.push(current);
                   current = current->left;
               }
               current = st.top(); st.pop();
               result.push_back(current->val);
               current = current->right;
           }
           return result;
       }
   };
   ```

3. **Morris Traversal (O(N)):**
   ```cpp
   class SolutionMorris {
   public:
       vector<int> inorderTraversal(TreeNode* root) {
           vector<int> result;
           TreeNode* current = root;
           while(current) {
               if(!current->left) {
                   result.push_back(current->val);
                   current = current->right;
               } else {
                   TreeNode* predecessor = current->left;
                   while(predecessor->right && predecessor->right != current) {
                       predecessor = predecessor->right;
                   }
                   if(!predecessor->right) {
                       predecessor->right = current;
                       current = current->left;
                   } else {
                       predecessor->right = nullptr;
                       result.push_back(current->val);
                       current = current->right;
                   }
               }
           }
           return result;
       }
   };
   ```

**Key Insight:** Inorder traversal visits nodes in left-root-right order.

**Time Complexity:** O(N)
**Space Complexity:**

- Recursive: O(H) where H is tree height
- Iterative: O(H) where H is tree height
- Morris: O(1) - constant space

---

## Key Concepts Covered

### 1. **Tree Traversal Techniques**

- **Level Order Traversal (BFS):** Using queue for breadth-first search
- **Zigzag Traversal:** Alternating direction with reverse/deque
- **Bottom-up Traversal:** Reverse the result of normal level order
- **Inorder Traversal:** Left-root-right pattern with multiple approaches

### 2. **Tree Properties and Validation**

- **Symmetric Tree:** Mirror image validation
- **Tree Height/Depth:** Maximum path length calculation
- **Tree Comparison:** Structure and value matching

### 3. **Data Structure Usage**

- **Queue:** For BFS and level order traversals
- **Stack:** For DFS and iterative inorder traversal
- **Deque:** For efficient zigzag traversal
- **Vector:** For result storage and level tracking

### 4. **Algorithm Optimization**

- **Single Traversal Solutions:** Multiple calculations in one pass
- **Space Optimization:** Morris traversal for constant space
- **Time Optimization:** Efficient data structure selection

## Common Patterns

1. **Tree Traversal Patterns:**

   - Recursive vs Iterative approaches
   - BFS vs DFS selection
   - Level tracking techniques

2. **Optimization Patterns:**

   - Single traversal for multiple calculations
   - Efficient data structure usage
   - Memory management considerations

3. **Problem-Specific Techniques:**
   - Mirror checking for symmetric trees
   - Level boundary tracking for BFS
   - Direction alternation for zigzag traversal
   - Result reversal for bottom-up traversal

## Time and Space Complexity Summary

| Problem               | Time Complexity | Space Complexity | Approach                   |
| --------------------- | --------------- | ---------------- | -------------------------- |
| Symmetric Tree        | O(N)            | O(H) / O(W)      | Recursive/Iterative        |
| Level Order           | O(N)            | O(W)             | Queue-based BFS            |
| Zigzag Level Order    | O(N)            | O(W)             | Queue with reverse/Deque   |
| Maximum Depth         | O(N)            | O(H) / O(W)      | Recursive/BFS/DFS          |
| Bottom-up Level Order | O(N)            | O(W)             | Queue with reverse/Stack   |
| Inorder Traversal     | O(N)            | O(H) / O(1)      | Recursive/Iterative/Morris |

## Practice Problems

- [Leetcode 105 - Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [Leetcode 106 - Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
- [Leetcode 108 - Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [Leetcode 109 - Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
- [Leetcode 110 - Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

## Notes

- **Traversal Selection:** Choose based on problem requirements
- **Memory Management:** Consider space complexity for large trees
- **Optimization:** Use Morris traversal for constant space inorder
- **Data Structures:** Queue for BFS, Stack for DFS, Deque for zigzag
- **Problem Analysis:** Understand traversal requirements before implementation
- **Edge Cases:** Handle null trees and single nodes properly

## Sample Usage

### Running Symmetric Tree:

```bash
g++ -o symmetric Leetcode_101.cpp
./symmetric
```

### Testing Level Order Traversal:

```bash
g++ -o level_order Leetcode_102.cpp
./level_order
```

### Testing Zigzag Traversal:

```bash
g++ -o zigzag Leetcode_103.cpp
./zigzag
```

### Testing Maximum Depth:

```bash
g++ -o max_depth Leetcode_104.cpp
./max_depth
```

### Testing Bottom-up Level Order:

```bash
g++ -o bottom_up Leetcode_107.cpp
./bottom_up
```

### Testing Inorder Traversal:

```bash
g++ -o inorder Leetcode_94.cpp
./inorder
```

## Next Steps

- Explore more advanced tree problems (AVL, Red-Black trees)
- Practice tree serialization/deserialization
- Study tree-based algorithms (Segment trees, Fenwick trees)
- Implement tree balancing algorithms
- Explore tree-based dynamic programming problems
- Practice tree construction from different traversals
- Study tree optimization techniques (threaded trees, etc.)
