# Day 093: Custom Queue Implementations

This directory contains custom implementations of three different types of queues, each designed to showcase specific operational constraints. The implementations use a doubly-linked list to manage the elements, providing a clear and efficient foundation for a variety of queue-based data structures.

---

## 1. Doubly Ended Queue (Deque)

**Solution File:** [custom_doubly_ended_queue.cpp](./custom_doubly_ended_queue.cpp)

A standard **doubly-ended queue (deque)** that supports adding and removing elements from both the front and the back. This implementation offers maximum flexibility, making it a versatile tool for problems that require efficient insertions and deletions at both ends of a sequence.

### Operations

- `push_front(data)`: Adds an element to the front of the queue.
- `push_back(data)`: Adds an element to the back of the queue.
- `pop_front()`: Removes and returns the front element.
- `pop_back()`: Removes and returns the back element.

### Complexity

- **Time Complexity:** O(1) for all operations (push, pop, front).
- **Space Complexity:** O(N), where N is the number of elements in the queue.

### Code Snippet

```cpp
#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val, Node* p) : data(val), prev(p), next(nullptr) {}
};

class DEQ {
    Node *head;
    Node *tail;
    int s;

public:
    DEQ() : head(nullptr), tail(nullptr), s(0) {}

    void push_front(int data) {
        if (head) {
            Node* temp = head;
            head->prev = new Node(data, nullptr);
            head = head->prev;
            head->next = temp;
        } else {
            head = new Node(data, nullptr);
            tail = head;
        }
        s++;
    }

    void push_back(int data) {
        if (head) {
            tail->next = new Node(data, tail);
            tail = tail->next;
        } else {
            head = new Node(data, nullptr);
            tail = head;
        }
        s++;
    }

    int pop_front() {
        if (s == 0) return -1;
        int ret = head->data;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        s--;
        return ret;
    }

    int pop_back() {
        if (s == 0) return -1;
        int ret = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        s--;
        return ret;
    }
};
```

---

## 2. Input-Restricted Queue

**Solution File:** [custom_input_restricted_queue.cpp](./custom_input_restricted_queue.cpp)

An **input-restricted queue** limits insertions to only one end (the back), but allows deletions from both the front and the back. This structure is useful in scenarios where items are added in a strict FIFO order but can be removed from either end, such as in certain scheduling or task-processing systems.

### Operations

- `push_back(data)`: Adds an element to the back of the queue.
- `pop_front()`: Removes the front element.
- `pop_back()`: Removes the back element.

### Complexity

- **Time Complexity:** O(1) for all operations.
- **Space Complexity:** O(N).

### Code Snippet

```cpp
#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val, Node* p) : data(val), prev(p), next(nullptr) {}
};

class IRQ {
    Node *head;
    Node *tail;
    int s;

public:
    IRQ() : head(nullptr), tail(nullptr), s(0) {}

    void push_back(int data) {
        if (head) {
            tail->next = new Node(data, tail);
            tail = tail->next;
        } else {
            head = new Node(data, nullptr);
            tail = head;
        }
        s++;
    }

    int pop_front() {
        if (s == 0) return -1;
        int ret = head->data;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        s--;
        return ret;
    }

    int pop_back() {
        if (s == 0) return -1;
        int ret = tail->data;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        s--;
        return ret;
    }
};
```

---

## 3. Output-Restricted Queue

**Solution File:** [custom_output_restricted_queue.cpp](./custom_output_restricted_queue.cpp)

An **output-restricted queue** allows insertions at both the front and the back but restricts deletions to only the front. This makes it a hybrid between a standard queue and a stack, where elements can be added with priority (at the front) but are always processed in a strict FIFO order.

### Operations

- `push_front(data)`: Adds an element to the front.
- `push_back(data)`: Adds an element to the back.
- `pop_front()`: Removes the front element.

### Complexity

- **Time Complexity:** O(1) for all operations.
- **Space Complexity:** O(N).

### Code Snippet

```cpp
#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int val, Node* n) : data(val), next(n) {}
};

class ORQ {
    Node *head;
    Node *tail;
    int s;

public:
    ORQ() : head(nullptr), tail(nullptr), s(0) {}

    void push_front(int data) {
        if (s == 0) {
            head = new Node(data, nullptr);
            tail = head;
        } else {
            head = new Node(data, head);
        }
        s++;
    }

    void push_back(int data) {
        if (s == 0) {
            tail = new Node(data, nullptr);
            head = tail;
        } else {
            tail->next = new Node(data, nullptr);
            tail = tail->next;
        }
        s++;
    }

    int pop_front() {
        if (s == 0) return -1;
        int ret = head->data;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        s--;
        return ret;
    }
};
```

---

## 4. LeetCode 641. Design Circular Deque

**Problem Link:** [641. Design Circular Deque](https://leetcode.com/problems/design-circular-deque/)
**Solution File:** [Leetcode_641.cpp](./Leetcode_641.cpp)

This problem requires designing a circular double-ended queue (deque) with a fixed size. The implementation should support standard deque operations like `insertFront`, `insertLast`, `deleteFront`, `deleteLast`, `getFront`, `getRear`, `isEmpty`, and `isFull`. The circular nature of the queue means that the front and back pointers wrap around the underlying array, allowing for efficient use of space.

### Complexity

- **Time Complexity:** O(1) for all operations. The use of an array with front and back pointers allows for constant-time access and modification.
- **Space Complexity:** O(k), where k is the maximum size of the deque, as we need to store the elements in an array.

### Code Snippet

```cpp
class MyCircularDeque {
    int * arr;
    int n;
    int cs ;
    int front =  0;
    int back = 0;
public:
    MyCircularDeque(int k) {
        this->n = k;
        this->cs = 0;
        this->front = -1;
        this->back = -1;
        this->arr = new int[k];
    }
    
    bool insertFront(int value) {
        if(cs == n) return false;
        if(cs == 0){
           front = back = 0;
        }else{
            front = (front -1 + n)% n;
        }
        arr[front] = value;
        cs++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cs == n) return false;
        if(cs == 0){
            front = back = 0;
        }else{
            back = (back +1)%n;
        }
        arr[back] = value;
        cs++;
         return true;
    }
    
    bool deleteFront() {
        if(cs == 0) return false;
        if(cs == 1){
            front= back = -1;
        }else{  
         front = (front+1)%n;
        }
         cs--;
         return true;
    }
    
    bool deleteLast() {
        if(cs == 0) return false;
        if(cs == 1){
              front =back = -1;
             
        }else{
           back =(back -1 +n) %n;
        }
        cs--;
        return true;
    }
};
```
