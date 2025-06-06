# Day 47: First and Last Position in Sorted Array (LeetCode 34)

## Problem Analysis

### Problem Statement
Given a sorted array `nums` and a target value, find the starting and ending position of the target value. If the target is not found, return `[-1, -1]`. The algorithm must have O(log n) runtime complexity.

### Constraints
- Array length: 0 ≤ nums.length ≤ 10⁵
- Array elements: -10⁹ ≤ nums[i] ≤ 10⁹
- Array is non-decreasing (sorted)
- Target value: -10⁹ ≤ target ≤ 10⁹

## Implementation Approach

### Core Algorithm
The solution uses a modified binary search algorithm with two phases:
1. **Finding Target**: Use binary search to locate any occurrence of target
2. **Expanding Range**: Once found, expand left and right to find boundaries

### Key Steps
1. Initialize result vector with [-1, -1]
2. Perform binary search to find target:
   ```cpp
   while (i <= j) {
       int m = i + (j - i) / 2;  // Calculate mid point
       if (nums[m] == target) {
           // Found target, now find boundaries
           i = j = m;
           // Expand left and right
           while (i > 0 && nums[i-1] == target) i--;
           while (j < nums.size()-1 && nums[j+1] == target) j++;
           return {i, j};
       }
       // Standard binary search logic
       else if (nums[m] < target) i = m + 1;
       else j = m - 1;
   }
   ```

### Optimizations
1. **Mid-point Calculation**: Uses `i + (j-i)/2` to prevent integer overflow
2. **Early Exit**: Returns [-1, -1] if array is empty
3. **Boundary Checks**: Careful handling of array boundaries while expanding range

## Complexity Analysis

### Time Complexity: O(log n)
- Binary search phase: O(log n)
- Range expansion phase: O(k) where k is the count of target value
- Overall worst case: O(n) if array contains all same elements
- Average case: O(log n)

### Space Complexity: O(1)
- Only uses constant extra space
- Result vector size is fixed (2 elements)

## Code Structure

### Main Components
1. **searchRange Function**
   - Input: Vector of integers and target value
   - Output: Vector with first and last positions
   - Uses modified binary search algorithm

2. **Main Function**
   - Contains test case
   - Demonstrates function usage
   - Formats and displays output

## Test Cases

### Test Case 1
```cpp
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Explanation: 8 appears at indices 3 and 4
```

### Test Case 2
```cpp
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Explanation: 6 is not present in array
```

### Test Case 3
```cpp
Input: nums = [], target = 0
Output: [-1,-1]
Explanation: Array is empty
```

## Common Edge Cases
1. Empty array
2. Single element array
3. All elements same as target
4. Target not present in array
5. Target at boundaries (start/end)

## Code Quality and Style

### Best Practices Used
1. Clear variable naming (`nums`, `target`, `ans`)
2. Proper comments explaining logic
3. Efficient algorithm meeting time complexity requirement
4. Safe array access with boundary checks
5. Clean code structure and formatting

### Potential Improvements
1. Could split into two binary searches for better readability
2. Add more comprehensive error handling
3. Consider template for different numeric types
4. Add input validation for constraints
