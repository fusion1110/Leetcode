#include <bits/stdc++.h>
using namespace std;
//all for directions: left, right, up, down
int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(vector<vector<char>> &grid, int r, int c)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0')
        return;

    //marking it as visited
    grid[r][c] = '0';

    // Explore all four directions
    for(int x = 0; x < 4; x++){
        dfs(grid, r + directions[x][0], c + directions[x][1]);
    }
}

int numIslands(vector<vector<char>> &grid)
{

    if (grid.empty() || grid[0].empty())
        return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == '1') 
            {
                dfs(grid, r, c);
                islandCount++;
            }
        }
    }

    return islandCount;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cin >> grid[r][c];
        }
    }
    cout << numIslands(grid) << endl;
    return 0;
}