// circular singly linked list implementation (Best Practices)
#include <iostream>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

class CSLL
{
  Node *head;
  Node *tail;

public:
  CSLL() : head(nullptr), tail(nullptr) {}
  ~CSLL()
  {
    if (!head)
      return;
    Node *curr = head;
    do
    {
      Node *next = curr->next;
      delete curr;
      curr = next;
    } while (curr != head);
    head = tail = nullptr;
  }
  // Add to head
  void addToHead(int value)
  {
    Node *temp = new Node(value);
    if (!head)
    {
      head = tail = temp;
      temp->next = head;
      return;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
  }
  // Add to tail
  void addToTail(int value)
  {
    Node *temp = new Node(value);
    if (!head)
    {
      head = tail = temp;
      temp->next = head;
      return;
    }
    tail->next = temp;
    tail = temp;
    tail->next = head;
  }
  // Insert at position (0-based)
  void insertAtPosition(int position, int value)
  {
    if (position == 0)
    {
      addToHead(value);
      return;
    }
    Node *curr = head;
    int i = 0;
    while (curr->next != head && i < position - 1)
    {
      curr = curr->next;
      i++;
    }
    Node *temp = new Node(value);
    temp->next = curr->next;
    curr->next = temp;
    if (curr == tail)
      tail = temp;
  }
  // Delete at position (0-based)
  void deleteAtPosition(int position)
  {
    if (!head)
      return;
    if (position == 0)
    {
      if (head == tail)
      {
        delete head;
        head = tail = nullptr;
        return;
      }
      Node *toDelete = head;
      head = head->next;
      tail->next = head;
      delete toDelete;
      return;
    }
    Node *curr = head;
    int i = 0;
    while (curr->next != head && i < position - 1)
    {
      curr = curr->next;
      i++;
    }
    Node *toDelete = curr->next;
    if (toDelete == head)
      return; // position out of range
    curr->next = toDelete->next;
    if (toDelete == tail)
      tail = curr;
    delete toDelete;
  }
  // Print the list in rail structure
  void printRail() const
  {
    if (!head)
    {
      cout << "[ ]" << endl;
      return;
    }
    Node *curr = head;
    cout << "[ ";
    do
    {
      cout << curr->val;
      if (curr->next != head)
        cout << " -> ";
      curr = curr->next;
    } while (curr != head);
    cout << " ]" << endl;
  }
};

int main()
{
  CSLL list;
  list.addToHead(1);
  list.addToHead(2);
  list.addToTail(3);
  list.addToTail(4);
  cout << "Initial list (rail):\n";
  list.printRail();
  list.insertAtPosition(2, 99);
  cout << "\nAfter inserting 99 at position 2 (rail):\n";
  list.printRail();
  list.deleteAtPosition(2);
  cout << "\nAfter deleting node at position 2 (rail):\n";
  list.printRail();
  return 0;
}