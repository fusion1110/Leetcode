#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
    for (int i = 0; i < s.length(); ++i) {

        if (isdigit(s[i])) {
            s.erase(i, 1);
            if (i - 1 >= 0) {
                s.erase(i - 1, 1);
                i = i - 2;
            }
        }
    }
    return s;
}

int main()
{

    return 0;
}