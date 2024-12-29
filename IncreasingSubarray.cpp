#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAdjacentIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Edge case: If the array size is less than 2 * k, it's impossible to have two adjacent subarrays of length k
        if (n < 2 * k) {
            return false;
        }
        
        // Lambda function to check if a subarray nums[start:start + k] is strictly increasing
        auto isStrictlyIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    return false;
                }
            }
            return true;
        };
        
        // Slide through the array to check each subarray of length k
        for (int i = 0; i <= n - 2 * k; ++i) {
            // Check if the subarray starting at i is strictly increasing
            if (isStrictlyIncreasing(i)) {
                // Check if the next subarray starting at i + k is also strictly increasing
                if (isStrictlyIncreasing(i + k)) {
                    return true;
                }
            }
        }
        
        // If we finish the loop without finding such pairs, return false
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4};  // Example array
    int k = 2;  // Subarray length
    
    bool result = solution.hasAdjacentIncreasingSubarrays(nums, k);
    cout << (result ? "True" : "False") << endl;  // Expected output: True
    
    return 0;
}
