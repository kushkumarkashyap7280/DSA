# Day 134: Cycle Detection in Directed Graphs

## Concepts Covered

- Cycle detection in directed graphs
- DFS-based approach with recursion stack tracking
- BFS-based approach (Kahn's algorithm) using topological sorting
- Applications of cycle detection in directed graphs

## What is a Cycle in a Directed Graph?

A cycle in a directed graph is a path that starts and ends at the same vertex, following the direction of edges. Unlike undirected graphs, the direction of edges matters in directed graphs, which adds complexity to cycle detection.

### Examples:

#### Directed Graph with a Cycle:

```
   ┌─→ 1
   │   ↓
0 ─┼─→ 2 ─→ 3
   │   ↑
   └───┘
```

This graph has a cycle: 0 → 2 → 0

#### Directed Graph without a Cycle (Directed Acyclic Graph or DAG):

```
   ┌─→ 1
   │   ↓
0 ─┼─→ 2 ─→ 3
   │
   └───────→ 4
```

This graph has no cycles.

## Approaches for Cycle Detection

### 1. DFS with Recursion Stack (Same Path) Tracking

This approach uses Depth-First Search with an additional array to track vertices in the current recursion stack:

1. Use a visited array to track overall visited nodes
2. Use a recursion stack array to track nodes in the current DFS path
3. If we encounter a node that's already in the recursion stack, we've found a cycle
4. If a node is visited but not in the recursion stack, it was processed in a different DFS path

**Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges
**Space Complexity**: O(V) for the visited array, recursion stack array, and call stack

### 2. BFS with Topological Sort (Kahn's Algorithm)

This approach uses the fact that a directed acyclic graph (DAG) can be topologically sorted, but a graph with a cycle cannot:

1. Calculate in-degree (number of incoming edges) for each vertex
2. Start with vertices having in-degree 0 (no incoming edges)
3. Process each vertex by removing it and decreasing the in-degree of its neighbors
4. If we can process all vertices, there's no cycle
5. If we can't process all vertices, there's a cycle

**Time Complexity**: O(V + E)
**Space Complexity**: O(V) for the queue and in-degree array

## Applications of Cycle Detection in Directed Graphs

1. **Deadlock Detection**: In operating systems, cycles in resource allocation graphs indicate potential deadlocks
2. **Dependency Resolution**: Package managers use topological sorting to resolve dependencies and detect circular dependencies
3. **Circuit Analysis**: Detecting feedback loops in electronic circuits
4. **Scheduling**: Task scheduling algorithms need to detect cycles to prevent infinite loops
5. **Compiler Optimization**: Detecting circular dependencies in program code

## Differences from Undirected Graph Cycle Detection

| Directed Graph                                               | Undirected Graph                       |
| ------------------------------------------------------------ | -------------------------------------- |
| Edge direction matters                                       | Edge direction doesn't matter          |
| Need recursion stack tracking in DFS                         | Simple visited array is sufficient     |
| Can use topological sort                                     | Topological sort not applicable        |
| Self-loops and parallel edges must be considered differently | Self-loops immediately indicate cycles |

## Implementation

Check the following files for detailed implementations:

1. `gfg_cycle_detection_in_directed_graph.cpp` - Implementations of both DFS and BFS approaches to detect cycles in directed graphs
2. `Leetcode_2360.cpp` - Finding the longest cycle in a directed graph where each node has at most one outgoing edge
