#include <bits/stdc++.h>
using namespace std;

int findMinTime(int currentTime, int nextStartTime, int nextDuration)
{
    if (currentTime < nextStartTime)
    {
        return nextStartTime + nextDuration;
    }
    else
    {
        return currentTime + nextDuration;
    }
}

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                       vector<int>& waterStartTime, vector<int>& waterDuration)
{
    int mintime = INT_MAX;

    for (int i = 0; i < landStartTime.size(); i++)
    {
        for (int j = 0; j < waterStartTime.size(); j++)
        {
            int time = findMinTime(landStartTime[i] + landDuration[i],
                                   waterStartTime[j], waterDuration[j]);
            mintime = min(mintime, time);
        }
    }

    for (int i = 0; i < waterStartTime.size(); i++)
    {
        for (int j = 0; j < landStartTime.size(); j++)
        {
            int time = findMinTime(waterStartTime[i] + waterDuration[i],
                                   landStartTime[j], landDuration[j]);
            mintime = min(mintime, time);
        }
    }

    return mintime;
}

int main()
{

    return 0;
}