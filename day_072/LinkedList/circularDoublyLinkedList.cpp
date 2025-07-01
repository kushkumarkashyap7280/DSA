// Circular Doubly Linked List implementation (Best Practices)
#include <iostream>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;
  Node(int v) : val(v), next(nullptr), prev(nullptr) {}
};

class CDLL
{
  Node *head;
  Node *tail;

public:
  CDLL() : head(nullptr), tail(nullptr) {}
  ~CDLL()
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
      temp->next = temp->prev = temp;
      return;
    }
    temp->next = head;
    temp->prev = tail;
    head->prev = temp;
    tail->next = temp;
    head = temp;
  }
  // Add to tail
  void addToTail(int value)
  {
    Node *temp = new Node(value);
    if (!head)
    {
      head = tail = temp;
      temp->next = temp->prev = temp;
      return;
    }
    temp->next = head;
    temp->prev = tail;
    tail->next = temp;
    head->prev = temp;
    tail = temp;
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
    temp->prev = curr;
    curr->next->prev = temp;
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
      head->prev = tail;
      delete toDelete;
      return;
    }
    Node *curr = head;
    int i = 0;
    while (curr->next != head && i < position)
    {
      curr = curr->next;
      i++;
    }
    if (curr == head)
      return; // position out of range
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    if (curr == tail)
      tail = curr->prev;
    delete curr;
  }
  // Print the list in rail structure (forward)
  void printRailForward() const
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
        cout << " <-> ";
      curr = curr->next;
    } while (curr != head);
    cout << " ]" << endl;
  }
  // Print the list in rail structure (backward)
  void printRailBackward() const
  {
    if (!tail)
    {
      cout << "[ ]" << endl;
      return;
    }
    Node *curr = tail;
    cout << "[ ";
    do
    {
      cout << curr->val;
      if (curr->prev != tail)
        cout << " <-> ";
      curr = curr->prev;
    } while (curr != tail);
    cout << " ]" << endl;
  }
};

int main()
{
  CDLL list;
  list.addToHead(1);
  list.addToHead(2);
  list.addToTail(3);
  list.addToTail(4);
  cout << "Initial list (forward rail):\n";
  list.printRailForward();
  cout << "Initial list (backward rail):\n";
  list.printRailBackward();
  list.insertAtPosition(2, 99);
  cout << "\nAfter inserting 99 at position 2 (forward rail):\n";
  list.printRailForward();
  list.deleteAtPosition(2);
  cout << "\nAfter deleting node at position 2 (forward rail):\n";
  list.printRailForward();
  return 0;
}
