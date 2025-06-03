// 2652. Sum Multiples

// https://leetcode.com/problems/sum-multiples/

/*
Given a positive integer n, find the sum of all integers in the range [1, n] inclusive that are divisible by 3, 5, or 7.

Return an integer denoting the sum of all numbers in the given range satisfying the constraint.



Example 1:

Input: n = 7
Output: 21
Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
Example 2:

Input: n = 10
Output: 40
Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
Example 3:

Input: n = 9
Output: 30
Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.


Constraints:

1 <= n <= 103
*/
#include <iostream>
using namespace std;

// Function(not optimal) to calculate the sum of multiples of 3, 5, or 7 up to n
// Time Complexity: O(n)
// Space Complexity: O(1)
int sumOfMultiples(int n)
{
  int sum = 0;
  for (int i = 3; i < n + 1; i++)
  {
    if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
    {
      sum += i;
    }
  }
  return sum;
}

//optimal solution
// Time Complexity: O(1)
// Space Complexity: O(1)
int sumOfMultiplesOptimal(int n){
 return (n / 3) * (n / 3 + 1) / 2 * 3 + (n / 5) * (n / 5 + 1) / 2 * 5 + (n / 7) * (n / 7 + 1) / 2 * 7;
  // This formula calculates the sum of multiples of 3, 5, and 7 using the arithmetic series formula.
  // It is more efficient than iterating through all numbers up to n.


}
int main()
{
  int n;
  cout << "Enter a positive integer n: ";
  cin >> n;

  int result = sumOfMultiples(n);
  cout << "The sum of all integers in the range [1, " << n << "] that are divisible by 3, 5, or 7 is: " << result << endl;

  return 0;
}