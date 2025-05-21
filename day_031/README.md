# Day 31: String Compression

## Problem: String Compression [LeetCode 443](https://leetcode.com/problems/string-compression)

### Problem Description

Given an array of characters `chars`, compress it in-place using the following rules:

- For each group of consecutive repeating characters:
  - If group length is 1, append only the character
  - Otherwise, append the character followed by the group's length
- Return the new length of the compressed array

### Examples:

```
Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Compressed array: ["a","2","b","2","c","3"]
Explanation: Groups "aa", "bb", "ccc" compress to "a2b2c3"

Input: chars = ["a"]
Output: 1
Explanation: Single character "a" remains uncompressed
```

### Approaches

#### 1. Two-Pointer Approach (Optimal)

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Use two pointers:
     - `write`: where to write next character
     - `read`: current character being read
  2. For each character:
     - Count consecutive occurrences
     - Write character at write position
     - If count > 1, write count digits
     - Update write position accordingly

```cpp
int compress(vector<char>& chars) {
    int write = 0, read = 0;
    while (read < chars.size()) {
        char current = chars[read];
        int count = 0;

        // Count consecutive characters
        while (read < chars.size() && chars[read] == current) {
            read++;
            count++;
        }

        // Write character
        chars[write++] = current;

        // Write count if > 1
        if (count > 1) {
            for (char c : to_string(count)) {
                chars[write++] = c;
            }
        }
    }
    return write;
}
```

#### 2. Using Temporary Array (Initial Approach)

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Algorithm**:
  1. Create temporary vector to store compressed result
  2. Track current character and its count
  3. When character changes or end reached:
     - Add character to result
     - If count > 1, add count digits
  4. Copy back to original array

```cpp
int compress(vector<char>& chars) {
    vector<char> temp;
    char current = chars[0];
    int count = 0;

    for (int j = 0; j <= chars.size(); ++j) {
        if (j < chars.size() && chars[j] == current) {
            count++;
        } else {
            temp.push_back(current);
            if (count > 1) {
                for (char c : to_string(count)) {
                    temp.push_back(c);
                }
            }
            if (j < chars.size()) {
                current = chars[j];
                count = 1;
            }
        }
    }
    chars = temp;
    return chars.size();
}
```

### Key Points

1. **In-place Modification**:

   - Optimal solution modifies array directly
   - No extra space needed except for count conversion

2. **Two-pointer Technique**:

   - Read pointer tracks current group
   - Write pointer manages compressed result position
   - Ensures in-place modification

3. **Handling Numbers**:
   - Numbers > 9 need multiple digits
   - Convert count to string for digit-by-digit writing
   - Each digit occupies one position in result

### Constraints

- 1 ≤ chars.length ≤ 2000
- chars[i] can be lowercase letter, uppercase letter, digit, or symbol

### Source

[LeetCode 443 - String Compression](https://leetcode.com/problems/string-compression)
