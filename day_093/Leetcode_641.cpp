//641. Design Circular Deque

// link - https://leetcode.com/problems/design-circular-deque/description

#include <iostream>
#include <cassert>
#include <vector>
#include <string>


/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/


class MyCircularDeque {
    int * arr;
    int n;
    int cs ;
    int front =  0;
    int back = 0;
public:
    MyCircularDeque(int k) {
        this->n = k;
        this->cs = 0;
        this->front = -1;
        this->back = -1;
        this->arr = new int[k];
    }
    
    bool insertFront(int value) {
        if(cs == n) return false;
        if(cs == 0){
           front = back = 0;
        }else{
            front = (front -1 + n)% n;
        }
        arr[front] = value;
        cs++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cs == n) return false;
        if(cs == 0){
            front = back = 0;
        }else{
            back = (back +1)%n;
        }
        arr[back] = value;
        cs++;
         return true;
    }
    
    bool deleteFront() {
        if(cs == 0) return false;
        if(cs == 1){
            front= back = -1;
        }else{  
         front = (front+1)%n;
        }
         cs--;
         return true;
    }
    
    bool deleteLast() {
        if(cs == 0) return false;
        if(cs == 1){
              front =back = -1;
             
        }else{
           back =(back -1 +n) %n;
        }
        cs--;
        return true;
    }
    
    int getFront() {
        if(cs == 0) return -1;
        return arr[front];
    }
    
    int getRear() {
         if(cs == 0) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        return  cs == 0;
    }
    
    bool isFull() {
        return cs == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

void run_leetcode_tests() {
    std::cout << "Running LeetCode Example 1..." << std::endl;
    MyCircularDeque* myCircularDeque = new MyCircularDeque(3);
    
    assert(myCircularDeque->insertLast(1) == true);
    assert(myCircularDeque->insertLast(2) == true);
    assert(myCircularDeque->insertFront(3) == true);
    assert(myCircularDeque->insertFront(4) == false);
    assert(myCircularDeque->getRear() == 2);
    assert(myCircularDeque->isFull() == true);
    assert(myCircularDeque->deleteLast() == true);
    assert(myCircularDeque->insertFront(4) == true);
    assert(myCircularDeque->getFront() == 4);

    delete myCircularDeque;
    std::cout << "Test case passed!" << std::endl;
}

int main() {
    run_leetcode_tests();
    return 0;
}