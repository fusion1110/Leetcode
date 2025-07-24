#include <bits/stdc++.h>
using namespace std;

// int uniquePaths(int m, int n)
// {
//     //*O(2^(m+n))
//     if (m == 1 && n == 1)
//         return 1;
//     if (m == 0 || n == 0)
//         return 0;
//     return uniquePaths(m - 1, n) +uniquePaths(m, n - 1);

// }


// int main()
// {
//     int m = 3, n = 3;                                        // Grid size
//     vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // Initialize memo table with -1

//     cout << "Unique Paths: " << uniquePaths(m, n, memo) << endl;
//     return 0;
// }

//*O(m+n) using memoization
// Helper function for recursion + memoization
int helper(int m, int n, vector<vector<int>>& dp) {
    if (m == 1 || n == 1) 
        return 1; // Base case: If we reach the first row or first column, only 1 way exists

    if (dp[m][n] != -1) 
        return dp[m][n]; // Return stored result if computed earlier

    // Store the result in dp table and return
    dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    return dp[m][n];
}

// Main function
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Memoization table
    return helper(m, n, dp);
}

int main() {
    int m = 3, n = 3; 
    cout << "Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}
