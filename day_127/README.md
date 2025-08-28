# Day 127: Longest Common Prefix (LeetCode 14)

## Problem Description

Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

**Examples:**

- Input: strs = ["flower", "flow", "flight"]
  Output: "fl"
- Input: strs = ["dog", "racecar", "car"]
  Output: ""

**Constraints:**

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters.

## Approach 1: Character-by-Character Comparison

This is a straightforward approach where we:

1. Take the first string as our initial prefix
2. Iterate through each character of this prefix
3. For each character, check if it matches with the corresponding character in all other strings
4. If a mismatch is found or we reach the end of any string, we truncate the prefix at that position
5. Return the resulting prefix

**Time Complexity:** O(S) where S is the sum of all characters in all strings
**Space Complexity:** O(1) constant extra space

## Approach 2: Using Trie Data Structure

A Trie (prefix tree) is perfectly suited for this problem:

1. Build a trie with all strings in the array
2. Start from the root and traverse down
3. At each level, if there is only one child, add that character to the result
4. If there are multiple children or we reach a terminal node, stop the traversal
5. Return the collected characters as the common prefix

**Time Complexity:** O(S) for building the trie + O(m) for finding LCP, where m is the length of the shortest string
**Space Complexity:** O(S) for storing the trie

## Implementation Details

In our Trie implementation:

- We use a `TrieNode` structure that stores a character, a boolean flag for terminal nodes, and an array of children (one for each letter)
- The `insertion` method adds a string to the trie
- The `getLCP` method traverses the trie to find the longest common prefix

The Trie-based approach is elegant for this problem because it naturally represents the common prefixes of the strings. The traversal algorithm simply follows the path where there is only one choice until we reach a branching point or the end of a string.

## Key Insights

1. The longest common prefix can't be longer than the shortest string in the array
2. The Trie data structure provides a visual way to think about the problem - the common prefix is the portion before any branching occurs
3. While both approaches have similar time complexity, the Trie approach becomes more efficient when we need to perform multiple operations on the same set of strings

This problem demonstrates how a specialized data structure like Trie can provide a clean solution to string prefix problems.
