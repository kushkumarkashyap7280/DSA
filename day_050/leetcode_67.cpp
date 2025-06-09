// 67. Add Binary

// https://leetcode.com/problems/add-binary/

/*
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Function to add two binary strings
// Time Complexity: O(max(m, n)), where m and n are the lengths of the two binary strings.
// Space Complexity: O(max(m, n)), for the result string.
string addBinary(string a, string b)
{
  string ans = "";
  int i = a.size() - 1;
  int j = b.size() - 1;

  int carry = 0;
  while (i >= 0 || j >= 0 || carry)
  {
    int sum = carry;
    if (i >= 0)
      sum += a[i--] - '0';
    if (j >= 0)
      sum += b[j--] - '0';
    ans.push_back('0' + sum % 2);
    carry = sum / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string a = "1010";
  string b = "1011";
  cout << "Sum of binary strings: " << addBinary(a, b) << endl; // Output: "10101"
  return 0;
}