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

// !incorrect approach, problem due to find function
// void preorder(TreeNode *root, string &res)
// {
//     if (!root)
//     {
//         res += "#,";
//         return;
//     }

//     res += to_string(root->val) + ",";
//     preorder(root->left, res);
//     preorder(root->right, res);
// }

// bool isSubtree(TreeNode *root, TreeNode *subRoot)
// {
//     if (!root)
//         return false;
//     if (!subRoot)
//         return false;

//     string subTree = "";
//     string tree = "";

//     preorder(root, tree);
//     preorder(subRoot, subTree);

//     // Debugging output
//     cout << "Serialized root tree: " << tree << endl;
//     cout << "Serialized subRoot tree: " << subTree << endl;

//     return tree.find(subTree) != string::npos;
// }

bool isIdentical(TreeNode *a, TreeNode *b)
{
    if (!a && !b)
        return true; // Both are null
    if (!a || !b)
        return false; // One is null, not identical
    if (a->val != b->val)
        return false; // Values don't match

    return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root)
        return false; 
    if (isIdentical(root, subRoot))
        return true; 

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(12);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(0);

    TreeNode *subRoot = new TreeNode(2);
    // subRoot->left = new TreeNode(4);
    // subRoot->right = new TreeNode(5);

    if (isSubtree(root, subRoot))
        cout << "Yes, it is a subtree!" << endl;
    else
        cout << "No, it is not a subtree!" << endl;

    return 0;
}