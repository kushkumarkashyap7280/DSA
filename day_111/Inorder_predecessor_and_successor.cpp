//Predecessor and Successor

//link = https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

/*
TIME COMPLEXITY: O(h) where h is the height of the BST
- In worst case (skewed tree): O(n) 
- In best case (balanced tree): O(log n)
- We traverse at most one path from root to leaf

SPACE COMPLEXITY: O(1) 
- Only using constant extra space for pointers
- No recursion or additional data structures used

ALGORITHM:
1. Search for the key while maintaining potential predecessor and successor
2. If key found, find actual predecessor (rightmost in left subtree) and successor (leftmost in right subtree)
3. If key not found, the last nodes where we went right/left are predecessor/successor
*/

/*
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3], key = 3

Output: 2 -1
Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
Constraints: 
1 <= no. of nodes <= 105
1 <= node->data <= 106
1 <= key <= 106
*/

#include <iostream>
#include <vector>
using namespace std;

// BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; 


class Solution {
    public:
        vector<Node*> findPreSuc(Node* root, int key) {
            Node* pre = NULL;
            Node* suc = NULL;
            Node* curr = root;
    
            // Search for predecessor and successor while searching for key
            while (curr) {
                if (curr->data < key) {
                    pre = curr; // potential predecessor
                    curr = curr->right;
                }
                else if (curr->data > key) {
                    suc = curr; // potential successor
                    curr = curr->left;
                }
                else { 
                    // Key found
                    if (curr->left) {
                        Node* temp = curr->left;
                        while (temp->right) temp = temp->right;
                        pre = temp;
                    }
                    if (curr->right) {
                        Node* temp = curr->right;
                        while (temp->left) temp = temp->left;
                        suc = temp;
                    }
                    break;
                }
            }
            return {pre, suc};
        }
    };
    
// Helper function to create BST nodes
Node* createNode(int data) {
    return new Node(data);
}

// Helper function to print results
void printResult(vector<Node*> result, int key) {
    cout << "Key: " << key << " -> ";
    cout << "Predecessor: " << (result[0] ? to_string(result[0]->data) : "NULL");
    cout << ", Successor: " << (result[1] ? to_string(result[1]->data) : "NULL") << endl;
}

// Test function
void runTests() {
    Solution sol;
    
    cout << "=== PREDECESSOR AND SUCCESSOR TEST CASES ===" << endl;
    
    // Test Case 1: Basic BST - key exists
    cout << "\nTest Case 1: Basic BST with existing key" << endl;
    Node* root1 = createNode(8);
    root1->left = createNode(3);
    root1->right = createNode(10);
    root1->left->left = createNode(1);
    root1->left->right = createNode(6);
    root1->right->right = createNode(14);
    root1->left->right->left = createNode(4);
    root1->left->right->right = createNode(7);
    root1->right->right->left = createNode(13);
    
    vector<Node*> result1 = sol.findPreSuc(root1, 8);
    printResult(result1, 8); // Expected: Predecessor: 7, Successor: 10
    
    // Test Case 2: Key is leaf node
    cout << "\nTest Case 2: Key is leaf node" << endl;
    vector<Node*> result2 = sol.findPreSuc(root1, 4);
    printResult(result2, 4); // Expected: Predecessor: 3, Successor: 6
    
    // Test Case 3: Key doesn't exist
    cout << "\nTest Case 3: Key doesn't exist" << endl;
    vector<Node*> result3 = sol.findPreSuc(root1, 5);
    printResult(result3, 5); // Expected: Predecessor: 4, Successor: 6
    
    // Test Case 4: Key is minimum (no predecessor)
    cout << "\nTest Case 4: Key is minimum" << endl;
    vector<Node*> result4 = sol.findPreSuc(root1, 1);
    printResult(result4, 1); // Expected: Predecessor: NULL, Successor: 3
    
    // Test Case 5: Key is maximum (no successor)
    cout << "\nTest Case 5: Key is maximum" << endl;
    vector<Node*> result5 = sol.findPreSuc(root1, 14);
    printResult(result5, 14); // Expected: Predecessor: 13, Successor: NULL
    
    // Test Case 6: Single node tree
    cout << "\nTest Case 6: Single node tree" << endl;
    Node* root2 = createNode(5);
    vector<Node*> result6 = sol.findPreSuc(root2, 5);
    printResult(result6, 5); // Expected: Predecessor: NULL, Successor: NULL
    
    // Test Case 7: Key smaller than all nodes
    cout << "\nTest Case 7: Key smaller than all nodes" << endl;
    vector<Node*> result7 = sol.findPreSuc(root1, 0);
    printResult(result7, 0); // Expected: Predecessor: NULL, Successor: 1
    
    // Test Case 8: Key larger than all nodes
    cout << "\nTest Case 8: Key larger than all nodes" << endl;
    vector<Node*> result8 = sol.findPreSuc(root1, 20);
    printResult(result8, 20); // Expected: Predecessor: 14, Successor: NULL
    
    // Test Case 9: Skewed tree (right skewed)
    cout << "\nTest Case 9: Right skewed tree" << endl;
    Node* root3 = createNode(1);
    root3->right = createNode(2);
    root3->right->right = createNode(3);
    root3->right->right->right = createNode(4);
    vector<Node*> result9 = sol.findPreSuc(root3, 2);
    printResult(result9, 2); // Expected: Predecessor: 1, Successor: 3
    
    // Test Case 10: Left skewed tree
    cout << "\nTest Case 10: Left skewed tree" << endl;
    Node* root4 = createNode(4);
    root4->left = createNode(3);
    root4->left->left = createNode(2);
    root4->left->left->left = createNode(1);
    vector<Node*> result10 = sol.findPreSuc(root4, 3);
    printResult(result10, 3); // Expected: Predecessor: 2, Successor: 4
}

int main() {
    runTests();
    return 0;
}