// 3136. Valid Word

// link - https://leetcode.com/problems/valid-word/description

/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.


Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.



Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
  bool isValid(string word)
  {
    string v = "aeiou";
    if (word.size() < 3)
      return false;
    bool HasVowel = false;
    bool HasConsonant = false;
    for (char c : word)
    {
      char s = tolower(c);
      if (s >= 'a' && s <= 'z')
      {
        if (v.find(s) != string::npos)
        {
          HasVowel = true;
        }
        else
        {
          HasConsonant = true;
        }
      }
      else if (s >= '0' && s <= '9')
      {
        continue;
      }
      else
      {
        return false;
      }
    }
    return HasVowel && HasConsonant;
  }
};

// Time Complexity: O(N), where N is the length of the word (max 20).
// Space Complexity: O(1), only a few variables used.

int main()
{
  Solution sol;
  cout << boolalpha;
  cout << "Test 1: '234Adas' => " << sol.isValid("234Adas") << endl; // true
  cout << "Test 2: 'b3' => " << sol.isValid("b3") << endl;           // false
  cout << "Test 3: 'a3$e' => " << sol.isValid("a3$e") << endl;       // false
  cout << "Test 4: 'aei123' => " << sol.isValid("aei123") << endl;   // false (no consonant)
  cout << "Test 5: 'bcd123' => " << sol.isValid("bcd123") << endl;   // false (no vowel)
  cout << "Test 6: 'A1eB2c' => " << sol.isValid("A1eB2c") << endl;   // true
  return 0;
}