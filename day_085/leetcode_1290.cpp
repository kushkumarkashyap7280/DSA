// 1290. Convert Binary Number in a Linked List to Integer

// link - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0


Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
public:
  int getDecimalValue(ListNode *head)
  {
    if (!head)
      return -1;
    int ans = 0;
    while (head)
    {
      ans <<= 1;
      ans |= head->val & 1;
      head = head->next;
    }
    return ans;
  }
};

int main()
{
  // Example: head = [1,0,1]
  ListNode *n3 = new ListNode(1);
  ListNode *n2 = new ListNode(0, n3);
  ListNode *n1 = new ListNode(1, n2);
  Solution sol;
  cout << "Decimal value: " << sol.getDecimalValue(n1) << endl; // Output: 5
  // Clean up
  delete n1;
  delete n2;
  delete n3;
  return 0;
}