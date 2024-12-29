#include <bits/stdc++.h>
using namespace std;

// Function to find the largest divisor of a number p, other than itself.
int largest_div(int p)
{
    // Edge case: If the health is 1, there are no divisors other than 1 itself.
    if (p == 1)
        return p;

    int max_div = 1; // The smallest divisor of any number (other than the number itself) is 1.

    // Loop from 2 to sqrt(p) to find divisors.
    for (int i = 2; i < sqrt(p); i++)
    {
        // If i divides p, it's a divisor.
        if (p % i == 0)
        {
            max_div = max(max_div, i); // Max divisor is updated.
        }

        // If p / i is also a divisor and not equal to i, update the max divisor.
        if (i != p / i)
        {
            max_div = max(max_div, p / i);
        }
    }
    return max_div; // Return the largest divisor.
}

// Function to simulate the battle and return the maximum number of battles Chef can fight.
int battle(int h, int k)
{
    int max_battles = 0; // Variable to store the maximum number of battles Chef can fight.

    // Try all possible multipliers from 1 to k.
    for (int m = 1; m <= k; m++)
    {
        int current_health = h * m; // Multiply health by m to maximize the number of battles.
        int battles = 0;            // Counter for the number of battles Chef can fight.

        // Keep reducing Chef's health until it reaches 1.
        while (current_health > 1)
        {
            current_health = largest_div(current_health); // Reduce health to the largest divisor.
            battles++;                                    // Increment the battle count.
        }
        max_battles = max(max_battles, battles); // Keep track of the maximum battles.
    }

    return max_battles; // Return the maximum battles found.
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases.

    while (t--)
    {
        int h, k;
        cin >> h >> k; // Read the initial health and the multiplier range.

        // Output the maximum number of battles Chef can fight for each test case.
        cout << battle(h, k) << endl;
    }
    return 0;
}

//for rev: https://chatgpt.com/share/672b884a-5948-800e-8c53-9d13741eb25f


// optimised code
// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate the largest divisor of each number up to max_val
// vector<int> precompute_largest_divisors(int max_val) {
//     vector<int> largest_div(max_val + 1, 1);  // Initialize with 1, as every number has 1 as a divisor.

//     // Use a sieve-like approach to fill the largest divisors for all numbers.
//     for (int i = 2; i <= max_val; i++) {
//         for (int j = i * 2; j <= max_val; j += i) {
//             largest_div[j] = max(largest_div[j], i);  // Update the largest divisor of j.
//         }
//     }
//     return largest_div;
// }

// // Function to simulate the battle and return the maximum number of battles Chef can fight.
// int battle(int h, int k, const vector<int>& largest_div) {
//     int max_battles = 0;  // Variable to store the maximum number of battles Chef can fight.

//     // Try all possible multipliers from 1 to k.
//     for (int m = 1; m <= k; m++) {
//         int current_health = h * m;  // Multiply health by m to maximize the number of battles.
//         int battles = 0;  // Counter for the number of battles Chef can fight.

//         // Keep reducing Chef's health until it reaches 1.
//         while (current_health > 1) {
//             current_health = largest_div[current_health];  // Reduce health to the largest divisor.
//             battles++;  // Increment the battle count.
//         }
//         max_battles = max(max_battles, battles);  // Keep track of the maximum battles.
//     }

//     return max_battles;  // Return the maximum battles found.
// }

// int main() {
//     int t;
//     cin >> t;  // Read the number of test cases.

//     // Set a reasonable upper limit for the health values Chef can encounter.
//     int max_hk = 100000;  // You can adjust this based on the problem constraints.

//     // Precompute the largest divisors for all values up to max_hk.
//     vector<int> largest_div = precompute_largest_divisors(max_hk);

//     while (t--) {
//         int h, k;
//         cin >> h >> k;  // Read the initial health and the multiplier range.

//         // Output the maximum number of battles Chef can fight for each test case.
//         cout << battle(h, k, largest_div) << endl;
//     }
//     return 0;
// }
