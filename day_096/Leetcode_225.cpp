// 225. Implement Stack using Queues

// link -https://leetcode.com/problems/implement-stack-using-queues/description/

#include <iostream>
#include <queue>

/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?
*/
// space and time complexity 
class MyStack {
  std::queue<int> Aux;
  std::queue<int> Main;
public:
  MyStack() {

  }
  
  void push(int x) {
        Aux.push(x);
      while(!Main.empty()){
          Aux.push(Main.front());
          Main.pop();
      }
    
      while(!Aux.empty()){
          Main.push(Aux.front());
          Aux.pop();
      }
  }
  
  int pop() {
    if(Main.empty()) return  -1;
    int ans = Main.front();
     Main.pop();
     return ans;
  }
  
  int top() {
       if(Main.empty()) return  -1;
      return Main.front();
  }
  
  bool empty() {
      return Main.empty();
  }
};

// Demo main function for testing
int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << "Top: " << myStack.top() << std::endl; // Expected: 2
    std::cout << "Pop: " << myStack.pop() << std::endl; // Expected: 2
    std::cout << "Empty: " << (myStack.empty() ? "true" : "false") << std::endl; // Expected: false
    std::cout << "Pop: " << myStack.pop() << std::endl; // Expected: 1
    std::cout << "Empty: " << (myStack.empty() ? "true" : "false") << std::endl; // Expected: true
    return 0;
}

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/