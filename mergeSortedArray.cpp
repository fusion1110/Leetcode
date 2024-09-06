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

    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
          merged.begin());

    for (int i = 0; i < (m + n);)
    {
        if (merged[i] == 0)
        {
            merged.erase(merged.begin() + i);
            n--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = nums1.size();
    int n = nums2.size();
    // cout << merge(nums1, m, nums2, n) << endl;
    return 0;
}

// Todo: correct its algorithm

