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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;
    int carry = 0;
    int sum = 0;
    int v1, v2;

    if (!l1 && !l2 && carry == 0)
    {
        return dummy->next;
    }

    while (l1 || l2 || carry)
    {
        v1 = v2 = 0;

        int v1 = (l1) ? l1->val : 0;
        int v2 = (l2) ? l2->val : 0;
        // !if l1->val is not zero then v1 = 0 else v1 = 0


        sum = v1 + v2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);
        curr = curr->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

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
    // Example: 342 + 465 = 807 (represented as 2->4->3 + 5->6->4 = 7->0->8)
    ListNode *l1 = new ListNode(9);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(9);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);

    cout << "First number: ";
    printList(l1);

    cout << "Second number: ";
    printList(l2);

    ListNode *result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}