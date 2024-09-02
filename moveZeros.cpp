#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[i + 1]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        cout << nums[j] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    return 0;
}