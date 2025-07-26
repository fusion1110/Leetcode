#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int orangesRotting(vector<vector<int>>& grid)
{
    queue<pair<int, int>> q;
    int fresh = 0;
    int time = 0;

    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (grid[r][c] == 1)
            {
                fresh++;
            }

            if (grid[r][c] == 2)
            {
                // push the position of the rotten orange
                q.push({r, c});
            }
        }
    }

    while (fresh > 0 && !q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            // starting point
            auto cur = q.front();
            q.pop();

            int r = cur.first;
            int c = cur.second;

            // better speed and memory efficiency
            for (int i = 0; i < 4; i++)
            {
                int row = r + directions[i][0];
                int col = c + directions[i][1];
                if (row >= 0 && row < grid.size() && col >= 0 &&
                    col < grid[0].size() && grid[row][col] == 1)
                {
                    grid[row][col] = 2; // rotten abh
                    q.push({row, col});
                    fresh--;
                }
            }
        }
        time++;
    }

    // if fresh == 0 then return time else -1
    return fresh == 0 ? time : -1;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    int result = orangesRotting(grid);
    if (result == -1)
    {
        cout << "Not all oranges can rot." << endl;
    }
    else
    {
        cout << "Minutes to rot all oranges: " << result << endl;
    }

    return 0;
}