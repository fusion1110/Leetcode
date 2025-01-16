#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next; // pointer to node
};



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

    return prev; // head
}

int main()
{

    return 0;
}