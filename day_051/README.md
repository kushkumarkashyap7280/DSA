# Day 51: LeetCode 3442 - Maximum Difference Between Even and Odd Frequency

## Problem Analysis

### Problem Statement

Given a string `s` of lowercase English letters, find the maximum difference `diff = freq(a1) - freq(a2)` between the frequencies of two characters where:

- a1 has an odd frequency
- a2 has an even frequency

### Constraints

- 3 ≤ s.length ≤ 100
- Only lowercase English letters
- At least one odd and one even frequency character present

## Solution Approach

### Algorithm: Frequency Analysis

The solution uses a frequency counting approach with these steps:

1. Count frequencies of all characters
2. Find maximum odd frequency
3. Find minimum even frequency
4. Return their difference

### Implementation Details

```cpp
int maxDifference(string s) {
    // Initialize frequency array for 26 letters
    int freq[26] = {0};

    // Count frequencies
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find max odd and min even frequencies
    int maxOdd = 0;
    int minEven = INT_MAX;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {          // Odd frequency
            maxOdd = max(maxOdd, freq[i]);
        } else if (freq[i] > 0) {        // Even frequency
            minEven = min(minEven, freq[i]);
        }
    }

    return maxOdd - minEven;
}
```

### Key Points

1. **Frequency Counting**:

   - Use array indexed by (char - 'a')
   - Handles all lowercase letters efficiently

2. **Odd/Even Check**:

   - Use modulo operator (% 2)
   - Keep track of maximum odd
   - Keep track of minimum even

3. **Result Calculation**:
   - Simple subtraction of found values
   - Guaranteed valid by problem constraints

## Complexity Analysis

### Time Complexity: O(n)

- One pass through string: O(n)
- One pass through frequency array: O(1) [constant 26]
- Overall: O(n)

### Space Complexity: O(1)

- Fixed size array of 26 elements
- Independent of input size
- Constant extra space

## Test Cases

### Example 1

```
Input: s = "aaaaabbc"
Output: 3
Explanation:
- 'a' has odd frequency 5
- 'b' has even frequency 2
- Maximum difference is 5 - 2 = 3
```

### Example 2

```
Input: s = "abcabcab"
Output: 1
Explanation:
- 'a' has odd frequency 3
- 'c' has even frequency 2
- Maximum difference is 3 - 2 = 1
```

## Edge Cases

1. **Minimum Length**:

   - String of length 3
   - One odd, one even frequency required

2. **Maximum Length**:

   - String of length 100
   - Handle large frequency counts

3. **Special Cases**:
   - Single character with odd frequency
   - Multiple characters with same frequency
   - All characters except one with even frequency

## Code Organization

1. **Frequency Array**:

   - Fixed size array for lowercase letters
   - Index calculation using ASCII values

2. **Main Logic**:
   - Frequency counting
   - Odd/Even separation
   - Maximum difference calculation

## Common Pitfalls

1. **Array Indexing**:

   - Remember to subtract 'a' for correct index
   - Check array bounds

2. **Frequency Checks**:

   - Don't count zero frequencies
   - Consider only positive even frequencies

3. **Integer Limits**:
   - Handle potential overflow
   - Initialize min/max values appropriately

## Real-world Applications

1. **Text Analysis**:

   - Character frequency analysis
   - Pattern recognition
   - Text compression

2. **Data Processing**:
   - Frequency distribution
   - Statistical analysis
   - Anomaly detection

## Implementation Tips

1. Use frequency array for efficient counting
2. Check both odd and even frequencies
3. Consider only non-zero frequencies
4. Handle edge cases properly
5. Verify answer satisfies constraints

## Related Problems

1. Valid Anagram (LeetCode 242)
2. First Unique Character (LeetCode 387)
3. Sort Characters By Frequency (LeetCode 451)
