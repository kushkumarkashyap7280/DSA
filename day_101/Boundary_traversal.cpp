// Tree Boundary Traversal

// link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:

As the root doesn't have a right subtree, the right boundary is not included in the traversal.
Input: root[] = [1, N, 2, N, 3, N, 4, N, N]
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// Boundary Traversal of Binary Tree
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(h) - where h is the height of the tree (due to recursion stack)
//                  In worst case (skewed tree): O(n)
//                  In best case (balanced tree): O(log n)
class Solution
{
public:
  // Left boundary traversal (excluding leaf nodes)
  void left(Node *root, vector<int> &v)
  {
    if (!root || (!root->left && !root->right))
      return;
    v.push_back(root->data);
    if (root->left)
      left(root->left, v);
    else
      left(root->right, v);
  }

  // Leaf nodes traversal (inorder to get left-to-right order)
  void leafs(Node *root, vector<int> &v)
  {
    if (!root)
      return;
    if (!root->left && !root->right)
    {
      v.push_back(root->data);
      return;
    }
    leafs(root->left, v);
    leafs(root->right, v);
  }

  // Right boundary traversal (excluding leaf nodes, in reverse order)
  void right(Node *root, vector<int> &v)
  {
    if (!root || (!root->left && !root->right))
      return;
    if (root->right)
      right(root->right, v);
    else
      right(root->left, v);
    v.push_back(root->data);
  }

  vector<int> boundaryTraversal(Node *root)
  {
    vector<int> v;
    if (!root)
      return v;
    v.push_back(root->data);
    if (!root->left && !root->right)
      return v;

    // Left boundary
    left(root->left, v);

    // Leaf nodes
    leafs(root, v);

    // Right boundary
    right(root->right, v);

    return v;
  }
};

// Alternative Solution using Single Traversal
// Time Complexity: O(n)
// Space Complexity: O(h)
class SolutionAlternative
{
public:
  void boundaryTraversalUtil(Node *root, vector<int> &left, vector<int> &leaves, vector<int> &right, bool isLeft, bool isRight)
  {
    if (!root)
      return;

    // Add to left boundary
    if (isLeft)
    {
      left.push_back(root->data);
    }
    // Add to right boundary (will be reversed later)
    else if (isRight && !root->left && !root->right)
    {
      // Skip leaf nodes for right boundary
    }
    else if (isRight)
    {
      right.push_back(root->data);
    }
    // Add leaf nodes
    else if (!root->left && !root->right)
    {
      leaves.push_back(root->data);
    }

    boundaryTraversalUtil(root->left, left, leaves, right, isLeft, false);
    boundaryTraversalUtil(root->right, left, leaves, right, false, isRight);
  }

  vector<int> boundaryTraversal(Node *root)
  {
    if (!root)
      return {};

    vector<int> left, leaves, right;

    // Handle root separately
    left.push_back(root->data);

    // Traverse left boundary
    boundaryTraversalUtil(root->left, left, leaves, right, true, false);

    // Traverse right boundary
    boundaryTraversalUtil(root->right, left, leaves, right, false, true);

    // Reverse right boundary
    reverse(right.begin(), right.end());

    // Combine all parts
    vector<int> result = left;
    result.insert(result.end(), leaves.begin(), leaves.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
  }
};

// Helper function to create a binary tree from array
Node *createTree(vector<int> &arr, int index)
{
  if (index >= arr.size() || arr[index] == -1)
    return nullptr;

  Node *root = new Node(arr[index]);
  root->left = createTree(arr, 2 * index + 1);
  root->right = createTree(arr, 2 * index + 2);
  return root;
}

// Helper function to print the result
void printResult(vector<int> &result)
{
  cout << "[";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i];
    if (i < result.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main()
{
  Solution solution;
  SolutionAlternative solutionAlt;

  // Test Case 1: [1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1]
  cout << "Test Case 1: [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]" << endl;
  vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1};
  Node *root1 = createTree(arr1, 0);
  vector<int> result1 = solution.boundaryTraversal(root1);
  cout << "Expected: [1, 2, 4, 8, 9, 6, 7, 3]" << endl;
  cout << "Output: ";
  printResult(result1);
  cout << endl;

  // Test Case 2: [1, 2, -1, 4, 9, 6, 5, -1, 3, -1, -1, -1, -1, 7, 8]
  cout << "Test Case 2: [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N, 7, 8]" << endl;
  vector<int> arr2 = {1, 2, -1, 4, 9, 6, 5, -1, 3, -1, -1, -1, -1, 7, 8};
  Node *root2 = createTree(arr2, 0);
  vector<int> result2 = solution.boundaryTraversal(root2);
  cout << "Expected: [1, 2, 4, 6, 5, 7, 8]" << endl;
  cout << "Output: ";
  printResult(result2);
  cout << endl;

  // Test Case 3: [1, -1, 2, -1, 3, -1, 4, -1, -1]
  cout << "Test Case 3: [1, N, 2, N, 3, N, 4, N, N]" << endl;
  vector<int> arr3 = {1, -1, 2, -1, 3, -1, 4, -1, -1};
  Node *root3 = createTree(arr3, 0);
  vector<int> result3 = solution.boundaryTraversal(root3);
  cout << "Expected: [1, 4, 3, 2]" << endl;
  cout << "Output: ";
  printResult(result3);
  cout << endl;

  // Test Alternative Solution
  cout << "Alternative Solution Test:" << endl;
  vector<int> resultAlt = solutionAlt.boundaryTraversal(root1);
  cout << "Output: ";
  printResult(resultAlt);
  cout << endl;

  return 0;
}