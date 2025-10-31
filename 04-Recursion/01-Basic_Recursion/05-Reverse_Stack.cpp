#include <bits/stdc++.h>
using namespace std;

void reverseinsert(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    // Recursively insert x in sorted order
    reverseinsert(st, x);

    st.push(top);
}
void reversestack(stack<int>&st)
{
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();

    reversestack(st);

    reverseinsert(st, top);
}

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reversestack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}