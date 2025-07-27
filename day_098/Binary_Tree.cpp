// ============ Binary Tree Implementation ============
// This file contains comprehensive binary tree operations including:
// - Tree construction (recursive and iterative)
// - Tree traversal (recursive and iterative)
// - Tree printing and visualization

#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

// Binary Tree Node Structure
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

// ============ Tree Construction Methods ============

// Recursive tree construction
Node *buildBinaryTreeRecursive(Node *root)
{
  cout << "Enter data (or -1 for null): ";
  int data;
  cin >> data;

  if (data == -1)
  {
    return nullptr;
  }

  root = new Node(data);

  cout << "Enter left child of " << data << endl;
  root->left = buildBinaryTreeRecursive(root->left);

  cout << "Enter right child of " << data << endl;
  root->right = buildBinaryTreeRecursive(root->right);

  return root;
}

// Iterative tree construction using level order approach
Node *buildTreeIterative()
{
  queue<Node *> q;
  cout << "Enter root value (or -1 for empty tree): ";
  int data;
  cin >> data;

  if (data == -1)
  {
    return nullptr;
  }

  Node *root = new Node(data);
  q.push(root);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    cout << "Enter left child of " << temp->data << " (or -1 for null): ";
    int left;
    cin >> left;
    if (left != -1)
    {
      temp->left = new Node(left);
      q.push(temp->left);
    }

    cout << "Enter right child of " << temp->data << " (or -1 for null): ";
    int right;
    cin >> right;
    if (right != -1)
    {
      temp->right = new Node(right);
      q.push(temp->right);
    }
  }
  return root;
}

// ============ Tree Printing and Visualization ============

// Level order traversal with proper formatting
void printTree(Node *root)
{
  if (!root)
  {
    cout << "Tree is empty!" << endl;
    return;
  }

  queue<Node *> q;
  q.push(root);
  q.push(nullptr);

  cout << "Tree Structure (Level Order):" << endl;
  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == nullptr)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(nullptr);
      }
    }
    else
    {
      cout << temp->data << "  ";
      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
  cout << endl;
}

// ============ Recursive Traversal Methods ============

// Inorder Traversal (Left -> Root -> Right)
void inorderRecursive(Node *root)
{
  if (!root)
    return;
  inorderRecursive(root->left);
  cout << root->data << " ";
  inorderRecursive(root->right);
}

// Preorder Traversal (Root -> Left -> Right)
void preorderRecursive(Node *root)
{
  if (!root)
    return;
  cout << root->data << " ";
  preorderRecursive(root->left);
  preorderRecursive(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorderRecursive(Node *root)
{
  if (!root)
    return;
  postorderRecursive(root->left);
  postorderRecursive(root->right);
  cout << root->data << " ";
}

// ============ Iterative Traversal Methods ============

// Iterative Inorder Traversal using Stack
void inorderIterative(Node *root)
{
  if (!root)
    return;

  stack<Node *> s;
  Node *curr = root;

  cout << "Inorder (Iterative): ";
  while (curr != nullptr || !s.empty())
  {
    // Go to the leftmost node
    while (curr != nullptr)
    {
      s.push(curr);
      curr = curr->left;
    }

    // Process current node
    curr = s.top();
    s.pop();
    cout << curr->data << " ";

    // Move to right subtree
    curr = curr->right;
  }
  cout << endl;
}

// Iterative Preorder Traversal using Stack
void preorderIterative(Node *root)
{
  if (!root)
    return;

  stack<Node *> st;
  st.push(root);

  cout << "Preorder (Iterative): ";
  while (!st.empty())
  {
    Node *curr = st.top();
    st.pop();

    cout << curr->data << " ";

    // Push right child first (so left is processed first)
    if (curr->right)
    {
      st.push(curr->right);
    }
    if (curr->left)
    {
      st.push(curr->left);
    }
  }
  cout << endl;
}

// Iterative Postorder Traversal using Single Stack
void postorderIterative(Node *root)
{
  if (!root)
    return;

  stack<Node *> st;
  Node *curr = root;
  Node *lastVisited = nullptr;

  cout << "Postorder (Iterative): ";
  while (curr || !st.empty())
  {
    // Go left as far as possible
    if (curr)
    {
      st.push(curr);
      curr = curr->left;
    }
    else
    {
      Node *peekNode = st.top();
      // If right child exists and hasn't been visited yet
      if (peekNode->right && lastVisited != peekNode->right)
      {
        curr = peekNode->right;
      }
      else
      {
        cout << peekNode->data << " ";
        lastVisited = peekNode;
        st.pop();
      }
    }
  }
  cout << endl;
}

// ============ Utility Functions ============

// Calculate height of the tree
int getHeight(Node *root)
{
  if (!root)
    return 0;
  return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Count total nodes in the tree
int countNodes(Node *root)
{
  if (!root)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is balanced
bool isBalanced(Node *root)
{
  if (!root)
    return true;

  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);

  return abs(leftHeight - rightHeight) <= 1 &&
         isBalanced(root->left) &&
         isBalanced(root->right);
}

// ============ Main Function ============

int main()
{
  cout << "=== Binary Tree Operations ===" << endl;
  cout << "Choose tree construction method:" << endl;
  cout << "1. Recursive construction" << endl;
  cout << "2. Iterative construction" << endl;

  int choice;
  cin >> choice;

  Node *root = nullptr;

  switch (choice)
  {
  case 1:
    cout << "\n=== Recursive Tree Construction ===" << endl;
    root = buildBinaryTreeRecursive(root);
    break;
  case 2:
    cout << "\n=== Iterative Tree Construction ===" << endl;
    root = buildTreeIterative();
    break;
  default:
    cout << "Invalid choice! Using iterative method." << endl;
    root = buildTreeIterative();
  }

  if (root)
  {
    cout << "\n=== Tree Information ===" << endl;
    printTree(root);

    cout << "\n=== Tree Statistics ===" << endl;
    cout << "Total nodes: " << countNodes(root) << endl;
    cout << "Height: " << getHeight(root) << endl;
    cout << "Is balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;

    cout << "\n=== Traversal Results ===" << endl;

    cout << "Recursive Traversals:" << endl;
    cout << "Inorder: ";
    inorderRecursive(root);
    cout << endl;

    cout << "Preorder: ";
    preorderRecursive(root);
    cout << endl;

    cout << "Postorder: ";
    postorderRecursive(root);
    cout << endl;

    cout << "\nIterative Traversals:" << endl;
    inorderIterative(root);
    preorderIterative(root);
    postorderIterative(root);
  }
  else
  {
    cout << "Tree is empty!" << endl;
  }

  return 0;
}

/*
Sample Input for Recursive Construction:
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

Sample Input for Iterative Construction:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Expected Output:
Tree Structure (Level Order):
1
2  3
4  5  6  7

Tree Statistics:
Total nodes: 7
Height: 3
Is balanced: Yes

Recursive Traversals:
Inorder: 4 2 5 1 6 3 7
Preorder: 1 2 4 5 3 6 7
Postorder: 4 5 2 6 7 3 1

Iterative Traversals:
Inorder (Iterative): 4 2 5 1 6 3 7
Preorder (Iterative): 1 2 4 5 3 6 7
Postorder (Iterative): 4 5 2 6 7 3 1
*/