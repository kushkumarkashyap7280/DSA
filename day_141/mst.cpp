// Minimum Spanning Tree (MST) using Kruskal's Algorithm
// Problem Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

/*
Problem Statement:
Given a weighted, undirected, and connected graph with V vertices and E edges, find the sum of the 
weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a 
list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u 
and vertex v with edge weight w.

Examples:
Example 1:
Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
Output: 4
Explanation: The MST includes edges (0-2) with weight 1 and (1-2) with weight 3, totaling 4.

Example 2:
Input: V = 2, E = 1, Edges = [[0, 1, 5]]
Output: 5
Explanation: Only one Spanning Tree is possible which has a weight of 5.

Constraints:
- 2 ≤ V ≤ 1000
- V-1 ≤ E ≤ (V*(V-1))/2
- 1 ≤ w ≤ 1000
- The graph is connected and doesn't contain self-loops & multiple edges.

Approach (Kruskal's Algorithm):
1. Sort all edges in non-decreasing order of their weight.
2. Initialize a disjoint-set data structure to efficiently detect cycles.
3. Iterate through each edge in ascending order of weight:
   a. If including the edge doesn't form a cycle, include it in the MST.
   b. Otherwise, discard the edge.
4. Continue until V-1 edges are included in the MST.

Time Complexity: O(E log E)
- Sorting edges: O(E log E)
- Union-Find operations: O(E * α(V)), where α is the inverse Ackermann function (practically constant)
- Total: O(E log E) dominates

Space Complexity: O(V + E)
- Edges array: O(E)
- Disjoint-set data structure: O(V)
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
    // Find the parent of a node in the disjoint-set data structure
    // Uses path compression for optimization
    int findParent(vector<int> &parent , int node){
        if(parent[node] == node) return node;
        
        // Path compression: Point node directly to the root parent
        return parent[node] = findParent(parent , parent[node]);
    }
    
    // Union operation to merge two sets
    // Uses union by rank for optimization
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u == v) return;  // Already in the same set

        // Union by rank: Attach smaller rank tree under root of higher rank tree
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            // If ranks are same, make one as root and increment its rank
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree using Kruskal's algorithm
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Sort all edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), [](vector<int> u, vector<int> v){
            return u[2] < v[2];
        });
        
        // Step 2: Initialize disjoint-set data structure
        vector<int> parent(V), rank(V, 0);
        
        // Initially, each vertex is its own parent
        for(int i = 0; i < V; i++) parent[i] = i;
        
        int minWeight = 0;  // Total weight of MST
        int edgesAdded = 0;  // Count of edges added to MST
        
        // Step 3: Process edges in ascending order of weight
        for(auto &edge : edges){
            int u = findParent(parent, edge[0]);
            int v = findParent(parent, edge[1]);
            
            // Step 3a: If including this edge doesn't form a cycle, include it in MST
            if(u != v){
                minWeight += edge[2];
                unionSet(u, v, parent, rank);
                edgesAdded++;
                
                // MST contains exactly V-1 edges, so we can stop once we have enough
                if(edgesAdded == V-1) break;
            }
        }
        
        // Return total weight of MST
        return minWeight;
    }
};

// Test function to verify the implementation
void testMST() {
    Solution sol;
};


// Test function to verify the implementation
void testMST() {
    Solution sol;
    
    // Test Case 1: Standard example from problem statement
    vector<vector<int>> edges1 = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    int V1 = 3;
    int result1 = sol.spanningTree(V1, edges1);
    cout << "Test Case 1: MST Weight = " << result1 << " (Expected: 4)" << endl;
    
    // Test Case 2: Single edge graph
    vector<vector<int>> edges2 = {{0, 1, 5}};
    int V2 = 2;
    int result2 = sol.spanningTree(V2, edges2);
    cout << "Test Case 2: MST Weight = " << result2 << " (Expected: 5)" << endl;
    
    // Test Case 3: Complete graph with 4 vertices
    vector<vector<int>> edges3 = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, 
        {1, 2, 15}, {1, 3, 20}, 
        {2, 3, 4}
    };
    int V3 = 4;
    int result3 = sol.spanningTree(V3, edges3);
    cout << "Test Case 3: MST Weight = " << result3 << " (Expected: 19)" << endl;
    
    // Test Case 4: Star-shaped graph
    vector<vector<int>> edges4 = {
        {0, 1, 2}, {0, 2, 3}, {0, 3, 4}, {0, 4, 5}
    };
    int V4 = 5;
    int result4 = sol.spanningTree(V4, edges4);
    cout << "Test Case 4: MST Weight = " << result4 << " (Expected: 14)" << endl;
}

int main() {
    cout << "Testing Minimum Spanning Tree Implementation (Kruskal's Algorithm):" << endl;
    testMST();
    return 0;
}
