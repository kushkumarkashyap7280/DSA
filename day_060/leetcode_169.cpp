//169. Majority Element
// https://leetcode.com/problems/majority-element/

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// using unordered_map
// Time Complexity: O(n)
// Space Complexity: O(n)
int majorityElement_map(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > nums.size() / 2) {
            return num;
        }
    }
    return -1; // This line should never be reached as per problem constraints.
}

// Function to find the majority element using Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}


int main() {
    vector<int> nums1 = {3, 2, 3};
    cout << "Majority Element (using map): " << majorityElement_map(nums1) << endl;
    
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element (using Boyer-Moore): " << majorityElement(nums2) << endl;

    // Test with more cases
    vector<int> nums3 = {1, 1, 2, 2, 1};
    cout << "Majority Element (using Boyer-Moore): " << majorityElement(nums3) << endl;
return 0;
}