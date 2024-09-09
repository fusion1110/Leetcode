#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    m = nums1.size();
    n = nums2.size();

    vector<int> merged(m + n);

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> merged;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums1[i] > nums2[j])
            {
                merged.push_back(nums1[i]);
            }
            else
            {
                merged.push_back(nums2[j]);
            }
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    // int m = nums1.size();
    // int n = nums2.size();
    // cout << merge(nums1, m, nums2, n) << endl;
    return 0;
}

// Todo: correct its algorithm
