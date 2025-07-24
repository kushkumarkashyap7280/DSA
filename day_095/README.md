# Day 095: Queue and String Problems

## Leetcode 387: First Unique Character in a String

**Problem Link:** [Leetcode 387 - First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)
**Solution File:** [Leetcode_387.cpp](./Leetcode_387.cpp)

**Problem:**
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

**Examples:**

```
Input: s = "leetcode"
Output: 0

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1
```

**Approach:**

- Count the frequency of each character.
- Return the index of the first character with frequency 1.
- Alternative: Use a queue to track indices of unique characters as you process the string.

**Time Complexity:** O(N), where N is the length of the string
**Space Complexity:** O(26) for frequency array

**Code Snippet:**

```cpp
int firstUniqChar(const string &s) {
  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'a']++;
  for (int i = 0; i < (int)s.size(); i++) {
    if (freq[s[i] - 'a'] == 1)
      return i;
  }
  return -1;
}
```

---

## Stream First Non-repeating

**Problem Link:** [First Non-repeating Character in a Stream](https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)
**Solution File:** [stream_first_non_repeating.cpp](./stream_first_non_repeating.cpp)

**Problem:**
Given an input stream s consisting only of lowercase alphabets. For each character read, output the first non-repeating character so far in the stream. If there is no such character, output '#'.

**Examples:**

```
Input: s = "aabc"
Output: "a#bb"

Input: s = "zz"
Output: "z#"
```

**Approach:**

- Use a queue to keep track of the order of characters.
- Use a frequency array to count occurrences.
- For each character, remove from the queue any characters that have occurred more than once.
- The front of the queue is the first non-repeating character.

**Time Complexity:** O(N)
**Space Complexity:** O(26) for frequency + O(N) for queue

**Code Snippet:**

```cpp
string FirstNonRepeating(string &s) {
  vector<int> freq(26, 0);
  string ans;
  queue<char> stream;
  for (char c : s) {
    freq[c - 'a']++;
    stream.push(c);
    while (!stream.empty() && freq[stream.front() - 'a'] > 1) {
      stream.pop();
    }
    if (!stream.empty()) {
      ans.push_back(stream.front());
    } else {
      ans.push_back('#');
    }
  }
  return ans;
}
```

---

## Reverse First K Elements of Queue

**Problem Link:** [Reverse First K Elements of Queue](https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)
**Solution File:** [reverse_first_k_elements_in_queue.cpp](./reverse_first_k_elements_in_queue.cpp)

**Problem:**
Given an integer k and a queue of integers, reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

**Examples:**

```
Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]

Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4]
```

**Approach:**

- Use a stack to reverse the first k elements.
- Dequeue the first k elements and push them onto a stack.
- Pop from the stack and enqueue back to the queue.
- Move the remaining elements (size - k) to the back to maintain order.

**Time Complexity:** O(N)
**Space Complexity:** O(K) for the stack

**Code Snippet:**

```cpp
queue<int> reverseFirstK(queue<int> q, int k) {
  stack<int> s;
  int i = 0;
  while (i < k) {
    s.push(q.front());
    q.pop();
    i++;
  }
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
  for (int j = 0; j < q.size() - k; j++) {
    q.push(q.front());
    q.pop();
  }
  return q;
}
```

---

## First Negative Integer in Every Window of Size K

**Problem Link:** [First Negative Integer in Every Window of Size K](https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)
**Solution File:** [Find_first_negative_in_every_window_in_an_array.cpp](./Find_first_negative_in_every_window_in_an_array.cpp)

**Problem:**
Given an array arr[] and a positive integer k, find the first negative integer for each and every window (contiguous subarray) of size k. If a window does not contain a negative integer, return 0 for that window.

**Examples:**

```
Input: arr[] = [-8, 2, 3, -6, 10], k = 2
Output: [-8, 0, -6, -6]

Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output: [-1, -1, -7, -15, -15, 0]
```

**Approach:**

- Use a deque to store indices of negative numbers in the current window.
- For each window, the front of the deque is the first negative integer.
- Remove indices that are out of the current window.

**Time Complexity:** O(N)
**Space Complexity:** O(K) for the deque

**Code Snippet:**

```cpp
vector<int> firstNegInt(const vector<int> &arr, int k) {
  vector<int> ans;
  deque<int> window;
  for (int i = 0; i < k; i++) {
    if (arr[i] < 0)
      window.push_back(i);
  }
  if (!window.empty()) {
    ans.push_back(arr[window.front()]);
  } else {
    ans.push_back(0);
  }
  for (int i = k; i < arr.size(); i++) {
    while (!window.empty() && window.front() < i - k + 1) {
      window.pop_front();
    }
    if (arr[i] < 0)
      window.push_back(i);
    if (!window.empty()) {
      ans.push_back(arr[window.front()]);
    } else {
      ans.push_back(0);
    }
  }
  return ans;
}
```
