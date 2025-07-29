// 107. Binary Tree Level Order Traversal II

/// link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

/*
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
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
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
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

// Bottom-up Level Order Traversal using Queue with reverse
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
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
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

// Alternative Bottom-up Level Order Traversal using Stack
// Time Complexity: O(n)
// Space Complexity: O(w) - where w is the maximum width of the tree
class SolutionAlternative
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    queue<TreeNode *> q;
    stack<vector<int>> st;
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

      st.push(currentLevel);
    }

    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
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

// Helper function to print the result
void printResult(vector<vector<int>> &result)
{
  cout << "[";
  for (int i = 0; i < result.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j];
      if (j < result[i].size() - 1)
        cout << ",";
    }
    cout << "]";
    if (i < result.size() - 1)
      cout << ",";
  }
  cout << "]" << endl;
}

int main()
{
  Solution solution;
  SolutionAlternative solutionAlt;

  // Test Case 1: [3,9,20,null,null,15,7]
  cout << "Test Case 1: [3,9,20,null,null,15,7]" << endl;
  vector<int> arr1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root1 = createTree(arr1, 0);
  vector<vector<int>> result1 = solution.levelOrderBottom(root1);
  cout << "Expected: [[15,7],[9,20],[3]]" << endl;
  cout << "Output: ";
  printResult(result1);
  cout << endl;

  // Test Case 2: [1]
  cout << "Test Case 2: [1]" << endl;
  vector<int> arr2 = {1};
  TreeNode *root2 = createTree(arr2, 0);
  vector<vector<int>> result2 = solution.levelOrderBottom(root2);
  cout << "Expected: [[1]]" << endl;
  cout << "Output: ";
  printResult(result2);
  cout << endl;

  // Test Case 3: []
  cout << "Test Case 3: []" << endl;
  TreeNode *root3 = nullptr;
  vector<vector<int>> result3 = solution.levelOrderBottom(root3);
  cout << "Expected: []" << endl;
  cout << "Output: ";
  printResult(result3);
  cout << endl;

  // Test Alternative Solution
  cout << "Alternative Solution Test:" << endl;
  vector<vector<int>> resultAlt = solutionAlt.levelOrderBottom(root1);
  cout << "Output: ";
  printResult(resultAlt);
  cout << endl;

  return 0;
}
