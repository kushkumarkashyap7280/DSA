# Day 097: Advanced Data Structures and Algorithms

## Leetcode 24: Swap Nodes in Pairs

**Problem Link:** [Leetcode 24 - Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)
**Solution File:** [Leetcode_24.cpp](./Leetcode_24.cpp)

**Problem:**
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example:**

```
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Input: head = [1]
Output: [1]

Input: head = [1,2,3]
Output: [2,1,3]
```

**Approach:**

- **Recursive Solution**: Swap first two nodes, then recursively handle the rest
- **Iterative Solution**: Use a dummy node and traverse in pairs, swapping each pair

**Time Complexity:** O(n) - We visit each node exactly once
**Space Complexity:**

- Recursive: O(n) due to recursion stack
- Iterative: O(1) constant space

---

## Sum of Max and Min of Window K in Array

**Problem Link:** [GFG - Sum of minimum and maximum elements of all subarrays of size k](https://www.geeksforgeeks.org/dsa/sum-minimum-maximum-elements-subarrays-size-k/)
**Solution File:** [Sum_of_max_min_of_window_k_in_array.cpp](./Sum_of_max_min_of_window_k_in_array.cpp)

**Problem:**
Given an array and a window size k, find the sum of minimum and maximum elements of all subarrays of size k.

**Example:**

```
Input: arr[] = {2, 5, -1, 7, -3, -1, -2}, k = 4
Output: 19
Explanation: All subarrays of size 4 are:
  {2, 5, -1, 7},   min + max = -1 + 7 = 6
  {5, -1, 7, -3},  min + max = -3 + 7 = 4
  {-1, 7, -3, -1}, min + max = -3 + 7 = 4
  {7, -3, -1, -2}, min + max = -2 + 7 = 5
Sum of all min & max = 6 + 4 + 4 + 5 = 19
```

**Approach:**

- Use two deques to maintain minimum and maximum elements in each sliding window
- For each window, add the sum of current max and min to the result
- Maintain monotonic deques for efficient min/max tracking

**Time Complexity:** O(n) - Each element is pushed and popped at most once from each deque
**Space Complexity:** O(k) - Space used by the deques

---

## N Queues in an Array

**Problem Link:** [Naukri - N Queue Using Array](https://www.naukri.com/code360/problems/n-queue-using-array_1170053)
**Solution File:** [N_queues_in_an_array.cpp](./N_queues_in_an_array.cpp)

**Problem:**
Implement N queues using a single array. Each query will be one of two types:

1. Enqueue element X into the nth queue
2. Dequeue the element at the front of the nth queue

**Example:**

```
Input: N=2, S=5, Q=5
Queries:
1 2 1  (enqueue 2 to queue 1)
1 3 2  (enqueue 3 to queue 2)
1 4 1  (enqueue 4 to queue 1)
2 2    (dequeue from queue 2)
2 1    (dequeue from queue 1)

Output:
True
True
True
3
2
```

**Approach:**

- Use a single array with linked list approach
- Maintain front and back pointers for each queue
- Use next array to link free spaces and queue elements
- Efficiently manage memory allocation and deallocation

**Time Complexity:** O(1) for both enqueue and dequeue operations
**Space Complexity:** O(S) where S is the size of the array

---

## Key Concepts Covered

### 1. **Linked List Manipulation**

- Node swapping techniques
- Recursive vs iterative approaches
- Memory management in linked lists

### 2. **Sliding Window with Deques**

- Monotonic queue/deque concepts
- Efficient min/max tracking in sliding windows
- Space-time trade-offs

### 3. **Advanced Data Structure Implementation**

- Multiple queues in single array
- Memory-efficient linked list implementation
- Dynamic memory allocation patterns

### 4. **Algorithm Optimization**

- Time complexity analysis
- Space complexity optimization
- Trade-offs between different approaches

## Common Patterns

1. **Two Pointer Technique**: Used in linked list problems
2. **Sliding Window**: Applied with deques for range queries
3. **Memory Management**: Efficient use of arrays for multiple data structures
4. **Recursion vs Iteration**: Choosing the right approach based on constraints

## Practice Problems

- [Leetcode 25 - Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
- [Leetcode 239 - Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [GFG - K Queues in Single Array](https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/)

## Notes

- Always consider both time and space complexity when choosing algorithms
- Memory management is crucial in C++ implementations
- Sliding window problems often benefit from monotonic data structures
- Linked list problems can often be solved with both recursive and iterative approaches
