//61. Rotate List

//https://leetcode.com/problems/rotate-list/

/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
ListNode* rotateRight(ListNode* head, int k) {
  if (!head || !head->next || k == 0) return head;

  // Step 1: compute length
  int len = 1;
  ListNode* tail = head;
  while (tail->next) {
      tail = tail->next;
      len++;
  }

  // Step 2: effective rotations
  k = k % len;
  if (k == 0) return head;

  // Step 3: find the new tail (at position len-k-1)
  ListNode* newTail = head;
  for (int i = 0; i < len - k - 1; i++) {
      newTail = newTail->next;
  }

  // Step 4: set the new head and rewire
  ListNode* newHead = newTail->next;
  newTail->next = nullptr;
  tail->next = head;

  return newHead;
}


  //helper function to print the list
  void printList(ListNode* head) {
    while (head) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }
};


int main() {
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "Original list: ";
  sol.printList(head);
  head = sol.rotateRight(head, 2);
  cout << "Rotated list: ";
  sol.printList(head);
  return 0;
}