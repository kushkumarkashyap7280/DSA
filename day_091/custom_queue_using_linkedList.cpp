// lets build cutom queue using linked list;

#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    this->next = nullptr;
  }
};

class LL_queue
{
  int n;
  Node *head;
  Node *tail;

public:
  LL_queue() : n(0), head(nullptr), tail(nullptr) {}

  ~LL_queue()
  {
    while (head)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    tail= nullptr;
  }

  void push(int a)
  {
    if (n == 0)
    {
      tail = new Node(a);
      head = tail;
    }
    else
    {
      tail->next = new Node(a);
      tail = tail->next;
    }
    n++;
  }
  void pop()
  {
    if(!head) return;
    if(head == tail){
      tail = nullptr;
    }
    Node * temp = head;
    head = head->next;
    delete temp;
    n--;
  }

  int front(){
    if(!head)  throw runtime_error("queue is empty");
    return head->val;
  }
  bool isempty(){
    return head == nullptr;
  }

  int size(){
    return n;
  }
  void iterate() {
    Node* curr = head;
    cout << "Queue: ";
    while (curr) {
      cout << curr->val;
      if (curr->next) cout << " -> ";
      curr = curr->next;
    }
    cout << endl;
  }
  
};

int main(){
  LL_queue k = LL_queue();
  
  cout << " size is : " << k.size() << endl;
  cout << " is k empty " << k.isempty() << endl;
  k.push(4);
  k.iterate();

  cout << " size is : " << k.size() << endl;
  cout << "front is : " <<  k.front() << endl;
  cout << " is k empty " << k.isempty() << endl;

  k.push(5);
  k.iterate();
  cout << " size is : " << k.size() << endl;
  cout << "front is : " <<  k.front() << endl;
  cout << " is k empty " << k.isempty() << endl;

  k.pop();
  k.iterate();
  cout << " size is : " << k.size() << endl;
  cout << "front is : " <<  k.front() << endl;
  cout << " is k empty " << k.isempty() << endl;
}
