//109. Convert Sorted List to Binary Search Tree

// link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        // Find the middle node
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half from mid
        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        if (head != slow)  // avoid infinite recursion
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

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
    bool first = true;
    while (!q.empty()) {
        TreeNode* curr = q.front(); 
        q.pop();
        if (!first) cout << ",";
        if (curr) {
            cout << curr->val;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null";
        }
        first = false;
    }
    cout << "]\n";
}

// Helper function to create linked list from array
ListNode* createLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Driver code
int main() {
    // Test case 1: [-10,-3,0,5,9]
    vector<int> arr1 = {-10, -3, 0, 5, 9};
    ListNode* head1 = createLinkedList(arr1);
    
    Solution sol;
    TreeNode* result1 = sol.sortedListToBST(head1);
    
    cout << "Input: [-10,-3,0,5,9]\n";
    cout << "Output: ";
    printLevelOrder(result1);
    cout << endl;
    
    // Test case 2: []
    vector<int> arr2 = {};
    ListNode* head2 = createLinkedList(arr2);
    TreeNode* result2 = sol.sortedListToBST(head2);
    
    cout << "Input: []\n";
    cout << "Output: ";
    printLevelOrder(result2);
    
    return 0;
}