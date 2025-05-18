# Day 28: Array Properties

## Problem: Monotonic Array [LeetCode 896]

### Problem Description

- Check if array is monotonic (either increasing or decreasing)
- Array is monotone increasing if nums[i] <= nums[j] for all i <= j
- Array is monotone decreasing if nums[i] >= nums[j] for all i <= j

### Approaches

1. First Approach

   - Skip equal elements at start
   - Determine direction (increasing/decreasing)
   - Check if property holds
   - Time: O(n), Space: O(1)

2. Second Approach (Optimized)
   - Use two boolean flags (inc, dec)
   - Check both conditions simultaneously
   - Return true if either condition holds
   - Time: O(n), Space: O(1)

### Code Example

```cpp
bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    bool inc = true, dec = true;
    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[i-1]) dec = false;
        if(nums[i] < nums[i-1]) inc = false;
    }
    return inc || dec;
}
```
