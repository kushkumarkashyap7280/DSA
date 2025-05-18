
// Leetcode 33. Search in Rotated Sorted Array

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104



class Solution {
  public:
      int search(vector<int>& nums, int target) {
          int n = nums.size() -1;
          int i = 0 , j = n;
          while(i <j){
              int mid = i + ( j -i)/2;
              if(nums[mid] > nums[j]){
                  i = mid +1;
              }else{
                  j = mid;
              }
  
          }
          if(nums[j] == target){ return j;}
          else if(target <= nums[n] &&  target >= nums[j]){
              i = j+1;
              j = n;
          }else{
              i = 0;
              j = j -1;
          }
  
          while(i <= j){
                int mid = i + ( j -i)/2;
                if(target == nums[mid]){return mid;}
                else if(target <= nums[mid]){
                  j = mid -1;
                }else{
                  i = mid +1;
                }
          }
  
          return -1;
  
          
      }
  };