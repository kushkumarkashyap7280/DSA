# Day 45 - Array In-Place Operations

## LeetCode 27: Remove Element

[Problem Link](https://leetcode.com/problems/remove-element/)

### Problem Description

Remove all occurrences of a value from an array in-place and return the count of remaining elements.

### Solution Approaches

#### 1. Basic Approach using Vector Erase

```cpp
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] == val) {
            nums.erase(nums.begin() + i);
        } else {
            i++;
        }
    }
    return nums.size();
}
```

**Complexity Analysis**:

- Time Complexity: O(n²)
  - Each erase operation takes O(n) to shift elements
  - We might need to do this n times
- Space Complexity: O(1)
  - No extra space used

**Why Not Optimal**:

1. Vector's erase operation is expensive
2. Shifting elements after each removal
3. Multiple passes through the same elements

#### 2. Optimized Two-Pointer Approach

```cpp
int removeElementOptimized(vector<int>& nums, int val) {
    int k = 0;  // Position for next valid element
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
```

**Complexity Analysis**:

- Time Complexity: O(n)
  - Single pass through the array
- Space Complexity: O(1)
  - In-place modification

### Detailed Explanation of Optimized Approach

1. **Two-Pointer Technique**

   - k: Points to position where next non-val element should go
   - i: Scans through the array

2. **Key Steps**:
   ```
   Initial: [3,2,2,3], val = 3
           k
           i
   Step 1: [3,2,2,3]  (i=0, nums[i]=3)
           k i
   Step 2: [2,2,2,3]  (i=1, nums[i]=2)
           k→i
   Step 3: [2,2,2,3]  (i=2, nums[i]=2)
             k i
   Step 4: [2,2,2,3]  (i=3, nums[i]=3)
               k i
   Final:  [2,2,_,_]  (k=2)
   ```

### Implementation Benefits

1. **Efficiency**:

   - Single pass through array
   - No expensive shift operations
   - Minimal memory usage

2. **Maintainability**:

   - Simple to understand
   - Easy to debug
   - Clear logic flow

3. **Memory Usage**:
   - In-place modification
   - No additional data structures

### Common Pitfalls to Avoid

1. **Array Modification**:

   - Don't actually delete elements
   - Only overwrite as needed
   - Return correct length

2. **Edge Cases**:

   - Empty array
   - All elements are val
   - No elements are val

3. **Index Management**:
   - Keep track of valid element count
   - Don't access beyond array bounds
   - Handle last element correctly

### Example Test Cases

```cpp
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
```

### Best Practices

1. **Array Operations**:

   - Use efficient in-place modifications
   - Minimize array resizing operations
   - Consider memory impact

2. **Code Organization**:

   - Clear variable names
   - Proper comments
   - Consistent formatting

3. **Testing Strategy**:
   - Test edge cases
   - Verify output array
   - Check returned length
