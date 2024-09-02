#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    vector<int> merged(m + n);
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

    cout << "Merged vector: \n";
    for (int num : merged)
    {
        cout << num << " ";
    }
    cout << endl;

    int size = merged.size();

    if (size % 2 != 0)
    {
        return merged[size / 2];
    }
    else
    {
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    }
}
int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    return 0;
}