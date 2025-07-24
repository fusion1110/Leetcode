#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        right = left = nullptr;
    }
};

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}


bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}


// Time complexity: O(n2)
// can be done in less.

int main()
{
    // Create nodes
    Node *root = new Node();
    root->data = 1;

    root->left = new Node();
    root->left->data = 2;

    root->right = new Node();
    root->right->data = 3;

    root->left->left = new Node();
    root->left->left->data = 4;

    root->left->right = new Node();
    root->left->right->data = 5;

    root->right->right = new Node();
    root->right->right->data = 6;

    // Example tree:
    //         1
    //        / \
    //       2   3
    //      / \    \
    //     4   5    6

    // Check if the tree is balanced
    if (isBalanced(root))
        cout << "The tree is balanced.\n";
    else
        cout << "The tree is not balanced.\n";

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
