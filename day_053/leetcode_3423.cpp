// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

/*
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.



Example 1:

Input: nums = [1,2,4]

Output: 3

Explanation:

Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

Example 2:

Input: nums = [-5,-10,-5]

Output: 5

Explanation:

The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.



Constraints:

2 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum absolute difference between adjacent elements in a circular array
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), since we are using a constant amount of extra space.
int maxAdjacentDistance(vector<int> &nums)
{
  int n = nums.size();
  int ans = abs(nums[0] - nums[n - 1]);
  for (int i = 0; i < n - 1; i++)
  {
    ans = max(ans, abs(nums[i + 1] - nums[i]));
  }
  return ans;
}

int main()
{
  vector<int> nums1 = {1, 2, 4};
  vector<int> nums2 = {-5, -10, -5};
  cout << "Maximum absolute difference in nums1: " << maxAdjacentDistance(nums1) << endl; // Output: 3
  cout << "Maximum absolute difference in nums2: " << maxAdjacentDistance(nums2) << endl; // Output: 5

  return 0;
}