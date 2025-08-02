// 1483. Kth Ancestor of a Tree Node

// link -https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

#include <iostream>
#include <vector>
using namespace std;

/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.


Example 1:


Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor


Constraints:

1 <= k <= n <= 5 * 104
parent.length == n
parent[0] == -1
0 <= parent[i] < n for all 0 < i < n
0 <= node < n
There will be at most 5 * 104 queries.
*/

class TreeAncestor
{

  // naive brute force apporach
  //     int n;
  //     vector<int> *parent;
  // public:
  //     TreeAncestor(int n, vector<int>& parent)    : n(n), parent(&parent) {}

  //     int getKthAncestor(int node, int k) {
  //         if(node < 0 || node >= n) return -1;
  //          while(k){
  //             if(node == -1) return node;
  //             node =(*parent)[node];
  //             k--;
  //          }
  //          return node;
  //     }
  //  when queury is very large  it will run  suppose 50 k then it will fall

  // optimal apporahch using binary lifting
  int n;
  int LOG;
  vector<vector<int>> p;

public:
  TreeAncestor(int n, vector<int> &parent)
  {
    this->n = n;

    LOG = 1;
    // THIS JUST TO HELP IN  HOW BIG JUMPS WE CAN TAKE IN WORST CASE AND ALSO THE  SIZE OF COLUMN WHRE EACH INDEX IS REPRESENT 2'S POWER ith INDEX PARENT
    while ((1 << LOG) <= n)
      LOG++;
    // NOW LETS AFTER  FINDING COLUMN SIZE ASSING VALUES DEFAULT -1;
    p.assign(n, vector<int>(LOG, -1));
    // something like
    /*

    rows =  nodes
    cols = 2's the power col index parent
    Node | 2^0   2^1   2^2
    -----+---------------
    0    | -1    -1    -1
    1    | -1    -1    -1
    2    | -1    -1    -1
    3    | -1    -1    -1
    4    | -1    -1    -1
    5    | -1    -1    -1
    6    | -1    -1    -1
     */

    //  we already given that who is first parent so just insert since first col is represting 0th parent  meand just above or first parent
    for (int i = 0; i < n; i++)
    {
      p[i][0] = parent[i];
    }
    // now become like
    /*
   Node | 2^0   2^1   2^2
   -----+---------------
   0    | -1    -1    -1
   1    |  0    -1    -1
   2    |  1    -1    -1
   3    |  2    -1    -1
   4    |  3    -1    -1
   5    |  4    -1    -1
   6    |  5    -1    -1
     */

    // now we have to add other parents too

    for (int j = 1; j < LOG; j++)
    { // since we already added first anscester now  2th 4th ..... 2 power  log ancestors
      for (int i = 0; i < n; i++)
      {                         // loop for each node
        int prev = p[i][j - 1]; // why becuase previous if we somehow find it j-th parent we able to find its parent's parent which is 2nd ancestor
        if (prev != -1)
        { // if previous itself is -1 means going futher above is waste nothig left above in tree
          // in case of we are still in between child node and root
          // our node means anscetor become
          p[i][j] = p[prev][j - 1]; // "To find the 2^j ancestor of i, take i's 2^(j-1) ancestor (prev), then take prev's 2^(j-1) ancestor."
        }
      }
    }
  }

  int getKthAncestor(int node, int k)
  {
    for (int j = 0; j < LOG; j++)
    {
      if (k & (1 << j))
      {                    // if j-th bit of k is set
        node = p[node][j]; // jump 2^j steps
        if (node == -1)
          return -1; // reached root
      }
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

// Helper function to visualize the tree structure
void printTreeStructure(const vector<int> &parent, int n)
{
  cout << "Tree Structure:" << endl;
  cout << "Node | Parent" << endl;
  cout << "-----+-------" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << " " << i << "   |   " << parent[i] << endl;
  }
  cout << endl;
}

int main()
{
  cout << "=== LeetCode 1483: Kth Ancestor of a Tree Node ===" << endl
       << endl;

  // Test Case 1: Example from problem
  cout << "Test Case 1:" << endl;
  int n1 = 7;
  vector<int> parent1 = {-1, 0, 0, 1, 1, 2, 2};

  cout << "n = " << n1 << endl;
  printTreeStructure(parent1, n1);

  TreeAncestor treeAncestor1(n1, parent1);

  // Note: p and LOG are private members, so we can't access them directly
  // In a real implementation, you would add getter methods or make them public
  cout << "Binary lifting table computed successfully" << endl;

  // Test queries
  cout << "Testing getKthAncestor queries:" << endl;
  cout << "getKthAncestor(3, 1) = " << treeAncestor1.getKthAncestor(3, 1) << " (Expected: 1)" << endl;
  cout << "getKthAncestor(5, 2) = " << treeAncestor1.getKthAncestor(5, 2) << " (Expected: 0)" << endl;
  cout << "getKthAncestor(6, 3) = " << treeAncestor1.getKthAncestor(6, 3) << " (Expected: -1)" << endl;
  cout << "getKthAncestor(6, 1) = " << treeAncestor1.getKthAncestor(6, 1) << " (Expected: 2)" << endl;
  cout << "getKthAncestor(6, 2) = " << treeAncestor1.getKthAncestor(6, 2) << " (Expected: 0)" << endl;
  cout << endl;

  // Test Case 2: Larger tree
  cout << "Test Case 2:" << endl;
  int n2 = 10;
  vector<int> parent2 = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};

  cout << "n = " << n2 << endl;
  printTreeStructure(parent2, n2);

  TreeAncestor treeAncestor2(n2, parent2);

  // Note: p and LOG are private members, so we can't access them directly
  // In a real implementation, you would add getter methods or make them public
  cout << "Binary lifting table computed successfully" << endl;

  // Test queries
  cout << "Testing getKthAncestor queries:" << endl;
  cout << "getKthAncestor(9, 1) = " << treeAncestor2.getKthAncestor(9, 1) << " (Expected: 4)" << endl;
  cout << "getKthAncestor(9, 2) = " << treeAncestor2.getKthAncestor(9, 2) << " (Expected: 1)" << endl;
  cout << "getKthAncestor(9, 3) = " << treeAncestor2.getKthAncestor(9, 3) << " (Expected: 0)" << endl;
  cout << "getKthAncestor(9, 4) = " << treeAncestor2.getKthAncestor(9, 4) << " (Expected: -1)" << endl;
  cout << "getKthAncestor(7, 1) = " << treeAncestor2.getKthAncestor(7, 1) << " (Expected: 3)" << endl;
  cout << "getKthAncestor(7, 2) = " << treeAncestor2.getKthAncestor(7, 2) << " (Expected: 1)" << endl;
  cout << endl;

  // Test Case 3: Linear tree
  cout << "Test Case 3:" << endl;
  int n3 = 5;
  vector<int> parent3 = {-1, 0, 1, 2, 3};

  cout << "n = " << n3 << endl;
  printTreeStructure(parent3, n3);

  TreeAncestor treeAncestor3(n3, parent3);

  // Note: p and LOG are private members, so we can't access them directly
  // In a real implementation, you would add getter methods or make them public
  cout << "Binary lifting table computed successfully" << endl;

  // Test queries
  cout << "Testing getKthAncestor queries:" << endl;
  cout << "getKthAncestor(4, 1) = " << treeAncestor3.getKthAncestor(4, 1) << " (Expected: 3)" << endl;
  cout << "getKthAncestor(4, 2) = " << treeAncestor3.getKthAncestor(4, 2) << " (Expected: 2)" << endl;
  cout << "getKthAncestor(4, 3) = " << treeAncestor3.getKthAncestor(4, 3) << " (Expected: 1)" << endl;
  cout << "getKthAncestor(4, 4) = " << treeAncestor3.getKthAncestor(4, 4) << " (Expected: 0)" << endl;
  cout << "getKthAncestor(4, 5) = " << treeAncestor3.getKthAncestor(4, 5) << " (Expected: -1)" << endl;
  cout << endl;

  cout << "=== Complexity Analysis ===" << endl;
  cout << "Binary Lifting Solution:" << endl;
  cout << "- Time Complexity: O(n * log n) for preprocessing, O(log n) per query" << endl;
  cout << "- Space Complexity: O(n * log n)" << endl;
  cout << "- Algorithm: Binary Lifting (Sparse Table for trees)" << endl;
  cout << "- Key Insight: Precompute 2^j ancestors for each node" << endl;
  cout << "- Strategy: Use binary representation of k to jump efficiently" << endl;
  cout << "- Preprocessing: For each node, compute its 2^j ancestor using dynamic programming" << endl;
  cout << "- Query: Decompose k into powers of 2 and jump accordingly" << endl;

  return 0;
}