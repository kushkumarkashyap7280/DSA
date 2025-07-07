// Sort linked list of 0s 1s 2s

// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937

/*
Problem statement
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.



Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
1 0 2 1 0 2 1


Sample Output 1:
0 0 1 1 1 2 2


Explanation Of Sample Input 1:
Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

Explanation:
In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.


Sample Input 2:
8
2 1 0 2 1 0 0 2


Sample Output 2:
0 0 0 1 1 2 2 2


Follow Up:
Can you solve this without updating the Nodes of the given linked list?


Constraints :
1 <= N <= 10^3
0 <= data <= 2

Where 'N' is the length of the linked list.

Time Limit: 1 sec
*/

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
  int data;
  Node *next;

  Node(int val) : data(val), next(nullptr) {}
};

// Function to sort the linked list of 0s, 1s, and 2s
// This function takes the head of the linked list as input and returns the head of the sorted linked list.
// The function counts the occurrences of each value (0, 1, 2) and then overwrites the original linked list with the counted values.
// Time complexity: O(n), where n is the number of nodes in the linked list.
// Space complexity: O(1), as we are not using any additional data structures that grow with input size.
// Note: This approach modifies the original linked list nodes.
// and also good if interviewers ask to solve this without updating data in the nodes.
// In that case, we can create a new linked list and append the nodes in sorted order
Node *sortList(Node *head)
{
  int num0 = 0;
  int num1 = 0;
  int num2 = 0;
  Node *curr = head;
  while (curr)
  {
    switch (curr->data)
    {
    case 0:
      num0++;
      break;
    case 1:
      num1++;
      break;
    case 2:
      num2++;
      break;
    }
    curr = curr->next;
  }
  curr = head;
  while (num0)
  {
    curr->data = 0;
    num0--;
    curr = curr->next;
  }
  while (num1)
  {
    curr->data = 1;
    num1--;
    curr = curr->next;
  }
  while (num2)
  {
    curr->data = 2;
    num2--;
    curr = curr->next;
  }
  return head;
}

// three list approach
Node *sortListoptimised(Node *head)
{
  if (!head || !head->next)
    return head;

  // Create dummy heads for 0s, 1s, 2s
  Node dummy0(0), dummy1(0), dummy2(0);
  Node *tail0 = &dummy0, *tail1 = &dummy1, *tail2 = &dummy2;

  Node *curr = head;

  while (curr)
  {
    if (curr->data == 0)
    {
      tail0->next = curr;
      tail0 = tail0->next;
    }
    else if (curr->data == 1)
    {
      tail1->next = curr;
      tail1 = tail1->next;
    }
    else
    {
      tail2->next = curr;
      tail2 = tail2->next;
    }
    curr = curr->next;
  }

  // Now connect the lists together
  tail0->next = dummy1.next ? dummy1.next : dummy2.next;
  tail1->next = dummy2.next;
  tail2->next = nullptr;

  return dummy0.next;
}

int main()
{
  // Create a linked list for testing
  Node *head = new Node(1);
  head->next = new Node(0);
  head->next->next = new Node(2);
  head->next->next->next = new Node(1);
  head->next->next->next->next = new Node(2);
  head->next->next->next->next->next = new Node(1);
  head->next->next->next->next->next->next = new Node(0);
  head->next->next->next->next->next->next->next = new Node(2);
  // Print the original linked list
  cout << "Original linked list: ";
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
  // Sort the linked list
  head = sortList(head);
  // Print the sorted linked list
  Node *curr = head;
  cout << "Sorted linked list: ";
  while (curr)
  {
    cout << curr->data << " ";
    curr = curr->next; // ...existing code...
    cout << endl;

    // Sort the linked list using counting approach
    head = sortList(head);
    cout << "Sorted linked list (counting approach): ";
    curr = head;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;

    // Now demonstrate the 3-list approach
    // Re-create the original list for fair comparison
    Node *head2 = new Node(1);
    head2->next = new Node(0);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(1);
    head2->next->next->next->next = new Node(2);
    head2->next->next->next->next->next = new Node(1);
    head2->next->next->next->next->next->next = new Node(0);
    head2->next->next->next->next->next->next->next = new Node(2);

    cout << "Original linked list (for 3-list approach): ";
    temp = head2;
    while (temp)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;

    head2 = sortListoptimised(head2);
    cout << "Sorted linked list (3-list approach): ";
    curr = head2;
    while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;

    // Clean up memory for both lists
    while (head)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    while (head2)
    {
      Node *temp = head2;
      head2 = head2->next;
      delete temp;
    }
    cout << "Memory cleaned up." << endl;
    cout << "Program completed successfully." << endl;

    return 0;
  }

  cout << endl;

  // using 3 list approach
// ...existing code...
cout << endl;

// Sort the linked list using counting approach
head = sortList(head);
cout << "Sorted linked list (counting approach): ";
curr = head;
while (curr)
{
  cout << curr->data << " ";
  curr = curr->next;
}
cout << endl;

// Now demonstrate the 3-list approach
// Re-create the original list for fair comparison
Node *head2 = new Node(1);
head2->next = new Node(0);
head2->next->next = new Node(2);
head2->next->next->next = new Node(1);
head2->next->next->next->next = new Node(2);
head2->next->next->next->next->next = new Node(1);
head2->next->next->next->next->next->next = new Node(0);
head2->next->next->next->next->next->next->next = new Node(2);

cout << "Original linked list (for 3-list approach): ";
temp = head2;
while (temp)
{
  cout << temp->data << " ";
  temp = temp->next;
}
cout << endl;

head2 = sortListoptimised(head2);
cout << "Sorted linked list (3-list approach): ";
curr = head2;
while (curr)
{
  cout << curr->data << " ";
  curr = curr->next;
}
cout << endl;

// Clean up memory for both lists
while (head)
{
  Node *temp = head;
  head = head->next;
  delete temp;
}
while (head2)
{
  Node *temp = head2;
  head2 = head2->next;
  delete temp;
}
cout << "Memory cleaned up." << endl;
cout << "Program completed successfully." << endl;

return 0;
  // Clean up memory
  while (head)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  cout << "Memory cleaned up." << endl;
  // Return 0 to indicate successful execution
  cout << "Program completed successfully." << endl;

  return 0;
}