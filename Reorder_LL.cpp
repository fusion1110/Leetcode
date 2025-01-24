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

// Function to reorder the list
void reorderList(ListNode *head)
{
    if (!head || !head->next || !head->next->next) return; // Base case for short lists
    
    ListNode *slow = head;
    ListNode *fast = head->next;

    // Finding middle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next; // Moves by 2
    }

    // Reverse 2nd half
    ListNode *second = slow->next;
    slow->next = nullptr;
    ListNode *prev = nullptr;

    while (second)
    {
        ListNode *temp = second->next; // Save the next node
        second->next = prev;           // Reverse the pointer
        prev = second;                 // Move 'prev' forward
        second = temp;                 // Move 'second' forward
    }

    // Merge two halves
    ListNode *first = head;
    ListNode *curr = prev;
    while (curr)
    {
        ListNode *temp1;
        ListNode *temp2;
        temp1 = first->next;
        temp2 = curr->next;
        first->next = curr;
        curr->next = temp1;
        first = temp1;
        curr = temp2;
    }
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
    // Create the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    cout << "Original List: ";
    printList(head);

    // Reorder the list
    reorderList(head);

    // Print reordered list
    cout << "Reordered List: ";
    printList(head);

    // Clean up memory
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
