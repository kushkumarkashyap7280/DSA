## Leetcode 1957: Delete Characters to Make Fancy String

**Problem Link:** [Leetcode 1957 - Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)
**Solution File:** [Leetcode_1957.cpp](./Leetcode_1957.cpp)

**Problem:**
Given a string s, delete the minimum possible number of characters from s to make it fancy (no three consecutive characters are equal). Return the final string after the deletion.

**Example:**

```
Input: s = "leeetcode"
Output: "leetcode"

Input: s = "aaabaaaa"
Output: "aabaa"
```

**Approach:**

- Iterate through the string, keep a count of consecutive characters.
- Skip adding a character if it would make three in a row.

**Time Complexity:** O(N)
**Space Complexity:** O(N)

**Code Snippet:**

```cpp
string makeFancyString(string s) {
  string ans;
  int count = 0;
  char curr = s[0];
  for (char c : s) {
    if (c == curr && count >= 2) continue;
    ans.push_back(c);
    if (c == curr) count++;
    else { curr = c; count = 1; }
  }
  return ans;
}
```

---

## Leetcode 622: Design Circular Queue

**Problem Link:** [Leetcode 622 - Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
**Solution File:** [Leetcode_622.cpp](./Leetcode_622.cpp)

**Problem:**
Implement a circular queue with the following operations: enQueue, deQueue, Front, Rear, isEmpty, isFull. Do not use built-in queue data structures.

**Example:**

```
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

**Approach:**

- Use a fixed-size array and two pointers (front, rear) with modulo arithmetic to wrap around.

**Time Complexity:** O(1) for all operations
**Space Complexity:** O(k)

**Code Snippet:**

```cpp
class MyCircularQueue {
  int s, front, rear, currsize, *arr;
public:
  MyCircularQueue(int k) : s(k), front(0), rear(-1), currsize(0), arr(new int[k]) {}
  ~MyCircularQueue() { delete[] arr; }
  bool enQueue(int value) { if (isFull()) return false; rear = (rear + 1) % s; arr[rear] = value; currsize++; return true; }
  bool deQueue() { if (isEmpty()) return false; front = (front + 1) % s; currsize--; return true; }
  int Front() { return isEmpty() ? -1 : arr[front]; }
  int Rear() { return isEmpty() ? -1 : arr[rear]; }
  bool isEmpty() { return currsize == 0; }
  bool isFull() { return currsize == s; }
};
```

---

## Custom Circular Queue (Linked List)

**File:** [custom_circular_queue.cpp](./custom_circular_queue.cpp)

Implements a circular queue using a singly linked list. Supports:

- push, pop, front, size, isempty, and iteration.

**Usage Example:**

```cpp
C_queue c;
c.push(5);
c.push(6);
c.push(7);
c.pop();
cout << c.front(); // 6
```

---

Each file contains a `main` function with sample usage and output for easy testing and demonstration.
