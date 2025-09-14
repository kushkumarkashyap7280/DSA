# Day 140: Minimum Spanning Tree (MST) Algorithms

## Overview

Day 140 focuses on Minimum Spanning Tree (MST) algorithms, which are fundamental in graph theory for finding a subset of edges that connect all vertices with the minimum possible total edge weight. This implementation covers Prim's algorithm for MST construction, which is crucial for network design, circuit design, transportation networks, and clustering algorithms.

## Problems Covered

### 1. Minimum Spanning Tree using Prim's Algorithm

**File:** [mst.cpp](./mst.cpp)

**Problem Link:** [GeeksForGeeks - Minimum Spanning Tree](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1)

**Problem:** Given a weighted, undirected, and connected graph with V vertices and E edges, find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.

**Example:**

```
Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
Output: 4

Input: V = 2, E = 1, Edges = [[0, 1, 5]]
Output: 5
```

**Approaches Implemented:**

1. **Prim's Algorithm with Priority Queue (O(E log V)):**

   ```cpp
   class Solution {
   public:
       int spanningTree(int V, vector<vector<int>>& edges) {
           // Build adjacency list {node, weight}
           vector<vector<pair<int,int>>> adj(V);
           for (auto &edge : edges) {
               int u = edge[0];
               int v = edge[1];
               int wt = edge[2];
               adj[u].push_back({v, wt});
               adj[v].push_back({u, wt});  // Since undirected
           }

           // Min-Heap: {weight, node}
           priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

           vector<bool> inMST(V, false);
           minHeap.push({0, 0});  // Start from node 0

           int totalWeight = 0;

           while (!minHeap.empty()) {
               auto [wt, node] = minHeap.top();
               minHeap.pop();

               if (inMST[node]) continue;

               inMST[node] = true;
               totalWeight += wt;

               for (auto &[neigh, edgeWt] : adj[node]) {
                   if (!inMST[neigh]) {
                       minHeap.push({edgeWt, neigh});
                   }
               }
           }

           return totalWeight;
       }
   };
   ```

**Key Insight:** Prim's algorithm builds the MST by always selecting the edge with the minimum weight that connects a vertex in the MST to a vertex outside the MST.

**Time Complexity:** O(E log V)
- Building adjacency list: O(E)
- Priority queue operations: Each edge can be added to the queue once, and each pop takes O(log E) time
- Total: O(E log E), which is equivalent to O(E log V) since E ≤ V²

**Space Complexity:** O(V + E)
- Adjacency list: O(E)
- Priority queue: O(E) in worst case
- Visited array: O(V)

## Alternative Approach: Kruskal's Algorithm

While not implemented in the current file, Kruskal's algorithm is another common approach for solving MST problems:

```cpp
class Solution {
public:
    // Disjoint Set Union (DSU) implementation
    vector<int> parent, rank;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Initialize DSU
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;
            
        // Convert edges to sorted list format [weight, u, v]
        vector<vector<int>> edgeList;
        for (auto& edge : edges) {
            edgeList.push_back({edge[2], edge[0], edge[1]});
        }
        
        // Sort edges by weight
        sort(edgeList.begin(), edgeList.end());
        
        int totalWeight = 0;
        int edgesAdded = 0;
        
        // Process edges in ascending order of weight
        for (auto& edge : edgeList) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            // If including this edge doesn't create a cycle
            if (find(u) != find(v)) {
                unionSets(u, v);
                totalWeight += wt;
                edgesAdded++;
                
                // MST has exactly V-1 edges
                if (edgesAdded == V-1)
                    break;
            }
        }
        
        return totalWeight;
    }
};
```

**Time Complexity (Kruskal's):** O(E log E) or O(E log V)
- Sorting edges: O(E log E)
- Union-Find operations: O(E * α(V)), where α is the inverse Ackermann function (almost constant)

**Space Complexity (Kruskal's):** O(V + E)
- Edge list: O(E)
- Union-Find data structures: O(V)

## Key Concepts Covered

### 1. **Minimum Spanning Tree (MST)**
- A tree that spans all vertices with minimum total edge weight
- Contains exactly V-1 edges for a graph with V vertices
- No cycles (since it's a tree)

### 2. **Prim's Algorithm**
- Greedy approach starting from any vertex
- Grows MST one vertex at a time
- Uses priority queue to find minimum weight edge
- Similar to Dijkstra's algorithm but focuses on minimizing total edge weight

### 3. **Graph Representation**
- Adjacency list for efficient edge traversal
- Priority queue for selecting minimum weight edges
- Visited array to track nodes included in MST

### 4. **Edge Cases**
- Disconnected graphs (not handled in this implementation since problem states connected graph)
- Multiple edges with same weight (handled naturally by the algorithm)
- Cycle detection (handled by the visited array)

## Common Applications

1. **Network Design:** 
   - Designing networks with minimum cost
   - Laying cables with minimum total length

2. **Approximation Algorithms:**
   - Traveling Salesman Problem approximation
   - Clustering algorithms

3. **Circuit Design:**
   - Minimizing wire length in PCB design
   - VLSI layout optimization

4. **Transportation Networks:**
   - Road network design
   - Pipeline construction

## Variations and Extensions

1. **Maximum Spanning Tree:**
   - Find spanning tree with maximum total weight
   - Simply negate all weights and apply MST algorithm

2. **Bottleneck Spanning Tree:**
   - Minimize the maximum edge weight in the spanning tree
   - Useful for maximizing bandwidth in network design

3. **Minimum Spanning Forest:**
   - Find MST for each connected component in a disconnected graph

4. **Degree-Constrained MST:**
   - Find MST with constraints on vertex degrees
   - NP-hard problem requiring approximation algorithms

## Practice Problems

- [Leetcode 1584 - Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
- [GeeksForGeeks - Minimum Spanning Tree](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)
- [HackerRank - Kruskal (MST): Really Special Subtree](https://www.hackerrank.com/challenges/kruskalmstrsub/problem)
- [SPOJ - Minimum Spanning Tree](https://www.spoj.com/problems/MST/)
- [Leetcode 1135 - Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

## Notes

- **Algorithm Selection:** 
  - Prim's is better for dense graphs
  - Kruskal's is better for sparse graphs

- **Optimizations:**
  - Use adjacency matrix for dense graphs
  - Use binary heaps for better performance in sparse graphs
  - Use Fibonacci heaps for theoretical improvement (though rarely needed in practice)

- **Edge Cases:**
  - Handle disconnected graphs by checking if all vertices are visited
  - Consider negative weights (usually not allowed in MST problems)

## Sample Usage

```bash
g++ -o mst mst.cpp
./mst
```

## Next Steps

- Implement Kruskal's algorithm for MST
- Study variations like maximum spanning tree
- Explore applications in network design and clustering
- Learn about the relationship between MST and other graph algorithms
- Study approximation algorithms based on MST