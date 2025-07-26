#include <bits/stdc++.h>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>>& isConnected, vector<int>& vis)
{
  vis[start] = 1;
  for (int j = 0; j < isConnected.size(); j++)
  {
    if (isConnected[start][j] == 1 && !vis[j])
    {
      dfs(j, isConnected, vis);
    }
  }
}
int findCircleNum(vector<vector<int>>& isConnected)
{
  // visited array -> init by 0
  vector<int> vis(isConnected.size(), 0);
  int count = 0;
  for (int i = 0; i < isConnected.size(); i++)
  {
    if (vis[i] == 0)
    {
      count++;
      dfs(i, isConnected, vis);
    }
  }

  return count;
}

int main()
{
  vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  cout << "Number of provinces: " << findCircleNum(isConnected) << endl;
  return 0;
}