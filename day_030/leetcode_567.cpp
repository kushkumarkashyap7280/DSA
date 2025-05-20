// 567. Permutation in String

// https://leetcode.com/problems/permutation-in-string

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// my approach
// time complexity is O(n)
// space complexity is O(1)
bool checkInclusion(string s1, string s2)
{
  int len1 = s1.size(), len2 = s2.size();
  if (len1 > len2)
    return false;

  vector<int> CharArr(26, 0), window(26, 0);

  // Build frequency map for s1 and first window in s2
  for (int i = 0; i < len1; ++i)
  {
    CharArr[s1[i] - 'a']++;
    window[s2[i] - 'a']++;
  }

  if (CharArr == window)
    return true;

  // Slide the window
  for (int i = len1; i < len2; ++i)
  {
    window[s2[i] - 'a']++;        // add new char
    window[s2[i - len1] - 'a']--; // remove old char
    if (CharArr == window)
      return true; // check match
  }

  return false;
}

int main()
{
  string s1 = "ab", s2 = "eidbaooo";
  string s3 = "pqrs", s4 = "ppqrs";
  cout << checkInclusion(s1, s2) << endl; // Output: true
  cout << checkInclusion(s3, s4) << endl; // Output: true

 

  return 0;
}