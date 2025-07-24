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

//* basically a dfs
int preorder(TreeNode *node, int maxVal)
{
    if (!node)
        return 0;
    int res = (node->val >= maxVal) ? 1 : 0;
    maxVal = max(node->val, maxVal);
    res += preorder(node->left, maxVal);
    res += preorder(node->right, maxVal);

    return res;
}

int goodNodes(TreeNode *root)
{
    return preorder(root, root->val);
}


int main()
{
    // Constructing a sample binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);
    
    // Testing goodNodes function
    cout << "Number of good nodes: " << goodNodes(root) << endl;
    
    // Free allocated memory
    delete root->left->left;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
