#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void sortSentence(string s)
{
    stringstream ss(s);
    string word;
    vector<string> str;
    vector<string> str1;
    char lastChar;
    while (ss >> word)
    {
        str.push_back(word);
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (!str.empty())
        {
            lastChar = str[i].back();
            str1.insert(str.begin() + lastChar, str[i]);
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < str1.size(); i++)
    {
        cout << str1[i] << ",";
    }

    cout << endl;
}

int main()
{

    sortSentence("is2 sentence4 This1 a3");
    return 0;
}