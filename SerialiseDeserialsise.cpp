#include<bits/stdc++.h> 
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

string serialize(TreeNode* root) {
    if(!root) return "N";
    string res;
    queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()){
        TreeNode* node = queue.front();
        queue.pop();

        if(!node){
            res += "N,";
        }else{
            res += to_string(node->val) + ",";
            queue.push(node->left);
            queue.push(node->right);
        }
    }

    return res;    
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    string val;
    getline(ss, val, ',');
    if(val == "N") return nullptr;

    TreeNode* root = new TreeNode(stoi(val));
    queue<TreeNode*> q;
    q.push(root);

    while(getline(ss, val, ',')){
        TreeNode* node = q.front();
        q.pop();
        if(val != "N"){
            node->left = new TreeNode(stoi(val));
            q.push(node->left);
        }
        getline(ss, val, ',');
        if(val != "N"){
            node->right = new TreeNode(stoi(val));
            q.push(node->right);
        }   
    }
    return root;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serializing the binary tree
    string serializedData = serialize(root);
    cout << "Serialized Tree: " << serializedData << endl;

    // Deserializing the binary tree
    TreeNode* deserializedRoot = deserialize(serializedData);
    cout << "Deserialized Tree (Serialized Again): " << serialize(deserializedRoot) << endl;

    return 0;
}
