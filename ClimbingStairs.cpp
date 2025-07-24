#include <bits/stdc++.h>
using namespace std;

vector<int> cache;

int dfs(int n, int i)
{
    if (i >= n)
        return i == n;
    if (cache[i] != -1)
        return cache[i];
    return cache[i] = dfs(i + 1, n) + dfs(i + 2, n);
}

int climbStairs(int n)
{
    cache.resize(n, -1);
    return dfs(0, n);
}

int main()
{

    return 0;
}