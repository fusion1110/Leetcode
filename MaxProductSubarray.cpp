#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxProduct(vector<int>& nums)
{
    int curMaxProduct = 1;
    int curMinProduct = 1;

    int res = nums[0];

    for (int n : nums)
    {
        if (n == 0)
        {
            curMaxProduct = curMinProduct = 1;
            continue;
        }

        int tmp = curMaxProduct * n;
        curMaxProduct = max(max(n * curMaxProduct, n * curMinProduct), n);
        curMinProduct = min(min(tmp, n * curMinProduct), n);

        res = max(res, curMaxProduct);
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl; // Output: 6 (from subarray [2, 3])

    return 0;
}