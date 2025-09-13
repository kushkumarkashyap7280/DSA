//743. Network Delay Time
// link: https://leetcode.com/problems/network-delay-time/description/

#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

/*
Problem:
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Constraints:
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

Approach (Dijkstra's Algorithm):
1. Create an adjacency list representation of the graph where for each node, we store pairs of (weight, target_node)
2. Initialize distance array with infinity for all nodes except the source node (which is set to 0)
3. Use a set to implement a priority queue that keeps nodes sorted by their current distance
4. Process nodes in order of increasing distance:
   a. Extract the node with minimum distance from the set
   b. For each neighbor of the extracted node:
      i. Calculate new potential distance = current node's distance + edge weight
      ii. If this new distance is shorter, update the distance and add to the set
5. After processing all reachable nodes, find the maximum distance (which represents the time when all nodes receive the signal)
6. If any node is unreachable (distance still infinity), return -1

Time Complexity: O(E log V)
- Building adjacency list: O(E)
- Dijkstra's main loop: O(V) iterations in worst case
- For each vertex, we process all outgoing edges: O(E) operations total
- Each set operation (insert/erase) takes O(log V) time
- Overall: O(E log V) where E is the number of edges and V is the number of vertices

Space Complexity: O(V + E)
- Adjacency list: O(E)
- Distance array: O(V)
- Set for priority queue: O(V) in worst case
*/




class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list - Format: adj[from] = {(weight, to), ...}
        vector<vector<pair<int,int>>> adj(n);
        for (auto &i : times) {
            adj[i[0]-1].push_back({ i[2], i[1]-1 });  // {weight, target}
        }

        // Initialize distance array with infinity
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;  // Source node has distance 0

        // Use set as priority queue - Format: {distance, node}
        set<pair<int,int>> st;
        st.insert({0, k-1});

        // Dijkstra's algorithm main loop
        while (!st.empty()) {
            // Extract node with minimum distance
            auto top = *(st.begin());
            st.erase(st.begin());

            int topNodeDist = top.first;  // Current distance
            int topNode = top.second;     // Current node

            // Process all neighbors
            for (auto &neighbour : adj[topNode]) {
                int edgeWeight = neighbour.first;  // Weight of edge
                int neighNode = neighbour.second;  // Target node

                // Relaxation step: update if we found a shorter path
                if (topNodeDist + edgeWeight < dist[neighNode]) {
                    dist[neighNode] = topNodeDist + edgeWeight;
                    st.insert({dist[neighNode], neighNode});
                }
            }
        }

        // Find maximum time for signal to reach any node
        int maxDist = *max_element(dist.begin(), dist.end());
        
        // If any node is unreachable, return -1
        return (maxDist == INT_MAX) ? -1 : maxDist;
    }
};

// Main function with test cases
int main() {
    Solution solution;
    
    // Test Case 1: Standard example from problem
    vector<vector<int>> times1 = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n1 = 4, k1 = 2;
    cout << "Test Case 1: " << solution.networkDelayTime(times1, n1, k1) << " (Expected: 2)" << endl;
    
    // Test Case 2: All nodes reachable in 1 step
    vector<vector<int>> times2 = {{1,2,1}, {1,3,1}, {1,4,1}};
    int n2 = 4, k2 = 1;
    cout << "Test Case 2: " << solution.networkDelayTime(times2, n2, k2) << " (Expected: 1)" << endl;
    
    // Test Case 3: Unreachable node
    vector<vector<int>> times3 = {{1,2,1}};
    int n3 = 2, k3 = 2;
    cout << "Test Case 3: " << solution.networkDelayTime(times3, n3, k3) << " (Expected: -1)" << endl;
    
    // Test Case 4: Complex network with multiple paths
    vector<vector<int>> times4 = {{1,2,1}, {2,3,7}, {1,3,4}, {2,1,2}};
    int n4 = 3, k4 = 1;
    cout << "Test Case 4: " << solution.networkDelayTime(times4, n4, k4) << " (Expected: 4)" << endl;
    
    return 0;
}
