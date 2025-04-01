#include <bits/stdc++.h>
using namespace std;

//*without memoization -> O(2^n)
// long long mostPoints(vector<vector<int>> &q)
// {
//     return dfs(0, q);
// }

// long long dfs(int i, vector<vector<int>> &q)
// {
//     if (i >= q.size())
//         return 0;
//     long long int take = q[i][0] + dfs(i + q[i][1] + 1, q);
//     long long int skip = dfs(i + 1, q);

//     return max(take, skip);
// }

//*with memoization -> O(n)

vector<long long> dp;

long long dfs(int i, vector<vector<int>> &q)
{
    if (i >= q.size())
        return 0;

    if(dp[i] != -1) return dp[i];

    long long int take = q[i][0] + dfs(i + q[i][1] + 1, q);
    long long int skip = dfs(i + 1, q);

    return dp[i] = max(take, skip); //storing result -> memoization
}


long long mostPoints(vector<vector<int>> &q)
{
    dp.resize(q.size(), -1);//* initialize with -1
    return dfs(0, q);
}

int main()
{
    vector<vector<int>> questions = {
        {3, 2},  // 3 points, 2 questions cooldown
        {4, 3},  // 4 points, 3 questions cooldown
        {2, 1},  // 2 points, 1 question cooldown
        {5, 2},  // 5 points, 2 questions cooldown
        {1, 0}   // 1 point, 0 questions cooldown
    };

    cout << "Maximum points that can be earned: " << mostPoints(questions) << endl;
    return 0;
}