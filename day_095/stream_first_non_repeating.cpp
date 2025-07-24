#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Stream First Non-repeating
// link - https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*
Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
*/

// Time Complexity: O(N), where N = s.size()
// Space Complexity: O(26) for freq + O(N) for queue in worst case
string FirstNonRepeating(string &s)
{
  int size = s.size();
  if (size == 0)
    return "";
  if (size == 1)
    return s;
  vector<int> freq(26, 0);
  string ans;
  queue<char> stream;
  for (char c : s)
  {
    freq[c - 'a']++;
    stream.push(c);
    // Remove characters with frequency > 1 from front
    while (!stream.empty() && freq[stream.front() - 'a'] > 1)
    {
      stream.pop();
    }
    // Append the first non-repeating character
    if (!stream.empty())
    {
      ans.push_back(stream.front());
    }
    else
    {
      ans.push_back('#');
    }
  }
  return ans;
}

int main()
{
  vector<string> test_cases = {"aabc", "zz", "bb", "abcabc", "aabbcc", "a", ""};
  vector<string> expected = {"a#bb", "z#", "b#", "a#bbcc", "a#b#c#", "a", ""};
  for (size_t i = 0; i < test_cases.size(); ++i)
  {
    string s = test_cases[i];
    cout << "Test case " << i + 1 << ": input = '" << s << "'\n";
    string result = FirstNonRepeating(s);
    cout << "Output:   '" << result << "'\n";
    cout << "Expected: '" << expected[i] << "'\n";
    cout << (result == expected[i] ? "PASS" : "FAIL") << "\n\n";
  }
  return 0;
}