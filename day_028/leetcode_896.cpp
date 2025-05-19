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
// 1st approach :
// 1. Initialize a variable s to the size of the array minus 1.
// 2. Initialize a variable i to 0.
// 3. While i is less than s and the current element is equal to the next element, increment i.
// 4. If i is less than s and the current element is greater than the next element, iterate through the array.
//    - If the current element is less than the next element, return false.
// 5. If i is less than s and the current element is less than the next element, iterate through the array.

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

// 2nd approach :(optimal approach)
// 1. Initialize two boolean variables inc and dec to true.
// 2. Iterate through the array from the second element to the last element.
// 3. For each element, compare it with the previous element.
//    - If the current element is greater than the previous element, set dec to false.
//    - If the current element is less than the previous element, set inc to false.
// 4. If both inc and dec are false, return false.
// 5. If either inc or dec is true, return true.
bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true, dec = true;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) dec = false; // decreasing
            else  if(nums[i] < nums[i-1]) inc = false; // increasing
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