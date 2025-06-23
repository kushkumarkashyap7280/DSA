//342. Power of Four

//https://leetcode.com/problems/power-of-four/

/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
*/

#include <iostream>
using namespace std;

// function to check if n is a power of four
bool isPowerOfFour(int n) {
        
        if(n == 1 ) return true;
        if( n > 0 &&  n%4 == 0){
            return isPowerOfFour(n/4);
        }else{
            return false;
        }
    }
int main() {

  cout << isPowerOfFour(16) << endl;  // Output: 1 (true)
  cout << isPowerOfFour(5) << endl;   // Output: 0 (false)
  cout << isPowerOfFour(1) << endl;   // Output: 1 (true)
  return 0;
}