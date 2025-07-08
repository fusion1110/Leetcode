#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    //solving subproblems first
    for (int i = cost.size() - 1; i >= 0; i--)
    {
        cost[i] += min(cost[i + 1], cost[i + 2]);
    }

    //only compare the values for 0th and 1st index
    return min(cost[0], cost[1]);
}

int main()
{
    

    return 0;
}