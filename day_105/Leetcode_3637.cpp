// 3637. Trionic Array I

// link - https://leetcode.com/problems/trionic-array-i/

#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.



Example 1:

Input: nums = [1,3,5,4,2,6]

Output: true

Explanation:

Pick p = 2, q = 4:

nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
nums[4...5] = [2, 6] is strictly increasing (2 < 6).
Example 2:

Input: nums = [2,1,3]

Output: false

Explanation:

There is no way to pick p and q to form the required three segments.



Constraints:

3 <= n <= 100
-1000 <= nums[i] <= 1000
*/

class Solution
{
public:
  bool isTrionic(vector<int> &nums)
  {
    int s = nums.size();
    if (s < 4)
      return false; // need at least 4 for up-down-up

    int i = 0;

    // Phase 1: strictly increasing
    while (i + 1 < s && nums[i] < nums[i + 1])
      i++;
    int p = i;

    // Phase 2: strictly decreasing
    while (i + 1 < s && nums[i] > nums[i + 1])
      i++;
    int q = i;

    // Phase 3: strictly increasing
    while (i + 1 < s && nums[i] < nums[i + 1])
      i++;

    return p > 0 && q > p && q < s - 1 && i == s - 1;
  }
};

// Test cases and complexity analysis
int main()
{
  Solution sol;

  // Test Case 1: Valid trionic array
  vector<int> nums1 = {1, 3, 5, 4, 2, 6};
  cout << "Test Case 1: [1, 3, 5, 4, 2, 6]" << endl;
  cout << "Expected: true, Got: " << (sol.isTrionic(nums1) ? "true" : "false") << endl;
  cout << "Explanation: p=2, q=4 gives [1,3,5]↑[5,4,2]↓[2,6]↑" << endl
       << endl;

  // Test Case 2: Invalid array
  vector<int> nums2 = {2, 1, 3};
  cout << "Test Case 2: [2, 1, 3]" << endl;
  cout << "Expected: false, Got: " << (sol.isTrionic(nums2) ? "true" : "false") << endl;
  cout << "Explanation: No valid p,q can form three segments" << endl
       << endl;

  // Test Case 3: Too short array
  vector<int> nums3 = {1, 2, 3};
  cout << "Test Case 3: [1, 2, 3]" << endl;
  cout << "Expected: false, Got: " << (sol.isTrionic(nums3) ? "true" : "false") << endl;
  cout << "Explanation: Need at least 4 elements" << endl
       << endl;

  // Test Case 4: Another valid trionic array
  vector<int> nums4 = {1, 2, 3, 2, 1, 2, 3};
  cout << "Test Case 4: [1, 2, 3, 2, 1, 2, 3]" << endl;
  cout << "Expected: true, Got: " << (sol.isTrionic(nums4) ? "true" : "false") << endl;
  cout << "Explanation: p=2, q=4 gives [1,2,3]↑[3,2,1]↓[1,2,3]↑" << endl
       << endl;

  // Test Case 5: All increasing
  vector<int> nums5 = {1, 2, 3, 4, 5};
  cout << "Test Case 5: [1, 2, 3, 4, 5]" << endl;
  cout << "Expected: false, Got: " << (sol.isTrionic(nums5) ? "true" : "false") << endl;
  cout << "Explanation: No decreasing segment" << endl
       << endl;

  // Test Case 6: All decreasing
  vector<int> nums6 = {5, 4, 3, 2, 1};
  cout << "Test Case 6: [5, 4, 3, 2, 1]" << endl;
  cout << "Expected: false, Got: " << (sol.isTrionic(nums6) ? "true" : "false") << endl;
  cout << "Explanation: No increasing segment at start" << endl
       << endl;

  return 0;
}

/*
Time Complexity: O(n)
- We traverse the array only once
- Each element is visited at most once in each phase
- Total time complexity is O(n) where n is the length of the array

Space Complexity: O(1)
- We only use a constant amount of extra space for variables i, p, q, s
- No additional data structures are used
- Space complexity is O(1)

Algorithm:
1. Check if array has at least 4 elements (minimum required for up-down-up pattern)
2. Find the first increasing segment (Phase 1)
3. Find the decreasing segment (Phase 2)
4. Find the final increasing segment (Phase 3)
5. Verify that p > 0, q > p, q < n-1, and we reached the end of array

The algorithm efficiently identifies the trionic pattern by scanning the array once
and checking for the required three-phase pattern: strictly increasing → strictly
decreasing → strictly increasing.
*/