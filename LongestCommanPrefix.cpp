#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  for (int i = 0; i < strs[0].length(); i++) {
    for (const string& s : strs) {
      if (i == s.length() || s[i] != strs[0][i]) {
        return strs[0].substr(0, i);
      }
    }
  }
  return strs[0];
}

int main() {
  vector<string> str = {"dance", "dag", "danger", "damage"};
  cout << longestCommonPrefix(str) << endl;
}
