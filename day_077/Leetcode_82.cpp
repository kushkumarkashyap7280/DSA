// 82. Remove Duplicates from Sorted List II

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


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

// my solution recursive
// time complexity: O(n)
// space complexity: O(n)
// This solution recursively deletes duplicates from a sorted linked list. It checks if the current node's value is the same as the next node's value. If they are the same, it skips all nodes with that value and deletes them. If they are different, it keeps the current node and recursively processes the next node. The process continues until all duplicates are removed, and the function returns the modified list.
// Note: This solution uses recursion, which can lead to stack overflow for large lists due to the depth of recursion. An iterative approach would be more efficient for larger lists.
ListNode *deleteDuplicates(ListNode *head)
{
  if (!head || !head->next)
    return head;
  ListNode *currHead = head;
  if (currHead->val == currHead->next->val)
  {
    while (head->next != nullptr && head->val == head->next->val)
    {
      head = head->next;
    }
    head = head->next;
    while (currHead != head)
    {
      ListNode *temp = currHead->next;
      delete currHead;
      currHead = temp;
    }
    return deleteDuplicates(head);
  }
  else
  {
    currHead->next = deleteDuplicates(currHead->next);
    return currHead;
  }
}
int main()
{
  // Example usage
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  // print the original list
  ListNode *temp = head;
  cout << "Original list: ";
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  // Remove duplicates
  // This will modify the list in place and return the new head of the list
  // The original list is: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
  // After removing duplicates, the list will be: 1 -> 2 -> 5
  ListNode *modifiedHead = deleteDuplicates(head);
  // Print the modified list
  ListNode *current = modifiedHead;
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
  // Output: 1 2 5
  // The duplicates are removed, and the list is printed with only distinct values.
  // Return 0 to indicate successful execution
  cout << "Duplicates removed successfully." << endl;
  return 0;
}