// 102. Binary Tree Level Order Traversal

// link - https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
#include <queue>
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

// Level Order Traversal using Queue with nullptr as level separator
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue<TreeNode *> q;
    vector<int> v;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
      TreeNode *temp = q.front();
      q.pop();
      if (temp)
      {
        v.push_back(temp->val);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
      else
      {
        ans.push_back(v);
        v.clear();
        if (!q.empty())
        {
          q.push(nullptr);
        }
      }
    }
    return ans;
  }
};

// Alternative Level Order Traversal using Queue with size tracking
// Time Complexity: O(n)
// Space Complexity: O(w) - where w is the maximum width of the tree
class SolutionAlternative
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      int levelSize = q.size();
      vector<int> currentLevel;

      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        currentLevel.push_back(node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      ans.push_back(currentLevel);
    }

    return ans;
  }
};