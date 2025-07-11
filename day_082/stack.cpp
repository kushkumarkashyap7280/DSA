// here is the stack implementation in c++

#include <iostream>
using namespace std;

// using linked list

struct stackNode {
    int val;
    stackNode* down;

    stackNode(int val) : val(val), down(nullptr) {}
};


class myStack {
    stackNode* top;
    int count;

public:
    myStack() : top(nullptr), count(0) {}

    // Copy constructor (deep copy)
    myStack(const myStack& other) : top(nullptr), count(0) {
        if (!other.top) return;

        // Reverse into a temporary stack to preserve order
        myStack temp;
        for (stackNode* curr = other.top; curr; curr = curr->down) {
            temp.push(curr->val);
        }

        // Push from temp back into this stack
        for (stackNode* curr = temp.top; curr; curr = curr->down) {
            this->push(curr->val);
        }
    }

    ~myStack() {
        while (top) {
            stackNode* temp = top;
            top = top->down;
            delete temp;
        }
    }

    void push(int val) {
        stackNode* node = new stackNode(val);
        node->down = top;
        top = node;
        count++;
    }

    void pop() {
        if (!top) return;  // or throw exception
        stackNode* temp = top;
        top = top->down;
        delete temp;
        count--;
    }

    int peek() const {
        if (!top) throw runtime_error("Stack is empty");
        return top->val;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int size() const {
        return count;
    }

    // Optional: clone() method that returns a deep copy
    myStack clone() const {
        return myStack(*this);
    }
};

int main() {


  /// --------------basic ----------------------------------

  /*
  //intialise stack
  stack<int> s;

  //  s.push(5);

  //check empty
  if(s.empty()) cout << "stack is empty";
  else cout << "stack is not empty";

  // push elements
   s.push(5);
   s.push(6);
   s.push(4);
   
   cout << endl;
  // transverse the stack
  stack <int> temp = s;
   while(!temp.empty()){
      cout << temp.top() << endl;
       temp.pop();
   }
    
   cout << "top is :" << s.top() << endl;
   cout << "size is :" << s.size() << endl;
   // pop element
   s.pop();

   cout << "top is :" << s.top() << endl;
   cout << "size is :" << s.size() << endl;
   temp = s;
    while(temp.empty()!= true){
      cout << temp.top() << endl;
       temp.pop();
   }
    
   */


   // -------------- custom mystack ------------------
    myStack s;

    cout << "Initially, is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "Pushing elements: 10, 20, 30" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;      // should print 30
    cout << "Stack size: " << s.size() << endl;       // should print 3

    cout << "Popping top element..." << endl;
    s.pop();

    cout << "New top element: " << s.peek() << endl;  // should print 20
    cout << "Stack size: " << s.size() << endl;       // should print 2

    // cout << "Popping all elements: ";
    // while (!s.isEmpty()) {
    //     cout << s.peek() << " ";
    //     s.pop();
    // }
    // cout << endl;

    // cout << "Is stack empty now? " << (s.isEmpty() ? "Yes" : "No") << endl;

    
    // Copy stack
    myStack k = s.clone();  // or simply: myStack k = s;
    cout << "Copy top: " << k.peek() << endl;       // 20

    return 0;
   

return 0;
}
