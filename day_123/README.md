# Day 123: Subarray Sum Problems

## Overview

Day 123 focuses on subarray sum problems, exploring techniques like Kadane's algorithm and min-heap usage. These problems demonstrate efficient approaches to handling contiguous subarray computations and maintaining k-largest elements.

## Problems Solved

### 1. Maximum Subarray (LeetCode 53)

**File:** [Leetcode_58.cpp](./Leetcode_58.cpp)

**Problem Link:** [LeetCode 53 - Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

**Problem:**
Find the contiguous subarray with the largest sum and return its sum.

**Approaches:**

1. **Brute Force Solution (O(n²)):**

   ```cpp
   int maxSubArray(vector<int>& nums) {
       int maxSum = INT_MIN;
       for(int i = 0; i < nums.size(); i++) {
           int sum = 0;
           for(int j = i; j < nums.size(); j++) {
               sum += nums[j];
               maxSum = max(sum, maxSum);
           }
       }
       return maxSum;
   }
   ```

2. **Kadane's Algorithm (O(n)):**
   ```cpp
   int maxSubArray(vector<int>& nums) {
       int maxSum = INT_MIN;
       int currSum = 0;
       for(int num : nums) {
           currSum += num;
           maxSum = max(currSum, maxSum);
           if(currSum < 0) currSum = 0;
       }
       return maxSum;
   }
   ```

**Key Insights:**

- Negative prefix sums can be discarded
- Current sum reset to 0 when it becomes negative
- Maintain running maximum for global solution

**Time Complexity:** O(n)
**Space Complexity:** O(1)

### 2. K-th Largest Sum Contiguous Subarray

**File:** [kth-largest-sum-of_contigious_subarray.cpp](./kth-largest-sum-of_contigious_subarray.cpp)

**Problem Link:** [GeeksForGeeks - K-th Largest Sum Contiguous Subarray](https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1)

**Problem:**
Find the k-th largest sum among all possible contiguous subarrays.

**Approaches:**

1. **Brute Force Solution (O(n² log(n²))):**

   ```cpp
   int kthLargest(vector<int>& arr, int k) {
       vector<int> sums;
       for(int i = 0; i < arr.size(); i++) {
           int sum = 0;
           for(int j = i; j < arr.size(); j++) {
               sum += arr[j];
               sums.push_back(sum);
           }
       }
       sort(sums.begin(), sums.end());
       return sums[sums.size() - k];
   }
   ```

2. **Min Heap Solution (O(n² log k)):**
   ```cpp
   int kthLargest(vector<int>& arr, int k) {
       priority_queue<int, vector<int>, greater<int>> pq;
       for(int i = 0; i < arr.size(); i++) {
           int sum = 0;
           for(int j = i; j < arr.size(); j++) {
               sum += arr[j];
               if(pq.size() < k) {
                   pq.push(sum);
               } else if(pq.top() < sum) {
                   pq.pop();
                   pq.push(sum);
               }
           }
       }
       return pq.top();
   }
   ```

**Key Insights:**

- Min heap efficiently maintains k largest elements
- No need to store all sums
- Early pruning when sum smaller than k-th largest

**Time Complexity:** O(n² log k)
**Space Complexity:** O(k)

## Key Concepts Covered

### 1. **Dynamic Programming Pattern**

- Kadane's algorithm for maximum subarray sum
- Maintaining optimal substructure
- Local vs. global optima tracking

### 2. **Heap Data Structure**

- Min heap for k-largest elements
- Priority queue implementation
- Space-time trade-offs

### 3. **Problem-Solving Patterns**

- Sliding window technique
- Cumulative sum tracking
- Early pruning optimizations

## Common Patterns

1. **Subarray Sum Pattern:**

   - Track running sum
   - Reset on negative values
   - Maintain global maximum

2. **K-Largest Elements Pattern:**

   - Use min heap of size k
   - Push if heap size < k
   - Compare with top for replacement

3. **Optimization Techniques:**
   - Early pruning
   - Space optimization
   - Time-space trade-offs

## Time and Space Complexity Summary

| Problem          | Approach    | Time Complexity | Space Complexity |
| ---------------- | ----------- | --------------- | ---------------- |
| Maximum Subarray | Brute Force | O(n²)           | O(1)             |
| Maximum Subarray | Kadane's    | O(n)            | O(1)             |
| Kth Largest Sum  | Brute Force | O(n² log(n²))   | O(n²)            |
| Kth Largest Sum  | Min Heap    | O(n² log k)     | O(k)             |

## Notes

1. **For Maximum Subarray:**

   - Always consider Kadane's algorithm first
   - Watch for all negative arrays
   - Consider empty subarray rules

2. **For Kth Largest Sum:**

   - Consider k's size relative to n²
   - Balance between sorting and heap
   - Watch for integer overflow

3. **General Tips:**
   - Look for negative prefix optimization
   - Consider space-time trade-offs
   - Watch for edge cases

## Sample Usage

```bash
# Compile and run Maximum Subarray
g++ -std=c++17 Leetcode_58.cpp -o maxSubarray
./maxSubarray

# Compile and run Kth Largest Sum
g++ -std=c++17 kth-largest-sum-of_contigious_subarray.cpp -o kthLargest
./kthLargest
```
