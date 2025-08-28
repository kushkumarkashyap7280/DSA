#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 14. Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/

/*
Problem:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Approach 1 (Character-by-Character Comparison):
1. Take the first string as the initial prefix
2. Compare each character of this prefix with the corresponding character in all other strings
3. If any mismatch or end of string is found, truncate the prefix at that position
4. Return the final prefix

Approach 2 (Using Trie Data Structure):
1. Build a trie with all strings in the array
2. Start from the root and traverse down
3. At each level, if there is only one child, add that character to the result
4. If there are multiple children or a terminal node, stop the traversal
5. Return the collected characters as the common prefix

Time Complexity:
- Approach 1: O(S) where S is the sum of all characters in all strings
- Approach 2: O(S) for building the trie + O(m) for finding LCP, where m is the length of the shortest string

Space Complexity:
- Approach 1: O(1) constant space
- Approach 2: O(S) for storing the trie
*/

struct TrieNode
{
  char c;
  vector<TrieNode *> children;
  bool isTerminal;

  TrieNode(char c)
  {
    this->c = c;
    this->children = vector<TrieNode *>(26, nullptr); // initialize children
    this->isTerminal = false;
  }
};

class Trie
{
  TrieNode *root;

  // Helper function to insert a string into the trie
  void insertionUtil(TrieNode *root, string &s, int i)
  {
    if (i >= s.length())
    {
      root->isTerminal = true;
      return;
    }

    TrieNode *child = nullptr;
    int index = tolower(s[i]) - 'a';

    if (root->children[index])
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(s[i]);
      root->children[index] = child;
    }

    insertionUtil(child, s, i + 1);
  }

  // Helper function to find the longest common prefix
  void getLCPUtil(TrieNode *root, string &s)
  {
    // Stop if we reach null or a terminal node
    if (!root || root->isTerminal)
      return;

    int count = 0;
    TrieNode *onlyChild = nullptr;

    // Check if there is only one child at this node
    for (auto node : root->children)
    {
      if (node)
      {
        count++;
        onlyChild = node;
      }
    }

    // If there's only one path forward, add to the prefix
    if (count == 1)
    {
      s.push_back(onlyChild->c);
      getLCPUtil(onlyChild, s);
    }
  }

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  // Insert a string into the trie
  void insertion(string s)
  {
    return insertionUtil(root, s, 0);
  }

  // Get the longest common prefix
  string getLCP()
  {
    string ans;
    getLCPUtil(root, ans);
    return ans;
  }
};

class Solution
{
public:
  // Approach 1: Character-by-Character Comparison
  string longestCommonPrefix_approach1(vector<string> &strs)
  {
    if (strs.empty())
      return "";

    string ans = strs[0];
    for (int i = 0; i < ans.size(); i++)
    {
      for (int j = 0; j < strs.size(); j++)
      {
        if (i >= strs[j].size() || strs[j][i] != ans[i])
        {
          return ans.substr(0, i);
        }
      }
    }
    return ans;
  }

  // Approach 2: Using Trie Data Structure
  string longestCommonPrefix(vector<string> &strs)
  {
    // Handle edge case of empty input
    if (strs.empty())
      return "";

    // Special case: if any string is empty, return empty string
    for (const string &s : strs)
    {
      if (s.empty())
        return "";
    }

    Trie t;
    // Insert all strings into the trie
    for (string &s : strs)
    {
      t.insertion(s);
    }

    // Get the longest common prefix
    return t.getLCP();
  }
};