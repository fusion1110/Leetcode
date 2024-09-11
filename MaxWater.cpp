#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size() - 1;
    int maxArea = 0;
    while (l < r)
    {
        int width = r - l;
        int h = min(height[l], height[r]);
        maxArea = max(maxArea, h * width);
        if (height[l] < height[r])
            l++;
        else
        {
            r--;
        }
    }
    return maxArea;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    return 0;
}