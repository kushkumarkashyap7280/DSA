//509. Fibonacci Number

/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30
*/

#include <iostream>
using namespace std;

// Function to calculate Fibonacci number using recursion
//time complexity: O(2^n) - exponential time complexity due to the nature of recursion
//space complexity: O(n) - due to the recursive call stack
int fibonacci(int n) {
    // Base case: if n is 0 or 1, return n
    if (n == 0 || n == 1) {
        return n;
    }
    // Recursive case: return the sum of the two preceding Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//normal function to calculate Fibonacci number
// int fibonacci(int n) {
//     int a = 0, b = 1, c;
//     if (n == 0) return a;
//     for (int i = 2; i <= n; i++) {
//         c = a + b; // Calculate the next Fibonacci number
//         a = b; // Update a to the previous Fibonacci number
//         b = c; // Update b to the current Fibonacci number
//     }
//     return b; // Return the nth Fibonacci number
// }
int main() {
    int n;
    cout << "Enter a number to calculate its Fibonacci value: ";
    cin >> n; // Input from user
    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        int result = fibonacci(n); // Call the recursive function
        cout << "Fibonacci of " << n << " is " << result << endl; // Output the result
    }
return 0;
}