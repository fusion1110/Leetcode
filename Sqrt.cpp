#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }

    int l = 0, h = x;
    int mid = 0;

    while (l <= h)
    {
        mid = l + (h - l) / 2;
        long long square = (long long)mid * mid;

        if (square == x)
        {
            return mid;
        }
        else if (square > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return h; 
}

int main()
{
    cout << mySqrt(8) << endl;
    return 0;
}

// *https://chatgpt.com/share/f19c6ee0-0de7-44b5-b972-c55c6c31dc71 --> visualisation of the above algorithm