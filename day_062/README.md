# Day 62 - LeetCode 15: 3Sum

## Problem Description

Given an integer array `nums`, return all the unique triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

[Problem Link](https://leetcode.com/problems/3sum/)

## Solution Approach

The solution uses sorting and a two-pointer technique:

1. **Sort the array** to make it easier to skip duplicates and use two pointers.
2. **Iterate** through the array, fixing one element at a time.
3. For each fixed element, use two pointers (`left` and `right`) to find pairs that sum with the fixed element to zero.
4. **Skip duplicates** for both the fixed element and the two pointers to ensure unique triplets.

### Time Complexity

- O(n^2): Outer loop O(n), inner two-pointer scan O(n) per iteration.

### Space Complexity

- O(1) extra (not counting the output), O(n) for sorting.

## Example Test Cases

```cpp
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0,1,1]
Output: []

Input: nums = [0,0,0]
Output: [[0,0,0]]
```

## Key Points

- Sorting is essential for duplicate removal and two-pointer logic.
- Always skip duplicate values for both the fixed index and the two pointers.
- The order of triplets and their elements does not matter.

## Edge Cases

1. No triplet sums to zero (e.g., [0,1,1])
2. All elements are zero (e.g., [0,0,0])
3. Array with less than 3 elements
4. Large input size (up to 3000 elements)

# LeetCode 3582: Generate Tag for Video Caption

## Problem Description

Given a string `caption` representing the caption for a video, generate a valid tag by:

1. Combining all words into a single camelCase string prefixed with '#'
2. Removing all non-English letters except the first '#'
3. Truncating the result to a maximum of 100 characters

[Problem Link](https://leetcode.com/problems/generate-tag-for-video-caption/)

## Solution Approach

- Iterate through the caption, word by word.
- For the first word, add all characters in lowercase.
- For subsequent words, capitalize the first letter and add the rest in lowercase.
- Skip spaces and non-letter characters (except the initial '#').
- Truncate the result to 100 characters if needed.

### Time Complexity

- O(n), where n is the length of the caption.

### Space Complexity

- O(n), for the generated tag string.

## Example Test Cases

```cpp
Input: caption = "Leetcode daily streak achieved"
Output: "#leetcodeDailyStreakAchieved"

Input: caption = "can I Go There"
Output: "#canIGoThere"

Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
```

## Key Points

- Handles leading/trailing/multiple spaces.
- Only English letters are included in the tag (besides the initial '#').
- Truncates to 100 characters if needed.
- Follows camelCase rules for all words after the first.

## Edge Cases

1. Caption with only one long word (truncation).
2. Caption with multiple spaces between words.
3. Caption with non-letter characters (should be removed).
4. Caption with exactly 100 valid tag characters.
