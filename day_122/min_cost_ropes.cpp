#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Minimum Cost of Ropes
// Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

/*
Problem Description:
Given an array of rope lengths, connect all ropes into a single rope with minimum total cost.
The cost to connect two ropes is the sum of their lengths.

Time Complexity: O(N log N)
- Building min heap: O(N)
- N-1 extract-min operations: O(N log N)
- N-1 insert operations: O(N log N)

Space Complexity: O(N)
- Priority queue storing all rope lengths

Key Insights:
1. Always connect shortest ropes first to minimize cost
2. Use min heap to efficiently find two shortest ropes
3. After connecting, new rope length must be considered for future connections
4. Running cost must be accumulated at each step
5. Process continues until only one rope remains

Example Test Cases:

1. Basic Case:
   Input: [4, 3, 2, 6]
   Steps:
   - Connect 2,3 → [4,5,6] (cost=5)
   - Connect 4,5 → [6,9] (cost=9)
   - Connect 6,9 → [15] (cost=15)
   Total cost = 5+9+15 = 29

2. Multiple Equal Lengths:
   Input: [5, 5, 5, 5]
   Steps:
   - Connect 5,5 → [5,5,10] (cost=10)
   - Connect 5,5 → [10,10] (cost=10)
   - Connect 10,10 → [20] (cost=20)
   Total cost = 10+10+20 = 40

3. Single Rope:
   Input: [10]
   Output: 0 (no connections needed)

4. Increasing Lengths:
   Input: [2, 4, 6, 8]
   Steps:
   - Connect 2,4 → [6,6,8] (cost=6)
   - Connect 6,6 → [8,12] (cost=12)
   - Connect 8,12 → [20] (cost=20)
   Total cost = 6+12+20 = 38

5. Large Numbers:
   Input: [100, 200, 300, 400]
   Steps: Similar pattern, but with larger numbers
*/

class Solution
{
public:
  int minCost(vector<int> &arr)
  {
    // Base case: if only one rope, no connections needed
    if (arr.size() == 1)
    {
      return 0;
    }

    // Create min heap to always get shortest ropes first
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int totalCost = 0;

    // Keep connecting ropes until only one remains
    while (pq.size() > 1)
    {
      // Get two shortest ropes
      int firstRope = pq.top();
      pq.pop();
      int secondRope = pq.top();
      pq.pop();

      // Connect ropes and calculate cost
      int newRopeLength = firstRope + secondRope;
      totalCost += newRopeLength;

      // Add new rope back to heap for future connections
      pq.push(newRopeLength);
    }

    return totalCost;
  }
};

// Test function to print test case results
void printTestResult(const vector<int> &ropes, int expectedCost)
{
  Solution sol;
  vector<int> test = ropes; // Create copy to preserve original
  int actualCost = sol.minCost(test);

  cout << "Input: [";
  for (int i = 0; i < ropes.size(); i++)
  {
    cout << ropes[i];
    if (i < ropes.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;

  cout << "Expected Cost: " << expectedCost << endl;
  cout << "Actual Cost: " << actualCost << endl;
  cout << "Test " << (actualCost == expectedCost ? "PASSED" : "FAILED") << endl;
  cout << "------------------------" << endl;
}

// Main function with test cases
int main()
{
  // Test Case 1: Basic case
  printTestResult({4, 3, 2, 6}, 29);

  // Test Case 2: Multiple equal lengths
  printTestResult({5, 5, 5, 5}, 40);

  // Test Case 3: Single rope
  printTestResult({10}, 0);

  // Test Case 4: Increasing lengths
  printTestResult({2, 4, 6, 8}, 38);

  // Test Case 5: Large numbers
  printTestResult({100, 200, 300, 400}, 2000);

  return 0;
}
