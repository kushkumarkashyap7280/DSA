// ================== custom Circular queue ===========================


#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node* next;

  Node(int val){
    this->val = val;
    this->next = nullptr;
  }
  Node(int val , Node* next){
    this->val = val;
    this->next = next;
  }
  
};

class C_queue{
  int s;
  Node* head;
  Node* tail;
  
  public :

  C_queue(){
    this->s = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  ~C_queue(){
    if (!head) return;
     tail->next = nullptr;
    while(head){
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  int size(){
    return s;
  }

  void push(int val){
    if(s ==0){
      head = new Node(val);
      tail = head;
      tail->next = head;
    }else{
      tail->next = new Node(val , tail->next);
      tail = tail->next;
    }
    s++;
  }

 int   pop(){
    if(s == 0) {
      cout << "circular queue is alredy empty " << endl; 
      return -1;
    }
     int ret = head->val;
    if(s == 1){
       tail = nullptr;
       delete head;
       head = nullptr;
    }else{
      head = head->next;
      delete tail->next;
      tail->next = head;
    }
    s--;
    return ret;
  }

  int front(){
    if(s == 0) {
      cout << "circular queue is alredy empty " << endl; 
      return -1;
    }
    return head->val;
  }

  bool isempty(){
    return s == 0;
  }

  void iterate(){
    if(s == 0) {
      cout << "circular queue is alredy empty " << endl; 
      return;
    }
    Node* temp = head;
    cout << "front ->"<< temp->val << " " ;
    temp = temp->next;
    while(temp != head){
      cout << "->"<< temp->val << " " ;
      temp = temp->next;
    }
  }
};

int main(){

     C_queue* c = new C_queue();

     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->push(5);

     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->push(6);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


     c->push(7);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


     c->push(8);
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

     c->pop();
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;

  return 0;
}





