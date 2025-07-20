## Leetcode 3622: Check Divisibility by Digit Sum and Product

**Problem Link:** [Leetcode 3622 - Check Divisibility by Digit Sum and Product](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/)
**Solution File:** [Leetcode_3622.cpp](./Leetcode_3622.cpp)

**Problem:**
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

- The digit sum of n (the sum of its digits).
- The digit product of n (the product of its digits).
  Return true if n is divisible by this sum; otherwise, return false.

**Example:**

```
Input: n = 99
Output: true

Input: n = 23
Output: false
```

**Approach:**

- Calculate the sum and product of the digits of n.
- Check if n is divisible by (sum + product).

**Time Complexity:** O(D), where D is the number of digits in n (at most 7 for n <= 10^6)
**Space Complexity:** O(1)

**Code Snippet:**

```cpp
bool checkDivisibility(int n) {
  int num = n;
  int sum = 0;
  int product = 1;
  while(num){
      sum +=  num%10;
      product *= num%10;
      num/=10;
  }
  return (n%(sum+product)) == 0;
}
```

---

## STL Queue Demo

**File:** [queue.cpp](./queue.cpp)

Demonstrates the usage of `std::queue` in C++:

- Pushing, popping, accessing front/back, checking size and emptiness, and printing the queue.

**Code Snippet:**

```cpp
#include <queue>
queue<int> q;
q.push(5);
q.push(6);
q.push(7);
cout << q.front(); // 5
q.pop();
cout << q.front(); // 6
```

---

## Custom Queue Using Array

**File:** [custom_queue_using_array.cpp](./custom_queue_using_array.cpp)

Implements a fixed-size queue using an array. Supports:

- push, pop, front, size, isempty, and iteration.

**Usage Example:**

```cpp
array_queue k(5);
k.push(0);
k.push(1);
k.push(2);
k.push(3);
k.push(4);
k.pop();
cout << k.front(); // 1
```

---

## Custom Queue Using Linked List

**File:** [custom_queue_using_linkedList.cpp](./custom_queue_using_linkedList.cpp)

Implements a queue using a singly linked list. Supports:

- push, pop, front, size, isempty, and iteration.

**Usage Example:**

```cpp
LL_queue k;
k.push(4);
k.push(5);
k.pop();
cout << k.front(); // 5
```

---

Each file contains a `main` function with sample usage and output for easy testing and demonstration.
