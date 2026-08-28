#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  int row = text1.length();
  int col = text2.length();

  vector<vector<int>> grid(row + 1, vector<int>(col + 1, 0));

  if (row == 0 || col == 0) {
    return 0;
  }

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= col; j++) {

      if (text1[i - 1] == text2[j - 1])
        grid[i][j] = grid[i - 1][j - 1] + 1;
      else
        grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
    }
  }

  return grid[row][col];
}

int main() {
  string text1, text2;

  cout << "Enter first string: ";
  cin >> text1;

  cout << "Enter second string: ";
  cin >> text2;

  cout << "Longest Common Subsequence length: "
       << longestCommonSubsequence(text1, text2) << '\n';

  return 0;
}
