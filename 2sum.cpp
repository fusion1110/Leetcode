#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    vector<int> test = {3,2,4};
    vector<int> result = twoSum(test, 6);

    for (int r : result)
    {
        cout << r << " ";
    }
    return 0;
}