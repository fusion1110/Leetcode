#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{

    int NumberOfPalindrome = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        // Odd length palindrome
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            NumberOfPalindrome++;
            l--;
            r++;
        }

        // Even length palindrome
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            NumberOfPalindrome++;
            l--;
            r++;
        }
    }

    return NumberOfPalindrome;
}

int main()
{
    string s = "abc";
    cout << "Number of Palindromic Substrings: " << countSubstrings(s) << endl;
    s = "aaa";
    cout << "Number of Palindromic Substrings: " << countSubstrings(s) << endl;
    s = "ababa";
    return 0;
}