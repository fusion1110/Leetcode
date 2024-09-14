#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
         int y, int &health)
{
    int m = grid.size();
    int n = grid[0].size();

    if (x < 0 || x >= m || y < 0 || y >= n || health <= 0 ||
        visited[x][y])
    {
        return false;
    }
    if (x == m - 1 && y == n - 1 && health > 0)
    {
        return true;
    }

    visited[x][y] = true;

    if (grid[x][y] == 1)
    {
        health--;
    }

    for (auto &dir : directions)
    {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (dfs(grid, visited, newX, newY, health))
        {
            return true;
        }
    }

    visited[x][y] = false; // backtracking

    return false;
}

bool findSafeWalk(vector<vector<int>> &grid, int health)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(grid, visited, 0, 0, health);
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}};
    int health = 4;

    bool result = findSafeWalk(grid, health);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
