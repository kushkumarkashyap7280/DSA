//108. Convert Sorted Array to Binary Search Tree

// link -https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/


/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#include <iostream>
#include <vector>
#include <queue>
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
    // time complexity O(n)
    // space complexity O(n)
    TreeNode* makeBst(vector<int>& nums, int i ,int j){
        if(i > j) return nullptr;
         int m = i + (j-i)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = makeBst(nums, i , m-1);
        root->right = makeBst(nums, m+1 , j);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return makeBst(nums , 0 , nums.size()-1);
    }
};



// Helper function to print tree in level order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    
    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }
    
    // Remove trailing nulls
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    
    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
}

// Helper function to delete tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Solution sol;
    
    // Test Case 1: Example 1 from problem statement
    {
        cout << "Test Case 1: [-10,-3,0,5,9]\n";
        vector<int> nums1 = {-10, -3, 0, 5, 9};
        TreeNode* result1 = sol.sortedArrayToBST(nums1);
        cout << "Output: ";
        printLevelOrder(result1);
        cout << "\n";
        deleteTree(result1);
    }
    
    // Test Case 2: Example 2 from problem statement
    {
        cout << "Test Case 2: [1,3]\n";
        vector<int> nums2 = {1, 3};
        TreeNode* result2 = sol.sortedArrayToBST(nums2);
        cout << "Output: ";
        printLevelOrder(result2);
        cout << "\n";
        deleteTree(result2);
    }
    
    // Test Case 3: Single element
    {
        cout << "Test Case 3: [5]\n";
        vector<int> nums3 = {5};
        TreeNode* result3 = sol.sortedArrayToBST(nums3);
        cout << "Output: ";
        printLevelOrder(result3);
        cout << "\n";
        deleteTree(result3);
    }
    
    // Test Case 4: Even number of elements
    {
        cout << "Test Case 4: [1,2,3,4,5,6,7,8]\n";
        vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8};
        TreeNode* result4 = sol.sortedArrayToBST(nums4);
        cout << "Output: ";
        printLevelOrder(result4);
        cout << "\n";
        deleteTree(result4);
    }
    
    // Test Case 5: Large range
    {
        cout << "Test Case 5: [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]\n";
        vector<int> nums5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        TreeNode* result5 = sol.sortedArrayToBST(nums5);
        cout << "Output: ";
        printLevelOrder(result5);
        cout << "\n";
        deleteTree(result5);
    }
    
    return 0;
}