#include <iostream>
#include <unordered_map>
using namespace std;

//another method is to sort it but its time complexity is O(nlogn)

bool isAnagram(string s, string t)
{
    unordered_map<char, int> count;

    if (s.length() != t.length())
        return false;

    for (char c : s)
    {
        count[c]++;
    }

    for (char c : t)
    {
        count[c]--;
        if (count[c] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isAnagram("racecar", "carrace");
    cout << endl;
    return 0;
}