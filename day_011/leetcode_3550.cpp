// 3550. Smallest Index With Digit Sum Equal to Index

//https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

// You are given an integer array nums.

// Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

// If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,3,2]

// Output: 2

// Explanation:

// For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
// Example 2:

// Input: nums = [1,10,11]

// Output: 1

// Explanation:

// For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
// For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
// Since index 1 is the smallest, the output is 1.
// Example 3:

// Input: nums = [1,2,3]

// Output: -1

// Explanation:

// Since no index satisfies the condition, the output is -1.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

#include <iostream>
#include <vector>
using namespace std;

//fuction to  find the smallest index where the sum of digits of nums[i] is equal to i
//time complexity is O(n) and space complexity is O(1)
 int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int tempsum =0;
            int tempNo = nums[i];
             while(tempNo){
                 tempsum += tempNo%10;
                 tempNo/=10;
             }
            if(tempsum == i) return  i;
        }
        return -1;
    }
int main() {
    vector<int> nums1 = {1, 3, 2};
    vector<int> nums2 = {1, 10, 11};
    vector<int> nums3 = {1, 2, 3};

    cout << "Smallest index for nums1: " << smallestIndex(nums1) << endl; // Output: 2
    cout << "Smallest index for nums2: " << smallestIndex(nums2) << endl; // Output: 1
    cout << "Smallest index for nums3: " << smallestIndex(nums3) << endl; // Output: -1
return 0;
}