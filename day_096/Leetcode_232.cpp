// 232. Implement Queue using Stacks

// link -https://leetcode.com/problems/implement-queue-using-stacks/description/

/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.


Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

#include <iostream>
#include <stack>

// time and space

class MyQueue
{
  std::stack<int> Aux;
  std::stack<int> Main;

public:
  MyQueue()
  {
  }

  void push(int x)
  {

    while (!Main.empty())
    {
      Aux.push(Main.top());
      Main.pop();
    }
    Aux.push(x);
    while (!Aux.empty())
    {
      Main.push(Aux.top());
      Aux.pop();
    }
  }

  int pop()
  {
    if (Main.empty())
      return -1;
    int ans = Main.top();
    Main.pop();
    return ans;
  }

  int peek()
  {
    if (Main.empty())
      return -1;
    return Main.top();
  }

  bool empty()
  {
    return Main.empty();
  }
};

// Demo main function for testing
int main()
{
  MyQueue myQueue;
  myQueue.push(1);
  myQueue.push(2);
  std::cout << "Peek: " << myQueue.peek() << std::endl;                        // Expected: 1
  std::cout << "Pop: " << myQueue.pop() << std::endl;                          // Expected: 1
  std::cout << "Empty: " << (myQueue.empty() ? "true" : "false") << std::endl; // Expected: false
  std::cout << "Pop: " << myQueue.pop() << std::endl;                          // Expected: 2
  std::cout << "Empty: " << (myQueue.empty() ? "true" : "false") << std::endl; // Expected: true
  return 0;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */