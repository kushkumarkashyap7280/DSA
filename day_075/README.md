# Day 75: Linked List Advanced Problems

## Problem 1: Reverse Nodes in k-Group

**LeetCode 25**: [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

### Problem Description

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. If the number of nodes is not a multiple of k, the remaining nodes at the end should remain as is.

### Approach & Visualization

1. **Find (2k-1)th Node**: Use a helper to check if there are at least k nodes left to reverse. If not, leave the rest as is.
   - Visual: For k=3, you need to find the 5th node from the current start to ensure a full group exists.
2. **Reverse k Nodes**: Reverse the group of k nodes using pointer manipulation.
   - Visual: For [1,2,3,4,5], k=2, after first group: [2,1,3,4,5].
3. **Recursive/Iterative Linking**: After reversing, connect the last node of the reversed group to the result of the next group.
   - Visual: Each group is reversed and linked to the next processed group.

#### Example Walkthrough

- Input: [1,2,3,4,5,6,7,8], k=3
- Step 1: Reverse [1,2,3] → [3,2,1]
- Step 2: Reverse [4,5,6] → [6,5,4]
- Step 3: Remaining [7,8] (less than k), so keep as is
- Output: [3,2,1,6,5,4,7,8]

#### Key Points

- Only node links are changed, not values.
- Handles cases where the list size is not a multiple of k.
- Time Complexity: O(n), Space Complexity: O(1) (if done iteratively)

**Solution File:** [Leetcode_25.cpp](Leetcode_25.cpp)

---

## Problem 2: Linked List Cycle

**LeetCode 141**: [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

### Problem Description

Given the head of a linked list, determine if the linked list has a cycle in it.

### Approach & Visualization

- **Floyd’s Tortoise and Hare Algorithm**: Use two pointers (slow and fast). If there is a cycle, they will eventually meet.
- Visual: Slow moves 1 step, fast moves 2 steps. If fast ever equals slow, there is a cycle.
- Time Complexity: O(n), Space Complexity: O(1)

**Solution File:** [Leetcode_141.cpp](Leetcode_141.cpp)

---

## Problem 3: Linked List Cycle II

**LeetCode 142**: [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

### Problem Description

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

### Approach & Visualization

- **Floyd’s Tortoise and Hare Algorithm (Cycle Detection + Entry Point)**:
  1. Detect cycle as in 141.
  2. When slow and fast meet, start a new pointer from head; move both pointers one step at a time. The node where they meet is the cycle start.
- Visual: Meeting point math shows both pointers will meet at the cycle entry.
- Time Complexity: O(n), Space Complexity: O(1)

**Solution File:** [Leetcode_142.cpp](Leetcode_142.cpp)

---

## Visual Resources

- [LeetCode 25 - Visual Explanation (YouTube)](https://www.youtube.com/watch?v=Of0HPkk3JgI)
- [GeeksforGeeks - Reverse Nodes in k-Group](https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/)
- [LeetCode 141/142 - Cycle Detection Visual (YouTube)](https://www.youtube.com/watch?v=gBTe7lFR3vc)
