#include <bits/stdc++.h>
using namespace std;

// 1268. Search Suggestions System
// Link: https://leetcode.com/problems/search-suggestions-system/

/*
Problem:
You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character
of searchWord is typed. Suggested products should have common prefix with searchWord.
If there are more than three products with a common prefix return the three lexicographically
minimums products.

Approach:
1. Build a Trie with all products
2. For each prefix of the searchWord:
   a. Navigate to the corresponding node in the Trie
   b. Perform DFS from that node to collect up to 3 lexicographically smallest products
   c. Add the suggestions to the result

Alternative Approach (not implemented here):
1. Sort the products lexicographically
2. For each prefix of searchWord, find all products that start with this prefix
3. Return the first 3 (or fewer) matches

Time Complexity:
- Building the Trie: O(L) where L is the total length of all products
- Finding suggestions: O(len(searchWord) * S) where S is the max time to find 3 suggestions
  via DFS (bounded by the length of the longest product)
- Overall: O(L + len(searchWord) * S)

Space Complexity:
- O(L) for the Trie structure, where L is total length of all products
*/

// Trie Node structure
struct TrieNode
{
  TrieNode *children[26];
  bool isTerminal;

  TrieNode()
  {
    isTerminal = false;
    for (auto &child : children)
      child = nullptr;
  }
};

// Trie class for prefix-based search
class Trie
{
  TrieNode *root;

  // Helper function to insert a string into the trie
  void insertionUtil(TrieNode *node, const string &s, int i)
  {
    if (i == s.size())
    {
      node->isTerminal = true;
      return;
    }

    int index = s[i] - 'a';
    if (!node->children[index])
      node->children[index] = new TrieNode();

    insertionUtil(node->children[index], s, i + 1);
  }

  // DFS to collect up to 3 suggestions from current node in lexicographical order
  void suggestionUtil(TrieNode *node, vector<string> &res, string &prefix)
  {
    if (res.size() == 3)
      return; // limit to 3 suggestions
    if (node->isTerminal)
      res.push_back(prefix);

    // Explore children in lexicographical order (a to z)
    for (char c = 'a'; c <= 'z'; c++)
    {
      TrieNode *next = node->children[c - 'a'];
      if (next)
      {
        prefix.push_back(c);
        suggestionUtil(next, res, prefix);
        prefix.pop_back(); // backtrack
      }
    }
  }

public:
  Trie()
  {
    root = new TrieNode();
  }

  // Insert a product into the trie
  void insert(const string &s)
  {
    insertionUtil(root, s, 0);
  }

  // Get suggestions for each prefix of searchWord
  vector<vector<string>> getSuggestions(const string &searchWord)
  {
    TrieNode *node = root;
    vector<vector<string>> ans;
    string prefix = "";

    for (char c : searchWord)
    {
      prefix.push_back(c);

      // Move to the next node in the trie
      if (node)
        node = node->children[c - 'a'];

      vector<string> temp;
      if (node)
        suggestionUtil(node, temp, prefix);
      ans.push_back(temp);
    }

    return ans;
  }
};

class Solution
{
public:
  vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
  {
    // Alternative approach (not using Trie):
    // sort(products.begin(), products.end());
    // For each prefix, binary search for first matching product
    // Then collect up to 3 consecutive products that match the prefix

    // Using Trie approach for efficient prefix search
    Trie trie;
    for (const string &product : products)
      trie.insert(product);

    return trie.getSuggestions(searchWord);
  }
};
