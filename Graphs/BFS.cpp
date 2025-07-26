#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start,  vector<vector<int>> &adj, int n)
{
    vector<int> vis(n, 0);
    vis[start] = 1;
    queue<int> q;
    q.push(start);
    vector<int> bfsTraversal;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsTraversal.push_back(node);

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }

    return bfsTraversal;
}

int main()
{
    int n = 10; 
    vector<vector<int>> adj(n);

    // Sample undirected graph
    adj[0] = {};
    adj[1] = {2,6};
    adj[2] = {1,3,4};
    adj[3] = {2};
    adj[4] = {2,5};
    adj[5] = {4};
    adj[6] = {1,7,9};
    adj[7] = {6,8};
    adj[8] = {7};
    adj[9] = {6};

    int startNode = 1;
    vector<int> result = bfs(startNode, adj, n);

    cout << "BFS traversal from node " << startNode << ": ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}