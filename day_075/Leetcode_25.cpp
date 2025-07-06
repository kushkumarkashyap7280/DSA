// 25. Reverse Nodes in k-Group

// https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


Follow-up: Can you solve the problem in O(1) extra memory space?
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// my solution
// time complexity: O(n)
// space complexity: O(1)
// This solution reverses the nodes in groups of k, maintaining the order of the remaining nodes if they are less than k.
// It uses a two-pointer technique to reverse the nodes in each k-group and connects the reversed
// groups back to the main list. The first time it sets the real head of the list, and for subsequent groups, it connects
// the previous group's end to the new reversed group head. The process continues until there are no more complete k-groups to reverse.
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;
    ListNode *realHead = head;
    bool firstTime = true;
    ListNode *prev = nullptr;
    ListNode *previousHead = head;
    while (true)
    {
        ListNode *kthNode = head;
        for (int i = 0; i < k; i++)
        {
            if (kthNode == nullptr)
                return realHead;
            kthNode = kthNode->next;
        }
        prev = kthNode;

        ListNode *currentGroupHead = head;
        for (int i = 0; i < k; i++)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        if (firstTime)
        {
            realHead = prev;
            firstTime = false;
        }
        else
        {
            previousHead->next = prev;
            previousHead = currentGroupHead;
        }
    }
    return realHead;
}

// Function to reverse k nodes in a linked list
// time complexity: O(n)
// space complexity: O(1)
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prevGroupEnd = &dummy;

    while (true)
    {
        ListNode *groupStart = prevGroupEnd->next;
        ListNode *groupEnd = groupStart;

        // Check if there are k nodes to reverse
        for (int i = 0; i < k - 1 && groupEnd; ++i)
        {
            groupEnd = groupEnd->next;
        }
        if (!groupEnd)
            break; // Not enough nodes to reverse

        ListNode *nextGroupStart = groupEnd->next;
        groupEnd->next = nullptr; // Temporarily end the current group

        // Reverse the current k-group
        ListNode *prev = nullptr;
        ListNode *curr = groupStart;
        while (curr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Connect the reversed group back to the list
        prevGroupEnd->next = prev;         // Connect previous part to reversed part
        groupStart->next = nextGroupStart; // Connect reversed part to next part
        prevGroupEnd = groupStart;         // Move to the end of the reversed part
    }

    return dummy.next; // Return the new head of the modified list
}

// recursive solution
// time complexity: O(n)
// space complexity: O(n)
// This solution uses recursion to reverse the nodes in groups of k. It checks if there are enough nodes to reverse,
// reverses the first k nodes, and then recursively calls itself for the next group of k nodes.
ListNode *recursiveway(ListNode *head, int k)
{

    ListNode *isValidNode = head;
    for (int i = 0; i < k; i++)
    {
        if (isValidNode == nullptr)
            return head;
        isValidNode = isValidNode->next;
    }
    ListNode *prevHead = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < k; i++)
    {
        ListNode *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    prevHead->next = recursiveway(head, k);
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    return recursiveway(head, k);
}
int main()
{
    // Example usage
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode *modifiedHead = reverseKGroup(head, k);

    // Print the modified list
    ListNode *current = modifiedHead;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up memory
    while (modifiedHead)
    {
        ListNode *temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}