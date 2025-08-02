// Maximum sum of Non-adjacent nodes

// link -https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105
*/

// Node Structure
struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
  pair<int, int> solve(Node *root)
  {
    if (!root)
      return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;

    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first, right.second);
    return ans;
  }

public:
  // Function to return the maximum sum of non-adjacent nodes.
  int getMaxSum(Node *root)
  {
    if (!root)
      return 0;

    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
  }
};

// Helper function to create a binary tree from vector
Node *createTree(vector<int> &values, int index = 0)
{
  if (index >= values.size() || values[index] == -1)
  {
    return nullptr;
  }

  Node *root = new Node(values[index]);
  root->left = createTree(values, 2 * index + 1);
  root->right = createTree(values, 2 * index + 2);
  return root;
}

// Helper function to print tree (inorder traversal)
void printTree(Node *root)
{
  if (!root)
    return;
  printTree(root->left);
  cout << root->data << " ";
  printTree(root->right);
}

// Helper function to visualize tree structure
void printTreeStructure(Node *root, string prefix = "", bool isLeft = true)
{
  if (!root)
    return;

  cout << prefix;
  cout << (isLeft ? "├── " : "└── ");
  cout << root->data << endl;

  printTreeStructure(root->left, prefix + (isLeft ? "│   " : "    "), true);
  printTreeStructure(root->right, prefix + (isLeft ? "│   " : "    "), false);
}

// Helper function to delete tree (cleanup)
void deleteTree(Node *root)
{
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main()
{
  cout << "=== Maximum Sum of Non-adjacent Nodes ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {11, 1, 2};
  Node *root1 = createTree(values1);

  cout << "Tree structure:" << endl;
  printTreeStructure(root1);
  cout << "Inorder traversal: ";
  printTree(root1);
  cout << endl;

  Solution sol1;
  int result1 = sol1.getMaxSum(root1);
  cout << "Maximum sum of non-adjacent nodes: " << result1 << endl;
  cout << "Expected: 11" << endl
       << endl;

  deleteTree(root1);

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {1, 2, 3, 4, -1, 5, 6};
  Node *root2 = createTree(values2);

  cout << "Tree structure:" << endl;
  printTreeStructure(root2);
  cout << "Inorder traversal: ";
  printTree(root2);
  cout << endl;

  Solution sol2;
  int result2 = sol2.getMaxSum(root2);
  cout << "Maximum sum of non-adjacent nodes: " << result2 << endl;
  cout << "Expected: 16" << endl
       << endl;

  deleteTree(root2);

  // Test Case 3: Simple tree with 3 nodes
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {5, 3, 7};
  Node *root3 = createTree(values3);

  cout << "Tree structure:" << endl;
  printTreeStructure(root3);
  cout << "Inorder traversal: ";
  printTree(root3);
  cout << endl;

  Solution sol3;
  int result3 = sol3.getMaxSum(root3);
  cout << "Maximum sum of non-adjacent nodes: " << result3 << endl;
  cout << "Expected: 12 (5 + 7)" << endl
       << endl;

  deleteTree(root3);

  // Test Case 4: Larger tree
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {10, 20, 30, 40, 50, 60, 70};
  Node *root4 = createTree(values4);

  cout << "Tree structure:" << endl;
  printTreeStructure(root4);
  cout << "Inorder traversal: ";
  printTree(root4);
  cout << endl;

  Solution sol4;
  int result4 = sol4.getMaxSum(root4);
  cout << "Maximum sum of non-adjacent nodes: " << result4 << endl;
  cout << "Expected: 160 (10 + 40 + 50 + 60)" << endl
       << endl;

  deleteTree(root4);

  // Test Case 5: Tree with negative values
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {5, -2, 3, 4, -1, 6, -3};
  Node *root5 = createTree(values5);

  cout << "Tree structure:" << endl;
  printTreeStructure(root5);
  cout << "Inorder traversal: ";
  printTree(root5);
  cout << endl;

  Solution sol5;
  int result5 = sol5.getMaxSum(root5);
  cout << "Maximum sum of non-adjacent nodes: " << result5 << endl;
  cout << "Expected: 15 (5 + 4 + 6)" << endl
       << endl;

  deleteTree(root5);

  // Test Case 6: Single node
  cout << "Test Case 6:" << endl;
  vector<int> values6 = {8};
  Node *root6 = createTree(values6);

  cout << "Tree structure:" << endl;
  printTreeStructure(root6);
  cout << "Inorder traversal: ";
  printTree(root6);
  cout << endl;

  Solution sol6;
  int result6 = sol6.getMaxSum(root6);
  cout << "Maximum sum of non-adjacent nodes: " << result6 << endl;
  cout << "Expected: 8" << endl
       << endl;

  deleteTree(root6);

  // Test Case 7: Empty tree
  cout << "Test Case 7:" << endl;
  Node *root7 = nullptr;

  cout << "Tree structure: Empty tree" << endl;

  Solution sol7;
  int result7 = sol7.getMaxSum(root7);
  cout << "Maximum sum of non-adjacent nodes: " << result7 << endl;
  cout << "Expected: 0" << endl
       << endl;

  cout << "=== Algorithm Explanation ===" << endl;
  cout << "Dynamic Programming Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl;
  cout << "- Algorithm: Bottom-up dynamic programming" << endl;
  cout << "- Key Insight: For each node, we have two choices:" << endl;
  cout << "  1. Include current node + exclude children" << endl;
  cout << "  2. Exclude current node + include best of children" << endl;
  cout << "- Strategy: Use pair<int,int> where:" << endl;
  cout << "  - first: maximum sum including current node" << endl;
  cout << "  - second: maximum sum excluding current node" << endl;
  cout << "- Formula:" << endl;
  cout << "  include = node->data + left.exclude + right.exclude" << endl;
  cout << "  exclude = max(left.include, left.exclude) + max(right.include, right.exclude)" << endl;

  return 0;
}