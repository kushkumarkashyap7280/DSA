// 75. Sort Colors

// https://leetcode.com/problems/sort-colors/

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// my approach:
// The idea is to count the occurrences of each color (0, 1, 2) and then overwrite the original array with the counted values.
// time complexity: O(n), space complexity: O(n)
// The function sorts the colors in-place, so we don't need to return anything.
// Note: This approach uses extra space for the unordered_map to count occurrences.
// However, it is not a one-pass algorithm and does not use constant extra space.
void sortColors(vector<int> &nums)
{

  unordered_map<int, int> mymap;
  for (int i : nums)
  {
    mymap[i]++;
  }
  int val = 0;
  int i = 0;
  while (i < nums.size())
  {
    if (val > 2)
      return;
    int count = mymap[val];
    while (count)
    {
      nums[i] = val;
      i++;
      count--;
    }
    val++;
  }
}

// Optimized approach: Dutch National Flag problem
// The idea is to use three pointers: low, mid, and high.
// low points to the next position for 0, mid is the current element being processed, and high points to the next position for 2.
// time complexity: O(n), space complexity: O(1)
void sortColorsoptimised(vector<int> &nums)
{
  int low = 0;
  int mid = 0;
  int high = nums.size() - 1;
  while (mid <= high)
  {
    switch (nums[mid])
    {
    case 0:
      swap(nums[low], nums[mid]);
      low++;
      mid++;
      break;

    case 1:
      mid++;
      break;

    case 2:
      swap(nums[mid], nums[high]);
      high--;
      break;
    }
  }
}
int main()
{

  vector<int> nums = {2, 0, 2, 1, 1, 0};
  cout << "Original colors: ";
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;
  // Sort the colors using the sortColors function
  // time complexity: O(n), space complexity: O(n)
  // The function sorts the colors in-place, so we don't need to return anything.
  sortColors(nums);

  cout << "Sorted colors: ";
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  // Optimized approach: Dutch National Flag problem
  vector<int> nums2 = {2, 0, 1};
  cout << "Original colors: ";
  for (int num : nums2)
  {
    cout << num << " ";
  }
  cout << endl;
  // Sort the colors using the optimized sortColors function
  // time complexity: O(n), space complexity: O(1)
  sortColorsoptimised(nums2);
  cout << "Sorted colors: ";
  for (int num : nums2)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;

}