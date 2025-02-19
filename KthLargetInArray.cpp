#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{

    //* using max heap: space-> O(n), time-> O(nlogn)
    // priority_queue<int> pq; 
    
    //* using min heap: space-> O(k), time-> O(nlogk)
    priority_queue<int, vector<int>, greater<int>> pq; 
    for (int num : nums)
    {
        pq.push(num);
        if (pq.size() > k)
        {
            pq.pop(); 
        }
    }

    return pq.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "K-th Largest: " << findKthLargest(nums, k) << endl; 
    return 0;
}
