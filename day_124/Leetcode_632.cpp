#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// 632. Smallest Range Covering Elements from K Lists
// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

/*
Problem:
Given k sorted lists, find the smallest range that includes at least one number from each list.

Approach:
- Use a min-heap to always get the smallest current element among all lists.
- Track the current maximum value among the heap elements.
- At each step, update the range if the current [min, max] is smaller.
- Move forward in the list from which the min element was taken, pushing the next element into the heap and updating the max.
- Stop when any list is exhausted (since the range must include at least one from each list).

Key Insights:
- The heap always contains one element from each list.
- The range is updated only if it is smaller than the previous best.
- Efficiently finds the minimum window covering all lists.

Time Complexity: O(N log k), where N is the total number of elements and k is the number of lists.
Space Complexity: O(k) for the heap.
*/

using node = pair<int, pair<int, int>>;
struct compare
{
  bool operator()(node a, node b)
  {
    return a.first > b.first; // min-heap
  }
};

class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    int k = nums.size();
    priority_queue<node, vector<node>, compare> pq;
    int currMax = INT_MIN;
    // Push first element of each list
    for (int i = 0; i < k; i++)
    {
      pq.push({nums[i][0], {i, 0}});
      currMax = max(currMax, nums[i][0]);
    }
    int start = pq.top().first, end = currMax;
    // Main loop: always keep one element from each list in the heap
    while (pq.size() == k)
    {
      auto top = pq.top();
      pq.pop();
      int val = top.first;
      int row = top.second.first;
      int col = top.second.second;
      // Update range if smaller
      if (currMax - val < end - start)
      {
        start = val;
        end = currMax;
      }
      // Move to next element in the same list
      if (col + 1 < nums[row].size())
      {
        int nextVal = nums[row][col + 1];
        pq.push({nextVal, {row, col + 1}});
        currMax = max(currMax, nextVal);
      }
      else
      {
        break; // One list exhausted
      }
    }
    return {start, end};
  }
};
