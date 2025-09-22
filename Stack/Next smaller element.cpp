#include<bits/stdc++.h>
using namespace std;

//time complexity = O(2N) for visiting and popping elelment once tc <= 2N  Space : O(2n)
vector<int>  nextSmallerEle(vector<int> &arr)
{
    //  code shere
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);
    int i = n - 1;
    while (i >= 0)
    {   //recursively popping if not in increasing order (to ensurere monotonic increasing stack)
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        //if empty push -1 else top elem
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
        i--;
    }
    return ans;
}
int main(){
    vector<int>arr={4, 8, 5, 2, 25};
    vector<int>ans=nextSmallerEle(arr);
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}