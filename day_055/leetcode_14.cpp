// 14. Longest Common Prefix

// https://leetcode.com/problems/longest-common-prefix/

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function to find the longest common prefix
//time complexity: O(n * m) where n is the number of strings and m is the length of the longest string
//space complexity: O(1) since we are using only a few variables
string longestCommonPrefix(vector<string> &strs)
{
  string temp = strs[0];
  for (int i = 0; i < temp.size(); i++)
  {
    for (int j = 0; j < strs.size(); j++)
    {
      if (strs[j].size() <= i || strs[j][i] != temp[i])
      {
        return temp.substr(0, i);
      }
    }
  }
  return temp;
}
int main()
{

  vector<string> strs1 = {"flower", "flow", "flight"};
  vector<string> strs2 = {"dog", "racecar", "car"};
  cout << "Longest common prefix of strs1: " << longestCommonPrefix(strs1) << endl; // Output: "fl"
  
  return 0;
}