# Day 094: Queue Reversal

## Leetcode 203: Remove Linked List Elements

**Problem Link:** [Leetcode 203 - Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
**Solution File:** [Leetcode_203.cpp](./Leetcode_203.cpp)

**Problem:**
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

**Example:**

```
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []

Input: head = [7,7,7,7], val = 7
Output: []
```

**Approach:**

- Remove leading nodes with value == val.
- Traverse the list, removing nodes with value == val by updating pointers and deleting nodes.

**Time Complexity:** O(N), where N is the number of nodes in the list
**Space Complexity:** O(1) (in-place)

**Code Snippet:**

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    if (!head) return nullptr;
    ListNode *curr = head->next;
    ListNode *prev = head;
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}
```

---

This directory also contains a solution for reversing a queue, a common problem that tests understanding of queue and stack data structures. The solution is provided in C++ and demonstrates two different approaches to achieve the reversal.

**Problem Link:** [Queue Reversal](https://www.geeksforgeeks.org/problems/queue-reversal/1)
**Solution File:** [reverse_a_queue.cpp](./reverse_a_queue.cpp)

---

## Queue Reversal

Given a queue `q` containing integer elements, the task is to reverse the order of its elements.

**Examples:**

- **Input:** `q[] = [4, 3, 1, 10, 2, 6]`
- **Output:** `[6, 2, 10, 1, 3, 4]`

- **Input:** `q[] = [7, 9, 5, 12, 8]`
- **Output:** `[8, 12, 5, 9, 7]`

### Approach 1: Using a Stack

The most intuitive and standard way to reverse a queue is by using a stack. Since a queue is a FIFO (First-In, First-Out) structure and a stack is a LIFO (Last-In, First-Out) structure, we can leverage the stack to invert the order of elements.

1.  Dequeue all elements from the queue and push them onto a stack.
2.  Pop all elements from the stack and enqueue them back into the queue.

The result is a reversed queue.

#### Complexity

- **Time Complexity:** O(N), where N is the number of elements. We iterate through the queue once to push to the stack and once to pop from the stack.
- **Space Complexity:** O(N) to store the elements in the auxiliary stack.

#### Code Snippet

```cpp
#include <queue>
#include <stack>

// Approach 2: Using a stack
// Time Complexity: O(N), where N is the number of elements in the queue.
// Space Complexity: O(N) for the auxiliary stack.
std::queue<int> reverseQueueWithStack(std::queue<int>& q) {
        std::stack<int> st;

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}
```

---

### Approach 2: Using Recursion

This approach uses the function call stack to reverse the queue. It's a classic recursive solution that demonstrates how recursion can be used to simulate a stack.

1.  Base case: If the queue is empty, return.
2.  Recursive step: Dequeue an element and hold it in the function's execution context.
3.  Make a recursive call with the smaller queue.
4.  After the recursive call returns, enqueue the held element.

This process effectively reverses the queue because the first element dequeued is the last one to be enqueued.

#### Complexity

- **Time Complexity:** O(N^2). For each element, the recursion goes N levels deep, and the `push` operation at each level takes time proportional to the size of the queue at that level. A more accurate analysis shows that each element is enqueued and dequeued N times.
- **Space Complexity:** O(N) for the recursion call stack depth.

#### Code Snippet

```cpp
#include <queue>

// Approach 3: Using Recursion
std::queue<int> reverseQueue(std::queue<int> &q) {
    if (q.empty()) return q;

    int f = q.front();   // store the front
    q.pop();

    reverseQueue(q);     // reverse the rest

    q.push(f);           // push the front to back
    return q;
}
```

---

### Approach 3: Using an Array

Another method is to use an auxiliary array. This approach is straightforward but may be less elegant than the stack-based solution.

1.  Create an array of the same size as the queue.
2.  Dequeue elements from the queue and store them in the array in reverse order.
3.  Enqueue the elements from the array back into the queue.

#### Complexity

- **Time Complexity:** O(N), as we iterate through the queue to fill the array and then iterate through the array to fill the queue.
- **Space Complexity:** O(N) for the auxiliary array.

#### Code Snippet

```cpp
#include <queue>

// Approach 1: Using an auxiliary array
// Time Complexity: O(N), where N is the number of elements in the queue.
// Space Complexity: O(N) for the auxiliary array.
std::queue<int> reverseQueueWithArray(std::queue<int> &q) {
    int s = q.size();
    int * arr = new int[s];
    int j = s-1;
    while(!q.empty()){
        arr[j] = q.front();
        q.pop();
        j--;
    }

    for(int i = 0; i < s; i++){
        q.push(arr[i]);
    }

    delete [] arr;
    return q;
}
```
