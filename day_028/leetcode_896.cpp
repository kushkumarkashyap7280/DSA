// Monotonic array

// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 

// Example 1:

// Input: nums = [1,2,2,3]
// Output: true
// Example 2:

// Input: nums = [6,5,4,4]
// Output: true
// Example 3:

// Input: nums = [1,3,2]
// Output: false
 

// Constraints:

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105



#include <iostream>
#include <vector>
using namespace std;


// my approach ; 
//  bool isMonotonic(vector<int>& nums) {
    //     int s = nums.size() -1;
    //     int i = 0;
    //     while(i < s && nums[i]==nums[i+1]) i++;
    //     if(i < s && nums[i]> nums[i+1]){
    //         while(i < s){
    //             if(nums[i] < nums[i+1]) return 0;
    //             i++;
    //         }
    //     }else if(i < s && nums[i] < nums[i+1]){
    //         while(i < s){
    //             if(nums[i] > nums[i+1]) return 0;
    //             i++;
    //         }
    //     }
    //     return 1;
    // }
// Time complexity : O(n)
// Space complexity : O(1)

// 2nd approach :
bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true, dec = true;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) dec = false;
            if(nums[i] < nums[i-1]) inc = false;
        }
        return inc || dec;
    }
// Time complexity : O(n)
// Space complexity : O(1)



int main() {
  
    vector<int> nums = {1, 2, 2, 3};
    if (isMonotonic(nums)) {
        cout << "The array is monotonic." << endl;
    } else {
        cout << "The array is not monotonic." << endl;
    }
return 0;
}