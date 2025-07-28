#include <iostream>
#include <algorithm>
using namespace std;

// 543. Diameter of Binary Tree

// link - https://leetcode.com/problems/diameter-of-binary-tree/description/

/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1


Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
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

// time complexity  - O(N*N);
class SolutionBruteForce
{
public:
  int height(TreeNode *node)
  {
    if (!node)
      return 0;
    return 1 + max(height(node->left), height(node->right));
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;
    int l = diameterOfBinaryTree(root->left);
    int r = diameterOfBinaryTree(root->right);
    int c = height(root->left) + height(root->right);
    return max(c, max(l, r));
  }
};

// time complexity O(N);
class SolutionOptimized
{
public:
  int dfs(TreeNode *root, int &diameter)
  {
    if (!root)
      return 0;

    int left = dfs(root->left, diameter);
    int right = dfs(root->right, diameter);

    diameter = max(diameter, left + right); // edges

    return 1 + max(left, right);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    int diameter = 0;
    dfs(root, diameter);
    return diameter;
  }
};

// Main function to test the solutions
int main()
{
  // Create a test tree: [1,2,3,4,5]
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  cout << "Testing Brute Force Solution:" << endl;
  SolutionBruteForce sol1;
  cout << "Diameter: " << sol1.diameterOfBinaryTree(root) << endl;

  cout << "\nTesting Optimized Solution:" << endl;
  SolutionOptimized sol2;
  cout << "Diameter: " << sol2.diameterOfBinaryTree(root) << endl;

  // Test case 2: [1,2]
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);

  cout << "\nTest case 2 [1,2]:" << endl;
  cout << "Brute Force Diameter: " << sol1.diameterOfBinaryTree(root2) << endl;
  cout << "Optimized Diameter: " << sol2.diameterOfBinaryTree(root2) << endl;

  return 0;
}