// 415. Add Strings

// https://leetcode.com/problems/add-strings/

/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"


Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to add two numbers represented as strings
string addStrings(string num1, string num2)
{
  string ans;
  int carry = 0;
  int i = num1.size() - 1;
  int j = num2.size() - 1;

  while (i >= 0 || j >= 0 || carry)
  {
    int sum = carry;
    if (i >= 0)
      sum += num1[i--] - '0';
    if (j >= 0)
      sum += num2[j--] - '0';

    ans.push_back('0' + (sum % 10));
    carry = sum / 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main()
{
  string num1 = "11", num2 = "123";
  cout << "Sum of " << num1 << " and " << num2 << " is: " << addStrings(num1, num2) << endl; // Output: "134" 
  return 0;
}