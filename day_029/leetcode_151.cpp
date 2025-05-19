// 151. Reverse Words in a String

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

#include <iostream>
#include <string>
using namespace std;

// my approach which is optimised also;
string reverseWords(string s)
{
    string ans = "", temp = "";
    int i = s.size() - 1;

    while (i >= 0)
    {
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ')
            i--;
        if (i < 0)
            break;

        int j = i;
        // Find the start of the word
        while (j >= 0 && s[j] != ' ')
            j--;

        temp = s.substr(j + 1, i - j);
        if (!ans.empty())
            ans += " ";
        ans += temp;

        i = j - 1;
    }

    return ans;
}
// time complexity : o(n);
//  space complexity : o(n);
int main()
{
    // Test cases
    string s1 = "the sky is blue";
    string s2 = "  hello world  ";
    string s3 = "a good   example";

    cout << "Test Case 1:" << endl;
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s1) << "\"" << endl
         << endl;

    cout << "Test Case 2:" << endl;
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s2) << "\"" << endl
         << endl;

    cout << "Test Case 3:" << endl;
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << reverseWords(s3) << "\"" << endl;

    return 0;
}