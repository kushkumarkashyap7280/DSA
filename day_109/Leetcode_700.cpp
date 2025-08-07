//700. Search in a Binary Search Tree

// link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/

#include <iostream>
#include <queue>
using namespace std;


/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
*/

  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
              if(val ==root->val) return root;
              if(val > root->val){
                root = root->right;
              }else{
                root = root->left;
              }
        }
        return root;
    }
};


// Function to print level order traversal
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val;
        if (q.empty() && !curr->left && !curr->right) break;
        cout << ",";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "]\n";
}

// Driver code
int main() {
    // Building the tree [4,2,7,1,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    Solution sol;
    TreeNode* result = sol.searchBST(root, val);

    printLevelOrder(result); // Should print [2,1,3]

    return 0;
}