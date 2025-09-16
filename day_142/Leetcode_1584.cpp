// 1584. Min Cost to Connect All Points
// Problem Link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

/*
Problem Statement:
You are given an array points representing integer coordinates of some points on a 2D-plane, 
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
|xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly 
one simple path between any two points.

Examples:
Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: We can connect the points as shown to get the minimum cost of 20.
             Notice that there is a unique path between every pair of points.

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Constraints:
- 1 <= points.length <= 1000
- -10^6 <= xi, yi <= 10^6
- All pairs (xi, yi) are distinct.

Approach (Prim's Algorithm):
1. Treat each point as a vertex in a graph
2. The weight of an edge between two points is the Manhattan distance
3. Use Prim's algorithm to find the minimum spanning tree:
   a. Start with any vertex (we choose point 0)
   b. Use a priority queue to select the minimum weight edge at each step
   c. Add the selected edge to the MST and explore its adjacent vertices
   d. Continue until all points are connected

Time Complexity: O(n² log n)
- For each of the n vertices, we may add O(n) edges to the priority queue
- Each priority queue operation takes O(log n) time
- Total: O(n² log n)

Space Complexity: O(n)
- Priority queue: O(n) in worst case
- Distance array: O(n)
- Visited array: O(n)
*/

#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();  // Number of points

        // Distance array to keep track of minimum distance to each point
        vector<int> dist(n, INT_MAX);
        
        // Track visited points
        vector<int> isVisited(n, 0);

        // Min-heap priority queue {cost, point index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Start from point 0 with cost 0
        pq.push({0, 0});
        dist[0] = 0;  // Distance to first point is 0

        int totalCost = 0;  // Total cost of the MST
        int edgesAdded = 0;  // Count of edges added to MST

        // Prim's algorithm main loop
        while (!pq.empty() && edgesAdded < n) {
            // Extract the point with minimum connection cost
            auto [currCost, index] = pq.top();
            pq.pop();

            // Skip if already visited
            if (isVisited[index]) continue;

            // Mark as visited and add cost to total
            isVisited[index] = true;
            totalCost += currCost;
            edgesAdded++;

            // Explore all other points
            for (int i = 0; i < n; i++) {
                if (!isVisited[i]) {
                    // Calculate Manhattan distance
                    int manhattan_dist = abs(points[index][0] - points[i][0]) + 
                                        abs(points[index][1] - points[i][1]);

                    // If we found a shorter path to point i
                    if (manhattan_dist < dist[i]) {
                        dist[i] = manhattan_dist;
                        pq.push({manhattan_dist, i});
                    }
                }
            }
        }

        return totalCost;
    }
};

// Test function to demonstrate the MST solution
int main() {
    Solution sol;
};


int main() {
    Solution sol;
    // Test Case 1: Standard example from problem statement
    vector<vector<int>> points1 = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Test Case 1: Minimum Cost = " << sol.minCostConnectPoints(points1) << " (Expected: 20)" << endl;
    
    // Test Case 2: Another example from problem statement
    vector<vector<int>> points2 = {{3,12}, {-2,5}, {-4,1}};
    cout << "Test Case 2: Minimum Cost = " << sol.minCostConnectPoints(points2) << " (Expected: 18)" << endl;
    
    // Test Case 3: Single point (edge case)
    vector<vector<int>> points3 = {{0,0}};
    cout << "Test Case 3: Minimum Cost = " << sol.minCostConnectPoints(points3) << " (Expected: 0)" << endl;
    
    // Test Case 4: Points in a line
    vector<vector<int>> points4 = {{0,0}, {1,1}, {2,2}, {3,3}};
    cout << "Test Case 4: Minimum Cost = " << sol.minCostConnectPoints(points4) << " (Expected: 3)" << endl;
    
    return 0;
}