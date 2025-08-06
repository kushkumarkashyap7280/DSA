# Day 108: Binary Tree Problems and Morris Traversal

## Overview

Day 108 covers three important topics in binary tree manipulation and traversal techniques. The problems range from infection simulation in binary trees to advanced traversal algorithms and tree flattening. These problems demonstrate various approaches to tree manipulation, from BFS-based infection spread to in-place tree transformations.

## Problems Covered

### 1. Amount of Time for Binary Tree to Be Infected (Leetcode 2385)

**File:** [Leetcode_2385.cpp](./Leetcode_2385.cpp)

**Problem Link:** [LeetCode 2385 - Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)

**Problem:** You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start. Each minute, a node becomes infected if it is currently uninfected and adjacent to an infected node. Return the number of minutes needed for the entire tree to be infected.

### 2. Morris Traversal Implementation

**File:** [Morris_traversal.cpp](./Morris_traversal.cpp)

**Problem Link:** [GeeksforGeeks - Morris Traversal](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/)

**Problem:** Implement Morris traversal for binary trees to perform inorder and preorder traversals without using recursion or stack, achieving O(1) space complexity.

### 3. Flatten Binary Tree to Linked List (Leetcode 114)

**File:** [Leetcode_114.cpp](./Leetcode_114.cpp)

**Problem Link:** [LeetCode 114 - Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

**Problem:** Given the root of a binary tree, flatten the tree into a "linked list" where the right child pointer points to the next node and the left child pointer is always null, maintaining preorder traversal order.

## Problem Analysis

### Key Constraints

#### LeetCode 2385 (Infection Problem)

- Binary tree with unique node values
- Infection spreads to adjacent nodes (parent, left child, right child)
- Need to find minimum time to infect entire tree
- Infection starts from a specific node

#### Morris Traversal

- Must not use recursion or stack
- Must achieve O(1) space complexity
- Should work for both inorder and preorder traversals
- Tree structure should be restored after traversal

#### LeetCode 114 (Flatten Problem)

- Must flatten tree in-place (O(1) extra space)
- Maintain preorder traversal order
- Left pointers should be null in final structure
- Right pointers should form the linked list

## Solution Approaches

### 1. LeetCode 2385: BFS with Parent Mapping

#### Algorithm

1. **Build Parent Map**: Use BFS to create a map from each node to its parent
2. **Find Start Node**: Locate the node with the start value
3. **BFS Infection**: Use BFS from the start node to simulate infection spread
4. **Track Time**: Count minutes until all nodes are infected

#### Code Implementation

```cpp
int amountOfTime(TreeNode* root, int start) {
    if (!root) return 0;

    // Step 1: Map child to parent and find the target node
    map<TreeNode*, TreeNode*> cp;
    TreeNode* target = nullptr;
    cp[root] = nullptr;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        if (temp->val == start) target = temp;
        q.pop();

        if (temp->left) {
            cp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            cp[temp->right] = temp;
            q.push(temp->right);
        }
    }

    // Step 2: BFS from target to infect the tree
    map<TreeNode*, bool> isVisited;
    isVisited[target] = true;
    queue<TreeNode*> infected;
    infected.push(target);
    int time = 0;

    while (!infected.empty()) {
        int s = infected.size();
        bool spread = false;
        while (s--) {
            TreeNode* temp = infected.front();
            infected.pop();

            // Check left child
            if (temp->left && !isVisited[temp->left]) {
                infected.push(temp->left);
                isVisited[temp->left] = true;
                spread = true;
            }
            // Check right child
            if (temp->right && !isVisited[temp->right]) {
                infected.push(temp->right);
                isVisited[temp->right] = true;
                spread = true;
            }
            // Check parent
            if (cp[temp] && !isVisited[cp[temp]]) {
                infected.push(cp[temp]);
                isVisited[cp[temp]] = true;
                spread = true;
            }
        }
        if (spread) time++;
    }
    return time;
}
```

### 2. Morris Traversal: Threading Technique

#### Algorithm

1. **Inorder Traversal**: Left → Root → Right
2. **Preorder Traversal**: Root → Left → Right
3. **Threading**: Create temporary links to navigate without stack
4. **Restoration**: Remove threads during traversal

#### Code Implementation

```cpp
// Inorder Traversal
vector<int> inorder(TreeNode* root) {
    if(!root) return {};

    vector<int> ans;
    TreeNode* curr = root;
    while(curr) {
        if(curr->left) {
            // Find the inorder predecessor
            TreeNode* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if(pred->right == curr) {
                // Thread already exists, remove it and visit current node
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Create thread and move to left subtree
                pred->right = curr;
                curr = curr->left;
            }
        } else {
            // No left child, visit current node and move right
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}
```

### 3. LeetCode 114: Morris Traversal for Flattening

#### Algorithm

1. **Find Rightmost**: For each node with left child, find rightmost node in left subtree
2. **Connect Subtrees**: Connect rightmost node to right subtree
3. **Move Left to Right**: Move entire left subtree to right
4. **Set Left to Null**: Ensure left pointer is null

#### Code Implementation

```cpp
void flatten(TreeNode* root) {
    if (!root) return;

    TreeNode *curr = root;
    while(curr) {
        if(curr->left) {
            // Find the rightmost node in the left subtree
            TreeNode* prev = curr->left;
            while(prev->right) {
                prev = prev->right;
            }
            // Connect the rightmost node of left subtree to the right subtree
            prev->right = curr->right;
            // Move left subtree to right
            curr->right = curr->left;
            // Set left to null
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}
```

## Complexity Analysis

### LeetCode 2385

- **Time Complexity**: O(n) - Each node is visited a constant number of times
- **Space Complexity**: O(n) - For the parent map, visited map, and BFS queue

### Morris Traversal

- **Time Complexity**: O(n) - Each node is visited at most 3 times
- **Space Complexity**: O(1) - Only uses a constant amount of extra space

### LeetCode 114

- **Time Complexity**: O(n) - Each node is visited once
- **Space Complexity**: O(1) - In-place modification using Morris traversal approach

## Key Insights

### Infection Simulation (LeetCode 2385)

1. **Bidirectional Infection**: Infection can spread to parent, left child, and right child
2. **Parent Mapping**: Need to track parent-child relationships for upward spread
3. **Level-wise BFS**: Each level represents one minute of infection spread
4. **Visited Tracking**: Prevent re-infection of already infected nodes

### Morris Traversal

1. **Threading Technique**: Creates temporary links to navigate without stack
2. **In-place Traversal**: No additional data structures needed
3. **Tree Restoration**: Threads are created and removed during traversal
4. **Constant Space**: Achieves O(1) space complexity

### Tree Flattening (LeetCode 114)

1. **Preorder Order**: Maintains Root → Left → Right traversal order
2. **In-place Transformation**: No extra space required
3. **Right-skewed Result**: Final structure is a right-skewed linked list
4. **Morris Technique**: Uses threading for efficient in-place modification

## Test Cases

### LeetCode 2385 Test Cases

1. **Example 1**: `root = [1,5,3,null,4,10,6,9,2]`, `start = 3` → Output: `4`
2. **Example 2**: `root = [1]`, `start = 1` → Output: `0`
3. **Skewed Tree**: `root = [1,null,2,null,3,null,4]`, `start = 1` → Output: `3`
4. **Complete Tree**: `root = [1,2,3,4,5,6,7]`, `start = 5` → Output: `4`

### Morris Traversal Test Cases

1. **Simple Tree**: `[1,2,3,4,5,6,7]` → Inorder: `[4,2,5,1,6,3,7]`, Preorder: `[1,2,4,5,3,6,7]`
2. **Skewed Right**: `[1,null,2,null,3,null,4]` → Inorder: `[1,2,3,4]`, Preorder: `[1,2,3,4]`
3. **Skewed Left**: `[1,2,null,3,null,4]` → Inorder: `[4,3,2,1]`, Preorder: `[1,2,3,4]`

### LeetCode 114 Test Cases

1. **Example 1**: `[1,2,5,3,4,null,6]` → `[1,2,3,4,5,6]`
2. **Empty Tree**: `[]` → `[]`
3. **Single Node**: `[0]` → `[0]`
4. **Complete Tree**: `[1,2,3,4,5,6,7]` → `[1,2,4,5,3,6,7]`

## Implementation Details

### Helper Functions

All solutions include comprehensive helper functions:

- **Tree Building**: Create trees from level-order arrays
- **Memory Management**: Proper cleanup to prevent memory leaks
- **Output Formatting**: Clear visualization of results
- **Test Case Generation**: Multiple scenarios for thorough testing

### Memory Management

- **Dynamic Allocation**: Uses `new` for tree node creation
- **Proper Deletion**: Uses `delete` to free memory
- **Memory Safety**: Ensures no memory leaks in test cases

## Common Pitfalls

### LeetCode 2385

1. **Missing Parent Mapping**: Forgetting to track parent-child relationships
2. **Incorrect BFS**: Not handling bidirectional infection spread
3. **Time Calculation**: Wrong counting of infection minutes

### Morris Traversal

1. **Thread Restoration**: Forgetting to remove temporary threads
2. **Infinite Loops**: Not handling thread detection properly
3. **Tree Modification**: Permanently altering tree structure

### LeetCode 114

1. **Wrong Order**: Not maintaining preorder traversal order
2. **Extra Space**: Using additional data structures instead of in-place modification
3. **Memory Leaks**: Not properly managing tree transformations

## Related Problems

### Tree Traversal Problems

1. **[Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)** - Easy
2. **[Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)** - Easy
3. **[Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)** - Easy

### Tree Manipulation Problems

1. **[Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)** - Easy
2. **[Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)** - Medium
3. **[Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)** - Hard

### Advanced Tree Problems

1. **[Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)** - Hard
2. **[Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)** - Medium
3. **[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)** - Medium

## Practice Problems

### Recommended Next Steps

1. **Tree Traversal Variations**: Practice different traversal orders
2. **Tree Construction**: Build trees from various representations
3. **Tree Validation**: Check BST properties and balance
4. **Path Problems**: Find paths, sums, and ancestors

### Difficulty Progression

- **Easy**: Basic tree traversal and manipulation
- **Medium**: Complex tree algorithms and transformations
- **Hard**: Advanced tree problems with multiple constraints

## Code Execution

To run the solutions:

```bash
# LeetCode 2385
g++ Leetcode_2385.cpp -o leetcode_2385
./leetcode_2385

# Morris Traversal
g++ Morris_traversal.cpp -o morris_traversal
./morris_traversal

# LeetCode 114
g++ Leetcode_114.cpp -o leetcode_114
./leetcode_114
```

### Expected Output

#### LeetCode 2385

```
=== LeetCode 2385: Amount of Time for Binary Tree to Be Infected ===

Test Case 1:
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Expected: 4

=== Algorithm Analysis ===
Time Complexity: O(n) - Each node is visited a constant number of times
Space Complexity: O(n) - For the parent map, visited map, and BFS queue
```

#### Morris Traversal

```
=== Morris Traversal Implementation ===

Test Case 1: Simple Tree
Tree: [1,2,3,4,5,6,7]
Inorder: [4, 2, 5, 1, 6, 3, 7]
Preorder: [1, 2, 4, 5, 3, 6, 7]

=== Algorithm Analysis ===
Time Complexity: O(n) - Each node is visited at most 3 times
Space Complexity: O(1) - Only uses a constant amount of extra space
```

#### LeetCode 114

```
=== LeetCode 114: Flatten Binary Tree to Linked List ===

Test Case 1:
Input: [1,2,5,3,4,null,6]
Before flattening: [1, 2, 5, 3, 4, null, 6]
Flattened Tree: [1, 2, 3, 4, 5, 6]
Expected: [1, 2, 3, 4, 5, 6]

=== Algorithm Analysis ===
Time Complexity: O(n) - Each node is visited once
Space Complexity: O(1) - In-place modification using Morris traversal approach
```

## Summary

Day 108 covers three fundamental aspects of binary tree manipulation:

1. **Infection Simulation (LeetCode 2385)**: Demonstrates BFS with parent mapping to simulate bidirectional infection spread in trees. This problem tests understanding of tree traversal and graph-like properties of binary trees.

2. **Morris Traversal**: Introduces an advanced traversal technique that achieves O(1) space complexity by using temporary threading. This is crucial for memory-constrained environments and demonstrates creative problem-solving.

3. **Tree Flattening (LeetCode 114)**: Shows how to transform a binary tree into a linked list while maintaining traversal order. This problem combines tree manipulation with linked list concepts.

The key takeaways include:

- **Bidirectional Tree Operations**: Trees can be traversed in multiple directions
- **In-place Algorithms**: Many tree operations can be done without extra space
- **Threading Techniques**: Temporary links can enable efficient traversal
- **Memory Management**: Proper cleanup is essential for tree operations

These problems build a strong foundation for advanced tree algorithms and demonstrate the versatility of binary tree data structures.
