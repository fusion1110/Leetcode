#include <bits/stdc++.h>
using namespace std;

string minCostGoodCaption(string caption)
{
    string res = caption;
    int n = caption.size();

    for (int i = 0; i < n;)
    {
        int j = i;

        while (j < n && res[j] == res[i])
        {
            j++;
        }

        int grpLength = j - i;

        if (grpLength < 3)
        {
            if (i > 0 && res[i] > 'a' && res[i] != 'z')
            {
                res[i]--;
            }
            else if (j < n && res[j] < 'z' && res[j] != 'a')
            {
                res[j]++;
            }
        }

        i = j; //moving to the next grp
    }
    return res;
}

int main()
{
    string caption = "aabbb"; // Example input
    string result = minCostGoodCaption(caption);
    cout << result << endl; // Output the result
    return 0;
}
