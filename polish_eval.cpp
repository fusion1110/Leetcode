#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOperator(const string &token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (const auto &token : tokens)
        {
            if (isOperator(token))
            {
                if (st.size() < 2)
                {
                    throw invalid_argument("Invalid postfix expression");
                }

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if (token == "+")
                {
                    st.push(op1 + op2);
                }
                else if (token == "-")
                {
                    st.push(op1 - op2);
                }
                else if (token == "*")
                {
                    st.push(op1 * op2);
                }
                else if (token == "/")
                {
                    if (op2 == 0)
                    {
                        throw invalid_argument("Division by zero is not allowed");
                    }
                    st.push(op1 / op2);
                }
            }
            else
            {
                st.push(stoi(token));
            }
        }

        if (st.size() != 1)
        {
            throw invalid_argument("Invalid postfix expression: extra operands or insufficient operators");
        }

        return st.top();
    }
};

int main()
{
    Solution s1;
    vector<string> input = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result = s1.evalRPN(input);
    cout << result << endl;
    return 0;
}