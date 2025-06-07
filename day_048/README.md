# Day 48: LeetCode 58 - Length of Last Word

## Problem Description

Given a string `s` consisting of words and spaces, return the length of the last word in the string. A word is a maximal substring consisting of non-space characters only.

## Examples

1. Input: s = "Hello World"

   - Output: 5
   - Explanation: Last word is "World" with length 5

2. Input: s = " fly me to the moon "

   - Output: 4
   - Explanation: Last word is "moon" with length 4

3. Input: s = "luffy is still joyboy"
   - Output: 6
   - Explanation: Last word is "joyboy" with length 6

## Approach

### Algorithm: Reverse Traversal

The solution uses a simple but efficient approach of traversing the string from the end:

1. Start from end of string
2. Skip trailing spaces
3. Count characters until next space or start of string
4. Return the count

### Implementation Details

```cpp
int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    // Skip trailing spaces
    while(i >= 0 && s[i] == ' ') i--;

    int count = 0;
    // Count characters until space or start
    while(i >= 0 && s[i--] != ' ') count++;

    return count;
}
```

### Key Points

1. **Trailing Space Handling**:

   - Skip all trailing spaces first
   - Ensures we start counting from actual word

2. **Boundary Cases**:

   - Check `i >= 0` to avoid array out of bounds
   - Works for strings with leading/trailing spaces

3. **Single Pass**:
   - No need to traverse entire string
   - Only process what's needed from end

### Time and Space Complexity

- **Time Complexity**: O(n)

  - Worst case: traverse entire string once
  - Best case: O(k) where k is length of last word plus trailing spaces

- **Space Complexity**: O(1)
  - Only uses fixed number of variables
  - No extra space required

## Code Structure

1. **Main Function**:

   - Takes string input
   - Returns integer (length of last word)

2. **Helper Variables**:
   - `i`: Current position in string
   - `count`: Length of last word

## Common Edge Cases

1. String with only spaces
2. String with trailing spaces
3. Single word string
4. Empty string (covered by constraint)
5. Single character string

## Notes

- No need for extra string manipulation
- Efficient approach without using additional data structures
- Solution is language-independent
- Works in-place without modifying input

## Real-world Applications

1. Text Processing

   - Word counting in documents
   - Line parsing in file processing
   - Command line argument parsing

2. String Manipulation
   - Input sanitization
   - Text formatting
   - Natural language processing

## Implementation Tips

1. Always check for array bounds
2. Consider space characters carefully
3. Use reverse traversal for efficiency
4. Keep code simple and readable
