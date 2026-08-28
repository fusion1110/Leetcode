#include <bits/stdc++.h>
using namespace std;
/*
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        result[i] = product;
    }

    return result;
}
*/

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();

  vector<int> res(n, 1);

  int prefix = 1, postfix = 1;

  for (int i = 0; i < n; i++) {
    res[i] = prefix;
    prefix *= nums[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    res[i] *= postfix;
    postfix *= nums[i];
  }

  return res;
}
int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = productExceptSelf(nums);

  for (int res : result) {
    cout << res << endl;
  }
  return 0;
}
