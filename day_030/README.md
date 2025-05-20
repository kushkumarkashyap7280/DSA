# Day 30: String Manipulation Problems

## Problem 1: Most Frequent Character

## Problem Description

Given a string `s` of lowercase alphabets, find the maximum occurring character in the string. If more than one character occurs the maximum number of times, return the lexicographically smaller character.

### Examples:

```
Input: s = "testsample"
Output: 'e'
Explanation: 'e' appears twice and is the character which appears most frequently.

Input: s = "output"
Output: 't'
Explanation: Both 't' and 'u' appear once, but 't' is lexicographically smaller.
```

## Approaches

### 1. Brute Force Approach

- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. For each character in the string:
     - Count its occurrences by iterating through the rest of the string
     - Keep track of maximum count seen so far
     - If current count > max count, update result
     - If current count equals max count, take lexicographically smaller character
  2. Return the character with maximum frequency

```cpp
// Code snippet of brute force approach:
char c = 'z';
int count = 0;

for (int i = 0; i < s.size(); i++) {
    int temp_count = 1;
    for (int j = i + 1; j < s.size(); j++) {
        if (s[j] == s[i])
            temp_count++;
    }
    if (temp_count > count) {
        count = temp_count;
        c = s[i];
    }
    else if (temp_count == count && s[i] < c) {
        c = s[i];
    }
}
```

### 2. Optimized Approach using Frequency Array

- **Time Complexity**: O(n)
- **Space Complexity**: O(1) [since array size is fixed at 26]
- **Algorithm**:
  1. Create a frequency array of size 26 (for lowercase letters)
  2. Count frequency of each character in one pass
  3. Find the maximum frequency and corresponding character
  4. Handle lexicographically smaller character when frequencies are equal

```cpp
// Code snippet of optimized approach:
int countArr[26] = {0};
char ans = 'a';

// Count frequency of each character
for (int i = 0; i < s.size(); i++) {
    int index = s[i] - 'a';
    countArr[index]++;
}

int maxi = countArr[0];

for (int i = 1; i < 26; i++) {
    if (countArr[i] > maxi) {
        maxi = countArr[i];
        ans = 'a' + i;
    }
    else if (countArr[i] == maxi && ('a' + i) < ans) {
        ans = 'a' + i;
    }
}
```

## Key Points

1. **ASCII Value Manipulation**:

   - The code uses `s[i] - 'a'` to convert characters to array indices (0-25)
   - `'a' + i` converts index back to character

2. **Lexicographical Ordering**:

   - When frequencies are equal, we choose the lexicographically smaller character
   - This is handled by comparing character values directly

3. **Space Optimization**:
   - We use a fixed-size array of 26 elements for lowercase letters
   - This makes the space complexity O(1) as it's independent of input size

## Constraints

- 1 ≤ |s| ≤ 100
- String contains only lowercase alphabets

## Source

[GeeksforGeeks - Maximum Occurring Character](https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1)

---

## Problem 2: Replace Spaces

### Problem Description

Given a string `str` of words, replace all spaces between words with "@40".

### Examples:

```
Input: str = "Coding Ninjas Is A Coding Platform"
Output: "Coding@40Ninjas@40Is@40A@40Coding@40Platform"

Input: str = "Hello World"
Output: "Hello@40World"
```

### Approaches

#### 1. String Manipulation (erase/insert)

- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Iterate through the string
  2. When a space is found:
     - Erase the space character
     - Insert "@40" at that position
     - Skip the next 3 characters (length of "@40")
  3. Continue until end of string

```cpp
string replaceSpaces(string &str) {
    string a = "@40";
    int i = 0;
    while(i < str.size()) {
        if(str[i] == ' ') {
            str.erase(i, 1);
            str.insert(i, a);
            i += 3;
        } else {
            i++;
        }
    }
    return str;
}
```

#### 2. Optimized Approach using String Building

- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- **Algorithm**:
  1. Create a new result string
  2. Iterate through input string once
  3. For each character:
     - If it's a space, append "@40"
     - If not, append the character as is
  4. Return the result string

```cpp
string replaceSpaces(const string &str) {
    string result;
    for (char ch : str) {
        if (ch == ' ')
            result += "@40";
        else
            result += ch;
    }
    return result;
}
```

### Key Points

1. **String Operations**:

   - First approach uses `erase()` and `insert()` which are O(n) operations
   - Second approach uses string concatenation which is more efficient

2. **Space vs Time Tradeoff**:

   - First approach modifies string in-place but has quadratic time complexity
   - Second approach uses extra space but achieves linear time complexity

3. **Implementation Choice**:
   - For smaller strings, both approaches are acceptable
   - For larger strings, the second approach is significantly faster

### Constraints

- 1 ≤ T ≤ 50 (number of test cases)
- 0 ≤ |STR| ≤ 100 (length of string)

### Source

[Naukri - Replace Spaces](https://www.naukri.com/code360/problems/replace-spaces_1172172)

---

## Problem 3: Remove All Occurrences of a Substring

### Problem Description

Given two strings `s` and `part`, perform the following operation on `s` until all occurrences of the substring `part` are removed:

- Find the leftmost occurrence of the substring `part` and remove it from `s`.
  Return `s` after removing all occurrences of `part`.

### Examples:

```
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation:
- s = "daabcbaabcbc" → "dabaabcbc" (remove "abc" at index 2)
- s = "dabaabcbc" → "dababc" (remove "abc" at index 4)
- s = "dababc" → "dab" (remove "abc" at index 3)

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation:
- s = "axxxxyyyyb" → "axxxyyyb" (remove "xy" at index 4)
- s = "axxxyyyb" → "axxyyb" (remove "xy" at index 3)
- s = "axxyyb" → "axyb" (remove "xy" at index 2)
- s = "axyb" → "ab" (remove "xy" at index 1)
```

### Approach

- **Algorithm**:
  1. Use string's `find()` method to locate the first occurrence of `part`
  2. If found, use `erase()` to remove that occurrence
  3. Repeat until no more occurrences are found
  4. Return the modified string

```cpp
string removeOccurrences(string s, string part) {
    size_t pos = s.find(part);
    while (pos != string::npos) {
        s.erase(pos, part.size());
        pos = s.find(part);
    }
    return s;
}
```

### Analysis

1. **Time Complexity**: O(n \* m)

   - n is the length of string s
   - m is the length of string part
   - Each find operation takes O(n \* m)
   - We might need to do this n/m times in worst case

2. **Space Complexity**: O(1)
   - No extra space is used except for variables
   - Modifications are done in-place

### Key Points

1. **String Methods Used**:

   - `find()`: Finds first occurrence of substring
   - `erase()`: Removes characters from string
   - `string::npos`: Special value indicating "not found"

2. **Implementation Notes**:
   - The solution handles overlapping patterns correctly
   - Processes string from left to right as required
   - Modifies string in-place to save space

### Constraints

- 1 ≤ s.length ≤ 1000
- 1 ≤ part.length ≤ 1000
- s and part consist of lowercase English letters

### Source

[LeetCode 1910 - Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring)

---

## Problem 4: Permutation in String

### Problem Description

Given two strings `s1` and `s2`, determine if `s2` contains a permutation of `s1`. In other words, check if one of `s1`'s permutations is present as a substring in `s2`.

### Examples:

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains a permutation of s1 ("ba")

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

### Approach: Sliding Window with Character Frequency

- **Algorithm**:
  1. Create frequency arrays for both pattern and current window
  2. Initialize first window with characters of s2
  3. Slide window through s2, updating frequencies:
     - Add frequency of new character
     - Remove frequency of character leaving window
     - Compare frequency arrays at each step
  4. Return true if frequencies match at any point

```cpp
bool checkInclusion(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2) return false;

    vector<int> CharArr(26, 0), window(26, 0);

    // Build initial frequency maps
    for (int i = 0; i < len1; ++i) {
        CharArr[s1[i] - 'a']++;
        window[s2[i] - 'a']++;
    }

    if (CharArr == window) return true;

    // Slide the window
    for (int i = len1; i < len2; ++i) {
        window[s2[i] - 'a']++;        // add new char
        window[s2[i - len1] - 'a']--; // remove old char
        if (CharArr == window)
            return true;
    }
    return false;
}
```

### Analysis

1. **Time Complexity**: O(n)

   - n is the length of string s2
   - Each character is processed exactly once
   - Array comparison is O(1) as size is fixed at 26

2. **Space Complexity**: O(1)
   - Uses two fixed-size arrays of size 26
   - Space usage is independent of input size

### Key Points

1. **Window Sliding Technique**:

   - Maintain a fixed-size window equal to length of s1
   - Update character frequencies as window slides
   - Efficient way to check all possible substrings

2. **Character Frequency Matching**:

   - Two strings are permutations if they have same character frequencies
   - Using arrays for O(1) frequency comparison
   - Only lowercase letters, so 26-size array is sufficient

3. **Optimization**:
   - Early return if s1 is longer than s2
   - Direct array comparison instead of character-by-character check
   - No need to generate actual permutations

### Constraints

- 1 ≤ s1.length, s2.length ≤ 10⁴
- Both strings consist of lowercase English letters

### Source

[LeetCode 567 - Permutation in String](https://leetcode.com/problems/permutation-in-string)

---

## Problem 5: Remove Adjacent Duplicates in String

### Problem Description

Given a string `s` consisting of lowercase English letters, implement a duplicate removal process where you choose two adjacent and equal letters and remove them. Repeat this process until no adjacent duplicates remain.

### Examples:

```
Input: s = "abbaca"
Output: "ca"
Explanation:
1. Remove "bb" -> "aaca"
2. Remove "aa" -> "ca"
No more adjacent duplicates can be removed.

Input: s = "azxxzy"
Output: "ay"
```

### Approach: Using Stack

- **Algorithm**:
  1. Use stack to store characters
  2. For each character in string:
     - If stack is not empty and top matches current char:
       - Pop from stack (removes the pair)
     - Else:
       - Push current char to stack
  3. Build final string from stack
  4. Reverse the result (due to LIFO nature of stack)

```cpp
string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // remove the duplicate pair
        } else {
            st.push(c);
        }
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}
```

### Analysis

1. **Time Complexity**: O(n)

   - Each character is processed once
   - Stack operations are O(1)
   - Final string construction and reversal are O(n)

2. **Space Complexity**: O(n)
   - Stack can store up to n characters
   - Additional space for result string

### Key Points

1. **Stack Usage**:

   - Perfect for matching and removing pairs
   - LIFO property helps track adjacent elements
   - Efficient for backtracking operations

2. **String Operations**:
   - Final reverse needed due to stack's LIFO nature
   - Building result string character by character
   - In-place modification not possible due to removals

### Constraints

- 1 ≤ s.length ≤ 10⁵
- s consists of lowercase English letters only

### Source

[LeetCode 1047 - Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string)
