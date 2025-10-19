#include <bits/stdc++.h>
using namespace std;

bool isoperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

string PostfixToPrefix(string postfix)
{
    stack<string> st;
    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
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
            string format = ch + elem1 + elem2;
            st.push(format);
        }
    }
    return st.top();
}

int main()
{
    string postfix = "ab+c*";
    string prefix = PostfixToPrefix(postfix);
    cout << "prefix : " << prefix;
    return 0;
}


