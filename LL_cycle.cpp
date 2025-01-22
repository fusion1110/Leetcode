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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;       // moves by 1
        fast = fast->next->next; // moves by 2

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    // Create nodes
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    // Connect nodes to form a cycle: 1 -> 2 -> 3 -> 4 -> 2
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle

    // Test for cycle
    if (hasCycle(node1))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle detected!" << endl;

    // Free memory (avoiding dangling pointers; assume no cycle for this part)
    node4->next = nullptr; // Break the cycle first
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
