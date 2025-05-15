// rotate an array of n elements to the right by k steps, where k is non-negative.
/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space? 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Using brute force
// Time complexity: O(n*k)
// Space complexity: O(1)

// void rotate(vector<int>& nums, int k) {
//         int i = 0;
//     while(i < k){
//         for(int i = nums.size()-1; i >= 1; i--){
//             swap(nums[i], nums[i-1]);
//         }
//         i++;
//     }
   
//     }


 // Approach 2 : Using reverse
// Time complexity: O(n)  
// Space complexity: O(1)
void rotate(vector<int>& nums, int k) {
  int s = nums.size();
     k = k% s ;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k , nums.end());

}  

int main() {
  // example 1:
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  rotate(nums, k);
  cout << "Rotated array: ";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  };
return 0;
}