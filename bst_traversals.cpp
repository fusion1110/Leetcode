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

void inorderHelper(TreeNode *root, vector<int> &res)
{
    if (root != nullptr)
    {
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    inorderHelper(root, res);
    return res;
}

void postorderHelper(TreeNode *root, vector<int> &res)
{
    if (root != nullptr)
    {
        postorderHelper(root->left, res);
        postorderHelper(root->right, res);
        res.push_back(root->val);
    }
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    postorderHelper(root, res);
    return res;
}

void preorderHelper(TreeNode *root, vector<int> &res)
{
    if (root != nullptr)
    {
        res.push_back(root->val);
        preorderHelper(root->left, res);
        preorderHelper(root->right, res);
    }
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    preorderHelper(root, res);
    return res;
}

int main()
{
    // Create a sample tree: [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // In-order Traversal
    vector<int> inorder = inorderTraversal(root);
    cout << "In-order: ";
    for (int val : inorder)
        cout << val << " ";
    cout << endl;

    // Post-order Traversal
    vector<int> postorder = postorderTraversal(root);
    cout << "Post-order: ";
    for (int val : postorder)
        cout << val << " ";
    cout << endl;

    // Pre-order Traversal
    vector<int> preorder = preorderTraversal(root);
    cout << "Pre-order: ";
    for (int val : preorder)
        cout << val << " ";
    cout << endl;

    return 0;
}
