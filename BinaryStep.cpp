#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void search(vector<int>& nums, int x)
{
    sort(nums.begin(), nums.end());

    int k = 0;
    for (int b = nums.size() / 2; b >= 1; b /= 2)
    {
        while (k + b < nums.size() && nums[k + b] <= x)
        {
            cout << "Current k: " << k << endl;
            k += b;
            cout << "New k: " << k << endl;
        }
    }
    if (nums[k] == x)
    {
        cout << "Found at index: " << k << endl;
    }
    else
    {
        cout << "Not in array\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {2, 4, 7, 10, 13, 18, 21, 27};

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << "\n";
    // }
    search(v, 18);
    return 0;
}