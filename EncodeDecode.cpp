#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> &strs)
{
    string encoded = "";
    for (string &s : strs)
    {
        encoded += to_string(s.length()) + "#" + s;
    }

    return encoded;
}

vector<string> decode(string s)
{
    vector<string> decoded;

    int i = 0;
    while (i < s.length())
    {
        int j = s.find('#', i); // finding the position of our special char

        int length = stoi(s.substr(i, j - i)); // extracting the number just before the '#'
        string str = s.substr(j + 1, length);  // extracting out string
        decoded.push_back(str);

        i = j + 1 + length;
    }

    return decoded;
}

int main()
{
    vector<string> original = {"apple", "banana", "orange"};

    // Encode the list of strings
    string encoded = encode(original);
    cout << "Encoded: " << encoded << endl;

    // Decode the encoded string back to the list of strings
    vector<string> decoded = decode(encoded);

    cout << "Decoded: " << endl;
    for (const string &s : decoded)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}