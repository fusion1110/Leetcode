#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty()) return "";

    unordered_map<char, int> t_freq, window;

    for (char c : t)
        t_freq[c]++;

    int need = t_freq.size(), have = 0;
    pair<int, int> res = {-1, -1};
    int res_len = INT_MAX;
    int l = 0;

    for (int r = 0; r < s.length(); r++)
    {
        char c = s[r];
        window[c]++;

        if (t_freq.count(c) && window[c] == t_freq[c])
            have++;

        while (have == need)
        {
            if ((r - l + 1) < res_len)
            {
                res_len = r - l + 1;
                res = {l, r};
            }

            window[s[l]]--;

            if (t_freq.count(s[l]) &&
                window[s[l]] < t_freq[s[l]])
                have--;

            l++;
        }
    }

    return res_len == INT_MAX ? "" : s.substr(res.first, res_len);
}

int main()
{
    string s, t;

    cin >> s >> t;

    cout << minWindow(s, t) << endl;

    return 0;
}
