// 17. Letter Combinations of a Phone Number

// htps://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function to generate letter combinations
//time complexity: O(3^n * 4^m) where n is the number of digits that map to 3 letters and m is the number of digits that map to 4 letters
// space complexity: O(n) where n is the length of the output combinations
// using backtracking
// keypad is a vector of strings representing the mapping of digits to letters
// digits is the input string of digits
// index is the current index in the digits string
void lc(vector<string> &keypad, string &digits, int index, string current, vector<string> &ans)
{
  if (current.size() == digits.size())
  {
    ans.push_back(current);
    return;
  }
  string temp = keypad[digits[index] - '0'];

  for (int i = 0; i < temp.size(); i++)
  {
    current.push_back(temp[i]);
    lc(keypad, digits, index + 1, current, ans);
    current.pop_back();
  }
}

// function to return all letter combinations for the given digits
// if digits is empty, return an empty vector
vector<string> letterCombinations(string digits)
{
  if (digits.empty())
    return {};
  vector<string> keypad = {
      "",     // 0
      "",     // 1
      "abc",  // 2
      "def",  // 3
      "ghi",  // 4
      "jkl",  // 5
      "mno",  // 6
      "pqrs", // 7
      "tuv",  // 8
      "wxyz"  // 9
  };
  vector<string> ans;
  lc(keypad, digits, 0, "", ans);

  return ans;
}

int main()
{
  string digits;
  cout << "Enter the digits (2-9): ";
  cin >> digits;

  vector<string> combinations = letterCombinations(digits);

  cout << "Possible letter combinations: ";
  for (const string &combination : combinations)
  {
    cout << combination << " ";
  }
  cout << endl;

  return 0;
}