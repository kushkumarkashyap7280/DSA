//Minimum element in BST  

// link -https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/*
Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Examples

Input: root = [5, 4, 6, 3, N, N, 7, 1]
ex-1
Output: 1
Input: root = [10, 5, 20, 2]
ex-2
Output: 2
Input: root = [10, N, 10, N, 11]
             10
              \
               10
                \
                 11
Output: 10
Constraints:
0 <= number of nodes <= 105
0 <= node->data <= 105
*/

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return -1;
       while(root->left) root = root->left;
       return root->data;
    }
    int maxValue(Node*root){
        if(!root) return -1;
        while(root->right) root = root->right;
        return root->data;
    }
};


int main(){
    // Create test BST from example 1: [5, 4, 6, 3, N, N, 7, 1]
    //       5
    //      / \
    //     4   6
    //    /     \
    //   3       7
    //  /
    // 1
    Node* root1 = newNode(5);
    root1->left = newNode(4);
    root1->right = newNode(6);
    root1->left->left = newNode(3);
    root1->right->right = newNode(7);
    root1->left->left->left = newNode(1);
    
    Solution sol;
    cout << "Test Case 1:" << endl;
    cout << "BST: [5, 4, 6, 3, N, N, 7, 1]" << endl;
    cout << "Minimum value: " << sol.minValue(root1) << endl;
    cout << "Maximum value: " << sol.maxValue(root1) << endl << endl;
    
    // Create test BST from example 2: [10, 5, 20, 2]
    //      10
    //     /  \
    //    5    20
    //   /
    //  2
    Node* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(20);
    root2->left->left = newNode(2);
    
    cout << "Test Case 2:" << endl;
    cout << "BST: [10, 5, 20, 2]" << endl;
    cout << "Minimum value: " << sol.minValue(root2) << endl;
    cout << "Maximum value: " << sol.maxValue(root2) << endl << endl;
    
    // Create test BST from example 3: [10, N, 10, N, 11]
    //  10
    //   \
    //    10
    //     \
    //      11
    Node* root3 = newNode(10);
    root3->right = newNode(10);
    root3->right->right = newNode(11);
    
    cout << "Test Case 3:" << endl;
    cout << "BST: [10, N, 10, N, 11]" << endl;
    cout << "Minimum value: " << sol.minValue(root3) << endl;
    cout << "Maximum value: " << sol.maxValue(root3) << endl << endl;
    
    // Test with empty tree
    cout << "Test Case 4 (Empty tree):" << endl;
    cout << "Minimum value: " << sol.minValue(nullptr) << endl;
    cout << "Maximum value: " << sol.maxValue(nullptr) << endl;
    
    return 0;
}

