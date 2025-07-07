//21. Merge Two Sorted Lists

// https://leetcode.com/problems/merge-two-sorted-lists/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive approach
ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoListsRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoListsRecursive(l1, l2->next);
        return l2;
    }
}

// Iterative approach
// time complexity O(m + n) where m and n are numbers of nodes in list1 and list2;
// space complexity O(1);
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    ListNode *l1 = list1;
    ListNode *l2 = list2;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;
    return dummy.next;
}

// Helper to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    // Create second sorted list: 2 -> 4 -> 6
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    // Iterative merge
    ListNode* mergedIter = mergeTwoLists(l1, l2);
    cout << "Merged (Iterative): "; printList(mergedIter);

    // For recursive, recreate the lists (since previous nodes are now merged)
    ListNode* l3 = new ListNode(1);
    l3->next = new ListNode(3);
    l3->next->next = new ListNode(5);
    ListNode* l4 = new ListNode(2);
    l4->next = new ListNode(4);
    l4->next->next = new ListNode(6);
    ListNode* mergedRec = mergeTwoListsRecursive(l3, l4);
    cout << "Merged (Recursive): "; printList(mergedRec);

    // Clean up memory
    while (mergedIter) {
        ListNode* temp = mergedIter;
        mergedIter = mergedIter->next;
        delete temp;
    }
    while (mergedRec) {
        ListNode* temp = mergedRec;
        mergedRec = mergedRec->next;
        delete temp;
    }
    return 0;
}