// =================  TRIE  DATASTRUCTURE  =================

// A Trie (pronounced as "try") is a special type of tree used to store associative data structures.
// A common application of a Trie is storing a predictive text or autocomplete dictionary.
// The key feature of a Trie is that it allows for efficient retrieval of keys with a common prefix.


// implementation of Trie data structure in C++.


#include <iostream>
using namespace std;

struct TrieNode
{
  char c ;
  TrieNode * children[26];
  bool isTerminalNode;

  TrieNode(char c){
    this->c = c;

   for (int i = 0; i < 26; i++) {
    children[i] = nullptr;
   }

    isTerminalNode = false;
  }
};

class Trie{
  TrieNode * root;
   
   // if present util
  bool isPresentUtil(TrieNode* root , const string &word , int i){
    if(i == word.length()) return root->isTerminalNode;
   
     int index = tolower(word[i]) - 'a';
    TrieNode * child;

    if(root->children[index] != nullptr){
      child = root->children[index];

    }else{
      return false;
    }

    // for next char
    return  isPresentUtil(child , word , i+1);
  }


     // insertion utility
  void insertionUtil(TrieNode * root , const string &word , int i){

    if(i == word.length()) {
      root->isTerminalNode = true;
      return;
    }

    int index = tolower(word[i]) - 'a';
    TrieNode * child;

    if(root->children[index] != nullptr){
      child = root->children[index];

    }else{
      child = new TrieNode(word[i]);
      root->children[index] = child;
    }

    // for next char
    insertionUtil(child , word , i+1);

  }

  // deletion utility fucntion

  bool deletionUtil( TrieNode* root , const string &word , int i){
      if (i == word.length()) {
        if (!root->isTerminalNode) return false; // word not found
        root->isTerminalNode = false;

        // if no children, this node can be deleted
        for (int j = 0; j < 26; j++) {
            if (root->children[j] != nullptr) return true; // still needed
        }
        return false; // no children → deletable
    }

     int index = tolower(word[i]) -'a';

     TrieNode * child = root->children[index];

     if(!child) return false;

     bool shouldKeepChild = deletionUtil(child , word , i+1);

     if(!shouldKeepChild){
         delete child;
        root->children[index] = nullptr;
     }

      if (!root->isTerminalNode) {
        for (int j = 0; j < 26; j++) {
            if (root->children[j] != nullptr) return true;
        }
        return false; 
      }
      return true;

  }

  public :

  Trie(){
    root = new TrieNode('\0');
  }

  void insert(const string &word) {
        insertionUtil(root, word , 0);
  }

  // if present or not
  bool isPresent(const string &word) {
    return isPresentUtil(root, word , 0 );
  }

  bool deletion(const string &word){
    return deletionUtil(root , word, 0);
  }
};

int main() {

  // initialsation
  Trie* t =  new Trie();

  // insertion
  t->insert("kush");

  t->insert("is");

  t->insert("a");

  t->insert("king");


  // if present

  string s1 = "kush";
  string s2 = "is";
  string s3 = "a";
  string s4 = "king";
  if(t->isPresent(s1)) {
    cout << "kush is present" << endl;
  }

  if(t->isPresent(s2)) {
    cout << "is is present" << endl;
  }

  if(t->isPresent(s3)) {
    cout << "a is present" << endl;
  }

  if(t->isPresent(s4)) {
    cout << "king is present" << endl;
  }


  string s5 = "queen";
  if(t->isPresent(s5)) {
    cout << "queen is present" << endl;
  } else {
    cout << "queen is not present" << endl;
  }

  string s6 = "kushal";
  if(t->isPresent(s6)) {
    cout << "kushal is present" << endl;
  } else {
    cout << "kushal is not present" << endl;
  }


  // deletion
 if(t->deletion(s1)){
    cout << "deleted successfully" << endl;
 }

 if(t->isPresent(s1)){
  cout  << "still Kush is persent " << endl;
 }

 

  return 0;

}