# Day 110: Binary Search Tree Operations and Linked List to BST Conversion

## Overview

Day 110 continues the Binary Search Tree journey with fundamental operations and advanced conversion techniques. The problems cover BST minimum/maximum value finding and converting sorted linked lists to height-balanced BSTs, demonstrating both basic BST properties and advanced construction algorithms.

## Problems Covered

### 1. Minimum Node in Binary Search Tree

**File:** [min_node_in_BST.cpp](./min_node_in_BST.cpp)

**Problem:** Find the minimum valued element in a given Binary Search Tree. This problem demonstrates the fundamental property of BSTs where the leftmost node contains the minimum value.

**Key Concepts:**
- BST Property: Left subtree contains smaller values
- Iterative approach: Keep going left until no left child exists
- Time Complexity: O(h) where h is height of tree
- Space Complexity: O(1)

**Implementation Highlights:**
- Efficient iterative solution using while loop
- Handles edge cases (empty tree)
- Also includes maximum value finding for completeness
- Comprehensive test cases with multiple BST structures

### 2. Convert Sorted List to Binary Search Tree (Leetcode 109)

**File:** [Leetcode_109.cpp](./Leetcode_109.cpp)

**Problem Link:** [LeetCode 109 - Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

**Problem:** Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

**Key Concepts:**
- Two-pointer technique (slow/fast) to find middle element
- Recursive divide-and-conquer approach
- Height-balanced BST construction
- Linked list manipulation and disconnection

**Algorithm Approach:**
1. Use slow-fast pointer technique to find middle node
2. Disconnect left half from middle node
3. Create root with middle node value
4. Recursively build left subtree from left half
5. Recursively build right subtree from right half

**Time Complexity:** O(n log n) where n is number of nodes
**Space Complexity:** O(log n) for recursion stack

## Code Structure and Implementation

### BST Minimum/Maximum Operations

```cpp
class Solution {
public:
    int minValue(Node* root) {
        if(!root) return -1;
        while(root->left) root = root->left;
        return root->data;
    }
    
    int maxValue(Node* root) {
        if(!root) return -1;
        while(root->right) root = root->right;
        return root->data;
    }
};
```

### Sorted List to BST Conversion

```cpp
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        // Find middle using two-pointer technique
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half
        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        if (head != slow)
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
```

## Key Learning Points

### BST Properties
- **Minimum Element**: Always the leftmost node
- **Maximum Element**: Always the rightmost node
- **Inorder Traversal**: Gives sorted sequence
- **Height-Balanced**: Ensures O(log n) operations

### Linked List to BST Conversion
- **Two-Pointer Technique**: Efficient way to find middle element
- **Recursive Construction**: Divide and conquer approach
- **Height Balance**: Choosing middle element as root ensures balance
- **Memory Management**: Proper disconnection prevents infinite recursion

### Algorithm Optimization
- **Iterative vs Recursive**: Iterative approach saves space for min/max finding
- **In-place Operations**: Modifying linked list structure during conversion
- **Edge Case Handling**: Empty lists, single nodes, etc.

## Test Cases and Examples

### Minimum Node Test Cases
1. **Balanced BST**: [5, 4, 6, 3, N, N, 7, 1] → Min: 1, Max: 7
2. **Left-skewed**: [10, 5, 20, 2] → Min: 2, Max: 20
3. **Right-skewed**: [10, N, 10, N, 11] → Min: 10, Max: 11
4. **Empty Tree**: [] → Min: -1, Max: -1

### Sorted List to BST Test Cases
1. **Standard Case**: [-10,-3,0,5,9] → Balanced BST with root 0
2. **Empty List**: [] → Empty BST (nullptr)
3. **Single Node**: [1] → Single node BST
4. **Two Nodes**: [1,2] → Root 2, left child 1

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Find Min/Max | O(h) | O(1) |
| List to BST | O(n log n) | O(log n) |
| BST Construction | O(n) | O(log n) |

Where:
- h = height of BST
- n = number of nodes
- Space complexity includes recursion stack

## Additional Resources

- [BST Properties and Operations](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
- [Two-Pointer Technique](https://www.geeksforgeeks.org/two-pointers-technique/)
- [Height-Balanced Trees](https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/)

## Files in This Directory

1. **min_node_in_BST.cpp** - Complete implementation with test cases
2. **Leetcode_109.cpp** - Sorted list to BST conversion with helper functions
3. **README.md** - This documentation file

---

**Day 110 Summary:** Successfully implemented BST fundamental operations and advanced conversion algorithms, demonstrating both basic BST properties and sophisticated tree construction techniques.
