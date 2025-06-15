// 3. Longest Substring Without Repeating Characters

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the length of the longest substring without repeating characters
// not optimal solution, but works
// Time complexity: O(n^2) in the worst case, where n is the length of the string
// Space complexity: O(n) in the worst case, where n is the length of the string
int lengthOfLongestSubstring(string s)
{
  if (s.empty())
    return 0;
  if (s == " ")
    return 1;

  int maxLen = 0;
  string subs = "";
  for (int i = 0; i < s.length(); i++)
  {
    size_t pos = subs.find(s[i]);
    if (pos != string::npos)
    {
      // Remove up to and including the duplicate
      subs = subs.substr(pos + 1);
    }
    subs.push_back(s[i]);
    maxLen = max(maxLen, (int)subs.size());
  }

  return maxLen;
}

//optimal solution using sliding window technique
// Time complexity: O(n), where n is the length of the string
// Space complexity: O(min(n, m)), where n is the length of the string and m is the size of the character set
int lengthOfLongestSubstringOptimal(string s)
{
  unordered_map<char, int> charIndexMap;
  int maxLen = 0;
  int start = 0;

  for (int i = 0; i < s.length(); i++)
  {
    if (charIndexMap.find(s[i]) != charIndexMap.end())
    {
      start = max(start, charIndexMap[s[i]] + 1);
    }
    charIndexMap[s[i]] = i;
    maxLen = max(maxLen, i - start + 1);
  }

  return maxLen;
}
int main()
{
  string s1 = "abcabcbb";
  string s2 = "bbbbb";
  string s3 = "pwwkew";
  cout << "Length of longest substring without repeating characters in \"" << s1 << "\": " << lengthOfLongestSubstring(s1) << endl;
  cout << "Length of longest substring without repeating characters in \"" << s2 << "\": " << lengthOfLongestSubstring(s2) << endl;
  cout << "Length of longest substring without repeating characters in \"" << s3 << "\": " << lengthOfLongestSubstring(s3) << endl;
  cout << "Optimal solution:" << endl;
  cout << "Length of longest substring without repeating characters in \"" << s1 << "\": " << lengthOfLongestSubstringOptimal(s1) << endl;
  cout << "Length of longest substring without repeating characters in \"" << s2 << "\": " << lengthOfLongestSubstringOptimal(s2) << endl;
  cout << "Length of longest substring without repeating characters in \"" << s3 << "\": " << lengthOfLongestSubstringOptimal(s3) << endl;
  // Test with an empty string
  string emptyString = "";
  cout << "Length of longest substring without repeating characters in an empty string: " << lengthOfLongestSubstring(emptyString) << endl;
  // Test with a single space
  string singleSpace = " ";
  cout << "Length of longest substring without repeating characters in a single space: " << lengthOfLongestSubstring(singleSpace) << endl;
  // Test with a single character
  string singleChar = "a";
  cout << "Length of longest substring without repeating characters in a single character: " << lengthOfLongestSubstring(singleChar) << endl;
  // Test with a string with all unique characters
  string uniqueChars = "abcdefg";
  cout << "Length of longest substring without repeating characters in \"" << uniqueChars << "\": " << lengthOfLongestSubstring(uniqueChars) << endl;
  // Test with a string with all repeating characters
  string repeatingChars = "aaaaaa";
  cout << "Length of longest substring without repeating characters in \"" << repeatingChars << "\": " << lengthOfLongestSubstring(repeatingChars) << endl;

  // Test with a string with mixed characters
  string mixedChars = "abc123!@#abc";
  cout << "Length of longest substring without repeating characters in \"" << mixedChars << "\": " << lengthOfLongestSubstring(mixedChars) << endl;
  // Test with a string with special characters
  string specialChars = "!@#$%^&*()_+";
  cout << "Length of longest substring without repeating characters in \"" << specialChars << "\": " << lengthOfLongestSubstring(specialChars) << endl;
  return 0;
}