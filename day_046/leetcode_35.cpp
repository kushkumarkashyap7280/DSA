// 35. Search Insert Position

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
#include <iostream>
#include <vector>
using namespace std;

// using binary search to find the index
// time complexity: O(log n)
// space complexity: O(1)
int searchInsert(vector<int> &nums, int target)
{

  int i = 0;
  int j = nums.size() - 1;
  int m = i + (j - i) / 2;
  while (i <= j)
  {

    if (nums[m] == target)
    {
      return m;
    }
    else if (nums[m] < target)
    {
      i = m + 1;
    }
    else
    {
      j = m - 1;
    }
    m = i + (j - i) / 2;
  }
  return m;
}
int main()
{
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  int index = searchInsert(nums, target);
  cout << "The index of the target " << target << " is: " << index << endl;
  return 0;
}