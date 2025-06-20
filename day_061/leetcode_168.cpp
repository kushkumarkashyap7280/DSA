// 168. Excel Sheet Column Title

// https://leetcode.com/problems/excel-sheet-column-title/

/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"


Constraints:

1 <= columnNumber <= 231 - 1
*/

#include <iostream>
using namespace std;

// Function to convert column number to Excel column title
// time complexity: O(log n)
// space complexity: O(1)
string convertToTitle(int columnNumber)
{
    string result;
    while (columnNumber > 0)
    {
        columnNumber--; // Adjust for 0-based index
        char ch = 'A' + (columnNumber % 26);
        result = ch + result; // Prepend character to result
        columnNumber /= 26;   // Move to the next "digit"
    }
    return result;
}
int main()
{
    // User input
    int columnNumber;
    cout << "Enter the column number: ";
    cin >> columnNumber;

    string columnTitle = convertToTitle(columnNumber);
    cout << "The corresponding Excel column title is: " << columnTitle << endl;

    // Sample test cases
    int testCases[] = {1, 28, 701, 52, 2147483647};
    cout << "\nSample Test Cases:" << endl;
    for (int test : testCases)
    {
        cout << "Column Number: " << test << " -> Title: " << convertToTitle(test) << endl;
    }
    return 0;
}