#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums)
{
    int r1 = 0, r2 = 0;
    for (int n : nums)
    {
        int temp = max(n + r1, r2);
        r1 = r2;
        r2 = temp;
    }

    return r2;
}

int rob(vector<int> &nums)
{
    vector<int> including1(nums.begin(), nums.end() - 1);
    vector<int> excluding1(nums.begin() + 1, nums.end());

    return max(nums[0], max(helper(including1), helper(excluding1)));
}

int main()
{
    vector<int> arr = {2, 9, 8, 3, 6};
    cout << "Maximum chori is: " << rob(arr);
    cout << endl;
    return 0;
    return 0;
}