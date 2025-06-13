// 217. Contains Duplicate

// https://leetcode.com/problems/contains-duplicate/

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true



Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if the array contains duplicates
bool containsDuplicate(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++)
  {
    if (nums[i] == nums[i + 1])
      return true;
  }
  return false;
}
int main()
{
  vector<int> nums = {1, 2, 3, 1};
  if (containsDuplicate(nums))
    cout << "true" << endl;
  else
    cout << "false" << endl;
  return 0;
}