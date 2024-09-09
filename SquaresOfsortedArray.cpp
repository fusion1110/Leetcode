#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> sq_nums;
    for (int i = 0; i < nums.size(); i++)
    {
        sq_nums.push_back(nums[i] * nums[i]);
    }
    sort(sq_nums.begin(), sq_nums.end());
    return sq_nums;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums); // Store the result

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " "; // Print the sorted squares
    }

    return 0;
}