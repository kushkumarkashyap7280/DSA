//171. Excel Sheet Column Number

// https://leetcode.com/problems/excel-sheet-column-number/

/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
 

Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

#include <iostream>
#include <string>
using namespace std;

// Function to convert Excel column title to number
int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) {
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}

int main() {
    cout << titleToNumber("A") << endl;  // Output: 1
    cout << titleToNumber("AB") << endl; // Output: 28
    cout << titleToNumber("ZY") << endl; // Output: 701
    return 0;
}