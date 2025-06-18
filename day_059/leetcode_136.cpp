//136. Single Number
//https://leetcode.com/problems/single-number/


/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Using XOR operation
// Time Complexity: O(n)
// Space Complexity: O(1)
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR operation
    }
    return result;
}

//approach: Using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
int singleNumberHashMap(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }
    for (const auto& pair : countMap) {
        if (pair.second == 1) {
            return pair.first;
        }
    }
    return -1; // This line should never be reached given the problem constraints
}

int main() {
    vector<int> nums1 = {2, 2, 1};
    cout << "Single number in nums1: " << singleNumber(nums1) << endl; // Output: 1

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Single number in nums2: " << singleNumber(nums2) << endl; // Output: 4

    vector<int> nums3 = {1};
    cout << "Single number in nums3: " << singleNumber(nums3) << endl; // Output: 1

    // Using Hash Map approach
    cout << "Single number in nums1 using Hash Map: " << singleNumberHashMap(nums1) << endl; // Output: 1
    cout << "Single number in nums2 using Hash Map: " << singleNumberHashMap(nums2) << endl; // Output: 4
    cout << "Single number in nums3 using Hash Map: " << singleNumberHashMap(nums3) << endl; // Output: 1
return 0;
}