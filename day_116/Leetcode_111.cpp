//111. Minimum Depth of Binary Tree

// link - https://leetcode.com/problems/minimum-depth-of-binary-tree/description/


/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

// Helper function to create a binary tree from a vector
TreeNode* createTree(const vector<int>& values, int index = 0) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Helper function to delete tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Helper function to print tree in level order (for test case visualization)
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    
    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }
    
    // Remove trailing nulls
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    
    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
}

class Solution {
    // Time complexity = O(n)
    // space complexity = O(h)
    void dfs(TreeNode* root, int curr, int &mini) {
      if (!root) return;
  
      // If it's a leaf
      if (!root->left && !root->right) {
          mini = min(mini, curr);
          return;
      }
  
      dfs(root->left, curr + 1, mini);
      dfs(root->right, curr + 1, mini);
  }
  public :
  int minDepth(TreeNode* root) {
      if (!root) return 0;
      int mini = INT_MAX;
      dfs(root, 1, mini);
      return mini;
  }
  
};