#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *node, vector<int> &arr)
{
    if (!node)
        return;
    inorder(node->left, arr);
    arr.push_back(node->val);
    inorder(node->right, arr);
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> arr;
    inorder(root, arr);

    // *[k-1] as k is 1-indexed
    return arr[k - 1];
}

int main()
{
    // Constructing the following BST:
    //        5
    //       / \
    //      3   7
    //     / \  / \
    //    2  4 6  8

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int k = 3; // Find the 3rd smallest element
    cout << "The " << k << "rd smallest element is: " << kthSmallest(root, k) << endl;

    return 0;
}