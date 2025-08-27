#include <iostream>
#include <string>
using namespace std;

// 208. Implement Trie (Prefix Tree)
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Problem:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently
store and retrieve keys in a dataset of strings. There are various applications of this
data structure, such as autocomplete and spellchecker.

Implement the Trie class:
- Trie() Initializes the trie object.
- void insert(String word) Inserts the string word into the trie.
- boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
- boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Approach:
1. Create a TrieNode structure with:
   - Character value
   - Array of pointers to child nodes (size 26 for lowercase English letters)
   - Boolean flag to mark end of words
2. Implement the Trie class with:
   - insert: Add each character of the word as nodes in the trie
   - search: Check if the word exists completely in the trie
   - startsWith: Check if the prefix exists in the trie

Time Complexity:
- insert: O(m) where m is the length of the word
- search: O(m) where m is the length of the word
- startsWith: O(m) where m is the length of the prefix

Space Complexity:
- O(n*m) where n is the number of words and m is the average length of words
*/

struct TrieNode
{
  char c;
  TrieNode *children[26];
  bool isTerminalNode;

  TrieNode(char c)
  {
    this->c = c;

    for (int i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }

    isTerminalNode = false;
  }
};

class Trie
{
private:
  TrieNode *root;

  // Helper function to check if a prefix exists
  bool prefixUtil(TrieNode *root, const string &word, int i)
  {
    if (i == word.length())
      return true;

    int index = tolower(word[i]) - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }

    // Recursively check next character
    return prefixUtil(child, word, i + 1);
  }

  // Helper function to check if a word exists
  bool isPresentUtil(TrieNode *root, const string &word, int i)
  {
    if (i == word.length())
      return root->isTerminalNode;

    int index = tolower(word[i]) - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }

    // Recursively check next character
    return isPresentUtil(child, word, i + 1);
  }

  // Helper function to insert a word
  void insertionUtil(TrieNode *root, const string &word, int i)
  {
    if (i == word.length())
    {
      root->isTerminalNode = true;
      return;
    }

    int index = tolower(word[i]) - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[i]);
      root->children[index] = child;
    }

    // Recursively insert next character
    insertionUtil(child, word, i + 1);
  }

public:
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insert(const string &word)
  {
    insertionUtil(root, word, 0);
  }

  bool search(const string &word)
  {
    return isPresentUtil(root, word, 0);
  }

  bool startsWith(string prefix)
  {
    return prefixUtil(root, prefix, 0);
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */