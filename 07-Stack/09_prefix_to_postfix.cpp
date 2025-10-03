#include <bits/stdc++.h>
using namespace std;


string prefixtopostfix(string prefix)
{
    stack<string> st;
    for (int i = prefix.size()- 1; i >= 0; i--){
        char ch = prefix[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            st.push(string(1,ch));
        }else{
            string elem1 = st.top();
            st.pop();
            string elem2 = st.top();
            st.pop();
            string format = elem1 + elem2 + ch;
            st.push(format);
        }
        
    }
    return st.top();
}

int main()
{
    string prefix = "/-ab*+def";
    string postfix  = prefixtopostfix(prefix);
    cout<<"postfix : "<<postfix<<endl;
    return 0;
}

