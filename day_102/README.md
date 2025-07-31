# Day 102: Advanced Tree Traversal Techniques

## Overview

Day 102 focuses on advanced tree traversal techniques covering specialized view problems and traversal patterns. The day includes top view, bottom view, diagonal traversal, and finding bottom-left tree value problems. Each problem demonstrates different approaches including BFS, DFS, and optimized solutions for complex tree scenarios.

## Problems Covered

### 1. Top View of Binary Tree

**File:** [Top_view_of_tree.cpp](./Top_view_of_tree.cpp)

**Problem Link:** [GFG - Top View of Binary Tree](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

**Problem:** Given a binary tree, return an array where elements represent the top view of the binary tree from left to right. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

**Key Points:**

- Return nodes from leftmost to rightmost
- If two nodes are at the same position, consider the leftmost node only
- Nodes outside the shadow of the tree are considered

**Example:**

```
Input: root[] = [1, 2, 3]
Output: [2, 1, 3]

Input: root[] = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
```

**Approaches Implemented:**

1. **BFS with Horizontal Distance Tracking (O(N)):**

   ```cpp
   class Solution {
   public:
       vector<int> topView(Node *root) {
           if (!root) return {};

           map<int, int> m;  // horizontal distance -> node value
           queue<pair<Node*, int>> q;  // {node, horizontal distance}

           q.push({root, 0});

           while (!q.empty()) {
               Node* curr = q.front().first;
               int hd = q.front().second;
               q.pop();

               // Only insert the first time we encounter this HD
               if (m.find(hd) == m.end()) {
                   m[hd] = curr->data;
               }

               if (curr->left) q.push({curr->left, hd - 1});
               if (curr->right) q.push({curr->right, hd + 1});
           }

           // Collect answer from leftmost to rightmost
           vector<int> ans;
           for (auto &p : m) {
               ans.push_back(p.second);
           }
           return ans;
       }
   };
   ```

2. **DFS with Depth Tracking (O(N)):**

   ```cpp
   class SolutionDFS {
   public:
       void farMost(Node *root, int hd, int depth, map<int,pair<int,int>> &mp) {
           if (!root) return;

           // If HD not seen OR current node is at a shallower depth
           if (mp.find(hd) == mp.end() || depth < mp[hd].second) {
               mp[hd] = {root->data, depth};
           }

           farMost(root->left, hd - 1, depth + 1, mp);
           farMost(root->right, hd + 1, depth + 1, mp);
       }

       vector<int> topView(Node *root) {
           if (!root) return {};

           map<int,pair<int,int>> mp; // hd -> {node, depth}
           farMost(root, 0, 0, mp);

           vector<int> ans;
           for (auto &p : mp) {
               ans.push_back(p.second.first);
           }
           return ans;
       }
   };
   ```

**Key Insight:** Track horizontal distance and only keep the first (topmost) node at each distance.

**Time Complexity:** O(N) - visit each node once
**Space Complexity:** O(W) - where W is the maximum width of the tree

---

### 2. Bottom View of Binary Tree

**File:** [Bottom_view_of_tree.cpp](./Bottom_view_of_tree.cpp)

**Problem Link:** [GFG - Bottom View of Binary Tree](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

**Problem:** Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

**Key Points:**

- If multiple bottom-most nodes exist for a horizontal distance, consider the later one in level order traversal
- Return nodes from leftmost to rightmost

**Example:**

```
Input: root[] = [1, 3, 2]
Output: [3, 1, 2]

Input: root[] = [10, 20, 30, 40, 60]
Output: [40, 20, 60, 30]
```

**Approach Implemented:**

```cpp
class Solution {
public:
    vector<int> bottomView(Node *root) {
        if (!root) return {};

        map<int, int> m;  // horizontal distance -> node value
        queue<pair<Node*, int>> q;  // {node, horizontal distance}

        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Always update with the latest node at this HD
            m[hd] = curr->data;

            if (curr->left) q.push({curr->left, hd - 1});
            if (curr->right) q.push({curr->right, hd + 1});
        }

        vector<int> ans;
        for (auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
```

**Key Insight:** Always update the map with the latest node at each horizontal distance (bottommost node).

**Time Complexity:** O(N)
**Space Complexity:** O(W)

---

### 3. Diagonal Traversal of Binary Tree

**File:** [Diagonal_traversal_binary_tree.cpp](./Diagonal_traversal_binary_tree.cpp)

**Problem Link:** [GFG - Diagonal Traversal of Binary Tree](https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1)

**Problem:** Given a Binary Tree, print the diagonal traversal of the binary tree. Consider lines of slope -1 passing between nodes.

**Key Points:**

- Process all nodes in the same diagonal together
- Use queue to store left children for next diagonal
- Traverse right children immediately

**Example:**

```
Input:
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output: [8, 10, 14, 3, 6, 7, 13, 1, 4]
```

**Approach Implemented:**

```cpp
class Solution {
public:
    vector<int> diagonal(Node *root) {
        if (!root) return {};

        vector<int> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            // Process all nodes in current diagonal
            while (temp) {
                ans.push_back(temp->data);

                // Store left child for next diagonal
                if (temp->left) q.push(temp->left);

                // Move to right child (same diagonal)
                temp = temp->right;
            }
        }
        return ans;
    }
};
```

**Key Insight:** Use queue to store left children and process right children immediately for the same diagonal.

**Time Complexity:** O(N)
**Space Complexity:** O(W)

---

### 4. Find Bottom Left Tree Value (Leetcode 513)

**File:** [Leetcode_513.cpp](./Leetcode_513.cpp)

**Problem Link:** [Leetcode 513 - Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/)

**Problem:** Given the root of a binary tree, return the leftmost value in the last row of the tree.

**Example:**

```
Input: root = [2,1,3]
Output: 1

Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

**Approaches Implemented:**

1. **BFS Solution (O(N)):**

   ```cpp
   class SolutionBFS {
   public:
       int findBottomLeftValue(TreeNode *root) {
           if (!root) return -1;

           int ans = -1;
           queue<TreeNode*> q;
           q.push(root);

           while (!q.empty()) {
               int s = q.size();
               ans = q.front()->val;  // First node at current level

               while (s--) {
                   TreeNode* temp = q.front();
                   q.pop();

                   if (temp->left) q.push(temp->left);
                   if (temp->right) q.push(temp->right);
               }
           }
           return ans;
       }
   };
   ```

2. **DFS Solution (O(N)):**

   ```cpp
   class SolutionDFS {
   private:
       int ans, maxDepth;

       void dfs(TreeNode* node, int depth) {
           if (!node) return;

           // If we reach a deeper level for the first time
           if (depth > maxDepth) {
               maxDepth = depth;
               ans = node->val;
           }

           // Go left first to ensure leftmost is found first
           dfs(node->left, depth + 1);
           dfs(node->right, depth + 1);
       }

   public:
       int findBottomLeftValue(TreeNode* root) {
           maxDepth = -1;
           dfs(root, 0);
           return ans;
       }
   };
   ```

**Key Insight:** Track the first node encountered at the deepest level.

**Time Complexity:** O(N)
**Space Complexity:**

- BFS: O(W) where W is maximum width
- DFS: O(H) where H is tree height

---

## Key Concepts Covered

### 1. **Specialized Tree View Techniques**

- **Top View:** Track horizontal distance, keep first node at each distance
- **Bottom View:** Track horizontal distance, keep last node at each distance
- **Diagonal Traversal:** Process nodes along diagonal lines with slope -1
- **Bottom Left Value:** Find leftmost node at deepest level

### 2. **Advanced Traversal Patterns**

- **Horizontal Distance Tracking:** Using coordinate system for view problems
- **Diagonal Grouping:** Processing nodes along diagonal lines
- **Level-based Processing:** BFS with level tracking
- **Depth-first Exploration:** DFS with depth tracking

### 3. **Data Structure Usage**

- **Map:** For organizing nodes by horizontal distance
- **Queue:** For BFS and level order traversals
- **Pair:** For storing node and coordinate information
- **Vector:** For storing results and intermediate data

### 4. **Algorithm Optimization**

- **Single Traversal Solutions:** Multiple calculations in one pass
- **Coordinate Tracking:** Efficient horizontal distance tracking
- **Memory Management:** Optimized space usage for large trees

## Common Patterns

1. **View Problems Patterns:**

   - **Top View:** First node at each horizontal distance
   - **Bottom View:** Last node at each horizontal distance
   - **Left/Right View:** First node at each level from respective side

2. **Diagonal Traversal Patterns:**

   - Use queue to store left children
   - Process right children immediately
   - Group nodes by diagonal lines

3. **Bottom Left Value Patterns:**
   - BFS: Take first node at deepest level
   - DFS: Track deepest level with left-first traversal

## Time and Space Complexity Summary

| Problem            | Time Complexity | Space Complexity | Approach                     |
| ------------------ | --------------- | ---------------- | ---------------------------- |
| Top View           | O(N)            | O(W)             | BFS with horizontal distance |
| Bottom View        | O(N)            | O(W)             | BFS with horizontal distance |
| Diagonal Traversal | O(N)            | O(W)             | BFS with diagonal grouping   |
| Bottom Left Value  | O(N)            | O(W) / O(H)      | BFS/DFS with level tracking  |

## Practice Problems

- [Leetcode 199 - Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [Leetcode 314 - Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
- [Leetcode 987 - Vertical Order Traversal of Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-binary-tree/)
- [Leetcode 545 - Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/)
- [Leetcode 366 - Find Leaves of Binary Tree](https://leetcode.com/problems/find-leaves-of-binary-tree/)

## Notes

- **Horizontal Distance:** Key concept for view problems
- **Coordinate System:** Essential for understanding tree views
- **Level Order Traversal:** Foundation for many tree problems
- **Memory Management:** Consider space complexity for large trees
- **Edge Cases:** Handle null trees, single nodes, and skewed structures
- **Traversal Order:** Important for maintaining correct output order

## Sample Usage

### Running Top View:

```bash
g++ -o top_view Top_view_of_tree.cpp
./top_view
```

### Testing Bottom View:

```bash
g++ -o bottom_view Bottom_view_of_tree.cpp
./bottom_view
```

### Testing Diagonal Traversal:

```bash
g++ -o diagonal Diagonal_traversal_binary_tree.cpp
./diagonal
```

### Testing Bottom Left Value:

```bash
g++ -o bottom_left Leetcode_513.cpp
./bottom_left
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

1. **Horizontal Distance Concept:** Fundamental for view problems
2. **Traversal Order:** Critical for maintaining correct output
3. **Data Structure Choice:** Map for coordinate tracking, Queue for BFS
4. **Edge Case Handling:** Important for robust solutions
5. **Space-Time Trade-offs:** Consider both complexity aspects
6. **Pattern Recognition:** Similar problems often have similar solutions
7. **Optimization Techniques:** Single traversal, coordinate tracking
8. **Implementation Details:** Careful attention to traversal order and data structures
