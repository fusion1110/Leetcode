#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    for (int j = 0, i = m; j < n; j++)
    {
        nums1[i] = nums2[j];
        i++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has space for nums2's elements
    vector<int> nums2 = {2, 5, 6};          // Elements to merge into nums1
    int m = 3;                              // The number of valid elements in nums1
    int n = nums2.size();                   // The number of elements in nums2

    merge(nums1, m, nums2, n);

    // Output merged and sorted nums1
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    return 0;
}
