#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<int, bool> dp;

bool dfs(string& s, vector<string>& wordDict, int i)
{
    // memoization check
    if (dp.find(i) != dp.end())
    {
        return dp[i];
    }

    for (const string& w : wordDict)
    {
        //checks if it is in bound and is the substring part of the string s
        if (i + w.length() <= s.length() && s.substr(i, w.length()) == w)
        {
            if (dfs(s, wordDict, i + w.length()))
            {
                dp[i] = true;
                return true;
            }
        }
    }
    dp[i] = false;
    return false;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    dp[s.length()] = true;
    return dfs(s, wordDict, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}