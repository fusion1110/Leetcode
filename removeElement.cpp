#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    for (int i = 0; i < n;)
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            n--;
        }
        else
        {
            i++;
        }
    }
    return n;
}

int main()
{
    vector<int> nums = {3, 2, 2, 3, 4, 5, 3};
    int val = 3;
    cout << removeElement(nums, val) << endl;

    return 0;
}
