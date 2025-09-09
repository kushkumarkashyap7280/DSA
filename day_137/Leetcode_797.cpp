// 797. All Paths From Source to Target

// link - https://leetcode.com/problems/all-paths-from-source-to-target/

/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]


Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    // DFS traversal to find all paths from current node to target
    void dfs(int node,
             vector<int> &currPath,
             vector<vector<int>> &graph,
             vector<vector<int>> &ans)
    {

        // Add current node to path
        currPath.push_back(node);

        // If we reached the target node (last node in the graph)
        if (node == graph.size() - 1)
        {
            // Add current path to answer
            ans.push_back(currPath);
        }
        else
        {
            // Otherwise, explore all adjacent nodes
            for (int nextNode : graph[node])
            {
                dfs(nextNode, currPath, graph, ans);
            }
        }

        // Backtrack by removing current node from path
        currPath.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> currPath;

        // Start DFS from node 0 (source)
        dfs(0, currPath, graph, ans);

        return ans;
    }
};

// Function to print paths for testing
void printPaths(const vector<vector<int>> &paths)
{
    cout << "All paths from source to target:" << endl;
    for (const auto &path : paths)
    {
        cout << "[ ";
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << "]" << endl;
    }
}

// Test cases
int main()
{
    Solution solution;

    // Test case 1
    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    cout << "Test Case 1:" << endl;
    auto result1 = solution.allPathsSourceTarget(graph1);
    printPaths(result1);
    cout << endl;

    // Test case 2
    vector<vector<int>> graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    cout << "Test Case 2:" << endl;
    auto result2 = solution.allPathsSourceTarget(graph2);
    printPaths(result2);

    return 0;
}