// 34. Find First and Last Position of Element in Sorted Array

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the first and last position of target in sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
vector<int> searchRange(vector<int> &nums, int target)
{
  vector<int> ans = {-1, -1};
  int i = 0;
  int j = nums.size() - 1;
  while (i <= j)
  {
    int m = i + (j - i) / 2;
    if (nums[m] == target)
    {
      i = j = m;

      while (i > 0 && nums[i - 1] == target)
        i--;
      while (j < nums.size() - 1 && nums[j + 1] == target)
        j++;
      ans[0] = i;
      ans[1] = j;
      break;
    }
    else if (nums[m] < target)
    {
      i = m + 1;
    }
    else
    {
      j = m - 1;
    }
  }

  return ans;
}
int main()
{
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> result = searchRange(nums, target);
  cout << "First and Last Position of Target: [" << result[0] << ", " << result[1] << "]" << endl;
  return 0;
}