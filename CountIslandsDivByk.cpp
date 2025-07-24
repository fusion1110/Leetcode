#include <bits/stdc++.h>
using namespace std;
//all for directions: left, right, up, down
int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

long long dfs(vector<vector<int>> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] <= 0)
        return 0;

    long long islandValue = grid[r][c]; 
    grid[r][c] = 0; 

    for (int x = 0; x < 4; x++) {
        islandValue += dfs(grid, r + directions[x][0], c + directions[x][1]);
    }

    return islandValue;
}

long long countIslands(vector<vector<int>>& grid, long long k)
{

    if (grid.empty() || grid[0].empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    long long Count = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] > 0)
            {
                long long LandSum = dfs(grid, r, c);
                if(LandSum % k == 0) {
                    Count++;
                }
            }
        }
    }

    return Count;
}

int main()
{
    int rows, cols, k;
    cin >> rows >> cols >> k;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cin >> grid[r][c];
        }
    }
    cout << countIslands(grid, k) << endl;
    return 0;
}