/**
 * 2360. Longest Cycle in a Graph - LeetCode Problem
 *
 * Problem: Given a directed graph with n nodes where each node has at most one outgoing edge,
 * find the length of the longest cycle in the graph. If no cycle exists, return -1.
 *
 * Link: https://leetcode.com/problems/longest-cycle-in-a-graph/
 *
 * Approach:
 * - We use a modified DFS traversal with step tracking for each node
 * - For each unvisited node, we start a DFS traversal
 * - We track the "step" at which we visit each node in the current DFS path
 * - If we encounter a previously visited node with a valid step value, we've found a cycle
 * - We calculate the cycle length as (current step - step of previously visited node + 1)
 * - We keep track of the maximum cycle length found
 *
 * Time Complexity: O(n) where n is the number of nodes (each node visited exactly once)
 * Space Complexity: O(n) for visited array, step array, and recursion call stack
 *
 * Example 1:
 * Input: edges = [3,3,4,2,3]
 * Output: 3
 * Visual representation:
 *     ┌─────┐
 *     │     ▼
 * 0───►3◄───2
 * │    │    ▲
 * └────┘    │
 *      4────┘
 * The cycle is: 2 → 4 → 3 → 2 (length 3)
 *
 * Example 2:
 * Input: edges = [2,-1,3,1]
 * Output: -1
 * Visual representation:
 * 0───►2───►3───►1
 *             │
 *             ▼
 *            -1 (no outgoing edge)
 * There are no cycles in this graph.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  /**
   * DFS helper function to find cycles in the graph
   *
   * @param node Current node being visited
   * @param edges Graph representation (adjacency list)
   * @param stepAtNode Tracks the step number at which each node was visited
   * @param isVisited Tracks visited nodes
   * @param maxNodeCycle Reference to store the maximum cycle length found
   * @param currSteps Current step count in the DFS path
   */
  void find(int node,
            vector<int> &edges,
            vector<int> &stepAtNode,
            vector<int> &isVisited,
            int &maxNodeCycle,
            int currSteps)
  {
    // Mark current node as visited
    isVisited[node] = 1;
    // Record the step at which we visited this node
    stepAtNode[node] = currSteps;

    // Get the next node (there's at most one outgoing edge per node)
    int next = edges[node];

    if (next != -1)
    { // If there's an outgoing edge
      if (isVisited[next] == 0)
      {
        // Continue DFS if next node is not visited
        find(next, edges, stepAtNode, isVisited, maxNodeCycle, currSteps + 1);
      }
      else if (stepAtNode[next] != -1)
      {
        // Cycle detected: We found a node that was already visited in the current DFS path
        // Calculate the cycle length by taking the difference in steps
        int cycleLength = currSteps - stepAtNode[next] + 1;
        maxNodeCycle = max(maxNodeCycle, cycleLength);
      }
    }

    // Important: reset stepAtNode[node] when backtracking
    // This ensures we only detect cycles in the current DFS path
    stepAtNode[node] = -1;
  }

public:
  /**
   * Find the length of the longest cycle in the graph
   *
   * @param edges Graph representation where edges[i] is the destination of node i's edge
   * @return Length of the longest cycle, or -1 if no cycle exists
   */
  int longestCycle(vector<int> &edges)
  {
    int n = edges.size();
    vector<int> stepAtNode(n, -1); // Track step at which node was visited
    vector<int> isVisited(n, 0);   // Track visited nodes
    int maxNodeCycle = -1;         // Result: longest cycle length

    // Run DFS from each unvisited node
    for (int i = 0; i < n; i++)
    {
      if (isVisited[i] == 0)
      {
        find(i, edges, stepAtNode, isVisited, maxNodeCycle, 0);
      }
    }

    return maxNodeCycle;
  }
};

/**
 * Main function with test cases
 */
int main()
{
  Solution sol;

  // Test Case 1: Graph with a cycle of length 3
  vector<int> edges1 = {3, 3, 4, 2, 3};

  cout << "Example 1:" << endl;
  cout << "Input: edges = [3, 3, 4, 2, 3]" << endl;
  cout << "Expected Output: 3" << endl;
  cout << "Actual Output: " << sol.longestCycle(edges1) << endl;
  cout << endl;

  // Test Case 2: Graph with no cycles
  vector<int> edges2 = {2, -1, 3, 1};

  cout << "Example 2:" << endl;
  cout << "Input: edges = [2, -1, 3, 1]" << endl;
  cout << "Expected Output: -1" << endl;
  cout << "Actual Output: " << sol.longestCycle(edges2) << endl;
  cout << endl;

  // Test Case 3: Graph with multiple cycles, find the longest
  vector<int> edges3 = {1, 2, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 3};
  /*
   * This creates:
   * - A 3-node cycle: 0→1→2→0
   * - A 10-node cycle: 3→4→5→6→7→8→9→10→11→12→3
   * The longest cycle has length 10
   */

  cout << "Example 3:" << endl;
  cout << "Input: edges = [1, 2, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 3]" << endl;
  cout << "Expected Output: 10" << endl;
  cout << "Actual Output: " << sol.longestCycle(edges3) << endl;

  return 0;
}