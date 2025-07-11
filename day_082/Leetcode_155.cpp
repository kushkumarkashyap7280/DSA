//155. Min Stack

//https://leetcode.com/problems/min-stack/

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <iostream>
using namespace std;

struct Node {
  int min;
  int val;
  Node* down;

  Node(int val, int min, Node* down) :
      min(min), val(val), down(down) {}
};

class MinStack {
  Node* top_;
public:
  MinStack() : top_(nullptr) {}

  ~MinStack() {
      while (top_) {
          Node* tmp = top_;
          top_ = top_->down;
          delete tmp;
      }
  }

  void push(int val) {
      if (!top_) {
          // first element
          top_ = new Node(val, val, nullptr);
      } else {
          int currMin = std::min(val, top_->min);
          top_ = new Node(val, currMin, top_);
      }
  }

  void pop() {
      if (!top_) return;
      Node* temp = top_;
      top_ = top_->down;
      delete temp;
  }

  int top() {
      if (!top_) throw std::runtime_error("Stack is empty");
      return top_->val;
  }

  int getMin() {
      if (!top_) throw std::runtime_error("Stack is empty");
      return top_->min;
  }
};

int main()
{
   // test cases
   MinStack minStack;
   minStack.push(-2);
   minStack.push(0);
   minStack.push(-3);
   cout << "Min: " << minStack.getMin() << endl; // -3
   minStack.pop();
   cout << "Top: " << minStack.top() << endl;    // 0
   cout << "Min: " << minStack.getMin() << endl; // -2
   minStack.pop();
   cout << "Top: " << minStack.top() << endl;    // -2
   cout << "Min: " << minStack.getMin() << endl; // -2
   minStack.pop();
   cout << "Top: " << minStack.top() << endl;    // -2
   cout << "Min: " << minStack.getMin() << endl; // -2
   return 0;
}