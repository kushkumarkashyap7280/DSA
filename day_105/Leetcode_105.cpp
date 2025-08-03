// 105. Construct Binary Tree from Preorder and Inorder Traversal

// link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

class Solution
{
  TreeNode *solve(vector<int> &preorder, int pl, int pr,
                  vector<int> &inorder, int il, int ir)
  {
    if (pl > pr || il > ir)
      return nullptr;

    int node = preorder[pl];
    TreeNode *temp = new TreeNode(node);

    // find root index in inorder
    int index = il;
    while (index <= ir && inorder[index] != node)
      index++;

    int leftSize = index - il; // number of nodes in left subtree

    // Left subtree:
    temp->left = solve(preorder, pl + 1, pl + leftSize,
                       inorder, il, index - 1);

    // Right subtree:
    temp->right = solve(preorder, pl + leftSize + 1, pr,
                        inorder, index + 1, ir);

    return temp;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
};

// Helper function to print tree in level order (for testing)
void printTree(TreeNode *root)
{
  if (!root)
  {
    cout << "null" << endl;
    return;
  }

  vector<TreeNode *> q = {root};
  while (!q.empty())
  {
    TreeNode *curr = q[0];
    q.erase(q.begin());

    if (curr)
    {
      cout << curr->val << " ";
      q.push_back(curr->left);
      q.push_back(curr->right);
    }
    else
    {
      cout << "null ";
    }
  }
  cout << endl;
}

// Test cases and complexity analysis
int main()
{
  Solution sol;

  // Test Case 1: Example from problem
  vector<int> preorder1 = {3, 9, 20, 15, 7};
  vector<int> inorder1 = {9, 3, 15, 20, 7};
  cout << "Test Case 1:" << endl;
  cout << "Preorder: [3, 9, 20, 15, 7]" << endl;
  cout << "Inorder: [9, 3, 15, 20, 7]" << endl;
  TreeNode *result1 = sol.buildTree(preorder1, inorder1);
  cout << "Tree (level order): ";
  printTree(result1);
  cout << "Expected: 3 9 20 null null 15 7" << endl
       << endl;

  // Test Case 2: Single node
  vector<int> preorder2 = {-1};
  vector<int> inorder2 = {-1};
  cout << "Test Case 2:" << endl;
  cout << "Preorder: [-1]" << endl;
  cout << "Inorder: [-1]" << endl;
  TreeNode *result2 = sol.buildTree(preorder2, inorder2);
  cout << "Tree (level order): ";
  printTree(result2);
  cout << "Expected: -1" << endl
       << endl;

  // Test Case 3: Left skewed tree
  vector<int> preorder3 = {1, 2, 3};
  vector<int> inorder3 = {3, 2, 1};
  cout << "Test Case 3:" << endl;
  cout << "Preorder: [1, 2, 3]" << endl;
  cout << "Inorder: [3, 2, 1]" << endl;
  TreeNode *result3 = sol.buildTree(preorder3, inorder3);
  cout << "Tree (level order): ";
  printTree(result3);
  cout << "Expected: 1 2 null 3 null null" << endl
       << endl;

  // Test Case 4: Right skewed tree
  vector<int> preorder4 = {1, 2, 3};
  vector<int> inorder4 = {1, 2, 3};
  cout << "Test Case 4:" << endl;
  cout << "Preorder: [1, 2, 3]" << endl;
  cout << "Inorder: [1, 2, 3]" << endl;
  TreeNode *result4 = sol.buildTree(preorder4, inorder4);
  cout << "Tree (level order): ";
  printTree(result4);
  cout << "Expected: 1 null 2 null 3" << endl
       << endl;

  // Test Case 5: Balanced tree
  vector<int> preorder5 = {1, 2, 4, 5, 3, 6, 7};
  vector<int> inorder5 = {4, 2, 5, 1, 6, 3, 7};
  cout << "Test Case 5:" << endl;
  cout << "Preorder: [1, 2, 4, 5, 3, 6, 7]" << endl;
  cout << "Inorder: [4, 2, 5, 1, 6, 3, 7]" << endl;
  TreeNode *result5 = sol.buildTree(preorder5, inorder5);
  cout << "Tree (level order): ";
  printTree(result5);
  cout << "Expected: 1 2 3 4 5 6 7" << endl
       << endl;

  return 0;
}

/*
Time Complexity: O(n²)
- For each node, we search for its position in inorder array
- In worst case (skewed tree), this search takes O(n) time
- Total time complexity is O(n²) where n is the number of nodes

Space Complexity: O(n)
- Recursion stack space: O(h) where h is height of tree
- In worst case (skewed tree), h = n, so O(n)
- Additional space for creating tree nodes: O(n)
- Total space complexity is O(n)

Algorithm:
1. First element of preorder is always the root
2. Find root's position in inorder array
3. Elements to the left of root in inorder form left subtree
4. Elements to the right of root in inorder form right subtree
5. Recursively build left and right subtrees

Optimization: Using hash map to store inorder indices can reduce
time complexity to O(n) by eliminating the linear search.
*/