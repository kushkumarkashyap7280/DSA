#include <iostream>
#include <vector>
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

// 23. Merge k Sorted Lists

// link - https://leetcode.com/problems/merge-k-sorted-lists/description/

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;
    return dummy.next;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    int n = lists.size();
    if (n == 0)
      return nullptr;

    while (n > 1)
    {
      int k = (n + 1) / 2;
      for (int i = 0; i < n / 2; i++)
      {
        lists[i] = mergeTwoLists(lists[i], lists[i + k]);
      }
      n = k;
    }
    return lists[0];
  }
};

// Helper function to create a linked list from a vector
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

// Helper function to print a linked list
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
  // Example 1: lists = [[1,4,5],[1,3,4],[2,6]]
  vector<ListNode *> lists1 = {
      createList({1, 4, 5}),
      createList({1, 3, 4}),
      createList({2, 6})};
  Solution sol;
  ListNode *merged1 = sol.mergeKLists(lists1);
  cout << "Merged list 1: ";
  printList(merged1); // Output: 1->1->2->3->4->4->5->6

  // Example 2: lists = []
  vector<ListNode *> lists2 = {};
  ListNode *merged2 = sol.mergeKLists(lists2);
  cout << "Merged list 2: ";
  printList(merged2); // Output: (empty)

  // Example 3: lists = [[]]
  vector<ListNode *> lists3 = {nullptr};
  ListNode *merged3 = sol.mergeKLists(lists3);
  cout << "Merged list 3: ";
  printList(merged3); // Output: (empty)

  return 0;
}

/*
Time Complexity: O(N log k), where N is the total number of nodes and k is the number of lists.
Space Complexity: O(1) (ignoring the output list and recursion stack, as merging is done in-place).
*/