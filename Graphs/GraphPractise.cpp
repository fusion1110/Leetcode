#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{

public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool directed)
    {
        // 0 -> undirected graph
        // 1 -> directed graph

        // make an edge from u to v
        adjList[u].push_back(v);
        if (!directed)
        {
            // make an edge from v to u also
            adjList[v].push_back(u);
        }
    }
    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    int n, m;
    bool directed;
    cout << "Is the graph directed? (1 for yes, 0 for no): ";
    cin >> directed;
    cout << "Enter the number of vertices: ";
    cin >> m;
    cout << "Enter the number of edges: ";
    cin >> n;
    cout << "Enter the edges (u v):" << endl;
    // Input edges
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, directed); // false for undirected graph
    }

    g.printGraph();
    return 0;
}