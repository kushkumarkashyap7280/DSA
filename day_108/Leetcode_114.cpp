// 114. Flatten Binary Tree to Linked List
// Time Complexity: O(n) - Each node is visited once
// Space Complexity: O(1) - In-place modification using Morris traversal approach

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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

class Solution
{
public:
  // Morris Traversal Approach for In-Place Flattening
  // Time Complexity: O(n) - Each node is visited once
  // Space Complexity: O(1) - Only uses a constant amount of extra space
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    TreeNode *curr = root;
    while (curr)
    {
      if (curr->left)
      {
        // Find the rightmost node in the left subtree
        TreeNode *prev = curr->left;
        while (prev->right)
        {
          prev = prev->right;
        }
        // Connect the rightmost node of left subtree to the right subtree
        prev->right = curr->right;
        // Move left subtree to right
        curr->right = curr->left;
        // Set left to null
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};

// Helper function to build a binary tree from a vector (level order, null as -1)
TreeNode *buildTree(const vector<int> &vals)
{
  if (vals.empty() || vals[0] == -1)
    return nullptr;
  TreeNode *root = new TreeNode(vals[0]);
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < vals.size())
  {
    TreeNode *curr = q.front();
    q.pop();
    if (i < vals.size() && vals[i] != -1)
    {
      curr->left = new TreeNode(vals[i]);
      q.push(curr->left);
    }
    i++;
    if (i < vals.size() && vals[i] != -1)
    {
      curr->right = new TreeNode(vals[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// Helper function to free memory
void deleteTree(TreeNode *root)
{
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Helper function to print flattened tree (linked list)
void printFlattenedTree(TreeNode *root)
{
  cout << "Flattened Tree: [";
  TreeNode *curr = root;
  bool first = true;
  while (curr)
  {
    if (!first)
      cout << ", ";
    cout << curr->val;
    first = false;
    curr = curr->right;
  }
  cout << "]" << endl;
}

// Helper function to print tree in level order (before flattening)
void printTreeLevelOrder(TreeNode *root)
{
  if (!root)
  {
    cout << "[]" << endl;
    return;
  }

  cout << "[";
  queue<TreeNode *> q;
  q.push(root);
  bool first = true;

  while (!q.empty())
  {
    TreeNode *curr = q.front();
    q.pop();

    if (!first)
      cout << ", ";
    if (curr)
    {
      cout << curr->val;
      q.push(curr->left);
      q.push(curr->right);
    }
    else
    {
      cout << "null";
    }
    first = false;
  }
  cout << "]" << endl;
}

int main()
{
  Solution sol;
  cout << "=== LeetCode 114: Flatten Binary Tree to Linked List ===\n\n";

  // Test Case 1: Example 1
  cout << "Test Case 1:" << endl;
  vector<int> vals1 = {1, 2, 5, 3, 4, -1, 6};
  TreeNode *root1 = buildTree(vals1);
  cout << "Input: [1,2,5,3,4,null,6]" << endl;
  cout << "Before flattening: ";
  printTreeLevelOrder(root1);

  sol.flatten(root1);
  printFlattenedTree(root1);
  cout << "Expected: [1, 2, 3, 4, 5, 6]\n"
       << endl;
  deleteTree(root1);

  // Test Case 2: Example 2 (empty tree)
  cout << "Test Case 2:" << endl;
  TreeNode *root2 = nullptr;
  cout << "Input: []" << endl;
  cout << "Before flattening: []" << endl;

  sol.flatten(root2);
  printFlattenedTree(root2);
  cout << "Expected: []\n"
       << endl;

  // Test Case 3: Example 3 (single node)
  cout << "Test Case 3:" << endl;
  vector<int> vals3 = {0};
  TreeNode *root3 = buildTree(vals3);
  cout << "Input: [0]" << endl;
  cout << "Before flattening: ";
  printTreeLevelOrder(root3);

  sol.flatten(root3);
  printFlattenedTree(root3);
  cout << "Expected: [0]\n"
       << endl;
  deleteTree(root3);

  // Test Case 4: Skewed tree (all left)
  cout << "Test Case 4:" << endl;
  vector<int> vals4 = {1, 2, -1, 3, -1, 4};
  TreeNode *root4 = buildTree(vals4);
  cout << "Input: [1,2,null,3,null,4]" << endl;
  cout << "Before flattening: ";
  printTreeLevelOrder(root4);

  sol.flatten(root4);
  printFlattenedTree(root4);
  cout << "Expected: [1, 2, 3, 4]\n"
       << endl;
  deleteTree(root4);

  // Test Case 5: Skewed tree (all right)
  cout << "Test Case 5:" << endl;
  vector<int> vals5 = {1, -1, 2, -1, 3, -1, 4};
  TreeNode *root5 = buildTree(vals5);
  cout << "Input: [1,null,2,null,3,null,4]" << endl;
  cout << "Before flattening: ";
  printTreeLevelOrder(root5);

  sol.flatten(root5);
  printFlattenedTree(root5);
  cout << "Expected: [1, 2, 3, 4]\n"
       << endl;
  deleteTree(root5);

  // Test Case 6: Complete binary tree
  cout << "Test Case 6:" << endl;
  vector<int> vals6 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root6 = buildTree(vals6);
  cout << "Input: [1,2,3,4,5,6,7]" << endl;
  cout << "Before flattening: ";
  printTreeLevelOrder(root6);

  sol.flatten(root6);
  printFlattenedTree(root6);
  cout << "Expected: [1, 2, 4, 5, 3, 6, 7]\n"
       << endl;
  deleteTree(root6);

  cout << "=== Algorithm Analysis ===" << endl;
  cout << "Time Complexity: O(n) - Each node is visited once" << endl;
  cout << "Space Complexity: O(1) - In-place modification using Morris traversal approach" << endl;
  cout << "\nKey Insights:" << endl;
  cout << "1. Uses Morris traversal technique for O(1) space complexity" << endl;
  cout << "2. Flattens tree in preorder traversal order (Root -> Left -> Right)" << endl;
  cout << "3. Each node's left subtree is moved to the right of its rightmost node" << endl;
  cout << "4. Left pointers are set to null to create the linked list structure" << endl;

  return 0;
}