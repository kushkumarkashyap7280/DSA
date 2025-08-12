// 1382. Balance a Binary Search Tree

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- Morris traversal takes O(n) time to create a sorted array
- Building a balanced BST from sorted array takes O(n) time
- Overall time complexity is O(n)

SPACE COMPLEXITY: O(n)
- We store all node pointers in a vector
- Morris traversal uses O(1) extra space, but the vector requires O(n) space
*/

/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]

Constraints:
- The number of nodes in the tree is in the range [1, 10^4].
- 1 <= Node.val <= 10^5
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
    TreeNode* buildBalanced(vector<TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        root->left = buildBalanced(nodes, start, mid - 1);
        root->right = buildBalanced(nodes, mid + 1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        
        // Morris inorder traversal to get sorted nodes
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                nodes.push_back(curr);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                if (temp->right == curr) {
                    temp->right = nullptr;
                    nodes.push_back(curr);
                    curr = curr->right;
                } else {
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        
        return buildBalanced(nodes, 0, nodes.size() - 1);
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

// Helper function to print tree in level order (for testing)
void printTree(TreeNode* root) {
    if (!root) return;
    
    vector<TreeNode*> current, next;
    current.push_back(root);
    
    while (!current.empty()) {
        for (TreeNode* node : current) {
            if (node) {
                cout << node->val << " ";
                next.push_back(node->left);
                next.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
        current.clear();
        swap(current, next);
    }
}

// Test function
void runTests() {
    Solution solution;
    
    // Test case 1: Skewed tree
    {
        cout << "Test Case 1: Skewed tree\n";
        vector<int> values = {1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4};
        TreeNode* root = createTree(values);
        cout << "Original tree (level order):\n";
        printTree(root);
        
        TreeNode* balanced = solution.balanceBST(root);
        cout << "\nBalanced tree (level order):\n";
        printTree(balanced);
        
        deleteTree(balanced); // Clean up
        cout << "----------------------------------------\n";
    }
    
    // Test case 2: Already balanced tree
    {
        cout << "Test Case 2: Already balanced tree\n";
        vector<int> values = {2, 1, 3};
        TreeNode* root = createTree(values);
        cout << "Original tree (level order):\n";
        printTree(root);
        
        TreeNode* balanced = solution.balanceBST(root);
        cout << "\nBalanced tree (level order):\n";
        printTree(balanced);
        
        deleteTree(balanced); // Clean up
        cout << "----------------------------------------\n";
    }
    
    // Test case 3: Single node
    {
        cout << "Test Case 3: Single node\n";
        vector<int> values = {1};
        TreeNode* root = createTree(values);
        cout << "Original tree (level order):\n";
        printTree(root);
        
        TreeNode* balanced = solution.balanceBST(root);
        cout << "\nBalanced tree (level order):\n";
        printTree(balanced);
        
        deleteTree(balanced); // Clean up
    }
}

int main() {
    runTests();
    return 0;
}