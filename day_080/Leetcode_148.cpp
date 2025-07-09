// 148. Sort List

// https://leetcode.com/problems/sort-list/

/*
Given the head of a linked list, return the list after sorting it in ascending order.


Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  // merge sort
  // time complexity: O(n log n)
  // space complexity: O(log n)
  ListNode *mergeSort(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *beforeCut = nullptr;
    while (fast && fast->next)
    {
      beforeCut = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast)
    {
      beforeCut = slow;
      slow = slow->next;
    }
    beforeCut->next = nullptr;
    ListNode *firstHalf = mergeSort(head);
    ListNode *secondHalf = mergeSort(slow);

    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (firstHalf && secondHalf)
    {
      if (firstHalf->val < secondHalf->val)
      {
        tail->next = firstHalf;
        tail = firstHalf;
        firstHalf = firstHalf->next;
      }
      else
      {
        tail->next = secondHalf;
        tail = secondHalf;
        secondHalf = secondHalf->next;
      }
    }
    tail->next = firstHalf ? firstHalf : secondHalf;

    return dummy.next;
  }
  // time complexity: O(n log n)
  // space complexity: O(log n)
  ListNode *sortList(ListNode *head)
  {
    return mergeSort(head);
  }
};

int main()
{
  Solution solution;
  ListNode *head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
  cout << "Original list: ";
  ListNode *temp = head;
  while (temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  ListNode *sortedHead = solution.sortList(head);
  cout << "Sorted list: ";
  while (sortedHead != nullptr)
  {
    cout << sortedHead->val << " ";
    sortedHead = sortedHead->next;
  }
  cout << endl;

  // clear the memory
  while (head != nullptr)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }

  ListNode *head2 = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0)))));
  cout << "Original list: ";
  temp = head2;
  while (temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  sortedHead = solution.sortList(head2);
  cout << "Sorted list: ";
  temp = sortedHead;
  while (temp != nullptr)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  // clear the memory
  while (head2 != nullptr)
  {
    ListNode *temp = head2;
    head2 = head2->next;
    delete temp;
  }

  return 0;
}
