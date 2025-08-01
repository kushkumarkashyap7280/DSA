// 1161. Maximum Level Sum of a Binary Tree

// link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.



Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// BFS Solution using Level Order Traversal
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(w) - where w is the maximum width of the tree (queue size)
class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    if (!root)
      return 0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    int maxSum = INT_MIN;
    int minLevel = 1;
    while (!q.empty())
    {
      int s = q.size();
      int sum = 0;
      while (s--)
      {
        TreeNode *curr = q.front();
        q.pop();
        sum += curr->val;
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
      if (sum > maxSum)
      {
        maxSum = sum;
        minLevel = level;
      }
      level++;
    }
    return minLevel;
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

// Helper function to print level order traversal
void printLevelOrder(TreeNode *root)
{
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);
  int level = 1;

  cout << "Level Order Traversal:" << endl;
  while (!q.empty())
  {
    int size = q.size();
    cout << "Level " << level << ": ";
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = q.front();
      q.pop();

      cout << curr->val << " ";
      sum += curr->val;

      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    cout << " (Sum: " << sum << ")" << endl;
    level++;
  }
}

int main()
{
  cout << "=== LeetCode 1161: Maximum Level Sum of a Binary Tree ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {1, 7, 0, 7, -8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
  TreeNode *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  printLevelOrder(root1);

  Solution sol1;
  int result1 = sol1.maxLevelSum(root1);
  cout << "Maximum Level Sum: Level " << result1 << endl;
  cout << "Expected: Level 2" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {989, -1, 10250, -1, -1, 98693, -89388, -1, -1, -1, -1, -1, -1, -1, -32127};
  TreeNode *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  printLevelOrder(root2);

  Solution sol2;
  int result2 = sol2.maxLevelSum(root2);
  cout << "Maximum Level Sum: Level " << result2 << endl;
  cout << "Expected: Level 2" << endl
       << endl;

  // Test Case 3: Simple tree
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  printLevelOrder(root3);

  Solution sol3;
  int result3 = sol3.maxLevelSum(root3);
  cout << "Maximum Level Sum: Level " << result3 << endl;
  cout << "Expected: Level 3" << endl
       << endl;

  // Test Case 4: Single node
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {5};
  TreeNode *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  printLevelOrder(root4);

  Solution sol4;
  int result4 = sol4.maxLevelSum(root4);
  cout << "Maximum Level Sum: Level " << result4 << endl;
  cout << "Expected: Level 1" << endl
       << endl;

  // Test Case 5: All negative values
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {-1, -2, -3, -4, -5, -6, -7};
  TreeNode *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  printLevelOrder(root5);

  Solution sol5;
  int result5 = sol5.maxLevelSum(root5);
  cout << "Maximum Level Sum: Level " << result5 << endl;
  cout << "Expected: Level 1" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "BFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(w) - queue size at maximum width" << endl;
  cout << "- Algorithm: Level order traversal with sum tracking" << endl;
  cout << "- Key Insight: Track sum at each level and find maximum" << endl;
  cout << "- Strategy: Use BFS to process level by level" << endl;

  return 0;
}