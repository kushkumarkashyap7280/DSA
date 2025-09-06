/**
 * Detect Cycle in a Directed Graph - GeeksforGeeks Problem
 *
 * Problem: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
 * check whether it contains any cycle or not.
 *
 * Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 *
 * Approach:
 * - We use DFS traversal with a concept of recursion stack (or same path stack)
 * - For each vertex, we check if it's part of a cycle
 * - If during DFS we encounter a vertex that is already in the current recursion stack, we found a cycle
 * - If a vertex is visited but not in the recursion stack, it means we have already checked it (no cycle there)
 *
 * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
 * Space Complexity: O(V) for visited array, recursion stack array, and recursion call stack
 *
 * Test Cases:
 *
 * Example 1:
 * Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
 * Output: true
 * Explanation: The diagram shows a cycle 0 → 2 → 0
 *
 * Example 2:
 * Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
 * Output: false
 * Explanation: No cycle in the graph
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
  /**
   * Helper function for DFS traversal to detect cycle
   *
   * @param node Current node being visited
   * @param adj Adjacency list representation of the graph
   * @param isVisited Track visited vertices
   * @param sameStack Track vertices in current recursion stack (same path)
   * @return true if cycle detected, false otherwise
   */
  bool dfs(int node,
           vector<vector<int>> &adj, vector<int> &isVisited, vector<int> &sameStack)
  {
    isVisited[node] = 1; // Mark current node as visited
    sameStack[node] = 1; // Add current node to recursion stack

    // Check all neighbors
    for (auto i : adj[node])
    {
      if (!isVisited[i])
      {
        // If not visited, recursively check
        if (dfs(i, adj, isVisited, sameStack))
          return true;
      }
      else if (sameStack[i] == 1)
      {
        // If already in recursion stack, we found a cycle
        return true;
      }
    }

    // Remove current node from recursion stack (backtrack)
    sameStack[node] = 0;
    return false;
  }

  /**
   * Alternative approach using Kahn's algorithm (BFS-based topological sort)
   * If a directed graph has a cycle, topological sort can't include all vertices
   *
   * @param V Number of vertices
   * @param adj Adjacency list representation of the graph
   * @return true if cycle detected, false otherwise
   */
  bool isCyclicBFS(int V, vector<vector<int>> &adj)
  {
    // Calculate in-degree for each vertex
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
      for (auto neighbor : adj[i])
      {
        inDegree[neighbor]++;
      }
    }

    // Queue for BFS (start with all vertices having in-degree 0)
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (inDegree[i] == 0)
      {
        q.push(i);
      }
    }

    int visitedCount = 0;

    // Process vertices in topological order
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      visitedCount++;

      // Reduce in-degree of neighbors
      for (auto neighbor : adj[curr])
      {
        inDegree[neighbor]--;
        // If in-degree becomes 0, add to queue
        if (inDegree[neighbor] == 0)
        {
          q.push(neighbor);
        }
      }
    }

    // If we couldn't visit all vertices, there's a cycle
    return visitedCount != V;
  }

public:
  /**
   * Main function to detect cycle in directed graph using DFS approach
   *
   * @param V Number of vertices
   * @param edges Edges of the graph
   * @return true if cycle detected, false otherwise
   */
  bool isCyclic(int V, vector<vector<int>> &edges)
  {

    // Create adjacency list from edges
    vector<vector<int>> adj(V);
    for (auto &pair : edges)
    {
      adj[pair[0]].push_back(pair[1]);
    }

    vector<int> isVisited(V, 0), sameStack(V, 0);

    // Comment the following block and uncomment the next line to use BFS approach
    // Check each component (for disconnected graphs)
    for (int i = 0; i < V; i++)
    {
      if (!isVisited[i])
      {
        if (dfs(i, adj, isVisited, sameStack))
          return true;
      }
    }
    return false; // No cycle found

    // Uncomment to use BFS approach (Kahn's algorithm)
    // return isCyclicBFS(V, adj);
  }
};

/**
 * Main function for testing
 */
int main()
{
  // Example 1: Graph with a cycle
  /*
      0 → 1
      ↓ ↙
      2 → 3
      ↑
      |
      0
  */
  int V1 = 4;
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

  Solution sol;
  cout << "Example 1 (Graph with cycle):" << endl;
  cout << "Result: " << (sol.isCyclic(V1, edges1) ? "Cycle detected" : "No cycle") << endl;
  cout << "Expected: Cycle detected" << endl;

  // Example 2: Graph without a cycle
  /*
      0 → 1
      ↓ ↙
      2 → 3
  */
  int V2 = 4;
  vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

  cout << "\nExample 2 (Graph without cycle):" << endl;
  cout << "Result: " << (sol.isCyclic(V2, edges2) ? "Cycle detected" : "No cycle") << endl;
  cout << "Expected: No cycle" << endl;

  // Example 3: Another graph with a cycle
  /*
      0 → 1 → 2
          ↑   ↓
          └── 3
  */
  int V3 = 4;
  vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};

  cout << "\nExample 3 (Graph with cycle):" << endl;
  cout << "Result: " << (sol.isCyclic(V3, edges3) ? "Cycle detected" : "No cycle") << endl;
  cout << "Expected: Cycle detected" << endl;

  return 0;
}