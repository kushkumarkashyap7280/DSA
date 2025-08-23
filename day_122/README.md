# Day 122: Binary Tree and Heap Problems - Properties and Applications

## Overview

Day 122 focuses on binary tree properties, heap operations, and their practical applications. We tackle six key problems: checking if a binary tree is complete, verifying max-heap properties, merging two max heaps, finding minimum cost of connecting ropes, converting BST to max heap, and merging two binary trees. These problems demonstrate important concepts in tree traversal, property validation, efficient recursive solutions, and tree manipulation techniques.

## Problems Covered

### 1. Check Completeness of a Binary Tree (LeetCode 958)

**File:** [Leetcode_958.cpp](./Leetcode_958.cpp)

**Problem Link:** [LeetCode 958 - Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

**Problem:** Determine if a binary tree is complete. A complete binary tree is one where every level except possibly the last is completely filled, and all nodes in the last level are as far left as possible.

**Example:**

```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full, and all nodes in the last level are as far left as possible.
```

**Approaches Implemented:**

1. **Index-based Recursive Solution (O(N)):**

   ```cpp
   class Solution {
       bool solve(TreeNode* root, int index, int size) {
           if(!root) return true;
           if(index >= size) return false;
           return solve(root->left, index*2 + 1, size) &&
                  solve(root->right, index*2 + 2, size);
       }

       int sizeOfTree(TreeNode* root) {
           if(!root) return 0;
           return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
       }
   public:
       bool isCompleteTree(TreeNode* root) {
           if(!root) return true;
           int s = sizeOfTree(root);
           return solve(root, 0, s);
       }
   };
   ```

**Key Insights:**

- Use array index property: for node at index i, left child is at 2i+1, right child at 2i+2
- Complete tree must have consecutive indices from 0 to size-1
- No gaps allowed in node indices

**Time Complexity:** O(N)
**Space Complexity:** O(H) where H is tree height

---

### 2. Is Binary Tree Heap (GeeksForGeeks)

**File:** [is_binary_tree_is_heap.cpp](./is_binary_tree_is_heap.cpp)

**Problem Link:** [GeeksForGeeks - Is Binary Tree Heap](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)

**Problem:** Determine if a binary tree is a max-heap. A binary tree is a max-heap if it's complete and each node's value is greater than or equal to its children's values.

**Example:**

```
Input:
       97
     /    \
   46      37
  /  \    /  \
 12   3  7   31
/  \
6   9

Output: true
Explanation: Tree is complete and each parent >= children
```

**Approaches Implemented:**

1. **Combined Property Check Solution (O(N)):**

   ```cpp
   class Solution {
       bool solve(Node* root, int index, int size) {
           if(!root) return true;
           if(index >= size) return false;

           // Check max-heap property
           if(root->left && root->left->data > root->data) return false;
           if(root->right && root->right->data > root->data) return false;

           // Check completeness and recurse
           return solve(root->left, index*2 + 1, size) &&
                  solve(root->right, index*2 + 2, size);
       }

       int sizeOfTree(Node* root) {
           if(!root) return 0;
           return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
       }
   public:
       bool isHeap(Node* tree) {
           if(!tree) return true;
           int s = sizeOfTree(tree);
           return solve(tree, 0, s);
       }
   };
   ```

**Key Insights:**

- Combine completeness check with max-heap property verification
- Use single traversal for efficiency
- Parent value must be >= both children's values
- Tree must be complete (no gaps in nodes)

**Time Complexity:** O(N)
**Space Complexity:** O(H) where H is tree height

---

### 3. Merge Two Binary Max Heaps (GeeksForGeeks)

**File:** [Merge_max_heap.cpp](./Merge_max_heap.cpp)

**Problem Link:** [GeeksForGeeks - Merge Two Binary Max Heaps](https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1)

**Problem:** Given two binary max heaps as arrays, merge them to form a new max heap. The resulting heap should maintain the max-heap property where each parent node is greater than or equal to its children.

**Example:**

```
Input:
Heap1: [10, 5, 6, 2]  Heap2: [12, 7, 9]
         10                  12
        /  \                /  \
       5    6              7    9
      /
     2

Output: [12, 10, 9, 2, 5, 7, 6]
          12
         /  \
        10   9
       / \  / \
      2  5 7  6
```

**Approaches Implemented:**

1. **Bottom-up Heapify Solution (O(N log N)):**

```cpp
class Solution {
    void heapify(vector<int> &a, int i, int n) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && a[left] > a[largest]) largest = left;
        if (right < n && a[right] > a[largest]) largest = right;
        if (largest != i) {
            swap(a[largest], a[i]);
            heapify(a, largest, n);
        }
    }
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Step 1: Append second heap to first heap
        a.insert(a.end(), b.begin(), b.end());

        // Step 2: Build max heap using bottom-up heapify
        for (int i = (n + m) / 2 - 1; i >= 0; i--) {
            heapify(a, i, n + m);
        }
        return a;
    }
};
```

**Key Insights:**

- Efficient merging by first combining arrays
- Bottom-up heapify is more efficient than top-down
- Heapify ensures max-heap property recursively
- No need to process leaf nodes in bottom-up heapify
- In-place transformation saves space

**Time Complexity:** O(N log N) where N = n + m
**Space Complexity:** O(1) excluding output array

### 4. Minimum Cost of Ropes (GeeksForGeeks)

**File:** [min_cost_ropes.cpp](./min_cost_ropes.cpp)

**Problem Link:** [GeeksForGeeks - Minimum Cost of Ropes](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

**Problem:** Given an array of rope lengths, connect all ropes into a single rope with minimum total cost. The cost to connect two ropes is the sum of their lengths.

**Example:**

```
Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation:
1. Connect 2,3 → [4,5,6] (cost=5)
2. Connect 4,5 → [9,6] (cost=9)
3. Connect 9,6 → [15] (cost=15)
Total cost = 5 + 9 + 15 = 29
```

**Approaches Implemented:**

1. **Min Heap Solution (O(N log N)):**

```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {
        // Base case: if only one rope, no connections needed
        if(arr.size() == 1) return 0;

        // Create min heap for efficient access to shortest ropes
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

        int totalCost = 0;
        while(pq.size() > 1) {
            // Get and connect two shortest ropes
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int newLength = first + second;
            totalCost += newLength;

            pq.push(newLength);
        }
        return totalCost;
    }
};
```

**Key Insights:**

- Always connect shortest ropes first for minimum cost
- Min heap provides efficient access to shortest ropes
- Each connection creates new rope for future connections
- Process continues until only one rope remains
- Greedy approach works because smaller combinations early reduce overall cost

**Time Complexity:** O(N log N) for heap operations
**Space Complexity:** O(N) for priority queue storage

### 5. Convert BST to Special Max Heap (GeeksForGeeks)

**File:** [bst_to_max_heap.cpp](./bst_to_max_heap.cpp)

**Problem Link:** [GeeksForGeeks - BST to Max Heap](https://www.geeksforgeeks.org/problems/bst-to-max-heap/1)

**Problem:** Convert a Binary Search Tree into a Special Max Heap where all values in the left subtree of a node should be less than all values in its right subtree. Maintain this property for all nodes in the converted Max Heap.

**Example:**

```
Input:
        4
      /   \
     2     6
    / \   / \
   1   3 5   7

Output:
        7
      /   \
     3     6
    / \   / \
   1   2 4   5

Explanation:
1. BST property initially ensures: Left < Root < Right
2. After conversion:
   - Max heap property: Parent > Children
   - Special property: Left subtree < Right subtree
3. Postorder traversal: [1, 2, 3, 4, 5, 6, 7]
```

**Approaches Implemented:**

1. **Two-Pass Traversal Solution (O(N)):**

```cpp
class Solution {
    void inorderTraversal(Node* root, vector<int>& values) {
        if (!root) return;
        inorderTraversal(root->left, values);
        values.push_back(root->data);
        inorderTraversal(root->right, values);
    }

    void rebuildTreePostorder(Node* root, const vector<int>& values, int& index) {
        if (!root) return;
        rebuildTreePostorder(root->left, values, index);
        rebuildTreePostorder(root->right, values, index);
        root->data = values[index++];
    }

public:
    void convertToMaxHeapUtil(Node* root) {
        if (!root) return;
        vector<int> sortedValues;
        inorderTraversal(root, sortedValues);
        int index = 0;
        rebuildTreePostorder(root, sortedValues, index);
    }
};
```

**Key Insights:**

- Inorder traversal of BST gives sorted array
- Postorder replacement ensures max heap property
- Original tree structure is preserved
- Only node values are modified
- Special property maintained by ordering
- No need to change tree connections

**Time Complexity:** O(N) for both traversals
**Space Complexity:** O(N) for storing values

### 6. Merge Two Binary Trees (LeetCode 617)

**File:** [Leetcode_617.cpp](./Leetcode_617.cpp)

**Problem Link:** [LeetCode 617 - Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)

**Problem:** Merge two binary trees. If two nodes overlap, sum their values; otherwise, use the existing node. The merging process starts from the root nodes of both trees.

**Example:**

```
Input:
Tree 1:     Tree 2:      Result:
   1          2            3
  / \        / \          / \
 3   2      1   3        4   5
/            \            \
5             4            9

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4]
Output: [3,4,5,5,4]
```

**Approaches Implemented:**

1. **Recursive Merge Solution (O(N)):**

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base cases: if either tree is empty
        if(!root1 && !root2) return nullptr;
        if(!root1 && root2) return root2;
        if(root1 && !root2) return root1;

        // Merge current nodes and recurse
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
```

**Key Insights:**

- Use root1 as the merged tree to save space
- Handle null nodes appropriately at each step
- Process overlapping nodes by summing values
- Preserve structure from non-null tree when one tree is empty

**Time Complexity:** O(N), where N is min(n1, n2), n1 and n2 are sizes of input trees
**Space Complexity:** O(H), where H is min(h1, h2), h1 and h2 are heights of input trees

## Key Concepts Covered

### 1. **Tree Property Validation and Transformation**

- Complete Binary Tree properties
- Max-heap properties
- Index-based node position verification
- Tree merging and modification techniques
- Structure preservation during transformations

### 2. **Tree Traversal Techniques**

- Recursive DFS with position tracking
- Level-aware traversal
- Size calculation
- Simultaneous traversal of multiple trees
- Coordinated tree processing

### 3. **Problem-Solving Patterns**

- Combined property verification
- Index-based position validation
- Efficient single-pass solutions
- Tree transformation techniques
- Structural merge operations

## Common Patterns

1. **Tree Validation Patterns:**

   - Node indexing in complete trees
   - Parent-child relationship checks
   - Completeness verification
   - Value-based property validation
   - Structural integrity checks

2. **Optimization Patterns:**

   - Single traversal for multiple properties
   - Early termination on failure
   - Efficient space usage
   - In-place modifications
   - Reuse of existing nodes

3. **Implementation Techniques:**
   - Index calculation for node positions
   - Size-based validation
   - Recursive property checking
   - Tree merging strategies
   - Null node handling
   - Structure modification

## Time and Space Complexity Summary

| Problem             | Time Complexity | Space Complexity | Approach            |
| ------------------- | --------------- | ---------------- | ------------------- |
| Check Complete Tree | O(N)            | O(H)             | Index-based DFS     |
| Is Binary Tree Heap | O(N)            | O(H)             | Combined Properties |
| Merge Max Heaps     | O(N log N)      | O(1)             | Bottom-up Heapify   |
| Min Cost Ropes      | O(N log N)      | O(N)             | Min Heap Solution   |
| BST to Max Heap     | O(N)            | O(N)             | Two-Pass Traversal  |
| Merge Two Trees     | O(min(N1,N2))   | O(min(H1,H2))    | Recursive Merge     |

Where:

- N = number of nodes in tree
- H = height of tree (log N for complete tree, N for skewed tree)

## Practice Problems

1. [LeetCode 1492 - The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/)
2. [LeetCode 230 - Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
3. [GeeksForGeeks - Minimum Cost of ropes](https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)
4. [LeetCode 703 - Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Notes

- Always check both structure (completeness) and value properties
- Consider edge cases: empty tree, single node, full tree
- Use efficient index calculations for position validation
- Combine property checks when possible for efficiency
- Handle null nodes appropriately
- Consider both recursive and iterative approaches

## Sample Usage

```bash
# Compile and run completeness check
g++ -o complete Leetcode_958.cpp
./complete

# Compile and run heap verification
g++ -o heap is_binary_tree_is_heap.cpp
./heap

# Compile and run tree merge
g++ -o merge Leetcode_617.cpp
./merge
```

## Next Steps

1. Study more advanced heap variants:

   - Fibonacci Heap
   - Binomial Heap
   - Leftist Heap

2. Explore applications:

   - Priority Queue implementations
   - Heap Sort variations
   - Graph algorithms using heaps

3. Practice related concepts:
   - Self-balancing trees
   - Advanced tree properties
   - Tree-based optimization problems
