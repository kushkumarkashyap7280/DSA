// 237. Delete Node in a Linked List

#include <iostream>
#include <vector>
using namespace std;

// link - https://leetcode.com/problems/delete-node-in-a-linked-list/description/

/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.


Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


Constraints:

The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  /*
  Time Complexity: O(1) - We only need to copy the value and update the pointer
  Space Complexity: O(1) - We use only a constant amount of extra space

  Approach:
  1. Since we don't have access to the previous node, we can't directly delete the current node
  2. Instead, we copy the value from the next node to the current node
  3. Then we delete the next node by updating the current node's next pointer
  4. This effectively removes the current node's value from the list
  */
  void deleteNode(ListNode *node)
  {
    // Copy the value from the next node
    node->val = node->next->val;

    // Store the next node to delete it
    ListNode *temp = node->next;

    // Update the current node's next pointer to skip the next node
    node->next = node->next->next;

    // Delete the next node (free memory)
    delete temp;
  }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(vector<int> &values)
{
  if (values.empty())
    return NULL;

  ListNode *head = new ListNode(values[0]);
  ListNode *current = head;

  for (int i = 1; i < values.size(); i++)
  {
    current->next = new ListNode(values[i]);
    current = current->next;
  }

  return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
  ListNode *current = head;
  cout << "[";
  while (current != NULL)
  {
    cout << current->val;
    if (current->next != NULL)
    {
      cout << " -> ";
    }
    current = current->next;
  }
  cout << "]" << endl;
}

// Helper function to find a node with a specific value
ListNode *findNode(ListNode *head, int value)
{
  ListNode *current = head;
  while (current != NULL)
  {
    if (current->val == value)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Helper function to free memory
void deleteLinkedList(ListNode *head)
{
  while (head != NULL)
  {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main()
{
  Solution solution;

  cout << "=== LeetCode 237: Delete Node in a Linked List ===" << endl
       << endl;

  // Test Case 1: Original example
  cout << "Test Case 1:" << endl;
  vector<int> values1 = {4, 5, 1, 9};
  ListNode *head1 = createLinkedList(values1);
  cout << "Original list: ";
  printLinkedList(head1);

  ListNode *nodeToDelete1 = findNode(head1, 5);
  if (nodeToDelete1 != NULL)
  {
    solution.deleteNode(nodeToDelete1);
    cout << "After deleting node with value 5: ";
    printLinkedList(head1);
  }
  deleteLinkedList(head1);
  cout << endl;

  // Test Case 2: Second example
  cout << "Test Case 2:" << endl;
  vector<int> values2 = {4, 5, 1, 9};
  ListNode *head2 = createLinkedList(values2);
  cout << "Original list: ";
  printLinkedList(head2);

  ListNode *nodeToDelete2 = findNode(head2, 1);
  if (nodeToDelete2 != NULL)
  {
    solution.deleteNode(nodeToDelete2);
    cout << "After deleting node with value 1: ";
    printLinkedList(head2);
  }
  deleteLinkedList(head2);
  cout << endl;

  // Test Case 3: Delete first node (not head)
  cout << "Test Case 3:" << endl;
  vector<int> values3 = {1, 2, 3, 4};
  ListNode *head3 = createLinkedList(values3);
  cout << "Original list: ";
  printLinkedList(head3);

  ListNode *nodeToDelete3 = findNode(head3, 2);
  if (nodeToDelete3 != NULL)
  {
    solution.deleteNode(nodeToDelete3);
    cout << "After deleting node with value 2: ";
    printLinkedList(head3);
  }
  deleteLinkedList(head3);
  cout << endl;

  // Test Case 4: Delete second to last node
  cout << "Test Case 4:" << endl;
  vector<int> values4 = {1, 2, 3, 4, 5};
  ListNode *head4 = createLinkedList(values4);
  cout << "Original list: ";
  printLinkedList(head4);

  ListNode *nodeToDelete4 = findNode(head4, 4);
  if (nodeToDelete4 != NULL)
  {
    solution.deleteNode(nodeToDelete4);
    cout << "After deleting node with value 4: ";
    printLinkedList(head4);
  }
  deleteLinkedList(head4);
  cout << endl;

  // Test Case 5: Single element list (edge case - should not happen per constraints)
  cout << "Test Case 5: Edge case with two elements" << endl;
  vector<int> values5 = {1, 2};
  ListNode *head5 = createLinkedList(values5);
  cout << "Original list: ";
  printLinkedList(head5);

  ListNode *nodeToDelete5 = findNode(head5, 1);
  if (nodeToDelete5 != NULL)
  {
    solution.deleteNode(nodeToDelete5);
    cout << "After deleting node with value 1: ";
    printLinkedList(head5);
  }
  deleteLinkedList(head5);
  cout << endl;

  cout << "=== Algorithm Analysis ===" << endl;
  cout << "Time Complexity: O(1) - Constant time operation" << endl;
  cout << "Space Complexity: O(1) - Constant extra space" << endl;
  cout << endl;
  cout << "Key Insight: Since we can't access the previous node, we copy the next node's value" << endl;
  cout << "and then delete the next node. This effectively removes the current node's value." << endl;

  return 0;
}