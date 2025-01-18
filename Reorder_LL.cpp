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

void reorderList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    // finding middle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next; // moves by 2
    }

    // reverse 2nd half
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

int main()
{

    return 0;
}