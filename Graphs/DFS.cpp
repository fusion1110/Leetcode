#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &lst)
{
    vis[node] = 1;
    lst.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, lst);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[], int startNode)
{
    int vis[V] = {0};
    vector<int> lst;

    // Start DFS from the explicitly defined start node
    dfs(startNode, adj, vis, lst);

    // Optional: visit remaining disconnected components
    // for (int i = 0; i < V; i++)
    // {
    //     if (!vis[i])
    //         dfs(i, adj, vis, lst);
    // }

    return lst;
}

int main()
{
    int V = 9; // Number of vertices
    vector<int> adj[V];

    adj[0] = {}; 
    adj[1] = {2, 3};
    adj[2] = {1, 5, 6};
    adj[3] = {1, 4, 7};
    adj[4] = {3, 8};
    adj[5] = {2};
    adj[6] = {2};
    adj[7] = {3, 8};
    adj[8] = {4, 7};

    int startNode = 3; // Starting node for DFS

    vector<int> dfsResult = dfsOfGraph(V, adj, startNode);

    cout << "DFS Traversal starting from node " << startNode << ":\n";
    for (int node : dfsResult)
        cout << node << " ";
    cout << endl;

    return 0;
}
