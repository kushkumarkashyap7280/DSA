// Bottom View of Binary Tree

// link - https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

For the above tree, the output should be 5 8 34 22 25

Examples :

Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input: root[] = [10, 20, 30, 40, 60]

Output: [40 20 60 30]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// BFS Solution using Level Order Traversal
// Time Complexity: O(n) - where n is the number of nodes
// Space Complexity: O(w) - where w is the maximum width of the tree (queue size)
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        if (!root)
            return {};

        map<int, int> m;

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            Node *curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            m[hd] = curr->data;
            if (curr->left)
            {
                q.push({curr->left, hd - 1});
            }
            if (curr->right)
            {
                q.push({curr->right, hd + 1});
            }
        }

        vector<int> ans;

        for (auto i : m)
        {
            ans.push_back(i.second);
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
    cout << "=== Bottom View of Binary Tree ===" << endl
         << endl;

    // Test Case 1: [1, 3, 2]
    cout << "Test Case 1:" << endl;
    vector<int> values1 = {1, 3, 2};
    Node *root1 = createTree(values1);
    cout << "Tree: ";
    printTree(root1);
    cout << endl;

    Solution sol1;
    vector<int> result1 = sol1.bottomView(root1);
    cout << "Bottom View: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [3 1 2]" << endl
         << endl;

    // Test Case 2: [10, 20, 30, 40, 60]
    cout << "Test Case 2:" << endl;
    vector<int> values2 = {10, 20, 30, 40, 60};
    Node *root2 = createTree(values2);
    cout << "Tree: ";
    printTree(root2);
    cout << endl;

    Solution sol2;
    vector<int> result2 = sol2.bottomView(root2);
    cout << "Bottom View: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [40 20 60 30]" << endl
         << endl;

    // Test Case 3: [1, 2, 3, 4, 5, 6, 7]
    cout << "Test Case 3:" << endl;
    vector<int> values3 = {1, 2, 3, 4, 5, 6, 7};
    Node *root3 = createTree(values3);
    cout << "Tree: ";
    printTree(root3);
    cout << endl;

    Solution sol3;
    vector<int> result3 = sol3.bottomView(root3);
    cout << "Bottom View: ";
    printVector(result3);
    cout << endl;
    cout << "Expected: [4 2 1 3 7]" << endl
         << endl;

    // Test Case 4: Single node
    cout << "Test Case 4:" << endl;
    vector<int> values4 = {5};
    Node *root4 = createTree(values4);
    cout << "Tree: ";
    printTree(root4);
    cout << endl;

    Solution sol4;
    vector<int> result4 = sol4.bottomView(root4);
    cout << "Bottom View: ";
    printVector(result4);
    cout << endl;
    cout << "Expected: [5]" << endl
         << endl;

    // Test Case 5: Left skewed tree
    cout << "Test Case 5:" << endl;
    vector<int> values5 = {1, 2, -1, 3, -1, -1, -1, 4};
    Node *root5 = createTree(values5);
    cout << "Tree: ";
    printTree(root5);
    cout << endl;

    Solution sol5;
    vector<int> result5 = sol5.bottomView(root5);
    cout << "Bottom View: ";
    printVector(result5);
    cout << endl;
    cout << "Expected: [4 2 1]" << endl
         << endl;

    // Test Case 6: Right skewed tree
    cout << "Test Case 6:" << endl;
    vector<int> values6 = {1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4};
    Node *root6 = createTree(values6);
    cout << "Tree: ";
    printTree(root6);
    cout << endl;

    Solution sol6;
    vector<int> result6 = sol6.bottomView(root6);
    cout << "Bottom View: ";
    printVector(result6);
    cout << endl;
    cout << "Expected: [1 2 3 4]" << endl
         << endl;

    cout << "=== Complexity Analysis ===" << endl;
    cout << "BFS Solution:" << endl;
    cout << "- Time Complexity: O(n) - visit each node once" << endl;
    cout << "- Space Complexity: O(w) - queue size at maximum width" << endl;
    cout << "- Algorithm: Level order traversal with horizontal distance tracking" << endl;
    cout << "- Key Insight: Last node at each horizontal distance is the bottom view" << endl;

    return 0;
}