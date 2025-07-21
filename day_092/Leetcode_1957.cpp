// 1957. Delete Characters to Make Fancy String

// link - https://leetcode.com/problems/delete-characters-to-make-fancy-string/description

/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

Example 1:
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".

Constraints:
1 <= s.length <= 10^5
s consists only of lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string makeFancyString(string s)
{
  string ans;
  int count = 0;
  char curr = s[0];
  for (char c : s)
  {
    if (c == curr && count >= 2)
    {
      continue;
    }
    ans.push_back(c);
    if (c == curr)
    {
      count++;
    }
    else
    {
      curr = c;
      count = 1;
    }
  }
  return ans;
}

int main()
{
  vector<pair<string, string>> testcases = {
      {"leeetcode", "leetcode"},
      {"aaabaaaa", "aabaa"},
      {"aab", "aab"},
      {"aaa", "aa"},
      {"abc", "abc"},
      {"a", "a"},
      {"bbbaaabb", "bbaabb"}};
  for (auto &[input, expected] : testcases)
  {
    string result = makeFancyString(input);
    cout << "Input: " << input << "\nOutput: " << result << "\nExpected: " << expected << "\n";
    cout << (result == expected ? "PASS" : "FAIL") << "\n\n";
  }
  return 0;
}

/*
Time Complexity: O(N), where N is the length of s
Space Complexity: O(N) for the answer string
*/