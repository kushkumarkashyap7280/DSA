# Day 141: Minimum Spanning Tree (MST) using Kruskal's Algorithm

## Overview

Day 141 focuses on implementing the Minimum Spanning Tree (MST) using Kruskal's algorithm, which is a greedy approach to finding the minimum spanning tree of a weighted, undirected graph. Unlike Prim's algorithm (covered in day_140), Kruskal's algorithm processes edges in ascending order of weight and uses a Disjoint Set data structure to detect cycles.

## Problems Covered

### 1. Minimum Spanning Tree using Kruskal's Algorithm

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

1. **Kruskal's Algorithm with Union-Find (O(E log E)):**

   ```cpp
   class Solution {
       // Find parent of a node in the disjoint set
       int findParent(vector<int> &parent, int node) {
           if(parent[node] == node) return node;
           return parent[node] = findParent(parent, parent[node]);
       }
       
       // Union operation to merge two sets
       void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
           u = findParent(parent, u);
           v = findParent(parent, v);
           
           if (u == v) return;  // Already in the same set
           
           if (rank[u] < rank[v]) {
               parent[u] = v;
           } else if (rank[v] < rank[u]) {
               parent[v] = u;
           } else {
               parent[v] = u;
               rank[u]++;
           }
       }
       
   public:
       int spanningTree(int V, vector<vector<int>>& edges) {
           // Sort edges by weight
           sort(edges.begin(), edges.end(), [](vector<int> u, vector<int> v) {
               return u[2] < v[2];
           });
           
           // Initialize disjoint set
           vector<int> parent(V), rank(V, 0);
           for(int i = 0; i < V; i++) parent[i] = i;
           
           int minWeight = 0;
           
           // Process edges in ascending order of weight
           for(auto &edge : edges) {
               int u = findParent(parent, edge[0]);
               int v = findParent(parent, edge[1]);
               
               // If including this edge doesn't create a cycle
               if(u != v) {
                   minWeight += edge[2];
                   unionSet(u, v, parent, rank);
               }
           }
           
           return minWeight;
       }
   };
   ```

**Key Insight:** Kruskal's algorithm builds the MST by adding edges in ascending order of weight, as long as they don't create a cycle. This is efficiently implemented using a disjoint-set data structure with union-find operations.

**Time Complexity:** O(E log E)
- Sorting edges: O(E log E)
- Union-Find operations: O(E * α(V)), where α is the inverse Ackermann function (practically constant)
- Total: O(E log E) dominates

**Space Complexity:** O(V + E)
- Edges array: O(E)
- Disjoint-set data structure: O(V)

## Comparison with Prim's Algorithm (Day 140)

Kruskal's and Prim's algorithms both solve the MST problem, but with different approaches:

| Aspect | Kruskal's Algorithm | Prim's Algorithm |
|--------|---------------------|------------------|
| Basic Approach | Edge-based: Processes edges in order of weight | Vertex-based: Grows a single tree from a starting vertex |
| Data Structure | Disjoint-Set (Union-Find) | Priority Queue |
| Best For | Sparse graphs (E ≈ V) | Dense graphs (E ≈ V²) |
| Time Complexity | O(E log E) | O(E log V) |
| Implementation | Simpler with sorting | Requires adjacency list/matrix |
| Edge Selection | Global minimum edge | Local minimum edge |

## Key Concepts Covered

### 1. **Disjoint-Set Data Structure**
- Union-Find operations for efficient cycle detection
- Path compression optimization for faster lookups
- Union by rank for balanced trees

### 2. **Kruskal's Algorithm**
- Greedy edge selection based on weight
- Global minimum edge selection strategy
- Cycle detection using Union-Find

### 3. **Minimum Spanning Tree Properties**
- Contains exactly V-1 edges for a graph with V vertices
- No cycles (by definition of a tree)
- Connects all vertices with minimum total weight

### 4. **Optimization Techniques**
- Path compression in find operation
- Union by rank for balanced tree height
- Efficient sorting of edges

## Applications of MST

1. **Network Design:**
   - Telecommunications network design
   - Electrical grid planning
   - Water supply network optimization

2. **Clustering Algorithms:**
   - Hierarchical clustering
   - Single-linkage clustering

3. **Approximation Algorithms:**
   - Traveling Salesman Problem approximation
   - Steiner Tree approximation

4. **Real-world Applications:**
   - Road network design
   - Circuit board design
   - Network routing

## Variations and Extensions

1. **Maximum Spanning Tree:**
   - Find the spanning tree with maximum total weight
   - Simply negate all edge weights and apply MST algorithm

2. **Second-Best Spanning Tree:**
   - Find the MST with second minimum total weight
   - Find MST, then for each edge in MST, find minimum spanning tree excluding that edge

3. **Minimum Bottleneck Spanning Tree:**
   - Minimize the maximum edge weight in the spanning tree
   - Any MST is also a minimum bottleneck spanning tree

4. **k-Minimum Spanning Tree:**
   - Find a tree with k vertices with minimum total weight
   - NP-hard problem requiring heuristics

## Practice Problems

- [Leetcode 1584 - Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)
- [Leetcode 1135 - Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
- [HackerRank - Kruskal (MST): Really Special Subtree](https://www.hackerrank.com/challenges/kruskalmstrsub/problem)
- [SPOJ - Minimum Spanning Tree](https://www.spoj.com/problems/MST/)
- [Codeforces - Two MST](https://codeforces.com/problemset/problem/1508/C)

## Notes

- **Disjoint-Set Optimization:**
  - Path compression reduces time complexity for find operations
  - Union by rank keeps the tree height balanced
  - These optimizations make the amortized time complexity nearly constant

- **Implementation Considerations:**
  - Sort edges only once at the beginning
  - Process edges in order to avoid unnecessary comparisons
  - Handle edge cases like disconnected graphs (though the problem states the graph is connected)

- **Kruskal vs Prim:**
  - Kruskal is often simpler to implement
  - Prim may be faster for dense graphs
  - Both algorithms produce the same result for unique edge weights

## Sample Usage

```bash
g++ -o mst mst.cpp
./mst
```

## Next Steps

- Implement Borůvka's algorithm for MST (another approach)
- Explore MST variants like maximum spanning tree and bottleneck spanning tree
- Study dynamic MST algorithms for graphs with changing edge weights
- Implement MST algorithms for directed graphs (Minimum Arborescence)
- Apply MST algorithms to solve real-world optimization problems