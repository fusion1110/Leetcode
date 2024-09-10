#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int min_day = 0;
    int maxPrice = INT_MIN;
    int max_day = 0;

    for (int j = 0; j < prices.size() - 1; j++)
    {
        if (prices[j] < minPrice)
        {
            minPrice = prices[j];
            min_day = j;
        }
    }
    cout << minPrice << endl;

    for (int i = min_day; i < prices.size(); i++)
    {
        if (prices[i] > maxPrice)
        {
            maxPrice = prices[i];
            max_day = i;
        }
    }
    cout << maxPrice << endl;

    if (min_day < max_day)
    {
        int result = maxPrice - minPrice;
        return result;
    }

    else
    {
        return 0;
    }
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(prices);
    cout << endl;

    return 0;
}