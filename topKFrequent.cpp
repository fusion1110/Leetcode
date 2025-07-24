#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> count;

    for (int n : nums)
    {
        count[n]++; // mapped the frequency of each element
    }

    cout << "frequency Count\n";
    for (auto x : count)
    {
        cout << x.first << " " << x.second;
        cout << endl;
    }

    //*a vector of vectors to store the elements with their respected freq
    vector<vector<int>> freq(n + 1);

    for (auto &[num, cnt] : count) //'num' corresponds to the each individual element in the count map and 'cnt' is the freq of each of the element
    {
        freq[cnt].push_back(num);
    }

    // freq[0] -> {}      // No numbers have 0 frequency (this is not used)
    // freq[1] -> {3}     // Number 3 appears 1 time
    // freq[2] -> {2}     // Number 2 appears 2 times
    // freq[3] -> {1}     // Number 1 appears 3 times
    // freq[4] -> {}      // No numbers have 4 frequency
    // ...
    // freq[6] -> {}      // Max frequency can be n, but in this case, it is not used

    vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; --i)
    {
        for (int num : freq[i])
        {
            result.push_back(num);
            if (result.size() == k)
                break;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {7, 7};
    vector<int> result = topKFrequent(nums, 1);
    cout << "Result: ";
    for (int n : result)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

//* for revision: https://chatgpt.com/share/66fd4d9e-3e18-800e-ac92-ed3ecae9bbb5
