//58. Length of Last Word

// https://leetcode.com/problems/length-of-last-word/

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while( i >= 0 && s[i] == ' ') i--;
        int count = 0;
        while(i >= 0 && s[i--] != ' ') count++;
        return count;
 }
 
int main() {
    string s1 = "Hello World";
    cout << "Length of last word in '" << s1 << "' is: " << lengthOfLastWord(s1) << endl;

    string s2 = "   fly me   to   the moon  ";
    cout << "Length of last word in '" << s2 << "' is: " << lengthOfLastWord(s2) << endl;

    string s3 = "luffy is still joyboy";
    cout << "Length of last word in '" << s3 << "' is: " << lengthOfLastWord(s3) << endl;
return 0;
}