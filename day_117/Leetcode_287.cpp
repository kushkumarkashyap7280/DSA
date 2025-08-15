// 287. Find the Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/

/*
Problem:
Given an integer array nums of length n + 1 where each number is in the range [1, n].
There is exactly one number that appears at least twice. Return the duplicate number.

Requirements:
- Do NOT modify the array (read-only)
- Use only O(1) extra space
- Run in O(n) time

Examples:
1) nums = [1,3,4,2,2] -> 2
2) nums = [3,1,3,4,2] -> 3
3) nums = [3,3,3,3,3] -> 3

Constraints:
- 1 <= n <= 1e5
- nums.length == n + 1
- 1 <= nums[i] <= n
- Exactly one value appears multiple times

Approach (Floyd's Tortoise and Hare - Cycle Detection):
Interpret the array as a linked list where next(i) = nums[i]. Since values are in [1..n],
all pointers are valid indices. The duplicate value creates a cycle. Detect the cycle
meeting point, then reset one pointer to start and move both one step at a time to
find the cycle entrance, which is the duplicate.

Time Complexity: O(n) — each pointer moves at most O(n) steps
Space Complexity: O(1) — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find intersection point inside the cycle
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find cycle entrance (duplicate value)
    slow = nums[0];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

// ---------------------
// Test Infrastructure
// ---------------------

static void expectEq(int got, int want, const string& testName) {
  if (got != want) {
    cerr << "[FAIL] " << testName << ": expected " << want << ", got " << got << "\n";
    exit(1);
  } else {
    cout << "[PASS] " << testName << "\n";
  }
}

static void runTests() {
  Solution sol;

  {
    vector<int> nums{1,3,4,2,2};
    expectEq(sol.findDuplicate(nums), 2, "Example 1");
  }
  {
    vector<int> nums{3,1,3,4,2};
    expectEq(sol.findDuplicate(nums), 3, "Example 2");
  }
  {
    vector<int> nums{3,3,3,3,3};
    expectEq(sol.findDuplicate(nums), 3, "All same");
  }
  {
    vector<int> nums{2,5,9,6,9,3,8,9,7,1};
    expectEq(sol.findDuplicate(nums), 9, "LeetCode extra");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  runTests();
  return 0;
}