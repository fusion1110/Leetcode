#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.empty())
        return {{}}; // empty list

    vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
    vector<vector<int>> perms = permute(tmp);
    vector<vector<int>> res;

    for (auto &p : perms)
    {
        for (int i = 0; i < p.size() + 1; ++i)
        {
            vector<int> p_copy = p;
            p_copy.insert(p_copy.begin() + i, nums[0]);
            res.push_back(p_copy);
        }
    }

    return res;
}

int main()
{   

    return 0;
}