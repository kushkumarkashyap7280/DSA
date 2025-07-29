// 103. Binary Tree Zigzag Level Order Traversal

// link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <iostream>
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

// Zigzag Level Order Traversal using Queue with reverse operation
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    bool ltr = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      vector<int> v;
      int s = q.size();
      for (int i = 0; i < s; i++)
      {
        TreeNode *temp = q.front();
        q.pop();
        v.push_back(temp->val);
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      }

      if (!ltr)
        reverse(v.begin(), v.end());
      ans.push_back(v);
      ltr = !ltr;
    }
    return ans;
  }
};

// Alternative Zigzag Level Order Traversal using Deque
// Time Complexity: O(n)
// Space Complexity: O(w) - where w is the maximum width of the tree
class SolutionAlternative
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;

    deque<TreeNode *> dq;
    dq.push_back(root);
    bool ltr = true;

    while (!dq.empty())
    {
      int levelSize = dq.size();
      vector<int> currentLevel;

      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *node;
        if (ltr)
        {
          node = dq.front();
          dq.pop_front();
          if (node->left)
            dq.push_back(node->left);
          if (node->right)
            dq.push_back(node->right);
        }
        else
        {
          node = dq.back();
          dq.pop_back();
          if (node->right)
            dq.push_front(node->right);
          if (node->left)
            dq.push_front(node->left);
        }
        currentLevel.push_back(node->val);
      }

      ans.push_back(currentLevel);
      ltr = !ltr;
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

  // Test Case 1: [3,9,20,null,null,15,7]
  cout << "Test Case 1: [3,9,20,null,null,15,7]" << endl;
  vector<int> arr1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root1 = createTree(arr1, 0);
  vector<vector<int>> result1 = solution.zigzagLevelOrder(root1);
  cout << "Expected: [[3],[20,9],[15,7]]" << endl;
  cout << "Output: ";
  printResult(result1);
  cout << endl;

  // Test Case 2: [1]
  cout << "Test Case 2: [1]" << endl;
  vector<int> arr2 = {1};
  TreeNode *root2 = createTree(arr2, 0);
  vector<vector<int>> result2 = solution.zigzagLevelOrder(root2);
  cout << "Expected: [[1]]" << endl;
  cout << "Output: ";
  printResult(result2);
  cout << endl;

  // Test Case 3: []
  cout << "Test Case 3: []" << endl;
  TreeNode *root3 = nullptr;
  vector<vector<int>> result3 = solution.zigzagLevelOrder(root3);
  cout << "Expected: []" << endl;
  cout << "Output: ";
  printResult(result3);
  cout << endl;

  return 0;
}
