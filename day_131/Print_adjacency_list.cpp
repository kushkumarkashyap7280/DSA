/**
 * Print Adjacency List
 *
 * Problem: Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph.
 * Link: https://www.codingninjas.com/codestudio/problems/print-adjacency-list_630462
 *
 * Problem Statement:
 * Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph.
 * 0-based indexing is followed everywhere.
 *
 * Example 1:
 * Input:
 * V = 5, E = 7
 * edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
 *
 * Output:
 * [[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
 *
 * Example 2:
 * Input:
 * V = 4, E = 3
 * edges = [[0,3], [0,2], [2,1]]
 *
 * Output:
 * [[2,3], [2], [0,1], [0]]
 *
 * Approach:
 * 1. Create a graph data structure using the adjacency list representation.
 * 2. Add all the edges to the graph.
 * 3. Extract the adjacency list for each vertex and return them in the required format.
 *
 * Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
 * Space Complexity: O(V + E) for storing the adjacency list
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Graph class implementing adjacency list representation
 */
template <typename T>
struct Graph
{
  map<T, vector<T>> adjList;

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

/**
 * Solution class to solve the Print Adjacency List problem
 */
class Solution
{
public:
  /**
   * Function to return the adjacency list for each vertex
   *
   * @param V Number of vertices in the graph (0 to V-1)
   * @param edges Vector of pairs representing edges between vertices
   * @return Vector of vectors containing adjacency lists for each vertex
   */
  vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
  {
    // Initialize graph
    Graph<int> g;

    // Build graph by adding all edges
    for (auto &e : edges)
    {
      g.addEdge(e.first, e.second);
    }

    // Prepare adjacency list in the required format
    vector<vector<int>> ans(V); // V vertices from 0..V-1
    for (int i = 0; i < V; i++)
    {
      ans[i] = g.adjList[i]; // Fetch neighbors of node i
    }

    return ans;
  }
};