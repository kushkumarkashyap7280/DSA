// 617. Merge Two Binary Trees
// Link: https://leetcode.com/problems/merge-two-binary-trees/

/*
Problem Description:
Merge two binary trees by summing overlapping nodes and using non-null nodes when one tree is empty.
The merging process must start from the root nodes of both trees.

Time Complexity: O(N), where N is min(n1, n2), n1 and n2 are sizes of the input trees
- We only process nodes that exist in at least one of the trees
- Once we hit a null in either tree, we stop that branch's recursion

Space Complexity: O(H), where H is min(h1, h2), h1 and h2 are heights of the trees
- Recursion stack space
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)

Example Test Cases:

1. Regular Case with Overlap:
   Tree 1:     Tree 2:      Result:
      1          2            3
     / \        / \          / \
    3   2      1   3        4   5
   /            \            \
  5             4            9

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4]
Output: [3,4,5,5,4]
Explanation: Overlapping nodes sum up, non-overlapping nodes are kept

2. One Empty Tree:
   Tree 1:     Tree 2:      Result:
      1         null          1
     / \                    / \
    2   3                  2   3

Input: root1 = [1,2,3], root2 = null
Output: [1,2,3]
Explanation: When one tree is empty, return the other tree

3. Unbalanced Trees:
   Tree 1:     Tree 2:      Result:
      1          2            3
     /          / \          / \
    3          1   3        4   3
               \            \
                4            4

Input: root1 = [1,3], root2 = [2,1,3,null,4]
Output: [3,4,3,null,4]
Explanation: Missing nodes are treated as 0 when summing

4. Single Node Trees:
   Tree 1:     Tree 2:      Result:
      5          3            8

Input: root1 = [5], root2 = [3]
Output: [8]
Explanation: Simple sum of root nodes

5. Complex Case with Multiple Levels:
   Tree 1:        Tree 2:         Result:
      1             2               3
     / \           / \             / \
    3   7         5   8           8  15
   /             / \             / \
  6             4   2          10   2
                                \
                                 2

Input: root1 = [1,3,7,6], root2 = [2,5,8,4,2]
Output: [3,8,15,10,2,null,null,null,2]
*/

#include <iostream>
#include <vector>
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
  // Helper function to create a tree from level-order traversal array
  static TreeNode *createTree(vector<int> &arr, int i = 0)
  {
    if (i >= arr.size() || arr[i] == -1)
      return nullptr; // -1 represents null
    TreeNode *root = new TreeNode(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
  }

  // Helper function to print level-order traversal of tree
  static void printLevelOrder(TreeNode *root)
  {
    if (!root)
    {
      cout << "[]" << endl;
      return;
    }

    queue<TreeNode *> q;
    q.push(root);
    vector<string> result;

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      if (node)
      {
        result.push_back(to_string(node->val));
        q.push(node->left);
        q.push(node->right);
      }
      else
      {
        result.push_back("null");
      }
    }

    // Remove trailing nulls
    while (!result.empty() && result.back() == "null")
    {
      result.pop_back();
    }

    // Print result
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
      if (i > 0)
        cout << ",";
      cout << result[i];
    }
    cout << "]" << endl;
  }

public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
  {
    // Base cases: if either tree is empty, return the other tree
    if (!root1 && !root2)
      return nullptr;
    if (!root1 && root2)
      return root2;
    if (root1 && !root2)
      return root1;

    // Sum the values and merge recursively
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
  }

  // Function to test the solution
  static void runTest(vector<int> &arr1, vector<int> &arr2)
  {
    Solution sol;
    TreeNode *root1 = createTree(arr1);
    TreeNode *root2 = createTree(arr2);

    cout << "Tree 1: ";
    printLevelOrder(root1);
    cout << "Tree 2: ";
    printLevelOrder(root2);

    TreeNode *result = sol.mergeTrees(root1, root2);
    cout << "Merged: ";
    printLevelOrder(result);
    cout << "-------------------\n";
  }
};

int main()
{
  // Test Case 1: Regular case with overlap
  vector<int> test1_tree1 = {1, 3, 2, 5};
  vector<int> test1_tree2 = {2, 1, 3, -1, 4};
  cout << "Test Case 1: Regular case with overlap\n";
  Solution::runTest(test1_tree1, test1_tree2);

  // Test Case 2: One empty tree
  vector<int> test2_tree1 = {1, 2, 3};
  vector<int> test2_tree2 = {};
  cout << "Test Case 2: One empty tree\n";
  Solution::runTest(test2_tree1, test2_tree2);

  // Test Case 3: Unbalanced trees
  vector<int> test3_tree1 = {1, 3};
  vector<int> test3_tree2 = {2, 1, 3, -1, 4};
  cout << "Test Case 3: Unbalanced trees\n";
  Solution::runTest(test3_tree1, test3_tree2);

  // Test Case 4: Single node trees
  vector<int> test4_tree1 = {5};
  vector<int> test4_tree2 = {3};
  cout << "Test Case 4: Single node trees\n";
  Solution::runTest(test4_tree1, test4_tree2);

  // Test Case 5: Complex case with multiple levels
  vector<int> test5_tree1 = {1, 3, 7, 6};
  vector<int> test5_tree2 = {2, 5, 8, 4, 2};
  cout << "Test Case 5: Complex case with multiple levels\n";
  Solution::runTest(test5_tree1, test5_tree2);

  return 0;
}