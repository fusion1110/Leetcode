#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    
    vector<int> count(26, 0);
    for (char task : tasks)
    {
        count[task - 'A']++;
    }

    priority_queue<int> maxHeap;
    for (int cnt : count)
    {
        if (cnt > 0)
            maxHeap.push(cnt);
    }

    int time = 0;
    queue<pair<int, int>> q;

    while (!maxHeap.empty() || !q.empty())
    {
        time++;

        //* return the final time if heap is empty
        if (maxHeap.empty())
        {
            time = q.front().second;
        }

        //* takes the top task and does that, decreases its count and stores the count and the next available time in queue
        else
        {
            int cnt = maxHeap.top() - 1;
            maxHeap.pop();
            if (cnt > 0)
            {
                q.push({cnt, time + n});
            }
        }

        //*reinsert the element when time reaches its time
        if (!q.empty() && q.front().second == time)
        {
            maxHeap.push(q.front().first);
            q.pop();
        }
    }

    return time;
}

int main()
{

    return 0;
}