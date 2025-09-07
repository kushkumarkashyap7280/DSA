// Kahn's Algorithm for Cycle Detection in Directed Graph
// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
Output: true
Explanation: 3 -> 3 is a cycle

Input: V = 3, edges[][] = [[0, 1], [1, 2]]
Output: false
Explanation: no cycle in the graph

Constraints:
1 ≤ V, E ≤ 10^5
*/

class Solution
{
public:
  /**
   * Detects if a directed graph contains a cycle using Kahn's algorithm (BFS-based topological sort)
   *
   * Approach:
   * 1. Calculate in-degree for each vertex
   * 2. Start BFS with all vertices having in-degree 0
   * 3. For each processed vertex, reduce in-degree of adjacent vertices
   * 4. If at the end, not all vertices are processed, there must be a cycle
   *
   * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
   * Space Complexity: O(V) for queue and indegree array
   */
  bool isCyclic(int V, vector<vector<int>> &edges)
  {
    // Create adjacency list and calculate in-degree for each vertex
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    // Start with vertices having in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    int visitedCount = 0;

    // Process vertices in BFS order
    while (!q.empty())
    {
      int current = q.front();
      q.pop();
      visitedCount++;

      // Reduce in-degree of all adjacent vertices
      for (int neighbor : adj[current])
      {
        indegree[neighbor]--;
        // If in-degree becomes 0, add to queue
        if (indegree[neighbor] == 0)
        {
          q.push(neighbor);
        }
      }
    }

    // If all vertices are processed, no cycle exists
    // Otherwise, there must be a cycle preventing complete topological ordering
    return visitedCount != V;
  }
};

/**
 * Function to visualize a directed graph as an adjacency list
 */
void printGraph(int V, vector<vector<int>> &edges)
{
  vector<vector<int>> adj(V);

  for (auto &edge : edges)
  {
    adj[edge[0]].push_back(edge[1]);
  }

  cout << "Graph Adjacency List:" << endl;
  for (int i = 0; i < V; i++)
  {
    cout << i << " -> ";
    for (int neighbor : adj[i])
    {
      cout << neighbor << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  Solution sol;

  // Test case 1: Graph with a self-loop (cycle)
  cout << "Test Case 1: Graph with a self-loop" << endl;
  int V1 = 4;
  vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}, {3, 3}}; // 3->3 is a self-loop

  printGraph(V1, edges1);
  bool hasCycle1 = sol.isCyclic(V1, edges1);
  cout << "Has cycle: " << (hasCycle1 ? "Yes" : "No") << endl;
  cout << endl;

  // Test case 2: DAG (Directed Acyclic Graph)
  cout << "Test Case 2: Directed Acyclic Graph (DAG)" << endl;
  int V2 = 3;
  vector<vector<int>> edges2 = {{0, 1}, {1, 2}};

  printGraph(V2, edges2);
  bool hasCycle2 = sol.isCyclic(V2, edges2);
  cout << "Has cycle: " << (hasCycle2 ? "Yes" : "No") << endl;
  cout << endl;

  // Test case 3: Graph with a cycle but not a self-loop
  cout << "Test Case 3: Graph with a cycle (not self-loop)" << endl;
  int V3 = 3;
  vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 0}}; // 0->1->2->0 forms a cycle

  printGraph(V3, edges3);
  bool hasCycle3 = sol.isCyclic(V3, edges3);
  cout << "Has cycle: " << (hasCycle3 ? "Yes" : "No") << endl;
  cout << endl;

  // Test case 4: Larger graph with multiple paths but no cycles
  cout << "Test Case 4: Larger DAG with multiple paths" << endl;
  int V4 = 6;
  vector<vector<int>> edges4 = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {3, 5}};

  printGraph(V4, edges4);
  bool hasCycle4 = sol.isCyclic(V4, edges4);
  cout << "Has cycle: " << (hasCycle4 ? "Yes" : "No") << endl;
  cout << endl;

  // Test case 5: Disconnected graph with a cycle
  cout << "Test Case 5: Disconnected graph with a cycle" << endl;
  int V5 = 7;
  vector<vector<int>> edges5 = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}};

  printGraph(V5, edges5);
  bool hasCycle5 = sol.isCyclic(V5, edges5);
  cout << "Has cycle: " << (hasCycle5 ? "Yes" : "No") << endl;

  return 0;
}