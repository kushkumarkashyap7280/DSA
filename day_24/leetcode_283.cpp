// moves zeroes to the end of the array
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// my code which i tried and workes but it is not optimal solution;

//  void moveZeroes(vector<int>& nums) {
//        for(int i = nums.size(); i >=0 ; i--){
//          int j = 0;
//         while( j <= nums.size() -1 ){
//             if(nums[j] == 0 && j+1 <= nums.size()-1){
//                swap(nums[j],nums[j+1]);
//             }
//             j++;
//         }
//        }
//     }



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Function to merge two sorted arrays
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    
    // Use two pointers: one for current, one for last non-zero
    int lastNonZeroIndex = 0;

    // Move all non-zero elements forward (overwrite)
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[lastNonZeroIndex++], nums[i]);
        }
    }
}


int main() {
    // Example usage
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
  
 
return 0;
}