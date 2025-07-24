#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *left = dummy;
    ListNode *right = head;

    while (n > 0 && right != nullptr)
    {
        right = right->next;
        n--;
    }

    while (right)
    {
        left = left->next;
        right = right->next;
    }

    left->next = left->next->next;

    return dummy->next;
}

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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int n = 2; // Remove the 2nd node from the end
    head = removeNthFromEnd(head, n);

    cout << "Modified list after removing " << n << "th node from end: ";
    printList(head);

    return 0;
}