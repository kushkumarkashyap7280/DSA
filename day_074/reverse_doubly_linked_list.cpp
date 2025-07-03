// reverse doubly linked list

//http://geeksforgeeks.org/reverse-a-doubly-linked-list/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// 
Node * reverseDLL(Node*head){
   Node * prev = nullptr;
   while(head != nullptr){
    Node * nextNode = head->next;
    head->next = prev;
    head->prev= nextNode;
    prev = head;
    head = nextNode;
   }
   return prev;
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    
    cout << "Original List: ";
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;

    Node* reversedHead = reverseDLL(head);

    cout << "Reversed List: ";
    for (Node* temp = reversedHead; temp != nullptr; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;

    return 0;

}