#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0;
    int h = arr.size() - 1;
    int peak = __INT_MAX__;

    while (l <= h)
    {
        int mid = l + (h -1)/2;
        if(mid == peak){
            return mid;
        }
        else if(mid > peak){
            
        }
    }
}

int main()
{

    return 0;
}