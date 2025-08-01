// 112. Path Sum

// link -https://leetcode.com/problems/path-sum/description/

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS Solution using Recursion
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(h) - where h is the height of the tree (recursion stack)
class Solution
{
  bool isPossible(TreeNode *root, int &targetSum, int sum, bool &found)
  {
    if (!root)
      return false;
    if (found)
      return true;
    if (!root->left && !root->right)
    {
      if ((sum + root->val) == targetSum)
      {
        found = true;
        return found;
      }
      return found;
    }
    bool left = isPossible(root->left, targetSum, sum + root->val, found);
    bool right = isPossible(root->right, targetSum, sum + root->val, found);

    return left || right;
  }

public:
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return false;
    bool found = false;
    found = isPossible(root, targetSum, 0, found);
    return found;
  }
};

// Helper function to create a binary tree from vector
TreeNode *createTree(vector<int> &values, int index = 0)
{
  if (index >= values.size() || values[index] == -1)
  {
    return nullptr;
  }

  TreeNode *root = new TreeNode(values[index]);
  root->left = createTree(values, 2 * index + 1);
  root->right = createTree(values, 2 * index + 2);
  return root;
}

// Helper function to print tree (inorder traversal)
void printTree(TreeNode *root)
{
  if (!root)
    return;
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
}

// Helper function to print all root-to-leaf paths with their sums
void printAllPaths(TreeNode *root, vector<int> &path)
{
  if (!root)
    return;

  path.push_back(root->val);

  if (!root->left && !root->right)
  {
    cout << "Path: ";
    int sum = 0;
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i];
      sum += path[i];
      if (i < path.size() - 1)
        cout << " -> ";
    }
    cout << " (Sum: " << sum << ")" << endl;
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
  cout << "=== LeetCode 112: Path Sum ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
  TreeNode *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path1;
  printAllPaths(root1, path1);

  int targetSum1 = 22;
  Solution sol1;
  bool result1 = sol1.hasPathSum(root1, targetSum1);
  cout << "Target Sum: " << targetSum1 << endl;
  cout << "Has Path Sum: " << (result1 ? "true" : "false") << endl;
  cout << "Expected: true" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {1, 2, 3};
  TreeNode *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path2;
  printAllPaths(root2, path2);

  int targetSum2 = 5;
  Solution sol2;
  bool result2 = sol2.hasPathSum(root2, targetSum2);
  cout << "Target Sum: " << targetSum2 << endl;
  cout << "Has Path Sum: " << (result2 ? "true" : "false") << endl;
  cout << "Expected: false" << endl
       << endl;

  // Test Case 3: Example 3 from problem (empty tree)
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {};
  TreeNode *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  int targetSum3 = 0;
  Solution sol3;
  bool result3 = sol3.hasPathSum(root3, targetSum3);
  cout << "Target Sum: " << targetSum3 << endl;
  cout << "Has Path Sum: " << (result3 ? "true" : "false") << endl;
  cout << "Expected: false" << endl
       << endl;

  // Test Case 4: Simple tree with valid path
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path4;
  printAllPaths(root4, path4);

  int targetSum4 = 7;
  Solution sol4;
  bool result4 = sol4.hasPathSum(root4, targetSum4);
  cout << "Target Sum: " << targetSum4 << endl;
  cout << "Has Path Sum: " << (result4 ? "true" : "false") << endl;
  cout << "Expected: true" << endl
       << endl;

  // Test Case 5: Single node
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {5};
  TreeNode *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  cout << "All Root-to-Leaf Paths:" << endl;
  vector<int> path5;
  printAllPaths(root5, path5);

  int targetSum5 = 5;
  Solution sol5;
  bool result5 = sol5.hasPathSum(root5, targetSum5);
  cout << "Target Sum: " << targetSum5 << endl;
  cout << "Has Path Sum: " << (result5 ? "true" : "false") << endl;
  cout << "Expected: true" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "DFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl;
  cout << "- Algorithm: DFS with sum tracking" << endl;
  cout << "- Key Insight: Track running sum and check at leaf nodes" << endl;
  cout << "- Strategy: Use recursion to explore all paths from root to leaves" << endl;

  return 0;
}
