// 27. Remove Element

// https://leetcode.com/problems/remove-element/

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to remove all occurrences of val in nums in-place
// first approach not optimal
// Time Complexity: O(n^2) due to erase operation inside a loop
// Space Complexity: O(1) since we are modifying the input array in-place
int removeElement(vector<int> &nums, int val)
{
  int i = 0;
  while (i < nums.size())
  {
    if (nums[i] == val)
    {
      nums.erase(nums.begin() + i);
    }
    else
    {
      i++;
    }
  }
  return nums.size();
}

// Optimized approach
// Time Complexity: O(n)
// Space Complexity: O(1) since we are modifying the input array in-place
int removeElementOptimized(vector<int> &nums, int val)
{
  int k = 0; // Count of elements not equal to val
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != val)
    {
      nums[k++] = nums[i]; // Place the element at the next position
    }
  }
  return k; // Return the count of elements not equal to val
}
int main()
{
  vector<int> nums1 = {3, 2, 2, 3};
  int val1 = 3;
  int k1 = removeElement(nums1, val1);
  cout << "k1: " << k1 << ", nums1: ";
  for (int i = 0; i < k1; i++)
    cout << nums1[i] << " ";
  cout << endl;

  vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
  int val2 = 2;
  int k2 = removeElementOptimized(nums2, val2);
  cout << "k2: " << k2 << ", nums2: ";
  for (int i = 0; i < k2; i++)
    cout << nums2[i] << " ";
  cout << endl;

  return 0;
}