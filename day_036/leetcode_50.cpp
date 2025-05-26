//50. Pow(x, n)

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <iostream>
using namespace std;

//normal function which calculates x raised to the power n is to iterate n times and multiply x each time
//time complexity: O(n)
// space complexity: O(1)
// double myPow(double x, int n) {
//     if (n == 0) return 1; // x^0 = 1
//     if (n < 0) { // if n is negative, we take the reciprocal
//         x = 1 / x;
//         n = -n; // make n positive
//     }
    
//     double result = 1;
//     for (int i = 0; i < n; ++i) {
//         result *= x; // multiply x, n times
//     }
    
//     return result;
// }

// Optimized function using divide and conquer approach
// time complexity: O(log n)
// space complexity: O(1)
double myPow(double x, int n) {
        long long N = n;
        if(N == 0) return 1;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
         double ans = 1;
        while(N>0){
            if(N%2 == 1){
                ans *= x;
            }
            x*=x;
            N /=2;
        }

    return ans;
        
    }

int main() {
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    double result = myPow(x, n);
    cout << "Result: " << result << endl;
return 0;
}