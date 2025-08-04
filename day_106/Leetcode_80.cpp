// 80. Remove Duplicates from Sorted Array II

#include <iostream>
#include <vector>
using namespace std;

// link -https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 2)
      return n;

    int idx = 2; // Index where the next valid element should go

    for (int i = 2; i < n; i++)
    {
      // If current number is not the same as nums[idx - 2], we can keep it
      if (nums[i] != nums[idx - 2])
      {
        nums[idx] = nums[i];
        idx++;
      }
    }

    return idx;
  }
};

// Time Complexity: O(n) - We traverse the array once
// Space Complexity: O(1) - We use only a constant amount of extra space

// Function to print array
void printArray(const vector<int> &nums, int k)
{
  cout << "[";
  for (int i = 0; i < k; i++)
  {
    cout << nums[i];
    if (i < k - 1)
      cout << ",";
  }
  cout << "]";
}

int main()
{
  Solution solution;

  // Test Case 1: Example 1
  cout << "Test Case 1:" << endl;
  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  cout << "Input: ";
  printArray(nums1, nums1.size());
  cout << endl;

  int k1 = solution.removeDuplicates(nums1);
  cout << "Output: " << k1 << ", nums = ";
  printArray(nums1, k1);
  cout << endl
       << endl;

  // Test Case 2: Example 2
  cout << "Test Case 2:" << endl;
  vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  cout << "Input: ";
  printArray(nums2, nums2.size());
  cout << endl;

  int k2 = solution.removeDuplicates(nums2);
  cout << "Output: " << k2 << ", nums = ";
  printArray(nums2, k2);
  cout << endl
       << endl;

  // Test Case 3: Single element
  cout << "Test Case 3:" << endl;
  vector<int> nums3 = {5};
  cout << "Input: ";
  printArray(nums3, nums3.size());
  cout << endl;

  int k3 = solution.removeDuplicates(nums3);
  cout << "Output: " << k3 << ", nums = ";
  printArray(nums3, k3);
  cout << endl
       << endl;

  // Test Case 4: Two elements
  cout << "Test Case 4:" << endl;
  vector<int> nums4 = {1, 2};
  cout << "Input: ";
  printArray(nums4, nums4.size());
  cout << endl;

  int k4 = solution.removeDuplicates(nums4);
  cout << "Output: " << k4 << ", nums = ";
  printArray(nums4, k4);
  cout << endl
       << endl;

  // Test Case 5: All same elements
  cout << "Test Case 5:" << endl;
  vector<int> nums5 = {3, 3, 3, 3, 3};
  cout << "Input: ";
  printArray(nums5, nums5.size());
  cout << endl;

  int k5 = solution.removeDuplicates(nums5);
  cout << "Output: " << k5 << ", nums = ";
  printArray(nums5, k5);
  cout << endl
       << endl;

  // Test Case 6: No duplicates
  cout << "Test Case 6:" << endl;
  vector<int> nums6 = {1, 2, 3, 4, 5};
  cout << "Input: ";
  printArray(nums6, nums6.size());
  cout << endl;

  int k6 = solution.removeDuplicates(nums6);
  cout << "Output: " << k6 << ", nums = ";
  printArray(nums6, k6);
  cout << endl
       << endl;

  return 0;
}