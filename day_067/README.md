# Day 67 - Subsequences of String

## Problem 1: Subsequences of String

**Link:** [Naukri Code360 - Subsequences of String](https://www.naukri.com/code360/problems/subsequences-of-string_985087)

### Problem Statement

Given a string, generate all non-empty possible subsequences.

### Approach

- Use backtracking/recursion to explore all possible combinations.
- At each character, decide to include it in the current subsequence or not.
- If the current subsequence is not empty, add it to the answer.
- For each character from the current index, add it to the current subsequence, recurse for the next index, then backtrack (remove the character).

### Time Complexity

- O(2^n \* n), where n is the length of the string (2^n subsequences, each up to length n)

### Space Complexity

- O(n) for the recursion stack
- O(2^n \* n) for storing all subsequences

### Code Example

```cpp
void subsets(string &str, vector<string> &ans, string &current, int index) {
    if (!current.empty()) ans.push_back(current);
    for (int i = index; i < str.size(); i++) {
        current.push_back(str[i]);
        subsets(str, ans, current, i + 1);
        current.pop_back();
    }
}
vector<string> subsequences(string str) {
    vector<string> ans;
    string current;
    subsets(str, ans, current, 0);
    return ans;
}
```

### Edge Cases

- All characters the same (e.g., "bbb")
- Single character string
- Empty string (should return nothing)

### Output Example

For input `abc`, output: `a ab abc ac b bc c`

---

## Related Problem: Subsets (Power Set)

**Link:** [LeetCode 78 - Subsets](https://leetcode.com/problems/subsets/)

Given an array of unique integers, return all possible subsets (the power set).

- Uses similar backtracking/recursion as above, but includes the empty subset.
- Time Complexity: O(n \* 2^n)
- Space Complexity: O(n \* 2^n)

If you add more files/approaches (e.g., subsets for arrays), document them here with links and explanations.
