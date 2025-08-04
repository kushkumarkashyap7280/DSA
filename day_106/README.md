# Day 106: Array Manipulation and Search Problems

## Overview

Day 106 focuses on array manipulation and search problems. The day covers removing duplicates from sorted arrays while allowing at most two occurrences of each element, and searching in rotated sorted arrays with duplicate elements. These problems test understanding of array manipulation, binary search in modified arrays, and handling edge cases with duplicates.

## Problems Covered

### 1. Remove Duplicates from Sorted Array II (Leetcode 80)

**File:** [Leetcode_80.cpp](./Leetcode_80.cpp)

**Problem Link:** [LeetCode 80 - Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

**Problem:** Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

**Key Points:**

- Array is sorted in non-decreasing order
- Each unique element can appear at most twice
- Must modify array in-place with O(1) extra memory
- Return the new length of the modified array
- Elements beyond the returned length don't matter

**Example:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
```

**Approach Implemented:**

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int idx = 2;  // Index where the next valid element should go

        for (int i = 2; i < n; i++) {
            // If current number is not the same as nums[idx - 2], we can keep it
            if (nums[i] != nums[idx - 2]) {
                nums[idx] = nums[i];
                idx++;
            }
        }

        return idx;
    }
};
```

**Key Insight:** Use two-pointer technique with index tracking for valid positions.

**Time Complexity:** O(n) - single traversal through array
**Space Complexity:** O(1) - constant extra space

---

### 2. Search in Rotated Sorted Array II (Leetcode 81)

**File:** [Leetcode_81.cpp](./Leetcode_81.cpp)

**Problem Link:** [LeetCode 81 - Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

**Problem:** There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values). Before being passed to your function, nums is rotated at an unknown pivot index k. Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not.

**Key Points:**

- Array is rotated at unknown pivot
- Array may contain duplicate elements
- Must handle duplicates efficiently
- Binary search with special handling for duplicates
- Return boolean indicating target presence

**Example:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Approach Implemented:**

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates at boundaries
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
```

**Key Insight:** Modified binary search with special handling for duplicates at boundaries.

**Time Complexity:** O(log n) in average case, O(n) in worst case when many duplicates
**Space Complexity:** O(1) - constant extra space

---

## Key Concepts Covered

### 1. **Array Manipulation Techniques**

- **Two-Pointer Technique:** Efficient in-place array modification
- **Index Tracking:** Maintain valid position for next element
- **In-Place Operations:** Modify array without extra space
- **Boundary Conditions:** Handle edge cases and minimum requirements

### 2. **Binary Search in Modified Arrays**

- **Rotated Array Search:** Binary search in non-standard sorted arrays
- **Duplicate Handling:** Special logic for arrays with duplicates
- **Pivot Detection:** Identify sorted and unsorted portions
- **Boundary Management:** Handle edge cases in search space

### 3. **Duplicate Management**

- **At Most K Occurrences:** Allow limited duplicates (k=2 for problem 80)
- **Duplicate Skipping:** Efficient handling of repeated elements
- **Order Preservation:** Maintain relative order of elements
- **Space Efficiency:** O(1) space complexity requirements

### 4. **Search Space Optimization**

- **Sorted Portion Identification:** Determine which half is sorted
- **Target Range Checking:** Verify if target lies in sorted portion
- **Duplicate Boundary Handling:** Skip duplicates at search boundaries
- **Early Termination:** Return immediately when target found

### 5. **Algorithm Design Patterns**

- **Two-Pointer Pattern:** Common for array manipulation
- **Modified Binary Search:** Adapt standard binary search for special cases
- **In-Place Modification:** Efficient memory usage
- **Edge Case Handling:** Comprehensive test case coverage

## Common Patterns

1. **Array Manipulation Patterns:**

   - **Two-Pointer Technique:** One pointer for reading, one for writing
   - **Index Tracking:** Maintain position for next valid element
   - **In-Place Operations:** Modify array without extra space
   - **Boundary Validation:** Check array bounds and requirements

2. **Binary Search Patterns:**

   - **Rotated Array Search:** Handle non-standard sorted arrays
   - **Duplicate Handling:** Special logic for repeated elements
   - **Sorted Portion Detection:** Identify which half is sorted
   - **Target Range Validation:** Check if target lies in sorted portion

3. **Duplicate Management Patterns:**
   - **K-Occurrence Limit:** Allow at most k occurrences of each element
   - **Duplicate Skipping:** Efficient handling of repeated elements
   - **Order Preservation:** Maintain relative order during modification
   - **Space Optimization:** Minimize extra space usage

## Time and Space Complexity Summary

| Problem                         | Time Complexity | Space Complexity | Approach               |
| ------------------------------- | --------------- | ---------------- | ---------------------- |
| Remove Duplicates II (80)       | O(n)            | O(1)             | Two-pointer technique  |
| Search in Rotated Array II (81) | O(log n) avg    | O(1)             | Modified binary search |
|                                 | O(n) worst      |                  |                        |

## Practice Problems

- [LeetCode 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
- [LeetCode 33 - Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- [LeetCode 153 - Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- [LeetCode 154 - Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
- [LeetCode 287 - Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

## Notes

- **Array Manipulation:** Important skill for in-place operations
- **Binary Search Adaptation:** Key for modified search problems
- **Duplicate Handling:** Critical for arrays with repeated elements
- **Space Optimization:** O(1) space requirements common in interviews
- **Edge Cases:** Handle various boundary conditions
- **Algorithm Efficiency:** Choose appropriate approach based on constraints
- **Memory Management:** Consider space complexity for large inputs
- **Search Space Reduction:** Efficient binary search implementation

## Sample Usage

### Running Remove Duplicates II:

```bash
g++ -o remove_duplicates_ii Leetcode_80.cpp
./remove_duplicates_ii
```

### Testing Rotated Array Search:

```bash
g++ -o rotated_search Leetcode_81.cpp
./rotated_search
```

## Next Steps

- Explore more array manipulation problems
- Practice binary search variations
- Study advanced duplicate handling techniques
- Explore array pattern recognition
- Practice in-place algorithm design
- Study array optimization techniques
- Explore search space reduction methods
- Practice edge case handling
- Study memory-efficient algorithms
- Explore array-based interview problems

## Key Takeaways

1. **Two-Pointer Technique:** Essential for array manipulation
2. **Binary Search Adaptation:** Key for modified search problems
3. **Duplicate Handling:** Critical for arrays with repeated elements
4. **Space Optimization:** O(1) space requirements common
5. **Edge Cases:** Handle various boundary conditions
6. **Algorithm Efficiency:** Choose appropriate approach
7. **Memory Management:** Consider space complexity
8. **Search Space Reduction:** Efficient binary search implementation

## Complexity Analysis

### Remove Duplicates II

- **Time:** O(n) - single pass through array
- **Space:** O(1) - constant extra space
- **Key Insight:** Two-pointer technique with index tracking
- **Strategy:** Allow at most two occurrences of each element

### Search in Rotated Array II

- **Time:** O(log n) average, O(n) worst case with many duplicates
- **Space:** O(1) - constant extra space
- **Key Insight:** Modified binary search with duplicate handling
- **Strategy:** Identify sorted portions and handle duplicates

## Advanced Concepts

1. **Array Manipulation Applications:**

   - Data cleaning and preprocessing
   - Memory-efficient algorithms
   - In-place sorting and filtering
   - Array compression techniques

2. **Binary Search Applications:**

   - Database query optimization
   - Search engine indexing
   - Numerical analysis
   - Game theory algorithms

3. **Optimization Techniques:**
   - Memory-efficient implementations
   - Cache-friendly algorithms
   - Parallel processing opportunities
   - Hardware-specific optimizations

## Resources

- [Two-Pointer Technique](https://leetcode.com/tag/two-pointers/)
- [Binary Search Tutorial](https://www.geeksforgeeks.org/binary-search/)
- [Array Manipulation Problems](https://leetcode.com/tag/array/)
- [Search Problems Collection](https://leetcode.com/tag/binary-search/)

## Test Cases Summary

### Remove Duplicates II Test Cases:

1. Example case: `[1,1,1,2,2,3]` → `5, [1,1,2,2,3]`
2. Another example: `[0,0,1,1,1,1,2,3,3]` → `7, [0,0,1,1,2,3,3]`
3. Single element: `[5]` → `1, [5]`
4. Two elements: `[1,2]` → `2, [1,2]`
5. All same elements: `[3,3,3,3,3]` → `2, [3,3]`
6. No duplicates: `[1,2,3,4,5]` → `5, [1,2,3,4,5]`

### Search in Rotated Array II Test Cases:

1. Target found: `[2,5,6,0,0,1,2]`, target `0` → `true`
2. Target not found: `[2,5,6,0,0,1,2]`, target `3` → `false`
3. Target in rotated portion: `[4,5,6,7,0,1,2]`, target `1` → `true`
4. Target not in array: `[4,5,6,7,0,1,2]`, target `8` → `false`
5. All same elements: `[1,1,1,1,1,1,1]`, target `1` → `true`
6. All same elements, target not found: `[1,1,1,1,1,1,1]`, target `2` → `false`
7. Single element: `[5]`, target `5` → `true`
8. Two elements: `[3,1]`, target `1` → `true`

## Implementation Notes

- **Error Handling:** Validate input arrays and handle edge cases
- **Memory Management:** Efficient use of constant extra space
- **Index Validation:** Ensure indices are within bounds
- **Performance:** Consider optimization for large inputs
- **Output Format:** Consistent array representation for testing
- **Readability:** Clear variable names and comments
- **Maintainability:** Modular code structure for easy modification
- **Testing:** Comprehensive test case coverage

## Common Pitfalls

1. **Remove Duplicates II:**

   - Forgetting to handle arrays with ≤2 elements
   - Incorrect index tracking for valid positions
   - Not preserving relative order of elements
   - Returning wrong length

2. **Search in Rotated Array II:**
   - Not handling duplicates at boundaries properly
   - Incorrect sorted portion identification
   - Missing edge cases with all same elements
   - Inefficient duplicate handling

## Performance Considerations

- **Memory Usage:** Both problems require O(1) space
- **Time Efficiency:** Linear time for duplicates, logarithmic for search
- **Cache Performance:** Sequential access patterns
- **Scalability:** Handle large input arrays efficiently
- **Edge Cases:** Comprehensive boundary condition handling

## Related Topics

- Array manipulation techniques
- Binary search variations
- Two-pointer algorithms
- In-place operations
- Duplicate handling strategies
- Search space optimization
- Memory-efficient algorithms
- Edge case management
- Algorithm optimization
- Interview problem patterns
