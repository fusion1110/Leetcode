#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1)
    {
        tail->next = list1;
    }
    if (list2)
    {
        tail->next = list2;
    }

    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create two sorted linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Example linked lists:
    // List1: 1 -> 3 -> 5
    // List2: 2 -> 4 -> 6

    // Merge the lists
    ListNode *mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    while (list1) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
