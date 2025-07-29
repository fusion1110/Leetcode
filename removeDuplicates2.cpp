#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() <= 2)
    {
        return nums.size();
    }
    int i = 2;
    for (int j = 2; j < nums.size(); j++)
    {
        if (nums[j] != nums[i - 2])
        { // unique element
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

int main()
{

    vector<int> nums = {0, 0, 0, 1, 1, 2, 3, 4};
    int res = removeDuplicates(nums);
    cout << res << endl;

    for (int i = 0; i < res; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}