#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    // imax is maxValue of nums[i]
    // dmax is maxValue of nums[i] - nums[j]
    long long maxValue = 0, imax = 0, dmax = 0;
    for (int k = 0; k < nums.size(); k++)
    {
        maxValue = max(maxValue, dmax * nums[k]);
        dmax = max(dmax, imax - nums[k]);
        // C++ type conversion
        imax = max(imax, static_cast<long long>(nums[k]));
    }
    return maxValue;
}

int main()
{

    vector<int> nums = {3, 7, 1, 5, 10};
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}