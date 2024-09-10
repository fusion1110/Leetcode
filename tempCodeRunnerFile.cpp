for (int j = 0; j < prices.size(); j++)
    {
        if (prices[j] < minPrice)
        {
            minPrice = prices[j];
            min_day = j;
        }
    }