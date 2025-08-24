#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

unordered_set<int> cols;
unordered_set<int> diag;
unordered_set<int> antiDiag;
vector<vector<string>> res;

void backtrack(int row, int n, vector<string>& board)
{
    if (row == n)
    {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (cols.count(col) || diag.count(col + row) ||
            antiDiag.count(col - row + n - 1))
        {
            continue;
        }

        cols.insert(col);
        diag.insert(col + row);
        antiDiag.insert(col - row + n - 1);
        board[row][col] = 'Q';

        backtrack(row + 1, n, board);

        // clean up
        cols.erase(col);
        diag.erase(row + col);
        antiDiag.erase(row - col);
        board[row][col] = '.';
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    backtrack(0, n, board);

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto solutions = solveNQueens(n);
    for (auto& sol : solutions)
    {
        for (auto& row : sol)
        {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}