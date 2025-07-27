# Day 098: Binary Tree Fundamentals and Advanced Problems

## Overview

Day 098 focuses on binary tree fundamentals, including tree construction, traversal methods, and solving complex tree-related problems. The day covers both basic implementations and advanced algorithmic techniques for binary trees.

## Problems Covered

### 1. Binary Tree Implementation

**File:** [Binary_Tree.cpp](./Binary_Tree.cpp)

**Description:** Comprehensive binary tree implementation with multiple construction and traversal methods.

**Features:**

- **Tree Construction:**
  - Recursive tree construction
  - Iterative tree construction using level order approach
- **Tree Traversal Methods:**
  - Recursive: Inorder, Preorder, Postorder
  - Iterative: Inorder, Preorder, Postorder (using stacks)
- **Utility Functions:**
  - Tree height calculation
  - Node counting
  - Balance checking
- **Tree Visualization:**
  - Level order printing with proper formatting

**Key Concepts:**

- Stack-based iterative traversal
- Queue-based level order construction
- Memory management in tree operations
- Time/Space complexity analysis

**Time Complexity:**

- Construction: O(n)
- Traversal: O(n)
- Height calculation: O(n)

**Space Complexity:**

- Recursive: O(h) where h is tree height
- Iterative: O(w) where w is maximum width

---

### 2. Count Leaves in Binary Tree

**File:** [Count_leaves_in_Binary_tree.cpp](./Count_leaves_in_Binary_tree.cpp)

**Problem Link:** [GFG - Count Leaves in Binary Tree](https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1)

**Problem:** Given a Binary Tree of size n, count the number of leaf nodes in it.

**Example:**

```
Input:
    1
   / \
  2   3
 / \
4   5

Output: 3
Explanation: Three leaves are 4, 5 and 3.
```

**Approaches Implemented:**

1. **Recursive Approach:**

   ```cpp
   int countLeaves(Node* root) {
       if (!root) return 0;
       if (!root->left && !root->right) return 1;
       return countLeaves(root->left) + countLeaves(root->right);
   }
   ```

2. **Alternative Recursive:**

   - Explicit counting with conditional checks

3. **Iterative Approach:**
   - Level order traversal with leaf detection

**Time Complexity:** O(n) - Visit each node once
**Space Complexity:**

- Recursive: O(h) - Recursion stack height
- Iterative: O(w) - Queue size for level order

---

### 3. Count Complete Tree Nodes (Leetcode 222)

**File:** [Leetcode_222.cpp](./Leetcode_222.cpp)

**Problem Link:** [Leetcode 222 - Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/)

**Problem:** Given the root of a complete binary tree, return the number of nodes in the tree. Design an algorithm that runs in less than O(n) time complexity.

**Example:**

```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Key Insight:** Complete binary trees have special properties that allow for optimization beyond simple traversal.

**Approach:**

- **Simple Recursive:** O(n) - Works for any binary tree
- **Optimized for Complete Trees:** O(log²n) - Leverages complete tree properties
- **Binary Search Approach:** O(log²n) - Most efficient for complete trees

**Complete Binary Tree Properties:**

- Every level except possibly the last is completely filled
- All nodes in the last level are as far left as possible
- Can have between 1 and 2^h nodes at the last level

**Time Complexity:** O(log²n) for optimized approaches
**Space Complexity:** O(log n) - Recursion depth

---

### 4. Maximum Median Sum of Subsequences of Size 3 (Leetcode 3627)

**File:** [Leetcode_3627.cpp](./Leetcode_3627.cpp)

**Problem Link:** [Leetcode 3627 - Maximum Median Sum](https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/)

**Problem:** Given an integer array nums with length divisible by 3, find the maximum possible sum of medians when selecting three elements at a time and removing them.

**Example:**

```
Input: nums = [2,1,3,2,1,3]
Output: 5
Explanation:
- First step: Select [3,1,3] → median = 3, remaining [2,1,2]
- Second step: Select [2,1,2] → median = 2, remaining []
- Sum = 3 + 2 = 5
```

**Approach:**

1. Sort the array in ascending order
2. Start from the second largest element
3. Take every second element from the end
4. Sum up the selected elements

**Algorithm:**

```cpp
long long maximumMedianSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0;
    int idx = n - 2;  // start from second largest
    for(int i = 0; i < n/3; i++) {
        ans += nums[idx];
        idx -= 2;
    }
    return ans;
}
```

**Time Complexity:** O(n log n) - Due to sorting
**Space Complexity:** O(1) - In-place sorting

---

## Key Concepts Covered

### 1. **Binary Tree Fundamentals**

- Tree node structure and memory management
- Tree construction techniques (recursive vs iterative)
- Traversal algorithms and their applications
- Tree properties and characteristics

### 2. **Complete Binary Trees**

- Special properties and optimizations
- Height-based calculations
- Perfect vs complete binary trees
- Efficient node counting algorithms

### 3. **Algorithm Optimization**

- Time complexity analysis for tree operations
- Space complexity considerations
- Trade-offs between different approaches
- Problem-specific optimizations

### 4. **Advanced Data Structure Techniques**

- Stack-based iterative traversal
- Queue-based level order operations
- Memory-efficient implementations
- Recursive vs iterative trade-offs

## Common Patterns

1. **Tree Traversal Patterns:**

   - DFS (Depth-First Search) with recursion
   - BFS (Breadth-First Search) with queues
   - Iterative traversal with stacks

2. **Complete Tree Optimization:**

   - Height calculation for optimization
   - Binary search in tree structure
   - Mathematical properties utilization

3. **Problem-Specific Techniques:**
   - Greedy algorithms for optimization
   - Sorting and selection strategies
   - Mathematical insights for efficiency

## Practice Problems

- [Leetcode 104 - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [Leetcode 110 - Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)
- [Leetcode 226 - Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
- [Leetcode 543 - Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

## Notes

- **Tree Construction:** Choose between recursive and iterative based on requirements
- **Traversal Selection:** Consider space constraints when choosing traversal method
- **Complete Trees:** Always leverage special properties for optimization
- **Memory Management:** Be careful with memory allocation in tree operations
- **Problem Analysis:** Understand problem constraints before choosing approach

## Sample Usage

### Running Binary Tree Implementation:

```bash
g++ -o binary_tree Binary_Tree.cpp
./binary_tree
```

### Testing Count Leaves:

```bash
g++ -o count_leaves Count_leaves_in_Binary_tree.cpp
./count_leaves
```

### Testing Complete Tree Nodes:

```bash
g++ -o count_nodes Leetcode_222.cpp
./count_nodes
```

### Testing Median Sum:

```bash
g++ -o median_sum Leetcode_3627.cpp
./median_sum
```

## Next Steps

- Explore more advanced tree problems (AVL, Red-Black trees)
- Practice tree serialization/deserialization
- Study tree-based algorithms (Segment trees, Fenwick trees)
- Implement tree balancing algorithms
