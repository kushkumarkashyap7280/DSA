# Day 138: Shortest Path in Directed Acyclic Graph (DAG)

## Overview

Day 138 focuses on finding the shortest path in a Directed Acyclic Graph (DAG) using a combination of topological sorting and dynamic programming. This algorithm is more efficient than Dijkstra's algorithm for DAGs and has applications in scheduling, dependency resolution, and network routing.

## Problems Covered

### 1. Shortest Path in Directed Acyclic Graph

**File:** [gfg_short_path_in_acylic_weighted_undireted_graph.cpp](./gfg_short_path_in_acylic_weighted_undireted_graph.cpp)

**Problem Link:** [GeeksforGeeks - Shortest Path in Directed Acyclic Graph](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1)

**Problem:** Given a Directed Acyclic Graph of V vertices and E edges with weights, find the shortest path from source vertex (0) to all other vertices. If a vertex is unreachable, return -1 for that vertex.

**Example:**

```
Input: V = 6, E = 7
edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]

Output: [0, 2, 3, 6, 1, 5]

Explanation:
- Shortest path from 0 to 1 is 0->1 with weight 2
- Shortest path from 0 to 2 is 0->4->2 with weight 1+2=3
- Shortest path from 0 to 3 is 0->4->5->3 with weight 1+4+1=6
- Shortest path from 0 to 4 is 0->4 with weight 1
- Shortest path from 0 to 5 is 0->4->5 with weight 1+4=5
```

**Approach Implemented:**

The solution uses a two-step approach combining topological sorting and dynamic programming:

```cpp
class Solution {
private:
    // DFS for topological sort
    void dfs(int node, vector<int> &isVisited, vector<vector<pair<int,int>>> &adj, stack<int> &s) {
        isVisited[node] = 1;
        for(auto &neighbor : adj[node]) {
            if(!isVisited[neighbor.first]) {
                dfs(neighbor.first, isVisited, adj, s);
            }
        }
        s.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]}); // {neighbor, weight}
        }

        // Step 1: Topological Sort
        vector<int> isVisited(V, 0);
        stack<int> topoOrder;
        for(int i = 0; i < V; i++) {
            if(!isVisited[i]) {
                dfs(i, isVisited, adj, topoOrder);
            }
        }

        // Step 2: Initialize distances
        vector<int> distance(V, 1e9);
        distance[0] = 0;

        // Step 3: Process vertices in topological order
        while(!topoOrder.empty()) {
            int node = topoOrder.top();
            topoOrder.pop();

            if(distance[node] != 1e9) {
                for(auto &edge : adj[node]) {
                    int neighbor = edge.first;
                    int weight = edge.second;

                    if(distance[node] + weight < distance[neighbor]) {
                        distance[neighbor] = distance[node] + weight;
                    }
                }
            }
        }

        // Replace unreachable nodes with -1
        for(int i = 0; i < V; i++) {
            if(distance[i] == 1e9) distance[i] = -1;
        }

        return distance;
    }
};
```

**Key Insight:** Using topological sorting ensures that we process vertices in the correct order (from dependencies to dependents), allowing us to compute shortest paths in a single pass without the need for a priority queue as in Dijkstra's algorithm.

**Time Complexity:** O(V+E) - where V is the number of vertices and E is the number of edges
**Space Complexity:** O(V+E) - for the adjacency list, visited array, and topological ordering stack

## Detailed Algorithm Explanation

### Why Topological Sort + DP works for DAGs

The shortest path algorithm for DAGs exploits two key properties:

1. **Acyclicity**: DAGs don't have cycles, so once we process a vertex, we don't need to revisit it
2. **Topological ordering**: If we process vertices in topological order, we're guaranteed that all incoming edges to a vertex have been processed before we process the vertex itself

### Step-by-Step Algorithm

1. **Build the graph representation**:

   - Create an adjacency list where for each vertex, we store its neighbors and the edge weights

2. **Perform topological sorting**:

   - Use DFS to create a topological ordering of vertices
   - This ensures we process vertices in the correct dependency order

3. **Initialize distances**:

   - Set distance from source to source as 0
   - Set all other distances to infinity (or a very large value)

4. **Process vertices in topological order**:

   - For each vertex in the topological order:
     - If the vertex is reachable (distance < infinity):
       - For each of its neighbors:
         - Try to relax the edge: if we can reach the neighbor through the current vertex with a shorter distance, update the neighbor's distance

5. **Handle unreachable vertices**:
   - Mark vertices that couldn't be reached with -1 (or as specified by the problem)

## Advantages Over Dijkstra's Algorithm

For DAGs, this algorithm has several advantages over Dijkstra's:

1. **Better time complexity**: O(V+E) vs O((V+E)logV) for Dijkstra's with binary heap
2. **Simpler implementation**: No need for a priority queue
3. **Works with negative weights**: Unlike Dijkstra's, this algorithm handles negative edge weights correctly (as long as there are no negative cycles, which DAGs can't have by definition)

## Applications

1. **Task Scheduling**: Finding the earliest time to complete dependent tasks
2. **Critical Path Analysis**: Identifying the longest path in project management
3. **Network Routing**: Computing optimal routes in directed networks
4. **Compilation Dependencies**: Resolving dependencies in build systems
5. **Pipeline Optimization**: Minimizing delays in data processing pipelines

## Practice Problems

- [LeetCode 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [LeetCode 787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- [LeetCode 1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- [GeeksforGeeks - Minimum time taken by each job to be completed given by a DAG](https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/)
- [GeeksforGeeks - Longest Path in a Directed Acyclic Graph](https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/)

## Key Concepts Covered

### 1. **Directed Acyclic Graphs (DAGs)**

- **Acyclicity**: No cycles means we can establish a clear ordering of vertices
- **Directed Edges**: Allow modeling one-way relationships
- **Topological Sorting**: A linear ordering of vertices such that for every directed edge (u,v), u comes before v

### 2. **Topological Sorting**

- **Definition**: An ordering of vertices such that for every directed edge (u,v), u comes before v
- **DFS-based approach**: Explore all descendants before adding the current vertex to the result
- **Applications**: Dependency resolution, task scheduling

### 3. **Shortest Path Algorithms**

- **Single-source shortest path**: Finding shortest paths from one vertex to all others
- **Dynamic programming approach**: Building solutions incrementally from simpler subproblems
- **Edge relaxation**: The core operation of updating distance if a shorter path is found

## Comparison with Other Shortest Path Algorithms

| Algorithm         | Time Complexity | Space Complexity | Works with Negative Weights | Works with Cycles             | Notes                     |
| ----------------- | --------------- | ---------------- | --------------------------- | ----------------------------- | ------------------------- |
| DAG Shortest Path | O(V+E)          | O(V+E)           | Yes                         | No (DAGs only)                | Fastest for DAGs          |
| Dijkstra's        | O((V+E)logV)    | O(V+E)           | No                          | Yes                           | Good for sparse graphs    |
| Bellman-Ford      | O(V\*E)         | O(V)             | Yes                         | Yes (detects negative cycles) | More versatile but slower |
| Floyd-Warshall    | O(V³)           | O(V²)            | Yes                         | Yes (detects negative cycles) | All-pairs shortest paths  |

## Notes

- **Negative Weight Handling**: While this algorithm can handle negative weights, the graph must remain a DAG (which inherently cannot have negative cycles)
- **Source Vertex**: The problem specifies vertex 0 as the source; the algorithm can be adapted for any source
- **Unreachable Vertices**: We mark vertices that cannot be reached as -1 in the final result
- **Implementation Optimization**: We only process a vertex if it's reachable (distance != infinity) to avoid unnecessary computations

## Further Reading

- [Shortest Path in Directed Acyclic Graph](https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/)
- [Topological Sorting](https://www.geeksforgeeks.org/topological-sorting/)
- [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)
- [Comparison of Shortest Path Algorithms](https://www.geeksforgeeks.org/comparison-dijkstra-floyd-warshall-bellman-ford-algorithms/)
