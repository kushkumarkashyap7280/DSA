# Day 124: Heap & Range Problems

## 1. Smallest Range Covering Elements from K Lists

**Leetcode 632**  
[Problem Link](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)

**Problem:**
Given k sorted lists, find the smallest range that includes at least one number from each list.

**Approach:**

- Use a min-heap to always get the smallest current element among all lists.
- Track the current maximum value among the heap elements.
- At each step, update the range if the current [min, max] is smaller.
- Move forward in the list from which the min element was taken, pushing the next element into the heap and updating the max.
- Stop when any list is exhausted (since the range must include at least one from each list).

**Example:**

```
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
```

**Complexity:**

- Time: O(N log k), where N is the total number of elements and k is the number of lists.
- Space: O(k) for the heap.

**Solution File:**

- [Leetcode_632.cpp](./Leetcode_632.cpp)

---

## 2. Find Median from Data Stream

**Leetcode 295**  
[Problem Link](https://leetcode.com/problems/find-median-from-data-stream/)

**Problem:**
Design a data structure that supports adding numbers and finding the median efficiently.

**Approach:**

- Use two heaps:
  - maxHeap: stores the smaller half of the numbers (max at top)
  - minHeap: stores the larger half of the numbers (min at top)
- Always keep maxHeap.size() >= minHeap.size()
- For odd total, median is top of maxHeap
- For even total, median is average of tops of both heaps
- Rebalance after every insertion to maintain size property

**Example:**

```
Input: [1, 2, 3]
Medians: 1, 1.5, 2
```

**Complexity:**

- addNum: O(log n)
- findMedian: O(1)
- Space: O(n)

**Solution File:**

- [Leetcode_295.cpp](./Leetcode_295.cpp)
