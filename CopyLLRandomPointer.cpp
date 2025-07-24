#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> map;
    if (head == nullptr)
        return nullptr;
    Node *curr = head;

    //* copy of all the value of nodes first
    while (curr)
    {
        Node *copy = new Node(curr->val);
        map[curr] = copy;
        curr = curr->next;
    }

    //* connecting the pointers
    curr = head;
    while (curr)
    {
        Node *copy = map[curr];
        copy->next = map[curr->next];
        copy->random = map[curr->random];
        curr = curr->next;
    }

    return map[head];
}

int main() {
    // Creating a test case
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;

    head->random = third;   // 1's random points to 3
    second->random = head;  // 2's random points to 1
    third->random = second; // 3's random points to 2

    cout << "Original List:" << endl;
    Node* temp = head;
    while (temp) {
        cout << "Node Value: " << temp->val;
        if (temp->random)
            cout << ", Random Points to: " << temp->random->val;
        else
            cout << ", Random Points to: NULL";
        cout << endl;
        temp = temp->next;
    }

    // Cloning the list
    Node* clonedHead = copyRandomList(head);

    cout << "\nCloned List:" << endl;
    temp = clonedHead;
    while (temp) {
        cout << "Node Value: " << temp->val;
        if (temp->random)
            cout << ", Random Points to: " << temp->random->val;
        else
            cout << ", Random Points to: NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}
