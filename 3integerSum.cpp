#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        //skip dublicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = nums.size() - 1;
        int target = -nums[i];
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == target)
            {
                result.push_back({nums[i], nums[l], nums[r]});


                //skip dublicates
                while (l < r && nums[l] == nums[l + 1])
                    l++;
                //skip dublicates
                while (l < r && nums[r] == nums[r - 1])
                    r--;

                l++;
                r--;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> test = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(test);

    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}