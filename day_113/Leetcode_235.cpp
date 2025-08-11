// 235. Lowest Common Ancestor of a Binary Search Tree

/*
TIME COMPLEXITY: O(h) where h is the height of the tree
- In the worst case, we traverse from root to the deepest leaf
- For a balanced BST, h = log(n)
- For a skewed BST, h = n

SPACE COMPLEXITY: O(1)
- Uses constant extra space as we're using an iterative approach
*/

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:
- The number of nodes in the tree is in the range [2, 10^5].
- -10^9 <= Node.val <= 10^9
- All Node.val are unique.
- p != q
- p and q will exist in the BST.
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Iterative approach - O(h) time, O(1) space
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both p and q are greater than root, then LCA lies in right subtree
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } 
            // If both p and q are smaller than root, then LCA lies in left subtree
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } 
            // We have found the split point, i.e. the LCA node
            else {
                return root;
            }
        }
        return nullptr;
    }
};

// Helper function to create a binary tree from an array (for testing)
TreeNode* createTree(const vector<int>& values, int index = 0) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Helper function to find a node with given value in the tree
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    
    return findNode(root->right, val);
}

// Helper function to delete the tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Test function
void runTests() {
    Solution solution;
    
    // Test case 1
    {
        vector<int> values = {6,2,8,0,4,7,9,-1,-1,3,5};
        TreeNode* root = createTree(values);
        TreeNode* p = findNode(root, 2);
        TreeNode* q = findNode(root, 8);
        TreeNode* result = solution.lowestCommonAncestor(root, p, q);
        cout << "Test 1: " << (result && result->val == 6 ? "PASSED" : "FAILED")
             << " (Expected: 6, Got: " << (result ? to_string(result->val) : "null") << ")\n";
        deleteTree(root);
    }
    
    // Test case 2
    {
        vector<int> values = {6,2,8,0,4,7,9,-1,-1,3,5};
        TreeNode* root = createTree(values);
        TreeNode* p = findNode(root, 2);
        TreeNode* q = findNode(root, 4);
        TreeNode* result = solution.lowestCommonAncestor(root, p, q);
        cout << "Test 2: " << (result && result->val == 2 ? "PASSED" : "FAILED")
             << " (Expected: 2, Got: " << (result ? to_string(result->val) : "null") << ")\n";
        deleteTree(root);
    }
    
    // Test case 3: Single node
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        TreeNode* p = root;  // 2
        TreeNode* q = root->left;  // 1
        TreeNode* result = solution.lowestCommonAncestor(root, p, q);
        cout << "Test 3: " << (result && result->val == 2 ? "PASSED" : "FAILED")
             << " (Expected: 2, Got: " << (result ? to_string(result->val) : "null") << ")\n";
        delete root->left;
        delete root;
    }
}

int main() {
    runTests();
    return 0;
}