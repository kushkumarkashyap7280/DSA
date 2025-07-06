// 83. Remove Duplicates from Sorted List

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.



Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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

// my solution
// time complexity: O(n)
// space complexity: O(1)
// This solution iterates through the linked list and removes duplicates by comparing the current node's value with the next node's value.
// If they are the same, it deletes the next node and continues; otherwise, it moves to the next node.
// The process continues until the end of the list is reached.
ListNode *deleteDuplicates(ListNode *head)
{
  ListNode *curr = head;
  while (curr && curr->next)
  {
    if (curr->val == curr->next->val)
    {
      ListNode *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}
int main()
{
  // Example usage
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(3);
  // original list: 1 -> 1 -> 2 -> 3 -> 3
  cout << "Original list: ";
  ListNode *current = head;
  while (current)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
  // Remove duplicates
  ListNode *modifiedHead = deleteDuplicates(head);
  // Print the modified list
  current = modifiedHead;
  while (current)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
  // Clean up memory
  while (modifiedHead)
  {
    ListNode *temp = modifiedHead;
    modifiedHead = modifiedHead->next;
    delete temp;
  }
  cout << "Duplicates removed successfully." << endl;
  // Return 0 to indicate successful execution
  cout << "Program completed successfully." << endl;
  return 0;
}