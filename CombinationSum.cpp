#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void backtrack(vector<int> &nums, int target, vector<int> &cur, int i)
{
    if (target == 0)
    {
        res.push_back(cur);
        return;
    }

    if (target < 0 || i >= nums.size())
    {
        return;
    }

    cur.push_back(nums[i]);                    // inclusion of the current element
    backtrack(nums, target - nums[i], cur, i); // choose the current element
    cur.pop_back();                            // revert the choice that is removing the current element

    backtrack(nums, target, cur, i + 1); // add the next element
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<int> cur;
    backtrack(nums, target, cur, 0);
    return res;
}

int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(nums, target);
    for (auto &row : res)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}