// 2385. Amount of Time for Binary Tree to Be Infected

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

// link - https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:
- The node is currently uninfected.
- The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
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
  // Time Complexity: O(n) - Each node is visited a constant number of times
  // Space Complexity: O(n) - For the parent map, visited map, and BFS queue
  int amountOfTime(TreeNode *root, int start)
  {
    if (!root)
      return 0;
    // Step 1: Map child to parent and find the target node
    map<TreeNode *, TreeNode *> cp;
    TreeNode *target = nullptr;
    cp[root] = nullptr;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *temp = q.front();
      if (temp->val == start)
        target = temp;
      q.pop();
      if (temp->left)
      {
        cp[temp->left] = temp;
        q.push(temp->left);
      }
      if (temp->right)
      {
        cp[temp->right] = temp;
        q.push(temp->right);
      }
    }
    // Step 2: BFS from target to infect the tree
    map<TreeNode *, bool> isVisited;
    isVisited[target] = true;
    queue<TreeNode *> infected;
    infected.push(target);
    int time = 0;
    while (!infected.empty())
    {
      int s = infected.size();
      bool spread = false;
      while (s--)
      {
        TreeNode *temp = infected.front();
        infected.pop();
        // left
        if (temp->left && !isVisited[temp->left])
        {
          infected.push(temp->left);
          isVisited[temp->left] = true;
          spread = true;
        }
        // right
        if (temp->right && !isVisited[temp->right])
        {
          infected.push(temp->right);
          isVisited[temp->right] = true;
          spread = true;
        }
        // parent
        if (cp[temp] && !isVisited[cp[temp]])
        {
          infected.push(cp[temp]);
          isVisited[cp[temp]] = true;
          spread = true;
        }
      }
      if (spread)
        time++;
    }
    return time;
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

int main()
{
  Solution sol;
  cout << "=== LeetCode 2385: Amount of Time for Binary Tree to Be Infected ===\n\n";
  // Test Case 1: Example 1
  cout << "Test Case 1:" << endl;
  vector<int> vals1 = {1, 5, 3, -1, 4, 10, 6, 9, 2};
  int start1 = 3;
  TreeNode *root1 = buildTree(vals1);
  cout << "Input: root = [1,5,3,null,4,10,6,9,2], start = 3" << endl;
  int res1 = sol.amountOfTime(root1, start1);
  cout << "Output: " << res1 << "\nExpected: 4\n"
       << endl;
  deleteTree(root1);

  // Test Case 2: Example 2
  cout << "Test Case 2:" << endl;
  vector<int> vals2 = {1};
  int start2 = 1;
  TreeNode *root2 = buildTree(vals2);
  cout << "Input: root = [1], start = 1" << endl;
  int res2 = sol.amountOfTime(root2, start2);
  cout << "Output: " << res2 << "\nExpected: 0\n"
       << endl;
  deleteTree(root2);

  // Test Case 3: Skewed tree (all right)
  cout << "Test Case 3:" << endl;
  vector<int> vals3 = {1, -1, 2, -1, 3, -1, 4};
  int start3 = 1;
  TreeNode *root3 = buildTree(vals3);
  cout << "Input: root = [1,null,2,null,3,null,4], start = 1" << endl;
  int res3 = sol.amountOfTime(root3, start3);
  cout << "Output: " << res3 << "\nExpected: 3\n"
       << endl;
  deleteTree(root3);

  // Test Case 4: Skewed tree (all left)
  cout << "Test Case 4:" << endl;
  vector<int> vals4 = {1, 2, -1, 3, -1, 4};
  int start4 = 4;
  TreeNode *root4 = buildTree(vals4);
  cout << "Input: root = [1,2,null,3,null,4], start = 4" << endl;
  int res4 = sol.amountOfTime(root4, start4);
  cout << "Output: " << res4 << "\nExpected: 3\n"
       << endl;
  deleteTree(root4);

  // Test Case 5: Complete binary tree
  cout << "Test Case 5:" << endl;
  vector<int> vals5 = {1, 2, 3, 4, 5, 6, 7};
  int start5 = 5;
  TreeNode *root5 = buildTree(vals5);
  cout << "Input: root = [1,2,3,4,5,6,7], start = 5" << endl;
  int res5 = sol.amountOfTime(root5, start5);
  cout << "Output: " << res5 << "\nExpected: 4\n"
       << endl;
  deleteTree(root5);

  cout << "=== Algorithm Analysis ===" << endl;
  cout << "Time Complexity: O(n) - Each node is visited a constant number of times" << endl;
  cout << "Space Complexity: O(n) - For the parent map, visited map, and BFS queue" << endl;
  return 0;
}