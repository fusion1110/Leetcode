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

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next) return head;

    ListNode *cur = head;
    ListNode *after = head->next;
    ListNode *afterHead = after;

    while (after && after->next)
    {
        cur->next = after->next;
        cur = cur->next;

        after->next = cur->next;
        after = after->next;
    }

    cur->next = afterHead;

    return head;
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


ListNode *createList(vector<int> &vals)
{
    if (vals.empty()) return nullptr;
    
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;

    for (size_t i = 1; i < vals.size(); i++)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }

    return head;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};

    ListNode *head = createList(values);
    cout << "Original List: ";
    printList(head);

    head = oddEvenList(head);
    cout << "Reordered List: ";
    printList(head);

    return 0;
}
