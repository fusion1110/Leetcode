#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool bfsCycle(vector<vector<int>>& adjLs, int start, vector<int>& vis)
{
    // stores a pair -> (node, parent node)
    queue<pair<int, int>> q;

    q.push({start, -1});
    vis[start] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto& x : adjLs[node])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                q.push({x, node});
            }
            else if (parent != x)
            {
                return true;
            }
        }
    }
    return false;
}

bool dfsCycle(int node, int parent, vector<vector<int>>& adjLs,
              vector<int>& vis)
{
    vis[node] = 1;
    for (auto& x : adjLs[node])
    {
        if (!vis[x])
        {
            if (dfsCycle(x, node, adjLs, vis) == true)
            {
                return true;
            }
        }
        else if (x != parent)
        {
            return true;
        }
    }

    return false;
}
bool isCycleInGraph(vector<vector<int>>& adjLs)
{
    vector<int> vis(adjLs.size(), 0);
    for (int i = 0; i < adjLs.size(); ++i)
    {
        if (!vis[i])
        {
            if (bfsCycle(adjLs, i, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 8;
    vector<vector<int>> adjLs(n);

    adjLs[1] = {2, 3};
    adjLs[2] = {1, 5};
    adjLs[3] = {1, 4, 6};
    adjLs[4] = {3};
    adjLs[5] = {2, 7};
    adjLs[6] = {3, 7};
    adjLs[7] = {5, 6};

    // --- Using BFS ---
    vector<int> vis_bfs(n, 0);
    bool cycle_bfs = false;
    for (int i = 0; i < n; ++i)
    {
        if (!vis_bfs[i])
        {
            if (bfsCycle(adjLs, i, vis_bfs))
            {
                cycle_bfs = true;
                break;
            }
        }
    }

    if (cycle_bfs)
    {
        cout << "Cycle detected in the graph (using bfs).\n";
    }
    else
    {
        cout << "No cycle found in the graph (using bfs).\n";
    }

    // --- Using DFS ---
    vector<int> vis_dfs(n, 0);
    bool cycle_dfs = false;
    for (int i = 0; i < n; ++i)
    {
        if (!vis_dfs[i])
        {
            if (dfsCycle(i, -1, adjLs, vis_dfs))
            {
                cycle_dfs = true;
                break;
            }
        }
    }

    if (cycle_dfs)
    {
        cout << "Cycle detected in the graph (using dfs).\n";
    }
    else
    {
        cout << "No cycle found in the graph (using dfs).\n";
    }

    return 0;
}
