#include <bits/stdc++.h>
using namespace std;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>>& ans,
         int initColor, int newColor)
{

    ans[sr][sc] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int newR = sr + directions[i][0];
        int newC = sc + directions[i][1];

        if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
            image[newR][newC] == initColor && ans[newR][newC] != newColor)
        {
            dfs(newR, newC, image, ans, initColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                              int color)
{
    int initColor = image[sr][sc];
    if (initColor == color)
    {
        return image;
    }
    // not to tamper with the orignal data -> irl
    vector<vector<int>> ans = image;
    dfs(sr, sc, image, ans, initColor, color);

    return ans;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    int sr = 1, sc = 1; // starting row and column
    int newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Flood filled image:\n";
    for (auto& row : result)
    {
        for (int pixel : row)
        {
            cout << pixel << " ";
        }
        cout << "\n";
    }

    return 0;
}