// 81. Search in Rotated Sorted Array II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

class Solution
{
public:
  bool search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target)
      {
        return true;
      }

      // Handle duplicates at boundaries
      if (nums[left] == nums[mid] && nums[mid] == nums[right])
      {
        left++;
        right--;
        continue;
      }

      // Check if left half is sorted
      if (nums[left] <= nums[mid])
      {
        if (nums[left] <= target && target < nums[mid])
        {
          right = mid - 1;
        }
        else
        {
          left = mid + 1;
        }
      }
      // Right half is sorted
      else
      {
        if (nums[mid] < target && target <= nums[right])
        {
          left = mid + 1;
        }
        else
        {
          right = mid - 1;
        }
      }
    }

    return false;
  }
};

// Time Complexity: O(log n) in average case, O(n) in worst case when many duplicates
// Space Complexity: O(1) - We use only a constant amount of extra space

// Function to print array
void printArray(const vector<int> &nums)
{
  cout << "[";
  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i];
    if (i < nums.size() - 1)
      cout << ",";
  }
  cout << "]";
}

int main()
{
  Solution solution;

  // Test Case 1: Example 1
  cout << "Test Case 1:" << endl;
  vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
  int target1 = 0;
  cout << "Input: nums = ";
  printArray(nums1);
  cout << ", target = " << target1 << endl;

  bool result1 = solution.search(nums1, target1);
  cout << "Output: " << (result1 ? "true" : "false") << endl
       << endl;

  // Test Case 2: Example 2
  cout << "Test Case 2:" << endl;
  vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
  int target2 = 3;
  cout << "Input: nums = ";
  printArray(nums2);
  cout << ", target = " << target2 << endl;

  bool result2 = solution.search(nums2, target2);
  cout << "Output: " << (result2 ? "true" : "false") << endl
       << endl;

  // Test Case 3: Target found in rotated array
  cout << "Test Case 3:" << endl;
  vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
  int target3 = 1;
  cout << "Input: nums = ";
  printArray(nums3);
  cout << ", target = " << target3 << endl;

  bool result3 = solution.search(nums3, target3);
  cout << "Output: " << (result3 ? "true" : "false") << endl
       << endl;

  // Test Case 4: Target not found
  cout << "Test Case 4:" << endl;
  vector<int> nums4 = {4, 5, 6, 7, 0, 1, 2};
  int target4 = 8;
  cout << "Input: nums = ";
  printArray(nums4);
  cout << ", target = " << target4 << endl;

  bool result4 = solution.search(nums4, target4);
  cout << "Output: " << (result4 ? "true" : "false") << endl
       << endl;

  // Test Case 5: All same elements
  cout << "Test Case 5:" << endl;
  vector<int> nums5 = {1, 1, 1, 1, 1, 1, 1};
  int target5 = 1;
  cout << "Input: nums = ";
  printArray(nums5);
  cout << ", target = " << target5 << endl;

  bool result5 = solution.search(nums5, target5);
  cout << "Output: " << (result5 ? "true" : "false") << endl
       << endl;

  // Test Case 6: All same elements, target not found
  cout << "Test Case 6:" << endl;
  vector<int> nums6 = {1, 1, 1, 1, 1, 1, 1};
  int target6 = 2;
  cout << "Input: nums = ";
  printArray(nums6);
  cout << ", target = " << target6 << endl;

  bool result6 = solution.search(nums6, target6);
  cout << "Output: " << (result6 ? "true" : "false") << endl
       << endl;

  // Test Case 7: Single element
  cout << "Test Case 7:" << endl;
  vector<int> nums7 = {5};
  int target7 = 5;
  cout << "Input: nums = ";
  printArray(nums7);
  cout << ", target = " << target7 << endl;

  bool result7 = solution.search(nums7, target7);
  cout << "Output: " << (result7 ? "true" : "false") << endl
       << endl;

  // Test Case 8: Two elements
  cout << "Test Case 8:" << endl;
  vector<int> nums8 = {3, 1};
  int target8 = 1;
  cout << "Input: nums = ";
  printArray(nums8);
  cout << ", target = " << target8 << endl;

  bool result8 = solution.search(nums8, target8);
  cout << "Output: " << (result8 ? "true" : "false") << endl
       << endl;

  return 0;
}