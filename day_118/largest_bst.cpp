// Largest BST

// link - https://www.geeksforgeeks.org/problems/largest-bst/1

/*
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct info{
    int maxi ;
    int mini ;
    int size ;
    bool isBst;
};

class Solution {
      info solve(Node* root , int &ans){
          if(!root){
             return {INT_MIN, INT_MAX, 0, true};
          }
          
          info l = solve(root->left , ans);
          info r = solve(root->right , ans);
    
            info currNode;
            currNode.size = l.size + r.size + 1;
            currNode.maxi = max(root->data , r.maxi);
            currNode.mini = min(root->data , l.mini);
            currNode.isBst = l.maxi < root->data && r.mini > root->data  && l.isBst && r.isBst;
           if(currNode.isBst){
               ans  = max(ans , currNode.size);
           }
           return currNode;
      }
   
  public:
    // time complexity O(n)
    // space complexity O(h) for recursion stack
    int largestBst(Node *root) {
         int maxBst = 0;
         solve(root , maxBst);
        return maxBst;
    }
};

// Helper: insert into BST (for building quick test trees)
Node* insertBST(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Helper: delete tree
void deleteTree(Node* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    // Test 1: mixed tree where largest BST is a subtree
    Node* root1 = new Node(5);
    root1->left = new Node(2);
    root1->right = new Node(4); // violates BST at root
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);

    Solution sol;
    cout << "Largest BST size (Test 1): " << sol.largestBst(root1) << "\n"; // expected 3

    // Test 2: a valid BST
    Node* root2 = nullptr;
    for(int v : {6,3,8,2,5,7,9}) root2 = insertBST(root2, v);
    cout << "Largest BST size (Test 2): " << sol.largestBst(root2) << "\n"; // expected 7

    deleteTree(root1);
    deleteTree(root2);
    return 0;
}