#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
    {
        while (l < r && !isalnum(s[l]))
            l++;
        while (l < r && !isalnum(s[r]))
            r--;

        if (tolower(s[l]) != tolower(s[r]))
            return false;

        l++;
        r--;
    }
    return true;
}

// bool isalnum(char c)
// {
//     return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9');
// }

int main()
{
    cout << (isPalindrome("Was it a car or a cat I saw?") ? "true" : "false");

    return 0;
}