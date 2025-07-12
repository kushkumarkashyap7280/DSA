// 2095. Delete the Middle Node of a Linked List 
// difficulty - medium

//  Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/


//time complexity O(n);
//space complexity O(1)

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteMiddle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next)
    {
        if (!prev)
        {
            prev = head;
        }
        else
        {
            prev = prev->next;
        }
        fast = fast->next->next;
    }
    ListNode *temp = prev->next->next;
    delete prev->next;
    prev->next = temp;
    return head;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "After deleting middle node: ";
    printList(head);

    // Free memory
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}