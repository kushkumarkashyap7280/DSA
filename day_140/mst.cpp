// Minimum Spanning Tree (MST) using Prim's Algorithm
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

Approach (Prim's Algorithm):
1. Build an adjacency list representation of the graph
2. Use a priority queue (min-heap) to select the minimum weight edge at each step
3. Start from any vertex (here, vertex 0)
4. For each unvisited neighbor of the current vertex, add it to the priority queue
5. Select the edge with minimum weight that doesn't form a cycle
6. Repeat until all vertices are included in the MST

Time Complexity: O(E log V)
- Building adjacency list: O(E)
- Priority queue operations: Each edge can be added to the queue once, and each pop takes O(log E) time
- Total: O(E log E), which is equivalent to O(E log V) since E ≤ V²

Space Complexity: O(V + E)
- Adjacency list: O(E)
- Priority queue: O(E) in worst case
- Visited array: O(V)
*/

#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Build adjacency list where adj[u] contains pairs {v, weight}
        vector<vector<pair<int,int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Since the graph is undirected
        }

        // Min-Heap to get the minimum weight edge at each step
        // Each element is {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        // Track vertices included in MST
        vector<bool> inMST(V, false);
        
        // Start from vertex 0
        minHeap.push({0, 0});  // {weight, vertex}
        
        int totalWeight = 0;  // Sum of weights in MST

        // Prim's algorithm main loop
        while (!minHeap.empty()) {
            // Extract the minimum weight edge
            auto [wt, node] = minHeap.top();
            minHeap.pop();

            // If node already in MST, skip
            if (inMST[node]) continue;

            // Include vertex in MST
            inMST[node] = true;
            totalWeight += wt;  // Add edge weight to total

            // Explore all adjacent vertices of the current vertex
            for (auto &[neigh, edgeWt] : adj[node]) {
                // If neighbor not yet in MST, add edge to priority queue
                if (!inMST[neigh]) {
                    minHeap.push({edgeWt, neigh});
                }
            }
        }

        // Return total weight of MST
        return totalWeight;
    }
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
    cout << "Testing Minimum Spanning Tree Implementation (Prim's Algorithm):" << endl;
    testMST();
    return 0;
}
