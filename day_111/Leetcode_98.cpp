//98. Validate Binary Search Tree

// link - https://leetcode.com/problems/validate-binary-search-tree/description/

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- We visit each node exactly once during inorder traversal
- Each node operation takes O(1) time

SPACE COMPLEXITY: O(h) where h is the height of the tree
- Due to recursion stack depth
- In worst case (skewed tree): O(n)
- In best case (balanced tree): O(log n)
- Additional O(1) space for the previous node pointer

ALGORITHM:
1. Perform inorder traversal of the BST
2. In a valid BST, inorder traversal should give nodes in strictly increasing order
3. Keep track of previous node and compare with current node
4. If current node value <= previous node value, it's not a valid BST
*/

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/


#include <iostream>
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
    bool inorder(TreeNode* root, TreeNode*& prev) {
        if (!root) return true;

        if (!inorder(root->left, prev)) return false;

        if (prev && root->val <= prev->val) return false;
        prev = root;

        return inorder(root->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }
};

// Helper function to create TreeNode
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Test function
void runTests() {
    Solution sol;
    
    cout << "=== VALIDATE BST TEST CASES ===" << endl;
    
    // Test Case 1: Valid BST
    cout << "\nTest Case 1: Valid BST" << endl;
    TreeNode* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);
    cout << "Tree: [2,1,3] -> " << (sol.isValidBST(root1) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 2: Invalid BST (right child smaller than root)
    cout << "\nTest Case 2: Invalid BST (right child smaller than root)" << endl;
    TreeNode* root2 = createNode(5);
    root2->left = createNode(1);
    root2->right = createNode(4);
    root2->right->left = createNode(3);
    root2->right->right = createNode(6);
    cout << "Tree: [5,1,4,null,null,3,6] -> " << (sol.isValidBST(root2) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 3: Single node (always valid)
    cout << "\nTest Case 3: Single node" << endl;
    TreeNode* root3 = createNode(1);
    cout << "Tree: [1] -> " << (sol.isValidBST(root3) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 4: Valid larger BST
    cout << "\nTest Case 4: Valid larger BST" << endl;
    TreeNode* root4 = createNode(5);
    root4->left = createNode(3);
    root4->right = createNode(8);
    root4->left->left = createNode(2);
    root4->left->right = createNode(4);
    root4->right->left = createNode(7);
    root4->right->right = createNode(9);
    cout << "Tree: [5,3,8,2,4,7,9] -> " << (sol.isValidBST(root4) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 5: Invalid BST (duplicate values)
    cout << "\nTest Case 5: Invalid BST (duplicate values)" << endl;
    TreeNode* root5 = createNode(5);
    root5->left = createNode(3);
    root5->right = createNode(5);
    cout << "Tree: [5,3,5] -> " << (sol.isValidBST(root5) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 6: Invalid BST (left subtree has value greater than root)
    cout << "\nTest Case 6: Invalid BST (left subtree violation)" << endl;
    TreeNode* root6 = createNode(5);
    root6->left = createNode(3);
    root6->right = createNode(8);
    root6->left->right = createNode(6); // 6 > 5, violates BST property
    cout << "Tree: [5,3,8,null,6] -> " << (sol.isValidBST(root6) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 7: Invalid BST (right subtree has value smaller than root)
    cout << "\nTest Case 7: Invalid BST (right subtree violation)" << endl;
    TreeNode* root7 = createNode(5);
    root7->left = createNode(3);
    root7->right = createNode(8);
    root7->right->left = createNode(4); // 4 < 5, violates BST property
    cout << "Tree: [5,3,8,4] -> " << (sol.isValidBST(root7) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 8: Right skewed valid BST
    cout << "\nTest Case 8: Right skewed valid BST" << endl;
    TreeNode* root8 = createNode(1);
    root8->right = createNode(2);
    root8->right->right = createNode(3);
    root8->right->right->right = createNode(4);
    cout << "Tree: [1,null,2,null,3,null,4] -> " << (sol.isValidBST(root8) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 9: Left skewed valid BST
    cout << "\nTest Case 9: Left skewed valid BST" << endl;
    TreeNode* root9 = createNode(4);
    root9->left = createNode(3);
    root9->left->left = createNode(2);
    root9->left->left->left = createNode(1);
    cout << "Tree: [4,3,null,2,null,1] -> " << (sol.isValidBST(root9) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 10: Edge case with negative values
    cout << "\nTest Case 10: BST with negative values" << endl;
    TreeNode* root10 = createNode(0);
    root10->left = createNode(-1);
    root10->right = createNode(1);
    cout << "Tree: [0,-1,1] -> " << (sol.isValidBST(root10) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 11: Invalid BST with negative values
    cout << "\nTest Case 11: Invalid BST with negative values" << endl;
    TreeNode* root11 = createNode(-1);
    root11->left = createNode(-3);
    root11->right = createNode(-2);
    root11->right->left = createNode(-4); // -4 < -1, violates BST property
    cout << "Tree: [-1,-3,-2,-4] -> " << (sol.isValidBST(root11) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 12: Two nodes - valid
    cout << "\nTest Case 12: Two nodes - valid" << endl;
    TreeNode* root12 = createNode(1);
    root12->left = createNode(0);
    cout << "Tree: [1,0] -> " << (sol.isValidBST(root12) ? "Valid BST" : "Invalid BST") << endl;
    
    // Test Case 13: Two nodes - invalid
    cout << "\nTest Case 13: Two nodes - invalid" << endl;
    TreeNode* root13 = createNode(1);
    root13->left = createNode(2);
    cout << "Tree: [1,2] -> " << (sol.isValidBST(root13) ? "Valid BST" : "Invalid BST") << endl;
}

int main() {
    runTests();
    return 0;
}