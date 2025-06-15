# Day 56: LeetCode 3 - Longest Substring Without Repeating Characters

## Problem Analysis

### Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

### Constraints

- 0 ≤ s.length ≤ 5 \* 10⁴
- String consists of English letters, digits, symbols and spaces

## Solution Approaches

### 1. Basic Approach (Initial Solution)

```cpp
int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s == " ") return 1;

    int maxLen = 0;
    string subs = "";
    for (int i = 0; i < s.length(); i++) {
        size_t pos = subs.find(s[i]);
        if (pos != string::npos) {
            subs = subs.substr(pos + 1);
        }
        subs.push_back(s[i]);
        maxLen = max(maxLen, (int)subs.size());
    }
    return maxLen;
}
```

#### Complexity

- Time: O(n²) - string search operations
- Space: O(n) - storing substring

### 2. Optimal Approach (Sliding Window)

```cpp
int lengthOfLongestSubstringOptimal(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (charIndexMap.find(s[i]) != charIndexMap.end()) {
            start = max(start, charIndexMap[s[i]] + 1);
        }
        charIndexMap[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}
```

#### Complexity

- Time: O(n) - single pass
- Space: O(min(n,m)) - where m is character set size

## Implementation Details

### Sliding Window Technique

1. Use map to store character positions
2. Maintain window start position
3. Update window on finding duplicates
4. Track maximum length seen

### Key Points

1. **Character Tracking**:

   - Use hash map for O(1) lookups
   - Store most recent position

2. **Window Management**:

   - Update start on duplicate
   - Maximize window size
   - Handle overlapping cases

3. **Length Calculation**:
   - Current position - start + 1
   - Update maximum seen

## Test Cases

### Example 1

```
Input: s = "abcabcbb"
Output: 3
Explanation: "abc" is longest non-repeating substring
```

### Example 2

```
Input: s = "bbbbb"
Output: 1
Explanation: "b" is longest non-repeating substring
```

### Example 3

```
Input: s = "pwwkew"
Output: 3
Explanation: "wke" is longest non-repeating substring
```

## Edge Cases

1. **Empty String**:

   - Return 0
   - Handle as special case

2. **Single Character**:

   - Return 1
   - No duplicates possible

3. **All Same Characters**:

   - Return 1
   - Simple case

4. **Space Character**:
   - Handle like any other char
   - Consider as valid character

## Optimization Techniques

1. **Hash Map Usage**:

   - Use unordered_map for O(1)
   - Store only needed info

2. **Window Management**:

   - Avoid unnecessary checks
   - Optimize start updates

3. **Early Returns**:
   - Handle special cases first
   - Reduce unnecessary processing

## Common Pitfalls

1. **Index Management**:

   - Off-by-one errors
   - Window boundaries

2. **Character Set**:

   - All ASCII vs specific set
   - Space character handling

3. **Substring vs Subsequence**:
   - Must be continuous
   - Order matters

## Real-world Applications

1. **String Processing**:

   - Pattern detection
   - Data validation
   - Text analysis

2. **Data Streams**:
   - Unique sequence detection
   - Pattern recognition
   - Anomaly detection

## Related Problems

1. Longest Repeating Character Replacement (LeetCode 424)
2. Sliding Window Maximum (LeetCode 239)
3. Minimum Window Substring (LeetCode 76)

## Implementation Tips

1. Use sliding window for efficiency
2. Consider space vs time trade-offs
3. Handle edge cases first
4. Use appropriate data structures
5. Optimize window updates
