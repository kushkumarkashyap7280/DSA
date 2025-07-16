// 3201. Find the Maximum Length of Valid Subsequence I
// Problem Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/

/*
You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:
(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

Approach:
- Try all 4 possible parity patterns (all even, all odd, even-odd-even..., odd-even-odd...)
- For each pattern, iterate through nums and count the maximum valid subsequence length.
- Return the maximum among all patterns.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int maximumLength(vector<int> &nums)
  {
    int n = nums.size();
    int ans = 0;

    // 4 patterns
    for (int pattern = 0; pattern < 4; ++pattern)
    {
      int len = 0;
      int expect; // what parity we expect next: 0 = even, 1 = odd

      if (pattern == 0)
      { // all even
        expect = 0;
      }
      else if (pattern == 1)
      { // all odd
        expect = 1;
      }
      else if (pattern == 2)
      { // even–odd–even–odd
        expect = 0;
      }
      else
      { // odd–even–odd–even
        expect = 1;
      }

      for (int i = 0; i < n; ++i)
      {
        if (nums[i] % 2 == expect)
        {
          len++;
          if (pattern >= 2)
          {
            expect ^= 1; // flip parity for alternating patterns
          }
        }
      }

      ans = max(ans, len);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 4};
  vector<int> nums2 = {1, 2, 1, 1, 2, 1, 2};
  vector<int> nums3 = {1, 3};

  cout << "Input: [1, 2, 3, 4]\nOutput: " << sol.maximumLength(nums1) << endl;
  cout << "Input: [1, 2, 1, 1, 2, 1, 2]\nOutput: " << sol.maximumLength(nums2) << endl;
  cout << "Input: [1, 3]\nOutput: " << sol.maximumLength(nums3) << endl;
  return 0;
}
