// Diagonal Tree Traversal

// link - https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation: Diagonal traversal of the binary tree is:
8 10 14 3 6 7 13 1 4

Example 2:

Input :
           1
         /    \
        4      2
      /   \      \
     8     5      3
         /  \    /
        9    7  6
Output : 1 2 3 4 5 7 6 8 9
Explanation: Diagonal traversal of the binary tree is:
1 2 3 4 5 7 6 8 9

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node
{
  int data;
  Node *left, *right;

  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

// BFS Solution using Queue
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(w) - where w is the maximum width of the tree (queue size)
class Solution
{
public:
  vector<int> diagonal(Node *root)
  {
    if (!root)
      return {};
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      Node *temp = q.front();
      q.pop();
      while (temp)
      {
        ans.push_back(temp->data);

        if (temp->left)
          q.push(temp->left);
        temp = temp->right;
      }
    }
    return ans;
  }
};

// Helper function to create a binary tree from vector
Node *createTree(vector<int> &values, int index = 0)
{
  if (index >= values.size() || values[index] == -1)
  {
    return nullptr;
  }

  Node *root = new Node(values[index]);
  root->left = createTree(values, 2 * index + 1);
  root->right = createTree(values, 2 * index + 2);
  return root;
}

// Helper function to print tree (inorder traversal)
void printTree(Node *root)
{
  if (!root)
    return;
  printTree(root->left);
  cout << root->data << " ";
  printTree(root->right);
}

// Helper function to print vector
void printVector(vector<int> &vec)
{
  cout << "[";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i];
    if (i < vec.size() - 1)
      cout << " ";
  }
  cout << "]";
}

int main()
{
  cout << "=== Diagonal Traversal of Binary Tree ===" << endl
       << endl;

  // Test Case 1: Example 1 from problem
  cout << "Test Case 1:" << endl;
  cout << "Tree structure:" << endl;
  cout << "            8" << endl;
  cout << "         /     \\" << endl;
  cout << "        3      10" << endl;
  cout << "      /   \\      \\" << endl;
  cout << "     1     6     14" << endl;
  cout << "         /   \\   /" << endl;
  cout << "        4     7 13" << endl;

  vector<int> values1 = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, -1, -1, 13, -1};
  Node *root1 = createTree(values1);
  cout << "Tree (inorder): ";
  printTree(root1);
  cout << endl;

  Solution sol1;
  vector<int> result1 = sol1.diagonal(root1);
  cout << "Diagonal Traversal: ";
  printVector(result1);
  cout << endl;
  cout << "Expected: [8 10 14 3 6 7 13 1 4]" << endl
       << endl;

  // Test Case 2: Example 2 from problem
  cout << "Test Case 2:" << endl;
  cout << "Tree structure:" << endl;
  cout << "           1" << endl;
  cout << "         /    \\" << endl;
  cout << "        4      2" << endl;
  cout << "      /   \\      \\" << endl;
  cout << "     8     5      3" << endl;
  cout << "         /  \\    /" << endl;
  cout << "        9    7  6" << endl;

  vector<int> values2 = {1, 4, 2, 8, 5, -1, 3, -1, -1, 9, 7, -1, -1, 6, -1};
  Node *root2 = createTree(values2);
  cout << "Tree (inorder): ";
  printTree(root2);
  cout << endl;

  Solution sol2;
  vector<int> result2 = sol2.diagonal(root2);
  cout << "Diagonal Traversal: ";
  printVector(result2);
  cout << endl;
  cout << "Expected: [1 2 3 4 5 7 6 8 9]" << endl
       << endl;

  // Test Case 3: Simple tree
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {1, 2, 3, 4, 5, 6, 7};
  Node *root3 = createTree(values3);
  cout << "Tree (inorder): ";
  printTree(root3);
  cout << endl;

  Solution sol3;
  vector<int> result3 = sol3.diagonal(root3);
  cout << "Diagonal Traversal: ";
  printVector(result3);
  cout << endl;
  cout << "Expected: [1 3 7 2 5 6 4]" << endl
       << endl;

  // Test Case 4: Single node
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {5};
  Node *root4 = createTree(values4);
  cout << "Tree (inorder): ";
  printTree(root4);
  cout << endl;

  Solution sol4;
  vector<int> result4 = sol4.diagonal(root4);
  cout << "Diagonal Traversal: ";
  printVector(result4);
  cout << endl;
  cout << "Expected: [5]" << endl
       << endl;

  // Test Case 5: Left skewed tree
  cout << "Test Case 5:" << endl;
  vector<int> values5 = {1, 2, -1, 3, -1, -1, -1, 4};
  Node *root5 = createTree(values5);
  cout << "Tree (inorder): ";
  printTree(root5);
  cout << endl;

  Solution sol5;
  vector<int> result5 = sol5.diagonal(root5);
  cout << "Diagonal Traversal: ";
  printVector(result5);
  cout << endl;
  cout << "Expected: [1 2 3 4]" << endl
       << endl;

  // Test Case 6: Right skewed tree
  cout << "Test Case 6:" << endl;
  vector<int> values6 = {1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4};
  Node *root6 = createTree(values6);
  cout << "Tree (inorder): ";
  printTree(root6);
  cout << endl;

  Solution sol6;
  vector<int> result6 = sol6.diagonal(root6);
  cout << "Diagonal Traversal: ";
  printVector(result6);
  cout << endl;
  cout << "Expected: [1 2 3 4]" << endl
       << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "BFS Solution:" << endl;
  cout << "- Time Complexity: O(n) - visit each node once" << endl;
  cout << "- Space Complexity: O(w) - queue size at maximum width" << endl;
  cout << "- Algorithm: Level order traversal with diagonal grouping" << endl;
  cout << "- Key Insight: Process all nodes in current diagonal before moving to next" << endl;
  cout << "- Strategy: Use queue to store left children, traverse right children immediately" << endl;

  return 0;
}