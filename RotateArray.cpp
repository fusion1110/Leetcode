#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{

    int n = nums.size();
    k = k % n; // *to handle the cases where k is more than the size of vector
    reverse(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    reverse(nums.begin(), nums.begin() + k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    reverse(nums.begin() + k, nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    rotate(nums, k);
    return 0;
}