# Day 105: Array Patterns and Binary Tree Construction

## Overview

Day 105 focuses on array pattern recognition and binary tree construction problems. The day covers trionic array detection using pattern matching, and two fundamental binary tree construction problems using different traversal combinations. These problems test understanding of array manipulation, tree traversal properties, and recursive tree construction techniques.

## Problems Covered

### 1. Trionic Array I (Leetcode 3637)

**File:** [Leetcode_3637.cpp](./Leetcode_3637.cpp)

**Problem Link:** [LeetCode 3637 - Trionic Array I](https://leetcode.com/problems/trionic-array-i/)

**Problem:** You are given an integer array nums of length n. An array is trionic if there exist indices 0 < p < q < n − 1 such that:

- nums[0...p] is strictly increasing
- nums[p...q] is strictly decreasing
- nums[q...n − 1] is strictly increasing

Return true if nums is trionic, otherwise return false.

**Key Points:**

- Array must have at least 4 elements for trionic pattern
- Three distinct phases: increasing → decreasing → increasing
- Pattern must be strictly monotonic in each phase
- Efficient single-pass solution possible

**Example:**

```
Input: nums = [1,3,5,4,2,6]
Output: true
Explanation: Pick p = 2, q = 4:
nums[0...2] = [1, 3, 5] is strictly increasing
nums[2...4] = [5, 4, 2] is strictly decreasing
nums[4...5] = [2, 6] is strictly increasing

Input: nums = [2,1,3]
Output: false
Explanation: No way to pick p and q to form required three segments
```

**Approach Implemented:**

```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int s = nums.size();
        if (s < 4) return false; // need at least 4 for up-down-up

        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < s && nums[i] < nums[i+1]) i++;
        int p = i;

        // Phase 2: strictly decreasing
        while (i + 1 < s && nums[i] > nums[i+1]) i++;
        int q = i;

        // Phase 3: strictly increasing
        while (i + 1 < s && nums[i] < nums[i+1]) i++;

        return p > 0 && q > p && q < s-1 && i == s-1;
    }
};
```

**Key Insight:** Use three-phase pattern detection with single pass through array.

**Time Complexity:** O(n) - single traversal
**Space Complexity:** O(1) - constant extra space

---

### 2. Construct Binary Tree from Preorder and Inorder Traversal (Leetcode 105)

**File:** [Leetcode_105.cpp](./Leetcode_105.cpp)

**Problem Link:** [LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

**Problem:** Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

**Key Points:**

- First element of preorder is always the root
- Inorder gives left subtree and right subtree information
- Recursive construction using divide and conquer
- Handle edge cases (empty trees, single nodes)

**Example:**

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

**Approach Implemented:**

```cpp
class Solution {
    TreeNode* solve(vector<int>& preorder, int pl, int pr,
                    vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;

        int node = preorder[pl];
        TreeNode* temp = new TreeNode(node);

        // find root index in inorder
        int index = il;
        while (index <= ir && inorder[index] != node) index++;

        int leftSize = index - il; // number of nodes in left subtree

        // Left subtree:
        temp->left = solve(preorder, pl + 1, pl + leftSize,
                           inorder, il, index - 1);

        // Right subtree:
        temp->right = solve(preorder, pl + leftSize + 1, pr,
                            inorder, index + 1, ir);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
    }
};
```

**Key Insight:** Use preorder to identify root, inorder to determine subtree boundaries.

**Time Complexity:** O(n²) - linear search in inorder for each node
**Space Complexity:** O(n) - recursion stack and tree construction

---

### 3. Construct Binary Tree from Inorder and Postorder Traversal (Leetcode 106)

**File:** [Leetcode_106.cpp](./Leetcode_106.cpp)

**Problem Link:** [LeetCode 106 - Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

**Problem:** Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

**Key Points:**

- Last element of postorder is always the root
- Inorder gives left subtree and right subtree information
- Right subtree comes before left subtree in postorder
- Need to calculate left subtree size correctly

**Example:**

```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

**Approach Implemented:**

```cpp
class Solution {
    TreeNode* solve(vector<int>& inorder, int il, int ir,
                    vector<int>& postorder, int pl, int pr) {
        if (pl > pr || il > ir) return nullptr;

        int node = postorder[pr];  // root is last in postorder
        TreeNode* temp = new TreeNode(node);

        // find root index in inorder
        int index = il;
        while (index <= ir && inorder[index] != node) index++;

        int leftSize = index - il;

        // build left
        temp->left = solve(inorder, il, index - 1,
                           postorder, pl, pl + leftSize - 1);

        // build right
        temp->right = solve(inorder, index + 1, ir,
                            postorder, pl + leftSize, pr - 1);

        return temp;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};
```

**Key Insight:** Use postorder to identify root (last element), inorder to determine subtree boundaries.

**Time Complexity:** O(n²) - linear search in inorder for each node
**Space Complexity:** O(n) - recursion stack and tree construction

---

## Key Concepts Covered

### 1. **Array Pattern Recognition**

- **Three-Phase Pattern:** Identify increasing → decreasing → increasing pattern
- **Monotonic Sequences:** Strictly increasing/decreasing subarrays
- **Boundary Conditions:** Handle edge cases and minimum requirements
- **Single Pass Algorithm:** Efficient O(n) solution with constant space

### 2. **Tree Traversal Properties**

- **Preorder (Root-Left-Right):** Root comes first, useful for tree construction
- **Inorder (Left-Root-Right):** Gives sorted order for BST, subtree information
- **Postorder (Left-Right-Root):** Root comes last, useful for bottom-up construction
- **Traversal Combinations:** Different combinations provide different information

### 3. **Recursive Tree Construction**

- **Divide and Conquer:** Split problem into smaller subproblems
- **Root Identification:** Use traversal properties to identify root
- **Subtree Boundaries:** Use inorder to determine left/right subtree sizes
- **Base Cases:** Handle empty trees and single nodes

### 4. **Index Management**

- **Array Bounds:** Careful management of start and end indices
- **Subtree Sizing:** Calculate left subtree size for proper splitting
- **Recursive Calls:** Pass correct indices to recursive functions
- **Boundary Conditions:** Handle edge cases in index calculations

### 5. **Algorithm Optimization**

- **Hash Map Optimization:** Can reduce time complexity to O(n) using hash maps
- **Memory Management:** Efficient use of recursion stack
- **Early Termination:** Stop when no valid solution exists
- **Pattern Matching:** Efficient pattern detection algorithms

## Common Patterns

1. **Array Pattern Detection:**

   - **Multi-Phase Patterns:** Identify distinct phases in array
   - **Monotonic Sequences:** Detect strictly increasing/decreasing segments
   - **Boundary Validation:** Check pattern requirements and constraints
   - **Single Pass:** Process array in one traversal when possible

2. **Tree Construction Patterns:**

   - **Root-First Approach:** Use preorder for root identification
   - **Root-Last Approach:** Use postorder for root identification
   - **Subtree Splitting:** Use inorder for subtree boundary determination
   - **Recursive Construction:** Build tree from root to leaves

3. **Traversal Combination Patterns:**
   - **Preorder + Inorder:** Most common combination for tree construction
   - **Postorder + Inorder:** Alternative approach for tree construction
   - **Index Management:** Careful handling of array indices
   - **Subtree Calculation:** Proper calculation of subtree sizes

## Time and Space Complexity Summary

| Problem                   | Time Complexity | Space Complexity | Approach               |
| ------------------------- | --------------- | ---------------- | ---------------------- |
| Trionic Array I (3637)    | O(n)            | O(1)             | Pattern detection      |
| Preorder + Inorder (105)  | O(n²)           | O(n)             | Recursive construction |
| Postorder + Inorder (106) | O(n²)           | O(n)             | Recursive construction |

## Practice Problems

- [LeetCode 889 - Construct Binary Tree from Preorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)
- [LeetCode 1008 - Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)
- [LeetCode 297 - Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
- [LeetCode 449 - Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/)
- [LeetCode 331 - Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

## Notes

- **Pattern Recognition:** Important skill for array manipulation problems
- **Tree Traversal Properties:** Understanding traversal order is crucial
- **Recursive Construction:** Natural approach for tree building problems
- **Index Management:** Critical for correct tree construction
- **Optimization Opportunities:** Hash maps can improve performance
- **Edge Cases:** Handle empty trees, single nodes, and invalid inputs
- **Memory Management:** Consider recursion stack depth for large trees
- **Traversal Combinations:** Different combinations provide different information

## Sample Usage

### Running Trionic Array:

```bash
g++ -o trionic_array Leetcode_3637.cpp
./trionic_array
```

### Testing Tree Construction:

```bash
g++ -o tree_construction Leetcode_105.cpp
./tree_construction

g++ -o tree_construction_post Leetcode_106.cpp
./tree_construction_post
```

## Next Steps

- Explore more array pattern recognition problems
- Practice tree serialization and deserialization
- Study advanced tree construction techniques
- Explore binary search tree construction problems
- Practice tree traversal optimization
- Study tree-based dynamic programming
- Explore tree balancing algorithms
- Practice tree-based interview problems
- Study tree decomposition techniques
- Explore tree-based data structures

## Key Takeaways

1. **Pattern Recognition:** Essential skill for array manipulation
2. **Tree Traversal Properties:** Understanding order is crucial for construction
3. **Recursive Construction:** Natural approach for tree building
4. **Index Management:** Critical for correct implementation
5. **Optimization:** Hash maps can significantly improve performance
6. **Edge Cases:** Handle various boundary conditions
7. **Memory Efficiency:** Consider space complexity for large inputs
8. **Algorithm Design:** Choose appropriate approach based on problem constraints

## Complexity Analysis

### Trionic Array Detection

- **Time:** O(n) - single pass through array
- **Space:** O(1) - constant extra space
- **Key Insight:** Three-phase pattern detection with boundary validation
- **Strategy:** Identify increasing → decreasing → increasing pattern

### Tree Construction (Preorder + Inorder)

- **Time:** O(n²) - linear search in inorder for each node
- **Space:** O(n) - recursion stack and tree construction
- **Key Insight:** Use preorder for root, inorder for subtree boundaries
- **Strategy:** Recursive divide and conquer approach

### Tree Construction (Postorder + Inorder)

- **Time:** O(n²) - linear search in inorder for each node
- **Space:** O(n) - recursion stack and tree construction
- **Key Insight:** Use postorder for root (last element), inorder for subtree boundaries
- **Strategy:** Recursive construction with proper index management

## Advanced Concepts

1. **Pattern Recognition Applications:**

   - Array validation problems
   - Sequence analysis
   - Data validation
   - Pattern matching algorithms

2. **Tree Construction Applications:**

   - Expression tree construction
   - Syntax tree building
   - File system representation
   - Hierarchical data structures

3. **Optimization Techniques:**
   - Hash map usage for O(n) tree construction
   - Iterative tree construction
   - Memory-efficient implementations
   - Cache-friendly algorithms

## Resources

- [Tree Traversal Tutorial](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
- [Binary Tree Construction](https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/)
- [Array Pattern Recognition](https://leetcode.com/tag/array/)
- [Tree Problems Collection](https://leetcode.com/tag/tree/)

## Test Cases Summary

### Trionic Array Test Cases:

1. Valid trionic array: `[1,3,5,4,2,6]` → `true`
2. Invalid array: `[2,1,3]` → `false`
3. Too short array: `[1,2,3]` → `false`
4. Another valid array: `[1,2,3,2,1,2,3]` → `true`
5. All increasing: `[1,2,3,4,5]` → `false`
6. All decreasing: `[5,4,3,2,1]` → `false`

### Tree Construction Test Cases:

1. Example case with balanced tree
2. Single node tree
3. Left skewed tree
4. Right skewed tree
5. Balanced tree with multiple levels
6. Tree with only left child

## Implementation Notes

- **Error Handling:** Validate input arrays and handle edge cases
- **Memory Management:** Proper cleanup of dynamically allocated nodes
- **Index Validation:** Ensure indices are within bounds
- **Recursion Depth:** Consider stack overflow for very deep trees
- **Output Format:** Consistent tree representation for testing
- **Performance:** Consider optimization for large inputs
- **Readability:** Clear variable names and comments
- **Maintainability:** Modular code structure for easy modification
