#include <bits/stdc++.h>
using namespace std;

unordered_set<int> col;
unordered_set<int> posDiag;
unordered_set<int> negDiag;
vector<vector<string>> res;

void backtrack(int r, int n, vector<string> &board)
{
    if (r == n)
    {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c))
            continue;

        col.insert(c);
        posDiag.insert(r+c);
        negDiag.insert(r-c);
        board[r][c] = 'Q';

        backtrack(r+1, n, board);

        //clean up
        col.erase(c);
        posDiag.erase(r+c);
        negDiag.erase(r-c);
        board[r][c] = '.';

    }  
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    backtrack(0, n, board);

    return res;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    for (auto board : solutions) {
        for (auto row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
