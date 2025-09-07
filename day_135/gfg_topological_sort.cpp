// Topological Sort

// link  : https://www.geeksforgeeks.org/problems/topological-sort/1

/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
  /**
   * DFS approach for Topological Sort
   * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
   * Space Complexity: O(V) for visited array and recursion stack
   */
  void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &s)
  {
    visited[node] = 1;

    for (int neighbor : adj[node])
    {
      if (!visited[neighbor])
      {
        dfs(neighbor, adj, visited, s);
      }
    }

    // Push current node to stack after all its adjacent vertices are processed
    s.push(node);
  }

  vector<int> topoSortDFS(int V, vector<vector<int>> &edges)
  {
    // Create adjacency list
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
    }

    stack<int> s;
    vector<int> visited(V, 0);

    // Call DFS for each unvisited vertex
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs(i, adj, visited, s);
      }
    }

    // Pop elements from stack to get topological order
    vector<int> result;
    while (!s.empty())
    {
      result.push_back(s.top());
      s.pop();
    }

    return result;
  }

  /**
   * BFS approach (Kahn's Algorithm) for Topological Sort
   * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
   * Space Complexity: O(V) for queue and indegree array
   */
  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    // Create adjacency list and calculate indegree for each vertex
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    // Add all vertices with 0 indegree to queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> topo;

    // Process vertices in BFS order
    while (!q.empty())
    {
      int current = q.front();
      q.pop();
      topo.push_back(current);

      // Reduce indegree of all adjacent vertices
      for (int neighbor : adj[current])
      {
        indegree[neighbor]--;
        // If indegree becomes 0, add to queue
        if (indegree[neighbor] == 0)
          q.push(neighbor);
      }
    }

    // If topological sort doesn't include all vertices, there's a cycle
    if (topo.size() != V)
      return {};

    return topo;
  }
};

/**
 * Function to check if a topological sort is valid
 * Returns true if the order satisfies all edge constraints
 */
bool isValidTopoSort(int V, vector<vector<int>> &edges, vector<int> &order)
{
  // Create a position map for each vertex in the order
  vector<int> pos(V);
  for (int i = 0; i < V; i++)
  {
    pos[order[i]] = i;
  }

  // Check if for each edge (u,v), u comes before v in the order
  for (auto &edge : edges)
  {
    int u = edge[0];
    int v = edge[1];
    if (pos[u] > pos[v])
    {
      return false; // Invalid ordering
    }
  }

  return true;
}

/**
 * Function to print a vector
 */
void printVector(const vector<int> &vec)
{
  for (int val : vec)
  {
    cout << val << " ";
  }
  cout << endl;
}

int main()
{
  // Test case 1: Simple DAG with 4 vertices
  cout << "Test Case 1:" << endl;
  int V1 = 4;
  vector<vector<int>> edges1 = {{3, 0}, {1, 0}, {2, 0}};

  Solution sol;
  vector<int> result1 = sol.topoSort(V1, edges1);

  cout << "Topological Sort (BFS/Kahn's): ";
  printVector(result1);

  vector<int> dfsResult1 = sol.topoSortDFS(V1, edges1);
  cout << "Topological Sort (DFS): ";
  printVector(dfsResult1);

  cout << "Is BFS result valid? " << (isValidTopoSort(V1, edges1, result1) ? "Yes" : "No") << endl;
  cout << "Is DFS result valid? " << (isValidTopoSort(V1, edges1, dfsResult1) ? "Yes" : "No") << endl;

  // Test case 2: More complex DAG with 6 vertices
  cout << "\nTest Case 2:" << endl;
  int V2 = 6;
  vector<vector<int>> edges2 = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};

  vector<int> result2 = sol.topoSort(V2, edges2);
  cout << "Topological Sort (BFS/Kahn's): ";
  printVector(result2);

  vector<int> dfsResult2 = sol.topoSortDFS(V2, edges2);
  cout << "Topological Sort (DFS): ";
  printVector(dfsResult2);

  cout << "Is BFS result valid? " << (isValidTopoSort(V2, edges2, result2) ? "Yes" : "No") << endl;
  cout << "Is DFS result valid? " << (isValidTopoSort(V2, edges2, dfsResult2) ? "Yes" : "No") << endl;

  // Test case 3: DAG with a cycle (should return empty for Kahn's algorithm)
  cout << "\nTest Case 3 (Graph with cycle):" << endl;
  int V3 = 3;
  vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {2, 0}}; // Cycle: 0->1->2->0

  vector<int> result3 = sol.topoSort(V3, edges3);
  cout << "Topological Sort (BFS/Kahn's): ";
  if (result3.empty())
  {
    cout << "Empty (cycle detected)" << endl;
  }
  else
  {
    printVector(result3);
  }

  return 0;
}