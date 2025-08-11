// 653. Two Sum IV - Input is a BST

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- Morris traversal takes O(n) time to create a sorted array
- Two-pointer approach takes O(n) time in the worst case
- Overall time complexity is O(n)

SPACE COMPLEXITY: O(n)
- We store all node values in a vector
- Morris traversal uses O(1) extra space, but the vector requires O(n) space
*/

/*
Given the root of a binary search tree and an integer k, 
return true if there exist two elements in the BST such that their sum is equal to k, 
or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Explanation: 5 + 4 = 9

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
- The number of nodes in the tree is in the range [1, 10^4].
- -10^4 <= Node.val <= 10^4
- root is guaranteed to be a valid binary search tree.
- -10^5 <= k <= 10^5
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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        // Step 1: Perform Morris Inorder Traversal to get sorted values
        vector<int> values;
        TreeNode* current = root;
        
        while (current) {
            if (!current->left) {
                values.push_back(current->val);
                current = current->right;
            } else {
                // Find the inorder predecessor
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                
                if (!predecessor->right) {
                    // Set right pointer to current (temporary link)
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Revert the temporary link
                    predecessor->right = nullptr;
                    values.push_back(current->val);
                    current = current->right;
                }
            }
        }
        
        // Step 2: Use two pointers to find if two numbers sum to k
        int left = 0;
        int right = values.size() - 1;
        
        while (left < right) {
            int sum = values[left] + values[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        
        return false;
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
        vector<int> values = {5, 3, 6, 2, 4, -1, 7};
        TreeNode* root = createTree(values);
        int k = 9;
        bool result = solution.findTarget(root, k);
        cout << "Test 1: " << (result ? "PASSED" : "FAILED")
             << " (Expected: true, Got: " << (result ? "true" : "false") << ")\n";
        deleteTree(root);
    }
    
    // Test case 2
    {
        vector<int> values = {5, 3, 6, 2, 4, -1, 7};
        TreeNode* root = createTree(values);
        int k = 28;
        bool result = solution.findTarget(root, k);
        cout << "Test 2: " << (!result ? "PASSED" : "FAILED")
             << " (Expected: false, Got: " << (result ? "true" : "false") << ")\n";
        deleteTree(root);
    }
    
    // Test case 3: Single node
    {
        TreeNode* root = new TreeNode(1);
        int k = 2;
        bool result = solution.findTarget(root, k);
        cout << "Test 3: " << (!result ? "PASSED" : "FAILED")
             << " (Expected: false, Got: " << (result ? "true" : "false") << ")\n";
        delete root;
    }
    
    // Test case 4: Two nodes that sum to target
    {
        TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
        int k = 4;
        bool result = solution.findTarget(root, k);
        cout << "Test 4: " << (result ? "PASSED" : "FAILED")
             << " (Expected: true, Got: " << (result ? "true" : "false") << ")\n";
        delete root->left;
        delete root->right;
        delete root;
    }
}

int main() {
    runTests();
    return 0;
}