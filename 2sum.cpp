#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> m;

  /*each number : their index*/
  for (int i = 0; i < nums.size(); i++) {
    m[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++) {
    int diff = target - nums[i];

    if (m.count(diff) && m[diff] != i) {
      return {i, m[diff]};
    }
  }

  return {};
}

int main() {
  vector<int> test = {3, 2, 4};
  vector<int> result = twoSum(test, 6);

  for (int r : result) {
    cout << r << " ";
  }

  cout << endl;
  return 0;
}
