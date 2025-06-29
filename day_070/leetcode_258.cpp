//258. Add Digits

//https://leetcode.com/problems/add-digits/

/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0
 

Constraints:

0 <= num <= 231 - 1
 

Follow up: Could you do it without any loop/recursion in O(1) runtime?


*/

#include <iostream>
using namespace std;


//my approach: Use a loop to repeatedly sum the digits
// This approach runs in O(log n) time, where n is the number of digits in num, and uses O(1) space.
// The time complexity is O(log n) because the number of digits in num decreases with each iteration until it becomes a single digit.
// This is a straightforward approach that works well for small numbers but may not be optimal for larger numbers.
// This approach is not the most efficient, but it is easy to understand and implement.
int sumof(int num){
        int sum = 0;
        while(num){
          sum += num%10;
          num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum = sumof(num);
        while(true){
            sum = sumof(sum);
            if(sum <10) break;
        }
        return sum;
        
    }


//// Approach: Use the digital root formula
// The digital root can be calculated using the formula: 1 + (num - 1) % 9
// This works because the digital root is equivalent to the remainder when the number is divided by 9, with a special case for 0.
// This approach runs in constant time O(1) and uses constant space O(1).
int addDigitsOptimal(int num) {
    // If num is 0, return 0
    if (num == 0) return 0;
    
    // Use the digital root formula
    return 1 + (num - 1) % 9;
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Using the loop-based approach
    int result1 = addDigits(num);
    cout << "Result using loop-based approach: " << result1 << endl;

    // Using the digital root formula
    int result2 = addDigitsOptimal(num);
    cout << "Result using digital root formula: " << result2 << endl;
return 0;
}