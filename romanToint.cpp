#include <iostream>
#include <map>
using namespace std;

int romanToInt(string s)
{
    // int I = 1;
    // int V = 5;
    // int X = 10;
    // int L = 50;
    // int C = 100;
    // int D = 500;
    // int M = 1000;
    // int ans = 0;
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i < s.length() - 1 && m[s[i]] < m[s[i + 1]])
        {
            ans -= m[s[i]];
        }
        else
        {
            ans += m[s[i]];
        }
    }

    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] == 'I')
    //     {
    //         ans += I;
    //     }
    //     else if (s[i] == 'V')
    //     {
    //         if (i > 0 && s[i - 1] == 'I')
    //             ans += V - 2 * I;
    //         else
    //             ans += V;
    //     }
    //     else if (s[i] == 'X')
    //     {
    //         if (i > 0 && s[i - 1] == 'I')
    //             ans += X - 2 * I;
    //         else
    //             ans += X;
    //     }
    //     else if (s[i] == 'L')
    //     {
    //         if (i > 0 && s[i - 1] == 'X')
    //             ans += L - 2 * X;
    //         else
    //             ans += L;
    //     }
    //     else if (s[i] == 'C')
    //     {
    //         if (i > 0 && s[i - 1] == 'X')
    //             ans += C - 2 * X;
    //         else
    //             ans += C;
    //     }
    //     else if (s[i] == 'D')
    //     {
    //         if (i > 0 && s[i - 1] == 'C')
    //             ans += D - 2 * C;
    //         else
    //             ans += D;
    //     }
    //     else if (s[i] == 'M')
    //     {
    //         if (i > 0 && s[i - 1] == 'C')
    //             ans += M - 2 * C;
    //         else
    //             ans += M;
    //     }
    // }
    return ans;
}

int main()
{
    cout << romanToInt("IV") << endl;
    cout << romanToInt("VI") << endl;
    return 0;
}
