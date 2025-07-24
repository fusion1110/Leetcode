#include <bits/stdc++.h>
using namespace std;

vector<int> concatenatedDivisibility(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // Precompute digit counts and 10^digits mod k for each number
    vector<int> digits(n);
    vector<int> pow10mod(n);
    for (int i = 0; i < n; ++i)
    {
        digits[i] = nums[i] == 0 ? 1 : (int)log10(nums[i]) + 1;
        pow10mod[i] = 1;
        for (int j = 0; j < digits[i]; ++j)
        {
            pow10mod[i] = (pow10mod[i] * 10) % k;
        }
    }

    // DP table: mask -> (mod -> (sequence, exists))
    vector<vector<pair<vector<int>, bool>>> dp(1 << n, vector<pair<vector<int>, bool>>(k, {{}, false}));
    dp[0][0] = {{}, true};

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int mod = 0; mod < k; ++mod)
        {
            if (!dp[mask][mod].second)
                continue;

            for (int i = 0; i < n; ++i)
            {
                if (!(mask & (1 << i)))
                {
                    int new_mask = mask | (1 << i);
                    int new_mod = (mod * pow10mod[i] + nums[i]) % k;

                    if (!dp[new_mask][new_mod].second)
                    {
                        vector<int> new_seq = dp[mask][mod].first;
                        new_seq.push_back(nums[i]);
                        dp[new_mask][new_mod] = {new_seq, true};
                    }
                }
            }
        }
    }

    // Check full mask
    int full_mask = (1 << n) - 1;
    if (dp[full_mask][0].second)
    {
        return dp[full_mask][0].first;
    }
    return {};
}


int main()
{
    vector<int> nums = {3, 12, 45};
    int k = 5;

    vector<int> result = concatenatedDivisibility(nums, k);

    if (!result.empty())
    {
        for (int n : result)
        {
            cout << n << " ";
        }
    }
    else
    {
        cout << "No valid permutation found.";
    }
}
