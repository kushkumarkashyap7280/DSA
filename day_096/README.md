# Day 096: Queue and Stack Problems

## Leetcode 134: Gas Station

**Problem Link:** [Leetcode 134 - Gas Station](https://leetcode.com/problems/gas-station/)
**Solution File:** [Leetcode_134.cpp](./Leetcode_134.cpp)

**Problem:**
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

**Example:**

```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
```

**Approach:**

- Use a single pass to track total and current gas balance.
- If current balance drops below zero, reset start index.
- If total gas is less than total cost, return -1.

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## Leetcode 225: Implement Stack using Queues

**Problem Link:** [Leetcode 225 - Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
**Solution File:** [Leetcode_225.cpp](./Leetcode_225.cpp)

**Problem:**
Implement a stack using only standard queue operations.

**Example:**

```
Input: ["MyStack", "push", "push", "top", "pop", "empty"]
       [[], [1], [2], [], [], []]
Output: [null, null, null, 2, 2, false]
```

**Approach:**

- Use two queues to simulate stack push/pop/top/empty operations.
- Push: Enqueue to auxiliary queue, then move all elements from main queue.
- Pop/Top: Dequeue from main queue.

**Time Complexity:** O(n) for push, O(1) for pop/top/empty
**Space Complexity:** O(n)

---

## Leetcode 232: Implement Queue using Stacks

**Problem Link:** [Leetcode 232 - Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
**Solution File:** [Leetcode_232.cpp](./Leetcode_232.cpp)

**Problem:**
Implement a queue using only standard stack operations.

**Example:**

```
Input: ["MyQueue", "push", "push", "peek", "pop", "empty"]
       [[], [1], [2], [], [], []]
Output: [null, null, null, 1, 1, false]
```

**Approach:**

- Use two stacks to simulate queue push/pop/peek/empty operations.
- Push: Move all elements to auxiliary stack, push new element, move back.
- Pop/Peek: Pop/peek from main stack.

**Time Complexity:** O(n) for push, O(1) for pop/peek/empty
**Space Complexity:** O(n)

---

## Interleave the First Half of the Queue with Second Half

**Problem Link:** [GFG - Interleave the First Half of the Queue with Second Half](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)
**Solution File:** [Interleave_first_half_with_second_half_of_queue.cpp](./Interleave_first_half_with_second_half_of_queue.cpp)

**Problem:**
Given a queue of even size, rearrange it by interleaving its first half with the second half.

**Example:**

```
Input: q = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
```

**Approach:**

- Split the queue into two vectors for first and second halves.
- Alternate elements from each half and enqueue back.

**Time Complexity:** O(n)
**Space Complexity:** O(n)
