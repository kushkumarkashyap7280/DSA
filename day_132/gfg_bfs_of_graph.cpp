/**
 * BFS Traversal of Graph - GeeksforGeeks Problem
 *
 * Problem: Given a connected undirected graph, perform a Breadth First Search (BFS)
 * traversal starting from vertex 0.
 *
 * Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
 *
 * Problem Statement:
 * Given a connected undirected graph containing V vertices, represented by a 2-d adjacency
 * list adj[][], perform a Breadth First Search (BFS) traversal starting from vertex 0 and
 * return a list containing the BFS traversal of the graph.
 *
 * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
 * Space Complexity: O(V) for the queue and visited array
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * Solution class for the BFS traversal problem
 */
class Solution
{
public:
    /**
     * Performs BFS traversal of a graph
     *
     * @param adj Adjacency list representation of the graph
     * @return Vector containing the BFS traversal order
     */
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> ans;    // To store the BFS traversal result
        int V = adj.size(); // Number of vertices

        vector<bool> isVisited(V, false); // Track visited vertices

        // Handle all components (for disconnected graphs)
        for (int start = 0; start < V; start++)
        {
            if (!isVisited[start])
            {
                // BFS for current component
                queue<int> q;
                q.push(start);
                isVisited[start] = true;

                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();

                    ans.push_back(curr); // Add current node to result

                    // Visit all unvisited neighbors
                    for (int nbr : adj[curr])
                    {
                        if (!isVisited[nbr])
                        {
                            q.push(nbr);
                            isVisited[nbr] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * Example usage:
 *
 * Example 1:
 * Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
 * Output: [0, 2, 3, 1, 4]
 *
 * Example 2:
 * Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
 * Output: [0, 1, 2, 3, 4]
 */
