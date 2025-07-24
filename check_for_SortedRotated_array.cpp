#include<bits/stdc++.h> 
using namespace std;

bool check(vector<int>& nums) {
        int changes = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // * modulo n to make it of circular nature       
            if (nums[i] > nums[(i + 1) % n]) {
                changes++;
            }
            // *If the array is originally sorted, it should have at most one drop (i.e., at most one point where nums[i] > nums[i+1]).
            if (changes > 1)
                return false;
        }

        return true;
    }

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};  // Rotated sorted array
    vector<int> nums2 = {2, 1, 3, 4};     // Not a rotated sorted array
    vector<int> nums3 = {1, 2, 3, 4, 5};  // Already sorted (zero rotations)
    vector<int> nums4 = {1, 1, 1, 1};     // All same elements (valid)

    cout << check(nums1) << endl;  // Output: 1 (true)
    cout << check(nums2) << endl;  // Output: 0 (false)
    cout << check(nums3) << endl;  // Output: 1 (true)
    cout << check(nums4) << endl;  // Output: 1 (true)

    return 0;
}