# Day 101: Advanced Binary Tree Traversal and Tree Properties

## Overview

Day 101 focuses on advanced binary tree problems covering specialized traversal techniques, tree boundary analysis, and complex tree algorithms. The day includes boundary traversal, right side view, and vertical order traversal problems. Each problem demonstrates different approaches including DFS, BFS, and optimized solutions for complex tree scenarios.

## Problems Covered

### 1. Boundary Traversal of Binary Tree

**File:** [Boundary_traversal.cpp](./Boundary_traversal.cpp)

**Problem Link:** [GFG - Boundary Traversal of Binary Tree](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

**Problem:** Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

1. **Left Boundary:** All nodes on the path from root to leftmost leaf (excluding leaves)
2. **Leaf Nodes:** All leaf nodes in left-to-right order
3. **Reverse Right Boundary:** All nodes on the path from rightmost leaf to root in reverse order

**Example:**

```
Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
```

**Approaches Implemented:**

1. **Three-Step Approach (O(N)):**

   ```cpp
   class Solution {
   public:
       // Left boundary traversal (excluding leaf nodes)
       void left(Node* root, vector<int> &v) {
           if(!root || (!root->left && !root->right)) return;
           v.push_back(root->data);
           if(root->left) left(root->left, v);
           else left(root->right, v);
       }

       // Leaf nodes traversal (inorder to get left-to-right order)
       void leafs(Node* root, vector<int> &v) {
           if(!root) return;
           if(!root->left && !root->right) {
               v.push_back(root->data);
               return;
           }
           leafs(root->left, v);
           leafs(root->right, v);
       }

       // Right boundary traversal (excluding leaf nodes, in reverse order)
       void right(Node* root, vector<int> &v) {
           if(!root || (!root->left && !root->right)) return;
           if(root->right) right(root->right, v);
           else right(root->left, v);
           v.push_back(root->data);
       }

       vector<int> boundaryTraversal(Node *root) {
           vector<int> v;
           if(!root) return v;
           v.push_back(root->data);
           if(!root->left && !root->right) return v;

           left(root->left, v);
           leafs(root, v);
           right(root->right, v);

           return v;
       }
   };
   ```

2. **Alternative Single Traversal Approach (O(N)):**
   ```cpp
   class SolutionAlternative {
   public:
       void boundaryTraversalUtil(Node* root, vector<int>& left, vector<int>& leaves, vector<int>& right, bool isLeft, bool isRight) {
           if(!root) return;

           if(isLeft) {
               left.push_back(root->data);
           }
           else if(isRight && !root->left && !root->right) {
               // Skip leaf nodes for right boundary
           }
           else if(isRight) {
               right.push_back(root->data);
           }
           else if(!root->left && !root->right) {
               leaves.push_back(root->data);
           }

           boundaryTraversalUtil(root->left, left, leaves, right, isLeft, false);
           boundaryTraversalUtil(root->right, left, leaves, right, false, isRight);
       }

       vector<int> boundaryTraversal(Node* root) {
           if(!root) return {};

           vector<int> left, leaves, right;
           left.push_back(root->data);

           boundaryTraversalUtil(root->left, left, leaves, right, true, false);
           boundaryTraversalUtil(root->right, left, leaves, right, false, true);

           reverse(right.begin(), right.end());

           vector<int> result = left;
           result.insert(result.end(), leaves.begin(), leaves.end());
           result.insert(result.end(), right.begin(), right.end());

           return result;
       }
   };
   ```

**Key Insight:** Boundary traversal requires three distinct steps: left boundary, leaves, and reverse right boundary.

**Time Complexity:** O(N) - visits each node once
**Space Complexity:** O(H) - where H is the height of the tree (due to recursion stack)

---

### 2. Binary Tree Right Side View (Leetcode 199)

**File:** [Leetcode_199.cpp](./Leetcode_199.cpp)

**Problem Link:** [Leetcode 199 - Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

**Problem:** Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

**Example:**

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

**Approaches Implemented:**

1. **BFS Solution (O(N)):**

   ```cpp
   class Solution {
   public:
       vector<int> rightSideView(TreeNode* root) {
           if(!root) return {};
           vector<int> ans;
           queue<TreeNode*> q;
           q.push(root);
           while(!q.empty()){
               ans.push_back(q.front()->val);
               int s = q.size();
               while(s){
                   TreeNode* temp = q.front();
                   q.pop();
                   if(temp->right) q.push(temp->right);
                   if(temp->left) q.push(temp->left);
                   s--;
               }
           }
           return ans;
       }
   };
   ```

2. **DFS Solution (O(N)):**
   ```cpp
   class SolutionDFS {
   public:
       void dfs(TreeNode* root, vector<int>& result, int depth) {
           if(!root) return;

           if(depth == result.size()) {
               result.push_back(root->val);
           }

           dfs(root->right, result, depth + 1);
           dfs(root->left, result, depth + 1);
       }

       vector<int> rightSideView(TreeNode* root) {
           vector<int> result;
           dfs(root, result, 0);
           return result;
       }
   };
   ```

**Key Insight:** Take the first node (rightmost) at each level in BFS, or use right-first DFS traversal.

**Time Complexity:** O(N)
**Space Complexity:**

- BFS: O(W) where W is maximum width
- DFS: O(H) where H is tree height

---

### 3. Vertical Order Traversal of Binary Tree (Leetcode 987)

**File:** [Leetcode_987.cpp](./Leetcode_987.cpp)

**Problem Link:** [Leetcode 987 - Vertical Order Traversal of Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

**Problem:** Given the root of a binary tree, calculate the vertical order traversal. For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.

**Example:**

```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
```

**Approaches Implemented:**

1. **DFS Approach (O(N log N)):**

   ```cpp
   class Solution {
   public:
       // DFS to find column boundaries
       void farMost(TreeNode* root, int &l, int &r, int &c) {
           if(!root) return;
           if(root->left) {
               c--;
               l = min(l, c);
               r = max(r, c);
               farMost(root->left, l, r, c);
               c++;
           }
           if(root->right) {
               c++;
               l = min(l, c);
               r = max(r, c);
               farMost(root->right, l, r, c);
               c--;
           }
       }

       // DFS to collect nodes by column
       void add(TreeNode* root, vector<vector<pair<int,int>>> &v, int &c, int row) {
           if(!root) return;
           v[c].push_back({row, root->val});

           if(root->left) {
               c--;
               add(root->left, v, c, row+1);
               c++;
           }
           if(root->right) {
               c++;
               add(root->right, v, c, row+1);
               c--;
           }
       }

       vector<int> verticalTraversal(TreeNode* root) {
           if(!root) return {};
           int l = 0, r = 0, c = 0;
           farMost(root, l, r, c);

           int size = abs(l) + r + 1;
           vector<vector<pair<int,int>>> temp(size);

           c = abs(l);
           add(root, temp, c, 0);

           vector<vector<int>> ans(size);
           for(int i = 0; i < size; i++) {
               sort(temp[i].begin(), temp[i].end(), comparePairs);
               for(int j = 0; j < temp[i].size(); j++) {
                   ans[i].push_back(temp[i][j].second);
               }
           }
           return ans;
       }
   };
   ```

2. **BFS Approach using Map (O(N log N)):**

   ```cpp
   class SolutionBFS {
   public:
       vector<vector<int>> verticalTraversal(TreeNode* root) {
           if(!root) return {};

           map<int, vector<pair<int,int>>> nodes;  // col -> {row, value}
           queue<pair<TreeNode*, pair<int,int>>> q;  // node, {col, row}

           q.push({root, {0, 0}});

           while(!q.empty()) {
               auto front = q.front();
               q.pop();

               TreeNode* node = front.first;
               int col = front.second.first;
               int row = front.second.second;

               nodes[col].push_back({row, node->val});

               if(node->left) q.push({node->left, {col-1, row+1}});
               if(node->right) q.push({node->right, {col+1, row+1}});
           }

           vector<vector<int>> ans;
           for(auto &it : nodes) {
               auto &vec = it.second;
               sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                   if(a.first != b.first) return a.first < b.first;
                   return a.second < b.second;
               });

               vector<int> col;
               for(auto &p : vec) col.push_back(p.second);
               ans.push_back(col);
           }

           return ans;
       }
   };
   ```

**Key Insight:** Use coordinate system (row, col) and sort nodes within each column by row and value.

**Time Complexity:** O(N log N) - due to sorting at each column
**Space Complexity:** O(N) - for storing all nodes in the map/vectors

---

## Key Concepts Covered

### 1. **Specialized Tree Traversal Techniques**

- **Boundary Traversal:** Three-step process (left boundary, leaves, reverse right boundary)
- **Right Side View:** Level-based approach with rightmost node selection
- **Vertical Order Traversal:** Coordinate-based traversal with sorting

### 2. **Advanced Tree Properties**

- **Boundary Analysis:** Identifying tree boundaries and leaf nodes
- **Coordinate System:** Using (row, col) coordinates for vertical traversal
- **Multi-level Sorting:** Sorting by multiple criteria (row, value)

### 3. **Data Structure Usage**

- **Map:** For organizing nodes by column in vertical traversal
- **Queue:** For BFS and level order traversals
- **Vector:** For storing boundary nodes and results
- **Pair:** For storing coordinate information

### 4. **Algorithm Optimization**

- **Single Traversal Solutions:** Multiple calculations in one pass
- **Coordinate Tracking:** Efficient boundary and column tracking
- **Sorting Optimization:** Custom comparators for multi-criteria sorting

## Common Patterns

1. **Boundary Traversal Patterns:**

   - Left boundary: Prefer left child, exclude leaves
   - Leaf collection: Inorder traversal for left-to-right order
   - Right boundary: Prefer right child, reverse order

2. **Right Side View Patterns:**

   - BFS: Take first node at each level
   - DFS: Right-first traversal with depth tracking

3. **Vertical Traversal Patterns:**
   - Coordinate system: (row, col) tracking
   - Column organization: Map-based grouping
   - Multi-level sorting: Row first, then value

## Time and Space Complexity Summary

| Problem            | Time Complexity | Space Complexity | Approach                      |
| ------------------ | --------------- | ---------------- | ----------------------------- |
| Boundary Traversal | O(N)            | O(H)             | Three-step DFS                |
| Right Side View    | O(N)            | O(W) / O(H)      | BFS/DFS                       |
| Vertical Traversal | O(N log N)      | O(N)             | DFS with sorting/BFS with map |

## Practice Problems

- [Leetcode 314 - Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
- [Leetcode 199 - Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [Leetcode 545 - Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/)
- [Leetcode 366 - Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/)
- [Leetcode 863 - All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

## Notes

- **Boundary Traversal:** Handle edge cases carefully (single node, skewed trees)
- **Right Side View:** Consider both BFS and DFS approaches
- **Vertical Traversal:** Coordinate system is key to understanding
- **Sorting Requirements:** Pay attention to sorting criteria in problems
- **Memory Management:** Consider space complexity for large trees
- **Edge Cases:** Handle null trees, single nodes, and skewed structures

## Sample Usage

### Running Boundary Traversal:

```bash
g++ -o boundary Boundary_traversal.cpp
./boundary
```

### Testing Right Side View:

```bash
g++ -o right_view Leetcode_199.cpp
./right_view
```

### Testing Vertical Traversal:

```bash
g++ -o vertical Leetcode_987.cpp
./vertical
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
