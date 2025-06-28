//29. Divide Two Integers

//https://leetcode.com/problems/divide-two-integers/

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

#include <iostream>
using namespace std;

// Function to divide two integers without using multiplication, division, or mod operator
int divide(int dividend, int divisor) {
    // Handle edge cases for overflow
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // Overflow case
    }
    
    // Determine the sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    // Convert both numbers to positive
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);
    
    long long quotient = 0;
    
    // Perform division using bit manipulation
    while (absDividend >= absDivisor) {
        long long temp = absDivisor, multiple = 1;
        while (absDividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        absDividend -= temp;
        quotient += multiple;
    }
    
    // Apply the sign to the result
    return negative ? -quotient : quotient;
}
int main() {
    int dividend = 10, divisor = 3;
    cout << "Result of division: " << divide(dividend, divisor) << endl; // Output: 3

    dividend = 7, divisor = -3;
    cout << "Result of division: " << divide(dividend, divisor) << endl; // Output: -2

    dividend = INT_MIN, divisor = -1;
    cout << "Result of division: " << divide(dividend, divisor) << endl; // Output: 2147483647 (INT_MAX)
return 0;
}