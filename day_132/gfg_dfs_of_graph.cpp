/**
 * DFS Traversal of Graph - GeeksforGeeks Problem
 *
 * Problem: Given a connected undirected graph, perform a Depth First Search (DFS)
 * traversal starting from vertex 0.
 *
 * Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
 *
 * Problem Statement:
 * Given a connected undirected graph containing V vertices represented by a 2-d adjacency
 * list adj[][], where each adj[i] represents the list of vertices connected to vertex i.
 * Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices
 * from left to right as per the given adjacency list, and return a list containing the
 * DFS traversal of the graph.
 *
 * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
 * Space Complexity: O(V) for the recursive call stack and visited map
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Solution class for the DFS traversal problem
 */
class Solution
{
private:
  /**
   * Helper function to perform DFS recursively
   *
   * @param val Current node being visited
   * @param ans Vector to store DFS traversal result
   * @param adj Adjacency list representation of the graph
   * @param isVisited Map to track visited vertices
   */
  void util(int val, vector<int> &ans, vector<vector<int>> &adj, unordered_map<int, bool> &isVisited)
  {
    if (isVisited[val])
      return; // Already visited, return

    // Mark current node as visited and add to result
    ans.push_back(val);
    isVisited[val] = true;

    // Recursively visit all unvisited neighbors
    for (int nbr : adj[val])
    {
      if (!isVisited[nbr])
      {
        util(nbr, ans, adj, isVisited);
      }
    }
  }

public:
  /**
   * Performs DFS traversal of a graph (handles disconnected graphs too)
   *
   * @param adj Adjacency list representation of the graph
   * @return Vector containing the DFS traversal order
   */
  vector<int> dfs(vector<vector<int>> &adj)
  {
    int n = adj.size();                 // Number of vertices
    vector<int> ans;                    // To store the DFS traversal result
    unordered_map<int, bool> isVisited; // Track visited vertices

    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
    {
      isVisited[i] = false;
    }

    // Handle all components (for disconnected graphs)
    // Start from vertex 0 and visit all vertices in its component first
    for (int i = 0; i < n; i++)
    {
      if (!isVisited[i])
      {
        util(i, ans, adj, isVisited);
      }
    }

    return ans;
  }
};

/**
 * Example usage:
 *
 * Example 1:
 * Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
 * Output: [0, 2, 4, 3, 1]
 * Explanation:
 * Starting from 0, the DFS traversal proceeds as follows:
 * Visit 0 → Visit 2 → Visit 4 → Backtrack to 2 → Backtrack to 0 →
 * Visit 3 → Backtrack to 0 → Visit 1
 *
 * Example 2:
 * Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
 * Output: [0, 1, 2, 3, 4]
 * Explanation:
 * Starting from 0, DFS visits 1, then 2, then 3, then backtracks to 2 and visits 4
 */
