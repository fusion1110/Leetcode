#include <bits/stdc++.h>
using namespace std;

long long coloredCells(int n)
{
    return 1 + 2 * ((n - 1) * n);
}

int main()
{
    cout << coloredCells(4) << endl;
    return 0;
}