#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {

        if (price < minPrice)
        {
            minPrice = price;
        }
        else
        {
            maxProfit = max(maxProfit, price - minPrice);
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {2,4,1};
    cout << maxProfit(prices);
    cout << endl;

    return 0;
}