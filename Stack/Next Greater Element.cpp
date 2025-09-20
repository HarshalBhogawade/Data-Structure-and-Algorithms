#include<bits/stdc++.h>
using namespace std;
vector<int> nextLargerElement(vector<int> &arr)
{
    // code here
    stack<int> st;
    int n = arr.size();
    int i = n - 1;

    vector<int> ans(n);
    while (i >= 0)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
        i--;
    }
    return ans;
}
int main() {
    vector<int>nums = {6, 8, 0, 1, 3};
    vector<int>ans = nextLargerElement(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}