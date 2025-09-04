# Day 132: Graph Traversal Algorithms - BFS and DFS

## Concepts Covered

- Breadth-First Search (BFS) traversal of graphs
- Depth-First Search (DFS) traversal of graphs
- Handling connected and disconnected graphs
- Implementation of graph traversals using adjacency lists

## Problems Solved

1. **BFS Traversal Implementation**: Implemented BFS traversal for both connected and disconnected graphs.
2. **GFG - BFS of Graph**: Solved the standard BFS traversal problem from GeeksforGeeks.
3. **GFG - DFS of Graph**: Solved the standard DFS traversal problem from GeeksforGeeks.

## Approach and Implementation

### BFS Traversal

1. **Data Structures Used**:

   - Adjacency List (using `unordered_map<T, list<T>>`)
   - Queue for BFS traversal
   - Visited map to track visited nodes

2. **Algorithm**:

   - Start from a given node and mark it as visited
   - Push the node into a queue
   - While the queue is not empty:
     - Dequeue a node and print it
     - Enqueue all unvisited adjacent nodes and mark them as visited

3. **Time Complexity**:

   - O(V + E) where V is the number of vertices and E is the number of edges

4. **Space Complexity**:
   - O(V) for the queue and visited array

### DFS Traversal

1. **Data Structures Used**:

   - Adjacency List (using vector of vectors)
   - Visited map to track visited nodes
   - Recursion stack (implicit)

2. **Algorithm**:

   - Start from a given node and mark it as visited
   - Print the node
   - Recursively visit all unvisited adjacent nodes

3. **Time Complexity**:

   - O(V + E) where V is the number of vertices and E is the number of edges

4. **Space Complexity**:
   - O(V) for the recursion stack and visited array

## Notes

### Breadth-First Search (BFS)

- Uses a queue data structure to explore nodes level by level
- Ideal for finding the shortest path in unweighted graphs
- Can identify all nodes at distance k from a starting node
- Works well for graphs with a large breadth

### Depth-First Search (DFS)

- Uses recursion or a stack to explore as far as possible along each branch
- Ideal for problems requiring backtracking
- Used for detecting cycles, topological sorting, and finding connected components
- Generally requires less memory than BFS for deep graphs

### Handling Disconnected Graphs

- For both BFS and DFS, we need to iterate through all vertices
- For each unvisited vertex, perform a BFS or DFS starting from that vertex
- This ensures all components of the graph are traversed

## Practice Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [Course Schedule](https://leetcode.com/problems/course-schedule/)
- [Clone Graph](https://leetcode.com/problems/clone-graph/)
- [Word Ladder](https://leetcode.com/problems/word-ladder/)
- [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)
