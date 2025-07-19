// 143. Reorder List

// link - https://leetcode.com/problems/reorder-list/description

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
using namespace std;

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
  ListNode *reverselist(ListNode *head)
  {
    if (!head)
      return nullptr;
    ListNode *prev = nullptr;
    while (head)
    {
      ListNode *temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }
    return prev;
  }
  void reorderList(ListNode *head)
  {
    if (!head || !head->next)
      return;
    ListNode *prev = nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
      if (!prev)
      {
        prev = head;
      }
      else
      {
        prev = prev->next;
      }
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast)
    {
      prev = prev->next;
      slow = slow->next;
    }
    prev->next = nullptr;
    slow = reverselist(slow);
    fast = head;
    while (slow)
    {
      ListNode *temp1 = fast->next;
      ListNode *temp2 = slow->next;
      fast->next = slow;
      slow->next = temp1;
      fast = temp1;
      slow = temp2;
    }
    return;
  }
};

// Helper to create a linked list from vector
ListNode *createList(const vector<int> &vals)
{
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int v : vals)
  {
    tail->next = new ListNode(v);
    tail = tail->next;
  }
  return dummy.next;
}

// Helper to print a linked list
void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val;
    if (head->next)
      cout << "->";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  vector<vector<int>> testcases = {
      {1, 2, 3, 4},
      {1, 2, 3, 4, 5}};
  Solution sol;
  for (auto &vals : testcases)
  {
    ListNode *head = createList(vals);
    cout << "Original: ";
    printList(head);
    sol.reorderList(head);
    cout << "Reordered: ";
    printList(head);
    cout << endl;
  }
  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the list.
Space Complexity: O(1) (in-place, ignoring recursion stack for reversal which is iterative here)
*/