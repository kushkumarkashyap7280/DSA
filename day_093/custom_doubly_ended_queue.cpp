// ========================== DOUBLY ENDED QUEUE =====================

// it has only allowed  to insert back
// it has allowed to pop from both side


#include <iostream>
using namespace std;


struct Node
{
  int data;
  Node *next;
  Node *prev;

  Node(int data , Node* prev){
      this->data =data;
      this->prev = prev;
      this->next = nullptr;
  }
};

class IRQ
{
  Node *head;
  Node *tail;
  int s;

public:
 
   IRQ(){
    this->head = nullptr;
    this->tail = nullptr;
    this->s =0;
   }

   ~IRQ(){
    if(tail) tail = nullptr;
    while(head){
      Node* temp = head;
      head = head->next;
      delete temp;
    }
   }

  int size(){
    return s;
  }
  void push_back(int data)
  {
    if(head){
       tail->next = new Node(data, tail);
       tail = tail->next;
    }else{
      head = new Node(data, head);
      tail = head;
    }
    s++;
  }

  void push_front(int data){
    if(head){
      Node* temp  = head;
      head->prev = new Node( data, nullptr);
      head = head->prev;
      head->next = temp;
    }else{
      head = new Node(data , head);
      tail = head;
    }
    s++;
  }

  int front(){
    if(!head) return -1;
    return head->data;
  }
  int pop_front(){
    if(s == 0) return -1;
    int ret = head->data;
    if(s == 1){
      tail = nullptr;
      delete head;
      head = nullptr;
    }else{
      Node* temp = head;
      head = head->next;
      head->prev = nullptr;
      delete temp;
    }
    s--;
    return ret;
  }
  int pop_back(){
    if(!tail) return -1;
    int ret = tail->data;
    if(s == 1){
      head = nullptr;
      delete tail;
      tail  =nullptr;
    }else{
      Node*  temp = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete temp;
    }
    s--;
    return ret;
  }

  bool isempty(){
    return s == 0;
  }

  void iterate(){
    if(!head) return;
    Node* curr = head;
    cout << "front : " ;

    while(curr){
      cout << " -> " << curr->data ;
      curr = curr->next;
    }

    cout << endl;
  }

};


int main (){

   IRQ* c = new IRQ();

     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->push_back(5);

     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->push_front(6);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


     c->push_back(7);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


     c->push_front(8);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->pop_front();
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

       c->pop_back();
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


}
