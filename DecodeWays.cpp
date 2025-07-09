#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    if(s.empty() || s[0] == '0')
        return 0;
    if(s.size() == 1)
        return 1;

    // Create a DP array to store the number of ways to decode up to each index
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; // base case: empty string
    dp[1] = 1; // base case: single character (not 0)     
    
    for (int i = 2; i <= s.size(); i++)
    {
        // Check if the single digit is valid
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];

        // Check if the two digits form a valid number
        int twoDigit = stoi(s.substr(i - 2, 2));
        if (twoDigit >= 10 && twoDigit <= 26)
            dp[i] += dp[i - 2];
    }   

    return dp[s.size()];

}

int main()
{
    string s;
    cout << "Enter a string of digits: ";
    cin >> s;
    int result = numDecodings(s);
    cout << "Number of ways to decode: " << result << endl;
    return 0;
}