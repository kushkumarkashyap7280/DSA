#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 3005. Count Elements With Maximum Frequency
// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/

/*
Problem:
You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

Approach:
- Use a hashmap to count the frequency of each element in the array.
- Find the maximum frequency among all elements.
- Count the total occurrences of all elements that have this maximum frequency.

Key Insights:
- Hashmap efficiently tracks element frequencies in a single pass.
- Two-phase approach: first determine max frequency, then sum occurrences.
- The answer is the product of (max frequency) × (number of elements with max frequency).

Time Complexity: O(n), where n is the number of elements in the array.
Space Complexity: O(k), where k is the number of unique elements in the array.
*/

class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    // Step 1: Count the frequency of each element using a hashmap
    unordered_map<int, int> frequencyMap;
    for (int num : nums)
    {
      frequencyMap[num]++;
    }

    // Step 2: Find the maximum frequency
    int maxFrequency = 0;
    for (auto &pair : frequencyMap)
    {
      maxFrequency = max(maxFrequency, pair.second);
    }

    // Step 3: Count total occurrences of elements with maximum frequency
    int totalCount = 0;
    for (auto &pair : frequencyMap)
    {
      if (pair.second == maxFrequency)
      {
        totalCount += pair.second;
      }
    }

    return totalCount;
  }
};