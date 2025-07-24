#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // start from top right corner
    int i = 0, j = cols - 1;

    while (i < rows && j >= 0)
    {
        // to find range/ select row
        if (matrix[i][0] <= target && matrix[0][j] >= target)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                // move left
                j--;
            }
            else
            {
                // move down
                i++;
            }
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    bool found = searchMatrix(matrix, 20);
    cout << found << endl;
    return 0;
}

//! not the optimal solution