// 430. Flatten a Multilevel Doubly Linked List

// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.



Example 1:


Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:


Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:

Input: head = []
Output: []
Explanation: There could be empty list in the input.


Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105


How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
*/

#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
  Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

// my approach
// time complexity: O(n)
// space complexity: O(1)
Node *flatten(Node *head)
{
  if (!head)
    return head;
  Node *curr = head;
  while (curr)
  {
    if (curr->child)
    {
      Node *next = curr->next;
      Node *end = curr->child;
      while (end->next)
      {
        end = end->next;
      }
      curr->next = curr->child;
      curr->child->prev = curr;
      curr->child = nullptr;
      end->next = next;
      if (next)
      {
        next->prev = end;
      }
    }
    curr = curr->next;
  }
  return head;
}

// using recursion
// time complexity: O(n)
// space complexity: O(n)
Node *flattenUsingRecursion(Node *head)
{
  if (!head)
    return nullptr;

  Node *curr = head;

  while (curr)
  {
    if (curr->child)
    {
      Node *next = curr->next;
      Node *childHead = flatten(curr->child);

      curr->next = childHead;
      childHead->prev = curr;
      curr->child = nullptr;

      Node *tail = childHead;
      while (tail->next)
      {
        tail = tail->next;
      }

      tail->next = next;
      if (next)
        next->prev = tail;
    }
    curr = curr->next;
  }

  return head;
}

int main()
{
  // Assuming Node is defined as:
  // struct Node {
  //   int val;
  //   Node* prev;
  //   Node* next;
  //   Node* child;
  //   Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
  // };

  // Create main list: 1-2-3-4-5-6
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->prev = head;
  head->next->next = new Node(3);
  head->next->next->prev = head->next;
  head->next->next->next = new Node(4);
  head->next->next->next->prev = head->next->next;
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->prev = head->next->next->next;
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->prev = head->next->next->next->next;

  // Create child list for node 3: 7-8-9-10
  Node *child1 = new Node(7);
  child1->next = new Node(8);
  child1->next->prev = child1;
  child1->next->next = new Node(9);
  child1->next->next->prev = child1->next;
  child1->next->next->next = new Node(10);
  child1->next->next->next->prev = child1->next->next;
  head->next->next->child = child1; // 3->child = 7

  // Create child list for node 8: 11-12
  Node *child2 = new Node(11);
  child2->next = new Node(12);
  child2->next->prev = child2;
  child1->next->child = child2; // 8->child = 11


  /*
  here see the list
  1-2-3-4-5-6
         |
         7-8-9-10
             |
             11-12
  */

  // see original list and child list
  Node *temp = head;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  temp = head->next->next->child;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  cout << "child list: ";
  temp = head->next->next->child;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  Node *flattened = flatten(head);
  cout << "flattened list: ";
  while (flattened)
  {
    cout << flattened->val << " ";
    flattened = flattened->next;
  }
  cout << endl;

  // clear the memory
  while (head)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  return 0;
}