//66. Plus One

//https://leetcode.com/problems/plus-one/

/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to increment the large integer represented by the digits array
//time complexity: O(n), where n is the number of digits in the input array.
//space complexity: O(1), since we are modifying the input array in place and not using any additional data structures.
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    // Start from the last digit and increment it
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits; // No carry, return the result
        }
        digits[i] = 0; // Set current digit to 0 and carry over
    }
    
    // If we reach here, it means we had a carry out of the most significant digit
    digits.insert(digits.begin(), 1); // Insert 1 at the beginning
    return digits;
}
int main() {
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = plusOne(digits1);
    for (int digit : result1) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 2 4

    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = plusOne(digits2);
    for (int digit : result2) {
        cout << digit << " ";
    }
    cout << endl; // Output: 4 3 2 2

    vector<int> digits3 = {9};
    vector<int> result3 = plusOne(digits3);
    for (int digit : result3) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 0
return 0;
}