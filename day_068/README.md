# Day 68: Permutations & Letter Combinations (LeetCode 46 & 17)

## Problems

- [LeetCode 46: Permutations](https://leetcode.com/problems/permutations/)
- [LeetCode 17: Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

---

## 1. Permutations (LeetCode 46)

### Problem Statement
Given an array `nums` of distinct integers, return all possible permutations. You can return the answer in any order.

### Approach
We use **backtracking** to generate all permutations:
- At each recursion level, fix one element at the current position and recursively permute the rest.
- Swap the current element with each element from `start` to the end, recursively call for the next position, and then backtrack (swap back).
- When `start` reaches the end, add the permutation to the result.

#### Code
```cpp
void permute(vector<int> &nums, int start, vector<vector<int>> &result) {
    if (start >= nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}
```

#### Complexity
- **Time:** O(n! * n)
- **Space:** O(n) (recursion stack)

#### Edge Cases
- Single element array: Only one permutation.
- Handles negative numbers and zero naturally.

---

## 2. Letter Combinations of a Phone Number (LeetCode 17)

### Problem Statement
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent (like on a phone keypad).

### Approach
We use **backtracking**:
- Map each digit to its corresponding letters (like a phone keypad).
- For each digit, try all possible letters, recursively build up the current combination.
- When the current combination's length equals the input's length, add it to the result.
- If the input is empty, return an empty list.

#### Code
```cpp
void lc(vector<string> &keypad, string &digits, int index, string current, vector<string> &ans) {
    if (current.size() == digits.size()) {
        ans.push_back(current);
        return;
    }
    string temp = keypad[digits[index] - '0'];
    for (int i = 0; i < temp.size(); i++) {
        current.push_back(temp[i]);
        lc(keypad, digits, index + 1, current, ans);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    lc(keypad, digits, 0, "", ans);
    return ans;
}
```

#### Complexity
- **Time:** O(3^n * 4^m), where n is the number of digits mapping to 3 letters, m to 4 letters
- **Space:** O(n) (recursion stack)

#### Edge Cases
- Empty input: returns an empty list.
- Handles all valid digit strings from 2-9.

---

## Example Outputs

### Permutations
Input: `[1,2,3]`
Output:
```
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```

### Letter Combinations
Input: `"23"`
Output:
```
ad ae af bd be bf cd ce cf
```

---

**See code:** [`leetcode_46.cpp`](./leetcode_46.cpp), [`leetcode_17.cpp`](./leetcode_17.cpp)
