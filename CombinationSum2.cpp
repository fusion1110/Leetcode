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
        return;

    cur.push_back(nums[i]);
    backtrack(nums, target - nums[i], cur, i+1); //directly goto the next number the only change to the orignal code
    cur.pop_back();

    // to make sure that the same number isnt used multiple times
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
    {
        i++;
    }
    backtrack(nums, target, cur, i + 1);
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end()); // Ensure nums is sorted for duplicate skipping
    vector<int> cur;
    backtrack(nums, target, cur, 0);
    return res;
}

int main()

{
    vector<int> nums = {9, 2, 2, 4, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum(nums, target);

    // Print the result
    for (const auto &combination : result)
    {
        cout << "[";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}