// 199. Binary Tree Right Side View

// link  -https://leetcode.com/problems/binary-tree-right-side-view/description/

/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []



Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <queue>
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

// Binary Tree Right Side View using Level Order Traversal
// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(w) - where w is the maximum width of the tree
//                  In worst case: O(n) for a complete binary tree
//                  In best case: O(1) for a skewed tree
class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      ans.push_back(q.front()->val);
      int s = q.size();
      while (s)
      {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->right)
          q.push(temp->right);
        if (temp->left)
          q.push(temp->left);
        s--;
      }
    }
    return ans;
  }
};

// Alternative Solution using DFS (Right-first traversal)
// Time Complexity: O(n)
// Space Complexity: O(h) - where h is the height of the tree
class SolutionDFS
{
public:
  void dfs(TreeNode *root, vector<int> &result, int depth)
  {
    if (!root)
      return;

    // If this is the first node at this depth, add it
    if (depth == result.size())
    {
      result.push_back(root->val);
    }

    // Traverse right first, then left
    dfs(root->right, result, depth + 1);
    dfs(root->left, result, depth + 1);
  }

  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> result;
    dfs(root, result, 0);
    return result;
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
void printResult(vector<int> &result)
{
  cout << "[";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i];
    if (i < result.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main()
{
  Solution solution;
  SolutionDFS solutionDFS;

  // Test Case 1: [1,2,3,null,5,null,4]
  cout << "Test Case 1: [1,2,3,null,5,null,4]" << endl;
  vector<int> arr1 = {1, 2, 3, -1, 5, -1, 4};
  TreeNode *root1 = createTree(arr1, 0);
  vector<int> result1 = solution.rightSideView(root1);
  cout << "Expected: [1, 3, 4]" << endl;
  cout << "Output: ";
  printResult(result1);
  cout << endl;

  // Test Case 2: [1,2,3,4,null,null,null,5]
  cout << "Test Case 2: [1,2,3,4,null,null,null,5]" << endl;
  vector<int> arr2 = {1, 2, 3, 4, -1, -1, -1, 5};
  TreeNode *root2 = createTree(arr2, 0);
  vector<int> result2 = solution.rightSideView(root2);
  cout << "Expected: [1, 3, 4, 5]" << endl;
  cout << "Output: ";
  printResult(result2);
  cout << endl;

  // Test Case 3: [1,null,3]
  cout << "Test Case 3: [1,null,3]" << endl;
  vector<int> arr3 = {1, -1, 3};
  TreeNode *root3 = createTree(arr3, 0);
  vector<int> result3 = solution.rightSideView(root3);
  cout << "Expected: [1, 3]" << endl;
  cout << "Output: ";
  printResult(result3);
  cout << endl;

  // Test Case 4: []
  cout << "Test Case 4: []" << endl;
  TreeNode *root4 = nullptr;
  vector<int> result4 = solution.rightSideView(root4);
  cout << "Expected: []" << endl;
  cout << "Output: ";
  printResult(result4);
  cout << endl;

  // Test DFS Solution
  cout << "DFS Solution Test:" << endl;
  vector<int> resultDFS = solutionDFS.rightSideView(root1);
  cout << "Output: ";
  printResult(resultDFS);
  cout << endl;

  return 0;
}