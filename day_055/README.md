# Day 55: LeetCode 14 - Longest Common Prefix

## Problem Analysis

### Problem Statement

Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

### Constraints

- 1 ≤ strs.length ≤ 200
- 0 ≤ strs[i].length ≤ 200
- Strings consist of only lowercase English letters

## Solution Approach

### Algorithm: Character-by-Character Comparison

The solution uses a vertical scanning approach:

1. Take first string as reference
2. Compare each character with corresponding positions in other strings
3. Stop when mismatch found or string ends

### Implementation Details

```cpp
string longestCommonPrefix(vector<string>& strs) {
    string temp = strs[0];  // Reference string

    // Iterate through each character of first string
    for(int i = 0; i < temp.size(); i++) {
        // Compare with same position in other strings
        for(int j = 0; j < strs.size(); j++) {
            if(strs[j].size() <= i || strs[j][i] != temp[i]) {
                return temp.substr(0, i);
            }
        }
    }
    return temp;
}
```

### Key Points

1. **Reference String**:

   - Use first string as baseline
   - Compare others against it
   - Handle empty array case

2. **Early Termination**:

   - Stop at first mismatch
   - Stop if string ends
   - Return accumulated prefix

3. **Substring Extraction**:
   - Use substr() for result
   - Include characters up to mismatch
   - Handle full match case

## Complexity Analysis

### Time Complexity: O(n \* m)

- n = number of strings
- m = length of shortest string
- Need to check each character of each string

### Space Complexity: O(1)

- Only storing prefix string
- No additional data structures
- Space independent of input size

## Test Cases

### Example 1

```
Input: strs = ["flower","flow","flight"]
Output: "fl"
Explanation: First two characters match in all strings
```

### Example 2

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: No common prefix exists
```

## Edge Cases

1. **Empty Array**:

   - Handle empty input array
   - Return empty string

2. **Single String**:

   - Return the string itself
   - No comparison needed

3. **Empty String**:

   - String of length 0 in array
   - Return empty string

4. **Different Lengths**:
   - Strings of varying lengths
   - Stop at shortest string

## Code Structure

1. **Input Processing**:

   - Handle empty array case
   - Get reference string

2. **Character Comparison**:

   - Double loop structure
   - Position and string iteration

3. **Result Generation**:
   - Substring extraction
   - Return appropriate prefix

## Common Pitfalls

1. **Array Bounds**:

   - Check string lengths
   - Handle index limits

2. **String Comparison**:

   - Compare same positions
   - Handle string endings

3. **Empty Cases**:
   - Empty array
   - Empty strings in array

## Real-world Applications

1. **File Systems**:

   - Finding common path prefixes
   - Directory organization
   - File name grouping

2. **Search Systems**:
   - Auto-completion
   - Search suggestions
   - Pattern matching

## Implementation Tips

1. Check array bounds carefully
2. Use string functions efficiently
3. Consider early termination
4. Handle edge cases first
5. Use clear variable names

## Related Problems

1. Implement Trie (LeetCode 208)
2. Add and Search Word (LeetCode 211)
3. Word Search II (LeetCode 212)

## Alternative Approaches

### 1. Horizontal Scanning

```cpp
// Compare strings two at a time
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        while(strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length()-1);
            if(prefix.empty()) return "";
        }
    }
    return prefix;
}
```

### 2. Binary Search Approach

```cpp
// Use binary search on string length
// More complex but can be faster for very long strings
```

### 3. Divide and Conquer

```cpp
// Recursively solve for smaller subsets
// Combine results to get final answer
```
