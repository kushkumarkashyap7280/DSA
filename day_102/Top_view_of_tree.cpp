// Top View of Binary Tree

// link -https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only.
Examples:

Input: root[] = [1, 2, 3]

Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]

Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
  // using map and recursion ---- dfs approach
  //     void farMost(Node *root, int hd, int depth,
  //                  map<int,pair<int,int>> &mp) {
  //         if (!root) return;

  //         // if HD not seen OR current node is at a shallower depth
  //         if (mp.find(hd) == mp.end() || depth < mp[hd].second) {
  //             mp[hd] = {root->data, depth};
  //         }

  //         farMost(root->left, hd - 1, depth + 1, mp);
  //         farMost(root->right, hd + 1, depth + 1, mp);
  //     }

  // public:
  //     vector<int> topView(Node *root) {
  //         if (!root) return {};

  //         map<int,pair<int,int>> mp; // hd -> {node, depth}
  //         farMost(root, 0, 0, mp);

  //         vector<int> ans;
  //         for (auto &p : mp) {
  //             ans.push_back(p.second.first);
  //         }
  //         return ans;
  //     }

  // using map and queue ---- bfs approach
public:
  vector<int> topView(Node *root)
  {
    if (!root)
      return {};
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
      Node *curr = q.front().first;
      int hd = q.front().second;
      q.pop();

      // Only insert the first time we encounter this HD
      if (m.find(hd) == m.end())
      {
        m[hd] = curr->data;
      }

      if (curr->left)
        q.push({curr->left, hd - 1});
      if (curr->right)
        q.push({curr->right, hd + 1});
    }

    // Collect answer from leftmost to rightmost
    vector<int> ans;
    for (auto &p : m)
    {
      ans.push_back(p.second);
    }
    return ans;
  }
};