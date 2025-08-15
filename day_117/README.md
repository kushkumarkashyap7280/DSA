# Day 117 - Arrays: Cycle Detection Trick (Find the Duplicate Number)

This day focuses on the classic Floyd's Tortoise and Hare application on arrays by modeling indices as pointers.

## 📄 Problem
- Title: 287. Find the Duplicate Number
- Link: https://leetcode.com/problems/find-the-duplicate-number/
- Difficulty: Medium

Given an array `nums` of length `n + 1` with values in `[1, n]`, exactly one number appears at least twice. Return that duplicate without modifying the array, using O(1) extra space, and in O(n) time.

## ✅ Approach
- Model the array as a linked list where `next(i) = nums[i]`.
- The duplicate value creates a cycle.
- Use Floyd's Tortoise and Hare:
  - Phase 1: Find a meeting point inside the cycle using slow/fast pointers.
  - Phase 2: Move one pointer to start; advance both by one until they meet at the cycle entrance (the duplicate).

## ⏱️ Complexity
- Time: O(n)
- Space: O(1)

## 🧪 Test Coverage (in code)
- Example cases from LeetCode
- All-same values (valid by constraints)
- Mixed distribution with a later duplicate

## 📁 Files
- `Leetcode_287.cpp` — Full solution with explanation comments and a small test harness.

## ▶️ Build & Run
Using g++ (MinGW/Clang):

```bash
# From repo root or this folder
g++ -std=c++17 day_117/Leetcode_287.cpp -o day_117/Leetcode_287.exe && day_117/Leetcode_287.exe
```

On Linux/macOS, replace the last part with `./day_117/Leetcode_287`.

## 🔑 Key Concepts
- Cycle detection in arrays via index-as-pointer
- Constant-space duplicate detection
- Floyd's Tortoise and Hare

## References
- LeetCode 287: Find the Duplicate Number
