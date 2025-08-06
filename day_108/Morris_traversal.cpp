// Morris Traversal Implementation
// Time Complexity: O(n) - Each node is visited at most 3 times
// Space Complexity: O(1) - Only uses a constant amount of extra space

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// link - https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

/*
Morris Traversal is a tree traversal algorithm that does not use recursion or stack.
It uses the concept of threaded binary trees to traverse the tree in O(1) space.

Key Concepts:
1. Inorder: Left -> Root -> Right
2. Preorder: Root -> Left -> Right
3. Uses temporary links (threads) to connect nodes
4. Restores the tree structure after traversal
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
public:
  // Inorder Traversal: Left -> Root -> Right
  // Time Complexity: O(n) - Each node is visited at most 3 times
  // Space Complexity: O(1) - Only uses a constant amount of extra space
  vector<int> inorder(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
      if (curr->left)
      {
        // Find the inorder predecessor (rightmost node in left subtree)
        TreeNode *pred = curr->left;
        while (pred->right && pred->right != curr)
        {
          pred = pred->right;
        }

        if (pred->right == curr)
        {
          // Thread already exists, remove it and visit current node
          pred->right = nullptr;
          ans.push_back(curr->val);
          curr = curr->right;
        }
        else
        {
          // Create thread and move to left subtree
          pred->right = curr;
          curr = curr->left;
        }
      }
      else
      {
        // No left child, visit current node and move right
        ans.push_back(curr->val);
        curr = curr->right;
      }
    }
    return ans;
  }

  // Preorder Traversal: Root -> Left -> Right
  // Time Complexity: O(n) - Each node is visited at most 3 times
  // Space Complexity: O(1) - Only uses a constant amount of extra space
  vector<int> preorder(TreeNode *root)
  {
    if (!root)
      return {};

    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
      if (curr->left)
      {
        // Find the inorder predecessor
        TreeNode *pred = curr->left;
        while (pred->right && pred->right != curr)
        {
          pred = pred->right;
        }

        if (pred->right == curr)
        {
          // Thread already exists, remove it and move right
          pred->right = nullptr;
          curr = curr->right;
        }
        else
        {
          // Visit current node, create thread, and move left
          ans.push_back(curr->val);
          pred->right = curr;
          curr = curr->left;
        }
      }
      else
      {
        // No left child, visit current node and move right
        ans.push_back(curr->val);
        curr = curr->right;
      }
    }
    return ans;
  }
};

// Helper function to build a binary tree from a vector (level order, null as -1)
TreeNode *buildTree(const vector<int> &vals)
{
  if (vals.empty() || vals[0] == -1)
    return nullptr;
  TreeNode *root = new TreeNode(vals[0]);
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < vals.size())
  {
    TreeNode *curr = q.front();
    q.pop();
    if (i < vals.size() && vals[i] != -1)
    {
      curr->left = new TreeNode(vals[i]);
      q.push(curr->left);
    }
    i++;
    if (i < vals.size() && vals[i] != -1)
    {
      curr->right = new TreeNode(vals[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// Helper function to free memory
void deleteTree(TreeNode *root)
{
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

// Helper function to print vector
void printVector(const vector<int> &vec, const string &name)
{
  cout << name << ": [";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i];
    if (i < vec.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main()
{
  Solution sol;
  cout << "=== Morris Traversal Implementation ===\n\n";

  // Test Case 1: Simple tree
  cout << "Test Case 1: Simple Tree" << endl;
  vector<int> vals1 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode *root1 = buildTree(vals1);
  cout << "Tree: [1,2,3,4,5,6,7]" << endl;

  vector<int> inorder1 = sol.inorder(root1);
  vector<int> preorder1 = sol.preorder(root1);

  printVector(inorder1, "Inorder");
  printVector(preorder1, "Preorder");
  cout << "Expected Inorder: [4, 2, 5, 1, 6, 3, 7]" << endl;
  cout << "Expected Preorder: [1, 2, 4, 5, 3, 6, 7]\n"
       << endl;
  deleteTree(root1);

  // Test Case 2: Skewed tree (all right)
  cout << "Test Case 2: Skewed Tree (All Right)" << endl;
  vector<int> vals2 = {1, -1, 2, -1, 3, -1, 4};
  TreeNode *root2 = buildTree(vals2);
  cout << "Tree: [1,null,2,null,3,null,4]" << endl;

  vector<int> inorder2 = sol.inorder(root2);
  vector<int> preorder2 = sol.preorder(root2);

  printVector(inorder2, "Inorder");
  printVector(preorder2, "Preorder");
  cout << "Expected Inorder: [1, 2, 3, 4]" << endl;
  cout << "Expected Preorder: [1, 2, 3, 4]\n"
       << endl;
  deleteTree(root2);

  // Test Case 3: Skewed tree (all left)
  cout << "Test Case 3: Skewed Tree (All Left)" << endl;
  vector<int> vals3 = {1, 2, -1, 3, -1, 4};
  TreeNode *root3 = buildTree(vals3);
  cout << "Tree: [1,2,null,3,null,4]" << endl;

  vector<int> inorder3 = sol.inorder(root3);
  vector<int> preorder3 = sol.preorder(root3);

  printVector(inorder3, "Inorder");
  printVector(preorder3, "Preorder");
  cout << "Expected Inorder: [4, 3, 2, 1]" << endl;
  cout << "Expected Preorder: [1, 2, 3, 4]\n"
       << endl;
  deleteTree(root3);

  // Test Case 4: Single node
  cout << "Test Case 4: Single Node" << endl;
  vector<int> vals4 = {5};
  TreeNode *root4 = buildTree(vals4);
  cout << "Tree: [5]" << endl;

  vector<int> inorder4 = sol.inorder(root4);
  vector<int> preorder4 = sol.preorder(root4);

  printVector(inorder4, "Inorder");
  printVector(preorder4, "Preorder");
  cout << "Expected Inorder: [5]" << endl;
  cout << "Expected Preorder: [5]\n"
       << endl;
  deleteTree(root4);

  // Test Case 5: Empty tree
  cout << "Test Case 5: Empty Tree" << endl;
  TreeNode *root5 = nullptr;
  cout << "Tree: []" << endl;

  vector<int> inorder5 = sol.inorder(root5);
  vector<int> preorder5 = sol.preorder(root5);

  printVector(inorder5, "Inorder");
  printVector(preorder5, "Preorder");
  cout << "Expected Inorder: []" << endl;
  cout << "Expected Preorder: []\n"
       << endl;

  cout << "=== Algorithm Analysis ===" << endl;
  cout << "Time Complexity: O(n) - Each node is visited at most 3 times" << endl;
  cout << "Space Complexity: O(1) - Only uses a constant amount of extra space" << endl;
  cout << "\nKey Advantages:" << endl;
  cout << "1. Constant space complexity (no stack/recursion)" << endl;
  cout << "2. In-place traversal without modifying tree structure permanently" << endl;
  cout << "3. Threads are created and removed during traversal" << endl;

  return 0;
}