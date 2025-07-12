# Day 83: Stack and Linked List Problems

This folder contains various stack and linked list problems, including classic Leetcode and Coding Ninjas/Naukri problems, with both recursive and iterative solutions where applicable.

## Table of Contents

- [Leetcode_2095.cpp](#leetcode_2095cpp)
- [Leetcode_1381.cpp](#leetcode_1381cpp)
- [Leetcode_3606.cpp](#leetcode_3606cpp)
- [delete_middle_of_stack.cpp](#delete_middle_of_stackcpp)
- [reverse_stack.cpp](#reverse_stackcpp)
- [reverse_a_stirng_using_stack.cpp](#reverse_a_stirng_using_stackcpp)
- [Add_element_to_bottom_of_stack.cpp](#add_element_to_bottom_of_stackcpp)

---

## Leetcode_2095.cpp

- **Problem:** [Leetcode 2095. Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)
- **Description:**
  - Delete the middle node from a singly linked list. If the list has an even number of nodes, delete the second middle node.
- **Approach:**
  - Use the fast and slow pointer technique to find the middle node. Keep track of the previous node to the middle, then delete the middle node and reconnect the list.
  - **Core Logic:**
    ```cpp
    ListNode *deleteMiddle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = prev ? prev->next : head;
            fast = fast->next->next;
        }
        ListNode *temp = prev->next->next;
        delete prev->next;
        prev->next = temp;
        return head;
    }
    ```
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## Leetcode_1381.cpp

- **Problem:** [Leetcode 1381. Design a Stack With Increment Operation](https://leetcode.com/problems/design-a-stack-with-increment-operation/)
- **Description:**
  - Implement a custom stack with push, pop, and an increment operation that adds a value to the bottom k elements.
- **Approach:**
  - Use a dynamic array to store stack elements. Push and pop are standard. Increment iterates over the bottom k elements and adds the given value.
  - **Core Logic:**
    ```cpp
    class CustomStack {
        int *arr, index, size;
    public:
        CustomStack(int maxSize) { ... }
        void push(int x) { ... }
        int pop() { ... }
        void increment(int k, int val) {
            for (int i = 0; i < min(k, index+1); i++) arr[i] += val;
        }
    };
    ```
- **Time Complexity:**
  - Constructor: O(1)
  - push: O(1)
  - pop: O(1)
  - increment: O(min(k, N))
- **Space Complexity:** O(N)

---

## Leetcode_3606.cpp

- **Problem:** [Leetcode 3606. Coupon Code Validator](https://leetcode.com/problems/coupon-code-validator/)
- **Description:**
  - Validate a list of coupon codes based on business line, activity status, and code format. Return valid codes sorted by business line and lexicographically.
- **Approach:**
  - Check each coupon for validity (active, correct business line, valid code). Group valid codes by business line, sort each group, and concatenate results.
  - **Core Logic:**
    ```cpp
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // ... check validity, group, sort, and return
    }
    ```
- **Time Complexity:** O(n·m + k log k), where n = number of coupons, m = max code length, k = number of valid coupons
- **Space Complexity:** O(n·m)

---

## delete_middle_of_stack.cpp

- **Problem:** [Delete Middle Element of a Stack (GeeksforGeeks)](https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1)
- **Description:**
  - Delete the middle element from a stack using recursion, preserving the order of the remaining elements.
- **Approach:**
  - Use recursion to pop elements until the middle is reached, remove it, then push elements back in order.
  - **Core Logic:**
    ```cpp
    void deleteRecursive(stack<int>& s, int index, int mid) {
        if (index == mid) { s.pop(); return; }
        int temp = s.top(); s.pop();
        deleteRecursive(s, index+1, mid);
        s.push(temp);
    }
    void deleteMid(stack<int>& s) {
        int l = s.size()-1;
        deleteRecursive(s, 0, l/2);
    }
    ```
- **Time Complexity:** O(N)
- **Space Complexity:** O(N) (recursion stack)

---

## reverse_stack.cpp

- **Problem:** [Reverse a Stack (GeeksforGeeks)](https://www.geeksforgeeks.org/problems/reverse-a-stack/1)
- **Description:**
  - Reverse a stack using both recursive and iterative approaches.
- **Approach:**
  - Recursive: Pop all elements, insert each at the bottom recursively.
  - Iterative: Use a temporary stack to reverse the order.
  - **Core Logic:**
    ```cpp
    // Recursive
    void insertAtBottom(stack<int> &s, int x) { ... }
    void ReverseRecursive(stack<int> &s) {
        if (s.empty()) return;
        int top = s.top(); s.pop();
        ReverseRecursive(s);
        insertAtBottom(s, top);
    }
    // Iterative
    void Reverse(stack<int> &St) {
        stack<int> temp;
        while(!St.empty()) { temp.push(St.top()); St.pop(); }
        St = temp;
    }
    ```
- **Time Complexity:**
  - Recursive: O(N^2)
  - Iterative: O(N)
- **Space Complexity:**
  - Recursive: O(N) (recursion stack)
  - Iterative: O(N)

---

## reverse_a_stirng_using_stack.cpp

- **Problem:** Reverse a String Using Stack
- **Description:**
  - Reverse a string by pushing all characters onto a stack and popping them to build the reversed string.
- **Approach:**
  - Use a stack to reverse the order of characters.
  - **Core Logic:**
    ```cpp
    string reverseStr(string s) {
        stack<char> st;
        for(char c : s) st.push(c);
        string ans = "";
        while(!st.empty()) { ans.push_back(st.top()); st.pop(); }
        return ans;
    }
    ```
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

## Add_element_to_bottom_of_stack.cpp

- **Problem:** [Insert An Element At Its Bottom In A Given Stack (Coding Ninjas/Naukri)](https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166)
- **Description:**
  - Insert a given element at the bottom of a stack using recursion.
- **Approach:**
  - Recursively pop all elements, push the new element, then push the popped elements back.
  - **Core Logic:**
    ```cpp
    stack<int> pushAtBottom(stack<int> myStack, int x) {
        if (myStack.empty()) { myStack.push(x); return myStack; }
        int top = myStack.top(); myStack.pop();
        myStack = pushAtBottom(myStack, x);
        myStack.push(top);
        return myStack;
    }
    ```
- **Time Complexity:** O(N)
- **Space Complexity:** O(N) (recursion stack)

---
