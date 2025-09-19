#include <bits/stdc++.h>
using namespace std;

bool isoperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

string PrefixToInfix(string prefix)
{
    stack<string> st;
    for (int i = prefix.size()-1; i>=0; i--)
    {
        char ch = prefix[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            st.push(string(1, ch));
        }
        else if (isoperator(ch))
        {
                string elem2 = st.top();
                st.pop();
                string elem1 = st.top();
                st.pop();
            string format = '(' + elem1 + ch + elem2 + ')';
            st.push(format);
        }
    }
    return st.top();
}

int main()
{
    string prefix = "-A/BC-*DEF";
    string infix = PrefixToInfix(prefix);
    cout << "Infix : " << infix;
    return 0;
}