//876. Middle of the Linked List

//https://leetcode.com/problems/middle-of-the-linked-list/


/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// first approach: using vector to store nodes
// This approach is not optimal for large lists due to space complexity.
// It is used here for educational purposes to illustrate a simple method of finding the middle node.
//time complexity: O(n)
//space complexity: O(n)
 ListNode* middleNodeUsingVector(ListNode* head) {
          vector<ListNode*> ans;
          ListNode * temp = head;
        while(temp != nullptr){
            ans.push_back(temp);
            temp = temp->next;
        }
        return ans[ans.size()/2];  
 }

// second approach: using counting nodes
// This approach counts the number of nodes and then traverses to the middle node.
// This is a straightforward method but not the most efficient in terms of time complexity.
//time complexity: O(n)
//space complexity: O(1)
ListNode* middleNodeUsingCounting(ListNode* head) {
     ListNode * temp = head;
       
        int count = 0;
        while( temp != nullptr){
            count++;
            temp = temp->next;
        }
         
        int i = 0;
         ListNode * ans = head;
        while( i <count/2){
            ans = ans->next;
            i++;
        }
        return ans; 
  }

// third approach: using two pointers
// This approach uses a fast and slow pointer to find the middle node efficiently.
// The fast pointer moves two steps at a time, while the slow pointer moves one step.
// This is the most efficient method in terms of both time and space complexity.
//time complexity: O(n)
//space complexity: O(1)
ListNode* middleNodeUsingTwoPointer(ListNode* head) {
  ListNode * faster = head; 
    ListNode * slower = head; 

    while(faster != nullptr && faster->next !=nullptr){
        slower = slower->next;
        faster = faster->next->next;
    }
    return slower;
}
int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Using vector approach
    ListNode* middle1 = middleNodeUsingVector(head);
    cout << "Middle Node using Vector: " << middle1->val << endl;

    // Using counting approach
    ListNode* middle2 = middleNodeUsingCounting(head);
    cout << "Middle Node using Counting: " << middle2->val << endl;

    // Using two pointers approach
    ListNode* middle3 = middleNodeUsingTwoPointer(head);
    cout << "Middle Node using Two Pointers: " << middle3->val << endl;
return 0;
}