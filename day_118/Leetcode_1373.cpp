//1373. Maximum Sum BST in Binary Tree

// link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/


/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
*/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Concrete definition for a binary tree node (for local testing)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

struct info{
    int maxi ;
    int mini ;
    int sum ;
    bool isBst;
};

class Solution {
    info solve(TreeNode* root , int &ans){
        if(!root){
            return {INT_MIN, INT_MAX, 0, true};
        }
        
        info l = solve(root->left , ans);
        info r = solve(root->right , ans);
    
        info currNode;
        currNode.sum= l.sum + r.sum + root->val;
        currNode.maxi = max(root->val , r.maxi);
        currNode.mini = min(root->val , l.mini);
        currNode.isBst = l.maxi < root->val && r.mini > root->val  && l.isBst && r.isBst;
        if(currNode.isBst){
            ans  = max(ans , currNode.sum);
        }
        return currNode;
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};

// Helper: insert into BST (for building quick test trees)
TreeNode* insertBST(TreeNode* root, int val){
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Helper: delete tree to free memory
void deleteTree(TreeNode* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    // Test 1: tree with a BST subtree having max sum
    // Structure roughly:    1
    //                      / \
    //                     4   3
    //                    / \   \
    //                   2   4   5
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(5);

    Solution sol;
    cout << "Max Sum BST (Test 1): " << sol.maxSumBST(root1) << "\n";

    // Test 2: a valid BST
    TreeNode* root2 = nullptr;
    for(int v : {4,2,6,1,3,5,7}) root2 = insertBST(root2, v);
    cout << "Max Sum BST (Test 2): " << sol.maxSumBST(root2) << "\n"; // sum of all nodes

    deleteTree(root1);
    deleteTree(root2);
    return 0;
}