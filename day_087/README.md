## Leetcode 3201: Find the Maximum Length of Valid Subsequence I

**Problem Link:** [Leetcode 3201 - Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/)
**Solution File:** [Leetcode_3201.cpp](./Leetcode_3201.cpp)

**Problem:**
Given an integer array nums, a subsequence sub of nums with length x is called valid if:
(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

**Approach:**

- Try all 4 possible parity patterns (all even, all odd, even-odd-even..., odd-even-odd...)
- For each pattern, iterate through nums and count the maximum valid subsequence length.
- Return the maximum among all patterns.

**Time Complexity:** O(n)
**Space Complexity:** O(1)

**Code Snippet:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        for (int pattern = 0; pattern < 4; ++pattern) {
            int len = 0;
            int expect;
            if (pattern == 0) expect = 0;
            else if (pattern == 1) expect = 1;
            else if (pattern == 2) expect = 0;
            else expect = 1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] % 2 == expect) {
                    len++;
                    if (pattern >= 2) expect ^= 1;
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 1, 1, 2, 1, 2};
    vector<int> nums3 = {1, 3};
    cout << "Input: [1, 2, 3, 4]\nOutput: " << sol.maximumLength(nums1) << endl;
    cout << "Input: [1, 2, 1, 1, 2, 1, 2]\nOutput: " << sol.maximumLength(nums2) << endl;
    cout << "Input: [1, 3]\nOutput: " << sol.maximumLength(nums3) << endl;
    return 0;
}

# Celebrity Problem Solution

This directory contains the solution to the classic **Celebrity Problem** as implemented in [`Celebrity_problem.cpp`](Celebrity_problem.cpp).

## Problem Description
A celebrity is a person who is known to all but does not know anyone at a party. Given a square matrix `mat` (n x n) where `mat[i][j] == 1` means person `i` knows person `j`, find the index of the celebrity (if one exists), otherwise return -1.

- [GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

### Example
```

Input: mat = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person.

````

## Approaches Implemented

### 1. Brute Force Approach (`celebrityBruteForce`)
- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)

```cpp
int celebrityBruteForce(vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        bool isCelebrity = true;
        for (int j = 0; j < mat.size(); j++) {
            if (i == j) continue;
            if (mat[j][i] != 1) {
                isCelebrity = false;
                break;
            }
        }
        if (!isCelebrity) continue;
        for (int j = 0; j < mat[i].size(); j++) {
            if (i == j) continue;
            if (mat[i][j] == 1) {
                isCelebrity = false;
                break;
            }
        }
        if (!isCelebrity) continue;
        return i;
    }
    return -1;
}
````

### 2. Optimal Approach using Stack (`celebrity` - stack version, commented in code)

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

```cpp
int celebrity(vector<vector<int>> &mat) {
    int n = mat.size();
    stack<int> ans;
    for (int i = 0; i < n; i++) ans.push(i);
    while (ans.size() > 1) {
        int person1 = ans.top(); ans.pop();
        int person2 = ans.top(); ans.pop();
        if (mat[person1][person2] != 1) ans.push(person1);
        else ans.push(person2);
    }
    if (ans.empty()) return -1;
    int candidate = ans.top();
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) return -1;
        }
    }
    return candidate;
}
```

### 3. Most Optimal Approach (Two Pointer Elimination, `celebrity` - active version)

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
- This approach first finds a candidate in O(n) time, then verifies in another O(n) pass.

```cpp
int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int candidate = 0;
    for (int i = 1; i < n; i++) {
        if (mat[candidate][i] == 1) {
            candidate = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    }
    return candidate;
}
```

All three approaches are implemented in the same file for comparison and learning purposes. The most optimal approach is the active `celebrity` function in the code.

---

_For more details, see the code and comments in [`Celebrity_problem.cpp`](Celebrity_problem.cpp)._

```

```
