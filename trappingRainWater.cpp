#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int leftMax = height[l];
    int rightMax = height[r];
    int total = 0;

    while (l < r)
    {
        if (leftMax <= rightMax)
        {
            l++;
            leftMax = max(leftMax, height[l]);
            total += leftMax - height[l];
        }

        else
        {
            r--;
            rightMax = max(rightMax, height[r]);
            total += rightMax - height[r];
        }
    }

    return total;
}
int main()
{
    vector<int> ip = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = trap(ip);
    cout << res<<endl;
    return 0;
}