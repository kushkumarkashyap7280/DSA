# Day 128: Trie Applications - Prefix Problems

Today's problems focus on prefix-related operations using Trie data structures and string manipulation techniques.

## Problem 1: [1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)

### Problem Description

Design a search autocomplete system that suggests at most three product names from a given array of products after each character of a search word is typed. Suggested products should have a common prefix with the search word, and if there are more than three products with a common prefix, return the three lexicographically smallest products.

### Approach

I implemented a Trie-based solution:

1. Build a Trie with all products
2. For each prefix of the searchWord:
   - Navigate to the corresponding node in the Trie
   - Perform DFS from that node to collect up to 3 lexicographically smallest products
   - Add the suggestions to the result

### Time and Space Complexity

- **Time Complexity**: O(L + |searchWord| \* S), where:
  - L is the total length of all products
  - |searchWord| is the length of the search word
  - S is the time to find 3 suggestions via DFS (bounded by the length of the longest product)
- **Space Complexity**: O(L) for the Trie structure

### Key Insights

- Tries are excellent for prefix-based operations like autocomplete systems
- Using DFS with character-by-character traversal ensures we get lexicographically ordered results
- An alternative approach would be to sort all products and use binary search to find matches for each prefix

## Problem 2: [2185. Counting Words With a Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

### Problem Description

Given an array of strings `words` and a string `pref`, return the number of strings in `words` that contain `pref` as a prefix.

### Approaches

1. **Character-by-character comparison**:

   - For each word, compare each character with the corresponding character in the prefix
   - Count words where all characters match

2. **Using substring method**:

   - For each word, extract a substring of the same length as the prefix
   - Compare this substring with the prefix
   - Count matches

3. **Using C++20's starts_with method**:
   - Use the built-in method to check if each word starts with the prefix
   - Count matches

### Time and Space Complexity

- **Time Complexity**: O(n \* m) where n is the number of words and m is the length of the prefix
- **Space Complexity**: O(1)

### Key Insights

- For simple prefix checking on a small number of words, direct string operations are more efficient than building a Trie
- The substring approach is cleaner and less error-prone than manual character comparison
- Modern language features like `starts_with()` can make code more readable

## Problem 3: [2255. Count Prefixes of a Given String](https://leetcode.com/problems/count-prefixes-of-a-given-string/)

### Problem Description

Given a string array `words` and a string `s`, return the number of strings in `words` that are a prefix of `s`.

### Approaches

1. **Using substring method**:

   - For each word, extract a substring from s with the same length
   - Compare this substring with the word
   - Count matches

2. **Using starts_with method**:

   - Use the built-in method to check if s starts with each word
   - Count matches

3. **Manual character comparison**:
   - For each word, compare each character with the corresponding character in s
   - Count words where all characters match

### Time and Space Complexity

- **Time Complexity**: O(n \* m) where n is the number of words and m is the average length of words
- **Space Complexity**: O(1)

### Key Insights

- This problem is the reverse of Problem 2 - here we check if words are prefixes of s, not if pref is a prefix of words
- The starts_with approach is the most concise solution
- For large numbers of words that share common prefixes, a Trie could be beneficial, but for this problem's constraints, simple string operations are sufficient

## Comparing the Problems

These three problems demonstrate different aspects of prefix operations:

1. **Problem 1**: Building an autocomplete system that finds multiple matching prefixes - best solved with a Trie
2. **Problem 2**: Counting words that start with a given prefix - simple string operations are sufficient
3. **Problem 3**: Counting words that are prefixes of a string - again, simple string operations work well

The choice of approach depends on the problem constraints, the number of operations, and the size of the data. For a real-world autocomplete system with millions of products, a Trie would be essential, while for simple prefix counting on small datasets, direct string operations are more straightforward.
