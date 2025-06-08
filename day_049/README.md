# Day 49: LeetCode 66 - Plus One

## Problem Analysis

### Problem Statement

Given a large integer represented as an array of digits, increment the integer by one and return the resulting array. The digits are ordered from most significant to least significant in left-to-right order.

### Constraints

- 1 ≤ digits.length ≤ 100
- 0 ≤ digits[i] ≤ 9
- No leading zeros in the array

## Solution Approach

### Algorithm

The solution uses a single pass from right to left with carry propagation:

1. Start from rightmost digit
2. If digit < 9: increment and return
3. If digit = 9: set to 0 and continue
4. If reached start: insert 1 at beginning

### Implementation Details

```cpp
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Start from last digit
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;        // Increment and done
            return digits;
        }
        digits[i] = 0;         // Set to 0 and carry forward
    }

    // All 9s case
    digits.insert(digits.begin(), 1);
    return digits;
}
```

### Key Optimizations

1. **Early Return**:

   - Return immediately when no carry needed
   - Avoids unnecessary iterations

2. **In-place Modification**:

   - Modifies array in-place when possible
   - Only creates new space for all 9s case

3. **Efficient Carry Handling**:
   - No need to track carry explicitly
   - Uses digit value to determine carry

## Time and Space Complexity

### Time Complexity: O(n)

- Best Case: O(1) when last digit < 9
- Worst Case: O(n) for all 9s
- Average Case: O(1) as most numbers don't have long carry chains

### Space Complexity: O(1)

- In most cases, modifies array in-place
- O(n) only when new digit needed (all 9s case)

## Test Cases

### Example 1

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: 123 + 1 = 124
```

### Example 2

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: 4321 + 1 = 4322
```

### Example 3

```
Input: digits = [9]
Output: [1,0]
Explanation: 9 + 1 = 10
```

## Edge Cases

1. **Single Digit**:

   - Input: [0] → Output: [1]
   - Input: [9] → Output: [1,0]

2. **All Nines**:

   - Input: [9,9,9] → Output: [1,0,0,0]
   - Requires array expansion

3. **No Carry Required**:
   - Input: [1,2,3] → Output: [1,2,4]
   - Simple increment

## Code Organization

1. **Main Function**:

   - Takes vector input
   - Returns modified/new vector

2. **Algorithm Flow**:
   - Right to left iteration
   - Carry propagation
   - Array expansion if needed

## Common Pitfalls

1. **Array Bounds**:

   - Check bounds when iterating
   - Handle array expansion correctly

2. **Carry Propagation**:

   - Ensure proper carry handling
   - Consider all 9s case

3. **Memory Management**:
   - Be careful with vector resizing
   - Consider in-place vs new array

## Real-world Applications

1. **Numerical Computing**:

   - Large number arithmetic
   - Calculator implementations
   - Scientific computing

2. **Data Structures**:
   - Counter implementations
   - Version numbering
   - Sequential ID generation

## Implementation Tips

1. Start from the least significant digit
2. Use early return for optimization
3. Handle the all 9s case separately
4. Consider space efficiency
5. Test with various input sizes

## Related Problems

1. Add Two Numbers (LeetCode 2)
2. Plus One Linked List (LeetCode 369)
3. Add to Array-Form of Integer (LeetCode 989)
