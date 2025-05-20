// C++ program to find the maximum occurring character in a string

// https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

// Examples:

// Input: s = "testsample"
// Output: 'e'
// Explanation: e is the character which is having the highest frequency.
// Input: s = "output"
// Output: 't'
// Explanation:  t and u are the characters with the same frequency, but t is lexicographically smaller.
// Constraints:
// 1 ≤ |s| ≤ 100

#include <iostream>
using namespace std;

// Function to find the maximum occurring character
// its my first approach which is not optimised
// time complexity is O(n^2)
// space complexity is O(1)
// it is not optimised
// char getMaxOccuringChar(string &s)
// {
//   char c = 'z';
//   int count = 0;

//   for (int i = 0; i < s.size(); i++)
//   {
//     int temp_count = 1;
//     int j = i + 1;
//     while (j < s.size())
//     {
//       if (s[j] == s[i])
//         temp_count++;
//       j++;
//     }
//     if (temp_count > count)
//     {
//       count = temp_count;
//       c = s[i];
//     }
//     else if (temp_count == count)
//     {
//       // if the frequency is same then check for lexicographically smaller character
//       if (s[i] < c)
//         c = s[i];
//     }
//     else if (temp_count == count && s[i] < c)
//     {
      
//         count = temp_count;
//         c = s[i];
//     }
//   }
//   return c;
// }

// Optimised approach
// time complexity is O(n)
// space complexity is O(1)
// it is optimised
char getMaxOccuringChar(string& s) {
    char ans = 'z';

    int countArr[26] = {0};

    // Count frequency of each character
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        countArr[index]++;
    }

    int maxi = countArr[0];
    ans = 'a';  // Initialize to 'a', since that's index 0

    for (int i = 1; i < 26; i++) {
        if (countArr[i] > maxi) {
            maxi = countArr[i];
            ans = 'a' + i;
        } else if (countArr[i] == maxi) {
            // Lexicographically smaller check
            if (ans > ('a' + i)) {
                ans = 'a' + i;
            }
        }
    }

    return ans;
}



int main()
{
  // example string
  string s1 = "testsample";
  string s2 = "output";
  string s3 = "aabbccdd";
  string s4 = "hello";
  string s5 = "aabbccddeeffgghh";

  cout << "Test Case 1:" << endl;
  cout << "Input: \"" << s1 << "\"" << endl;
  cout << "Output: '" << getMaxOccuringChar(s1) << "'" << endl
       << endl;
  cout << "Test Case 2:" << endl;
  cout << "Input: \"" << s2 << "\"" << endl;
  cout << "Output: '" << getMaxOccuringChar(s2) << "'" << endl
       << endl;
  cout << "Test Case 3:" << endl;
  cout << "Input: \"" << s3 << "\"" << endl;
  cout << "Output: '" << getMaxOccuringChar(s3) << "'" << endl
       << endl;

  return 0;
}