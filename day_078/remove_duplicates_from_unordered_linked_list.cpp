// Remove duplicates from an unsorted linked list

// https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

/*
Given an unsorted linked list. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all other duplicates are to be removed.

Examples:

Input: LinkedList: 5->2->2->4
Output: 5->2->4
Explanation: Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4

Input: LinkedList: 2->2->2->2->2
Output: 2
Explanation:Given linked list elements are 2->2->2->2->2, in which 2 is repeated. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain only 2.
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 106
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// define the structure for a node in the linked list
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// first approach : using brute force
// function to remove duplicates from an unsorted linked list
// The function takes the head of the linked list as input and returns the head of the modified linked list.
// time complexity: O(n^2), space complexity: O(1)
//note: This approach is not efficient for large linked lists as it uses nested loops to check for duplicates.
Node *removeDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *curr = head;
    while (curr && curr->next)
    {
        Node *temp = curr->next;
        Node *prev = curr;
        while (temp)
        {
            if (temp->data == curr->data)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

// function to remove duplicates from an unsorted linked list
// The function takes the head of the linked list as input and returns the head of the modified linked list.
// It uses an unordered set to keep track of the values that have already been seen.
// time complexity: O(n), space complexity: O(n)
Node *removeDuplicates(Node *head)
{
    if (!head || !head->next)
        return head;
    unordered_set<int> isPresent;
    isPresent.insert(head->data);
    Node *curr = head;
    while (curr->next)
    {
        if (isPresent.find(curr->next->data) != isPresent.end())
        {
            Node *temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        }
        else
        {
            isPresent.insert(curr->next->data);
            curr = curr->next;
        }
    }

    return head;
}
int main()
{
    // Create a linked list for testing
    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original linked list: ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Remove duplicates
    head = removeDuplicates(head);

    // Print the modified linked list
    Node *curr = head;
    cout << "Linked list after removing duplicates: ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Clean up memory
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}