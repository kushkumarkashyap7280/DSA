// 236. Lowest Common Ancestor of a Binary Tree

// link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)."



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// DFS Solution using Recursion
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(h) - where h is the height of the tree (recursion stack)
class Solution
{

  // First approach: Path finding with deque
  //     void route( TreeNode* root , deque<TreeNode*>&n , TreeNode* &f , bool &isFound){
  //         if(!root || isFound) return;
  //         if(root == f){
  //             isFound = true;
  //             return;
  //         }
  //         if(root->left){
  //             n.push_back(root->left);
  //             route(root->left , n , f , isFound );
  //           if(!isFound)n.pop_back();
  //         }
  //         if(root->right){
  //             n.push_back(root->right);
  //             route(root->right ,n , f , isFound );
  //           if(!isFound)n.pop_back();
  //         }
  //     }
  // public:
  //     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  //         if(!root) return nullptr;
  //         if( root == p  || root == q) return root;
  //          deque<TreeNode*> n1;
  //          deque<TreeNode*> n2;
  //          bool isFound = false;

  //          route(root, n1 ,p , isFound);

  //          isFound = false;

  //          route(root, n2 ,q , isFound);

  //       TreeNode* prev = nullptr;
  //       while(!n1.empty() && !n2.empty()){
  //           if(n1.front() != n2.front()){
  //             return prev;
  //           }
  //           prev = n1.front();
  //           n1.pop_front();
  //           n2.pop_front();
  //       }
  //       return prev;
  //     }

  // Second approach: Recursive LCA finding

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root)
      return nullptr;
    if (root->val == p->val || root->val == q->val)
    {
      return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left && right)
    {
      return root;
    }
    if (left && !right)
      return left;
    if (right && !left)
      return right;

    return nullptr;
  }
};

// Helper function to create a binary tree from vector
TreeNode *createTree(vector<int> &values, int index = 0)
{
  if (index >= values.size() || values[index] == -1)
  {
    return nullptr;
  }

  TreeNode *root = new TreeNode(values[index]);
  root->left = createTree(values, 2 * index + 1);
  root->right = createTree(values, 2 * index + 2);
  return root;
}

// Helper function to print tree (inorder traversal)
void printTree(TreeNode *root)
{
  if (!root)
    return;
  printTree(root->left);
  cout << root->val << " ";
  printTree(root->right);
}

// Helper function to find a node by value
TreeNode *findNode(TreeNode *root, int val)
{
  if (!root)
    return nullptr;
  if (root->val == val)
    return root;

  TreeNode *left = findNode(root->left, val);
  if (left)
    return left;

  return findNode(root->right, val);
}

// Helper function to print path from root to a node
bool printPath(TreeNode *root, TreeNode *target, vector<int> &path)
{
  if (!root)
    return false;

  path.push_back(root->val);

  if (root == target)
  {
    cout << "Path to " << target->val << ": ";
    for (int i = 0; i < path.size(); i++)
    {
      cout << path[i];
      if (i < path.size() - 1)
        cout << " -> ";
    }
    cout << endl;
    return true;
  }

  if (printPath(root->left, target, path) || printPath(root->right, target, path))
  {
    return true;
  }

  path.pop_back();
  return false;
}

int main()
{
  cout << "=== LeetCode 236: Lowest Common Ancestor of a Binary Tree ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  TreeNode *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  TreeNode *p1 = findNode(root1, 5);
  TreeNode *q1 = findNode(root1, 1);

  cout << "Finding LCA of " << p1->val << " and " << q1->val << endl;
  vector<int> path1;
  printPath(root1, p1, path1);
  path1.clear();
  printPath(root1, q1, path1);

  Solution sol1;
  TreeNode *result1 = sol1.lowestCommonAncestor(root1, p1, q1);
  cout << "LCA: " << result1->val << endl;
  cout << "Expected: 3" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
  TreeNode *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  TreeNode *p2 = findNode(root2, 5);
  TreeNode *q2 = findNode(root2, 4);

  cout << "Finding LCA of " << p2->val << " and " << q2->val << endl;
  vector<int> path2;
  printPath(root2, p2, path2);
  path2.clear();
  printPath(root2, q2, path2);

  Solution sol2;
  TreeNode *result2 = sol2.lowestCommonAncestor(root2, p2, q2);
  cout << "LCA: " << result2->val << endl;
  cout << "Expected: 5" << endl
       << endl;

  // Test Case 3: Example 3 from problem
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {1, 2};
  TreeNode *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  TreeNode *p3 = findNode(root3, 1);
  TreeNode *q3 = findNode(root3, 2);

  cout << "Finding LCA of " << p3->val << " and " << q3->val << endl;
  vector<int> path3;
  printPath(root3, p3, path3);
  path3.clear();
  printPath(root3, q3, path3);

  Solution sol3;
  TreeNode *result3 = sol3.lowestCommonAncestor(root3, p3, q3);
  cout << "LCA: " << result3->val << endl;
  cout << "Expected: 1" << endl
       << endl;

  // Test Case 4: Simple tree
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  TreeNode *p4 = findNode(root4, 4);
  TreeNode *q4 = findNode(root4, 7);

  cout << "Finding LCA of " << p4->val << " and " << q4->val << endl;
  vector<int> path4;
  printPath(root4, p4, path4);
  path4.clear();
  printPath(root4, q4, path4);

  Solution sol4;
  TreeNode *result4 = sol4.lowestCommonAncestor(root4, p4, q4);
  cout << "LCA: " << result4->val << endl;
  cout << "Expected: 1" << endl
       << endl;

  // Test Case 5: Parent-child relationship
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  TreeNode *p5 = findNode(root5, 2);
  TreeNode *q5 = findNode(root5, 4);

  cout << "Finding LCA of " << p5->val << " and " << q5->val << endl;
  vector<int> path5;
  printPath(root5, p5, path5);
  path5.clear();
  printPath(root5, q5, path5);

  Solution sol5;
  TreeNode *result5 = sol5.lowestCommonAncestor(root5, p5, q5);
  cout << "LCA: " << result5->val << endl;
  cout << "Expected: 2" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "DFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(h) - recursion stack depth" << endl;
  cout << "- Algorithm: Recursive LCA finding" << endl;
  cout << "- Key Insight: If both nodes are found in different subtrees, current node is LCA" << endl;
  cout << "- Strategy: Use recursion to find nodes and return LCA when both found" << endl;

  return 0;
}