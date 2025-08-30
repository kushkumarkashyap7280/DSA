#include <vector>
#include <string>
using namespace std;

// 2255. Count Prefixes of a Given String
// Link: https://leetcode.com/problems/count-prefixes-of-a-given-string/

/*
Problem:
You are given a string array words and a string s, where words[i] and s comprise only of
lowercase English letters.

Return the number of strings in words that are a prefix of s.

A prefix of a string is a substring that occurs at the beginning of the string.
A substring is a contiguous sequence of characters within a string.

Approach 1 (Using substring):
1. For each word in words:
   a. Check if the word's length is less than or equal to the length of s
   b. Extract a substring from s with the same length as the word
   c. Compare this substring with the word
   d. Increment count if they match

Approach 2 (Using starts_with in C++20):
1. For each word in words:
   a. Use the starts_with method to check if s starts with the word
   b. Increment count if true

Approach 3 (Manual character comparison):
1. For each word in words:
   a. Check if the word's length is less than or equal to the length of s
   b. Compare each character of the word with the corresponding character in s
   c. If all characters match, increment the count

Time Complexity:
- O(n * m) where n is the number of words and m is the average length of words

Space Complexity:
- O(1) as we only use a constant amount of extra space
*/

class Solution
{
public:
    // Approach 1: Using substring method
    int countPrefixes_approach1(vector<string> &words, string s)
    {
        int count = 0;
        for (string &word : words)
        {
            if (word.size() <= s.size() && s.substr(0, word.size()) == word)
            {
                count++;
            }
        }
        return count;
    }

    // Approach 2: Using C++20 starts_with method
    int countPrefixes(vector<string> &words, string s)
    {
        int count = 0;
        for (string &word : words)
        {
            if (s.starts_with(word))
                count++;
        }
        return count;
    }

    // Approach 3: Manual character comparison
    int countPrefixes_approach3(vector<string> &words, string s)
    {
        int count = 0;
        for (string &word : words)
        {
            // Skip if word is longer than s
            if (word.size() > s.size())
                continue;

            bool isPrefix = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != s[i])
                {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix)
                count++;
        }
        return count;
    }
};