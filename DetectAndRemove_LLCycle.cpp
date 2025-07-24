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

// Function to detect cycle in the linked list
ListNode *hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;       // moves 1 step
        fast = fast->next->next; // moves 2 steps

        if (slow == fast)// Cycle detected
        {
            return slow; // Return meeting point
        } 
    }
    return nullptr; // No cycle
}

// Function to remove cycle from the linked list
void removeCycle(ListNode *head)
{
    ListNode *meetingPoint = hasCycle(head);
    if (!meetingPoint) // No cycle detected
        return;

    // Reset slow to head and find cycle start
    ListNode *slow = head;
    ListNode *prev = nullptr;

    while (slow != meetingPoint)
    {
        prev = meetingPoint;
        slow = slow->next;
        meetingPoint = meetingPoint->next;
    }

    // Break the cycle
    prev->next = nullptr;
}

int main()
{
    // Create nodes
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    // Connect nodes to form a cycle: 1 -> 2 -> 3 -> 4 -> 5 -> 3
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; // Cycle

    // Detect and remove cycle
    if (hasCycle(node1))
    {
        cout << "Cycle detected! Removing cycle..." << endl;
        removeCycle(node1);
    }
    else
        cout << "No cycle detected!" << endl;

    // Check again after removal
    if (hasCycle(node1))
        cout << "Cycle still exists!" << endl;
    else
        cout << "Cycle removed successfully!" << endl;

    // Free memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
