#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &res)
{
    if (i >= nums.size())
    {
        res.push_back(subset);
        return;
    }

    // *inlcude the number

    //*i++ increments i after passing it to dfs, which means dfs always receives the old i, causing an infinite loop.
    // *The correct way is to use i + 1
    subset.push_back(nums[i]);
    dfs(nums, i + 1, subset, res);

    // *not include the number
    subset.pop_back(); //*Uses backtracking (subset.pop_back()) to revert changes.S
    dfs(nums, i + 1, subset, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> subset;
    dfs(nums, 0, subset, res);
    return res;
}

int main()
{

    return 0;
}