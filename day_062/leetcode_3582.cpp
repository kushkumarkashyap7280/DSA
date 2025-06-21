// Q1. Generate Tag for Video Caption

// https://leetcode.com/problems/generate-tag-for-video-caption/

/*
You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:

Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.

Remove all characters that are not an English letter, except the first '#'.

Truncate the result to a maximum of 100 characters.

Return the tag after performing the actions on caption.

 

Example 1:

Input: caption = "Leetcode daily streak achieved"

Output: "#leetcodeDailyStreakAchieved"

Explanation:

The first letter for all words except "leetcode" should be capitalized.

Example 2:

Input: caption = "can I Go There"

Output: "#canIGoThere"

Explanation:

The first letter for all words except "can" should be capitalized.

Example 3:

Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Explanation:

Since the first word has length 101, we need to truncate the last two letters from the word.

 

Constraints:

1 <= caption.length <= 150
caption consists only of English letters and ' '.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.©leetcode
*/

#include <iostream>
#include <string>
using namespace std;

// Function to generate a tag for the video caption
//time complexity: O(n), where n is the length of the caption
//space complexity: O(n), where n is the length of the tag generated
string generateTag(string caption)
{
  string ans = "#";
  bool cap = false;
  int i = 0;

  while (i < caption.size())
  {
    // Skip leading spaces
    while (i < caption.size() && caption[i] == ' ')
      i++;
    if (i >= caption.size())
      break;

    // Capitalize or lowercase first letter of word
    if (!cap)
    {
      ans.push_back(tolower(caption[i]));
      cap = !cap;
    }
    else
    {
      ans.push_back(toupper(caption[i]));
    }
    i++;

    // Add rest of the word in lowercase
    while (i < caption.size() && caption[i] != ' ')
    {
      ans.push_back(tolower(caption[i]));
      i++;
    }
  }

  if (ans.size() >= 100)
    return ans.substr(0, 100);
  return ans;
}
int main()
{
  string caption1 = "Leetcode daily streak achieved";
  string caption2 = "can I Go There";
  cout << generateTag(caption1) << endl; // Output: "#leetcodeDailyStreakAchieved"
  cout << generateTag(caption2) << endl; // Output: "#canIGoThere"
  return 0;
}