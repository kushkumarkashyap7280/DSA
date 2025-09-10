// Shortest path in Directed Acyclic Graph (DAG)

// Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples:

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1. Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

Constraint:
1 <= V <= 100
1 <= E <= min((N*(N-1))/2,4000)
0 <= edgesi,0, edgesi,1 < n
0 <= edgei,2 <=105
*/

#include <bits/stdc++.h>
using namespace std;

/*
Algorithm:
1. Perform topological sort of the DAG to determine the processing order of vertices
2. Initialize distances to all vertices as infinity except the source vertex (distance = 0)
3. Process vertices in topological order:
   - For each outgoing edge, relax the distance if a shorter path is found
4. Return the array of shortest distances

Why this works:
- In a DAG, once we process a vertex in topological order, we've processed all its predecessors
- This means we have the final shortest distance to this vertex before we use it to update others
- Unlike Dijkstra's algorithm, we don't need a priority queue because the topological order ensures
  we process vertices in the correct dependency order
*/

class Solution
{
private:
  // Perform DFS to generate topological sort
  void dfs(int node,
           vector<int> &isVisited,
           vector<vector<pair<int, int>>> &adj,
           stack<int> &s)
  {
    // Mark current node as visited
    isVisited[node] = 1;

    // Recursively visit all unvisited neighbors
    for (auto &neighbor : adj[node])
    {
      int nextNode = neighbor.first;
      if (!isVisited[nextNode])
      {
        dfs(nextNode, isVisited, adj, s);
      }
    }

    // Push node to stack after all its neighbors are processed
    // (this ensures topological ordering)
    s.push(node);
  }

public:
  vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
  {
    // Step 1: Build adjacency list with weighted edges
    vector<vector<pair<int, int>>> adj(V);
    for (auto &e : edges)
    {
      adj[e[0]].push_back({e[1], e[2]}); // {neighbor, weight}
    }

    // Step 2: Perform topological sort using DFS
    vector<int> isVisited(V, 0);
    stack<int> topoOrder;

    // Start DFS from each unvisited node
    for (int i = 0; i < V; i++)
    {
      if (!isVisited[i])
      {
        dfs(i, isVisited, adj, topoOrder);
      }
    }

    // Step 3: Initialize distances
    vector<int> distance(V, 1e9); // Initialize with infinity
    distance[0] = 0;              // Distance from source to itself is 0

    // Step 4: Process vertices in topological order
    while (!topoOrder.empty())
    {
      int node = topoOrder.top();
      topoOrder.pop();

      // Only process if the current node is reachable
      if (distance[node] != 1e9)
      {
        // Relax all outgoing edges
        for (auto &edge : adj[node])
        {
          int neighbor = edge.first;
          int weight = edge.second;

          // If we can find a shorter path, update the distance
          if (distance[node] + weight < distance[neighbor])
          {
            distance[neighbor] = distance[node] + weight;
          }
        }
      }
    }

    // Step 5: Replace unreachable nodes with -1
    for (int i = 0; i < V; i++)
    {
      if (distance[i] == 1e9)
      {
        distance[i] = -1;
      }
    }

    return distance;
  }
};

// Test function to run the solution
void testShortestPath()
{
  Solution solution;

  cout << "--------- Testing Shortest Path in DAG ---------" << endl;

  // Test case 1: Basic example
  int V1 = 4, E1 = 2;
  vector<vector<int>> edges1 = {{0, 1, 2}, {0, 2, 1}};
  vector<int> result1 = solution.shortestPath(V1, E1, edges1);

  cout << "Test Case 1 (Basic Example):" << endl;
  cout << "Input: V=" << V1 << ", E=" << E1 << ", edges=[[0,1,2], [0,2,1]]" << endl;
  cout << "Expected: [0, 2, 1, -1]" << endl;
  cout << "Result:   [";
  for (int i = 0; i < result1.size(); i++)
  {
    cout << result1[i];
    if (i < result1.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test case 2: More complex example
  int V2 = 6, E2 = 7;
  vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
  vector<int> result2 = solution.shortestPath(V2, E2, edges2);

  cout << "Test Case 2 (Complex Example):" << endl;
  cout << "Input: V=" << V2 << ", E=" << E2 << ", edges=[[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]" << endl;
  cout << "Expected: [0, 2, 3, 6, 1, 5]" << endl;
  cout << "Result:   [";
  for (int i = 0; i < result2.size(); i++)
  {
    cout << result2[i];
    if (i < result2.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test case 3: Disconnected graph
  int V3 = 5, E3 = 3;
  vector<vector<int>> edges3 = {{0, 1, 2}, {0, 2, 1}, {3, 4, 5}};
  vector<int> result3 = solution.shortestPath(V3, E3, edges3);

  cout << "Test Case 3 (Disconnected Graph):" << endl;
  cout << "Input: V=" << V3 << ", E=" << E3 << ", edges=[[0,1,2], [0,2,1], [3,4,5]]" << endl;
  cout << "Expected: [0, 2, 1, -1, -1]" << endl;
  cout << "Result:   [";
  for (int i = 0; i < result3.size(); i++)
  {
    cout << result3[i];
    if (i < result3.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test case 4: Multiple paths to the same destination
  int V4 = 6, E4 = 8;
  vector<vector<int>> edges4 = {
      {0, 1, 2}, {0, 2, 4}, {1, 3, 7}, {2, 3, 2}, {2, 4, 3}, {3, 5, 1}, {4, 5, 5}, {1, 2, 1}};
  vector<int> result4 = solution.shortestPath(V4, E4, edges4);

  cout << "Test Case 4 (Multiple Paths):" << endl;
  cout << "Input: Multiple paths to same destination, testing if algorithm finds shortest" << endl;
  cout << "Result:   [";
  for (int i = 0; i < result4.size(); i++)
  {
    cout << result4[i];
    if (i < result4.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Explanation: The shortest path from 0 to 5 should be 0->1->2->3->5 with total weight of 2+1+2+1=6" << endl;

  cout << "------------------------------------------------" << endl;
}

// Main function to run tests
int main()
{
  testShortestPath();
  return 0;
}

/*
Time Complexity: O(V + E)
- Topological sort takes O(V + E) time
- Processing vertices in topological order takes O(E) time
- Overall time complexity is O(V + E)

Space Complexity: O(V + E)
- Adjacency list takes O(E) space
- Visited array and distance array take O(V) space
- Stack for topological sort takes O(V) space
- Overall space complexity is O(V + E)

Advantages over Dijkstra's Algorithm for DAGs:
1. Linear time complexity O(V+E) vs O((V+E)logV) for Dijkstra's
2. Can handle negative edge weights (Dijkstra's cannot)
3. Simpler implementation (no priority queue needed)
*/
