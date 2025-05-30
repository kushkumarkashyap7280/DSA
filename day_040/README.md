# Day 40: Container With Most Water

## Problem: [Container With Most Water - LeetCode 11](https://leetcode.com/problems/container-with-most-water/)

### Problem Description

Given an array of heights, find two lines that together with the x-axis can form a container that holds the maximum amount of water.

### Example

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

## Approaches

### 1. Brute Force Approach

```cpp
// Time Complexity: O(n²)
// Space Complexity: O(1)
int maxAreaBruteForce(vector<int>& height) {
    int maxArea = 0;
    int n = height.size();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int width = j - i;
            int h = min(height[i], height[j]);
            maxArea = max(maxArea, width * h);
        }
    }
    return maxArea;
}
```

#### Analysis

- **Time Complexity**: O(n²)
  - Two nested loops: outer loop runs n times, inner loop runs n-1, n-2, ..., 1 times
- **Space Complexity**: O(1)
  - Only using constant extra space
- **Why it's inefficient**:
  - Checks every possible pair of lines
  - Redundant calculations
  - Not suitable for large inputs

### 2. Optimal Approach (Two Pointer)

```cpp
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxArea(vector<int>& height) {
    long long maxArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while(left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        maxArea = max(maxArea, (long long)width * h);

        if(height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
```

#### Analysis

- **Time Complexity**: O(n)
  - Single pass through the array using two pointers
- **Space Complexity**: O(1)
  - Only constant extra space used
- **Key Insights**:
  1. Area = width × height
  2. Width = right_pointer - left_pointer
  3. Height = min(height[left], height[right])

#### Why Two Pointer Works

1. Start with maximum possible width
2. Move pointers based on height comparison:
   - If left height is smaller, moving right pointer can't improve area
   - If right height is smaller, moving left pointer can't improve area
3. Always move the pointer with smaller height

## Implementation Details

### Key Points

1. **Integer Overflow Handling**

   ```cpp
   long long maxArea = 0;
   long long temp_area = 1LL * h * w;
   ```

2. **Efficient Comparisons**
   ```cpp
   if(height[left] <= height[right]) {
       left++;
   } else {
       right--;
   }
   ```

### Edge Cases

1. Minimum array size: 2 elements
2. Maximum array size: 10⁵
3. Height range: 0 to 10⁴

## Common Pitfalls

1. Not handling integer overflow
2. Incorrect area calculation
3. Inefficient pointer movement strategy
4. Not considering edge cases

## Interview Tips

1. First explain brute force approach
2. Discuss its limitations
3. Explain two-pointer optimization
4. Mention time/space complexity
5. Discuss integer overflow handling
6. Consider follow-up questions:
   - What if heights are negative?
   - How to handle floating-point heights?
   - Can we optimize for space?
