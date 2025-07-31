// 513. Find Bottom Left Tree Value

// link -https://leetcode.com/problems/find-bottom-left-tree-value/description/

/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.



Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

#include <iostream>
#include <queue>
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

// DFS Solution
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(h) - where h is the height of the tree (recursion stack)
class Solutiondfs
{
  int ans, maxDepth;
  void dfs(TreeNode *node, int depth)
  {
    if (!node)
      return;

    // If we reach a deeper level for the first time
    if (depth > maxDepth)
    {
      maxDepth = depth;
      ans = node->val;
    }

    // Go left first to ensure leftmost is found first
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  }

public:
  int findBottomLeftValue(TreeNode *root)
  {
    maxDepth = -1;
    dfs(root, 0);
    return ans;
  }
};

// BFS Solution
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(w) - where w is the maximum width of the tree (queue size)
class Solutionbfs
{
public:
  int findBottomLeftValue(TreeNode *root)
  {
    if (!root)
      return -1;
    int ans = -1;
    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty())
    {
      int s = q.size();
      ans = q.front()->val;
      while (s--)
      {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }
    }
    return ans;
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

int main()
{
  cout << "=== LeetCode 513: Find Bottom Left Tree Value ===" << endl
       << endl;

  // Test Case 1: [2,1,3]
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {2, 1, 3};
  TreeNode *root1 = createTree(values1);
  cout << "Tree: ";
  printTree(root1);
  cout << endl;

  Solutiondfs dfs1;
  Solutionbfs bfs1;
  cout << "DFS Result: " << dfs1.findBottomLeftValue(root1) << endl;
  cout << "BFS Result: " << bfs1.findBottomLeftValue(root1) << endl;
  cout << "Expected: 1" << endl
       << endl;

  // Test Case 2: [1,2,3,4,-1,5,6,-1,-1,-1,7]
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {1, 2, 3, 4, -1, 5, 6, -1, -1, -1, 7};
  TreeNode *root2 = createTree(values2);
  cout << "Tree: ";
  printTree(root2);
  cout << endl;

  Solutiondfs dfs2;
  Solutionbfs bfs2;
  cout << "DFS Result: " << dfs2.findBottomLeftValue(root2) << endl;
  cout << "BFS Result: " << bfs2.findBottomLeftValue(root2) << endl;
  cout << "Expected: 7" << endl
       << endl;

  // Test Case 3: Single node
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {5};
  TreeNode *root3 = createTree(values3);
  cout << "Tree: ";
  printTree(root3);
  cout << endl;

  Solutiondfs dfs3;
  Solutionbfs bfs3;
  cout << "DFS Result: " << dfs3.findBottomLeftValue(root3) << endl;
  cout << "BFS Result: " << bfs3.findBottomLeftValue(root3) << endl;
  cout << "Expected: 5" << endl
       << endl;

  // Test Case 4: Left skewed tree
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {1, 2, -1, 3, -1, -1, -1, 4};
  TreeNode *root4 = createTree(values4);
  cout << "Tree: ";
  printTree(root4);
  cout << endl;

  Solutiondfs dfs4;
  Solutionbfs bfs4;
  cout << "DFS Result: " << dfs4.findBottomLeftValue(root4) << endl;
  cout << "BFS Result: " << bfs4.findBottomLeftValue(root4) << endl;
  cout << "Expected: 4" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "DFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl
       << endl;

  cout << "BFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(w) - queue size at maximum width" << endl;

  return 0;
}