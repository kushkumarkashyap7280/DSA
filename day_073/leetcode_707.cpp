//707. Design Linked List

//https://leetcode.com/problems/design-linked-list/

/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/

#include <iostream>
using namespace std;

// Definition for doubly-linked list.
struct Node {
    int val;
    Node* next;
    Node* prev;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    Node(int val, Node* next, Node* prev)
        : val(val), next(next), prev(prev) {}
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index >= length) return -1;
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        if (head) head->prev = temp;
        head = temp;
        if (!tail) tail = head;
        length++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);
        temp->prev = tail;
        if (tail) tail->next = temp;
        tail = temp;
        if (!head) head = tail;
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == length) {
            addAtTail(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);
        Node* prevNode = curr->prev;

        newNode->next = curr;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        curr->prev = newNode;

        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete temp;
            length--;
            return;
        }

        if (index == length - 1) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete temp;
            length--;
            return;
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }

        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete curr;
        length--;
    }
    ~MyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
};


int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    cout << myLinkedList.get(1) << endl; // return 2
    myLinkedList.deleteAtIndex(1); // now the linked list is 1->3
    cout << myLinkedList.get(1) << endl; // return 3

    // Clean up memory (not strictly necessary in this example)
    // In a real application, you would want to ensure all nodes are deleted properly.

    // Note: The destructor for MyLinkedList is not implemented here, but it should ideally delete all nodes to prevent memory leaks.
    // You can implement a destructor to clean up the linked list nodes if needed.
return 0;
}