// 701. Insert into a Binary Search Tree
// Link - https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

#include <iostream>
#include <queue>
using namespace std;

/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. 
You can return any of them.

Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]

Example 2:
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:
Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]

Constraints:
- The number of nodes in the tree will be in the range [0, 10^4].
- -10^8 <= Node.val <= 10^8
- All the values Node.val are unique.
- -10^8 <= val <= 10^8
- It's guaranteed that val does not exist in the original BST.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// Function to print level order traversal
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val;
        if (q.empty() && !curr->left && !curr->right) break;
        cout << ",";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << "]\n";
}

// Driver code
int main() {
    // Building the tree [4,2,7,1,3]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    Solution sol;
    TreeNode* updatedRoot = sol.insertIntoBST(root, val);

    printLevelOrder(updatedRoot); // Should print [4,2,7,1,3,5]

    return 0;
}
