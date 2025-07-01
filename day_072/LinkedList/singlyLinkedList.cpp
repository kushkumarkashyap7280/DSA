// singly linked list implementation in C++ (Best Practices)
#include <iostream>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node(int value) : value(value), next(nullptr) {}
};

class SinglyLinkedList
{
  Node *head;
  Node *tail;

public:
  SinglyLinkedList() : head(nullptr), tail(nullptr) {}
  ~SinglyLinkedList()
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
    head = temp;
    if (!tail)
      tail = head;
  }
  // Add to tail
  void addToTail(int value)
  {
    Node *temp = new Node(value);
    if (!head)
    {
      head = tail = temp;
      return;
    }
    tail->next = temp;
    tail = temp;
  }
  // Insert at position (0-based, after pos-1)
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
      if (!head)
        tail = nullptr;
      delete toDelete;
      return;
    }
    Node *curr = head;
    int i = 0;
    while (curr->next && i < position - 1)
    {
      curr = curr->next;
      i++;
    }
    if (!curr->next)
      return;
    Node *toDelete = curr->next;
    curr->next = toDelete->next;
    if (!curr->next)
      tail = curr;
    delete toDelete;
  }
  // Print the list in rail structure
  void printRail() const
  {
    Node *curr = head;
    cout << "[ ";
    while (curr)
    {
      cout << curr->value;
      if (curr->next)
        cout << " -> ";
      curr = curr->next;
    }
    cout << " ]" << endl;
  }
  // Search for a value, returns position or -1 if not found
  int search(int value) const
  {
    Node *curr = head;
    int pos = 0;
    while (curr)
    {
      if (curr->value == value)
        return pos;
      curr = curr->next;
      pos++;
    }
    return -1;
  }

  // Get length/size of the list
  int size() const
  {
    int count = 0;
    Node *curr = head;
    while (curr)
    {
      count++;
      curr = curr->next;
    }
    return count;
  }

  // Reverse the list
  void reverse()
  {
    Node *prev = nullptr;
    Node *curr = head;
    tail = head;
    while (curr)
    {
      Node *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }

  // Check if empty
  bool isEmpty() const
  {
    return head == nullptr;
  }

  // Clear the list
  void clear()
  {
    Node *curr = head;
    while (curr)
    {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
    head = tail = nullptr;
  }

  // Get value at a specific position
  int getAt(int position) const
  {
    Node *curr = head;
    int i = 0;
    while (curr && i < position)
    {
      curr = curr->next;
      i++;
    }
    if (!curr)
      throw out_of_range("Index out of range");
    return curr->value;
  }

  // Find middle node (returns value)
  int findMiddle() const
  {
    if (!head)
      throw out_of_range("Empty list");
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->value;
  }

  // Detect cycle (Floyd’s algorithm)
  bool hasCycle() const
  {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

int main()
{
  SinglyLinkedList list;
  list.addToHead(1);
  list.addToHead(5);
  list.addToHead(6);
  list.addToHead(7);
  list.addToHead(8);
  list.addToHead(9);
  list.addToHead(10);
  cout << "Initial list (rail):\n";
  list.printRail();
  list.addToTail(4);
  cout << "\nAfter adding to tail (rail):\n";
  list.printRail();
  list.insertAtPosition(4, 99);
  cout << "\nAfter inserting 99 at position 4 (rail):\n";
  list.printRail();
  list.deleteAtPosition(4);
  cout << "\nAfter deleting node at position 4 (rail):\n";
  list.printRail();
  return 0;
}