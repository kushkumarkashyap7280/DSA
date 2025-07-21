// 622. Design Circular Queue

// link -https://leetcode.com/problems/design-circular-queue/description

/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.

Example 1:
Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4

Constraints:
1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue
{
    int s;        // capacity
    int front;    // index of front element
    int rear;     // index of rear element
    int currsize; // current number of elements
    int *arr;

public:
    MyCircularQueue(int k)
    {
        this->s = k;
        this->front = 0;
        this->rear = -1;
        this->currsize = 0;
        this->arr = new int[k];
    }
    ~MyCircularQueue()
    {
        delete[] arr;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        rear = (rear + 1) % s;
        arr[rear] = value;
        currsize++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % s;
        currsize--;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return currsize == 0;
    }

    bool isFull()
    {
        return currsize == s;
    }
};

int main()
{
    MyCircularQueue q(3);
    cout << boolalpha;
    cout << "enQueue(1): " << q.enQueue(1) << endl; // true
    cout << "enQueue(2): " << q.enQueue(2) << endl; // true
    cout << "enQueue(3): " << q.enQueue(3) << endl; // true
    cout << "enQueue(4): " << q.enQueue(4) << endl; // false
    cout << "Rear(): " << q.Rear() << endl;         // 3
    cout << "isFull(): " << q.isFull() << endl;     // true
    cout << "deQueue(): " << q.deQueue() << endl;   // true
    cout << "enQueue(4): " << q.enQueue(4) << endl; // true
    cout << "Rear(): " << q.Rear() << endl;         // 4
    cout << "Front(): " << q.Front() << endl;       // 2
    cout << "isEmpty(): " << q.isEmpty() << endl;   // false
    cout << "deQueue(): " << q.deQueue() << endl;   // true
    cout << "deQueue(): " << q.deQueue() << endl;   // true
    cout << "deQueue(): " << q.deQueue() << endl;   // true
    cout << "deQueue(): " << q.deQueue() << endl;   // false
    cout << "isEmpty(): " << q.isEmpty() << endl;   // true
    cout << "Front(): " << q.Front() << endl;       // -1
    cout << "Rear(): " << q.Rear() << endl;         // -1
    return 0;
}

/*
Time Complexity: O(1) for all operations
Space Complexity: O(k) for the queue storage
*/