// Doubly linked list implementation in C++ (Best Practices)
#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node *prev;
  Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}
  ~DoublyLinkedList()
  {
    Node *curr = head;
    while (curr)
    {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }
  // Add to head
  void addToHead(int value)
  {
    Node *temp = new Node(value);
    temp->next = head;
    if (head)
      head->prev = temp;
    head = temp;
    if (!tail)
      tail = head;
  }
  // Add to tail
  void addToTail(int value)
  {
    Node *temp = new Node(value);
    temp->prev = tail;
    if (tail)
      tail->next = temp;
    tail = temp;
    if (!head)
      head = tail;
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
    while (curr && i < position - 1)
    {
      curr = curr->next;
      i++;
    }
    if (!curr)
    {
      addToTail(value);
      return;
    }
    Node *temp = new Node(value);
    temp->next = curr->next;
    temp->prev = curr;
    if (curr->next)
      curr->next->prev = temp;
    curr->next = temp;
    if (!temp->next)
      tail = temp;
  }
  // Delete at position (0-based)
  void deleteAtPosition(int position)
  {
    if (!head)
      return;
    if (position == 0)
    {
      Node *toDelete = head;
      head = head->next;
      if (head)
        head->prev = nullptr;
      else
        tail = nullptr;
      delete toDelete;
      return;
    }
    Node *curr = head;
    int i = 0;
    while (curr && i < position)
    {
      curr = curr->next;
      i++;
    }
    if (!curr)
      return;
    if (curr->prev)
      curr->prev->next = curr->next;
    if (curr->next)
      curr->next->prev = curr->prev;
    if (curr == tail)
      tail = curr->prev;
    delete curr;
  }
  // Print the list forward (rail)
  void printRailForward() const
  {
    Node *curr = head;
    cout << "[ ";
    while (curr)
    {
      cout << curr->value;
      if (curr->next)
        cout << " <-> ";
      curr = curr->next;
    }
    cout << " ]" << endl;
  }
  // Print the list backward (rail)
  void printRailBackward() const
  {
    Node *curr = tail;
    cout << "[ ";
    while (curr)
    {
      cout << curr->value;
      if (curr->prev)
        cout << " <-> ";
      curr = curr->prev;
    }
    cout << " ]" << endl;
  }
};

int main()
{
  DoublyLinkedList dll;
  dll.addToHead(10);
  dll.addToTail(20);
  dll.addToHead(5);
  cout << "Initial list (forward rail):\n";
  dll.printRailForward();
  cout << "Initial list (backward rail):\n";
  dll.printRailBackward();
  dll.insertAtPosition(2, 15);
  cout << "\nAfter inserting 15 at position 2 (forward rail):\n";
  dll.printRailForward();
  dll.deleteAtPosition(1);
  cout << "\nAfter deleting node at position 1 (forward rail):\n";
  dll.printRailForward();
  cout << "\nAfter deleting node at position 1 (backward rail):\n";
  dll.printRailBackward();
  return 0;
}
