//99. Recover Binary Search Tree

// link - https://leetcode.com/problems/recover-binary-search-tree/description/


/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
*/

#include <iostream>
#include <algorithm>
#include <vector>
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

class Solution {

public:

   // time complexity O(n)
   // space complexity O(1)
    void recoverTree(TreeNode* root) {

        TreeNode* v1 = nullptr;
        TreeNode* v2 = nullptr;
        TreeNode* prev = nullptr;
       
       TreeNode* curr = root;
       while(curr){
         if(!curr->left){
              if(prev && prev->val > curr->val){
                  if(!v1) v1 = prev;
                    v2  = curr;
             }
                 prev = curr;
             curr= curr->right;
         }else{
            TreeNode* temp =  curr->left;
            while(temp->right && temp->right != curr) temp = temp->right;

            if(temp->right == nullptr){
                 temp->right = curr;
                curr= curr->left;
             
            }else{
             if(prev && prev->val > curr->val){
                  if(!v1) v1 = prev;
                    v2  = curr;
             }
                 prev = curr;
                temp->right = nullptr;
                curr = curr->right;
               
            }
         }
       }
        if(v1 && v2 ) swap(v1->val ,v2->val);
    }
};

// Helper function to print tree in-order
void printInOrder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

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

int main() {
    Solution sol;
    
    // Test Case 1: Example 1 from problem statement
    // Original: [1,3,null,null,2]
    // Expected: [3,1,null,null,2]
    cout << "Test Case 1:\n";
    vector<int> values1 = {1, 3, -1, -1, 2};
    TreeNode* root1 = createTree(values1);
    cout << "Before recovery: ";
    printInOrder(root1);
    cout << "\n";
    sol.recoverTree(root1);
    cout << "After recovery:  ";
    printInOrder(root1);
    cout << "\n\n";
    
    // Test Case 2: Example 2 from problem statement
    // Original: [3,1,4,null,null,2]
    // Expected: [2,1,4,null,null,3]
    cout << "Test Case 2:\n";
    vector<int> values2 = {3, 1, 4, -1, -1, 2};
    TreeNode* root2 = createTree(values2);
    cout << "Before recovery: ";
    printInOrder(root2);
    cout << "\n";
    sol.recoverTree(root2);
    cout << "After recovery:  ";
    printInOrder(root2);
    cout << "\n\n";
    
    // Test Case 3: Additional test case with more nodes
    // Original: [10,5,15,2,8,12,20,1,3,6,9,11,13,18,25]
    // Swapped nodes: 5 and 25
    // Expected: [10,25,15,2,8,12,20,1,3,6,9,11,13,18,5]
    cout << "Test Case 3:\n";
    vector<int> values3 = {10, 5, 15, 2, 8, 12, 20, 1, 3, 6, 9, 11, 13, 18, 25};
    // Create a valid BST first
    TreeNode* root3 = createTree(values3);
    // Manually swap two nodes to create an invalid BST
    TreeNode* node5 = root3->left;  // 5
    TreeNode* node25 = root3->right->right->right;  // 25
    swap(node5->val, node25->val);
    
    cout << "Before recovery: ";
    printInOrder(root3);
    cout << "\n";
    sol.recoverTree(root3);
    cout << "After recovery:  ";
    printInOrder(root3);
    cout << "\n\n";
    
    // Clean up memory
    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root3);
    
    return 0;
}