// Merge two BST 's


// link - http://geeksforgeeks.org/problems/merge-two-bst-s/1


/*
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input: root1 = [5, 3, 6, 2, 4]
 
root2 = [2, 1, 3, N, N, N, 7, 6]
 
Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].
Input: root1 = [12, 9, N, 6, 11]

root2 = [8, 5, 10, 2]

Output: [2, 5, 6, 8, 9, 10, 11, 12]
Explanation: After merging and sorting the two BST we get [2, 5, 6, 8, 9, 10, 11, 12].
Constraints:
1 ≤ number of nodes, root->data ≤ 105
*/



// approach 1 : 
// time complexity : O (n);
// space complexity : O(n);

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
    
    void morris(Node* root , vector<int> &v){
        if(!root) return;
        
        while(root){
            if(!root->left){
                v.push_back(root->data);
                root = root->right;
            }else{
                Node* pred = root->left;
                while(pred->right && pred->right != root) pred = pred->right;
                
                if(pred->right != root){
                    pred->right = root;
                    root = root->left;
                }else{
                    pred->right = nullptr;
                    v.push_back(root->data);
                    root = root->right;
                }
            }
        }
    }
  public:
   
    vector<int> merge(Node *root1, Node *root2) {
       vector<int> v;
       
       morris(root1, v);
         morris(root2, v);
         
         sort(v.begin(), v.end());
         return v;
    }
};
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// second approach :
// time complexity : O(n);
// space complexity : O(n);
class Solution {
    
//     void morris(Node* root , vector<int> &v){
//         while(root){
//             if(!root->left){
//                 v.push_back(root->data);
//                 root = root->right;
//             }else{
//                 Node* pred = root->left;
//                 while(pred->right && pred->right != root) pred = pred->right;
                
//                 if(!pred->right){
//                     pred->right = root;
//                     root = root->left;
//                 }else{
//                     pred->right = nullptr;
//                     v.push_back(root->data);
//                     root = root->right;
//                 }
//             }
//         }
//     }

//     vector<int> mergeArrays(vector<int>& a, vector<int>& b){
//         vector<int> ans;
//         int i=0, j=0;
//         while(i<a.size() && j<b.size()){
//             if(a[i] < b[j]) ans.push_back(a[i++]);
//             else ans.push_back(b[j++]);
//         }
//         while(i<a.size()) ans.push_back(a[i++]);
//         while(j<b.size()) ans.push_back(b[j++]);
//         return ans;
//     }

//   public:
//     vector<int> merge(Node *root1, Node *root2) {
//         vector<int> v1, v2;
//         morris(root1, v1);
//         morris(root2, v2);
//         return mergeArrays(v1, v2);
//     }


// most optimal : 
// time complexity : O(n);
// space complexity : O(n);
Node* morris(Node* root){
    if(!root) return nullptr;
    Node* head = nullptr;
    Node* prev = nullptr;
    while(root){
        if(!root->left){
             if(!head) head = root;
             if(prev){
                  prev->right = root;
                  prev->left = nullptr;
             }
              prev = root;
            root = root->right;
        }else{
            Node* pred = root->left;
            while(pred->right && pred->right != root) pred = pred->right;
            
            if(!pred->right){
                pred->right = root;
                root = root->left;
            }else{
                pred->right = nullptr;
                 if (!head) head = root;
                 if(prev){
                  prev->right = root;
                  prev->left = nullptr;
             }
              prev = root;
            root = root->right;
            }
        }
    }
    return head;
}

public:

vector<int> merge(Node *root1, Node *root2) {
  
   root1 = morris(root1);
   root2 = morris(root2);
   
   vector<int> v;
   
   Node* c1 = root1;
   Node* c2 = root2;
   
   
   while(c1 && c2){
       if(c1->data >=  c2->data){
           v.push_back(c2->data);
           c2 = c2->right;
       }else{
           v.push_back(c1->data);
           c1 = c1->right;
       }
   }
   

    while(c1){
           v.push_back(c1->data);
           c1 = c1->right;
    }

    while(c2){
           v.push_back(c2->data);
           c2 = c2->right;
    }
   
 return v;
   
}
    
};

// Helper: insert into BST
Node* insertBST(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // Build sample BST 1: [5,3,6,2,4]
    Node* root1 = nullptr;
    for(int v : {5,3,6,2,4}) root1 = insertBST(root1, v);

    // Build sample BST 2: [2,1,3,7,6]
    Node* root2 = nullptr;
    for(int v : {2,1,3,7,6}) root2 = insertBST(root2, v);

    Solution sol;
    vector<int> merged = sol.merge(root1, root2);

    cout << "Merged elements: ";
    for(size_t i=0;i<merged.size();++i){
        if(i) cout << ", ";
        cout << merged[i];
    }
    cout << "\n";

    return 0;
}