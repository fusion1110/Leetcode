#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to invert a binary tree
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode *node = new TreeNode(root->val);

    node->right = invertTree(root->left);
    node->left = invertTree(root->right);

    return node;
}

// Helper function for pre-order traversal
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    // Create the tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Example tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7

    cout << "Original Tree (Pre-Order): ";
    preOrder(root);
    cout << endl;

    // Invert the tree
    TreeNode *invertedRoot = invertTree(root);

    cout << "Inverted Tree (Pre-Order): ";
    preOrder(invertedRoot);
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    delete invertedRoot->left->left;
    delete invertedRoot->left->right;
    delete invertedRoot->right->left;
    delete invertedRoot->right->right;
    delete invertedRoot->left;
    delete invertedRoot->right;
    delete invertedRoot;

    return 0;
}
