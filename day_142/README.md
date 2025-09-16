# Day 142: Advanced Graph Algorithms - MST Applications and Critical Connections

## Overview

Day 142 focuses on two important graph algorithm applications: Minimum Spanning Tree (MST) for connecting points in a 2D plane, and finding critical connections (bridges) in a network. We implement Prim's algorithm with a priority queue to solve the MST problem and Tarjan's algorithm for identifying critical connections. Both problems demonstrate the practical applications of graph theory in networking, infrastructure design, and system reliability analysis.

## Problems Covered

### 1. Min Cost to Connect All Points (LeetCode 1584)

**File:** [Leetcode_1584.cpp](./Leetcode_1584.cpp)

**Problem Link:** [LeetCode 1584 - Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

**Problem:** Given an array of points on a 2D plane, connect all points such that there is exactly one simple path between any two points. The cost of connecting two points is the Manhattan distance between them. Return the minimum total cost to connect all points.

**Example:**

```
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
```

**Approaches Implemented:**

1. **Prim's Algorithm with Priority Queue (O(n² log n)):**

   ```cpp
   class Solution {
   public:
       int minCostConnectPoints(vector<vector<int>>& points) {
           int n = points.size();

           vector<int> dist(n, INT_MAX);
           vector<int> isVisited(n, 0);

           // Min-heap priority queue {cost, point index}
           priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
           pq.push({0, 0});  // Start from point 0 with cost 0

           int totalCost = 0;

           while (!pq.empty()) {
               auto [currCost, index] = pq.top();
               pq.pop();

               if (isVisited[index]) continue;

               isVisited[index] = true;
               totalCost += currCost;

               for (int i = 0; i < n; i++) {
                   if (!isVisited[i]) {
                       int md = abs(points[index][0] - points[i][0]) + 
                               abs(points[index][1] - points[i][1]);

                       if (md < dist[i]) {
                           dist[i] = md;
                           pq.push({md, i});
                       }
                   }
               }
           }

           return totalCost;
       }
   };
   ```

**Key Insight:** This problem is essentially asking for a minimum spanning tree where vertices are points in a 2D plane and edge weights are Manhattan distances.

**Time Complexity:** O(n² log n)
- For each of the n vertices, we may add O(n) edges to the priority queue
- Each priority queue operation takes O(log n) time

**Space Complexity:** O(n)
- Priority queue: O(n) in worst case
- Distance array: O(n)
- Visited array: O(n)

---

### 2. Critical Connections in a Network (LeetCode 1192)

**File:** [Leetcode_1192.cpp](./Leetcode_1192.cpp)

**Problem Link:** [LeetCode 1192 - Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)

**Problem:** There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network. Any server can reach any other server directly or indirectly through the network. A critical connection is a connection that, if removed, will make some server unable to reach some other server. Return all critical connections in the network in any order.

**Example:**

```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
```

**Approaches Implemented:**

1. **Tarjan's Algorithm for Bridge Finding (O(V+E)):**

   ```cpp
   class Solution {
   public:
       void dfs(int node, int parent, 
               int &timer, vector<int> &isVisited, 
               vector<int> &low, vector<int> &disTime,
               vector<vector<int>> &ans,
               vector<vector<int>> &adj) {
           
           isVisited[node] = 1;
           disTime[node] = low[node] = timer++;

           for(auto nbr : adj[node]) {
               if(nbr == parent) continue;

               if(!isVisited[nbr]) {
                   dfs(nbr, node, timer, isVisited, low, disTime, ans, adj);
                   low[node] = min(low[node], low[nbr]);

                   // If this edge is a bridge
                   if(low[nbr] > disTime[node]) {
                       ans.push_back({node, nbr});
                   }
               } else {
                   // Back edge
                   low[node] = min(low[node], disTime[nbr]);
               }
           }
       }
       
       vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
           // Create adjacency list
           vector<vector<int>> adj(n);
           for(auto &connection : connections) {
               adj[connection[0]].push_back(connection[1]);
               adj[connection[1]].push_back(connection[0]);
           }

           vector<int> isVisited(n, 0);
           vector<int> low(n, -1);
           vector<int> disTime(n, -1);
           int timer = 0;
           
           vector<vector<int>> ans;

           for(int i = 0; i < n; i++) {
               if(!isVisited[i]) {
                   dfs(i, -1, timer, isVisited, low, disTime, ans, adj);
               }
           }
       
           return ans;
       }
   };
   ```

**Key Insight:** Critical connections are bridges in the graph. Tarjan's algorithm efficiently identifies these bridges in a single DFS traversal.

**Time Complexity:** O(V + E)
- Building adjacency list: O(E)
- DFS traversal: O(V + E)

**Space Complexity:** O(V + E)
- Adjacency list: O(E)
- Visited, discovery time, and low arrays: O(V) each

## Key Concepts Covered

### 1. **Minimum Spanning Tree (MST)**
- Using Prim's algorithm to find MST in a complete graph
- Priority queue implementation for efficient vertex selection
- Manhattan distance as edge weight in geometric applications
- Handling visited vertices and maintaining distance arrays

### 2. **Tarjan's Algorithm for Bridge Finding**
- Identifying critical connections (bridges) in a graph
- Using discovery time and low values to detect bridges
- DFS traversal with parent tracking
- Handling back edges in the graph

### 3. **Graph Representation Techniques**
- Adjacency list for efficient graph representation
- Implicit edge weights (calculated on-the-fly for geometric problems)
- Converting edge list to adjacency list

### 4. **Application-Specific Graph Algorithms**
- Geometric applications of MST (connecting points)
- Network reliability analysis (finding critical connections)
- Infrastructure design optimization

## Common Patterns

1. **MST Algorithm Patterns:**
   - Greedy selection of minimum weight edges
   - Tracking visited vertices
   - Using priority data structures for efficiency
   - Avoiding cycles in the spanning tree

2. **Bridge Finding Patterns:**
   - DFS with discovery and low time tracking
   - Parent-child relationship analysis
   - Back edge identification
   - Single-pass graph analysis

3. **Optimization Techniques:**
   - Lazy updates with priority queue
   - Early termination when possible
   - Efficient data structure selection
   - On-the-fly distance calculation

## Time and Space Complexity Summary

| Problem                   | Time Complexity | Space Complexity | Approach                    |
| ------------------------- | --------------- | ---------------- | --------------------------- |
| Min Cost to Connect Points| O(n² log n)     | O(n)             | Prim's with Priority Queue  |
| Critical Connections      | O(V + E)        | O(V + E)         | Tarjan's Algorithm          |

## Alternative Approaches

### Kruskal's Algorithm for MST

```cpp
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Generate all edges with weights
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int weight = abs(points[i][0] - points[j][0]) + 
                            abs(points[i][1] - points[j][1]);
                edges.push_back({weight, i, j});
            }
        }
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        
        // Initialize Union-Find
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int totalCost = 0;
        int edgesAdded = 0;
        
        // Kruskal's algorithm
        for (auto [weight, u, v] : edges) {
            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, rank, u, v);
                totalCost += weight;
                edgesAdded++;
                
                // MST has n-1 edges
                if (edgesAdded == n-1) break;
            }
        }
        
        return totalCost;
    }
};
```

### Optimized Prim's Algorithm without Priority Queue

```cpp
class OptimizedSolution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        int totalCost = 0;
        
        for (int i = 0; i < n; i++) {
            // Find vertex with minimum distance
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            visited[u] = true;
            totalCost += minDist[u];
            
            // Update distances
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + 
                               abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }
        
        return totalCost;
    }
};
```

## Applications

1. **Network Design:**
   - Designing city networks with minimum road length
   - Connecting data centers with minimum cable length
   - Setting up IoT sensor networks

2. **Infrastructure Planning:**
   - Pipeline or electricity grid design
   - Telecommunications network planning
   - Urban planning and facility location

3. **Network Reliability Analysis:**
   - Identifying critical connections (single points of failure)
   - Network robustness assessment
   - Fault-tolerant system design

4. **Circuit Design:**
   - PCB trace routing optimization
   - Minimizing wire length in VLSI design
   - Designing fault-tolerant circuits

## Practice Problems

- [Leetcode 1489 - Find Critical and Pseudo-Critical Edges in MST](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)
- [Leetcode 1135 - Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
- [Leetcode 684 - Redundant Connection](https://leetcode.com/problems/redundant-connection/)
- [Leetcode 743 - Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [Leetcode 1168 - Optimize Water Distribution in a Village](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)
- [SPOJ - MST](https://www.spoj.com/problems/MST/)
- [HackerEarth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/)

## Notes

- **Choice of MST Algorithm:** Prim's works well for dense graphs, while Kruskal's is often better for sparse graphs.
- **Bridge Detection:** Bridges represent vulnerabilities in networks where removal of a single edge disconnects the graph.
- **Manhattan vs Euclidean Distance:** Manhattan is often preferred for grid-like problems and is computationally cheaper.
- **Edge Cases:** Single points (return 0), disconnected components (handled by MST algorithms), and complete graphs (all points connected).
- **Performance Optimization:** For dense graphs in MST problems, array-based implementations can outperform priority queue-based ones.
- **DFS Implementation:** For bridge finding, careful handling of back edges is crucial for correctly calculating low values.

## Sample Usage

### Running Min Cost to Connect Points:

```bash
g++ -o connect_points Leetcode_1584.cpp
./connect_points
```

### Running Critical Connections:

```bash
g++ -o critical_connections Leetcode_1192.cpp
./critical_connections
```

## Next Steps

- Implement and compare different MST algorithms (Prim's, Kruskal's, Borůvka's)
- Explore different distance metrics for geometric MST problems
- Study articulation points (critical vertices) in addition to bridges
- Implement strongly connected components algorithms
- Explore dynamic MST algorithms for evolving graphs
- Study approximation algorithms for NP-hard graph problems like Steiner Tree
- Implement visualization tools for MST and bridge detection