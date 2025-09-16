// 1192. Critical Connections in a Network
// Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/

/*
Problem Statement:
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections 
forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. 
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some 
other server.

Return all critical connections in the network in any order.

Examples:
Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
- 2 <= n <= 10^5
- n - 1 <= connections.length <= 10^5
- 0 <= ai, bi <= n - 1
- ai != bi
- There are no repeated connections.

Approach (Tarjan's Algorithm / Bridge Finding Algorithm):
1. Create an adjacency list from the given connections
2. Perform DFS traversal of the graph:
   a. Keep track of discovery time (disTime) for each node
   b. Maintain a low value (low) representing the earliest visited vertex reachable from the subtree
   c. If low[child] > disTime[parent], then the edge is a bridge (critical connection)
3. Return all bridges found during the traversal

Time Complexity: O(V + E)
- Building adjacency list: O(E)
- DFS traversal: O(V + E)
- Total: O(V + E)

Space Complexity: O(V + E)
- Adjacency list: O(E)
- Visited, discovery time, and low arrays: O(V) each
- Result list: O(E) in worst case
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
    /**
     * DFS function to find bridges in the graph
     * 
     * @param node Current node being processed
     * @param parent Parent of the current node
     * @param timer Current timer value for discovery time
     * @param isVisited Array to track visited nodes
     * @param low Low values for each node
     * @param disTime Discovery time for each node
     * @param ans Result vector to store bridges
     * @param adj Adjacency list representing the graph
     */
    void dfs(int node, int parent, 
             int &timer, vector<int> &isVisited, 
             vector<int> &low, vector<int> &disTime,
             vector<vector<int>> &ans,
             vector<vector<int>> &adj) {
        
        // Mark current node as visited
        isVisited[node] = 1;
        
        // Initialize discovery time and low value
        disTime[node] = low[node] = timer++;

        // Process all neighbors of current node
        for(auto nbr : adj[node]) {
            // Skip parent (already processed)
            if(nbr == parent) continue;

            // If neighbor not visited, process it
            if(!isVisited[nbr]) {
                // Recursively process the neighbor
                dfs(nbr, node, timer, isVisited, low, disTime, ans, adj);
                
                // Update low value of current node based on its neighbor
                low[node] = min(low[node], low[nbr]);

                // Check if this edge is a bridge
                // If low value of neighbor is greater than discovery time of current node,
                // then this edge is a bridge (critical connection)
                if(low[nbr] > disTime[node]) {
                    ans.push_back({node, nbr});
                }
            } else {
                // For a back edge to an already visited node (except parent)
                // Update low value if needed
                low[node] = min(low[node], disTime[nbr]);
            }
        }
    }

public:
    /**
     * Find all critical connections in the network
     * 
     * @param n Number of servers
     * @param connections Array of connections between servers
     * @return Vector of critical connections
     */
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create adjacency list representation of the graph
        vector<vector<int>> adj(n);
        for(auto &connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        // Initialize arrays for Tarjan's algorithm
        vector<int> isVisited(n, 0);  // Track visited nodes
        vector<int> low(n, -1);       // Low values
        vector<int> disTime(n, -1);   // Discovery times
        int timer = 0;                // Timer for discovery times
        
        vector<vector<int>> ans;      // Result vector for bridges

        // Perform DFS on each unvisited node (handles disconnected components)
        for(int i = 0; i < n; i++) {
            if(!isVisited[i]) {
                dfs(i, -1, timer, isVisited, low, disTime, ans, adj);
            }
        }
    
        return ans;
    }
};

// Test function to demonstrate the critical connections algorithm
int main() {
    Solution sol;
    
    // Test Case 1: Example from LeetCode
    cout << "Test Case 1:" << endl;
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1}, {1,2}, {2,0}, {1,3}};
    cout << "Input: n = " << n1 << ", connections = [";
    for (size_t i = 0; i < connections1.size(); i++) {
        cout << "[" << connections1[i][0] << "," << connections1[i][1] << "]";
        if (i < connections1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<vector<int>> result1 = sol.criticalConnections(n1, connections1);
    cout << "Output: [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[" << result1[i][0] << "," << result1[i][1] << "]";
        if (i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected: [[1,3]]" << endl;
    
    // Test Case 2: Larger example
    cout << "\nTest Case 2:" << endl;
    int n2 = 6;
    vector<vector<int>> connections2 = {{0,1}, {1,2}, {2,0}, {1,3}, {3,4}, {4,5}, {5,3}};
    cout << "Input: n = " << n2 << ", connections = [";
    for (size_t i = 0; i < connections2.size(); i++) {
        cout << "[" << connections2[i][0] << "," << connections2[i][1] << "]";
        if (i < connections2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<vector<int>> result2 = sol.criticalConnections(n2, connections2);
    cout << "Output: [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "[" << result2[i][0] << "," << result2[i][1] << "]";
        if (i < result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected: [[1,3]]" << endl;
    
    // Time and Space Complexity Analysis
    cout << "\nTime Complexity: O(V + E), where V is the number of vertices and E is the number of edges" << endl;
    cout << "Space Complexity: O(V + E) for the adjacency list and additional arrays" << endl;
    
    return 0;