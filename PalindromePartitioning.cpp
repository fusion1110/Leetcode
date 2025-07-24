#include <bits/stdc++.h>
using namespace std;


//*Done using backtracking, its more efficient when done with DP
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, part, res);
        return res;
    }

private:
    void dfs(int i, string &s, vector<string> &part, vector<vector<string>> &res)
    {
        // base case
        if (i >= s.length())
        {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.length(); ++j)
        {
            if (isPali(s, i, j))
            {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, part, res);
                part.pop_back();
            }
        }
    }

    bool isPali(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> result = s.partition("aab");

    for (auto &vec : result)
    {
        for (auto &str : vec)
            cout << str << " ";
        cout << endl;
    }
}
