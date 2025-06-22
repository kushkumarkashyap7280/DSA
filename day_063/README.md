# Day 63 - Recursion: String and Sorting Problems

This day covers classic recursion problems involving strings and arrays:

## 1. Reverse a String (Recursion)

- **LeetCode:** [Reverse String (344)](https://leetcode.com/problems/reverse-string/)
- **Approach:** Swap characters from both ends, recursively move towards the center.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) (recursion stack)
- **Edge Cases:** Empty string, single character.

## 2. Check if Binary Representation is Palindrome

- **Approach:** Convert number to binary string, reverse it recursively, compare with original.
- **Time Complexity:** O(log n) (binary conversion) + O(n) (reverse)
- **Space Complexity:** O(n)
- **Edge Cases:** 0, 1, numbers with leading zeros in binary.

## 3. Power Calculation (a^n) Using Recursion

- **LeetCode:** [Pow(x, n) (50)](https://leetcode.com/problems/powx-n/)
- **Approach:** Multiply `a` recursively `n` times, using accumulator for tail recursion.
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)
- **Edge Cases:** n = 0 (should return 1), negative exponents (not handled in this code).



## Example Usage

```cpp
// Reverse a string
string s = "Hello World";
string reversed = reverseStr(s, s.length() - 1);

// Check binary palindrome
long long number = 9;
bool isPal = checkPalindrome(number);

// Power calculation
long long result = power(2, 10);


```

## Key Points

- Recursion is powerful for problems with repeated substructure.
- Always define clear base cases to avoid infinite recursion.
- Recursion can be less efficient than iteration for some problems due to stack usage.
