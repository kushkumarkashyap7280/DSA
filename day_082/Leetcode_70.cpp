// climbing stairs

//https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

#include <iostream>
using namespace std;

// recursive solution
// time complexity: O(2^n)
// space complexity: O(n)
// not efficient
// int climbStairs(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     return climbStairs(n - 1) + climbStairs(n - 2);
// }



// my approach
// time complexity: O(n)
// space complexity: O(1)
// efficient
int climbStairs(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;

  int prev1 = 1; // ways to reach step 1
  int prev2 = 2; // ways to reach step 2

  for (int i = 3; i <= n; ++i) {
      int curr = prev1 + prev2;
      prev1 = prev2;
      prev2 = curr;
  }

  return prev2;
}


int main()
{
    // test cases
    cout << "Test case 1: " << climbStairs(2) << endl;
    cout << "Test case 2: " << climbStairs(3) << endl;
    cout << "Test case 3: " << climbStairs(4) << endl;
    cout << "Test case 4: " << climbStairs(5) << endl;
    cout << "Test case 5: " << climbStairs(6) << endl;
    cout << "Test case 6: " << climbStairs(7) << endl;
    cout << "Test case 7: " << climbStairs(8) << endl;
    cout << "Test case 8: " << climbStairs(9) << endl;
    cout << "Test case 9: " << climbStairs(10) << endl;
    cout << "Test case 10: " << climbStairs(11) << endl;
    return 0;
}
