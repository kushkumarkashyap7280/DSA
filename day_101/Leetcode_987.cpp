// 987. Vertical Order Traversal of a Binary Tree

// link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.


Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// Vertical Order Traversal of Binary Tree using BFS
// Time Complexity: O(n log n) - where n is the number of nodes in the tree
// Space Complexity: O(n) - for storing all nodes in the map
class Solution
{
public:
  // DFS approach to find the leftmost and rightmost columns
  void farMost(TreeNode *root, int &l, int &r, int &c)
  {
    if (!root)
      return;
    if (root->left)
    {
      c--;
      l = min(l, c);
      r = max(r, c);
      farMost(root->left, l, r, c);
      c++;
    }
    if (root->right)
    {
      c++;
      l = min(l, c);
      r = max(r, c);
      farMost(root->right, l, r, c);
      c--;
    }
  }

  // DFS approach to add nodes to their respective columns
  void add(TreeNode *root, vector<vector<pair<int, int>>> &v, int &c, int row)
  {
    if (!root)
      return;
    v[c].push_back({row, root->val}); // row + value

    if (root->left)
    {
      c--;
      add(root->left, v, c, row + 1);
      c++;
    }
    if (root->right)
    {
      c++;
      add(root->right, v, c, row + 1);
      c--;
    }
  }

  // Custom comparator for sorting by row and value
  static bool comparePairs(const pair<int, int> &a, const pair<int, int> &b)
  {
    if (a.first != b.first)
      return a.first < b.first; // sort by row
    return a.second < b.second; // then by value
  }

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    if (!root)
      return {};
    int l = 0, r = 0, c = 0;
    farMost(root, l, r, c);

    int size = abs(l) + r + 1;
    vector<vector<pair<int, int>>> temp(size);

    c = abs(l);
    add(root, temp, c, 0);

    vector<vector<int>> ans(size);
    for (int i = 0; i < size; i++)
    {
      sort(temp[i].begin(), temp[i].end(), comparePairs);
      for (int j = 0; j < temp[i].size(); j++)
      {
        ans[i].push_back(temp[i][j].second);
      }
    }
    return ans;
  }
};

// Alternative BFS Solution using Map
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class SolutionBFS
{
public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    if (!root)
      return {};

    map<int, vector<pair<int, int>>> nodes;    // col -> {row, value}
    queue<pair<TreeNode *, pair<int, int>>> q; // node, {col, row}

    q.push({root, {0, 0}});

    while (!q.empty())
    {
      auto front = q.front();
      q.pop();

      TreeNode *node = front.first;
      int col = front.second.first;
      int row = front.second.second;

      nodes[col].push_back({row, node->val});

      if (node->left)
        q.push({node->left, {col - 1, row + 1}});
      if (node->right)
        q.push({node->right, {col + 1, row + 1}});
    }

    vector<vector<int>> ans;
    for (auto &it : nodes)
    {
      auto &vec = it.second;
      sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
           {
             if (a.first != b.first)
               return a.first < b.first; // sort by row
             return a.second < b.second; // then by value
           });

      vector<int> col;
      for (auto &p : vec)
        col.push_back(p.second);
      ans.push_back(col);
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
  SolutionBFS solutionBFS;

  // Test Case 1: [3,9,20,null,null,15,7]
  cout << "Test Case 1: [3,9,20,null,null,15,7]" << endl;
  vector<int> arr1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root1 = createTree(arr1, 0);
  vector<vector<int>> result1 = solution.verticalTraversal(root1);
  cout << "Expected: [[9],[3,15],[20],[7]]" << endl;
  cout << "Output: ";
  printResult(result1);
  cout << endl;

  // Test Case 2: [1,2,3,4,5,6,7]
  cout << "Test Case 2: [1,2,3,4,5,6,7]" << endl;
  vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root2 = createTree(arr2, 0);
  vector<vector<int>> result2 = solution.verticalTraversal(root2);
  cout << "Expected: [[4],[2],[1,5,6],[3],[7]]" << endl;
  cout << "Output: ";
  printResult(result2);
  cout << endl;

  // Test Case 3: [1,2,3,4,6,5,7]
  cout << "Test Case 3: [1,2,3,4,6,5,7]" << endl;
  vector<int> arr3 = {1, 2, 3, 4, 6, 5, 7};
  TreeNode *root3 = createTree(arr3, 0);
  vector<vector<int>> result3 = solution.verticalTraversal(root3);
  cout << "Expected: [[4],[2],[1,5,6],[3],[7]]" << endl;
  cout << "Output: ";
  printResult(result3);
  cout << endl;

  // Test BFS Solution
  cout << "BFS Solution Test:" << endl;
  vector<vector<int>> resultBFS = solutionBFS.verticalTraversal(root1);
  cout << "Output: ";
  printResult(resultBFS);
  cout << endl;

  return 0;
}
