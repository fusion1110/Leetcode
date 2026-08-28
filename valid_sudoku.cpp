#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
  vector<set<char>> rows(9);
  vector<set<char>> cols(9);
  vector<set<char>> cells(9);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        continue;
      }

      char x = board[i][j];

      if (!rows[i].insert(x).second) {
        return false;
      }
      if (!cols[j].insert(x).second) {
        return false;
      }

      int cell = (i / 3) * 3 + (j / 3);
      if (!cells[cell].insert(x).second) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  vector<vector<char>> v = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << isValidSudoku(v) << endl;
  ;
}
