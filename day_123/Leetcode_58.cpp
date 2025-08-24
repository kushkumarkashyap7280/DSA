#include <vector>
#include <climits>
using namespace std;

// 53. Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/

/*
Problem Description:
Find the contiguous subarray with the largest sum and return its sum.

Approaches:
1. Brute Force O(n^2):
   - Check all possible subarrays
   - Keep track of maximum sum
   - Nested loops for start and end points

2. Kadane's Algorithm O(n):
   - Key insight: If current sum becomes negative, discard it
   - Maintain two variables:
     * currSum: tracks current subarray sum
     * maxSum: tracks overall maximum sum
   - If currSum < 0, reset to 0 (start new subarray)
   - Continuously update maxSum

Example Walk-through:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Kadane's Algorithm Steps:
1. [-2]: currSum=-2, maxSum=-2
2. [1]: currSum=1, maxSum=1 (reset currSum after -2)
3. [-3]: currSum=-2, maxSum=1
4. [4]: currSum=4, maxSum=4 (reset currSum after negative)
5. [-1]: currSum=3, maxSum=4
6. [2]: currSum=5, maxSum=5
7. [1]: currSum=6, maxSum=6
8. [-5]: currSum=1, maxSum=6
9. [4]: currSum=5, maxSum=6

Final Result: 6 (subarray [4,-1,2,1])

Time Complexity: O(n)
Space Complexity: O(1)



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution
{
public:
  // brute force
  // int maxSubArray(vector<int>& nums) {

  //     int ans = INT_MIN;

  //   for(int i = 0; i < nums.size(); i++){
  //       int sum = 0;
  //       for(int j = i ; j < nums.size(); j++){
  //           sum += nums[j];
  //           if(sum > ans ) ans = sum;
  //       }
  //   }

  //   return ans;

  // }

  // kadane algo
  int maxSubArray(vector<int> &nums)
  {
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      currSum += nums[i];
      maxSum = max(currSum, maxSum);
      if (currSum < 0)
        currSum = 0;
    }
    return maxSum;
  }
};