//450. Delete Node in a BST

// link -https://leetcode.com/problems/delete-node-in-a-bst/description/

/*
TIME COMPLEXITY: O(h) where h is the height of the BST
- In worst case (skewed tree): O(n) where n is number of nodes
- In best case (balanced tree): O(log n)
- We traverse at most one path from root to the node to be deleted

SPACE COMPLEXITY: O(h) due to recursion stack
- In worst case (skewed tree): O(n)
- In best case (balanced tree): O(log n)
- Each recursive call uses constant space

ALGORITHM:
1. Search for the node to delete
2. Three cases when node is found:
   - Node has no children: Simply delete it
   - Node has one child: Replace node with its child
   - Node has two children: Replace with inorder successor (smallest in right subtree)
*/

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?
*/


#include <iostream>
#include <vector>
using namespace std;

//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    TreeNode* minValRight(TreeNode* root){
        while(root->left) root = root->left;
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
            if(!root) return root;
            if(root->val == key){
                if(!root->left && !root->right){
                    delete root;
                    return nullptr;

                }else if(root->left && !root->right){
                   TreeNode* temp = root->left;
                   delete root;
                   return temp;
                }else if(root->right && !root->left){
                     TreeNode* temp = root->right;
                     delete root;
                     return temp;

                }else{
                  TreeNode* minRight = minValRight(root->right);
                  root->val = minRight->val;
                 root->right = deleteNode(root->right, minRight->val);
                }

            }else{
                if(root->val > key){
                    root->left = deleteNode(root->left , key);
                }else{
                    root->right = deleteNode(root->right, key);
                }
            }
            
        return root;
    }
};
// Helper function to create TreeNode
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Helper function for inorder traversal to verify BST
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

// Helper function to print tree (inorder)
void printTree(TreeNode* root) {
    vector<int> result;
    inorderTraversal(root, result);
    cout << "Tree (inorder): ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
}

// Test function
void runTests() {
    Solution sol;
    
    cout << "=== DELETE NODE IN BST TEST CASES ===" << endl;
    
    // Test Case 1: Delete leaf node
    cout << "\nTest Case 1: Delete leaf node" << endl;
    TreeNode* root1 = createNode(5);
    root1->left = createNode(3);
    root1->right = createNode(6);
    root1->left->left = createNode(2);
    root1->left->right = createNode(4);
    root1->right->right = createNode(7);
    
    cout << "Before deletion: ";
    printTree(root1);
    root1 = sol.deleteNode(root1, 2);
    cout << "After deleting 2: ";
    printTree(root1);
    
    // Test Case 2: Delete node with one child (left)
    cout << "\nTest Case 2: Delete node with one child (left)" << endl;
    TreeNode* root2 = createNode(5);
    root2->left = createNode(3);
    root2->right = createNode(6);
    root2->left->left = createNode(2);
    root2->right->right = createNode(7);
    
    cout << "Before deletion: ";
    printTree(root2);
    root2 = sol.deleteNode(root2, 3);
    cout << "After deleting 3: ";
    printTree(root2);
    
    // Test Case 3: Delete node with one child (right)
    cout << "\nTest Case 3: Delete node with one child (right)" << endl;
    TreeNode* root3 = createNode(5);
    root3->left = createNode(3);
    root3->right = createNode(6);
    root3->left->right = createNode(4);
    root3->right->right = createNode(7);
    
    cout << "Before deletion: ";
    printTree(root3);
    root3 = sol.deleteNode(root3, 3);
    cout << "After deleting 3: ";
    printTree(root3);
    
    // Test Case 4: Delete node with two children
    cout << "\nTest Case 4: Delete node with two children" << endl;
    TreeNode* root4 = createNode(5);
    root4->left = createNode(3);
    root4->right = createNode(6);
    root4->left->left = createNode(2);
    root4->left->right = createNode(4);
    root4->right->right = createNode(7);
    
    cout << "Before deletion: ";
    printTree(root4);
    root4 = sol.deleteNode(root4, 3);
    cout << "After deleting 3: ";
    printTree(root4);
    
    // Test Case 5: Delete root node
    cout << "\nTest Case 5: Delete root node" << endl;
    TreeNode* root5 = createNode(5);
    root5->left = createNode(3);
    root5->right = createNode(6);
    root5->left->left = createNode(2);
    root5->left->right = createNode(4);
    root5->right->right = createNode(7);
    
    cout << "Before deletion: ";
    printTree(root5);
    root5 = sol.deleteNode(root5, 5);
    cout << "After deleting root 5: ";
    printTree(root5);
    
    // Test Case 6: Delete non-existent key
    cout << "\nTest Case 6: Delete non-existent key" << endl;
    TreeNode* root6 = createNode(5);
    root6->left = createNode(3);
    root6->right = createNode(6);
    
    cout << "Before deletion: ";
    printTree(root6);
    root6 = sol.deleteNode(root6, 10);
    cout << "After trying to delete 10: ";
    printTree(root6);
    
    // Test Case 7: Delete from single node tree
    cout << "\nTest Case 7: Delete from single node tree" << endl;
    TreeNode* root7 = createNode(5);
    cout << "Before deletion: ";
    printTree(root7);
    root7 = sol.deleteNode(root7, 5);
    cout << "After deleting 5: ";
    if (!root7) cout << "Tree is empty" << endl;
    else printTree(root7);
    
    // Test Case 8: Delete from empty tree
    cout << "\nTest Case 8: Delete from empty tree" << endl;
    TreeNode* root8 = nullptr;
    cout << "Before deletion: Tree is empty" << endl;
    root8 = sol.deleteNode(root8, 5);
    cout << "After trying to delete 5: ";
    if (!root8) cout << "Tree is still empty" << endl;
    else printTree(root8);
    
    // Test Case 9: Right skewed tree
    cout << "\nTest Case 9: Right skewed tree" << endl;
    TreeNode* root9 = createNode(1);
    root9->right = createNode(2);
    root9->right->right = createNode(3);
    root9->right->right->right = createNode(4);
    
    cout << "Before deletion: ";
    printTree(root9);
    root9 = sol.deleteNode(root9, 2);
    cout << "After deleting 2: ";
    printTree(root9);
    
    // Test Case 10: Left skewed tree
    cout << "\nTest Case 10: Left skewed tree" << endl;
    TreeNode* root10 = createNode(4);
    root10->left = createNode(3);
    root10->left->left = createNode(2);
    root10->left->left->left = createNode(1);
    
    cout << "Before deletion: ";
    printTree(root10);
    root10 = sol.deleteNode(root10, 3);
    cout << "After deleting 3: ";
    printTree(root10);
}

int main() {
    runTests();
    return 0;
}