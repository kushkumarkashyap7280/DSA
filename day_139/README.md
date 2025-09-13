# Day 139: Dijkstra's Algorithm for Shortest Path in Weighted Graphs

## Overview

Day 139 focuses on Dijkstra's algorithm, a fundamental algorithm for finding the shortest path in a weighted graph with non-negative edge weights. This algorithm is essential for network routing, GPS navigation, transportation optimization, and many other applications where finding the shortest path is critical.

## Problems Covered

### 1. Network Delay Time

**File:** [Leetcode_743.cpp](./Leetcode_743.cpp)

**Problem Link:** [LeetCode 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/description/)

**Problem:** You are given a network of n nodes (labeled from 1 to n) and a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target. We send a signal from a given node k. Return the minimum time it takes for all n nodes to receive the signal, or -1 if it's impossible for all nodes to receive the signal.

**Example:**

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Explanation: 
- Node 2 is the starting node
- It takes 1 time unit for the signal to reach node 1 directly from node 2
- It takes 1 time unit for the signal to reach node 3 directly from node 2
- It takes 2 time units for the signal to reach node 4 (1 unit from node 2 to node 3, and then 1 unit from node 3 to node 4)
- The maximum time is 2, which is the time it takes for all nodes to receive the signal
```

**Approach Implemented:**

The solution uses Dijkstra's algorithm to find the shortest path from the source node to all other nodes in the graph:

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto &i : times) {
            adj[i[0]-1].push_back({ i[2], i[1]-1 });  // {weight, target}
        }

        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;

        set<pair<int,int>> st;
        st.insert({0, k-1});

        while (!st.empty()) {
            auto top = *(st.begin());
            st.erase(st.begin());

            int topNodeDist = top.first;
            int topNode = top.second;

            for (auto &neighbour : adj[topNode]) {
                int edgeWeight = neighbour.first;
                int neighNode = neighbour.second;

                if (topNodeDist + edgeWeight < dist[neighNode]) {
                    dist[neighNode] = topNodeDist + edgeWeight;
                    st.insert({dist[neighNode], neighNode});
                }
            }
        }

        int maxDist = *max_element(dist.begin(), dist.end());
        return (maxDist == INT_MAX) ? -1 : maxDist;
    }
};
```

**Key Insight:** Using a set in the implementation of Dijkstra's algorithm ensures that we always process the node with the minimum distance next, similar to a priority queue but with the added benefit of being able to update existing elements more efficiently.

**Time Complexity:** O(E log V) - where E is the number of edges and V is the number of vertices
**Space Complexity:** O(V + E) - for the adjacency list, distance array, and set

## Detailed Algorithm Explanation

### Dijkstra's Algorithm

Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights. The algorithm maintains a set of nodes whose shortest distance from the source is already known and repeatedly selects the node with the minimum distance from the set of unvisited nodes.

### Step-by-Step Algorithm

1. **Initialize data structures**:
   - Create an adjacency list representation of the graph
   - Initialize a distance array with infinity for all nodes except the source node (which is set to 0)
   - Create a set or priority queue to keep track of nodes to visit, ordered by their current distance

2. **Process nodes in order of distance**:
   - While the set is not empty:
     - Extract the node with the minimum distance from the set
     - For each neighbor of the extracted node:
       - Calculate the potential new distance to the neighbor through the current node
       - If this distance is smaller than the previously known distance:
         - Update the distance
         - Add the neighbor to the set (or update its position in the priority queue)

3. **Extract the result**:
   - After processing all reachable nodes, the distance array contains the shortest path from the source to each node
   - For this problem, we return the maximum value in the distance array (if any node is unreachable, return -1)

### Implementation Details

In our solution:
- We use a set of pairs `<distance, node>` to efficiently extract the node with the minimum distance
- The adjacency list stores pairs of `<weight, target_node>` for each edge
- We handle 0-indexing vs. 1-indexing conversion since the problem uses 1-indexed nodes

## Advantages of Set-based Implementation

1. **Automatic ordering**: The set keeps elements sorted, allowing us to easily extract the minimum element
2. **Efficient updates**: Unlike a simple priority queue, a set allows us to remove and reinsert elements when distances are updated
3. **Simplicity**: The implementation is clean and straightforward

## Applications of Dijkstra's Algorithm

1. **Network Routing**: Finding the shortest path for data packets in computer networks
2. **GPS Navigation**: Determining the fastest route between locations
3. **Transportation Planning**: Optimizing delivery routes or public transit systems
4. **Social Networks**: Finding the shortest connection between individuals
5. **Robotics**: Path planning for autonomous robots

## Comparison with Other Shortest Path Algorithms

| Algorithm         | Time Complexity  | Works with Negative Weights | Best Used For                                |
|-------------------|------------------|-----------------------------|--------------------------------------------|
| Dijkstra's        | O(E log V)       | No                          | Single source, non-negative weights        |
| Bellman-Ford      | O(V*E)           | Yes                         | Single source, can detect negative cycles  |
| Floyd-Warshall    | O(V³)            | Yes                         | All pairs shortest paths                   |
| A*                | O(E)             | No                          | Single source-target with heuristic        |
| DAG Shortest Path | O(V+E)           | Yes                         | Directed Acyclic Graphs                    |

## Notes

- **Optimization**: Using a set instead of a traditional min-heap provides efficiency when updating distances
- **Edge Cases**: The problem requires checking if all nodes are reachable (returning -1 if not)
- **1-Indexing**: The problem uses 1-indexed nodes, but our implementation converts to 0-indexed for simplicity
- **Maximum Time**: The answer is the maximum of all shortest paths, representing the time when the last node receives the signal

## Practice Problems

- [LeetCode 787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)
- [LeetCode 1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)
- [LeetCode 1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)
- [GeeksforGeeks - Implementing Dijkstra's Algorithm](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)
- [GeeksforGeeks - Minimum Cost Path](https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1)

## Further Reading

- [Dijkstra's Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- [Shortest Path Problem](https://en.wikipedia.org/wiki/Shortest_path_problem)
- [Priority Queue Implementations](https://en.wikipedia.org/wiki/Priority_queue)
- [Graph Algorithms](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)