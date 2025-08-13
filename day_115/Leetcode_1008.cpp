// 1008. Construct Binary Search Tree from Preorder Traversal

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- We process each node exactly once
- Each node is visited only once during the construction
- The recursive approach has a time complexity of O(n)

SPACE COMPLEXITY: O(n) in the worst case (skewed tree)
- The recursion stack can go up to O(n) in the worst case
- For a balanced tree, space complexity would be O(log n)
*/

/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements 
for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value 
strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, 
then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]
 
Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
private:
    // Helper function to build BST from preorder traversal with bounds
    // i: current index in preorder array (passed by reference to maintain position)
    // mini: minimum value allowed for current subtree (exclusive)
    // maxi: maximum value allowed for current subtree (exclusive)
    TreeNode* buildBst(vector<int>& preorder, int &i, long mini, long maxi) {
        // Base case: if we've processed all elements or current value is out of bounds
        if (i >= preorder.size() || preorder[i] >= maxi || preorder[i] <= mini) {
            return nullptr;
        }
        
        // Create root node with current value and move to next element
        TreeNode* root = new TreeNode(preorder[i++]);
        
        // Recursively build left and right subtrees with updated bounds
        // Left subtree must have values between (mini, root->val)
        root->left = buildBst(preorder, i, mini, root->val);
        // Right subtree must have values between (root->val, maxi)
        root->right = buildBst(preorder, i, root->val, maxi);
        
        return root;
    }
    
public:
    // Main function to construct BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0; // Start from the first element
        // Use LONG_MIN and LONG_MAX as initial bounds to handle edge cases
        return buildBst(preorder, i, LONG_MIN, LONG_MAX);
    }
    
    /* Alternative approach (commented out):
    // Helper function to insert a value into BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
    
    // Alternative implementation using insert operation
    TreeNode* bstFromPreorderAlt(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            insertIntoBST(root, preorder[i]);
        }
        return root;
    }
    */
};

// Helper function to create a level order traversal string (for testing)
string levelOrderToString(TreeNode* root) {
    if (!root) return "[]";
    
    string result = "[";
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (!node) {
            result += "null, ";
            continue;
        }
        
        result += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    
    // Remove trailing comma and space if they exist
    if (result.size() > 1) {
        result = result.substr(0, result.size() - 2);
    }
    
    result += "]";
    return result;
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
    
    // Test case 1: Example from problem statement
    {
        vector<int> preorder = {8, 5, 1, 7, 10, 12};
        TreeNode* root = solution.bstFromPreorder(preorder);
        string result = levelOrderToString(root);
        cout << "Test 1: " << (result == "[8, 5, 10, 1, 7, null, 12]" ? "PASSED" : "FAILED")
             << " (Expected: [8,5,10,1,7,null,12], Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 2: Simple two-node tree
    {
        vector<int> preorder = {1, 3};
        TreeNode* root = solution.bstFromPreorder(preorder);
        string result = levelOrderToString(root);
        cout << "Test 2: " << (result == "[1, null, 3]" ? "PASSED" : "FAILED")
             << " (Expected: [1,null,3], Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 3: Single node
    {
        vector<int> preorder = {5};
        TreeNode* root = solution.bstFromPreorder(preorder);
        string result = levelOrderToString(root);
        cout << "Test 3: " << (result == "[5]" ? "PASSED" : "FAILED")
             << " (Expected: [5], Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 4: Right-skewed tree
    {
        vector<int> preorder = {1, 2, 3, 4, 5};
        TreeNode* root = solution.bstFromPreorder(preorder);
        string result = levelOrderToString(root);
        cout << "Test 4: " << (result == "[1, null, 2, null, 3, null, 4, null, 5]" ? "PASSED" : "FAILED")
             << " (Expected: [1,null,2,null,3,null,4,null,5], Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 5: Left-skewed tree
    {
        vector<int> preorder = {5, 4, 3, 2, 1};
        TreeNode* root = solution.bstFromPreorder(preorder);
        string result = levelOrderToString(root);
        cout << "Test 5: " << (result == "[5, 4, null, 3, null, 2, null, 1]" ? "PASSED" : "FAILED")
             << " (Expected: [5,4,null,3,null,2,null,1], Got: " << result << ")\n";
        deleteTree(root);
    }
}

int main() {
    runTests();
    return 0;
}