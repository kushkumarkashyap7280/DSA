// 26. Remove Duplicates from Sorted Array

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
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

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array(not optimal solution)
// time complexity: O(n2)
// space complexity: O(1)
// int removeDuplicates(vector<int> &nums)
// {
//   int i = 0;
//   int j = i + 1;
//   while (j < nums.size() && i < j)
//   {
//     if (nums[j] == nums[i])
//     {
//       nums.erase(nums.begin() + j, nums.begin() + j + 1);
//     }
//     else
//     {
//       j++;
//       i++;
//     }
//   }
//   return nums.size();
// }
// Function to remove duplicates from a sorted array (optimal solution)
// time complexity: O(n)
// space complexity: O(1)
int removeDuplicates(vector<int>& nums) {
        int element = nums[0];
        int i = 1 ;
        int j = 1;
        while(j < nums.size() ){
            if(nums[j] == element){
                j++;
                continue;
            }else{
                element =nums[j];
                nums[i++]=nums[j++];
            }
        }
        return i;
    }
int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = removeDuplicates(nums);
  cout << "Number of unique elements: " << k << endl;
  cout << "Modified array: ";
  for (int i = 0; i < k; i++)
  {
    cout << nums[i] << " ";
  }
  return 0;
}