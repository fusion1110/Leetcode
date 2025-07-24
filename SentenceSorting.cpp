#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string sortSentence(string s)
{
    stringstream ss(s);
    vector<string> v;

    while (getline(ss, s, ' '))
    {
        v.push_back(s);
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].back() > v[j + 1].back())
            {
                swap(v[j], v[j + 1]);
            }
        }
    }

    string result = "";
    for (int i = 0; i < v.size(); i++)
    {
        v[i].pop_back();
        result += v[i];
        if (i < v.size() - 1)
            result += " ";
    }

    return result;
}

int main()
{

    cout << sortSentence("is2 sentence4 This1 a3");
    return 0;
}