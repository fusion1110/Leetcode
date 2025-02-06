#include <bits/stdc++.h>
using namespace std;

int tupleSameProduct(vector<int> &nums)
{
    int res = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            map[nums[i] * nums[j]]++;
        }
    }

    for (auto [productValue, productFreq] : map)
    {
        //* formula for permutation
        int equalPairs = (productFreq - 1) * productFreq / 2;

        res += 8 * equalPairs;
    }

    return res; // Return the number of combinations
}

int main()
{
    vector<int> nums = {2, 3, 4, 6, 8, 12};  // Example input
    int ans = tupleSameProduct(nums); // Call the function
    cout << ans << endl;
    return 0;
}