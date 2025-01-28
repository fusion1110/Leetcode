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

vector<vector<int>> levelOrder(TreeNode *node)
{
    vector<vector<int>> result;
    if (node == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        vector<int> currentLevel;
        int levelSize = q.size();

        while (levelSize--)
        {
            TreeNode *current = q.front();
            currentLevel.push_back(current->val);
            q.pop();

            // Enqueue left and right children
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}

int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    // Call levelOrder and store the result
    vector<vector<int>> result = levelOrder(root);

    // Print the result
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
