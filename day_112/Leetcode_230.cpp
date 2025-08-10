// 230. Kth Smallest Element in a BST

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- We visit each node exactly once during inorder traversal
- Each node operation takes O(1) time

SPACE COMPLEXITY: O(h) where h is the height of the tree
- Due to recursion stack depth
- In worst case (skewed tree): O(n)
- In best case (balanced tree): O(log n)

ALGORITHM:
1. Perform inorder traversal (left-root-right) of the BST
2. Keep a counter that decrements on each node visit
3. When counter reaches 0, we've found our kth smallest element
4. Early return once the kth element is found
*/

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) 
of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Example 3:
Input: root = [1], k = 1
Output: 1

Example 4:
Input: root = [2,1,3], k = 3
Output: 3

Constraints:
- The number of nodes in the tree is n.
- 1 <= k <= n <= 10^4
- 0 <= Node.val <= 10^4

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find 
the kth smallest frequently, how would you optimize?
*/

#include <iostream>
#include <stack>
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
    // Recursive approach with early termination
    int findKthSmallest(TreeNode* root, int& k) {
        if (!root) return -1;
        
        // Traverse left subtree first
        int left = findKthSmallest(root->left, k);
        if (left != -1) return left;
        
        // Process current node
        k--;
        if (k == 0) return root->val;
        
        // Traverse right subtree
        return findKthSmallest(root->right, k);
    }
    
    // Iterative approach (alternative implementation)
    int kthSmallestIterative(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            // Traverse to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // Process the current node
            curr = st.top();
            st.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return -1; // Shouldn't reach here if k is valid
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        return findKthSmallest(root, k);
        // Alternative: return kthSmallestIterative(root, k);
    }
};

// Helper function to create TreeNode
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

// Test function
void runTests() {
    Solution sol;
    
    cout << "=== KTH SMALLEST ELEMENT IN BST TEST CASES ===" << endl;
    
    // Test Case 1: Simple BST
    cout << "\nTest Case 1: Simple BST" << endl;
    TreeNode* root1 = createNode(3);
    root1->left = createNode(1);
    root1->right = createNode(4);
    root1->left->right = createNode(2);
    cout << "Tree: [3,1,4,null,2], k=1 -> " << sol.kthSmallest(root1, 1) << " (Expected: 1)" << endl;
    
    // Test Case 2: Larger BST
    cout << "\nTest Case 2: Larger BST" << endl;
    TreeNode* root2 = createNode(5);
    root2->left = createNode(3);
    root2->right = createNode(6);
    root2->left->left = createNode(2);
    root2->left->right = createNode(4);
    root2->left->left->left = createNode(1);
    cout << "Tree: [5,3,6,2,4,null,null,1], k=3 -> " << sol.kthSmallest(root2, 3) << " (Expected: 3)" << endl;
    
    // Test Case 3: Right skewed tree
    cout << "\nTest Case 3: Right skewed tree" << endl;
    TreeNode* root3 = createNode(1);
    root3->right = createNode(2);
    root3->right->right = createNode(3);
    cout << "Tree: [1,null,2,null,3], k=2 -> " << sol.kthSmallest(root3, 2) << " (Expected: 2)" << endl;
    
    // Test Case 4: Left skewed tree
    cout << "\nTest Case 4: Left skewed tree" << endl;
    TreeNode* root4 = createNode(3);
    root4->left = createNode(2);
    root4->left->left = createNode(1);
    cout << "Tree: [3,2,null,1], k=3 -> " << sol.kthSmallest(root4, 3) << " (Expected: 3)" << endl;
    
    // Test Case 5: Single node
    cout << "\nTest Case 5: Single node" << endl;
    TreeNode* root5 = createNode(1);
    cout << "Tree: [1], k=1 -> " << sol.kthSmallest(root5, 1) << " (Expected: 1)" << endl;
    
    // Test Case 6: k = number of nodes
    cout << "\nTest Case 6: k = number of nodes" << endl;
    TreeNode* root6 = createNode(2);
    root6->left = createNode(1);
    root6->right = createNode(3);
    cout << "Tree: [2,1,3], k=3 -> " << sol.kthSmallest(root6, 3) << " (Expected: 3)" << endl;
    
    // Test Case 7: k = 1 (smallest element)
    cout << "\nTest Case 7: k = 1 (smallest element)" << endl;
    TreeNode* root7 = createNode(5);
    root7->left = createNode(3);
    root7->right = createNode(7);
    root7->left->left = createNode(1);
    root7->left->right = createNode(4);
    cout << "Tree: [5,3,7,1,4], k=1 -> " << sol.kthSmallest(root7, 1) << " (Expected: 1)" << endl;
}

int main() {
    runTests();
    return 0;
}