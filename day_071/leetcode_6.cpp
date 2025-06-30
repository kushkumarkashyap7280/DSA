// 6. Zigzag Conversion

//https://leetcode.com/problems/zigzag-conversion/

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to convert the string to zigzag pattern
//time complexity: O(n), where n is the length of the string s
//space complexity: O(n), where n is the length of the string s
string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {
        return s; // No zigzag conversion needed
    }

    vector<string> rows(min(numRows, int(s.length())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c; // Add character to the current row
        if (curRow == 0) {
            goingDown = true; // Start going down
        } else if (curRow == numRows - 1) {
            goingDown = false; // Start going up
        }
        curRow += goingDown ? 1 : -1; // Move to the next row
    }

    string result;
    for (const string& row : rows) {
        result += row; // Concatenate all rows
    }
    
    return result;
}
int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(s, numRows);
    cout << "Converted string: " << result << endl; // Output: PAHNAPLSIIGYIR

    s = "PAYPALISHIRING";
    numRows = 4;
    result = convert(s, numRows);
    cout << "Converted string: " << result << endl; // Output: PINALSIGYAHRPI

    s = "A";
    numRows = 1;
    result = convert(s, numRows);
    cout << "Converted string: " << result << endl; // Output: A
return 0;
}