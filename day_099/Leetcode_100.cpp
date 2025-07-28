#include <iostream>
using namespace std;

// 100. Same Tree

// link - https://leetcode.com/problems/same-tree/description/

/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(min(N, M)) where N and M are the number of nodes in trees p and q
// Space Complexity: O(min(H1, H2)) where H1 and H2 are the heights of trees p and q
class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (!p && !q)
      return true;
    if ((p && !q) || (!p && q))
      return false;
    bool l = (isSameTree(p->left, q->left));
    bool r = (isSameTree(p->right, q->right));
    return ((p->val == q->val) && l && r);
  }
};

// Main function to test the solution
int main()
{
  Solution sol;

  // Test case 1: p = [1,2,3], q = [1,2,3] - should return true
  TreeNode *p1 = new TreeNode(1);
  p1->left = new TreeNode(2);
  p1->right = new TreeNode(3);

  TreeNode *q1 = new TreeNode(1);
  q1->left = new TreeNode(2);
  q1->right = new TreeNode(3);

  cout << "Test case 1 [1,2,3] vs [1,2,3]:" << endl;
  cout << "Result: " << (sol.isSameTree(p1, q1) ? "true" : "false") << endl;

  // Test case 2: p = [1,2], q = [1,null,2] - should return false
  TreeNode *p2 = new TreeNode(1);
  p2->left = new TreeNode(2);

  TreeNode *q2 = new TreeNode(1);
  q2->right = new TreeNode(2);

  cout << "\nTest case 2 [1,2] vs [1,null,2]:" << endl;
  cout << "Result: " << (sol.isSameTree(p2, q2) ? "true" : "false") << endl;

  // Test case 3: p = [1,2,1], q = [1,1,2] - should return false
  TreeNode *p3 = new TreeNode(1);
  p3->left = new TreeNode(2);
  p3->right = new TreeNode(1);

  TreeNode *q3 = new TreeNode(1);
  q3->left = new TreeNode(1);
  q3->right = new TreeNode(2);

  cout << "\nTest case 3 [1,2,1] vs [1,1,2]:" << endl;
  cout << "Result: " << (sol.isSameTree(p3, q3) ? "true" : "false") << endl;

  // Test case 4: Both trees are null - should return true
  cout << "\nTest case 4 [] vs [] (both null):" << endl;
  cout << "Result: " << (sol.isSameTree(nullptr, nullptr) ? "true" : "false") << endl;

  return 0;
}