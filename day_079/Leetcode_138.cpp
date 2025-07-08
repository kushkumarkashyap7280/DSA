// 138. Copy List with Random Pointer

// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Node
{
  int val;
  Node *next;
  Node *random;
  Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// Helper to build a list from vector<pair<int, int>> where second is random index or -1 for null
Node *buildList(const vector<pair<int, int>> &nodes)
{
  if (nodes.empty())
    return nullptr;
  vector<Node *> created;
  for (const auto &p : nodes)
  {
    created.push_back(new Node(p.first));
  }
  for (size_t i = 0; i < nodes.size(); ++i)
  {
    if (i + 1 < nodes.size())
      created[i]->next = created[i + 1];
    int randIdx = nodes[i].second;
    if (randIdx >= 0 && randIdx < (int)nodes.size())
      created[i]->random = created[randIdx];
    else
      created[i]->random = nullptr;
  }
  return created[0];
}

// Helper to print the list as [val, random_index]
void printList(Node *head)
{
  vector<Node *> nodes;
  Node *curr = head;
  while (curr)
  {
    nodes.push_back(curr);
    curr = curr->next;
  }
  curr = head;
  int idx = 0;
  while (curr)
  {
    int randIdx = -1;
    if (curr->random)
    {
      for (size_t i = 0; i < nodes.size(); ++i)
      {
        if (nodes[i] == curr->random)
        {
          randIdx = (int)i;
          break;
        }
      }
    }
    cout << "[" << curr->val << ",";
    if (randIdx == -1)
      cout << "null";
    else
      cout << randIdx;
    cout << "] ";
    curr = curr->next;
    ++idx;
  }
  cout << endl;
}

Node *copyRandomList(Node *head)
{
  Node *curr = head;
  Node dummy(0);
  Node *tail = &dummy;
  while (curr)
  {
    tail->next = new Node(curr->val);
    tail = tail->next;
    curr = curr->next;
  }
  curr = head;
  tail = dummy.next;
  while (curr)
  {
    if (!curr->random)
    {
      tail->random = nullptr;
    }
    else
    {
      Node *Random = head;
      Node *cRandom = dummy.next;
      while (curr->random != Random)
      {
        Random = Random->next;
        cRandom = cRandom->next;
      }
      tail->random = cRandom;
    }

    curr = curr->next;
    tail = tail->next;
  }
  return dummy.next;
}
Node *copyRandomListUsingmap(Node *head)
{
  map<Node *, Node *> corresponding;
  Node *curr = head;
  Node dummy(0);
  Node *tail = &dummy;
  while (curr)
  {

    tail->next = new Node(curr->val);
    corresponding[curr] = tail->next;
    tail = tail->next;
    curr = curr->next;
  }
  curr = head;
  tail = dummy.next;
  while (curr)
  {
    tail->random = corresponding[curr->random];
    curr = curr->next;
    tail = tail->next;
  }
  return dummy.next;
}

Node *copyRandomListOptimised(Node *head)
{
  Node *curr = head;
  while (curr)
  {
    Node *temp = curr->next;
    curr->next = new Node(curr->val);
    curr->next->next = temp;
    curr = temp;
  }
  curr = head;
  while (curr && curr->next)
  {
    if (curr->random)
    {
      curr->next->random = curr->random->next;
    }
    else
    {
      curr->next->random = nullptr;
    }
    curr = curr->next->next;
  }
  curr = head;
  Node dummy(0);
  Node *tail = &dummy;

  while (curr && curr->next)
  {
    tail->next = curr->next;
    curr->next = curr->next->next;
    curr = curr->next;
    tail = tail->next;
  }
  return dummy.next;
}
int main()
{
  // Example 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
  vector<pair<int, int>> data = {
      {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
  Node *head = buildList(data);
  cout << "Original list: ";
  printList(head);

  // Approach 1: Brute force (no map)
  Node *copy1 = copyRandomList(head);
  cout << "Copied list (Approach 1): ";
  printList(copy1);

  // Approach 2: Using map
  Node *copy2 = copyRandomListUsingmap(head);
  cout << "Copied list (Approach 2): ";
  printList(copy2);

  // Approach 3: Optimized (O(1) space)
  Node *copy3 = copyRandomListOptimised(head);
  cout << "Copied list (Approach 3): ";
  printList(copy3);

  // Example 2: [[1,1],[2,1]]
  vector<pair<int, int>> data2 = {
      {1, 1}, {2, 1}};
  Node *head2 = buildList(data2);
  cout << "\nOriginal list 2: ";
  printList(head2);
  Node *c2 = copyRandomListOptimised(head2);
  cout << "Copied list 2 (Optimized): ";
  printList(c2);

  // Example 3: [[3,null],[3,0],[3,null]]
  vector<pair<int, int>> data3 = {
      {3, -1}, {3, 0}, {3, -1}};
  Node *head3 = buildList(data3);
  cout << "\nOriginal list 3: ";
  printList(head3);
  Node *c3 = copyRandomListOptimised(head3);
  cout << "Copied list 3 (Optimized): ";
  printList(c3);

  return 0;
}