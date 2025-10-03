#include<bits/stdc++.h>
using namespace std;


bool isoperator(char ch){
    return ch=='+' || ch=='-' || ch =='*' || ch=='/' || ch=='%' || ch=='^';
}

string Postfixtoinfix(string postfix){
    stack<string>st;
    int i =0;
    string res;
    for(int i=0;i<postfix.size();i++){
        char ch = postfix[i];
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            st.push(string(1,ch));
        }else{
            string elem1 = st.top();
            st.pop();
            string elem2 = st.top();
            st.pop();
            string format = '(' + elem2 + ch + elem1 +')';
            st.push(format);
        }
    }
    return st.top();
}

int main(){
    string postfix = "ab+c*";
    string infix = Postfixtoinfix(postfix);
    cout<<"Infix : "<<infix;
    return 0;
}