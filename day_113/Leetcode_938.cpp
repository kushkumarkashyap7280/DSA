// 938. Range Sum of BST

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- We visit each node exactly once in the worst case
- Each node operation takes O(1) time

SPACE COMPLEXITY: O(1) - Morris Traversal approach
- Uses constant extra space (no recursion stack or queue)
- Only uses a few pointers for traversal
*/

/*
Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].

Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

Constraints:
- The number of nodes in the tree is in the range [1, 2 * 10^4].
- 1 <= Node.val <= 10^5
- 1 <= low <= high <= 10^5
- All Node.val are unique.
*/

#include <iostream>
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
    // Morris Traversal approach - O(1) space
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        int sum = 0;
        while (root) {
            if (!root->left) {
                // Process current node
                if (root->val >= low && root->val <= high) {
                    sum += root->val;
                }
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                while (temp->right && temp->right != root) {
                    temp = temp->right;
                }
                
                if (temp->right == root) {
                    temp->right = nullptr;
                    // Process current node
                    if (root->val >= low && root->val <= high) {
                        sum += root->val;
                    }
                    root = root->right;
                } else {
                    temp->right = root;
                    root = root->left;
                }
            }
        }
        return sum;
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
        vector<int> values = {10,5,15,3,7,-1,18};
        TreeNode* root = createTree(values);
        int result = solution.rangeSumBST(root, 7, 15);
        cout << "Test 1: " << (result == 32 ? "PASSED" : "FAILED") 
             << " (Expected: 32, Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 2
    {
        vector<int> values = {10,5,15,3,7,13,18,1,-1,6};
        TreeNode* root = createTree(values);
        int result = solution.rangeSumBST(root, 6, 10);
        cout << "Test 2: " << (result == 23 ? "PASSED" : "FAILED")
             << " (Expected: 23, Got: " << result << ")\n";
        deleteTree(root);
    }
    
    // Test case 3: Single node
    {
        TreeNode* root = new TreeNode(5);
        int result = solution.rangeSumBST(root, 5, 5);
        cout << "Test 3: " << (result == 5 ? "PASSED" : "FAILED")
             << " (Expected: 5, Got: " << result << ")\n";
        delete root;
    }
}

int main() {
    runTests();
    return 0;
}