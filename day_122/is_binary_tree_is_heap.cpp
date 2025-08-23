// Is Binary Tree Heap
//  Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*
Problem Description:
Given a binary tree, determine if it's a max-heap. A binary tree is a max-heap if:
1. It's a complete binary tree (all levels filled except possibly last, nodes as far left as possible)
2. Every node's value is greater than or equal to its children's values (max-heap property)

Time Complexity: O(N), where N is the number of nodes
- sizeOfTree: O(N) to count all nodes
- solve: O(N) to check each node once for:
  * Completeness using index property
  * Max-heap property by comparing with children

Space Complexity: O(H), where H is the height of the tree
- Recursion stack space for both functions
- Best case (complete tree): O(log N)
- Worst case (skewed tree): O(N)

Example Test Cases:

1. Valid Max Heap:
       97
      /  \
     46   37
    / \   / \
   12  3  7  31
   / \
   6  9
Input: [97,46,37,12,3,7,31,6,9]
Output: true
Explanation: Complete tree + parent values >= children

2. Invalid - Not Complete:
       97
      /  \
     46   37
    / \    \
   12  3    31
      / \
     2   4
Input: [97,46,37,12,3,null,31,null,2,4]
Output: false
Explanation: Nodes not as far left as possible

3. Invalid - Violates Max Heap Property:
       50
      /  \
     60   30
    /  \
   20   10
Input: [50,60,30,20,10]
Output: false
Explanation: 60 > 50 violates max-heap property

4. Single Node:
       5
Input: [5]
Output: true
Explanation: Single node is always a valid heap

5. Perfect Max Heap:
       100
      /   \
     50    40
    /  \  /  \
   30  20 35  25
Input: [100,50,40,30,20,35,25]
Output: true
Explanation: Perfect binary tree + max-heap property
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure of node
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
private:
  // Check both completeness and max-heap property
  bool solve(Node *root, int index, int size)
  {
    // Base case
    if (!root)
      return true;

    // Check completeness using index property
    if (index >= size)
      return false;

    // Check max-heap property
    if (root->left && root->left->data > root->data)
      return false;
    if (root->right && root->right->data > root->data)
      return false;

    // Recursively check left and right subtrees
    return solve(root->left, index * 2 + 1, size) &&
           solve(root->right, index * 2 + 2, size);
  }

  // Get total number of nodes in tree
  int sizeOfTree(Node *root)
  {
    if (!root)
      return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
  }

public:
  bool isHeap(Node *tree)
  {
    if (!tree)
      return true;
    int size = sizeOfTree(tree);
    return solve(tree, 0, size);
  }

  // Helper function to create a tree from level-order array
  static Node *createTree(vector<int> &arr, int i = 0)
  {
    if (i >= arr.size() || arr[i] == -1)
      return nullptr; // -1 represents null

    Node *root = new Node(arr[i]);
    root->left = createTree(arr, 2 * i + 1);
    root->right = createTree(arr, 2 * i + 2);
    return root;
  }
};

// Test function
void runTest(vector<int> input, bool expected)
{
  Solution sol;
  Node *root = Solution::createTree(input);
  bool result = sol.isHeap(root);

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
  // Test Case 1: Valid Max Heap
  vector<int> test1 = {97, 46, 37, 12, 3, 7, 31, 6, 9};
  runTest(test1, true);

  // Test Case 2: Invalid - Not Complete
  vector<int> test2 = {97, 46, 37, 12, 3, -1, 31, -1, 2, 4}; // -1 represents null
  runTest(test2, false);

  // Test Case 3: Invalid - Violates Max Heap Property
  vector<int> test3 = {50, 60, 30, 20, 10};
  runTest(test3, false);

  // Test Case 4: Single Node
  vector<int> test4 = {5};
  runTest(test4, true);

  // Test Case 5: Perfect Max Heap
  vector<int> test5 = {100, 50, 40, 30, 20, 35, 25};
  runTest(test5, true);

  // Additional Test Case 6: Empty Tree
  vector<int> test6 = {};
  runTest(test6, true);

  // Additional Test Case 7: Two Level Complete Max Heap
  vector<int> test7 = {10, 5, 3};
  runTest(test7, true);

  // Additional Test Case 8: Invalid - Right Child Greater Than Parent
  vector<int> test8 = {10, 5, 15, 2, 1};
  runTest(test8, false);

  return 0;
}