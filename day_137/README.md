# Day 137: All Paths From Source to Target in a DAG

## Overview

Day 137 focuses on path finding in a Directed Acyclic Graph (DAG). The problem involves finding all possible paths from a source node to a target node in a graph represented using an adjacency list. This is a classic graph traversal problem that demonstrates the application of Depth-First Search (DFS) with backtracking in DAGs.

## Problems Covered

### 1. All Paths From Source to Target (Leetcode 797)

**File:** [Leetcode_797.cpp](./Leetcode_797.cpp)

**Problem Link:** [Leetcode 797 - All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

**Problem:** Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

**Example:**

```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Approach Implemented:**

**DFS with Backtracking Solution (O(2^N \* N)):**

```cpp
class Solution {
private:
    void dfs(int node,
             vector<int> &currPath,
             vector<vector<int>>& graph,
             vector<vector<int>> &ans) {

        // Add current node to path
        currPath.push_back(node);

        // If we reached the target node (last node in the graph)
        if(node == graph.size() - 1) {
            // Add current path to answer
            ans.push_back(currPath);
        } else {
            // Otherwise, explore all adjacent nodes
            for(int nextNode : graph[node]) {
                dfs(nextNode, currPath, graph, ans);
            }
        }

        // Backtrack by removing current node from path
        currPath.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> currPath;

        // Start DFS from node 0 (source)
        dfs(0, currPath, graph, ans);

        return ans;
    }
};
```

**Key Insight:** Since the graph is a DAG, we don't need to keep track of visited nodes because there can't be any cycles. This simplifies the DFS approach and allows us to use backtracking to explore all possible paths.

**Time Complexity:** O(2^N \* N) - There can be at most 2^(N-2) possible paths in a DAG with N nodes, and each path can have up to N nodes.
**Space Complexity:** O(N) - For the recursive call stack and to store the current path.

## Key Concepts Covered

### 1. **Graph Traversal in DAGs**

- **Depth-First Search (DFS):** Exploring as far as possible along each branch before backtracking
- **Backtracking:** Building a solution incrementally and abandoning a partial solution when it can't lead to a valid complete solution
- **Path Finding:** Discovering all possible paths between two nodes

### 2. **Graph Representation**

- **Adjacency List:** An efficient representation for sparse graphs
- **Directed Acyclic Graph (DAG):** A directed graph with no cycles, which simplifies traversal

### 3. **Data Structure Usage**

- **Vector of Vectors:** For adjacency list representation and storing paths
- **Recursive Stack:** For DFS traversal
- **Path Tracking:** Building and maintaining the current path during traversal

### 4. **Algorithm Flow**

- **Path Building:** Adding nodes to the current path as we explore
- **Base Case Detection:** Identifying when we've reached the target node
- **Path Collection:** Storing complete paths when they reach the target
- **Backtracking:** Removing nodes from the path when backtracking

## Why DAGs are Special

Directed Acyclic Graphs (DAGs) have several properties that make them easier to work with:

1. **No Cycles:** The absence of cycles means we don't need to track visited nodes during traversal
2. **Topological Ordering:** DAGs can be linearly ordered such that for every directed edge (u, v), u comes before v
3. **Simplifies Path Finding:** All paths are finite and can be enumerated completely
4. **Real-world Applications:** DAGs model many real-world scenarios like task scheduling, build systems, and dependency resolution

## Applications

1. **Task Scheduling:** Finding all possible execution sequences for dependent tasks
2. **Network Routing:** Discovering all possible routes between network nodes
3. **Dependency Resolution:** Finding all possible ways to satisfy dependencies in a system
4. **Circuit Design:** Analyzing signal flow paths in electronic circuits
5. **Project Management:** Determining possible sequences for completing a project with interdependent tasks

## Practice Problems

- [Leetcode 399 - Evaluate Division](https://leetcode.com/problems/evaluate-division/)
- [Leetcode 1059 - All Paths from Source Lead to Destination](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)
- [Leetcode 332 - Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)
- [Leetcode 2192 - All Ancestors of a Node in a Directed Acyclic Graph](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)
- [Leetcode 1584 - Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

## Notes

- **DAG vs General Graphs:** In general graphs, we would need to track visited nodes to avoid cycles
- **Path Enumeration:** For dense graphs, the number of paths can grow exponentially
- **Optimizations:** For large DAGs, consider using memoization or dynamic programming to avoid redundant calculations
- **Memory Management:** Be mindful of memory usage when storing all paths, as the number of paths can be exponential
- **Alternative Approaches:** BFS can also be used, but DFS with backtracking is typically more intuitive for path enumeration

## Sample Usage

### Running All Paths From Source to Target:

```bash
g++ -o all_paths Leetcode_797.cpp
./all_paths
```

## Next Steps

- Implement a BFS-based solution for comparison
- Explore path finding in weighted DAGs (shortest/longest paths)
- Study more complex graph algorithms like A\* search
- Investigate applications of path finding in real-world problems
- Extend the solution to handle constraints on paths (e.g., avoiding certain nodes)
