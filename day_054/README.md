# Day 54: LeetCode 217 - Contains Duplicate

## Problem Analysis

### Problem Statement

Given an integer array `nums`, determine if any value appears at least twice. Return `true` if any value appears at least twice, and return `false` if every element is distinct.

### Constraints

- 1 ≤ nums.length ≤ 10⁵
- -10⁹ ≤ nums[i] ≤ 10⁹

## Solution Approach

### Algorithm: Sort and Compare

The solution uses a sorting-based approach:

1. Sort the array in ascending order
2. Compare adjacent elements
3. Return true if any adjacent elements are equal

### Implementation Details

```cpp
bool containsDuplicate(vector<int>& nums) {
    // Sort array in ascending order
    sort(nums.begin(), nums.end());

    // Check adjacent elements
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            return true;  // Found duplicate
        }
    }
    return false;  // No duplicates found
}
```

### Key Points

1. **Sorting Advantage**:

   - Brings duplicates next to each other
   - Simplifies comparison process
   - No need for extra space

2. **Sequential Check**:

   - Only need to compare adjacent elements
   - Early return when duplicate found
   - Single pass through sorted array

3. **In-place Operation**:
   - Modifies original array
   - No additional storage needed
   - Trade-off between time and space

## Complexity Analysis

### Time Complexity: O(n log n)

- Sorting: O(n log n)
- Sequential scan: O(n)
- Overall: O(n log n)

### Space Complexity: O(1)

- In-place sorting
- No extra space needed
- Only few variables used

## Test Cases

### Example 1

```
Input: nums = [1,2,3,1]
Output: true
Explanation: 1 appears twice
```

### Example 2

```
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements distinct
```

### Example 3

```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
Explanation: Multiple duplicates present
```

## Edge Cases

1. **Minimum Size Array**:

   - Single element array
   - No duplicates possible

2. **Maximum Values**:

   - Values at INT_MAX
   - Values at INT_MIN

3. **Repeated Elements**:
   - All elements same
   - Multiple duplicates

## Alternative Approaches

### 1. Hash Set Approach

```cpp
// Time: O(n), Space: O(n)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for(int num : nums) {
        if(seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}
```

### 2. Brute Force Approach

```cpp
// Time: O(n²), Space: O(1)
bool containsDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] == nums[j]) return true;
        }
    }
    return false;
}
```

## Implementation Tips

1. Consider space vs time trade-offs
2. Use appropriate STL functions
3. Handle edge cases properly
4. Choose approach based on constraints

## Real-world Applications

1. **Data Validation**:

   - Checking unique identifiers
   - Validating user inputs
   - Database integrity

2. **Data Processing**:
   - Finding duplicate records
   - Data cleaning
   - Error detection

## Related Problems

1. Contains Duplicate II (LeetCode 219)
2. Contains Duplicate III (LeetCode 220)
3. Find the Duplicate Number (LeetCode 287)

## Optimization Opportunities

1. **Early Exit**:

   - Return as soon as duplicate found
   - No need to complete sort for small arrays

2. **Memory Usage**:

   - In-place sorting saves space
   - Avoid unnecessary copies

3. **Special Cases**:
   - Handle small arrays differently
   - Check for immediate duplicates first
