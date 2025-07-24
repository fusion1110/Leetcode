#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // Avoid overflow in calculating mid
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << searchInsert(nums, target) << endl;
    return 0;
}