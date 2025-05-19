# Day 29: String Word Reversal

## LeetCode 151: Reverse Words in a String

### Problem Description

- Reverse the order of words in a string
- Words are separated by spaces
- Remove extra spaces between words
- Remove leading/trailing spaces

### Solution Approach

1. Start from the end of string
2. Skip trailing spaces
3. For each word:
   - Find word boundaries
   - Extract word using substring
   - Add to result with proper spacing
4. Continue until start of string

### Time & Space Complexity

- Time: O(n) - Single pass through string
- Space: O(n) - For storing result string

### Example

```
Input: "  hello   world  "
Output: "world hello"

Process:
1. Skip trailing spaces
2. Find "world"
3. Add to result
4. Find "hello"
5. Add with space
```

### Edge Cases Handled

- Multiple spaces between words
- Leading/trailing spaces
- Single word
- Empty string
