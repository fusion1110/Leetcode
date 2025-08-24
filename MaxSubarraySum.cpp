#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxSubArray(vector<int>& nums) {
    //initialise the best with 'INT_MIN' for array with all negative elements

    int best = INT_MIN, sum = -1;

    for(int i = 0; i < nums.size(); ++i){
        sum = max(nums[i], nums[i]+sum);
        best = max(sum, best);
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {-1,2,4-3,5,3,-5,2};
    cout<< maxSubArray(v)<<endl;

    return 0;
}