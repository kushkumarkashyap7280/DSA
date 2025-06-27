//46. Permutations

//https://leetcode.com/problems/permutations/

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//function to generate permutations
//time complexity: O(n! * n) where n is the length of the input array
void permute(vector<int> &nums, int start, vector<vector<int>> &result) {
    if (start >= nums.size()) {
        result.push_back(nums);
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack
    }
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;

    permute(nums, 0, result);

    // Print the result
    for (const auto &perm : result) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
return 0;
}