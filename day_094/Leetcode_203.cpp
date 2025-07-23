// 203. Remove Linked List Elements

// link -https://leetcode.com/problems/remove-linked-list-elements/description/

/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:
Input: head = [], val = 1
Output: []
Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

Constraints:
The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= val <= 50
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
  ListNode *removeElements(ListNode *head, int val)
  {
    while (head && head->val == val)
    {
      ListNode *temp = head;
      head = head->next;
      delete temp;
    }
    if (!head)
      return nullptr;
    ListNode *curr = head->next;
    ListNode *prev = head;
    while (curr)
    {
      if (curr->val == val)
      {
        prev->next = curr->next;
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
      }
      else
      {
        prev = prev->next;
        curr = curr->next;
      }
    }
    return head;
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
  vector<pair<vector<int>, int>> testcases = {
      {{1, 2, 6, 3, 4, 5, 6}, 6},
      {{}, 1},
      {{7, 7, 7, 7}, 7},
      {{1, 2, 2, 1}, 2},
      {{1, 1, 1, 1}, 1},
      {{1, 2, 3, 4, 5}, 10}};
  Solution sol;
  for (auto &[vals, val] : testcases)
  {
    ListNode *head = createList(vals);
    cout << "Input: ";
    printList(head);
    cout << "Remove: " << val << endl;
    ListNode *result = sol.removeElements(head, val);
    cout << "Output: ";
    printList(result);
    cout << endl;
  }
  return 0;
}

/*
Time Complexity: O(N), where N is the number of nodes in the list
Space Complexity: O(1) (in-place, ignoring recursion stack)
*/