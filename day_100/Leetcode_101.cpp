// 101. Symmetric Tree

// link -https://leetcode.com/problems/symmetric-tree/description/

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/

#include <iostream>
#include <queue>
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
  bool isMirror(TreeNode *l, TreeNode *r)
  {
    if (!l && !r)
      return true;
    if (!l || !r)
      return false;

    return (l->val == r->val) &&
           (isMirror(l->left, r->right)) &&
           (isMirror(l->right, r->left));
  }
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;
    return isMirror(root->left, root->right);
  }
};

// Iterative Solution using Queue
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class SolutionIterative
{
public:
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() && !q2.empty())
    {
      TreeNode *temp1 = q1.front();
      q1.pop();
      TreeNode *temp2 = q2.front();
      q2.pop();

      if (!temp1 && !temp2)
        continue;
      if ((!temp1 || !temp2) || (temp1->val != temp2->val))
        return false;

      q1.push(temp1->left);
      q2.push(temp2->right);

      q1.push(temp1->right);
      q2.push(temp2->left);
    }
    return true;
  }
};

// Alternative Iterative Solution using Stack
// Time Complexity: O(n)
// Space Complexity: O(h) - where h is the height of the tree
class SolutionIterativeStack
{
public:
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;

    stack<TreeNode *> s1, s2;
    s1.push(root->left);
    s2.push(root->right);

    while (!s1.empty() && !s2.empty())
    {
      TreeNode *left = s1.top();
      s1.pop();
      TreeNode *right = s2.top();
      s2.pop();

      if (!left && !right)
        continue;
      if (!left || !right || left->val != right->val)
        return false;

      s1.push(left->left);
      s1.push(left->right);
      s2.push(right->right);
      s2.push(right->left);
    }

    return s1.empty() && s2.empty();
  }
};