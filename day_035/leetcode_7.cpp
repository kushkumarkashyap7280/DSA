//7. Reverse Integer

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/

#include <iostream>
using namespace std;

// Function to reverse the digits of a signed 32-bit integer
// time complexity: O(log10(n)), where n is the absolute value of the input integer
// space complexity: O(1), as we are using a constant amount of space
 int reverse(int x) {
        int ans = 0;
        while(x){
            if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            ans = ans*10 +  x%10;
            x /=10;
        }
        return ans;
        
    }
int main() {
    int x;
    cout << "Enter a signed 32-bit integer: ";
    cin >> x;

    int reversed = reverse(x);

    if (reversed == 0) {
        cout << "Reversing the integer causes overflow." << endl;
    } else {
        cout << "Reversed integer: " << reversed << endl;
    }
return 0;
}