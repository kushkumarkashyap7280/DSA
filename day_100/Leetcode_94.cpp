// 94. Binary Tree Inorder Traversal

// link - https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]



Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ========== RECURSIVE SOLUTION ==========
class SolutionRecursive
{
public:
  void inorder(TreeNode *root, vector<int> &v)
  {
    if (!root)
      return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> v;
    inorder(root, v);
    return v;
  }
};

// ========== ITERATIVE SOLUTION ==========
class SolutionIterative
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> v;
    if (!root)
      return v;

    stack<TreeNode *> s;
    TreeNode *curr = root;

    while (curr || !s.empty())
    {
      while (curr)
      {
        s.push(curr);
        curr = curr->left;
      }

      curr = s.top();
      s.pop();
      v.push_back(curr->val);
      curr = curr->right;
    }

    return v;
  }
};

// ========== MORRIS TRAVERSAL (OPTIMIZED) ==========
class SolutionMorris
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> v;
    TreeNode *curr = root;

    while (curr)
    {
      if (curr->left == nullptr)
      {
        v.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        TreeNode *prev = curr->left;
        while (prev->right && prev->right != curr)
        {
          prev = prev->right;
        }

        if (prev->right == nullptr)
        {
          prev->right = curr;
          curr = curr->left;
        }
        else
        {
          prev->right = nullptr;
          v.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
    return v;
  }
};

// ========== COMPLEXITY ANALYSIS ==========
/*
COMPLEXITY ANALYSIS:

1. RECURSIVE SOLUTION:
   - Time Complexity: O(n) where n is the number of nodes
   - Space Complexity: O(h) where h is the height of the tree
     * Best case (balanced tree): O(log n)
     * Worst case (skewed tree): O(n)
   - Call stack space used for recursion

2. ITERATIVE SOLUTION:
   - Time Complexity: O(n) where n is the number of nodes
   - Space Complexity: O(h) where h is the height of the tree
     * Best case (balanced tree): O(log n)
     * Worst case (skewed tree): O(n)
   - Stack space used to simulate recursion

3. MORRIS TRAVERSAL:
   - Time Complexity: O(n) where n is the number of nodes
   - Space Complexity: O(1) - constant extra space
   - Modifies the tree structure temporarily and restores it
   - Most space-efficient solution

COMPARISON:
- Recursive: Simple to understand, uses call stack
- Iterative: More control, uses explicit stack
- Morris: Most space-efficient, but modifies tree temporarily
*/

// ========== TEST CASES ==========
class TestCases
{
private:
  // Helper function to create a tree from array representation
  TreeNode *createTree(vector<int> &values, int index = 0)
  {
    if (index >= values.size() || values[index] == -1)
      return nullptr;

    TreeNode *root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
  }

  // Helper function to print vector
  void printVector(const vector<int> &v)
  {
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
      cout << v[i];
      if (i < v.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }

  // Helper function to compare vectors
  bool compareVectors(const vector<int> &v1, const vector<int> &v2)
  {
    if (v1.size() != v2.size())
      return false;
    for (int i = 0; i < v1.size(); i++)
    {
      if (v1[i] != v2[i])
        return false;
    }
    return true;
  }

public:
  void runAllTests()
  {
    cout << "=== TESTING BINARY TREE INORDER TRAVERSAL ===" << endl
         << endl;

    // Test Case 1: Simple tree [1,null,2,3]
    cout << "Test Case 1: [1,null,2,3]" << endl;
    vector<int> values1 = {1, -1, 2, -1, -1, 3, -1};
    TreeNode *root1 = createTree(values1);

    SolutionRecursive sol1_rec;
    SolutionIterative sol1_iter;
    SolutionMorris sol1_morris;

    vector<int> result1_rec = sol1_rec.inorderTraversal(root1);
    vector<int> result1_iter = sol1_iter.inorderTraversal(root1);
    vector<int> result1_morris = sol1_morris.inorderTraversal(root1);

    cout << "Expected: [1, 3, 2]" << endl;
    cout << "Recursive: ";
    printVector(result1_rec);
    cout << "Iterative: ";
    printVector(result1_iter);
    cout << "Morris: ";
    printVector(result1_morris);
    cout << "All match: " << (compareVectors(result1_rec, result1_iter) && compareVectors(result1_iter, result1_morris)) << endl
         << endl;

    // Test Case 2: Complex tree [1,2,3,4,5,null,8,null,null,6,7,9]
    cout << "Test Case 2: [1,2,3,4,5,null,8,null,null,6,7,9]" << endl;
    vector<int> values2 = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, -1, 9};
    TreeNode *root2 = createTree(values2);

    SolutionRecursive sol2_rec;
    SolutionIterative sol2_iter;
    SolutionMorris sol2_morris;

    vector<int> result2_rec = sol2_rec.inorderTraversal(root2);
    vector<int> result2_iter = sol2_iter.inorderTraversal(root2);
    vector<int> result2_morris = sol2_morris.inorderTraversal(root2);

    cout << "Expected: [4, 2, 6, 5, 7, 1, 3, 9, 8]" << endl;
    cout << "Recursive: ";
    printVector(result2_rec);
    cout << "Iterative: ";
    printVector(result2_iter);
    cout << "Morris: ";
    printVector(result2_morris);
    cout << "All match: " << (compareVectors(result2_rec, result2_iter) && compareVectors(result2_iter, result2_morris)) << endl
         << endl;

    // Test Case 3: Empty tree []
    cout << "Test Case 3: []" << endl;
    TreeNode *root3 = nullptr;

    SolutionRecursive sol3_rec;
    SolutionIterative sol3_iter;
    SolutionMorris sol3_morris;

    vector<int> result3_rec = sol3_rec.inorderTraversal(root3);
    vector<int> result3_iter = sol3_iter.inorderTraversal(root3);
    vector<int> result3_morris = sol3_morris.inorderTraversal(root3);

    cout << "Expected: []" << endl;
    cout << "Recursive: ";
    printVector(result3_rec);
    cout << "Iterative: ";
    printVector(result3_iter);
    cout << "Morris: ";
    printVector(result3_morris);
    cout << "All match: " << (compareVectors(result3_rec, result3_iter) && compareVectors(result3_iter, result3_morris)) << endl
         << endl;

    // Test Case 4: Single node [1]
    cout << "Test Case 4: [1]" << endl;
    vector<int> values4 = {1};
    TreeNode *root4 = createTree(values4);

    SolutionRecursive sol4_rec;
    SolutionIterative sol4_iter;
    SolutionMorris sol4_morris;

    vector<int> result4_rec = sol4_rec.inorderTraversal(root4);
    vector<int> result4_iter = sol4_iter.inorderTraversal(root4);
    vector<int> result4_morris = sol4_morris.inorderTraversal(root4);

    cout << "Expected: [1]" << endl;
    cout << "Recursive: ";
    printVector(result4_rec);
    cout << "Iterative: ";
    printVector(result4_iter);
    cout << "Morris: ";
    printVector(result4_morris);
    cout << "All match: " << (compareVectors(result4_rec, result4_iter) && compareVectors(result4_iter, result4_morris)) << endl
         << endl;

    // Test Case 5: Left skewed tree [1,2,null,3]
    cout << "Test Case 5: Left skewed [1,2,null,3]" << endl;
    vector<int> values5 = {1, 2, -1, 3, -1, -1, -1};
    TreeNode *root5 = createTree(values5);

    SolutionRecursive sol5_rec;
    SolutionIterative sol5_iter;
    SolutionMorris sol5_morris;

    vector<int> result5_rec = sol5_rec.inorderTraversal(root5);
    vector<int> result5_iter = sol5_iter.inorderTraversal(root5);
    vector<int> result5_morris = sol5_morris.inorderTraversal(root5);

    cout << "Expected: [3, 2, 1]" << endl;
    cout << "Recursive: ";
    printVector(result5_rec);
    cout << "Iterative: ";
    printVector(result5_iter);
    cout << "Morris: ";
    printVector(result5_morris);
    cout << "All match: " << (compareVectors(result5_rec, result5_iter) && compareVectors(result5_iter, result5_morris)) << endl
         << endl;

    // Test Case 6: Right skewed tree [1,null,2,null,3]
    cout << "Test Case 6: Right skewed [1,null,2,null,3]" << endl;
    vector<int> values6 = {1, -1, 2, -1, -1, -1, 3};
    TreeNode *root6 = createTree(values6);

    SolutionRecursive sol6_rec;
    SolutionIterative sol6_iter;
    SolutionMorris sol6_morris;

    vector<int> result6_rec = sol6_rec.inorderTraversal(root6);
    vector<int> result6_iter = sol6_iter.inorderTraversal(root6);
    vector<int> result6_morris = sol6_morris.inorderTraversal(root6);

    cout << "Expected: [1, 2, 3]" << endl;
    cout << "Recursive: ";
    printVector(result6_rec);
    cout << "Iterative: ";
    printVector(result6_iter);
    cout << "Morris: ";
    printVector(result6_morris);
    cout << "All match: " << (compareVectors(result6_rec, result6_iter) && compareVectors(result6_iter, result6_morris)) << endl
         << endl;

    cout << "=== ALL TESTS COMPLETED ===" << endl;
  }
};

// ========== MAIN FUNCTION ==========
int main()
{
  TestCases test;
  test.runAllTests();
  return 0;
}