//43. Multiply Strings

// https://leetcode.com/problems/multiply-strings/

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// approach 1:
// time complexity: O(n * m) where n is the length of num1 and m is the length of num2
// space complexity: O(n + m) for the result string
// ----------------------------------------------------------------------//

string mul(string num1 , char c, int z){
    int carry = 0;
    int ch =  c - '0';
    string ans;

    while(z--){
        ans.push_back('0');
    }

    int i = num1.size() -1;
    while(i >= 0 || carry){
        int sum = carry;
        if(i >= 0){
            int temp = num1[i--] - '0';
            sum += temp * ch;
        }
        ans.push_back('0' + sum % 10);
        carry = sum / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string Sum(string num1 , string num2){
    string ans;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry){
        int sum = carry;
        if(i >= 0) sum += num1[i--] - '0';
        if(j >= 0) sum += num2[j--] - '0';
        ans.push_back('0' + sum % 10);
        carry = sum / 10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string ans = "0";

    for(int i = num2.size() - 1; i >= 0; i--){
        string product = mul(num1, num2[i], num2.size() - 1 - i);
        ans = Sum(ans, product);
    }

    return ans;
}
// ----------------------------------------------------------------------//
// approach 2:
// using Karatsuba algorithm
// time complexity: O(n^log2(3)) where n is the length of the longer string
// space complexity: O(n + m) for the result string
string multiplyKaratsuba(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1.size() < 2 || num2.size() < 2) return multiply(num1, num2);

    int n = max(num1.size(), num2.size());
    int half = n / 2;

    string a = num1.substr(0, num1.size() - half);
    string b = num1.substr(num1.size() - half);
    string c = num2.substr(0, num2.size() - half);
    string d = num2.substr(num2.size() - half);

    string ac = multiplyKaratsuba(a, c);
    string bd = multiplyKaratsuba(b, d);
    string abcd = multiplyKaratsuba(Sum(a, b), Sum(c, d));

    string adbc = Sum(Sum(ac, bd), bd);
    
    for (int i = 0; i < 2 * half; i++) ac.push_back('0');
    for (int i = 0; i < half; i++) adbc.push_back('0');

    return Sum(Sum(ac, adbc), bd);
}
// ----------------------------------------------------------------------//
int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    string result = multiply(num1, num2);
    cout << "Product of " << num1 << " and " << num2 << " is: " << result << endl;

    // Using Karatsuba algorithm
    string resultKaratsuba = multiplyKaratsuba(num1, num2);
    cout << "Product using Karatsuba algorithm: " << resultKaratsuba << endl;

    return 0;
}
