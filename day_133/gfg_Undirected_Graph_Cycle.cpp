/**
 * Detect Cycle in an Undirected Graph - GeeksforGeeks Problem
 *
 * Problem: Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][],
 * where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether
 * the graph contains a cycle or not. The graph can have multiple components.
 *
 * Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 *
 * Approach 1: BFS Traversal
 * - Create an adjacency list representation of the graph
 * - For each unvisited node, perform BFS traversal
 * - Keep track of parent for each node
 * - If we find an already visited node that's not the parent of current node, we found a cycle
 *
 * Approach 2: DFS Traversal
 * - Create an adjacency list representation of the graph
 * - For each unvisited node, perform DFS traversal
 * - Keep track of parent for each node
 * - If we find an already visited node that's not the parent of current node, we found a cycle
 *
 * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
 * Space Complexity: O(V) for the queue/recursion stack, visited array, and parent array
 *
 * Test Cases:
 *
 * Example 1:
 * Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
 * Output: true
 * Explanation: 0 -> 1 -> 2 -> 0 forms a cycle.
 *
 * Example 2:
 * Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
 * Output: false
 * Explanation: No cycle in the graph.
 *
 * Example 3:
 * Input: V = 5, E = 5, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 0]]
 * Output: true
 * Explanation: 0 -> 1 -> 2 -> 3 -> 4 -> 0 forms a cycle.
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
  // BFS Approach to detect cycle in undirected graph
  bool isCycleBFS(int V, vector<vector<int>> &edges)
  {
    // Create adjacency list from edges
    vector<vector<int>> adj(V);

    for (auto &p : edges)
    {
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]); // Undirected edge
    }

    vector<int> vis(V, 0), parent(V, -1);

    // Check each component (for disconnected graphs)
    for (int i = 0; i < V; i++)
    {
      if (vis[i])
        continue; // Skip already visited nodes

      queue<int> q;
      q.push(i);
      vis[i] = true;
      parent[i] = -1; // Start node has no parent

      // Standard BFS
      while (!q.empty())
      {
        int currNode = q.front();
        q.pop();

        // Check all neighbors
        for (int j : adj[currNode])
        {
          if (!vis[j])
          {
            // If not visited, mark as visited and update parent
            q.push(j);
            vis[j] = true;
            parent[j] = currNode;
          }
          else if (parent[currNode] != j)
          {
            // If visited and not the parent, we found a cycle
            return true;
          }
        }
      }
    }

    return false; // No cycle found
  }

  // DFS approach to detect cycle in undirected graph
  bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis)
  {
    vis[node] = 1; // Mark current node as visited

    // Check all adjacent nodes
    for (int neighbor : adj[node])
    {
      if (!vis[neighbor])
      {
        // If not visited, recursively check
        if (dfs(neighbor, node, adj, vis))
          return true; // Cycle found in subtree
      }
      // If neighbor is visited and not the parent, we found a back edge (cycle)
      else if (neighbor != parent)
      {
        return true;
      }
    }
    return false; // No cycle found
  }

  // Main function to detect cycle using DFS
  bool isCycle(int V, vector<vector<int>> &edges)
  {
    // Create adjacency list from edges
    vector<vector<int>> adj(V);

    for (auto &p : edges)
    {
      adj[p[0]].push_back(p[1]);
      adj[p[1]].push_back(p[0]); // Undirected edge
    }

    vector<int> vis(V, 0); // Track visited nodes

    // Check each component (for disconnected graphs)
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, -1, adj, vis))
          return true; // Cycle found
      }
    }
    return false; // No cycle found
  }
};

/**
 * Main function for testing
 */
int main()
{
  // Example 1: Graph with a cycle
  /*
      0 -- 1
      |    |
      2 -- 3
  */
  int V1 = 4;
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};

  Solution sol;
  cout << "Example 1 (Graph with cycle):" << endl;
  cout << "BFS Approach: " << (sol.isCycleBFS(V1, edges1) ? "Cycle detected" : "No cycle") << endl;
  cout << "DFS Approach: " << (sol.isCycle(V1, edges1) ? "Cycle detected" : "No cycle") << endl;

  // Example 2: Graph without a cycle
  /*
      0 -- 1 -- 2 -- 3
  */
  int V2 = 4;
  vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};

  cout << "\nExample 2 (Graph without cycle):" << endl;
  cout << "BFS Approach: " << (sol.isCycleBFS(V2, edges2) ? "Cycle detected" : "No cycle") << endl;
  cout << "DFS Approach: " << (sol.isCycle(V2, edges2) ? "Cycle detected" : "No cycle") << endl;

  return 0;
}
