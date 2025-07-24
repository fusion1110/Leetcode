#include <bits/stdc++.h>
using namespace std;
// all for directions: left, right, up, down
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(vector<vector<int>> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
        return 0;

    int res = 1; //min area of 1 island
    // marking it as visited
    grid[r][c] = 0;

    // Explore all four directions
    for (int x = 0; x < 4; x++)
    {
        res += dfs(grid, r + directions[x][0], c + directions[x][1]);
    }
    return res;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{

    if (grid.empty() || grid[0].empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int maxArea = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 1)
            {
                maxArea = max(maxArea, dfs(grid, r, c));
            }
        }
    }

    return maxArea;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            cin >> grid[r][c];
        }
    }
    cout << maxAreaOfIsland(grid) << endl;
    return 0;
}