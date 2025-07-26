#include <bits/stdc++.h>
using namespace std;

// 24. Swap Nodes in Pairs

// link - https://leetcode.com/problems/swap-nodes-in-pairs/description/

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]



Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
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

// Definition of ListNode
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
  // Recursive Solution
  // Time Complexity: O(n) where n is the number of nodes
  // Space Complexity: O(n) due to recursion stack
  ListNode *swapPairs(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *first = head;
    ListNode *second = head->next;

    // swap first two nodes
    first->next = swapPairs(second->next);
    second->next = first;

    return second; // new head after swap
  }

  // Iterative Solution (Alternative approach)
  // Time Complexity: O(n) where n is the number of nodes
  // Space Complexity: O(1) constant space
  ListNode *swapPairsIterative(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prev = dummy;

    while (prev->next && prev->next->next)
    {
      ListNode *first = prev->next;
      ListNode *second = prev->next->next;

      // Swap the nodes
      first->next = second->next;
      second->next = first;
      prev->next = second;

      // Move to next pair
      prev = first;
    }

    ListNode *result = dummy->next;
    delete dummy;
    return result;
  }
};

// Utility function to create a linked list from vector
ListNode *createLinkedList(vector<int> &values)
{
  if (values.empty())
    return nullptr;

  ListNode *head = new ListNode(values[0]);
  ListNode *current = head;

  for (int i = 1; i < values.size(); i++)
  {
    current->next = new ListNode(values[i]);
    current = current->next;
  }

  return head;
}

// Utility function to print linked list
void printLinkedList(ListNode *head)
{
  ListNode *current = head;
  cout << "[";
  while (current)
  {
    cout << current->val;
    if (current->next)
      cout << ",";
    current = current->next;
  }
  cout << "]" << endl;
}

// Utility function to free linked list memory
void freeLinkedList(ListNode *head)
{
  while (head)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main()
{
  Solution sol;

  // Test cases
  vector<vector<int>> testCases = {
      {1, 2, 3, 4},   // Expected: [2,1,4,3]
      {},             // Expected: []
      {1},            // Expected: [1]
      {1, 2, 3},      // Expected: [2,1,3]
      {1, 2, 3, 4, 5} // Expected: [2,1,4,3,5]
  };

  cout << "Testing Recursive Solution:" << endl;
  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << (i + 1) << ": ";
    ListNode *head = createLinkedList(testCases[i]);
    cout << "Input: ";
    printLinkedList(head);

    ListNode *result = sol.swapPairs(head);
    cout << "Output: ";
    printLinkedList(result);
    cout << endl;

    freeLinkedList(result);
  }

  cout << "\nTesting Iterative Solution:" << endl;
  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << (i + 1) << ": ";
    ListNode *head = createLinkedList(testCases[i]);
    cout << "Input: ";
    printLinkedList(head);

    ListNode *result = sol.swapPairsIterative(head);
    cout << "Output: ";
    printLinkedList(result);
    cout << endl;

    freeLinkedList(result);
  }

  cout << "\nTime Complexity Analysis:" << endl;
  cout << "Recursive Solution:" << endl;
  cout << "- Time Complexity: O(n) - We visit each node exactly once" << endl;
  cout << "- Space Complexity: O(n) - Due to recursion stack depth" << endl;
  cout << endl;
  cout << "Iterative Solution:" << endl;
  cout << "- Time Complexity: O(n) - We visit each node exactly once" << endl;
  cout << "- Space Complexity: O(1) - Only using constant extra space" << endl;

  return 0;
}