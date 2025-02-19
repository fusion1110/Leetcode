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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty())
        return nullptr;
    int n = sizeof(inorder) / sizeof(inorder[0]);

    //* Root value is the 1st value in preorder traversal
    TreeNode *root = new TreeNode(preorder[0]);

    //*finding the value of preorder element in inorder array to create subarrays
    auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

    //*Creating subarrays
    vector<int> LeftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> RightPre(preorder.begin() + mid + 1, preorder.end());
    vector<int> LeftIn(inorder.begin(), inorder.begin() + mid);
    vector<int> RightIn(inorder.begin() + mid + 1, inorder.end());

    root->left = buildTree(LeftPre, LeftIn);
    root->right = buildTree(RightPre, RightIn);

    return root;
}

int main()
{
    vector<int> preorder = {1, 2, 3, 4};
    vector<int> inorder = {2, 1, 3, 4};
    buildTree(preorder, inorder);

    return 0;
}