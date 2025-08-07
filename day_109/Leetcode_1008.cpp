#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Problem: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
  TreeNode* insert(TreeNode*& root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
  }

public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = nullptr;
    for (int val : preorder) {
      insert(root, val);
    }
    return root;
  }
};

// Helper: Print tree in level-order format (null as -1)
void printLevelOrder(TreeNode* root) {
  if (!root) {
    cout << "[]\n";
    return;
  }

  queue<TreeNode*> q;
  q.push(root);
  vector<string> result;

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

  // Remove trailing "null"s
  while (!result.empty() && result.back() == "null") {
    result.pop_back();
  }

  cout << "[";
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i != result.size() - 1) cout << ",";
  }
  cout << "]\n";
}

// Helper: Free memory
void deleteTree(TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Main function to test
int main() {
  Solution sol;

  cout << "=== LeetCode 1008: Construct BST from Preorder ===\n\n";

  vector<vector<int>> testCases = {
    {8,5,1,7,10,12},  // Example 1
    {1,3},            // Example 2
    {10,5,1,7,40,50}, // Balanced
    {5,4,3,2,1},      // Skewed Left
    {1,2,3,4,5}       // Skewed Right
  };

  for (int i = 0; i < testCases.size(); ++i) {
    cout << "Test Case " << i + 1 << ":\nInput: ";
    for (int num : testCases[i]) cout << num << " ";
    cout << "\nOutput: ";
    TreeNode* root = sol.bstFromPreorder(testCases[i]);
    printLevelOrder(root);
    deleteTree(root);
    cout << endl;
  }

  return 0;
}
