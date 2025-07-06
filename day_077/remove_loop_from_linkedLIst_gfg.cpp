// Remove loop in Linked List

// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

/*
Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

Custom Input format:

A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation:

The Linked list does not contains any loop.
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};
// Function to remove loop in linked list
// time complexity: O(n)
void removeLoop(Node *head)
{
  Node *fast = head;
  Node *slow = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow)
    {
      Node *pos = head;
      while (pos != slow)
      {
        pos = pos->next;
        slow = slow->next;
      }
      while (pos->next != slow)
      {
        pos = pos->next;
      }
      pos->next = nullptr;
      return;
    }
  }
}
int main()
{
  // Example usage
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = head->next; // Creating a loop for testing
  removeLoop(head);
  // Print the modified list
  Node *current = head;
  while (current)
  {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
  // Clean up memory
  while (head)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  // Output: 1 2 3 4
  // The loop is removed, and the list is printed without the loop.
  return 0;
}