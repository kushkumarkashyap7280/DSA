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

## 4. Insertion Sort Using Recursion

- **LeetCode:** [Sort an Array (912)](https://leetcode.com/problems/sort-an-array/)
- **Approach:** Sort first n-1 elements recursively, insert last element in correct position.
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(n) (recursion stack)
- **Edge Cases:** Already sorted, reverse sorted, all elements equal, single element.

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

// Insertion sort
int arr[] = {5, 2, 9, 1, 5, 6};
recursive_insertion_sort(arr, 6);
```

## Key Points

- Recursion is powerful for problems with repeated substructure.
- Always define clear base cases to avoid infinite recursion.
- Recursion can be less efficient than iteration for some problems due to stack usage.
