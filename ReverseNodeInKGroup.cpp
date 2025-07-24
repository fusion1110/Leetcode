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

ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *cur = head;
    int pair = 0;
    while (cur && pair < k)
    {
        cur = cur->next;
        pair++;
    }

    if (pair == k)
    {
        cur = reverseKGroup(cur, k);
        while (pair-- > 0)
        {
            ListNode *temp = head->next;
            head->next = cur;
            cur = head;
            head = temp;
        }

        head = cur;
    }

    return head;
}

int main()
{

    return 0;
}