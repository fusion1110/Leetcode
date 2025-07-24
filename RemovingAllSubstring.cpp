#include <bits/stdc++.h>
using namespace std;

bool checkMatch(stack<char> &s, string &part, int partLen)
{
    stack<char> tmp = s;

    for (int i = partLen - 1; i >= 0; i--)
    {
        if (tmp.top() != part[i])
        {
            return false;
        }
        tmp.pop();
    }

    return true;
}

string removeOccurrences(string s, string part)
{
    stack<char> str;

    int partLen = part.length();
    int sLen = s.length();

    for (int i = 0; i < sLen; i++)
    {
        str.push(s[i]);

        if (str.size() >= partLen && checkMatch(str, part, partLen))
        {
            for (int j = 0; j < partLen; j++)
            {
                str.pop();
            }
        }
    }

    string res = "";
    while (!str.empty())
    {
        res += str.top();
        str.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    removeOccurrences("daabcbaabcbc", "abc");
    return 0;
}