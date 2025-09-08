# Day 136: Shortest Path in Unweighted Undirected Graphs

## Overview

Day 136 focuses on solving the shortest path problem in unweighted undirected graphs using Breadth-First Search (BFS). The implementation demonstrates how to find the shortest path between two nodes in an unweighted graph, which is a fundamental algorithm in graph theory with applications in social networks, routing, and network analysis.

## Problems Covered

### 1. Shortest Path in an Unweighted Undirected Graph

**File:** [cn_shortest_path_unweighted_undirected_graph.cpp](./cn_shortest_path_unweighted_undirected_graph.cpp)

**Problem Link:** [Code360 - Shortest Path in an Unweighted Graph](https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297)

**Problem:** Given an undirected unweighted graph with n vertices and m edges, and two nodes s and t, find the shortest path from node s to node t.

**Example:**

```
Input:
n = 5, m = 6
edges = [(0,1), (0,2), (1,2), (1,3), (2,4), (3,4)]
s = 0, t = 4

Output: [0, 2, 4]
```

**Approach Implemented:**

**BFS-based Solution (O(V+E)):**

```cpp
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
   vector<vector<int>> adj(n+1);

   // Build adjacency list
   for(auto &p :  edges){
       adj[p.first].push_back(p.second);
       adj[p.second].push_back(p.first);
   }

   vector<int> isVisted(n+1, 0), parent(n+1, -1);
   queue<int> q;

   // Start BFS from source node
   q.push(s);
   isVisted[s] = 1;
   parent[s] = -1;

   // BFS traversal
   while(!q.empty()){
       int curr = q.front();
       q.pop();
       if(curr == t) break; // Found destination

       // Explore all neighbors
       for(int neighbour : adj[curr]){
           if(!isVisted[neighbour]){
               q.push(neighbour);
               isVisted[neighbour] = 1;
               parent[neighbour] = curr;
           }
       }
   }

   // Reconstruct path
   vector<int> sp;
   int curr = t;
   while(curr != -1){
       sp.push_back(curr);
       curr = parent[curr];
   }

   reverse(sp.begin(), sp.end());

   // Return path if it exists
   if(sp.front() == s){
       return sp;
   }

   return {}; // No path exists
}
```

**Key Insight:** In an unweighted graph, BFS naturally finds the shortest path because it explores nodes level by level, reaching nodes with minimum number of edges first.

**Time Complexity:** O(V+E) - where V is the number of vertices and E is the number of edges
**Space Complexity:** O(V) - for the queue, visited array, and parent array

## Key Concepts Covered

### 1. **Shortest Path in Unweighted Graphs**

- **BFS Approach:** Using BFS to find shortest path
- **Path Reconstruction:** Using parent array to reconstruct the path
- **Edge Case Handling:** Checking if a path exists

### 2. **Graph Representation**

- **Adjacency List:** Efficient representation for sparse graphs
- **Bidirectional Edges:** Handling undirected graph edges

### 3. **Data Structure Usage**

- **Queue:** For BFS traversal
- **Vector of Vectors:** For adjacency list representation
- **Parent Array:** For path reconstruction
- **Visited Array:** For marking visited nodes

### 4. **Algorithm Flow**

- **BFS Initialization:** Starting from source node
- **Traversal:** Exploring neighbors level by level
- **Path Tracking:** Recording parent of each node
- **Path Reconstruction:** Working backwards from destination to source

## Common Patterns

1. **Graph Traversal Patterns:**

   - BFS for shortest path in unweighted graphs
   - Parent array for path reconstruction
   - Early termination when destination is found

2. **Optimization Patterns:**

   - Efficient adjacency list for sparse graphs
   - Breaking loop when destination is found
   - Only visiting each node once

3. **Problem-Specific Techniques:**
   - Path reconstruction from destination to source
   - Reversing the path to get correct order
   - Returning empty array when no path exists

## Time and Space Complexity Summary

| Problem                           | Time Complexity | Space Complexity | Approach              |
| --------------------------------- | --------------- | ---------------- | --------------------- |
| Shortest Path in Unweighted Graph | O(V+E)          | O(V)             | BFS with parent array |

## Why BFS for Shortest Path in Unweighted Graphs?

In unweighted graphs, where all edges have the same weight (or unit weight), BFS is the optimal algorithm for finding the shortest path because:

1. **Level-by-level exploration:** BFS explores nodes in order of their distance from the source.
2. **First visit guarantee:** When BFS first discovers a node, it has found the shortest path to that node.
3. **Optimality:** BFS guarantees the shortest path in terms of the number of edges.
4. **Efficiency:** BFS runs in O(V+E) time, which is optimal for this problem.

In contrast, for weighted graphs, algorithms like Dijkstra's or Bellman-Ford would be necessary.

## Applications of Shortest Path Algorithms

1. **Social Networks:** Finding shortest connection between two people
2. **Routing Protocols:** Determining the shortest path for data packets
3. **GPS and Navigation:** Finding shortest routes in road networks
4. **Network Analysis:** Analyzing connectivity in various networks
5. **Game AI:** Pathfinding for game characters
6. **Robot Motion Planning:** Finding efficient paths for robots

## Practice Problems

- [Leetcode 743 - Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [Leetcode 787 - Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- [Leetcode 1091 - Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
- [Leetcode 1631 - Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- [Leetcode 2359 - Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/)

## Notes

- **BFS vs DFS:** For shortest paths in unweighted graphs, always use BFS
- **Visited Array:** Critical to avoid cycles and redundant exploration
- **Parent Array:** Essential for path reconstruction
- **Bidirectional Search:** Can be used to speed up the search in some cases
- **Early Termination:** Stop BFS once destination is found
- **Edge Cases:** Handle disconnected graphs by checking if a path exists

## Sample Usage

### Running Shortest Path:

```bash
g++ -o shortest_path cn_shortest_path_unweighted_undirected_graph.cpp
./shortest_path
```

## Next Steps

- Implement shortest path algorithms for weighted graphs (Dijkstra, Bellman-Ford)
- Explore multi-source shortest path algorithms (Floyd-Warshall)
- Study algorithms for negative weight cycles detection
- Implement bidirectional BFS for faster shortest path finding
- Explore A\* algorithm for heuristic-based pathfinding
- Study applications in real-world network problems
- Implement shortest path in directed graphs
