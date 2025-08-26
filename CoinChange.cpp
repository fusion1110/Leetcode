#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

// result is only possible the coins less than the amt exists
// if not possible then return -1
// By Greedy choose the biggest number
// doing by DP first

// recursive approach
//  int coinChange(vector<int>& coins, int amount)
//  {
//      bool ready[amount];
//      int value[amount];
//      int best = 0;
//      if (coins.empty() || amount < 0)
//      {
//          return -1;
//      }
//      if (ready[amount])
//      {
//          return value[amount];
//      }

//     for (auto c : coins)
//     {
//         best = min(best, coinChange(vector<int> & coins, (amount - c) + 1));
//     }
//     value[amount] = best;
//     ready[amount] = true;

//     return best;
// }

// iterative
int coinChange(vector<int>& coin, int amount)
{
    vector<int> value(amount + 1, INT_MAX);
    value[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for(auto c : coin){
            if(i - c >= 0  && value[i - c] != INT_MAX){
                value[i] = min(value[i], value[i-c]+1);
            }
        }
    }

    return (value[amount] == INT_MAX) ? -1 : value[amount];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}