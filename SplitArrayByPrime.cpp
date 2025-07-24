#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

long long splitArray(vector<int> &nums)
{
    vector<int> primes;
    vector<int> nonPrimes;

    for(int i = 0; i < nums.size(); i++)
    {
        if (isPrime(i))
        {
            primes.push_back(nums[i]);
        }
        else
        {
            nonPrimes.push_back(nums[i]);
        }
    }
    long long sumPrimes = accumulate(primes.begin(), primes.end(), 0LL);
    long long sumNonPrimes = accumulate(nonPrimes.begin(), nonPrimes.end(), 0LL);
    long long difference = abs(sumPrimes - sumNonPrimes);

    return difference;

}

int main() {
    vector<int> nums = {-1,0,5,7}; // Example input
    cout << splitArray(nums) << endl; // Output the difference
    return 0;
}