#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

int lengthOfLIS(vector<int>& nums)
{
    vector<int> sub;
    for (int n : nums)
    {
        if (sub.empty() || sub[sub.size() - 1] < n) //instead of sub[sub.size() - 1] sub.back can also be used
        {
            sub.push_back(n);
        }
        else
        {
            auto it = lower_bound(sub.begin(), sub.end(), n);
            *it = n;
        }
    }

    return sub.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {6, 2, 5, 1, 7, 4, 8, 3};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}