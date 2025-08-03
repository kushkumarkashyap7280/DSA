// 106. Construct Binary Tree from Inorder and Postorder Traversal

// link -https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
  TreeNode *solve(vector<int> &inorder, int il, int ir,
                  vector<int> &postorder, int pl, int pr)
  {
    if (pl > pr || il > ir)
      return nullptr;

    int node = postorder[pr]; // root is last in postorder
    TreeNode *temp = new TreeNode(node);

    // find root index in inorder
    int index = il;
    while (index <= ir && inorder[index] != node)
      index++;

    int leftSize = index - il;

    // build left
    temp->left = solve(inorder, il, index - 1,
                       postorder, pl, pl + leftSize - 1);

    // build right
    temp->right = solve(inorder, index + 1, ir,
                        postorder, pl + leftSize, pr - 1);

    return temp;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    return solve(inorder, 0, inorder.size() - 1,
                 postorder, 0, postorder.size() - 1);
  }
};

// Helper function to print tree in level order (for testing)
void printTree(TreeNode *root)
{
  if (!root)
  {
    cout << "null" << endl;
    return;
  }

  vector<TreeNode *> q = {root};
  while (!q.empty())
  {
    TreeNode *curr = q[0];
    q.erase(q.begin());

    if (curr)
    {
      cout << curr->val << " ";
      q.push_back(curr->left);
      q.push_back(curr->right);
    }
    else
    {
      cout << "null ";
    }
  }
  cout << endl;
}

// Test cases and complexity analysis
int main()
{
  Solution sol;

  // Test Case 1: Example from problem
  vector<int> inorder1 = {9, 3, 15, 20, 7};
  vector<int> postorder1 = {9, 15, 7, 20, 3};
  cout << "Test Case 1:" << endl;
  cout << "Inorder: [9, 3, 15, 20, 7]" << endl;
  cout << "Postorder: [9, 15, 7, 20, 3]" << endl;
  TreeNode *result1 = sol.buildTree(inorder1, postorder1);
  cout << "Tree (level order): ";
  printTree(result1);
  cout << "Expected: 3 9 20 null null 15 7" << endl
       << endl;

  // Test Case 2: Single node
  vector<int> inorder2 = {-1};
  vector<int> postorder2 = {-1};
  cout << "Test Case 2:" << endl;
  cout << "Inorder: [-1]" << endl;
  cout << "Postorder: [-1]" << endl;
  TreeNode *result2 = sol.buildTree(inorder2, postorder2);
  cout << "Tree (level order): ";
  printTree(result2);
  cout << "Expected: -1" << endl
       << endl;

  // Test Case 3: Left skewed tree
  vector<int> inorder3 = {3, 2, 1};
  vector<int> postorder3 = {3, 2, 1};
  cout << "Test Case 3:" << endl;
  cout << "Inorder: [3, 2, 1]" << endl;
  cout << "Postorder: [3, 2, 1]" << endl;
  TreeNode *result3 = sol.buildTree(inorder3, postorder3);
  cout << "Tree (level order): ";
  printTree(result3);
  cout << "Expected: 1 2 null 3 null null" << endl
       << endl;

  // Test Case 4: Right skewed tree
  vector<int> inorder4 = {1, 2, 3};
  vector<int> postorder4 = {3, 2, 1};
  cout << "Test Case 4:" << endl;
  cout << "Inorder: [1, 2, 3]" << endl;
  cout << "Postorder: [3, 2, 1]" << endl;
  TreeNode *result4 = sol.buildTree(inorder4, postorder4);
  cout << "Tree (level order): ";
  printTree(result4);
  cout << "Expected: 1 null 2 null 3" << endl
       << endl;

  // Test Case 5: Balanced tree
  vector<int> inorder5 = {4, 2, 5, 1, 6, 3, 7};
  vector<int> postorder5 = {4, 5, 2, 6, 7, 3, 1};
  cout << "Test Case 5:" << endl;
  cout << "Inorder: [4, 2, 5, 1, 6, 3, 7]" << endl;
  cout << "Postorder: [4, 5, 2, 6, 7, 3, 1]" << endl;
  TreeNode *result5 = sol.buildTree(inorder5, postorder5);
  cout << "Tree (level order): ";
  printTree(result5);
  cout << "Expected: 1 2 3 4 5 6 7" << endl
       << endl;

  // Test Case 6: Tree with only left child
  vector<int> inorder6 = {2, 1};
  vector<int> postorder6 = {2, 1};
  cout << "Test Case 6:" << endl;
  cout << "Inorder: [2, 1]" << endl;
  cout << "Postorder: [2, 1]" << endl;
  TreeNode *result6 = sol.buildTree(inorder6, postorder6);
  cout << "Tree (level order): ";
  printTree(result6);
  cout << "Expected: 1 2 null" << endl
       << endl;

  return 0;
}

/*
Time Complexity: O(n²)
- For each node, we search for its position in inorder array
- In worst case (skewed tree), this search takes O(n) time
- Total time complexity is O(n²) where n is the number of nodes

Space Complexity: O(n)
- Recursion stack space: O(h) where h is height of tree
- In worst case (skewed tree), h = n, so O(n)
- Additional space for creating tree nodes: O(n)
- Total space complexity is O(n)

Algorithm:
1. Last element of postorder is always the root
2. Find root's position in inorder array
3. Elements to the left of root in inorder form left subtree
4. Elements to the right of root in inorder form right subtree
5. Recursively build left and right subtrees

Key Differences from Preorder+Inorder:
- Root is at the end of postorder (not beginning)
- Right subtree comes before left subtree in postorder
- Need to calculate left subtree size to split postorder correctly

Optimization: Using hash map to store inorder indices can reduce
time complexity to O(n) by eliminating the linear search.
*/
