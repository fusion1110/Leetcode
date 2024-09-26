#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

void sortSentence(string s)
{
    stringstream ss(s);

    vector<string> v;
    // using while loop until the getline condition is
    // satisfied
    // ' ' represent split the string whenever a space is
    // found in the original string

    while (getline(ss, s, ' '))
    {
        v.push_back(s);
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            // Compare the last characters (which are numbers)
            if (v[j].back() > v[j + 1].back())
            {
                swap(v[j], v[j + 1]);  
            }
        }
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        v[i].pop_back(); // accessing the last char of each element ie, the number
        cout << v[i] << " ";
    }
}

int main()
{

    sortSentence("is2 sentence4 This1 a3");
    return 0;
}