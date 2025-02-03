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

int dfs(TreeNode *node, int &res)
{
    if (!node)
        return 0;

    int leftMax = max(dfs(node->left, res), 0);
    int rightMax = max(dfs(node->right, res), 0);

    res = max(res, node->val + leftMax + rightMax);

    return node->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode *root)
{
    int res = root->val;
    dfs(root, res);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    cout << "Max Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
