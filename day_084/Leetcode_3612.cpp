// 3612. Process String with Special Operations I

// link - https://leetcode.com/problems/process-string-with-special-operations-i/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


/*
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.



Example 1:

Input: s = "a#b%*"

Output: "ba"

Explanation:

i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
Thus, the final result is "ba".

Example 2:

Input: s = "z*#"

Output: ""

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
Thus, the final result is "".



Constraints:

1 <= s.length <= 20
s consists of only lowercase English letters and special characters *, #, and %.
*/

string processStr(string s)
{
    string r = "";

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            r.push_back(c);
        if (c == '*' && !r.empty())
            r.pop_back();
        if (c == '#' && !r.empty())
        {
            r += r;
        }
        if (c == '%' && !r.empty())
        {
            reverse(r.begin(), r.end());
        }
    }
    return r;
}

int main()
{
    // Test cases
    string test1 = "a#b%*";
    cout << "Input: " << test1 << endl;
    cout << "Output: " << processStr(test1) << endl;
    cout << "Expected: ba" << endl
         << endl;

    string test2 = "z*#";
    cout << "Input: " << test2 << endl;
    cout << "Output: " << processStr(test2) << endl;
    cout << "Expected: " << endl
         << endl;

    string test3 = "abc%";
    cout << "Input: " << test3 << endl;
    cout << "Output: " << processStr(test3) << endl;
    cout << "Expected: cba" << endl
         << endl;

    return 0;
}
