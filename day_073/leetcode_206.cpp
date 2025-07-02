// 206. Reverse Linked List

// https://leetcode.com/problems/reverse-linked-list/

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *reverseList(ListNode *head)
{
  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr != nullptr)
  {
    ListNode *nextTemp = curr->next; // Store the next node
    curr->next = prev;               // Reverse the link
    prev = curr;                     // Move prev to current
    curr = nextTemp;                 // Move to the next node
  }

  return prev; // New head of the reversed list
}
int main()
{
  // Example usage:
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  // print the original list
  ListNode *current = head;
  while (current != nullptr)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
  // Reverse the linked list
  ListNode *reversedHead = reverseList(head);

  // Print the reversed list
  current = reversedHead;
  while (current != nullptr)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;

  // Clean up memory (not shown here, but should be done in practice)
  return 0;
}