//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    Node* flattenBST(Node* root) {
        if (!root) return nullptr;
        vector<Node*> nodes;
        
        // Morris in-order traversal to get nodes in sorted order
        Node* curr = root;
        while (curr) {
            if (!curr->left) {
                nodes.push_back(curr);
                curr = curr->right;
            } else {
                Node* temp = curr->left;
                while (temp->right && temp->right != curr) {
                    temp = temp->right;
                }
                
                if (temp->right == curr) {
                    temp->right = nullptr;
                    nodes.push_back(curr);
                    curr = curr->right;
                } else {
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        
        // Connect nodes to form the linked list
        for (int i = 0; i + 1 < nodes.size(); i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        
        // Set the last node's pointers to null
        if (!nodes.empty()) {
            nodes.back()->left = nullptr;
            nodes.back()->right = nullptr;
        }
        
        return nodes.empty() ? nullptr : nodes[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        // inorder(root);
        // cout<<"\n";
        Solution obj;
        Node* ans = obj.flattenBST(root);
        while (ans != NULL) {
            cout << ans->data << " ";
            ans = ans->right;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends