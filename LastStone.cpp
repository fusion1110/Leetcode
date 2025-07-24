#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;

    for (int n : stones)
    {
        pq.push(n);
    }

    while (pq.size() > 1) 
    {
        int x = pq.top();
        pq.pop();

        int y = pq.top();
        pq.pop();
        
        if (x != y) // Only push if they are not equal
        {
            pq.push(abs(x - y));
        }
    }

    return pq.empty() ? 0 : pq.top(); // Return 0 if no stones left
}

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl; // Output: 1

    return 0;
}

//* Problem without if statement
// You always push abs(x - y) back into the priority queue, even if x == y.
// If x == y, both stones are destroyed, and nothing should be pushed back.
// This could lead to an unnecessary 0 in the heap, causing incorrect results.