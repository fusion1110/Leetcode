#include <iostream>
using namespace std;

int reverse(int x)
{
    int sign = 1;
    if (x < 0)
    {
        sign = -1;
        x = -x;
    }

    int rev = 0;
    while (x > 0){
        
    }
    // int rev = 0;
    // while (x > 0)
    // {
    //     rev = rev * 10 + x % 10;
    //     x = x / 10;
    // }
    // return sign * rev;


}

int main()
{
    int result = reverse(321);
    cout << result;
    return 0;
}