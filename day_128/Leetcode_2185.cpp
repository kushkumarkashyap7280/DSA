#include <vector>
#include <string>
using namespace std;

// 2185. Counting Words With a Given Prefix
// Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/

/*
Problem:
You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

Approach 1 (Brute Force):
1. For each word in words:
   a. Check if the word's length is at least the length of pref
   b. Compare each character of the word with the corresponding character in pref
   c. If a mismatch is found, the word doesn't have pref as prefix
   d. Increment count only if all characters match

Approach 2 (Using Substring):
1. For each word in words:
   a. Check if the word's length is at least the length of pref
   b. Use the substr method to extract the prefix of the word with length equal to pref
   c. Compare this extracted substring with pref
   d. Increment count if they match

Approach 3 (Using starts_with in C++20):
1. For each word in words:
   a. Use the starts_with method to check if the word starts with pref
   b. Increment count if true

Time Complexity:
- O(n * m) where n is the number of words and m is the length of the prefix

Space Complexity:
- O(1) as we only use a constant amount of extra space
*/

class Solution
{
public:
    // Approach 1: Character-by-character comparison
    int prefixCount_approach1(vector<string> &words, string pref)
    {
        int count = 0;

        for (int i = 0; i < words.size(); i++)
        {
            // Skip if word is shorter than prefix
            if (words[i].size() < pref.size())
            {
                continue;
            }

            bool isPrefix = true;
            // Check each character
            for (int j = 0; j < pref.size(); j++)
            {
                if (words[i][j] != pref[j])
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

    // Approach 2: Using substring method
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (string &word : words)
        {
            // Check if word length is sufficient and the substring matches pref
            if (word.size() >= pref.size() && word.substr(0, pref.size()) == pref)
                count++;
        }
        return count;
    }

    // Approach 3: Using C++20 starts_with method (uncomment if using C++20)
    /*
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string &word : words) {
            if(word.starts_with(pref)) count++;
        }
        return count;
    }
    */
};