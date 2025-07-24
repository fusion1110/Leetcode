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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        TreeNode *right = nullptr;

        while (levelSize--)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                right = node;
                q.push(node->left);
                q.push(node->right);
            }
        }
        if (right)
        {
            res.push_back(right->val);
        }
    }

    return res;
}

int main()
{

    return 0;
}