# Day 104: Binary Tree Advanced Problems

## Overview

Day 104 focuses on advanced binary tree problems covering kth ancestor queries using binary lifting technique and maximum sum of non-adjacent nodes using dynamic programming. The day includes problems involving tree traversal optimization, dynamic programming on trees, and efficient query processing techniques.

## Problems Covered

### 1. Kth Ancestor of a Tree Node (Leetcode 1483)

**File:** [Leetcode_1483.cpp](./Leetcode_1483.cpp)

**Problem Link:** [LeetCode 1483 - Kth Ancestor of a Tree Node](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)

**Problem:** You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

**Key Points:**

- Implement TreeAncestor class with constructor and getKthAncestor method
- Return -1 if kth ancestor doesn't exist
- Handle large number of queries efficiently
- Use binary lifting technique for optimal performance

**Example:**

```
Input: ["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output: [null, 1, 0, -1]

Explanation:
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
```

**Approach Implemented:**

```cpp
class TreeAncestor {
  int n;
  int LOG;
  vector<vector<int>> p;

public:
  TreeAncestor(int n, vector<int>& parent) {
     this->n = n;
     LOG = 1;
     while((1<<LOG) <= n) LOG++;
     p.assign(n, vector<int>(LOG, -1));

     // Initialize first level (2^0 ancestors)
     for(int i = 0; i < n; i++) {
         p[i][0] = parent[i];
     }

     // Build binary lifting table
     for(int j = 1; j < LOG; j++) {
         for(int i = 0; i < n; i++) {
             int prev = p[i][j-1];
             if(prev != -1) {
                 p[i][j] = p[prev][j-1];
             }
         }
     }
  }

  int getKthAncestor(int node, int k) {
     for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = p[node][j];
            if (node == -1) return -1;
        }
     }
     return node;
  }
};
```

**Key Insight:** Use binary lifting to precompute 2^j ancestors for each node, then decompose k into powers of 2.

**Time Complexity:** O(n log n) for preprocessing, O(log n) per query
**Space Complexity:** O(n log n)

---

### 2. Maximum Sum of Non-adjacent Nodes

**File:** [Maximum_sum_of_non_adjacents_nodes.cpp](./Maximum_sum_of_non_adjacents_nodes.cpp)

**Problem Link:** [GeeksForGeeks - Maximum Sum of Non-adjacent Nodes](https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)

**Problem:** Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected.

**Key Points:**

- No two selected nodes can be directly connected (parent-child relationship)
- Find maximum sum of non-adjacent nodes
- Use dynamic programming approach
- Consider both including and excluding current node

**Example:**

```
Input: root[] = [11, 1, 2]
Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]
Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6.
```

**Approach Implemented:**

```cpp
class Solution {
  pair<int,int> solve(Node* root) {
      if(!root) return {0,0};

      pair<int,int> left = solve(root->left);
      pair<int,int> right = solve(root->right);

      pair<int,int> ans;

      // Include current node + exclude children
      ans.first = root->data + left.second + right.second;

      // Exclude current node + include best of children
      ans.second = max(left.first, left.second) + max(right.first, right.second);

      return ans;
  }

public:
  int getMaxSum(Node *root) {
    if(!root) return 0;

    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
  }
};
```

**Key Insight:** For each node, we have two choices: include the current node (and exclude its children) or exclude the current node (and take the best of its children).

**Time Complexity:** O(n) - visit each node once
**Space Complexity:** O(h) - recursion stack depth

---

## Key Concepts Covered

### 1. **Binary Lifting Technique**

- **Purpose:** Efficiently find kth ancestor in O(log n) time
- **Preprocessing:** Build table of 2^j ancestors for each node
- **Query:** Decompose k into powers of 2 and jump accordingly
- **Applications:** Tree queries, LCA problems, range queries

### 2. **Dynamic Programming on Trees**

- **Bottom-up Approach:** Solve subproblems from leaves to root
- **State Definition:** Use pairs to track include/exclude decisions
- **Optimal Substructure:** Solution depends on optimal solutions of subtrees
- **Applications:** Maximum independent set, tree coloring, path problems

### 3. **Tree Traversal Optimization**

- **Binary Lifting:** Precompute ancestors for efficient queries
- **State Tracking:** Maintain multiple states during traversal
- **Memory Management:** Efficient use of space for large trees
- **Query Processing:** Handle multiple queries efficiently

### 4. **Data Structure Usage**

- **Vector of Vectors:** For binary lifting table
- **Pairs:** For dynamic programming states
- **Recursion:** For tree traversal and DP
- **Bit Manipulation:** For efficient k decomposition

### 5. **Algorithm Optimization**

- **Preprocessing:** Build lookup tables for efficient queries
- **State Compression:** Use pairs to track multiple states
- **Early Termination:** Stop when no valid ancestor exists
- **Memory Efficiency:** Optimize space usage for large trees

## Common Patterns

1. **Binary Lifting Patterns:**

   - **Preprocessing:** Build 2^j ancestor table
   - **Query Processing:** Decompose k into powers of 2
   - **Jump Strategy:** Use bit manipulation for efficient jumps
   - **Edge Cases:** Handle cases where ancestor doesn't exist

2. **Tree DP Patterns:**

   - **Include/Exclude:** Two choices for each node
   - **State Tracking:** Use pairs to track multiple states
   - **Bottom-up:** Solve from leaves to root
   - **Optimal Substructure:** Combine optimal solutions of subtrees

3. **Tree Query Patterns:**
   - **Ancestor Queries:** Use binary lifting for efficiency
   - **Path Queries:** Combine multiple techniques
   - **Subtree Queries:** Use DFS with state tracking
   - **Range Queries:** Apply segment tree or similar structures

## Time and Space Complexity Summary

| Problem                  | Time Complexity | Space Complexity | Approach            |
| ------------------------ | --------------- | ---------------- | ------------------- |
| Kth Ancestor (1483)      | O(n log n)      | O(n log n)       | Binary lifting      |
| Maximum Non-adjacent Sum | O(n)            | O(h)             | Dynamic programming |

## Practice Problems

- [LeetCode 236 - Lowest Common Ancestor](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [LeetCode 124 - Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
- [LeetCode 337 - House Robber III](https://leetcode.com/problems/house-robber-iii/)
- [LeetCode 968 - Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/)
- [LeetCode 834 - Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/)

## Notes

- **Binary Lifting:** Powerful technique for tree queries
- **Tree DP:** Natural fit for optimization problems on trees
- **Memory Management:** Consider space complexity for large trees
- **Edge Cases:** Handle null trees, single nodes, and invalid queries
- **Query Optimization:** Preprocessing can significantly improve query performance
- **State Management:** Careful tracking of multiple states during traversal
- **Bit Manipulation:** Efficient way to decompose numbers into powers of 2

## Sample Usage

### Running Kth Ancestor:

```bash
g++ -o kth_ancestor Leetcode_1483.cpp
./kth_ancestor
```

### Testing Maximum Non-adjacent Sum:

```bash
g++ -o max_sum Maximum_sum_of_non_adjacents_nodes.cpp
./max_sum
```

## Next Steps

- Explore more advanced tree problems (Heavy-light decomposition)
- Practice tree-based dynamic programming problems
- Study tree optimization techniques (Centroid decomposition)
- Explore graph algorithms on trees
- Practice tree-based interview problems
- Study advanced tree traversal techniques (Euler tour, etc.)
- Explore tree-based data structures (Segment trees, Fenwick trees)
- Practice tree construction from different traversals
- Study tree balancing algorithms
- Explore tree-based range queries

## Key Takeaways

1. **Binary Lifting:** Essential technique for efficient tree queries
2. **Tree DP:** Powerful approach for optimization problems
3. **State Management:** Careful tracking of multiple states
4. **Preprocessing:** Can significantly improve query performance
5. **Bit Manipulation:** Efficient decomposition techniques
6. **Memory Optimization:** Important for large trees
7. **Query Patterns:** Different approaches for different query types
8. **Implementation Details:** Careful attention to traversal order and state updates

## Complexity Analysis

### Binary Lifting (Kth Ancestor)

- **Preprocessing Time:** O(n log n) - build table for each node and each power of 2
- **Query Time:** O(log n) - decompose k into powers of 2
- **Space:** O(n log n) - store 2^j ancestors for each node
- **Key Insight:** Trade space for time efficiency

### Dynamic Programming (Non-adjacent Sum)

- **Time:** O(n) - visit each node once
- **Space:** O(h) - recursion stack depth
- **Key Insight:** Two choices per node, optimal substructure
- **Strategy:** Include current node or exclude and take best of children

## Advanced Concepts

1. **Binary Lifting Applications:**

   - Lowest Common Ancestor (LCA)
   - Range queries on trees
   - Path queries
   - Tree decomposition

2. **Tree DP Applications:**

   - Maximum independent set
   - Tree coloring
   - Path optimization
   - Subtree problems

3. **Optimization Techniques:**
   - Heavy-light decomposition
   - Centroid decomposition
   - Euler tour technique
   - Link-cut trees

## Resources

- [Binary Lifting Tutorial](https://cp-algorithms.com/graph/lca_binary_lifting.html)
- [Tree Dynamic Programming](https://codeforces.com/blog/entry/20935)
- [Advanced Tree Techniques](https://codeforces.com/blog/entry/71568)
- [Tree Problems Collection](https://codeforces.com/blog/entry/20935)
