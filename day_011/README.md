# Day 11: Array Problems

## Problem 1: Two Sum

### Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers in `nums` such that they add up to `target`.

### Examples:

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Approaches

#### 1. Hash Map Approach

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Algorithm**:
  1. Use hash map to store complement values
  2. For each number x:
     - Calculate complement (target - x)
     - If complement exists in map, return current and stored indices
     - Else store current number and index
  3. Return empty array if no solution found

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}
```

### Key Points

1. **Hash Map Usage**:
   - O(1) lookup time
   - Stores complement values for quick access
2. **Index Management**:
   - Returns original indices
   - Handles duplicate values correctly

### Constraints

- 2 ≤ nums.length ≤ 10⁴
- -10⁹ ≤ nums[i] ≤ 10⁹
- -10⁹ ≤ target ≤ 10⁹
- Only one valid solution exists

### Source

[LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum)

---

## Problem 2: Smallest Index With Equal Digit Sum

### Problem Description

Find the smallest index i where the sum of digits of nums[i] equals i.

### Examples:

```
Input: nums = [1,10,11]
Output: 1
Explanation: nums[1] = 10, digit sum = 1+0 = 1 equals index 1

Input: nums = [1,2,3]
Output: -1
Explanation: No index satisfies the condition
```

### Approach

- **Time Complexity**: O(n \* log m)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Iterate through array indices
  2. For each number:
     - Calculate sum of its digits
     - If sum equals index, return index
  3. Return -1 if no match found

```cpp
int smallestIndex(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        int tempsum = 0;
        int tempNo = nums[i];
        while(tempNo) {
            tempsum += tempNo%10;
            tempNo/=10;
        }
        if(tempsum == i) return i;
    }
    return -1;
}
```

### Key Points

1. **Digit Sum Calculation**:
   - Uses modulo and division operations
   - Handles multi-digit numbers correctly
2. **Early Return**:
   - Returns first matching index
   - Ensures smallest index is found

### Constraints

- 1 ≤ nums.length ≤ 100
- 0 ≤ nums[i] ≤ 1000

### Source

[LeetCode 3550 - Smallest Index With Equal Digit Sum](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)
