// Height of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

/*
Given a binary tree, find its height.

The height of a tree is defined as the number of edges on the longest path from the root to a leaf node.
A leaf node is a node that does not have any children.

Examples:

Input: root[] = [12, 8, 18, 5, 11]
Output: 2
Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.

Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]
Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edges.

Constraints:
1 <= number of nodes <= 10^5
0 <= node->data <= 10^5
*/

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Binary Tree Node Structure
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = nullptr;
  }
};

class Solution
{
public:
  // Method 1: Recursive approach to find height
  // Time Complexity: O(n) where n is the number of nodes
  // Space Complexity: O(h) where h is the height of the tree (recursion stack)
  int heightRecursive(Node *node)
  {
    if (!node)
      return -1; // Return -1 for null nodes (edges count)
    return 1 + max(heightRecursive(node->left), heightRecursive(node->right));
  }

  // Method 2: Iterative approach using level order traversal
  // Time Complexity: O(n) where n is the number of nodes
  // Space Complexity: O(w) where w is the maximum width of the tree
  int height(Node *node)
  {
    if (!node)
      return 0;

    int count = 0;
    queue<Node *> q;
    q.push(node);
    q.push(nullptr);

    while (!q.empty())
    {
      Node *temp = q.front();
      q.pop();

      if (temp)
      {
        // Add children to queue
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
      else
      {
        count++;
        if (!q.empty())
        {
          q.push(nullptr);
        }
      }
    }
    return count - 1; // Subtract 1 to get edge count instead of node count
  }

  // Method 3: Alternative recursive approach (node count instead of edge count)
  // Returns the number of nodes in the longest path (not edges)
  int heightNodes(Node *node)
  {
    if (!node)
      return 0;
    return 1 + max(heightNodes(node->left), heightNodes(node->right));
  }

  // Method 4: Iterative approach using stack (DFS)
  // Time Complexity: O(n)
  // Space Complexity: O(h) where h is the height of the tree
  int heightIterativeDFS(Node *node)
  {
    if (!node)
      return -1;

    int maxHeight = -1;
    stack<pair<Node *, int>> st; // {node, current_height}
    st.push({node, 0});

    while (!st.empty())
    {
      auto [current, currentHeight] = st.top();
      st.pop();

      maxHeight = max(maxHeight, currentHeight);

      if (current->right)
      {
        st.push({current->right, currentHeight + 1});
      }
      if (current->left)
      {
        st.push({current->left, currentHeight + 1});
      }
    }

    return maxHeight;
  }
};

// Test function to create a sample tree
Node *createSampleTree()
{
  Node *root = new Node(12);
  root->left = new Node(8);
  root->right = new Node(18);
  root->left->left = new Node(5);
  root->left->right = new Node(11);
  return root;
}

// Test function to create a deeper tree
Node *createDeepTree()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->right = new Node(5);
  root->left->left->left = new Node(6);
  root->left->left->right = new Node(7);
  return root;
}

// Main function for testing
int main()
{
  Solution solution;

  // Test with sample tree
  Node *root1 = createSampleTree();
  cout << "Sample Tree Height:" << endl;
  cout << "Recursive approach: " << solution.heightRecursive(root1) << endl;
  cout << "Iterative approach: " << solution.height(root1) << endl;
  cout << "Node count approach: " << solution.heightNodes(root1) << endl;
  cout << "DFS iterative approach: " << solution.heightIterativeDFS(root1) << endl;

  cout << "\n";

  // Test with deeper tree
  Node *root2 = createDeepTree();
  cout << "Deep Tree Height:" << endl;
  cout << "Recursive approach: " << solution.heightRecursive(root2) << endl;
  cout << "Iterative approach: " << solution.height(root2) << endl;
  cout << "Node count approach: " << solution.heightNodes(root2) << endl;
  cout << "DFS iterative approach: " << solution.heightIterativeDFS(root2) << endl;

  return 0;
}

/*
Expected Output:
Sample Tree Height:
Recursive approach: 2
Iterative approach: 2
Node count approach: 3
DFS iterative approach: 2

Deep Tree Height:
Recursive approach: 3
Iterative approach: 3
Node count approach: 4
DFS iterative approach: 3
*/