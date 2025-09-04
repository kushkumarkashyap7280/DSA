/**
 * Breadth-First Search (BFS) Traversal of a Graph
 *
 * This implementation demonstrates:
 * 1. Creating a graph using adjacency list representation
 * 2. BFS traversal starting from a specific node
 * 3. BFS traversal for disconnected graphs (handling all components)
 *
 * Time Complexity: O(V + E) where V is number of vertices and E is number of edges
 * Space Complexity: O(V) for queue and visited map
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

/**
 * Graph class implementing adjacency list representation with BFS traversal
 */
template <typename T>
struct graph
{
  // Adjacency list: maps each node to its list of neighbors
  unordered_map<T, list<T>> adj;

  /**
   * Adds an edge between two nodes in the graph
   *
   * @param node First node
   * @param edgeNode Second node
   * @param dir If true, adds a directed edge from node to edgeNode
   *            If false (default), adds an undirected edge (both directions)
   */
  void addEdge(T node, T edgeNode, bool dir = true)
  {
    adj[node].push_back(edgeNode);

    if (!dir)
    {
      adj[edgeNode].push_back(node);
    }
  }

  /**
   * Prints the adjacency list representation of the graph
   */
  void printGraph()
  {
    for (auto &node : adj)
    {
      cout << node.first << "  : ";

      for (auto i : node.second)
      {
        cout << i << " , ";
      }
      cout << endl;
    }
  }

  /**
   * Performs BFS traversal starting from a specific node
   *
   * @param node Starting node for BFS traversal
   */
  void bfs(T node)
  {
    // Check if node exists in graph
    if (adj.find(node) == adj.end())
    {
      cout << "Node not present in graph\n";
      return;
    }

    // Initialize visited map
    unordered_map<T, bool> isVisited;
    for (auto &node : adj)
      isVisited.insert({node.first, false});

    // Initialize queue with starting node
    queue<T> q;
    q.push(node);
    isVisited[node] = true;

    // BFS traversal
    while (!q.empty())
    {
      int s = q.size(); // Process nodes level by level

      while (s--)
      {
        T curr = q.front();
        q.pop();

        cout << curr << " , ";

        // Process all neighbors
        for (auto &nbr : adj[curr])
        {
          if (!isVisited[nbr])
          {
            q.push(nbr);
            isVisited[nbr] = true;
          }
        }
      }
      cout << endl; // New line after each level
    }
  }

  /**
   * Performs BFS traversal for disconnected graphs
   * This ensures all components of the graph are traversed
   */
  void bfsDisconnected()
  {
    // Initialize visited map
    unordered_map<T, bool> isVisited;
    for (auto &node : adj)
      isVisited.insert({node.first, false});

    // Iterate through all nodes to handle disconnected components
    for (auto &node : adj)
    {
      if (!isVisited[node.first])
      {
        // BFS for current component
        queue<T> q;
        q.push(node.first);
        isVisited[node.first] = true;

        while (!q.empty())
        {
          int s = q.size();

          while (s--)
          {
            T curr = q.front();
            q.pop();

            cout << curr << " , ";

            // Process all neighbors
            for (auto &nbr : adj[curr])
            {
              if (!isVisited[nbr])
              {
                q.push(nbr);
                isVisited[nbr] = true;
              }
            }
          }
          cout << endl; // New line after each level
        }
      }
    }
  }
};
}
;

/**
 * Main function to demonstrate BFS traversal on different graph structures
 */
int main()
{
  cout << "========== BFS Traversal of a Connected Graph ==========" << endl;
  graph<int> g1;

  // Create a connected undirected graph
  g1.addEdge(0, 1, false);
  g1.addEdge(0, 2, false);
  g1.addEdge(1, 3, false);
  g1.addEdge(2, 3, false);

  cout << "Graph structure (adjacency list):" << endl;
  g1.printGraph();

  cout << "\nBFS Traversal starting from node 0:" << endl;
  g1.bfs(0);

  cout << "\n========== BFS Traversal of a Disconnected Graph ==========" << endl;
  graph<int> g2;

  // Create a disconnected undirected graph with two components
  g2.addEdge(0, 1, false);
  g2.addEdge(0, 2, false);
  g2.addEdge(3, 4, false); // separate component

  cout << "Graph structure (adjacency list):" << endl;
  g2.printGraph();

  cout << "\nBFS Traversal (handling all components):" << endl;
  g2.bfsDisconnected();

  return 0;
}
