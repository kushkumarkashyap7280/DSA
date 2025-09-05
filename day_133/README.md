# Day 133: Cycle Detection in Graphs

## Concepts Covered

- Cycle detection in undirected graphs
- Graph representation using adjacency lists
- Breadth-First Search (BFS) in graphs
- Depth-First Search (DFS) in graphs
- Handling disconnected components in graphs

## Problems Solved

### 1. [Detect Cycle in an Undirected Graph](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

- **Difficulty**: Medium
- **Approach**: Implemented both BFS and DFS-based solutions
- **Solution**: [gfg_Undirected_Graph_Cycle.cpp](./gfg_Undirected_Graph_Cycle.cpp)

## Cycle Detection in Undirected Graphs

A cycle in an undirected graph is a path that starts and ends at the same vertex, with at least one edge. For example, if vertices A, B, and C form a triangle, then A → B → C → A is a cycle.

### Visual Representation

```
Example 1 (Has Cycle):
    0 -- 1
    |    |
    2 -- 3

Example 2 (No Cycle):
    0 -- 1 -- 2 -- 3
```

### Approaches to Detect Cycles

#### 1. Using BFS (Breadth-First Search)

**Algorithm**:

1. Create an adjacency list representation of the graph
2. For each unvisited node, perform BFS traversal
3. For each vertex, keep track of its parent
4. If during BFS, we find an already visited node that's not the parent of the current node, we've found a cycle

**Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges
**Space Complexity**: O(V) for the queue, visited array, and parent array

#### 2. Using DFS (Depth-First Search)

**Algorithm**:

1. Create an adjacency list representation of the graph
2. For each unvisited node, perform DFS traversal
3. For each vertex, keep track of its parent
4. If during DFS, we find an already visited node that's not the parent of the current node, we've found a cycle

**Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges
**Space Complexity**: O(V) for the recursion stack and visited array

### Key Insights

1. **Back Edge Detection**: A cycle exists if and only if we discover a "back edge" during graph traversal - an edge that connects a vertex to an already visited vertex (excluding the parent).

2. **Parent Tracking**: We need to track the parent of each vertex to avoid false positives. In an undirected graph, each edge appears twice in the adjacency list (once for each vertex), so we need to ensure that we're not detecting the edge we just came from as a cycle.

3. **Connected Components**: The graph might have multiple disconnected components, so we need to start BFS/DFS from each unvisited node.

### Applications

- Detecting deadlocks in systems
- Finding redundancies in networks
- Cycle detection in dependency graphs
- Circuit analysis in electrical engineering
