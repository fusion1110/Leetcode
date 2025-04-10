#include <bits/stdc++.h> 
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        backtrack(0, {}, nums);
        return res;
    }

    void backtrack(int i, vector<int> subset, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[i]);
        backtrack(i + 1, subset, nums);
        subset.pop_back();

        // Skip duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Exclude current element
        backtrack(i + 1, subset, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
