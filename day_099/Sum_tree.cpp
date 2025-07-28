#include <iostream>
#include <utility>
using namespace std;

// Sum Tree

// link - https://www.geeksforgeeks.org/problems/sum-tree/1

/*
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples:

Input:
    3
  /   \
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Input:
   25
  /   \
 9     15
Output: false
Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

*/

/*  Tree node */
struct Node
{
  int data;
  Node *left, *right;
  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree (recursion stack)
class Solution
{
  pair<bool, int> isValid(Node *root)
  {
    if (!root)
      return {true, 0};
    if (!root->left && !root->right)
      return {true, root->data};
    pair<bool, int> l = isValid(root->left);
    pair<bool, int> r = isValid(root->right);
    return {(l.first && r.first) && (l.second + r.second) == root->data, l.second + r.second + root->data};
  }

public:
  bool isSumTree(Node *root)
  {
    if (!root)
      return true;
    return isValid(root).first;
  }
};

// Main function to test the solution
int main()
{
  Solution sol;

  // Test case 1:
  //     3
  //   /   \    
    //  1     2
  // Expected: true
  Node *root1 = new Node(3);
  root1->left = new Node(1);
  root1->right = new Node(2);

  cout << "Test case 1:" << endl;
  cout << "    3" << endl;
  cout << "   / \\" << endl;
  cout << "  1   2" << endl;
  cout << "Result: " << (sol.isSumTree(root1) ? "true" : "false") << endl;

  // Test case 2:
  //          10
  //        /    \
    //      20      30
  //    /   \ 
    //   10    10
  // Expected: false
  Node *root2 = new Node(10);
  root2->left = new Node(20);
  root2->right = new Node(30);
  root2->left->left = new Node(10);
  root2->left->right = new Node(10);

  cout << "\nTest case 2:" << endl;
  cout << "          10" << endl;
  cout << "        /    \\" << endl;
  cout << "      20      30" << endl;
  cout << "    /   \\" << endl;
  cout << "   10    10" << endl;
  cout << "Result: " << (sol.isSumTree(root2) ? "true" : "false") << endl;

  // Test case 3:
  //   25
  //  /   \    
    // 9     15
  // Expected: false
  Node *root3 = new Node(25);
  root3->left = new Node(9);
  root3->right = new Node(15);

  cout << "\nTest case 3:" << endl;
  cout << "   25" << endl;
  cout << "  /   \\" << endl;
  cout << " 9     15" << endl;
  cout << "Result: " << (sol.isSumTree(root3) ? "true" : "false") << endl;

  // Test case 4: Empty tree - should return true
  cout << "\nTest case 4: Empty tree" << endl;
  cout << "Result: " << (sol.isSumTree(nullptr) ? "true" : "false") << endl;

  // Test case 5: Single node - should return true
  Node *root5 = new Node(5);
  cout << "\nTest case 5: Single node (5)" << endl;
  cout << "Result: " << (sol.isSumTree(root5) ? "true" : "false") << endl;

  return 0;
}