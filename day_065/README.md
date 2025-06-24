# Day 65 - Quick Sort and Excel Sheet Column Number

## 1. Quick Sort using Recursion ([LeetCode 912](https://leetcode.com/problems/sort-an-array/))

This file demonstrates the implementation of the Quick Sort algorithm using recursion.

### Approach

- Select the first element as the pivot.
- Count how many elements are less than the pivot to determine its correct position (pivot index).
- Place the pivot at its correct position.
- Partition the array so that all elements less than the pivot are on the left, and all greater or equal are on the right.
- Recursively apply the same process to the left and right subarrays.

### Time Complexity

- Average: O(n log n)
- Worst-case: O(n^2) (when the array is already sorted or reverse sorted and the first element is always chosen as pivot)

### Space Complexity

- O(log n) (recursion stack)

### Edge Cases

- Array with all equal elements
- Already sorted or reverse sorted array
- Array with one or zero elements

### Example Usage

```cpp
vector<int> arr = {10, 7, 8, 9, 1, 5};
quickSort(arr, 0, arr.size() - 1);
// Output: 1 5 7 8 9 10
```

---

## 2. Excel Sheet Column Number ([LeetCode 171](https://leetcode.com/problems/excel-sheet-column-number/))

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

### Approach

- Treat the string as a base-26 number, where 'A' = 1, 'B' = 2, ..., 'Z' = 26.
- For each character, multiply the current result by 26 and add the value of the character.

### Time Complexity

- O(n), where n is the length of the string.

### Space Complexity

- O(1)

### Example Usage

```cpp
cout << titleToNumber("A") << endl;  // Output: 1
cout << titleToNumber("AB") << endl; // Output: 28
cout << titleToNumber("ZY") << endl; // Output: 701
```
