#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    //if (seen.find(num) != seen.end()): This checks if num is already present in the seen set.
    // seen.find(num) searches for num in the set.
    // If num is found, it returns an iterator to the element; otherwise, it returns seen.end().
    // So, if seen.find(num) != seen.end(), it means num is already in the set, and a duplicate has been found.
    unordered_set<int> set;
    for (int num : nums)
    {
        if (set.find(num) != set.end())
        {
            return true;
        }
        set.insert(num);
    }
    return false;
}

int main()
{
    
    return 0;
}