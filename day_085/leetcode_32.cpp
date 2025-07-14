// 32. Longest Valid Parentheses

// link - https://leetcode.com/problems/longest-valid-parentheses/description

/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.

Time and Space Complexity:
Approach 1 (Stack):
  - Time: O(n), single pass
  - Space: O(n), stack can grow to size n
Approach 2 (Left/Right Counters):
  - Time: O(n), two passes
  - Space: O(1), only uses a few variables
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Approach 1: Using stack
// Time Complexity: O(n), where n is the length of the string (single pass)
// Space Complexity: O(n), for the stack in the worst case (all '(')
int longestValidParentheses(string s)
{
  int maxi = 0;
  stack<int> st;
  st.push(-1);
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
    {
      st.push(i);
    }
    else
    {
      st.pop();
      if (st.empty())
      {
        st.push(i);
      }
      else
      {
        maxi = max(maxi, i - st.top());
      }
    }
  }
  return maxi;
}

// Approach 2: Using left and right counters
// Time Complexity: O(n), where n is the length of the string (two passes)
// Space Complexity: O(1), only uses a few integer variables
// int longestValidParentheses(string s)
// {
//   int maxi = 0;
//   int open = 0, close = 0;

//   // Left to Right
//   for (char c : s)
//   {
//     if (c == '(')
//       open++;
//     else
//       close++;

//     if (open == close)
//     {
//       maxi = max(maxi, 2 * close);
//     }
//     else if (close > open)
//     {
//       // Too many ')', reset
//       open = close = 0;
//     }
//   }

//   open = close = 0;

//   // Right to Left
//   for (int i = s.size() - 1; i >= 0; i--)
//   {
//     if (s[i] == '(')
//       open++;
//     else
//       close++;

//     if (open == close)
//     {
//       maxi = max(maxi, 2 * open);
//     }
//     else if (open > close)
//     {
//       // Too many '(', reset
//       open = close = 0;
//     }
//   }

//   return maxi;
// }

int main()
{
  string s1 = "(()";
  string s2 = ")()())";
  string s3 = "";
  cout << "Input: '" << s1 << "'\tOutput: " << longestValidParentheses(s1) << endl;
  cout << "Input: '" << s2 << "'\tOutput: " << longestValidParentheses(s2) << endl;
  cout << "Input: '" << s3 << "'\tOutput: " << longestValidParentheses(s3) << endl;
  return 0;
}