// 104. Maximum Depth of Binary Tree

// link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
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

// Recursive Solution
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(h) - where h is the height of the tree (due to recursion stack)
//                  In worst case (skewed tree): O(n)
//                  In best case (balanced tree): O(log n)
class SolutionRecursive
{
public:
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

// Iterative Solution using Queue (Level Order Traversal)
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
      int s = q.size();
      while (s)
      {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
        s--;
      }
      depth++;
    }
    return depth;
  }
};

// Alternative Iterative Solution using Stack (DFS)
// Time Complexity: O(n)
// Space Complexity: O(h) - where h is the height of the tree
class SolutionDFS
{
public:
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    int maxDepth = 0;

    while (!st.empty())
    {
      TreeNode *node = st.top().first;
      int depth = st.top().second;
      st.pop();

      maxDepth = max(maxDepth, depth);

      if (node->right)
        st.push({node->right, depth + 1});
      if (node->left)
        st.push({node->left, depth + 1});
    }

    return maxDepth;
  }
};

// Helper function to create a binary tree from array
TreeNode *createTree(vector<int> &arr, int index)
{
  if (index >= arr.size() || arr[index] == -1)
    return nullptr;

  TreeNode *root = new TreeNode(arr[index]);
  root->left = createTree(arr, 2 * index + 1);
  root->right = createTree(arr, 2 * index + 2);
  return root;
}

int main()
{
  Solution solution;
  SolutionRecursive solutionRecursive;
  SolutionDFS solutionDFS;

  // Test Case 1: [3,9,20,null,null,15,7]
  cout << "Test Case 1: [3,9,20,null,null,15,7]" << endl;
  vector<int> arr1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root1 = createTree(arr1, 0);
  cout << "Expected: 3" << endl;
  cout << "Iterative (BFS): " << solution.maxDepth(root1) << endl;
  cout << "Recursive: " << solutionRecursive.maxDepth(root1) << endl;
  cout << "DFS: " << solutionDFS.maxDepth(root1) << endl;
  cout << endl;

  // Test Case 2: [1,null,2]
  cout << "Test Case 2: [1,null,2]" << endl;
  vector<int> arr2 = {1, -1, 2};
  TreeNode *root2 = createTree(arr2, 0);
  cout << "Expected: 2" << endl;
  cout << "Iterative (BFS): " << solution.maxDepth(root2) << endl;
  cout << "Recursive: " << solutionRecursive.maxDepth(root2) << endl;
  cout << "DFS: " << solutionDFS.maxDepth(root2) << endl;
  cout << endl;

  // Test Case 3: []
  cout << "Test Case 3: []" << endl;
  TreeNode *root3 = nullptr;
  cout << "Expected: 0" << endl;
  cout << "Iterative (BFS): " << solution.maxDepth(root3) << endl;
  cout << "Recursive: " << solutionRecursive.maxDepth(root3) << endl;
  cout << "DFS: " << solutionDFS.maxDepth(root3) << endl;
  cout << endl;

  return 0;
}