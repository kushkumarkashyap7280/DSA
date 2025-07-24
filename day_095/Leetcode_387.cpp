#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 387. First Unique Character in a String
// link - https://leetcode.com/problems/first-unique-character-in-a-string/

/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

// Time Complexity: O(N), where N = s.size()
// Space Complexity: O(26) for freq + O(N) for queue in worst case
int firstUniqCharUsingQueue(const string &s)
{
  vector<int> freq(26, 0);
  queue<int> window;
  for (int i = 0; i < (int)s.size(); i++)
  {
    freq[s[i] - 'a']++;
    window.push(i);
    while (!window.empty() && freq[s[window.front()] - 'a'] > 1)
    {
      window.pop();
    }
  }
  return (!window.empty()) ? window.front() : -1;
}

// Classic approach: just two passes
// Time: O(N), Space: O(26)
int firstUniqChar(const string &s)
{
  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'a']++;
  for (int i = 0; i < (int)s.size(); i++)
  {
    if (freq[s[i] - 'a'] == 1)
      return i;
  }
  return -1;
}

int main()
{
  vector<string> test_cases = {"leetcode", "loveleetcode", "aabb", "a", "", "abcabc", "z"};
  vector<int> expected = {0, 2, -1, 0, -1, -1, 0};
  for (size_t i = 0; i < test_cases.size(); ++i)
  {
    const string &s = test_cases[i];
    cout << "Test case " << i + 1 << ": input = '" << s << "'\n";
    int result1 = firstUniqChar(s);
    int result2 = firstUniqCharUsingQueue(s);
    cout << "Output (classic):   " << result1 << "\n";
    cout << "Output (queue):     " << result2 << "\n";
    cout << "Expected:           " << expected[i] << "\n";
    cout << ((result1 == expected[i] && result2 == expected[i]) ? "PASS" : "FAIL") << "\n\n";
  }
  return 0;
}