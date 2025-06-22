// 326. Power of Three

// https://leetcode.com/problems/power-of-three/

/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.



Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


Constraints:

-231 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;
// Function to check if n is a power of three
// Recursive approach: O(log3 n) time and O(n) space due to recursion stack
bool isPowerOfThree(int n)
{
  if (n == 1)
    return true;
  if (n <= 0 || n % 3 != 0)
    return false;
  return isPowerOfThree(n / 3);
}

int main()
{
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  cout << isPowerOfThree(n) << endl;
  // Output: 1 if n is a power of three, otherwise 0
  return 0;
}