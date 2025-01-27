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
int dfs(TreeNode *root, int &res)
{
    if (!root)
        return 0;

    int left = dfs(root->left, res);
    int right = dfs(root->right, res);
    res = max(res, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    dfs(root, res);
    return res;
}


int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate the diameter of the binary tree
    int diameter = diameterOfBinaryTree(root);

    // Print the result
    cout << "The diameter of the binary tree is: " << diameter << endl;

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

//     1
//    / \
//   2   3
//  / \
// 4   5
