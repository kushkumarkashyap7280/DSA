# Day 107: Linked List Node Deletion

## Overview

Day 107 focuses on a unique linked list problem that tests understanding of pointer manipulation and memory management. The problem involves deleting a node from a singly-linked list without having access to the head of the list, which requires a clever approach to work around this constraint.

## Problem Covered

### 1. Delete Node in a Linked List (Leetcode 237)

**File:** [Leetcode_237.cpp](./Leetcode_237.cpp)

**Problem Link:** [LeetCode 237 - Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

**Problem:** There is a singly-linked list head and we want to delete a node node in it. You are given the node to be deleted node. You will not be given access to the first node of head. All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

## Problem Analysis

### Key Constraints

- You don't have access to the head of the linked list
- You only have access to the node to be deleted
- The node to be deleted is guaranteed to not be the last node
- All values in the linked list are unique

### Challenge

The main challenge is that we cannot directly delete the current node because:

1. We don't have access to the previous node to update its `next` pointer
2. We cannot modify the previous node's pointer to skip the current node

## Solution Approach

### Algorithm

Since we can't access the previous node, we use a clever trick:

1. **Copy the value** from the next node to the current node
2. **Delete the next node** by updating the current node's `next` pointer
3. **Free memory** of the next node

This effectively removes the current node's value from the list while maintaining the structure.

### Code Implementation

```cpp
void deleteNode(ListNode* node) {
    // Copy the value from the next node
    node->val = node->next->val;

    // Store the next node to delete it
    ListNode* temp = node->next;

    // Update the current node's next pointer to skip the next node
    node->next = node->next->next;

    // Delete the next node (free memory)
    delete temp;
}
```

### Step-by-Step Explanation

1. **Copy Value**: `node->val = node->next->val`

   - Copy the value from the next node to the current node
   - This makes the current node appear to have the next node's value

2. **Store Reference**: `ListNode* temp = node->next`

   - Store a reference to the next node so we can delete it later

3. **Update Pointer**: `node->next = node->next->next`

   - Skip the next node by pointing directly to the node after it
   - This removes the next node from the list structure

4. **Free Memory**: `delete temp`
   - Properly deallocate the memory of the next node
   - Prevents memory leaks

## Complexity Analysis

### Time Complexity: O(1)

- **Constant time operation** - We only perform a few pointer operations
- No loops or recursive calls involved
- Independent of the size of the linked list

### Space Complexity: O(1)

- **Constant extra space** - We only use one additional pointer (`temp`)
- No additional data structures required
- Memory usage doesn't scale with input size

## Key Insights

### Why This Approach Works

1. **Value Replacement**: By copying the next node's value, we effectively replace the current node's value
2. **Structural Integrity**: By updating the `next` pointer, we maintain the list structure
3. **Memory Management**: Proper deletion prevents memory leaks

### Important Considerations

1. **Not the Last Node**: The constraint that the node is not the last node is crucial
   - If it were the last node, `node->next` would be NULL, causing a segmentation fault
2. **Unique Values**: The constraint that all values are unique ensures this approach works correctly
3. **Memory Safety**: Always free the deleted node to prevent memory leaks

## Test Cases

### Test Case 1: Original Example

- **Input**: `head = [4,5,1,9]`, `node = 5`
- **Output**: `[4,1,9]`
- **Explanation**: Delete node with value 5, list becomes 4 → 1 → 9

### Test Case 2: Second Example

- **Input**: `head = [4,5,1,9]`, `node = 1`
- **Output**: `[4,5,9]`
- **Explanation**: Delete node with value 1, list becomes 4 → 5 → 9

### Test Case 3: Middle Node

- **Input**: `head = [1,2,3,4]`, `node = 2`
- **Output**: `[1,3,4]`
- **Explanation**: Delete middle node with value 2

### Test Case 4: Second to Last Node

- **Input**: `head = [1,2,3,4,5]`, `node = 4`
- **Output**: `[1,2,3,5]`
- **Explanation**: Delete second to last node

### Test Case 5: Edge Case

- **Input**: `head = [1,2]`, `node = 1`
- **Output**: `[2]`
- **Explanation**: Delete first node in a two-element list

## Implementation Details

### Helper Functions

The solution includes several helper functions for testing:

1. **`createLinkedList(vector<int>& values)`**

   - Creates a linked list from an array of values
   - Returns pointer to the head of the created list

2. **`printLinkedList(ListNode* head)`**

   - Prints the linked list in a readable format
   - Shows the structure with arrows between nodes

3. **`findNode(ListNode* head, int value)`**

   - Finds and returns a node with the specified value
   - Used to locate the node to be deleted for testing

4. **`deleteLinkedList(ListNode* head)`**
   - Properly frees all memory allocated for the linked list
   - Prevents memory leaks during testing

### Memory Management

- **Dynamic Allocation**: Uses `new` to create nodes
- **Proper Deletion**: Uses `delete` to free memory
- **Memory Safety**: Ensures no memory leaks in test cases

## Common Pitfalls

### 1. Not Freeing Memory

```cpp
// WRONG - Memory leak
node->val = node->next->val;
node->next = node->next->next;
// Missing: delete temp;
```

### 2. Accessing NULL Pointer

```cpp
// WRONG - Will crash if node is last element
node->val = node->next->val; // node->next could be NULL
```

### 3. Incorrect Order of Operations

```cpp
// WRONG - Loses reference to next node
ListNode* temp = node->next;
node->next = node->next->next;
node->val = temp->val; // temp->val is now the wrong value
```

## Related Problems

### Similar Linked List Problems

1. **[Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)** - Easy
2. **[Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)** - Medium
3. **[Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)** - Easy
4. **[Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)** - Easy

### Advanced Linked List Problems

1. **[Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)** - Hard
2. **[Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)** - Medium
3. **[Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)** - Medium

## Practice Problems

### Recommended Next Steps

1. **Linked List Cycle Detection** - Learn about fast and slow pointer technique
2. **Merge Two Sorted Lists** - Practice merging operations
3. **Add Two Numbers** - Handle carry-over in linked lists
4. **Palindrome Linked List** - Use two-pointer technique

### Difficulty Progression

- **Easy**: Basic pointer manipulation
- **Medium**: Complex pointer operations and edge cases
- **Hard**: Advanced algorithms with linked lists

## Code Execution

To run the solution:

```bash
g++ Leetcode_237.cpp -o leetcode_237
./leetcode_237
```

### Expected Output

```
=== LeetCode 237: Delete Node in a Linked List ===

Test Case 1:
Original list: [4 -> 5 -> 1 -> 9]
After deleting node with value 5: [4 -> 1 -> 9]

Test Case 2:
Original list: [4 -> 5 -> 1 -> 9]
After deleting node with value 1: [4 -> 5 -> 9]

=== Algorithm Analysis ===
Time Complexity: O(1) - Constant time operation
Space Complexity: O(1) - Constant extra space

Key Insight: Since we can't access the previous node, we copy the next node's value
and then delete the next node. This effectively removes the current node's value.
```

## Summary

This problem demonstrates an elegant solution to a seemingly impossible constraint. By thinking creatively about what we can modify (the current node's value and next pointer), we can effectively delete a node without access to the previous node. This approach is both efficient and memory-safe, making it an excellent example of pointer manipulation in linked lists.

The key takeaway is that sometimes the best solution involves working around constraints rather than trying to overcome them directly. This problem is a perfect example of how understanding data structure limitations can lead to innovative solutions.
