// Sum of nodes on the longest path

// link - https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

Examples:

Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]

Output: 13
Explanation:

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Input: root[] = [1, 2, 3, 4, 5, 6, 7]

Output: 11
Explanation:

The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

Output: 19
Explanation:

The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104
*/

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

  Node(int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

// DFS Solution using Recursion
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(h) - where h is the height of the tree (recursion stack)
class Solution
{

  void solve(Node *root, int &sum, int &maxDepth, int currDepth, int currSum)
  {
    if (!root)
      return;
    currSum += root->data;
    if (!root->left && !root->right)
    {
      if (maxDepth < currDepth)
      {
        maxDepth = currDepth;
        sum = currSum;
        return;
      }
      else if (currDepth == maxDepth)
      {
        sum = max(sum, currSum); // handle equal depth
      }
    }
    solve(root->left, sum, maxDepth, currDepth + 1, currSum);
    solve(root->right, sum, maxDepth, currDepth + 1, currSum);
  }

public:
  int sumOfLongRootToLeafPath(Node *root)
  {
    if (!root)
      return 0;
    int sum = 0;
    int maxDepth = -1;
    solve(root, sum, maxDepth, 0, 0);

    return sum;
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

// Helper function to print all root-to-leaf paths
void printAllPaths(Node *root, vector<int> &path)
{
  if (!root)
    return;

  path.push_back(root->data);

  if (!root->left && !root->right)
  {
    cout << "Path: ";
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i];
      if (i < path.size() - 1)
        cout << " -> ";
    }
    cout << " (Length: " << path.size() << ", Sum: ";
    int sum = 0;
    for (int val : path)
      sum += val;
    cout << sum << ")" << endl;
  }
  else
  {
    printAllPaths(root->left, path);
    printAllPaths(root->right, path);
  }

  path.pop_back();
}

int main()
{
  cout << "=== Sum of Nodes on the Longest Path ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {4, 2, 5, 7, 1, 2, 3, -1, -1, 6, -1};
  Node *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path1;
  printAllPaths(root1, path1);

  Solution sol1;
  int result1 = sol1.sumOfLongRootToLeafPath(root1);
  cout << "Longest Path Sum: " << result1 << endl;
  cout << "Expected: 13" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {1, 2, 3, 4, 5, 6, 7};
  Node *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path2;
  printAllPaths(root2, path2);

  Solution sol2;
  int result2 = sol2.sumOfLongRootToLeafPath(root2);
  cout << "Longest Path Sum: " << result2 << endl;
  cout << "Expected: 11" << endl
       << endl;

  // Test Case 3: Example 3 from problem
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {10, 5, 15, 3, 7, -1, 20, 1};
  Node *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path3;
  printAllPaths(root3, path3);

  Solution sol3;
  int result3 = sol3.sumOfLongRootToLeafPath(root3);
  cout << "Longest Path Sum: " << result3 << endl;
  cout << "Expected: 19" << endl
       << endl;

  // Test Case 4: Single node
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {5};
  Node *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path4;
  printAllPaths(root4, path4);

  Solution sol4;
  int result4 = sol4.sumOfLongRootToLeafPath(root4);
  cout << "Longest Path Sum: " << result4 << endl;
  cout << "Expected: 5" << endl
       << endl;

  // Test Case 5: Left skewed tree
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {1, 2, -1, 3, -1, -1, -1, 4};
  Node *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path5;
  printAllPaths(root5, path5);

  Solution sol5;
  int result5 = sol5.sumOfLongRootToLeafPath(root5);
  cout << "Longest Path Sum: " << result5 << endl;
  cout << "Expected: 10" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "DFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl;
  cout << "- Algorithm: DFS with depth and sum tracking" << endl;
  cout << "- Key Insight: Track both depth and sum, prefer longer paths, then higher sums" << endl;
  cout << "- Strategy: Use recursion to explore all paths from root to leaves" << endl;

  return 0;
}