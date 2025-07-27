// Count Leaves in Binary Tree
// Link: https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

/*
Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree

Examples:

Input:
Given Tree is
    1
   / \
  2   3
 / \
4   5

Output: 3
Explanation: Three leaves are 4, 5 and 3.

Input:
Given Tree is
    10
   /  \
  20   30
 /  \
40   50

Output: 3
Explanation: Three leaves are 40, 50 and 30.

Constraints:
1 <= number of nodes <= 10^5
1 <= node->data <= 10^5
*/

#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class Solution
class Solution
{
public:
  // Function to count the number of leaf nodes in a binary tree.
  // Time Complexity: O(n) where n is the number of nodes
  // Space Complexity: O(h) where h is the height of the tree (recursion stack)
  int countLeaves(Node *root)
  {
    if (!root)
      return 0;

    // If both left and right children are null, it's a leaf node
    if (!root->left && !root->right)
    {
      return 1;
    }

    // Recursively count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
  }

  // Alternative implementation with explicit counting
  int countLeavesAlternative(Node *root)
  {
    if (!root)
      return 0;

    int count = 0;
    if (!root->left && !root->right)
    {
      count++;
    }

    if (root->left)
    {
      count += countLeavesAlternative(root->left);
    }

    if (root->right)
    {
      count += countLeavesAlternative(root->right);
    }

    return count;
  }

  // Iterative approach using level order traversal
  int countLeavesIterative(Node *root)
  {
    if (!root)
      return 0;

    int count = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      Node *current = q.front();
      q.pop();

      // If it's a leaf node
      if (!current->left && !current->right)
      {
        count++;
      }

      // Add children to queue
      if (current->left)
      {
        q.push(current->left);
      }
      if (current->right)
      {
        q.push(current->right);
      }
    }

    return count;
  }
};

// Test function to create a sample tree
Node *createSampleTree()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  return root;
}

// Main function for testing
int main()
{
  Solution solution;

  // Create a sample tree
  Node *root = createSampleTree();

  // Test all three approaches
  cout << "Recursive approach: " << solution.countLeaves(root) << endl;
  cout << "Alternative recursive: " << solution.countLeavesAlternative(root) << endl;
  cout << "Iterative approach: " << solution.countLeavesIterative(root) << endl;

  return 0;
}
