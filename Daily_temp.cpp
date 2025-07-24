#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    //! O(n2) -> using brute-force;
    //  int count = 0, n = temperatures.size();
    //  vector<int> res(n, 0);

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = i + 1; j <= n; j++)
    //     {
    //         if (temperatures[j] > temperatures[i])
    //         {
    //             res[i] = j - i;
    //             break;
    //         }
    //     }
    // }

    //! O(n)->  using stack;
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int idx = st.top();
            st.pop();
            res[idx] = i - idx; 
        }
        st.push(i);
    }

    return res;
}

int main()
{
    vector<int> input = {30, 38, 30, 36, 35, 40, 28};
    vector<int> res = dailyTemperatures(input);
    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}