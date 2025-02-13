#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    KthLargest kthLargest(2, nums); // Correct object initialization

    cout << kthLargest.add(4) << endl; // Example usage
    cout << kthLargest.add(5) << endl;

    return 0;
}