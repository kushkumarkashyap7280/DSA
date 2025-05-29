// 69. Sqrt(x)

// LeetCode Problem: https://leetcode.com/problems/sqrtx/

/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.


Constraints:

0 <= x <= 231 - 1
*/

#include <iostream>
using namespace std;
// Function to compute the square root of a non-negative integer x
// brute force approach
// Time Complexity: O(sqrt(x)), where x is the input number
// Space Complexity: O(1), as we are using a constant amount of space
// int mySqrt(int x)
// {
//   int i = 0;
//   while (i * i <= x)
//   {
//     i++;
//   }
//   return i - 1;
// }

// optimal approach using binary search
// Time Complexity: O(log(x)), where x is the input number
// Space Complexity: O(1), as we are using a constant amount of space
int mySqrt(int x)
{
  if (x < 2)
    return x;

  int ans = 0;
  long long n = x;
  long long i = 0, j = x / 2;
  while (i <= j)
  {
    long long m = i + (j - i) / 2;
    if (m * m <= n)
    {
      ans = m;
      i = m + 1;
    }
    else
    {
      j = m - 1;
    }
  }
  return ans;
}
int main()
{
  int x;
  cout << "Enter a non-negative integer x: ";
  cin >> x;

  int result = mySqrt(x);
  cout << "The square root of " << x << " rounded down is: " << result << endl;
  return 0;
}