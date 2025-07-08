#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int r1 = 0, r2 = 0;
    for (int n : nums)
    {
        int temp = max(n + r1, r2);
        r1 = r2;
        r2 = temp;
    }

    return r2;
}

int main()
{
    vector<int> arr = {2, 9, 8, 3, 6};
    cout << "Maximum chori is: " << rob(arr);
    cout << endl;
    return 0;
}