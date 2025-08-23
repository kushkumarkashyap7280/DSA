// 958. Check Completeness of a Binary Tree
//  Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

/*
Problem Description:
Given the root of a binary tree, determine if it is a complete binary tree.
A complete binary tree has all levels fully filled except possibly the last level,
and in the last level, all nodes are as far left as possible.

Time Complexity: O(N), where N is the number of nodes in the tree
- sizeOfTree: O(N) to count all nodes
- solve: O(N) to visit each node once

Space Complexity: O(H), where H is the height of the tree
- Recursion stack space for both sizeOfTree and solve functions
- In worst case (skewed tree): O(N)
- In best case (complete/perfect tree): O(log N)

Example Test Cases:

1. Complete Binary Tree:
        1
       / \
      2   3
     / \  /
    4   5 6
Input: [1,2,3,4,5,6]
Output: true
Explanation: All nodes in last level are towards left

2. Incomplete Binary Tree:
        1
       / \
      2   3
     / \   \
    4   5   7
Input: [1,2,3,4,5,null,7]
Output: false
Explanation: Node 7 should be towards left

3. Single Node:
        1
Input: [1]
Output: true
Explanation: Single node is always complete

4. Perfect Binary Tree:
        1
       / \
      2   3
     / \ / \
    4  5 6  7
Input: [1,2,3,4,5,6,7]
Output: true
Explanation: All levels are completely filled

5. Edge Case - Empty Tree:
Input: []
Output: true
Explanation: Empty tree is considered complete

Approach:
1. Get total size of tree using sizeOfTree function
2. Use array index property of complete binary trees:
   - For node at index i:
   - Left child is at 2i + 1
   - Right child is at 2i + 2
3. If any index >= total size, tree is not complete
*/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
  bool solve(TreeNode *root, int index, int size)
  {
    if (!root)
      return true;
    if (index >= size)
      return false;

    // Check left and right subtrees
    if (!solve(root->left, index * 2 + 1, size))
      return false;
    if (!solve(root->right, index * 2 + 2, size))
      return false;
    return true;
  }

  int sizeOfTree(TreeNode *root)
  {
    if (!root)
      return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
  }

public:
  bool isCompleteTree(TreeNode *root)
  {
    if (!root)
      return true;
    int s = sizeOfTree(root);
    return solve(root, 0, s);
  }

  // Helper function to create a tree from level-order array
  static TreeNode *createTree(vector<int> &arr, int i = 0)
  {
    if (i >= arr.size() || arr[i] == -1)
      return nullptr; // -1 represents null

    TreeNode *root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
  }
};

// Test function
void runTest(vector<int> input, bool expected)
{
  Solution sol;
  TreeNode *root = Solution::createTree(input);
  bool result = sol.isCompleteTree(root);

  cout << "Input: [";
  for (int i = 0; i < input.size(); i++)
  {
    if (i > 0)
      cout << ",";
    if (input[i] == -1)
      cout << "null";
    else
      cout << input[i];
  }
  cout << "]\n";

  cout << "Expected: " << (expected ? "true" : "false") << "\n";
  cout << "Output: " << (result ? "true" : "false") << "\n";
  cout << "Test " << (result == expected ? "PASSED" : "FAILED") << "\n\n";
}

int main()
{
  // Test Case 1: Complete Binary Tree
  vector<int> test1 = {1, 2, 3, 4, 5, 6};
  runTest(test1, true);

  // Test Case 2: Incomplete Binary Tree
  vector<int> test2 = {1, 2, 3, 4, 5, -1, 7}; // -1 represents null
  runTest(test2, false);

  // Test Case 3: Single Node
  vector<int> test3 = {1};
  runTest(test3, true);

  // Test Case 4: Perfect Binary Tree
  vector<int> test4 = {1, 2, 3, 4, 5, 6, 7};
  runTest(test4, true);

  // Test Case 5: Incomplete at last level but not left-aligned
  vector<int> test5 = {1, 2, 3, 4, -1, 6};
  runTest(test5, false);

  return 0;
}