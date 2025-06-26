// 78. Subsets

// https://leetcode.com/problems/subsets/

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <iostream>
#include <vector>
using namespace std;

// bit manipulation approach
// time complexity: O(n * 2^n)
// space complexity: O(n * 2^n) for storing the subsets
vector<vector<int>> subsets(vector<int> &nums)
{
  int s = nums.size();
  int n = 1 << s;

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++)
  {
    vector<int> subarr;
    int k = i;
    for (int j = 0; j < s; j++)
    {
      if (k & 1)
      {
        subarr.push_back(nums[j]);
      }
      k >>= 1;
    }
    ans.push_back(subarr);
  }
  return ans;
}

// using backtracking approach
// time complexity: O(n * 2^n)
//space complexity: O(n * 2^n) for storing the subsets
void backtrack(vector<int> &nums, vector<vector<int>> &ans, vector<int> &subarr, int start)
{
  ans.push_back(subarr);
  for (int i = start; i < nums.size(); i++)
  {
    subarr.push_back(nums[i]);
    backtrack(nums, ans, subarr, i + 1);
    subarr.pop_back();
  }
}
int main()
{
  // example usage
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = subsets(nums);
  for (const auto &subset : result)
  {
    cout << "[";
    for (const auto &num : subset)
    {
      cout << num << " ";
    }
    cout << "]" << endl;
  }

  // using backtracking
  vector<vector<int>> ans;
  vector<int> subarr;
  backtrack(nums, ans, subarr, 0);
  cout << "Using backtracking:" << endl;
  for (const auto &subset : ans)
  {
    cout << "[";
    for (const auto &num : subset)
    {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
  return 0;
}