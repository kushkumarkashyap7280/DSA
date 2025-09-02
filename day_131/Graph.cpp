// =============== Graph ===============

// what is graph ?

// A graph is a collection of nodes (or vertices) and edges that connect pairs of nodes. Graphs can be used to represent various real-world systems, such as social networks, transportation networks, and communication networks. They can be directed or undirected, weighted or unweighted, and can have cycles or be acyclic.

// example :
/*
   A --- B
   |     |
   C --- D
*/

// what are the types of graphs ?

// 1. Directed Graph (Digraph): A graph in which edges have a direction, going from one vertex to another.

// example :
/*
   A --> B
   |     |
   v     v
   C --> D
*/
// 2. Undirected Graph: A graph in which edges have no direction, and the connection between vertices is bidirectional.

// example :
/*
   A --- B
   |     |
   C --- D
*/

// 3. Weighted Graph: A graph in which edges have weights (costs) associated with them, representing the cost of traversing the edge.

// example :
/*    1
   A --- B
   | 3   | 2
   C --- D
     4
*/
// 4. Unweighted Graph: A graph in which all edges have the same weight or no weight at all.

// example :

/*
   A --- B
   |     |
   C --- D
*/

// 5. Cyclic Graph: A graph that contains at least one cycle (a path that starts and ends at the same vertex).

// example :
/*
   A --- B
   |     |
   C --- D
*/

// 6. Acyclic Graph: A graph that does not contain any cycles.

// example :
/*
   A --- B --- F
   |      \
   |       E
   |
   C --- D
*/

// 7. Connected Graph: A graph in which there is a path between every pair of vertices.

// example :
/*
   A --- B
   |     |
   C --- D
*/
// 8. Disconnected Graph: A graph in which at least one pair of vertices is not connected by a path.

// example :
/*
   A --- B
   |     |
   C --- D
*/

/// what is a node ?

// A node (or vertex) is a fundamental part of a graph that represents an entity or a point in the graph. Nodes can store data and may have connections (edges) to other nodes. In a social network graph, for example, each user can be represented as a node, and the connections between users (friendships) can be represented as edges.

// example :
/*
   A
   |
   B
*/

// what is an edge ?

// An edge is a connection between two nodes (or vertices) in a graph. Edges can be directed or undirected, and they may have weights associated with them. In a social network graph, an edge could represent a friendship between two users, while in a transportation network, an edge could represent a road connecting two locations.

// example :
/*
   A --- B
   |     |
   C --- D
*/

// what is degree ?

// The degree of a node (or vertex) in a graph is the number of edges connected to it. In a directed graph, we can differentiate between in-degree (the number of incoming edges) and out-degree (the number of outgoing edges). The degree of a node is an important concept in graph theory and can provide insights into the structure and properties of the graph.

// example :
/*
   A --- B
   |     |
   C --- D
*/
// types of degree:
// 1. In-Degree: The number of incoming edges to a node.

// example :
/*          \
       --- node -->
            /
*/
// 2. Out-Degree: The number of outgoing edges from a node.

// example :
/*           /
       ---> node --
              \
*/
//  3. Total Degree: The total number of edges connected to a node (in-degree + out-degree).

// example :
/*          \/
       ---> node -->
            /\
*/

// what is path ?

// A path in a graph is a sequence of edges that connects a sequence of vertices. In other words, it is a way to traverse the graph from one node to another by following the edges. Paths can be simple (no repeated vertices) or can contain cycles (repeated vertices). The length of a path is typically measured by the number of edges it contains.

// example :
/*
   A --- B --- C
   |     |     |
   D --- E --- F
*/

// representation of a path in a graph
/*
   A --- B --- C
   |     |     |
   D --- E --- F
*/

// adjacency list representation of a graph
/*
   A: B, C
   B: A, D, E
   C: A, F
   D: B, E
   E: B, D, F
   F: C, E
*/

// adjacency matrix representation of a graph
/*    A B C D E F
   A: 0 1 1 0 0 0
   B: 1 0 0 1 1 0
   C: 1 0 0 0 0 1
   D: 0 1 0 0 1 0
   E: 0 1 0 1 0 1
   F: 0 0 1 0 1 0
*/

// ============  Implementation of Graph Data Structure ================

/**
 * Graph Data Structure Implementation
 *
 * This implementation uses an adjacency list representation using unordered_map and list.
 * It supports both directed and undirected graphs with templated node types.
 *
 * Time Complexity:
 * - Add Edge: O(1)
 * - Print Graph: O(V + E) where V is number of vertices and E is number of edges
 *
 * Space Complexity: O(V + E) for storing the adjacency list
 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
struct Graph
{
  // Adjacency list representation - each node maps to a list of its neighbors
  unordered_map<T, list<T>> adjList;

  /**
   * Adds an edge between two vertices in the graph
   *
   * @param u First vertex
   * @param v Second vertex
   * @param directed If true, adds a directed edge from u to v;
   *                 If false (default), adds an undirected edge (both directions)
   */
  void addEdge(T u, T v, bool directed = false)
  {
    adjList[u].push_back(v);
    if (!directed)
    {
      adjList[v].push_back(u);
    }
  }

  /**
   * Prints the adjacency list representation of the graph
   */
  void printGraph()
  {
    for (const auto &pair : adjList)
    {
      cout << pair.first << " -> ";
      for (const auto &neighbor : pair.second)
      {
        cout << neighbor << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  // Create an undirected graph with integer nodes
  Graph<int> g;

  // Add edges to the graph
  g.addEdge(1, 2);       // Undirected edge between 1 and 2
  g.addEdge(1, 3);       // Undirected edge between 1 and 3
  g.addEdge(2, 4);       // Undirected edge between 2 and 4
  g.addEdge(3, 4);       // Undirected edge between 3 and 4
  g.addEdge(4, 5, true); // Directed edge from 4 to 5

  // Display the graph structure
  cout << "Graph adjacency list:\n";
  g.printGraph();

  /**
   * Expected Output:
   *
   * Graph adjacency list:
   * 5 ->
   * 4 -> 2 3 5
   * 3 -> 1 4
   * 2 -> 1 4
   * 1 -> 2 3
   */

  return 0;
}