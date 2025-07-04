//142. Linked List Cycle II

//https://leetcode.com/problems/linked-list-cycle-ii/

/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect the start of the cycle in a linked list using Floyd's Tortoise and Hare algorithm
// Time complexity: O(n)
// Space complexity: O(1)
ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr; // If the list is empty or has only one node

    ListNode *slow = head, *fast = head;

    // Step 1: Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;          // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps

        if (slow == fast) {        // Cycle detected
            break;
        }
    }

    if (!fast || !fast->next) return nullptr; // No cycle found

    // Step 2: Find the start of the cycle
    slow = head; // Reset slow pointer to the head
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // The node where the cycle begins
}
int main() {
    // Example usage
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    ListNode* cycleStart = detectCycle(head);
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Clean up memory (not shown here)
return 0;
}