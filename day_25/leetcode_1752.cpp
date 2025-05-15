// check if array is sorted and rotated or not;

// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

#include <iostream>
#include <vector> 
using namespace std;

// approach 1 : using brute force
// Time complexity: O(n)
 bool check(vector<int>& nums) {
        int s = nums.size();
        int breakpoints = 0;
       for( int i = 0 ; i < s-1 ; i++){
        if(nums[i] > nums[i+1]) breakpoints++;
       }
       if(breakpoints == 0) return true;
       if(breakpoints == 1){
        return nums[0]>=nums[s-1];
       }
        return false;
    }

int main(){
    vector<int> nums = {3,4,5,1,2};
    cout << check(nums) << endl; // Output: 1 (true)
    vector<int> nums2 = {2,1,3,4};
    cout << check(nums2) << endl; // Output: 0 (false)
    vector<int> nums3 = {1,2,3};
    cout << check(nums3) << endl; // Output: 1 (true)
    return 0;

}