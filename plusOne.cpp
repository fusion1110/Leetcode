#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    //--1 is faster than 1--
    for (int i = n - 1; i >= 0; --i) // starts at the end of the vector/array
    {
        if (digits[i] < 9)
        {
            digits[i] += 1; // simply add 1 to the last element/number
            return digits;
        }
        digits[i] = 0; // 9 hua last mai toh usko 0 krna padega
    }

    vector<int> result(n + 1, 0); // end mai 9 tha toh had to add an extra space so created a new vector
    result[0] = 1;
    return result;
}

int main()
{
    vector<int> digits = {1, 2, 3};
    vector<int> result = plusOne(digits);

    for (int i : result)
    {
        cout << i;
    }
    cout << endl;

    return 0;
}
