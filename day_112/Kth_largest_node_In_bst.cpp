// Kth Largest Element in BST

/*
TIME COMPLEXITY: O(n) where n is the number of nodes in the tree
- We visit each node exactly once during reverse inorder traversal
- Each node operation takes O(1) time

SPACE COMPLEXITY: O(h) where h is the height of the tree
- Due to recursion stack depth
- In worst case (skewed tree): O(n)
- In best case (balanced tree): O(log n)

ALGORITHM:
1. Perform reverse inorder traversal (right-root-left) of the BST
2. Keep a counter that decrements on each node visit
3. When counter reaches 0, we've found our kth largest element
4. Early return once the kth element is found
*/

/*
Given a Binary Search Tree. Your task is to complete the function which will return the kth largest element without doing any modification in the Binary Search Tree.

Examples:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4
Explanation: 2nd Largest element in BST is 4

Input:
       9
        \ 
          10
k = 1
Output: 10
Explanation: 1st Largest element in BST is 10

Input:
      4
    /   \
   2     9
k = 3 
Output: 2
Explanation: 3rd Largest element in BST is 2

Constraints:
1 <= number of nodes <= 10^5
1 <= node->data <= 10^5
1 <= k <= number of nodes
*/

#include <iostream>
using namespace std;

// The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    int findKthLargest(Node* root, int& k) {
        if (!root) return -1;
        
        // Traverse right subtree first (reverse inorder)
        int right = findKthLargest(root->right, k);
        if (right != -1) return right;
        
        // Process current node
        k--;
        if (k == 0) return root->data;
        
        // Traverse left subtree
        return findKthLargest(root->left, k);
    }
    
public:
    int kthLargest(Node *root, int k) {
        return findKthLargest(root, k);
    }
};

// Helper function to create Node
Node* createNode(int val) {
    return new Node(val);
}

// Test function
void runTests() {
    Solution sol;
    
    cout << "=== KTH LARGEST ELEMENT IN BST TEST CASES ===" << endl;
    
    // Test Case 1: Small BST
    cout << "\nTest Case 1: Small BST" << endl;
    Node* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(9);
    cout << "Tree: [4,2,9], k=2 -> " << sol.kthLargest(root1, 2) << " (Expected: 4)" << endl;
    
    // Test Case 2: Right skewed tree
    cout << "\nTest Case 2: Right skewed tree" << endl;
    Node* root2 = createNode(9);
    root2->right = createNode(10);
    cout << "Tree: [9,null,10], k=1 -> " << sol.kthLargest(root2, 1) << " (Expected: 10)" << endl;
    
    // Test Case 3: Left skewed tree
    cout << "\nTest Case 3: Left skewed tree" << endl;
    Node* root3 = createNode(9);
    root3->left = createNode(7);
    root3->left->left = createNode(5);
    cout << "Tree: [9,7,null,5], k=3 -> " << sol.kthLargest(root3, 3) << " (Expected: 9)" << endl;
    
    // Test Case 4: Larger BST
    cout << "\nTest Case 4: Larger BST" << endl;
    Node* root4 = createNode(10);
    root4->left = createNode(5);
    root4->right = createNode(15);
    root4->left->left = createNode(2);
    root4->left->right = createNode(7);
    root4->right->left = createNode(12);
    root4->right->right = createNode(20);
    cout << "Tree: [10,5,15,2,7,12,20], k=3 -> " << sol.kthLargest(root4, 3) << " (Expected: 12)" << endl;
    
    // Test Case 5: Single node
    cout << "\nTest Case 5: Single node" << endl;
    Node* root5 = createNode(1);
    cout << "Tree: [1], k=1 -> " << sol.kthLargest(root5, 1) << " (Expected: 1)" << endl;
    
    // Test Case 6: k = number of nodes
    cout << "\nTest Case 6: k = number of nodes" << endl;
    Node* root6 = createNode(4);
    root6->left = createNode(2);
    root6->right = createNode(6);
    cout << "Tree: [4,2,6], k=3 -> " << sol.kthLargest(root6, 3) << " (Expected: 2)" << endl;
    
    // Test Case 7: k = 1 (largest element)
    cout << "\nTest Case 7: k = 1 (largest element)" << endl;
    Node* root7 = createNode(8);
    root7->left = createNode(4);
    root7->right = createNode(12);
    root7->right->left = createNode(10);
    root7->right->right = createNode(14);
    cout << "Tree: [8,4,12,null,null,10,14], k=1 -> " << sol.kthLargest(root7, 1) << " (Expected: 14)" << endl;
}

int main() {
    runTests();
    return 0;
}