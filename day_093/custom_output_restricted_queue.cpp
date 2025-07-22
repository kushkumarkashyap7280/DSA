// ==================== OUTPUT RESTRICTED QUEUE ==========================
// it has only allowed  to pop front ;
// it has allowed to push from both side


#include <iostream>
using namespace std;


struct Node
{
  int data;
  Node *next;

  Node(int data , Node* next){
      this->data =data;
      this->next = next;
  }
};

class ORQ
{
  Node *head;
  Node *tail;
  int s;

public:
 
   ORQ(){
    this->head = nullptr;
    this->tail = nullptr;
    this->s =0;
   }

   ~ORQ(){
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
    if(s == 0){
      tail = new Node(data, tail);
      head = tail;
    }else{
      tail->next = new Node(data , nullptr);
      tail = tail->next;
    }
    s++;
  }

  void push_front(int data){
     if(s == 0){
      head = new Node(data , head);
      tail = head;
     }else{
        head  = new Node(data , head);
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

   ORQ* c = new ORQ();

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

       c->pop_front();
     cout << "size is :" << c->size() << endl;
     cout << "queue is empty ?  " << ((c->isempty()) ? "Yes" : "No") << endl;
     cout << " iterate queue :" << endl;
     c->iterate();
     cout << "front is :" << c->front() << endl;


}
