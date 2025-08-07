// ===================== Binary search Tree ==================
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// TreeNode

struct TreeNode
{
  int val;
  TreeNode * left ;
  TreeNode* right ;
  TreeNode(int val){
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

TreeNode* makeBst(TreeNode * root ,int val){
  if(!root) {
    root = new TreeNode(val);
    return root;
  }
  if(root->val > val){
    root->left = makeBst(root->left ,val);
  }else{
    root->right = makeBst(root->right ,val);
  }
  return root;
}

void inorder(TreeNode* root){ // L N R
  if(!root) return;
  inorder(root->left);
  cout << root->val << " -> ";
  inorder(root->right);

}

void preorder(TreeNode* root){ //N L  R
  if(!root) return;
  cout << root->val << " -> ";
  preorder(root->left);
  
  preorder(root->right);
}

void postorder(TreeNode* root){ // L  R N
  if(!root) return;
  
  postorder(root->left);
  
  postorder(root->right);
  cout << root->val << " -> ";
}



void buildBST(TreeNode* &root){
  cout << "enter root val : " ;
  int val;
  cin >> val;
 cout << endl;

  while(val != -1){
    root = makeBst( root ,val);
    cout << "enter next :" ;
    cin >> val;
    cout << endl;
  }

}

void levelOrder(TreeNode *root)
  {
    if (!root)
      return ;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
      int s = q.size();
      while(s){
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->val << "    " ;

        if(temp->left){
          q.push(temp->left);
        }
        if(temp->right){
          q.push(temp->right);
        }
        s--;
      }
      cout << endl;
    }
  }

int main(){
  TreeNode * root = nullptr;
   buildBST(root);
 
   cout << "tree level wise traversal" << endl;
  levelOrder(root);

  cout << " inorder " << endl;
  inorder(root);

  cout <<" preorder" << endl;
  preorder(root);

  cout << "postorder" << endl;
  postorder(root);
  return 0;
}