#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

// 110. Balanced Binary Tree

// link - https://leetcode.com/problems/balanced-binary-tree/description/

/*
Given a binary tree, determine if it is height-balanced.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
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

// Time Complexity: O(N²) - For each node, we calculate height which takes O(N)
// Space Complexity: O(H) - Height of the tree (recursion stack)
class SolutionBruteForce
{
  int height(TreeNode *root)
  {
    if (!root)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }

public:
  bool isBalanced(TreeNode *root)
  {
    if (!root)
      return true;
    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);
    bool c = abs(height(root->left) - height(root->right)) <= 1;
    return (l && r && c);
  }
};

// Time Complexity: O(N) - Single traversal of the tree
// Space Complexity: O(H) - Height of the tree (recursion stack)
class SolutionOptimised
{

  pair<bool, int> isValid(TreeNode *root)
  {
    if (!root)
    {
      return {true, 0};
    }
    pair<bool, int> l = isValid(root->left);
    pair<bool, int> r = isValid(root->right);
    bool diff = abs(l.second - r.second) <= 1;
    bool balanced = l.first && r.first && diff;

    int height = 1 + max(l.second, r.second);

    return {balanced, height};
  }

public:
  bool isBalanced(TreeNode *root)
  {
    if (!root)
      return true;
    return isValid(root).first;
  }
};

// Main function to test the solutions
int main()
{
  // Test case 1: [3,9,20,null,null,15,7] - should return true
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  cout << "Test case 1 [3,9,20,null,null,15,7]:" << endl;
  SolutionBruteForce sol1;
  SolutionOptimised sol2;
  cout << "Brute Force: " << (sol1.isBalanced(root1) ? "true" : "false") << endl;
  cout << "Optimized: " << (sol2.isBalanced(root1) ? "true" : "false") << endl;

  // Test case 2: [1,2,2,3,3,null,null,4,4] - should return false
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->left = new TreeNode(3);
  root2->left->right = new TreeNode(3);
  root2->left->left->left = new TreeNode(4);
  root2->left->left->right = new TreeNode(4);

  cout << "\nTest case 2 [1,2,2,3,3,null,null,4,4]:" << endl;
  cout << "Brute Force: " << (sol1.isBalanced(root2) ? "true" : "false") << endl;
  cout << "Optimized: " << (sol2.isBalanced(root2) ? "true" : "false") << endl;

  // Test case 3: [] (empty tree) - should return true
  TreeNode *root3 = nullptr;

  cout << "\nTest case 3 [] (empty tree):" << endl;
  cout << "Brute Force: " << (sol1.isBalanced(root3) ? "true" : "false") << endl;
  cout << "Optimized: " << (sol2.isBalanced(root3) ? "true" : "false") << endl;

  return 0;
}