#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    string res; 
    int resLength = 0;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        // Odd length palindrome
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLength)
            {
                res = s.substr(l, r - l + 1);
                resLength = r - l + 1;
            }
            l--;
            r++;
        }

        // Even length palindrome
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLength)
            {
                res = s.substr(l, r - l + 1);
                resLength = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return res;
}

int main()
{
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    s = "cbbd";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    s = "a";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    s = "ac";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}