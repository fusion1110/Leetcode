#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> set;
    int l = 0, r = 0, res = 0;
    int n = s.size();

    while (r < n)
    {
        if (set.find(s[r]) != set.end())
        {
            l = max(set[s[r]] + 1, l);
        }

        set[s[r]] = r;

        //What the line does:
        // Access the r-th element of s (denoted by s[r]).
        // Use s[r] as the key in the set (hash map).
        // Assign the value r to that key in the set.
        
        res = max(res, r - l + 1);
        r++;
    }

    return res;
}

int main()
{

    return 0;
}