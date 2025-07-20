// 3622. Check Divisibility by Digit Sum and Product

// link - https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/

/*
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.

Example 1:
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:
Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

Constraints:
1 <= n <= 10^6
*/

#include <iostream>
#include <vector>
using namespace std;

bool checkDivisibility(int n)
{
  int num = n;
  int sum = 0;
  int product = 1;
  while (num)
  {
    sum += num % 10;
    product *= num % 10;
    num /= 10;
  }
  return (n % (sum + product)) == 0;
}

int main()
{
  vector<pair<int, bool>> testcases = {
      {99, true},
      {23, false},
      {1, true},
      {10, false},
      {36, false},
      {135, true}, // 1+3+5=9, 1*3*5=15, 9+15=24, 135%24==15 -> false
      {81, true}   // 8+1=9, 8*1=8, 9+8=17, 81%17==13 -> false
  };
  // Fix testcases for correct expected output
  testcases[5].second = false; // 135
  testcases[6].second = false; // 81

  for (auto &[n, expected] : testcases)
  {
    bool result = checkDivisibility(n);
    cout << "n = " << n << ": ";
    cout << (result ? "true" : "false");
    cout << " (expected: " << (expected ? "true" : "false") << ")\n";
  }
  return 0;
}

/*
Time Complexity: O(D), where D is the number of digits in n (at most 7 for n <= 10^6)
Space Complexity: O(1)
*/