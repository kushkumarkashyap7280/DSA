# Day 135: Topological Sort

Today's focus is on the Topological Sort algorithm, which is used to linearly order the vertices of a Directed Acyclic Graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.

## Problem Covered

### [Topological Sort](https://www.geeksforgeeks.org/problems/topological-sort/1) (GeeksforGeeks - Medium)

**Problem Statement:**
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, find a topological sorting of the vertices.

**Approaches Implemented:**

1. **DFS-based Topological Sort**:

   - Use depth-first search to explore all vertices.
   - Once all neighbors of a vertex are processed, add the vertex to a stack.
   - After all vertices are processed, pop elements from the stack to get topological order.
   - Time Complexity: O(V + E)
   - Space Complexity: O(V)

2. **BFS-based Topological Sort (Kahn's Algorithm)**:
   - Calculate in-degree for each vertex.
   - Start with vertices having in-degree 0.
   - Process each vertex, reduce in-degree of neighbors, and add to queue when in-degree becomes 0.
   - If all vertices are not included in the result, the graph has a cycle.
   - Time Complexity: O(V + E)
   - Space Complexity: O(V)

## Key Insights

1. Topological sorting is only possible for Directed Acyclic Graphs (DAGs).
2. There can be multiple valid topological orderings for a single graph.
3. Kahn's algorithm can detect cycles in the graph (if one exists, not all vertices will be included in the result).
4. The DFS approach builds the result in reverse order, which is why we use a stack.

## Example

Consider a graph with edges: (3,0), (1,0), (2,0)

Visual representation:

```
3 → 0 ← 1
    ↑
    2
```

Valid topological sorts include:

- [3, 1, 2, 0]
- [3, 2, 1, 0]
- [1, 3, 2, 0]
- [1, 2, 3, 0]
- [2, 3, 1, 0]
- [2, 1, 3, 0]

## Applications

1. Task scheduling (dependencies between tasks)
2. Build systems (determining order of compilation)
3. Course prerequisites in academic planning
4. Package management in software development (resolving dependencies)

## Code Implementation

Check out the full implementation with test cases in [gfg_topological_sort.cpp](./gfg_topological_sort.cpp).
