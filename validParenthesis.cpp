#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    //for the cp
    for(char c : s){
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else{
            if(st.empty() ||
            (c == ')' && st.top() != '(')||
            (c == ']' && st.top() != '[')||
            (c == '}' && st.top() != '{'))
            return false;
        st.pop();
        }  
    }
    return st.empty();
}

int main()
{
    cout<<isValid("(]");
    cout<<endl;
    return 0;
}