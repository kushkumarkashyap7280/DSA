// 2016. Maximum Difference Between Increasing Elements

// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

/*
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

Example 1:
Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

Example 2:
Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].

Example 3:
Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

Constraints:
n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum difference between increasing elements
// Time complexity: O(n) - single pass through array
// Space complexity: O(1) - only using constant extra space
int maximumDifference(vector<int> &nums)
{
  int maxDiff = -1;
  int minElement = nums[0];

  // Traverse array keeping track of minimum element seen so far
  for (int j = 1; j < nums.size(); j++)
  {
    if (nums[j] > minElement)
    {
      // Update maxDiff if we find a larger difference
      maxDiff = max(maxDiff, nums[j] - minElement);
    }
    else
    {
      // Update minimum element if we find a smaller one
      minElement = nums[j];
    }
  }

  return maxDiff;
}

int main()
{
  // Test Case 1: Standard case with positive difference
  vector<int> nums1 = {7, 1, 5, 4};
  cout << "Maximum Difference for [7,1,5,4]: " << maximumDifference(nums1) << endl; // Expected: 4

  // Test Case 2: No increasing elements
  vector<int> nums2 = {9, 4, 3, 2};
  cout << "Maximum Difference for [9,4,3,2]: " << maximumDifference(nums2) << endl; // Expected: -1

  // Test Case 3: Larger difference available
  vector<int> nums3 = {1, 5, 2, 10};
  cout << "Maximum Difference for [1,5,2,10]: " << maximumDifference(nums3) << endl; // Expected: 9

  return 0;
}
