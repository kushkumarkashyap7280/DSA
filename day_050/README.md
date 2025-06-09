# Day 50: LeetCode 67 - Add Binary

## Problem Analysis

### Problem Statement

Given two binary strings `a` and `b`, return their sum as a binary string. The strings contain only '0' or '1' characters.

### Constraints

- 1 ≤ a.length, b.length ≤ 10⁴
- Strings only contain '0' or '1'
- No leading zeros except for zero itself

## Solution Approach

### Algorithm: Digit-by-Digit Addition

The solution uses a straightforward approach similar to how we add binary numbers by hand:

1. Start from rightmost digits
2. Add digits and carry
3. Keep track of carry for next position
4. Build result string in reverse
5. Finally reverse the string

### Implementation Details

```cpp
string addBinary(string a, string b) {
    string ans = "";
    int i = a.size() - 1;  // Rightmost index of first string
    int j = b.size() - 1;  // Rightmost index of second string
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // Add digit from first string if available
        if (i >= 0) sum += a[i--] - '0';

        // Add digit from second string if available
        if (j >= 0) sum += b[j--] - '0';

        // Add digit to result and update carry
        ans.push_back('0' + sum % 2);
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
```

### Key Points

1. **Character to Integer Conversion**:

   - Using `char - '0'` to convert character to integer
   - Using `'0' + value` to convert back to character

2. **Carry Handling**:
   - `sum % 2` gives current digit
   - `sum / 2` gives carry for next position
3. **Result Building**:
   - Build string in reverse
   - Reverse once at end for final result

## Complexity Analysis

### Time Complexity: O(max(m,n))

- m, n are lengths of input strings
- One pass through the longer string
- Final reverse operation is O(max(m,n))

### Space Complexity: O(max(m,n))

- Result string length is at most max(m,n) + 1
- No other significant space usage

## Test Cases

### Example 1

```
Input: a = "11", b = "1"
Output: "100"
```

### Example 2

```
Input: a = "1010", b = "1011"
Output: "10101"
```

## Edge Cases

1. **Different Lengths**:

   - One string longer than other
   - Handle missing digits as 0

2. **Carry Propagation**:

   - Multiple consecutive carries
   - Carry at most significant digit

3. **Special Cases**:
   - Empty strings (covered by constraints)
   - Single digit strings
   - All ones (maximum carry propagation)

## Code Structure

1. **Variable Setup**:

   - Result string
   - Position pointers
   - Carry tracker

2. **Main Loop**:

   - Process until all digits and carry handled
   - Build result in reverse

3. **Final Processing**:
   - Reverse result string
   - Return final answer

## Common Pitfalls

1. **String Processing**:

   - Remember to convert characters to integers
   - Handle string indices carefully

2. **Loop Condition**:

   - Continue while any string has digits
   - Don't forget about remaining carry

3. **Result Building**:
   - Build in reverse for efficiency
   - Remember final reverse step

## Real-world Applications

1. **Digital Systems**:

   - Binary arithmetic units
   - Digital circuit simulation
   - Computer architecture

2. **String Processing**:
   - Numerical string operations
   - Base conversion problems
   - Calculator implementations

## Related Problems

1. Add Strings (LeetCode 415)
2. Add Two Numbers (LeetCode 2)
3. Multiply Strings (LeetCode 43)

## Implementation Tips

1. Use character arithmetic for digit conversion
2. Process strings from right to left
3. Handle carry properly
4. Consider building result in reverse
5. Test with strings of different lengths
