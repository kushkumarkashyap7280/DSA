//1047. Remove All Adjacent Duplicates In String

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:

// Input: s = "azxxzy"
// Output: "ay"
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

// approach :
// 1. use stack to store the characters
// 2. if the top of the stack is equal to the current character, pop the stack
// 3. if the top of the stack is not equal to the current character, push the current character onto the stack
// 4. after iterating through the string, the stack will contain the final string
// 5. construct the final string from the stack
// 6. since we constructed the result from the stack (LIFO), we need to reverse it
// time complexity : O(n)
// space complexity : O(n)
//  where n is the length of the string
 string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // remove the duplicate pair
        } else {
            st.push(c);
        }
    }

    // Construct the final string from the stack
   string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Since we constructed the result from the stack (LIFO), we need to reverse it
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    string s = "abbaca";
    cout << "Input: " << s << endl;
    string result = removeDuplicates(s);
    cout << "Output: " << result << endl;
    // Output: "ca"

return 0;
}