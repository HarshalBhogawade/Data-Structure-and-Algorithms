#include <bits/stdc++.h>
using namespace std;

// time complexity = O(N) Sc is O(N) call stack but internally normally no space 
// problem : delete kth element from top of stack
void deletemiddle(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();
    k--;
    deletemiddle(st, k);
    st.push(top);
}

// delete middle element of stack

//tc ON sc ON
void deletemiddle(stack<int> &st, int stsize, int currentsize)
{
    if (currentsize == stsize / 2)
    {
        st.pop();
        return;
    }
    int top = st.top();

    st.pop();

    currentsize++;

    deletemiddle(st, stsize, currentsize);

    st.push(top);
}

void deleteMid(stack<int> &s)
{
    // code here..
    int stsize = s.size();
    deletemiddle(s, stsize, 0);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    deletemiddle(st, 3);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}