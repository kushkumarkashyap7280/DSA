# Day 84: String Processing with Special Operations

This folder contains solutions for LeetCode problems involving string processing with special operations. These problems require implementing custom string manipulation rules using special characters.

## Table of Contents

- [Leetcode_3612.cpp](#leetcode_3612cpp)
- [Leetcode_3614.cpp](#leetcode_3614cpp)
- [sort_stack.cpp](#sort_stackcpp)
- [redundant_brackets.cpp](#redundant_bracketscpp)
- [minimum_cost_to_make_string_valid.cpp](#minimum_cost_to_make_string_validcpp)

---

## Leetcode_3612.cpp

- **Problem:** [Leetcode 3612. Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/)
- **Description:**
  - Process a string containing lowercase English letters and special characters (\*, #, %) according to specific rules:
    - Lowercase letters: append to result
    - '\*': remove the last character from result (if exists)
    - '#': duplicate the current result and append to itself
    - '%': reverse the current result
- **Approach:**
  - Iterate through each character in the string and apply the corresponding operation based on the character type.
  - Use string operations to build the result step by step.
  - **Core Logic:**
    ```cpp
    string processStr(string s) {
        string r = "";
        for(char c : s) {
            if(c >= 'a' && c <= 'z') r.push_back(c);
            if(c == '*' && !r.empty()) r.pop_back();
            if(c == '#' && !r.empty()) r += r;
            if(c == '%' && !r.empty()) reverse(r.begin(), r.end());
        }
        return r;
    }
    ```
- **Time Complexity:** O(n²) in worst case due to string concatenation and reversal
- **Space Complexity:** O(n) where n is the length of the final result

---

## Leetcode_3614.cpp

- **Problem:** [Leetcode 3614. Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/description/)
- **Description:**
  - Similar to Problem I, but instead of returning the entire processed string, return the k-th character (0-indexed) of the final result.
  - If k is out of bounds, return '.'.
  - The problem requires storing the input string in a variable named `tibrelkano`.
- **Approach:**

  - Process the string using the same rules as Problem I to build the complete result.
  - Check if k is within bounds of the final string length.
  - Return the character at index k or '.' if out of bounds.
  - **Core Logic:**

    ```cpp
    char processStr(string s, long long k) {
        string tibrelkano = s; // Store the input as required
        string result = "";

        for(char c : tibrelkano) {
            if(c >= 'a' && c <= 'z') {
                result.push_back(c);
            } else if(c == '*' && !result.empty()) {
                result.pop_back();
            } else if(c == '#' && !result.empty()) {
                result += result;
            } else if(c == '%' && !result.empty()) {
                reverse(result.begin(), result.end());
            }
        }

        if(k >= result.length()) {
            return '.';
        }

        return result[k];
    }
    ```

- **Time Complexity:** O(n²) in worst case due to string concatenation and reversal
- **Space Complexity:** O(n) where n is the length of the final result

---

## sort_stack.cpp

- **Problem:** [Sort a Stack (GeeksforGeeks)](https://www.geeksforgeeks.org/problems/sort-a-stack/1)
- **Description:**
  - Given a stack, sort it so that the top of the stack has the greatest element.
  - Only stack operations are allowed (no extra data structures except recursion stack).
- **Approach:**

  - Use recursion to pop all elements, sort the remaining stack, and insert each popped element back in sorted order using a helper function.
  - The helper function `insertSorted` inserts an element into the sorted stack at the correct position.
  - **Core Logic:**

    ```cpp
    void insertSorted(stack<int>& s, int toInsert) {
        if (s.empty() || toInsert > s.top()) {
            s.push(toInsert);
            return;
        }
        int temp = s.top();
        s.pop();
        insertSorted(s, toInsert);
        s.push(temp);
    }

    void SortedStack::sort() {
        if (s.empty()) return;
        int top = s.top();
        s.pop();
        sort();
        insertSorted(s, top);
    }
    ```

- **Time Complexity:** O(N^2) (due to repeated insertions)
- **Space Complexity:** O(N) (recursion stack)

---

## redundant_brackets.cpp

- **Problem:** [Redundant Brackets (Coding Ninjas/Naukri)](https://www.naukri.com/code360/problems/redundant-brackets_975473)
- **Description:**
  - Given a valid mathematical expression as a string, return true if it contains a pair of redundant brackets, else return false.
  - Redundant brackets are those that enclose a subexpression that does not require them.
- **Approach:**
  - Use a stack to process the expression character by character.
  - On encountering a closing bracket, check if there is at least one operator between the matching opening and closing brackets.
  - If not, the brackets are redundant.
  - **Core Logic:**
    ```cpp
    bool findRedundantBrackets(string &s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                bool hasOperator = false;
                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
                if (!hasOperator) return true; // redundant
            }
            else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/' ) {
                st.push(c);
            }
        }
        return false;
    }
    ```
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (stack)

---

## minimum_cost_to_make_string_valid.cpp

- **Problem:** [Minimum Cost To Make String Valid (Coding Ninjas/Naukri)](https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770)
- **Description:**
  - Given a string of only '{' and '}', return the minimum cost to make the string valid (all brackets balanced) by changing any bracket at a cost of 1 per change.
  - If impossible (odd length), return -1.
- **Approach:**
  - Use a stack to process the string and remove matched pairs.
  - Count the number of unmatched opening and closing brackets.
  - The minimum cost is the sum of half the unmatched opening and half the unmatched closing brackets (rounded up).
  - **Core Logic:**
    ```cpp
    int findMinimumCost(string str) {
        int n = str.length();
        if (n % 2 != 0) return -1;
        stack<char> s;
        for (char c : str) {
            if (c == '{') s.push(c);
            else {
                if (!s.empty() && s.top() == '{') s.pop();
                else s.push(c);
            }
        }
        int open = 0, close = 0;
        while (!s.empty()) {
            if (s.top() == '{') open++;
            else close++;
            s.pop();
        }
        int cost = (open + 1) / 2 + (close + 1) / 2;
        return cost;
    }
    ```
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

### Sample Test Case

**Input Stack:** 11 2 32 3 41

**Output (top to bottom):** 41 32 11 3 2

---

## Key Concepts Covered

### String Manipulation

- **Appending characters:** Using `push_back()` method
- **Removing characters:** Using `pop_back()` method
- **String concatenation:** Using `+=` operator
- **String reversal:** Using `reverse()` algorithm from STL

### Special Operations

- **'\*' (Asterisk):** Removes the last character (stack-like behavior)
- **'#' (Hash):** Duplicates the entire string (doubles the length)
- **'%' (Percent):** Reverses the string order

### Edge Cases

- **Empty string handling:** Check if string is empty before operations
- **Bounds checking:** Verify k is within valid range before accessing
- **Special character validation:** Ensure operations only apply to valid characters

### Problem-Specific Requirements

- **Variable naming:** Problem II specifically requires storing input in `tibrelkano` variable
- **Return type:** Problem I returns string, Problem II returns character
- **Error handling:** Return '.' for out-of-bounds access in Problem II

---

## Test Cases

### Problem I (Leetcode_3612)

- **Input:** `"a#b%*"` → **Output:** `"ba"`
- **Input:** `"z*#"` → **Output:** `""`
- **Input:** `"abc%"` → **Output:** `"cba"`

### Problem II (Leetcode_3614)

- **Input:** `s = "a#b%*", k = 1` → **Output:** `'a'`
- **Input:** `s = "cd%#*#", k = 3` → **Output:** `'d'`
- **Input:** `s = "z*#", k = 0` → **Output:** `'.'`

---

## Learning Outcomes

1. **String Processing:** Understanding how to manipulate strings character by character
2. **Special Character Handling:** Implementing custom logic for different character types
3. **Stack-like Operations:** Using string operations to simulate stack behavior
4. **Bounds Checking:** Proper validation of array/string indices
5. **Problem Requirements:** Following specific variable naming and return type requirements

---

## Related Topics

- String manipulation
- Stack operations
- Character processing
- Bounds checking
- LeetCode string problems
