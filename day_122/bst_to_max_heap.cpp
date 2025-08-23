#include <vector>
#include <iostream>
using namespace std;

// BST to Max Heap Conversion
//  Link: https://www.geeksforgeeks.org/problems/bst-to-max-heap/1

/*
Problem Description:
Convert a Binary Search Tree (BST) into a Special Max Heap where all values in the left
subtree of a node should be less than all values in its right subtree. This condition
must be satisfied for all nodes in the resulting Max Heap.

Time Complexity: O(N)
- Inorder traversal: O(N)
- Postorder traversal with array assignment: O(N)

Space Complexity: O(N)
- Vector to store inorder traversal: O(N)
- Recursion stack space: O(H) where H is height of tree

Key Properties:
1. BST Property: Left < Root < Right
2. Max Heap Property: Root > Left && Root > Right
3. Special Max Heap: All left subtree < All right subtree

Algorithm Steps:
1. Store BST nodes in sorted order using inorder traversal
2. Replace node values using postorder traversal
   - Process left and right subtrees first
   - Replace current node with next value from sorted array
   - This ensures Max Heap and special property are maintained

Example Test Cases:

1. Basic BST:
   Input:     4
            /   \
           2     6
          / \   / \
         1   3 5   7

   Steps:
   1. Inorder:  [1,2,3,4,5,6,7] (sorted)
   2. Postorder replacement:

   Output:    7
            /   \
           3     6
          / \   / \
         1   2 4   5

2. Left-Skewed BST:
   Input:  3
          /
         2
        /
       1

   Output: 3
          /
         2
        /
       1

3. Right-Skewed BST:
   Input:  1
            \
             2
              \
               3
   Output: 3
          /
         2
        /
       1

4. Single Node:
   Input:  5
   Output: 5 (no change needed)

5. Empty Tree:
   Input: NULL
   Output: NULL

Special Conditions:
1. Original BST structure is preserved, only values are changed
2. Final tree satisfies both Max Heap and special left-right property
3. Postorder traversal of result gives sorted array in ascending order
*/

// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

// Node structure for Binary Tree
struct Node
{
  int data;
  Node *left, *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
  // Helper function to perform inorder traversal and store values
  void inorderTraversal(Node *root, vector<int> &values)
  {
    if (!root)
      return;

    inorderTraversal(root->left, values);  // Process left subtree
    values.push_back(root->data);          // Store current node's value
    inorderTraversal(root->right, values); // Process right subtree
  }

  // Helper function to rebuild tree using postorder traversal
  void rebuildTreePostorder(Node *root, const vector<int> &values, int &index)
  {
    if (!root)
      return;

    rebuildTreePostorder(root->left, values, index);  // Process left subtree
    rebuildTreePostorder(root->right, values, index); // Process right subtree
    root->data = values[index++];                     // Replace current node's value
  }

public:
  void convertToMaxHeapUtil(Node *root)
  {
    if (!root)
      return;

    // Step 1: Store BST values in sorted order using inorder traversal
    vector<int> sortedValues;
    inorderTraversal(root, sortedValues);

    // Step 2: Replace values in postorder to create Max Heap
    int index = 0;
    rebuildTreePostorder(root, sortedValues, index);
  }
};

// Helper functions for testing
void printPostorder(Node *root)
{
  if (!root)
    return;
  printPostorder(root->left);
  printPostorder(root->right);
  cout << root->data << " ";
}

bool isMaxHeap(Node *root)
{
  if (!root)
    return true;

  // Check if current node is greater than children
  if (root->left && root->data < root->left->data)
    return false;
  if (root->right && root->data < root->right->data)
    return false;

  // Check special property: all left subtree < all right subtree
  if (root->left && root->right)
  {
    Node *maxLeft = root->left;
    while (maxLeft->right)
      maxLeft = maxLeft->right;

    Node *minRight = root->right;
    while (minRight->left)
      minRight = minRight->left;

    if (maxLeft->data > minRight->data)
      return false;
  }

  // Recursively check children
  return isMaxHeap(root->left) && isMaxHeap(root->right);
}

// Test function
void runTests()
{
  // Test Case 1: Basic BST
  Node *test1 = new Node(4);
  test1->left = new Node(2);
  test1->right = new Node(6);
  test1->left->left = new Node(1);
  test1->left->right = new Node(3);
  test1->right->left = new Node(5);
  test1->right->right = new Node(7);

  cout << "Test Case 1:\nBefore conversion (Postorder): ";
  printPostorder(test1);
  cout << "\n";

  Solution sol;
  sol.convertToMaxHeapUtil(test1);

  cout << "After conversion (Postorder): ";
  printPostorder(test1);
  cout << "\nIs Valid Max Heap: " << (isMaxHeap(test1) ? "Yes" : "No") << "\n\n";

  // Test Case 2: Left-skewed BST
  Node *test2 = new Node(3);
  test2->left = new Node(2);
  test2->left->left = new Node(1);

  cout << "Test Case 2:\nBefore conversion (Postorder): ";
  printPostorder(test2);
  cout << "\n";

  sol.convertToMaxHeapUtil(test2);

  cout << "After conversion (Postorder): ";
  printPostorder(test2);
  cout << "\nIs Valid Max Heap: " << (isMaxHeap(test2) ? "Yes" : "No") << "\n\n";

  // Test Case 3: Single node
  Node *test3 = new Node(5);

  cout << "Test Case 3:\nBefore conversion (Postorder): ";
  printPostorder(test3);
  cout << "\n";

  sol.convertToMaxHeapUtil(test3);

  cout << "After conversion (Postorder): ";
  printPostorder(test3);
  cout << "\nIs Valid Max Heap: " << (isMaxHeap(test3) ? "Yes" : "No") << "\n\n";
}

// Main function
int main()
{
  runTests();
  return 0;
}
