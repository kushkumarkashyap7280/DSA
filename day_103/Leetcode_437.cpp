// 437. Path Sum III

// link - https://leetcode.com/problems/path-sum-iii/description/

/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).



Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3


Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
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

// DFS Solution using Recursion with Path Tracking
// Time Complexity: O(n²) - where n is the number of nodes (for each node, we check all paths ending at it)
// Space Complexity: O(h) - where h is the height of the tree (recursion stack)
class Solution
{
  void solve(TreeNode *root, int &targetSum, int &count, vector<int> &path)
  {
    if (!root)
      return;
    path.push_back(root->val);
    solve(root->left, targetSum, count, path);
    solve(root->right, targetSum, count, path);

    long long sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
      sum += path[i];
      if (sum == targetSum)
        count++;
    }
    path.pop_back();
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    if (!root)
      return 0;
    vector<int> path;
    int count = 0;
    solve(root, targetSum, count, path);
    return count;
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

// Helper function to print all possible paths with their sums
void printAllPaths(TreeNode *root, vector<int> &path)
{
  if (!root)
    return;

  path.push_back(root->val);

  // Print all subpaths ending at current node
  cout << "Paths ending at " << root->val << ":" << endl;
  long long sum = 0;
  for (int i = path.size() - 1; i >= 0; i--)
  {
    sum += path[i];
    cout << "  ";
    for (int j = i; j < path.size(); j++)
    {
      cout << path[j];
      if (j < path.size() - 1)
        cout << " -> ";
    }
    cout << " (Sum: " << sum << ")" << endl;
  }

  printAllPaths(root->left, path);
  printAllPaths(root->right, path);

  path.pop_back();
}

int main()
{
  cout << "=== LeetCode 437: Path Sum III ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
  TreeNode *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  cout << "All Possible Paths:" << endl;
  vector<int> path1;
  printAllPaths(root1, path1);

  int targetSum1 = 8;
  Solution sol1;
  int result1 = sol1.pathSum(root1, targetSum1);
  cout << "Target Sum: " << targetSum1 << endl;
  cout << "Number of Paths: " << result1 << endl;
  cout << "Expected: 3" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
  TreeNode *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  cout << "All Possible Paths:" << endl;
  vector<int> path2;
  printAllPaths(root2, path2);

  int targetSum2 = 22;
  Solution sol2;
  int result2 = sol2.pathSum(root2, targetSum2);
  cout << "Target Sum: " << targetSum2 << endl;
  cout << "Number of Paths: " << result2 << endl;
  cout << "Expected: 3" << endl
       << endl;

  // Test Case 3: Simple tree
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  cout << "All Possible Paths:" << endl;
  vector<int> path3;
  printAllPaths(root3, path3);

  int targetSum3 = 7;
  Solution sol3;
  int result3 = sol3.pathSum(root3, targetSum3);
  cout << "Target Sum: " << targetSum3 << endl;
  cout << "Number of Paths: " << result3 << endl;
  cout << "Expected: 2" << endl
       << endl;

  // Test Case 4: Single node
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {5};
  TreeNode *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  cout << "All Possible Paths:" << endl;
  vector<int> path4;
  printAllPaths(root4, path4);

  int targetSum4 = 5;
  Solution sol4;
  int result4 = sol4.pathSum(root4, targetSum4);
  cout << "Target Sum: " << targetSum4 << endl;
  cout << "Number of Paths: " << result4 << endl;
  cout << "Expected: 1" << endl
       << endl;

  // Test Case 5: Empty tree
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {};
  TreeNode *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  int targetSum5 = 0;
  Solution sol5;
  int result5 = sol5.pathSum(root5, targetSum5);
  cout << "Target Sum: " << targetSum5 << endl;
  cout << "Number of Paths: " << result5 << endl;
  cout << "Expected: 0" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "DFS Solution with Path Tracking:" << endl;
  cout << "- Time Complexity: O(n²) - for each node, check all paths ending at it" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl;
  cout << "- Algorithm: DFS with path tracking and sum calculation" << endl;
  cout << "- Key Insight: Check all possible subpaths ending at each node" << endl;
  cout << "- Strategy: Use recursion to explore all nodes and calculate sums for all subpaths" << endl;

  return 0;
}