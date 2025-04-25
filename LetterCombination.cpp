#include <bits/stdc++.h>
using namespace std;

vector<string> res;

// nothing mapped to 0 and 1
vector<string> DigitToChar = {"", "", "abc", "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};

void backtrack(int i, string curString, string &digits)
{
    if (curString.size() == digits.size())
    {
        res.push_back(curString);
        return;
    }

    string chars = DigitToChar[digits[i] - '0'];
    for (char c : chars)
    {
        backtrack(i + 1, curString + c, digits);
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return res;
    backtrack(0, "", digits);
    return res;
}

int main()
{
    string input;
    cout << "Enter a string of digits (2-9): ";
    cin >> input;

    vector<string> combinations = letterCombinations(input);

    cout << "All possible letter combinations:\n";
    for (const string &s : combinations)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}