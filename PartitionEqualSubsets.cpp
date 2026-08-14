#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;

int sum(vector<int> nums)
{
    int sum = 0;
    for (int n : nums)
    {
        sum += n;
    }

    return sum;
}

bool canPartition(vector<int>& nums)
{
    if (sum(nums) % 2 != 0)
    {
        return false;
    }

    int target = sum(nums) / 2;
    unordered_set<int> dp;
    dp.insert(0);

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        //cloning the dp into nextDp to preserve the previous computed sums
        unordered_set<int> nextDp = dp;
        for (int t : dp)
        {
            if (t + nums[i] == target)
            {
                return true;
            }
            nextDp.insert(t + nums[i]);
        }
        //updates the dp to inculcate all the sums done in this iteration ie, nums[i]
        dp = nextDp;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}