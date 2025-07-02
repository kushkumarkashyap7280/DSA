//19. Remove Nth Node From End of List

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
*/

#include <iostream>
using namespace std;


//  * Definition for singly-linked list.
  struct ListNode {
      int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// brute force approach
// 1. Calculate the length of the linked list.
// 2. If n is greater than the length, return the head.
// 3. If n is equal to the length, delete the head and return the new
//    head.
// 4. If n is 1, delete the tail node and return the head.
// 5. Otherwise, find the node to delete by traversing the list until
//    reaching the (length - n)th node, then delete the next node.
//time complexity: O(n)
//space complexity: O(1)

class Solution {
public:
    int length(ListNode * head){
         if(head == nullptr) return 0;
        ListNode *temp = head;
        int len = 1;
        while(temp->next != nullptr){
            temp  = temp->next;
            len++;
        }
        return len;
    }
    ListNode* deleteHead(ListNode * head){
         ListNode* temp = head->next;
         delete head;
         return temp;
    }
  void deleteTail(ListNode* head) {
    if (!head || !head->next) return;
    ListNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
       int s = length(head);
       if( n > s) return head;
       if( n == s ) return deleteHead(head);
       if (n == 1) {
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    } else {
        deleteTail(head);
        return head;
    }
}

       int indexToDelete = s - n + 1;
       ListNode * previousNode = head;
       for(int i =1 ; i <= indexToDelete -2 ; i++ ){
                previousNode = previousNode->next;
       }
       ListNode * toDelete = previousNode->next;
       previousNode->next = toDelete->next;
       delete toDelete;
       return head;
    }
};


int main() {
    // Example usage
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    Solution solution;
    ListNode* result = solution.removeNthFromEnd(head, n);

    // Print the resulting linked list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
return 0;
}