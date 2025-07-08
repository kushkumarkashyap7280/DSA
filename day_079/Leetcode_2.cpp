// 2. Add Two Numbers

// https://leetcode.com/problems/add-two-numbers/description/

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Approach 1: In-place addition 
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode *addTwoNumbersInPlace(ListNode *l1, ListNode *l2)
{
  ListNode *head = l1;
  ListNode *prev = nullptr;
  int carry = 0;

  while (l1 && l2)
  {
    int sum = l1->val + l2->val + carry;
    l1->val = sum % 10;
    carry = sum / 10;

    prev = l1;
    l1 = l1->next;
    l2 = l2->next;
  }

  ListNode *rest = l1 ? l1 : l2; // if one list is longer
  if (prev)
    prev->next = rest;

  while (rest)
  {
    int sum = rest->val + carry;
    rest->val = sum % 10;
    carry = sum / 10;

    prev = rest;
    rest = rest->next;
  }

  if (carry)
  {
    prev->next = new ListNode(carry);
  }

  return head;
}

// Approach 2: Using dummy node
// Time Complexity: O(n)
// Space Complexity: O(n)
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  int carry = 0;
  ListNode dummy(0);
  ListNode *tail = &dummy;
  while (l1 || l2 || carry)
  {
    int sum = carry;
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2)
    {
      sum += l2->val;
      l2 = l2->next;
    }

    tail->next = new ListNode(sum % 10);
    tail = tail->next;
    carry = sum / 10;
  }
  return dummy.next;
}
int main()
{
  // Test cases for Approach 1
  ListNode *l1a = new ListNode(2);
  l1a->next = new ListNode(4);
  l1a->next->next = new ListNode(3);

  ListNode *l2a = new ListNode(5);
  l2a->next = new ListNode(6);
  l2a->next->next = new ListNode(4);

  // Test cases for Approach 2
  ListNode *l1b = new ListNode(2);
  l1b->next = new ListNode(4);
  l1b->next->next = new ListNode(3);

  ListNode *l2b = new ListNode(5);
  l2b->next = new ListNode(6);
  l2b->next->next = new ListNode(4);

  // Approach 1: In-place addition
  ListNode *result = addTwoNumbersInPlace(l1a, l2a);

  // Approach 2: Using dummy node
  ListNode *result2 = addTwoNumbers(l1b, l2b);

  // Print the result
  cout << "Approach 1: In-place addition" << endl;
  while (result)
  {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;

  cout << "Approach 2: Using dummy node" << endl;
  while (result2)
  {
    cout << result2->val << " ";
    result2 = result2->next;
  }
  cout << endl;

  return 0;
}
