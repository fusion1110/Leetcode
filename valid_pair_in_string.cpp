#include <bits/stdc++.h>
using namespace std;

string findValidPair(string s)
{
    string res;
    unordered_map<char, int> countMap;
    for (auto &c : s)
    {
        countMap[c]++;
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        int num1 = s[i] - '0';

        if (countMap[s[i]] == num1)
        {
                int num2 = s[i+1] - '0';
                if (countMap[s[i+1]] == num2 && s[i] != s[i+1])
                {
                    res = string(1, s[i]) + string(1, s[i+1]);
                    return res;
            }
        }
    }
    return "";
}

int main()
{
    string ans = findValidPair("22");
    cout << ans << endl;

    return 0;
}