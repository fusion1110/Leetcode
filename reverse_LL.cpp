#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next; // pointer to node
    ListNode(int x) : data(x), next(nullptr) {} // Constructor for easy creation
};

// Function to reverse the linked list
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev; // New head
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original linked list
    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Print the reversed linked list
    cout << "Reversed List: ";
    printList(head);

    // Clean up memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
