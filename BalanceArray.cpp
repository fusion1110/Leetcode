#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//not good to always target max
// int minRemoval(vector<int>& nums, int k)
// {
//     int count = 0;
//     if (nums.empty() || nums.size() == 1)
//     {
//         return count;
//     }
//     auto arrMax = max_element(nums.begin(), nums.end());
//     auto arrMin = min_element(nums.begin(), nums.end());

//     while (true)
//     {
//         auto arrMax = max_element(nums.begin(), nums.end());
//         auto arrMin = min_element(nums.begin(), nums.end());

//         if (*arrMin == 0)
//         {
//             break;
//         }

//         if (*arrMax / *arrMin <= k)
//         {
//             break;
//         }

//         nums.erase(arrMax);
//         count++;

//         if (nums.size() <= 1)
//         {
//             break;
//         }
//     }

//     return count;
// }

int minRemoval(std::vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int maxLen = 0;
    int n = nums.size();

    for (int left = 0, right = 0; right < n; ++right) {
        while (nums[right] > (long long)nums[left] * k) {
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    return n - maxLen;
}


int main()
{

    return 0;
}